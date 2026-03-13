// Copyright (c) 2026, Michal Flaška & RedFox Studios. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Enemies/EnemyBase.h"
#include "BombermanGameMode.generated.h"

class ABombermanGrid;
class ABombermanGameState;

UCLASS()
class BOMBERMAN3D_API ABombermanGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ABombermanGameMode();

protected:
	virtual void BeginPlay() override;

public:
	// Called by BombermanCharacter when player runs out of lives
	void OnGameOver();

	// Called by enemy when it dies
	void OnEnemyDied();

	// Called when player enters the door
	void OnPlayerEnteredDoor();

	UPROPERTY(EditDefaultsOnly, Category = "Stage Config")
	float StageTimerDuration = 200.f;

	UPROPERTY(EditDefaultsOnly, Category = "Stage Config")
	int32 StartingLives = 3;

	UPROPERTY(EditDefaultsOnly, Category = "Stage Config")
	TSubclassOf<AEnemyBase> DefaultEnemyClass;

	UPROPERTY(EditDefaultsOnly, Category = "Stage Config")
	int32 EnemyCount = 3;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UUserWidget> GameOverWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UUserWidget> StageClearWidgetClass;

private:
	void StartStage();
	void OnStageTimerTick();
	void OnStageTimerExpired();
	void StageClear();
	void SpawnEnemies();
	void LoadNextStage();

	FTimerHandle StageTimerHandle;
	FTimerHandle StageTickHandle;

	ABombermanGrid* Grid = nullptr;
	ABombermanGameState* BombermanGameState = nullptr;
};
