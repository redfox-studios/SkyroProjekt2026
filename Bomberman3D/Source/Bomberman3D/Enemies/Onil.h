// Copyright (c) 2026, Michal Flaška & RedFox Studios. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Enemies/EnemyBase.h"
#include "Onil.generated.h"

UCLASS()
class BOMBERMAN3D_API AOnil : public AEnemyBase
{
    GENERATED_BODY()

public:
    AOnil();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;
    virtual void UpdateMovement() override;

    UPROPERTY(EditAnywhere, Category = "AI")
    float PursuitRange = 5.f; // in tiles

private:
    void PickRandomDirection();
    void MoveTowardPlayer();
    bool IsDirectionBlocked(FVector2D Dir) const;

    FVector2D CurrentDirection = FVector2D::ZeroVector;
    float DirectionChangeTimer = 0.f;
};
