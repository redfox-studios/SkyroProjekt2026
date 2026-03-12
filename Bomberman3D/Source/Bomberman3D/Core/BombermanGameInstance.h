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
	int32 CurrentStage = 1;
	int32 Lives = 3;
	FBombermanPlayerUpgrades Upgrades;
};
