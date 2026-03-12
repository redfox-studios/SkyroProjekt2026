// Copyright (c) 2026, Michal Flaška & RedFox Studios. All Rights Reserved.

#include "Enemies/Ballom.h"
#include "Grid/BombermanGrid.h"
#include "GameFramework/CharacterMovementComponent.h"

ABallom::ABallom()
{
	PrimaryActorTick.bCanEverTick = true;
	MoveSpeed = 100.f;
}

void ABallom::BeginPlay()
{
	Super::BeginPlay();
	PickNewDirection();
}

void ABallom::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DirectionChangeTimer += DeltaTime;

	if (DirectionChangeTimer >= DirectionChangeInterval)
	{
		DirectionChangeTimer = 0.f;
		UpdateMovement();
	}

	// Apply movement every frame
	if (!CurrentDirection.IsZero())
	{
		AddMovementInput(FVector(CurrentDirection.X, CurrentDirection.Y, 0.f));
	}
}

void ABallom::UpdateMovement()
{
	if (IsDirectionBlocked(CurrentDirection))
	{
		PickNewDirection();
	}
}

void ABallom::PickNewDirection()
{
	const TArray<FVector2D> Directions = {
		FVector2D(1, 0), FVector2D(-1, 0),
		FVector2D(0, 1), FVector2D(0, -1)
	};

	// Shuffle and pick first unblocked direction
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

	// All directions blocked - stop
	CurrentDirection = FVector2D::ZeroVector;
}

bool ABallom::IsDirectionBlocked(FVector2D Dir) const
{
	if (!Grid || Dir.IsZero()) return true;

	FVector2D GridPos = Grid->GetGridPositionFromWorld(GetActorLocation());
	int32 NX = FMath::RoundToInt(GridPos.X + Dir.X);
	int32 NY = FMath::RoundToInt(GridPos.Y + Dir.Y);

	return !Grid->IsTileWalkable(NX, NY);
}