// Copyright (c) 2026, Michal Flaška & RedFox Studios. All Rights Reserved.

#include "Enemies/Onil.h"
#include "Grid/BombermanGrid.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"

AOnil::AOnil()
{
    PrimaryActorTick.bCanEverTick = true;
    MoveSpeed = 150.f;
}

void AOnil::BeginPlay()
{
    Super::BeginPlay();
    PickRandomDirection();
}

void AOnil::Tick(float DeltaTime)
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

void AOnil::UpdateMovement()
{
    if (!Grid) return;

    ACharacter* Player = Cast<ACharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
    if (Player)
    {
        FVector2D MyTile = Grid->GetGridPositionFromWorld(GetActorLocation());
        FVector2D PlayerTile = Grid->GetGridPositionFromWorld(Player->GetActorLocation());
        float Distance = FVector2D::Distance(MyTile, PlayerTile);

        if (Distance <= PursuitRange)
        {
            MoveTowardPlayer();
            return;
        }
    }

    if (IsDirectionBlocked(CurrentDirection))
    {
        PickRandomDirection();
    }
}

void AOnil::MoveTowardPlayer()
{
    if (!Grid) return;

    ACharacter* Player = Cast<ACharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
    if (!Player) return;

    FVector2D MyTile = Grid->GetGridPositionFromWorld(GetActorLocation());
    FVector2D PlayerTile = Grid->GetGridPositionFromWorld(Player->GetActorLocation());

    FVector2D Diff = PlayerTile - MyTile;

    // Try to move along the dominant axis first, fall back to other axis
    TArray<FVector2D> Preferred;
    if (FMath::Abs(Diff.X) >= FMath::Abs(Diff.Y))
    {
        Preferred.Add(FVector2D(FMath::Sign(Diff.X), 0));
        Preferred.Add(FVector2D(0, FMath::Sign(Diff.Y)));
    }
    else
    {
        Preferred.Add(FVector2D(0, FMath::Sign(Diff.Y)));
        Preferred.Add(FVector2D(FMath::Sign(Diff.X), 0));
    }

    for (const FVector2D& Dir : Preferred)
    {
        if (!Dir.IsZero() && !IsDirectionBlocked(Dir))
        {
            CurrentDirection = Dir;
            return;
        }
    }

    // Both preferred directions blocked, fall back to random
    PickRandomDirection();
}

void AOnil::PickRandomDirection()
{
    const TArray<FVector2D> Directions = {
        FVector2D(1, 0), FVector2D(-1, 0),
        FVector2D(0, 1), FVector2D(0, -1)
    };

    TArray<FVector2D> Shuffled = Directions;
    for (int32 i = Shuffled.Num() - 1; i > 0; i--)
    {
        int32 j = FMath::RandRange(0, i);
        Shuffled.Swap(i, j);
    }

    for (const FVector2D& Dir : Shuffled)
    {
        if (!IsDirectionBlocked(Dir))
        {
            CurrentDirection = Dir;
            return;
        }
    }

    CurrentDirection = FVector2D::ZeroVector;
}

bool AOnil::IsDirectionBlocked(FVector2D Dir) const
{
    if (!Grid || Dir.IsZero()) return true;

    FVector2D GridPos = Grid->GetGridPositionFromWorld(GetActorLocation());
    int32 NX = FMath::RoundToInt(GridPos.X + Dir.X);
    int32 NY = FMath::RoundToInt(GridPos.Y + Dir.Y);

    return !Grid->IsTileWalkable(NX, NY) || IsNextTileOccupied(Dir);
}
