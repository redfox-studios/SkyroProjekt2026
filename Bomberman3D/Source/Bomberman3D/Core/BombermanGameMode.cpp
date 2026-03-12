// Copyright (c) 2026, Michal Flaška & RedFox Studios. All Rights Reserved.

#include "Core/BombermanGameMode.h"
#include "Core/BombermanGameState.h"

#include "Player/BombermanPlayerController.h"
#include "Player/BombermanCharacter.h"
#include "Player/BombermanPlayerState.h"
#include "Grid/BombermanGrid.h"

#include "Kismet/GameplayStatics.h"
#include "EngineUtils.h"

ABombermanGameMode::ABombermanGameMode()
{
	DefaultPawnClass = ABombermanCharacter::StaticClass();
	PlayerControllerClass = ABombermanPlayerController::StaticClass();
	PlayerStateClass = ABombermanPlayerState::StaticClass();
	GameStateClass = ABombermanGameState::StaticClass();
}

void ABombermanGameMode::BeginPlay()
{
	Super::BeginPlay();

	Grid = Cast<ABombermanGrid>(UGameplayStatics::GetActorOfClass(GetWorld(), ABombermanGrid::StaticClass()));
	BombermanGameState = GetGameState<ABombermanGameState>();

	if (!Grid)
	{
		UE_LOG(LogTemp, Error, TEXT("BombermanGameMode: no grid found in level!"));
		return;
	}

	StartStage();
}

void ABombermanGameMode::StartStage()
{
	if (!BombermanGameState) return;

	BombermanGameState->StageState = EStageState::InProgress;
	BombermanGameState->StageTimeRemaining = StageTimerDuration;
	BombermanGameState->EnemiesRemaining = 0; // TODO: set this when enemy spawning is implemented

	// Spawn player at grid spawn position
	if (Grid)
	{
		for (TActorIterator<ABombermanCharacter> It(GetWorld()); It; ++It)
		{
			It->SetActorLocation(Grid->GetPlayerSpawnPosition());
			break;
		}
	}

	// Tick timer every second to update StageTimeRemaining
	GetWorld()->GetTimerManager().SetTimer(
		StageTickHandle,
		this,
		&ABombermanGameMode::OnStageTimerTick,
		1.f,
		true
	);

	// Full stage timer - on expire spawn enemy rush
	GetWorld()->GetTimerManager().SetTimer(
		StageTimerHandle,
		this,
		&ABombermanGameMode::OnStageTimerExpired,
		StageTimerDuration,
		false
	);

	UE_LOG(LogTemp, Log, TEXT("Stage %d started"), BombermanGameState->CurrentStage);
}

void ABombermanGameMode::OnStageTimerTick()
{
	if (!BombermanGameState) return;
	BombermanGameState->StageTimeRemaining = FMath::Max(0.f, BombermanGameState->StageTimeRemaining - 1.f);
}

void ABombermanGameMode::OnStageTimerExpired()
{
	UE_LOG(LogTemp, Warning, TEXT("Stage timer expired - enemy rush! (TODO: spawn Pontants)"));
	// TODO: spawn 10 Pontants
}

void ABombermanGameMode::OnEnemyDied()
{
	if (!BombermanGameState) return;

	BombermanGameState->EnemiesRemaining = FMath::Max(0, BombermanGameState->EnemiesRemaining - 1);

	UE_LOG(LogTemp, Log, TEXT("Enemy died. Remaining: %d"), BombermanGameState->EnemiesRemaining);

	if (BombermanGameState->EnemiesRemaining <= 0)
	{
		// All enemies dead - door is now active
		// Grid already handles door visibility via DestroyActorOnTile
		UE_LOG(LogTemp, Log, TEXT("All enemies dead - find the door!"));
	}
}

void ABombermanGameMode::OnPlayerEnteredDoor()
{
	if (!BombermanGameState) return;
	if (BombermanGameState->EnemiesRemaining > 0) return; // can't leave until all enemies dead

	StageClear();
}

void ABombermanGameMode::StageClear()
{
	if (!BombermanGameState) return;

	BombermanGameState->StageState = EStageState::StageClear;
	BombermanGameState->CurrentStage++;

	GetWorld()->GetTimerManager().ClearTimer(StageTimerHandle);
	GetWorld()->GetTimerManager().ClearTimer(StageTickHandle);

	UE_LOG(LogTemp, Log, TEXT("Stage clear! Loading next stage... (TODO: level reload)"));
	// TODO: reload level / load next stage
}

void ABombermanGameMode::OnGameOver()
{
	if (!BombermanGameState) return;

	BombermanGameState->StageState = EStageState::GameOver;

	GetWorld()->GetTimerManager().ClearTimer(StageTimerHandle);
	GetWorld()->GetTimerManager().ClearTimer(StageTickHandle);

	UE_LOG(LogTemp, Log, TEXT("Game over!"));
	// TODO: show game over screen
}