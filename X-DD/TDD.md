# Technical Design Document - Bomberman 3D
Project: Bomberman3D<br />
Engine: Unreal Engine 5 (Hybrid C++ / Blueprints)<br />
Team: Maximilián Repa (Game Design, 3D Art, Sound), Michal Flaška (Programming), Eduard Fabo (3D Art, 2D Art)<br />
Target Platform: PC (Windows)<br />
Last Updated: `2026-02-26 5:22PM`

<br><br>

## 1. Tech Stack

| Thing            | What we're using                                    |
|------------------|-----------------------------------------------------|
| Engine           | UE5                                                 |
| Code             | C++ + Blueprints (hybrid)                           |
| Version Control  | GitHub (no LFS because we are poor)                 |
| IDE              | Visual Studio                                       |
| 3D               | Blender                                             |
| Texture/Material | Imphenzia Pixpal (one texture, one material policy) |

<br><br>

## 2. Architecture Overview

The codebase follows a hybrid approach - core systems (grid, bomb logic, AI, game state) are in C++, while designers can tweak everything through exposed `UPROPERTY` variables in the editor. Blueprints are used for things that don't need raw performance - UI, VFX triggers, simple animations.

Rule of thumb: if it has logic, it's C++. If it's just connecting things visually or needs to be tweaked by a non-coder, it can be BP.

<br><br>

## 3. Grid System

The map is tile-based but player and enemy movement is smooth (free movement, no snapping). The grid exists purely as a data structure - it tracks what's on each tile (empty, soft block, hard block, bomb, upgrade, door).

Bomb placement snaps to grid. When the player presses place bomb, we take their world position and round it to the nearest tile center:

```cpp
FVector2D ABombermanCharacter::GetCurrentGridPosition() const
{
    return FVector2D(
        FMath::RoundToInt(GetActorLocation().X / TileSize),
        FMath::RoundToInt(GetActorLocation().Y / TileSize)
    );
}
```

Grid class responsibilities:
- Knows the state of every tile
- Handles spawning/destroying actors on tiles (soft blocks, bombs, upgrades, door)
- Provides queries like `IsTileWalkable()`, `IsTileSoft()`, `GetTileWorldPosition()`

Configurable via UPROPERTY (because I didn't forget about game designers):
```cpp
UPROPERTY(EditAnywhere, Category = "Grid Config")
int32 BaseGridWidth = 13;

UPROPERTY(EditAnywhere, Category = "Grid Config")
int32 BaseGridHeight = 11;

UPROPERTY(EditAnywhere, Category = "Grid Config")
int32 GridGrowthPerStages = 10; // every X stages, grid grows by 1 in each direction

UPROPERTY(EditAnywhere, Category = "Grid Config")
int32 MaxGridWidth = 21;

UPROPERTY(EditAnywhere, Category = "Grid Config")
int32 MaxGridHeight = 17;

UPROPERTY(EditAnywhere, Category = "Grid Config")
float TileSize = 100.f;
```

<br><br>

## 4. Stage Generation

Stages are procedurally generated in the sense that soft blocks, enemies, upgrades, and the door are randomized each stage. Hard walls never move - their layout is fixed.

What stays the same every stage:
- Hard wall positions
- Map size (until growth threshold is hit)
- Player spawn (top-left corner)

What's randomized:
- Soft block positions (with guaranteed safe zone around player spawn)
- Enemy spawn positions
- Upgrade/item positions hidden under soft blocks
- Door position hidden under a soft block

Stage generation flow:
1. Place hard walls (static)
2. Spawn soft blocks randomly (skip player spawn zone ~2x2 tiles)
3. Pick one soft block to hide the door under
4. Pick soft blocks to hide upgrades/items under (based on stage config)
5. Spawn enemies at valid positions (away from player)

Configurable per stage via Data Table:
- Enemy types and counts
- Which upgrades can appear
- Which special items can appear
- Timer duration

<br><br>

## 5. Bomb System

Placement: snaps to nearest grid tile on player's position at time of input.

Explosion: cross-shaped, expanding in 4 directions (up/down/left/right). Each direction expands up to `BlastRadius` tiles. Expansion stops when it hits a hard wall (blocked entirely) or soft wall (destroys it, stops there).

```cpp
UPROPERTY(EditAnywhere, Category = "Bomb Config")
float BombFuseTime = 2.5f;

UPROPERTY(EditAnywhere, Category = "Bomb Config")
int32 DefaultBlastRadius = 1;

UPROPERTY(EditAnywhere, Category = "Bomb Config")
int32 MaxBlastRadius = 10; // Fire Up cap

UPROPERTY(EditAnywhere, Category = "Bomb Config")
int32 DefaultMaxBombs = 1;

UPROPERTY(EditAnywhere, Category = "Bomb Config")
int32 MaxBombCount = 10; // Bomb Up cap
```

Bomb states: Placed -> Armed (after player steps off) -> Detonating -> Explosion -> Cleanup

Chain reactions: if an explosion hits another bomb, that bomb detonates immediately.

<br><br>

## 6. Player

Inherits from `ACharacter`. Movement is handled by UE's built-in `CharacterMovementComponent` - no custom grid snapping for the player.

Input: Enhanced Input System (UE5 standard). Keybinds are configurable through the settings menu.

Player state tracked in `UBombermanPlayerState`:
- Current lives
- Current score
- Active upgrades (bitmask or struct)
- Current bomb count / max bombs
- Current blast radius

Upgrades are a struct:
```cpp
USTRUCT(BlueprintType)
struct FPlayerUpgrades
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 BombUp = 0;       // 0-10
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 FireUp = 0;       // 0-10
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 SpeedUp = 0;      // 0-3
    UPROPERTY(EditAnywhere, BlueprintReadWrite) bool bRemoteControl = false;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) bool bWallPass = false;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) bool bBombPass = false;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) bool bFlamePass = false;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) bool bInvincible = false;
};
```

<br><br>

## 7. Enemy AI

Each enemy type is a separate C++ class inheriting from `AEnemyBase`. Behavior complexity increases with enemy tier.

| Enemy   | AI Approach                             | Complexity           |
|---------|-----------------------------------------|----------------------|
| Ballom  | Random direction, change on wall hit    | Low - pure C++       |
| Onil    | Random + pursue if player nearby        | Low-Medium - C++     |
| Dahl    | Alternates axis (horizontal ↔ vertical) | Low - C++            |
| Minvo   | Random + pursue, can get stuck          | Medium - C++         |
| Doria   | Chase player + avoid bombs              | High - Behavior Tree |
| Ovape   | Mostly ignores player, occasional chase | Medium - C++         |
| Pass    | Aggressive chase                        | Medium - C++         |
| Pontant | Always chase, fastest                   | Medium - C++         |

NavMesh will be used for pathfinding on enemies that chase the player. Enemies that can pass through soft blocks will have a separate NavMesh config that ignores soft block collision.

Doria bomb avoidance - on bomb placement, broadcast an event. Doria listens, checks if bomb is within X tiles, and pathfinds away. This is the most complex AI behavior, scheduled for May.

<br><br>

## 8. Camera

Fixed spring arm attached to player, no collision. Rotation is locked.

```cpp
UPROPERTY(EditAnywhere, Category = "Camera Config")
float CameraArmLength = 1500.f;

UPROPERTY(EditAnywhere, Category = "Camera Config")
FRotator CameraRotation = FRotator(-65.f, 0.f, 0.f); // ~65 degrees down, slight isometric feel
```

Camera follows player position (XY only), Z is fixed. No zoom, no rotation during gameplay.

<br><br>

## 9. Game State & Flow

`ABombermanGameMode` handles the overall flow. `ABombermanGameState` holds shared state.

Stage flow:
1. GameMode initializes grid, generates stage
2. Spawns player, enemies
3. Starts stage timer
4. Waits for win condition (all enemies dead -> door appears -> player enters door)
5. Or lose condition (player loses last life)
6. On stage clear -> save progress -> load next stage
7. On timer expire -> spawn 10 Pontants (Enemy Rush)

Configurable:
```cpp
UPROPERTY(EditAnywhere, Category = "Stage Config")
float StageTimerDuration = 200.f;

UPROPERTY(EditAnywhere, Category = "Stage Config")
int32 StartingLives = 3;

UPROPERTY(EditAnywhere, Category = "Stage Config")
int32 TotalStages = 50;
```

<br><br>

## 10. Save System

Using UE5's built-in `USaveGame`. No password system.

`UBombermanSaveGame` stores:
- Current stage number
- Current lives
- Current score
- Active upgrades struct
- Current grid size (in case it grew)

Save happens on stage clear and on game over. Load happens on game start / continue from main menu.

```cpp
// Save
UGameplayStatics::SaveGameToSlot(SaveGameObject, TEXT("BombermanSave"), 0);

// Load
UBombermanSaveGame* Save = Cast<UBombermanSaveGame>(
    UGameplayStatics::LoadGameFromSlot(TEXT("BombermanSave"), 0)
);
```

<br><br>

## 11. UI

All UI is built in UMG (UE's widget system), driven from C++ where needed.

Screens:
- Main Menu (New Game, Continue, Settings, Credits, Quit)
- HUD (lives, score, timer, active upgrades)
- Pause Menu (Resume, Restart Stage, Main Menu)
- Game Over screen
- Stage Clear screen
- Loading Screen (between stages)
- Credits Screen
- Settings (keybind remapping via Enhanced Input)

<br><br>

## 12. Multiplayer (Future)

Core systems (grid, bomb, player state) will be designed with multiplayer in mind - no hardcoded "one player" assumptions. `PlayerState` already handles per-player data.

- Phase 1 (current): Singleplayer only
- Phase 2 (future): Local co-op/versus
- Phase 3 (if time allows): Online via UE5 replication (no dedicated server, peer-to-peer)

To keep this door open: avoid using global singletons for player data, always route through `PlayerState` / `GameState`.

<br><br>

## 13. Project Structure

```
Content/
├── Blueprints/
│   ├── Characters/
│   ├── Enemies/
│   ├── UI/
│   └── GameMode/
├── Maps/
├── Meshes/          (SM_ prefix)
├── Materials/       (M_, MI_ prefix)
├── Textures/        (T_ prefix)
├── Animations/      (AN_ prefix)
├── Sounds/
├── VFX/
└── Data/            (Data Tables, configs)

Source/
├── Bomberman3D/
│   ├── Characters/
│   ├── Enemies/
│   ├── Grid/
│   ├── Bombs/
│   ├── GameMode/
│   ├── SaveGame/
│   └── UI/
```

<br><br>

## 14. Development Schedule

- Core systems: grid, player movement, bomb placement/explosion, soft/hard walls, 2 enemies (no AI), basic stage loading, HUD
- Procedural stage generation, all upgrades, save system, stage progression
- Full AI for all 8 enemies, VFX, sound, items, special item conditions
- UI polish, settings/keybinds, loading screens, credits, local multiplayer (if time), final bugfix pass

<br><br>

## 15. Known Risks

Enemy AI complexity - Doria's bomb avoidance and Pontant's pathfinding through soft blocks will be the hardest part. NavMesh with dynamic obstacles (soft blocks being destroyed mid-game) needs testing early. Don't leave this to May.

Procedural generation edge cases - soft block placement needs to guarantee the door is always reachable and there's always a valid path. Worth adding a simple flood-fill check after generation.

Dynamic NavMesh - when soft blocks get destroyed, NavMesh needs to update. UE5 supports dynamic NavMesh rebuilding but it has a cost. Test performance early.

Multiplayer refactor cost - if online multiplayer gets added late, it might require significant refactoring. Design decisions now (no global player singletons, proper use of GameState/PlayerState) will minimize this.