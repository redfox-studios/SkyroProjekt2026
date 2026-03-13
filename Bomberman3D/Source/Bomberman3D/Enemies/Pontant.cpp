// Copyright (c) 2026, Michal Flaška & RedFox Studios. All Rights Reserved.

#include "Enemies/Pontant.h"
#include "Grid/BombermanGrid.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"

APontant::APontant()
{
    PrimaryActorTick.bCanEverTick = true;
    MoveSpeed = 250.f; // faster than everyone else
}

void APontant::BeginPlay()
{
    Super::BeginPlay();
    ChasePlayer();
}

void APontant::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    DirectionChangeTimer += DeltaTime;

    if (DirectionChangeTimer >= DirectionChangeInterval)
    {
        DirectionChangeTimer = 0.f;
        UpdateMovement();
    }

    if (!CurrentDirection.IsZero())
    {
        AddMovementInput(FVector(CurrentDirection.X, CurrentDirection.Y, 0.f));
    }
}

void APontant::UpdateMovement()
{
    ChasePlayer();
}

void APontant::ChasePlayer()
{
    if (!Grid) return;

    ACharacter* Player = Cast<ACharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
    if (!Player) return;

    FVector2D MyTile = Grid->GetGridPositionFromWorld(GetActorLocation());
    FVector2D PlayerTile = Grid->GetGridPositionFromWorld(Player->GetActorLocation());
    FVector2D Diff = PlayerTile - MyTile;

    TArray<FVector2D> Preferred;
    if (FMath::Abs(Diff.X) >= FMath::Abs(Diff.Y))
    {
        Preferred.Add(FVector2D(FMath::Sign(Diff.X), 0));
        Preferred.Add(FVector2D(0, FMath::Sign(Diff.Y)));
        Preferred.Add(FVector2D(FMath::Sign(Diff.X) * -1, 0));
        Preferred.Add(FVector2D(0, FMath::Sign(Diff.Y) * -1));
    }
    else
    {
        Preferred.Add(FVector2D(0, FMath::Sign(Diff.Y)));
        Preferred.Add(FVector2D(FMath::Sign(Diff.X), 0));
        Preferred.Add(FVector2D(0, FMath::Sign(Diff.Y) * -1));
        Preferred.Add(FVector2D(FMath::Sign(Diff.X) * -1, 0));
    }

    for (const FVector2D& Dir : Preferred)
    {
        if (!Dir.IsZero() && !IsDirectionBlocked(Dir))
        {
            CurrentDirection = Dir;
            return;
        }
    }

    CurrentDirection = FVector2D::ZeroVector;
}

bool APontant::IsDirectionBlocked(FVector2D Dir) const
{
    if (!Grid || Dir.IsZero()) return true;

    FVector2D GridPos = Grid->GetGridPositionFromWorld(GetActorLocation());
    int32 NX = FMath::RoundToInt(GridPos.X + Dir.X);
    int32 NY = FMath::RoundToInt(GridPos.Y + Dir.Y);

    return !Grid->IsTileWalkable(NX, NY);
}
