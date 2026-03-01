# Bomberman3D - TODO

AI enhanced TODO

## Phase 1 - Core Systems

### Grid
- [x] ETileContent enum
- [x] Grid data structure (TArray 2D)
- [x] IsTileWalkable()
- [x] IsTileSoft()
- [x] GetTileWorldPosition()
- [x] GetTileContent()
- [x] SetTileContent()
- [ ] SpawnActorOnTile() - spawn soft blocks, bombs, upgrades, door
- [ ] DestroyActorOnTile()
- [ ] Hard wall layout (static, placed on BeginPlay)
- [ ] Debug visualization (draw tiles in editor so you can see the grid)

### Player
- [x] BombermanCharacter class (inherits ACharacter)
- [x] Top-down movement (4-directional, smooth)
- [x] Fixed camera setup (spring arm, locked rotation, -65 degrees)
- [ ] Bomb placement input
- [ ] GetCurrentGridPosition() (world pos -> grid coords)
- [ ] BombermanPlayerState (lives, score, upgrades struct, bomb count, blast radius)
- [ ] FPlayerUpgrades struct

### Bomb
- [ ] ABomb actor class
- [ ] Bomb states: Placed -> Armed -> Detonating -> Explosion -> Cleanup
- [ ] Fuse timer
- [ ] Explosion logic (cross-shaped, 4 directions, stops on hard/soft walls)
- [ ] Soft block destruction on explosion
- [ ] Chain reaction (bomb hit by explosion detonates immediately)
- [ ] Snap placement to grid tile

### Stage
- [ ] BombermanGameMode class
- [ ] Basic stage loading
- [ ] Hard wall placement (static per stage)
- [ ] Player spawn (top-left)
- [ ] Stage timer
- [ ] Win condition (all enemies dead -> door spawns -> player enters)
- [ ] Lose condition (player loses last life)

### Enemies (2 basic ones, no AI yet)
- [ ] AEnemyBase class
- [ ] Ballom (random direction, change on wall hit)
- [ ] Onil (random + pursue if player nearby)

### HUD
- [ ] Lives display
- [ ] Score display
- [ ] Timer display

---

## Phase 2 - Content

### Stage Generation
- [ ] Procedural soft block placement (skip player spawn zone ~2x2)
- [ ] Door hidden under random soft block
- [ ] Upgrades hidden under random soft blocks
- [ ] Enemy spawn positions (away from player)
- [ ] Flood-fill check (guarantee door is always reachable)
- [ ] Data Table setup (enemy types, upgrades, timer per stage)
- [ ] Grid growth (every X stages, grid grows by 1 in each direction)

### Upgrades & Items
- [ ] BombUp (max bombs +1)
- [ ] FireUp (blast radius +1)
- [ ] SpeedUp (movement speed +1)
- [ ] RemoteControl
- [ ] WallPass
- [ ] BombPass
- [ ] FlamePass
- [ ] Invincible

### Save System
- [ ] UBombermanSaveGame class
- [ ] Save on stage clear + game over
- [ ] Load on game start / continue

### Stage Progression
- [ ] Load next stage on clear
- [ ] Enemy Rush (10 Pontants on timer expire)
- [ ] 50 total stages

---

## Phase 3 - Full AI

- [ ] Dahl (alternates axis)
- [ ] Minvo (random + pursue, can get stuck)
- [ ] Ovape (mostly ignores player)
- [ ] Pass (aggressive chase)
- [ ] Pontant (always chase, fastest)
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
- [ ] Main Menu (New Game, Continue, Settings, Credits, Quit)
- [ ] Pause Menu (Resume, Restart Stage, Main Menu)
- [ ] Game Over screen
- [ ] Stage Clear screen
- [ ] Loading Screen
- [ ] Credits Screen
- [ ] Settings (keybind remapping via Enhanced Input)

### Final
- [ ] Full bugfix pass
- [ ] Local co-op/versus (if time allows)

---

## Known Risks
- Dynamic NavMesh performance with soft block destruction -> test early
- Doria AI complexity -> don't leave to May
- Procedural gen edge cases -> add flood-fill check early
- Multiplayer refactor cost -> no global player singletons, always use PlayerState/GameState