// Copyright (c) 2026, Michal Flaška & RedFox Studios. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Player/BombermanPlayerUpgrades.h"
#include "BombermanGameInstance.generated.h"

UCLASS()
class BOMBERMAN3D_API UBombermanGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	// static constexpr int32 DefaultStage = 1;
	// static constexpr int32 DefaultLives = 3;

	UPROPERTY(BlueprintReadWrite, Category = "Game Instance")
	int32 CurrentStage = 1;

	UPROPERTY(BlueprintReadWrite, Category = "Game Instance")
	int32 Lives = 3;

	UPROPERTY(BlueprintReadWrite, Category = "Game Instance")
	FBombermanPlayerUpgrades Upgrades;

	UFUNCTION(BlueprintCallable, Category = "Game Instance")
	void ResetToDefaults();
};
