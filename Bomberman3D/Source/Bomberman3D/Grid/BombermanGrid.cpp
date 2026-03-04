// Fill out your copyright notice in the Description page of Project Settings.


#include "Grid/BombermanGrid.h"

// Sets default values
ABombermanGrid::ABombermanGrid()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ABombermanGrid::BeginPlay()
{
	Super::BeginPlay();

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
}

// Called every frame
void ABombermanGrid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// credits to: https://github.com/kubgus
bool ABombermanGrid::IsInBounds(int32 X, int32 Y) const {
	return X >= 0 && X < BaseGridHeight && Y >= 0 && Y < BaseGridWidth;
}
// end credits

bool ABombermanGrid::IsTileWalkable(int32 X, int32 Y) const {

	bool bIsWalkable;

	if (!IsInBounds(X, Y))
	{
		return false;
	}
	else {
		if (
			Data[X][Y] == ETileContent::SoftBlock ||
			Data[X][Y] == ETileContent::HardBlock ||
			Data[X][Y] == ETileContent::Bomb
			)
		{
			bIsWalkable = false;
		}
		else {
			bIsWalkable = true;
		}

		/*
		// can also be simplified to:
		return !(Data[X][Y] == ETileContent::SoftBlock ||
				 Data[X][Y] == ETileContent::HardBlock ||
				 Data[X][Y] == ETileContent::Bomb);
		*/
	}

	return bIsWalkable;
}

FVector ABombermanGrid::GetTileWorldPosition(int32 X, int32 Y) const {

	FVector Result = GetActorLocation();

	Result += { X * TileSize, Y * TileSize, 0.f };

	return Result;
}

ETileContent ABombermanGrid::GetTileContent(int32 X, int32 Y) const {

	if (!IsInBounds(X, Y))
	{
		return ETileContent::Empty;
	}
	else {
		return Data[X][Y];
	}
}

void ABombermanGrid::SetTileContent(int32 X, int32 Y, ETileContent NewContent) {
	if (!IsInBounds(X, Y))
	{
		return;
	}
	else {
		Data[X][Y] = NewContent;
	}
}

bool ABombermanGrid::IsTileSoft(int32 X, int32 Y) const {
	if (!IsInBounds(X, Y))
	{
		return false;
	}
	else {
		if (Data[X][Y] == ETileContent::SoftBlock) {
			return true;
		}
		else {
			return false;
		}
	}
}

FVector2D ABombermanGrid::GetGridPositionFromWorld(FVector WorldLocation) const
{
	FVector LocalPos = WorldLocation - GetActorLocation();
	return FVector2D(
		FMath::RoundToInt(LocalPos.X / TileSize),
		FMath::RoundToInt(LocalPos.Y / TileSize)
	);
}