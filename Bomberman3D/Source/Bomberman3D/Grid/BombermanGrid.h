// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BombermanGrid.generated.h"

UENUM(BlueprintType)
enum class ETileContent : uint8
{
	Empty       UMETA(DisplayName = "Empty"),
	SoftBlock   UMETA(DisplayName = "Soft Block"),
	HardBlock   UMETA(DisplayName = "Hard Block"),
	Bomb        UMETA(DisplayName = "Bomb"),
	Upgrade     UMETA(DisplayName = "Upgrade"),
	Door        UMETA(DisplayName = "Door")
};

UCLASS()
class BOMBERMAN3D_API ABombermanGrid : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABombermanGrid();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Grid Config")
	int32 BaseGridWidth = 13;

	UPROPERTY(EditAnywhere, Category = "Grid Config")
	int32 BaseGridHeight = 11;

	UPROPERTY(EditAnywhere, Category = "Grid Config")
	int32 GridGrowthPerStages = 10; // every X stages, grid grows by 1 in each direction

	UPROPERTY(EditAnywhere, Category = "Grid Config")
	int32 MaxGridWidth = 21;

	UPROPERTY(EditAnywhere, Category = "Grid Config")
	int32 MaxGridHeight = 17;

	UPROPERTY(EditAnywhere, Category = "Grid Config")
	float TileSize = 100.f;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	bool IsTileWalkable(int32 X, int32 Y) const;

	UFUNCTION(BlueprintCallable)
	FVector GetTileWorldPosition(int32 X, int32 Y) const;

	UFUNCTION(BlueprintCallable)
	ETileContent GetTileContent(int32 X, int32 Y) const;

	UFUNCTION(BlueprintCallable)
	void SetTileContent(int32 X, int32 Y, ETileContent NewContent);

	UFUNCTION(BlueprintCallable)
	bool IsTileSoft(int32 X, int32 Y) const;

	UFUNCTION(BlueprintCallable)
	bool IsInBounds(int32 X, int32 Y) const;

public:
	float GetTileSize() const { return TileSize; }
	FVector2D GetCurrentGridPosition() const;

	UFUNCTION(BlueprintCallable)
	FVector2D GetGridPositionFromWorld(FVector WorldLocation) const;

private:
	TArray<TArray<ETileContent>> Data;
};
