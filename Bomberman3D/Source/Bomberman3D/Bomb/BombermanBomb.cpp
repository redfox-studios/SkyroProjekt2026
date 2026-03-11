// Copyright (c) 2026, Michal Flaška & RedFox Studios. All Rights Reserved.

#include "Bomb/BombermanBomb.h"
#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"
#include "Grid/BombermanGrid.h"
#include "EngineUtils.h"

ABombermanBomb::ABombermanBomb()
{
	PrimaryActorTick.bCanEverTick = false;

	BombMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Bomb Mesh"));
	RootComponent = BombMesh;
}

void ABombermanBomb::BeginPlay()
{
	Super::BeginPlay();

	Grid = Cast<ABombermanGrid>(UGameplayStatics::GetActorOfClass(GetWorld(), ABombermanGrid::StaticClass()));

	GetWorld()->GetTimerManager().SetTimer(
		FuseTimerHandle,
		this,
		&ABombermanBomb::Detonate,
		FuseTimer,
		false
	);
}

void ABombermanBomb::Detonate()
{
	// Already past Placed/Armed - don't double-detonate
	if (CurrentState == EBombState::Detonating || CurrentState == EBombState::Explosion || CurrentState == EBombState::Cleanup)
		return;

	if (!Grid) return;

	CurrentState = EBombState::Detonating;
	Explode();
}

void ABombermanBomb::Explode()
{
	CurrentState = EBombState::Explosion;

	FVector2D BombGridPos = Grid->GetGridPositionFromWorld(GetActorLocation());
	int32 BX = FMath::RoundToInt(BombGridPos.X);
	int32 BY = FMath::RoundToInt(BombGridPos.Y);

	// Clear this tile in the grid
	Grid->SetTileContent(BX, BY, ETileContent::Empty);

	// 4 directions: right, left, forward, back
	const TArray<FVector2D> Directions = {
		FVector2D(1, 0), FVector2D(-1, 0),
		FVector2D(0, 1), FVector2D(0, -1)
	};

	for (const FVector2D& Dir : Directions)
	{
		for (int32 i = 1; i <= BlastRadius; i++)
		{
			int32 X = BX + FMath::RoundToInt(Dir.X * i);
			int32 Y = BY + FMath::RoundToInt(Dir.Y * i);

			ETileContent Tile = Grid->GetTileContent(X, Y);

			if (Tile == ETileContent::HardBlock)
			{
				break; // hard wall, stop completely
			}
			else if (Tile == ETileContent::SoftBlock)
			{
				Grid->SetTileContent(X, Y, ETileContent::Empty);
				break; // destroys soft block, stops here
			}
			else if (Tile == ETileContent::Bomb)
			{
				TriggerChainReaction(X, Y);
				break; // chain reaction triggered, stop this ray
			}
			// ETileContent::Empty - keep expanding
		}
	}

	// Cleanup
	CurrentState = EBombState::Cleanup;
	GetWorld()->GetTimerManager().ClearTimer(FuseTimerHandle);
	Destroy();
}

void ABombermanBomb::TriggerChainReaction(int32 X, int32 Y)
{
	if (!Grid) return;

	FVector TileWorld = Grid->GetTileWorldPosition(X, Y);

	// Find the bomb actor sitting on this tile and detonate it
	for (TActorIterator<ABombermanBomb> It(GetWorld()); It; ++It)
	{
		ABombermanBomb* OtherBomb = *It;
		if (OtherBomb == this) continue;

		FVector2D OtherGridPos = Grid->GetGridPositionFromWorld(OtherBomb->GetActorLocation());
		int32 OX = FMath::RoundToInt(OtherGridPos.X);
		int32 OY = FMath::RoundToInt(OtherGridPos.Y);

		if (OX == X && OY == Y)
		{
			OtherBomb->Detonate();
			return;
		}
	}
}
