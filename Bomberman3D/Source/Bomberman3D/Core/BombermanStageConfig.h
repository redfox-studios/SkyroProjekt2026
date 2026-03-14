// Copyright (c) 2026, Michal Flaška & RedFox Studios. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Enemies/EnemyBase.h"
#include "BombermanStageConfig.generated.h"

USTRUCT(BlueprintType)
struct FBombermanStageConfig : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TSubclassOf<AEnemyBase> EnemyClass;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 EnemyCount = 3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float StageTimer = 200.f;
};
