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
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 BombUp = 0;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 FireUp = 0;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 SpeedUp = 0;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) bool bRemoteControl = false;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) bool bWallPass = false;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) bool bBombPass = false;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) bool bFlamePass = false;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) bool bInvincible = false;
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
    int32 BombCount = 1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player State")
    int32 BlastRadius = 1;
};
