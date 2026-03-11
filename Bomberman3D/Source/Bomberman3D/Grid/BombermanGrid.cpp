// Copyright (c) 2026, Michal Flaška & RedFox Studios. All Rights Reserved.

#include "Grid/BombermanGrid.h"
#include "Engine/World.h"

ABombermanGrid::ABombermanGrid()
{
	PrimaryActorTick.bCanEverTick = true; // only needed for debug
}

void ABombermanGrid::BeginPlay()
{
	Super::BeginPlay();

	InitGrid();
	PlaceHardWalls();
}

void ABombermanGrid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bDrawDebug)
	{
		for (int32 X = 0; X < BaseGridHeight; X++)
			for (int32 Y = 0; Y < BaseGridWidth; Y++)
			{
				FVector Center = GetTileWorldPosition(X, Y) + FVector(0, 0, 50.f);
				FColor Color = Data[X][Y] == ETileContent::HardBlock ? FColor::Red :
					Data[X][Y] == ETileContent::SoftBlock ? FColor::Orange :
					Data[X][Y] == ETileContent::Bomb ? FColor::Yellow :
					FColor::Green;
				DrawDebugBox(GetWorld(), Center, FVector(TileSize * 0.45f), Color, false, -1.f, 0, 2.f);
			}
	}
}

void ABombermanGrid::InitGrid()
{
	Data.Empty();
	Data.Reserve(BaseGridHeight);

	for (int32 i = 0; i < BaseGridHeight; i++)
	{
		TArray<ETileContent> Row;
		Row.Reserve(BaseGridWidth);

		for (int32 j = 0; j < BaseGridWidth; j++)
		{
			Row.Add(ETileContent::Empty);
		}

		Data.Add(Row);
	}

	// Init actor map too
	ActorMap.Empty();
	ActorMap.Reserve(BaseGridHeight);
	for (int32 i = 0; i < BaseGridHeight; i++)
	{
		TArray<AActor*> Row;
		Row.Init(nullptr, BaseGridWidth);
		ActorMap.Add(Row);
	}
}

void ABombermanGrid::PlaceHardWalls()
{
	// Classic bomberman hard wall pattern:
	// Hard walls on every even row AND even column (checkerboard of pillars)
	// Plus the border

	for (int32 X = 0; X < BaseGridHeight; X++)
	{
		for (int32 Y = 0; Y < BaseGridWidth; Y++)
		{
			// Border
			if (X == 0 || X == BaseGridHeight - 1 || Y == 0 || Y == BaseGridWidth - 1)
			{
				Data[X][Y] = ETileContent::HardBlock;
				continue;
			}

			// Interior pillars - every even X and even Y
			if (X % 2 == 0 && Y % 2 == 0)
			{
				Data[X][Y] = ETileContent::HardBlock;
			}
		}
	}

	// Spawn hard wall actors if class is set
	if (!HardBlockClass) return;

	for (int32 X = 0; X < BaseGridHeight; X++)
	{
		for (int32 Y = 0; Y < BaseGridWidth; Y++)
		{
			if (Data[X][Y] == ETileContent::HardBlock)
			{
				SpawnActorOnTile(X, Y, HardBlockClass);
			}
		}
	}
}

// credits to: https://github.com/kubgus
bool ABombermanGrid::IsInBounds(int32 X, int32 Y) const
{
	return X >= 0 && X < BaseGridHeight && Y >= 0 && Y < BaseGridWidth;
}
// end credits

bool ABombermanGrid::IsTileWalkable(int32 X, int32 Y) const
{
	if (!IsInBounds(X, Y)) return false;

	ETileContent Tile = Data[X][Y];
	return Tile != ETileContent::SoftBlock &&
		Tile != ETileContent::HardBlock &&
		Tile != ETileContent::Bomb;
}

FVector ABombermanGrid::GetTileWorldPosition(int32 X, int32 Y) const
{
	FVector Result = GetActorLocation();
	Result += FVector(X * TileSize, Y * TileSize, 0.f);
	return Result;
}

ETileContent ABombermanGrid::GetTileContent(int32 X, int32 Y) const
{
	if (!IsInBounds(X, Y))
		return ETileContent::HardBlock; // out of bounds = treat as hard wall, stops explosions

	return Data[X][Y];
}

void ABombermanGrid::SetTileContent(int32 X, int32 Y, ETileContent NewContent)
{
	if (!IsInBounds(X, Y)) return;
	Data[X][Y] = NewContent;
}

bool ABombermanGrid::IsTileSoft(int32 X, int32 Y) const
{
	if (!IsInBounds(X, Y)) return false;
	return Data[X][Y] == ETileContent::SoftBlock;
}

FVector2D ABombermanGrid::GetGridPositionFromWorld(FVector WorldLocation) const
{
	FVector LocalPos = WorldLocation - GetActorLocation();
	return FVector2D(
		FMath::RoundToInt(LocalPos.X / TileSize),
		FMath::RoundToInt(LocalPos.Y / TileSize)
	);
}

AActor* ABombermanGrid::SpawnActorOnTile(int32 X, int32 Y, TSubclassOf<AActor> ActorClass)
{
	if (!IsInBounds(X, Y) || !ActorClass) return nullptr;

	// Don't double-spawn
	if (ActorMap[X][Y] != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("SpawnActorOnTile: tile [%d, %d] already has an actor"), X, Y);
		return nullptr;
	}

	FVector WorldPos = GetTileWorldPosition(X, Y);
	AActor* Spawned = GetWorld()->SpawnActor<AActor>(ActorClass, WorldPos, FRotator::ZeroRotator);

	if (Spawned)
	{
		ActorMap[X][Y] = Spawned;
	}

	return Spawned;
}

void ABombermanGrid::DestroyActorOnTile(int32 X, int32 Y)
{
	if (!IsInBounds(X, Y)) return;

	AActor* Actor = ActorMap[X][Y];
	if (!Actor) return;

	Actor->Destroy();
	ActorMap[X][Y] = nullptr;
	Data[X][Y] = ETileContent::Empty;
}

AActor* ABombermanGrid::GetActorOnTile(int32 X, int32 Y) const
{
	if (!IsInBounds(X, Y)) return nullptr;
	return ActorMap[X][Y];
}
