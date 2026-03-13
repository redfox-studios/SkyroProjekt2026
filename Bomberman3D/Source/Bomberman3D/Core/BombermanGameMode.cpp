// Copyright (c) 2026, Michal Flaška & RedFox Studios. All Rights Reserved.

#include "Core/BombermanGameMode.h"
#include "Core/BombermanGameState.h"

#include "Player/BombermanPlayerController.h"
#include "Player/BombermanCharacter.h"
#include "Player/BombermanPlayerState.h"
#include "Enemies/EnemyBase.h"
#include "Grid/BombermanGrid.h"
#include "Components/CapsuleComponent.h"
#include "Core/BombermanGameInstance.h"

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

	if (UBombermanGameInstance* GI = Cast<UBombermanGameInstance>(GetGameInstance()))
	{
		BombermanGameState->CurrentStage = GI->CurrentStage;
		// GI->CurrentStage++;

		for (TActorIterator<ABombermanCharacter> It(GetWorld()); It; ++It)
		{
			if (ABombermanPlayerState* PS = It->GetPlayerState<ABombermanPlayerState>())
			{
				PS->Lives = GI->Lives;
				PS->Upgrades = GI->Upgrades;
			}
			break;
		}
	}

	BombermanGameState->StageState = EStageState::InProgress;
	BombermanGameState->StageTimeRemaining = StageTimerDuration;
	BombermanGameState->EnemiesRemaining = 0;

	// Move player to spawn
	for (TActorIterator<ABombermanCharacter> It(GetWorld()); It; ++It)
	{
		It->SetActorLocation(Grid->GetPlayerSpawnPosition());
		break;
	}

	// Instead of calling SpawnEnemies directly
	FTimerHandle SpawnDelay;
	GetWorld()->GetTimerManager().SetTimer(SpawnDelay, this, &ABombermanGameMode::SpawnEnemies, 0.1f, false);

	// Tick timer every second
	GetWorld()->GetTimerManager().SetTimer(
		StageTickHandle,
		this,
		&ABombermanGameMode::OnStageTimerTick,
		1.f,
		true
	);

	// Full stage timer
	GetWorld()->GetTimerManager().SetTimer(
		StageTimerHandle,
		this,
		&ABombermanGameMode::OnStageTimerExpired,
		StageTimerDuration,
		false
	);

	UE_LOG(LogTemp, Log, TEXT("Stage %d started. Enemies: %d"), BombermanGameState->CurrentStage, BombermanGameState->EnemiesRemaining);
}

void ABombermanGameMode::SpawnEnemies()
{
	if (!DefaultEnemyClass || !Grid || !BombermanGameState) return;

	// Collect valid spawn tiles - must be empty, not near player spawn (1,1)
	TArray<FVector2D> ValidTiles;

	for (int32 X = 1; X < Grid->GetGridHeight() - 1; X++)
	{
		for (int32 Y = 1; Y < Grid->GetGridWidth() - 1; Y++)
		{
			if (Grid->GetTileContent(X, Y) != ETileContent::Empty) continue;

			// Keep enemies away from player spawn
			int32 SafeZone = Grid->GetPlayerSafeZone();
			if (FMath::Abs(X - 1) <= SafeZone && FMath::Abs(Y - 1) <= SafeZone) continue;

			ValidTiles.Add(FVector2D(X, Y));
		}
	}

	// Shuffle
	for (int32 i = ValidTiles.Num() - 1; i > 0; i--)
	{
		int32 j = FMath::RandRange(0, i);
		ValidTiles.Swap(i, j);
	}

	int32 Spawned = 0;
	for (const FVector2D& Tile : ValidTiles)
	{
		if (Spawned >= EnemyCount) break;

		UE_LOG(LogTemp, Log, TEXT("Trying to spawn at [%d,%d] content: %d"),
			FMath::RoundToInt(Tile.X), FMath::RoundToInt(Tile.Y),
			(int32)Grid->GetTileContent(FMath::RoundToInt(Tile.X), FMath::RoundToInt(Tile.Y)));

		FVector WorldPos = Grid->GetTileWorldPosition(
			FMath::RoundToInt(Tile.X),
			FMath::RoundToInt(Tile.Y)
		);

		AEnemyBase* CDO = DefaultEnemyClass->GetDefaultObject<AEnemyBase>();
		WorldPos.Z = CDO->GetCapsuleComponent()->GetScaledCapsuleHalfHeight();

		// AActor* Enemy = GetWorld()->SpawnActor<AActor>(DefaultEnemyClass, WorldPos, FRotator::ZeroRotator);
		// if (Enemy)
		// {
		//	  Spawned++;
		//	  BombermanGameState->EnemiesRemaining++;
		// }

		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		AEnemyBase* Enemy = GetWorld()->SpawnActor<AEnemyBase>(DefaultEnemyClass, WorldPos, FRotator::ZeroRotator, SpawnParams);
		if (Enemy)
		{
			Spawned++;
			BombermanGameState->EnemiesRemaining++;
		}
	}

	UE_LOG(LogTemp, Log, TEXT("Spawned %d enemies"), Spawned);
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
		UE_LOG(LogTemp, Log, TEXT("All enemies dead - find the door!"));
	}
}

void ABombermanGameMode::OnPlayerEnteredDoor()
{
	if (!BombermanGameState) return;
	if (BombermanGameState->EnemiesRemaining > 0) return;

	StageClear();
}

void ABombermanGameMode::StageClear()
{
	if (!BombermanGameState) return;

	BombermanGameState->StageState = EStageState::StageClear;

	GetWorld()->GetTimerManager().ClearTimer(StageTimerHandle);
	GetWorld()->GetTimerManager().ClearTimer(StageTickHandle);

	// disable player input during stage clear
	for (TActorIterator<ABombermanCharacter> It(GetWorld()); It; ++It)
	{
		It->DisableInput(nullptr);
		break;
	}

	if (UBombermanGameInstance* GI = Cast<UBombermanGameInstance>(GetGameInstance()))
	{
		GI->CurrentStage = BombermanGameState->CurrentStage + 1;

		for (TActorIterator<ABombermanCharacter> It(GetWorld()); It; ++It)
		{
			if (ABombermanPlayerState* PS = It->GetPlayerState<ABombermanPlayerState>())
			{
				GI->Lives = PS->Lives;
				GI->Upgrades = PS->Upgrades;
			}
			break;
		}
	}

	if (StageClearWidgetClass)
	{
		APlayerController* PC = GetWorld()->GetFirstPlayerController();
		if (PC)
		{
			UUserWidget* Widget = CreateWidget<UUserWidget>(PC, StageClearWidgetClass);
			if (Widget) Widget->AddToViewport();
		}
	}

	// short delay so the player can see the screen before reload
	FTimerHandle StageClearDelay;
	GetWorld()->GetTimerManager().SetTimer(
		StageClearDelay,
		this,
		&ABombermanGameMode::LoadNextStage,
		3.f,
		false
	);
}

void ABombermanGameMode::LoadNextStage()
{
	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()));
}

void ABombermanGameMode::OnGameOver()
{
	if (!BombermanGameState) return;

	BombermanGameState->StageState = EStageState::GameOver;

	GetWorld()->GetTimerManager().ClearTimer(StageTimerHandle);
	GetWorld()->GetTimerManager().ClearTimer(StageTickHandle);

	for (TActorIterator<ABombermanCharacter> It(GetWorld()); It; ++It)
	{
		It->DisableInput(nullptr);
		break;
	}

	// Show game over widget
	if (GameOverWidgetClass)
	{
		APlayerController* PC = GetWorld()->GetFirstPlayerController();
		if (PC)
		{
			UUserWidget* Widget = CreateWidget<UUserWidget>(PC, GameOverWidgetClass);
			if (Widget)
			{
				Widget->AddToViewport();
				PC->bShowMouseCursor = true;
			}
		}
	}

	UE_LOG(LogTemp, Log, TEXT("Game over!"));
}
