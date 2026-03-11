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
	if (CurrentState == EBombState::Detonating || CurrentState == EBombState::Explosion || CurrentState == EBombState::Cleanup)
		return;

	if (!Grid) return;

	CurrentState = EBombState::Detonating;

	// Clear timer - handles the case where we got chain-triggered before fuse expired
	GetWorld()->GetTimerManager().ClearTimer(FuseTimerHandle);

	Explode();
}

void ABombermanBomb::Explode()
{
	CurrentState = EBombState::Explosion;

	FVector2D BombGridPos = Grid->GetGridPositionFromWorld(GetActorLocation());
	int32 BX = FMath::RoundToInt(BombGridPos.X);
	int32 BY = FMath::RoundToInt(BombGridPos.Y);

	// Clear our tile first - prevents other explosion rays from trying to chain back into us
	Grid->SetTileContent(BX, BY, ETileContent::Empty);

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
			UE_LOG(LogTemp, Warning, TEXT("Checking tile [%d, %d] = %d"), X, Y, (int32)Tile);

			if (Tile == ETileContent::HardBlock)
			{
				break;
			}
			else if (Tile == ETileContent::SoftBlock)
			{
				Grid->DestroyActorOnTile(X, Y);
				break;
			}
			else if (Tile == ETileContent::Bomb)
			{
				UE_LOG(LogTemp, Warning, TEXT("Chain reaction triggered at [%d, %d]"), X, Y);
				Grid->SetTileContent(X, Y, ETileContent::Empty);
				TriggerChainReaction(X, Y);
				break;
			}
		}
	}

	CurrentState = EBombState::Cleanup;
	Destroy();
}

void ABombermanBomb::TriggerChainReaction(int32 X, int32 Y)
{
	UE_LOG(LogTemp, Warning, TEXT("Looking for bomb actor at [%d, %d]"), X, Y);

	for (TActorIterator<ABombermanBomb> It(GetWorld()); It; ++It)
	{
		ABombermanBomb* OtherBomb = *It;
		if (OtherBomb == this) continue;

		FVector2D OtherGridPos = Grid->GetGridPositionFromWorld(OtherBomb->GetActorLocation());
		if (FMath::RoundToInt(OtherGridPos.X) == X && FMath::RoundToInt(OtherGridPos.Y) == Y)
		{
			UE_LOG(LogTemp, Warning, TEXT("Found bomb actor, detonating"));
			OtherBomb->Detonate();
			return;
		}
	}
}
