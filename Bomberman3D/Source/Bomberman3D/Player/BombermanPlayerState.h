// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"

#include "Player/BombermanPlayerUpgrades.h"

#include "BombermanPlayerState.generated.h"

/**
 * 
 */

/*
// MOVED TO Player/BombermanPlayerUpgrades.h
USTRUCT(BlueprintType)
struct FPlayerUpgrades
{
    ...
};
*/

UCLASS()
class BOMBERMAN3D_API ABombermanPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player State")
    int32 Lives = 3;

    /*
    // Unreal already has built-in score system
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player State")
    int32 Score = 0;
    */

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player State")
    FBombermanPlayerUpgrades Upgrades;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player State")
    int32 BombCount = 10; // just for testing, ill change it back to 1 someday

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player State")
    int32 BlastRadius = 1;
};
