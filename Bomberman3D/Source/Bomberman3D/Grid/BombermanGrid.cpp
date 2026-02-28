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

