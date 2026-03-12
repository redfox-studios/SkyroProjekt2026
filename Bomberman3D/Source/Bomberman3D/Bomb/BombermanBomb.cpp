// Copyright (c) 2026, Michal Flaška & RedFox Studios. All Rights Reserved.

#include "Bomb/BombermanBomb.h"
#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"
#include "Grid/BombermanGrid.h"
#include "Components/BombermanHealthComponent.h"
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

	// Damage anything on the bomb's own tile
	DamageActorsOnTile(BX, BY);

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
				DamageActorsOnTile(X, Y);
				break;
			}
			else if (Tile == ETileContent::Bomb)
			{
				UE_LOG(LogTemp, Warning, TEXT("Chain reaction triggered at [%d, %d]"), X, Y);
				Grid->SetTileContent(X, Y, ETileContent::Empty);
				TriggerChainReaction(X, Y);
				break;
			}
			else
			{
				// Empty tile - damage anything standing here (player, enemy)
				DamageActorsOnTile(X, Y);
			}
		}
	}

	CurrentState = EBombState::Cleanup;
	Destroy();
}

void ABombermanBomb::DamageActorsOnTile(int32 X, int32 Y) const
{
	UE_LOG(LogTemp, Warning, TEXT("Looking for bomb actor at [%d, %d]"), X, Y);
	if (!Grid) return;

	FVector TileWorld = Grid->GetTileWorldPosition(X, Y);
	float HalfTile = Grid->GetTileSize() * 0.5f;

	// Overlap check - find all actors within this tile's bounds
	TArray<AActor*> OverlappingActors;
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes = {
		UEngineTypes::ConvertToObjectType(ECC_Pawn)
	};

	UKismetSystemLibrary::BoxOverlapActors(
		GetWorld(),
		TileWorld,
		FVector(HalfTile * 0.9f), // slightly smaller than tile to avoid edge bleed
		ObjectTypes,
		nullptr,
		TArray<AActor*>{ const_cast<ABombermanBomb*>(this) },
		OverlappingActors
	);

	for (AActor* Actor : OverlappingActors)
	{
		if (!Actor) continue;

		UBombermanHealthComponent* Health = Actor->FindComponentByClass<UBombermanHealthComponent>();
		if (Health)
		{
			Health->TakeDamage(1.f);
		}
	}
}

void ABombermanBomb::TriggerChainReaction(int32 X, int32 Y)
{
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
