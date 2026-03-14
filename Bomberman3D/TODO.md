# Bomberman3D - TODO

## Phase 1 - Core Systems

### Grid
- [x] ETileContent enum
- [x] Grid data structure (TArray 2D)
- [x] IsTileWalkable()
- [x] IsTileSoft()
- [x] GetTileWorldPosition()
- [x] GetTileContent() - OOB returns HardBlock so explosions stop at map edge
- [x] SetTileContent()
- [x] SpawnActorOnTile()
- [x] DestroyActorOnTile() - also reveals door if it was hidden under the destroyed soft block
- [x] Hard wall layout (border + checkerboard pillars, placed on BeginPlay)
- [x] Procedural soft block generation (density configurable, safe zone around player spawn)
- [x] Door placement (hidden under random soft block, flood-fill check guarantees reachability)
- [x] Debug visualization (color coded: red=hard, green=soft, yellow=bomb, blue=door, white=empty)

### Player
- [x] BombermanCharacter class (inherits ACharacter)
- [x] Top-down movement (4-directional, smooth)
- [x] Fixed camera setup (spring arm, locked rotation, -65 degrees)
- [x] Bomb placement input
- [x] GetCurrentGridPosition() (world pos -> grid coords)
- [x] BombermanPlayerState (lives, upgrades struct)
- [x] FBombermanPlayerUpgrades struct
- [x] BombCount and BlastRadius derived from upgrades (GetBombCount(), GetBlastRadius())
- [x] Health component (BombermanHealthComponent, reusable on enemies)
- [x] Death handling (lose life, respawn or game over)

### Bomb
- [x] ABomb actor class
- [x] Bomb states: Placed -> Armed -> Detonating -> Explosion -> Cleanup
- [x] Fuse timer
- [x] Explosion logic (cross-shaped, 4 directions, stops on hard/soft walls)
- [x] Soft block destruction on explosion (calls DestroyActorOnTile)
- [x] Chain reaction (bomb hit by explosion detonates immediately, double-trigger protected)
- [x] Snap placement to grid tile
- [x] Blast radius from PlayerState (FireUp upgrade)
- [x] Bomb count limit from PlayerState (BombUp upgrade)
- [x] Player/enemy damage on explosion (BoxOverlap on each blast tile)
- [x] Bomb passthrough until player leaves tile

### Stage
- [x] BombermanGameMode class
- [x] BombermanGameState class (StageState, StageTimeRemaining, CurrentStage, EnemiesRemaining)
- [x] Player spawn at grid spawn position (top-left interior tile)
- [x] Stage timer (200s countdown, ticks every second)
- [x] Enemy spawning (procedural, away from player spawn, configurable count)
- [x] Win condition (all enemies dead -> door active -> player enters door)
- [x] Lose condition (game over screen with restart button)
- [x] Level reload on stage clear
- [x] Stage timer expire -> Enemy Rush (spawn 10 Pontants) - stub exists
- [x] Score system

### Enemies
- [x] AEnemyBase class (health component, death notifies GameMode, configurable speed)
- [x] Ballom (random direction, changes on wall hit)

### HUD
- [x] Lives display
- [x] Timer display
- [x] Stage display
- [x] Score display

---

## Phase 2 - Content

### Stage Generation
- [x] Procedural soft block placement (skip player spawn zone)
- [x] Door hidden under random soft block
- [x] Flood-fill check (guarantee door is always reachable)
- [x] Upgrades hidden under random soft blocks (BombUp, FireUp)
- [ ] Data Table setup (enemy types, upgrades, timer per stage)
- [x] Grid growth (every X stages, grid grows by 1 in each direction)

### Upgrades & Items
- [x] BombUp (max bombs +1)
- [x] FireUp (blast radius +1)
- [x] SpeedUp (movement speed +1)
- [ ] RemoteControl
- [ ] WallPass
- [ ] BombPass
- [ ] FlamePass
- [ ] Invincible

### Save System
- [x] GameInstance persists stage, lives, upgrades across level loads
- [x] UBombermanSaveGame class (persist between game sessions)
- [x] Save on stage clear + game over
- [x] Load on game start / continue

### Stage Progression
- [x] Load next stage on clear (reloads current level for now)
- [x] Enemy Rush (10 Pontants on timer expire)
- [ ] 50 total stages

---

## Phase 3 - Full AI

- [x] Onil (random + pursue if player nearby)
- [ ] Dahl (alternates axis)
- [ ] Minvo (random + pursue, can get stuck)
- [ ] Ovape (mostly ignores player)
- [ ] Pass (aggressive chase)
- [x] Pontant (always chase, fastest)
- [ ] Doria (chase + bomb avoidance via Behavior Tree) <- hardest, start early
- [ ] NavMesh setup for pathfinding enemies
- [ ] Separate NavMesh config for soft-block-passthrough enemies
- [ ] Dynamic NavMesh rebuild on soft block destruction <- test performance early

### VFX & Sound
- [ ] Explosion VFX
- [ ] Soft block destroy VFX
- [ ] Upgrade pickup VFX
- [ ] Background music
- [ ] SFX (bomb place, explosion, pickup, death, stage clear)

---

## Phase 4 - Polish

### UI
- [x] Main Menu (New Game, Continue, Settings, Credits, Quit)
- [x] Pause Menu (Resume, Restart Stage, Main Menu)
- [x] Game Over screen
- [x] Stage Clear screen
- [ ] Loading Screen
- [ ] Credits Screen
- [ ] Settings (keybind remapping via Enhanced Input)

### Final
- [ ] Full bugfix pass
- [ ] Local co-op/versus (if time allows)

### Movement
- [ ] Corner rounding logic for enemies

---

## Known Risks
- Dynamic NavMesh performance with soft block destruction -> test early
- Doria AI complexity -> don't leave to May
- Procedural gen edge cases -> flood-fill check is in, keep an eye on edge cases
- Multiplayer refactor cost -> no global player singletons, always use PlayerState/GameState