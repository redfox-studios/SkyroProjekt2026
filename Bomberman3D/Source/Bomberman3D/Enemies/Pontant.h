// Copyright (c) 2026, Michal Flaška & RedFox Studios. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Enemies/EnemyBase.h"
#include "Pontant.generated.h"

UCLASS()
class BOMBERMAN3D_API APontant : public AEnemyBase
{
    GENERATED_BODY()

public:
    APontant();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;
    virtual void UpdateMovement() override;

private:
    void ChasePlayer();
    bool IsDirectionBlocked(FVector2D Dir) const;

    FVector2D CurrentDirection = FVector2D::ZeroVector;
    float DirectionChangeTimer = 0.f;
};
