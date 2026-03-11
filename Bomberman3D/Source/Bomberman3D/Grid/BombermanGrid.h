// Copyright (c) 2026, Michal Flaška & RedFox Studios. All Rights Reserved.

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
	ABombermanGrid();

protected:
	virtual void BeginPlay() override;

	// --- config ---

	UPROPERTY(EditAnywhere, Category = "Grid Config")
	int32 BaseGridWidth = 13;

	UPROPERTY(EditAnywhere, Category = "Grid Config")
	int32 BaseGridHeight = 11;

	UPROPERTY(EditAnywhere, Category = "Grid Config")
	int32 GridGrowthPerStages = 10;

	UPROPERTY(EditAnywhere, Category = "Grid Config")
	int32 MaxGridWidth = 21;

	UPROPERTY(EditAnywhere, Category = "Grid Config")
	int32 MaxGridHeight = 17;

	UPROPERTY(EditAnywhere, Category = "Grid Config")
	float TileSize = 100.f;

	// Assign a hard block static mesh actor BP here in editor
	UPROPERTY(EditAnywhere, Category = "Grid Config")
	TSubclassOf<AActor> HardBlockClass;

public:
	virtual void Tick(float DeltaTime) override;

	// --- tile queries ---

	UFUNCTION(BlueprintCallable)
	bool IsInBounds(int32 X, int32 Y) const;

	UFUNCTION(BlueprintCallable)
	bool IsTileWalkable(int32 X, int32 Y) const;

	UFUNCTION(BlueprintCallable)
	bool IsTileSoft(int32 X, int32 Y) const;

	UFUNCTION(BlueprintCallable)
	ETileContent GetTileContent(int32 X, int32 Y) const;

	UFUNCTION(BlueprintCallable)
	void SetTileContent(int32 X, int32 Y, ETileContent NewContent);

	UFUNCTION(BlueprintCallable)
	FVector GetTileWorldPosition(int32 X, int32 Y) const;

	UFUNCTION(BlueprintCallable)
	FVector2D GetGridPositionFromWorld(FVector WorldLocation) const;

	// --- actor spawning ---

	UFUNCTION(BlueprintCallable)
	AActor* SpawnActorOnTile(int32 X, int32 Y, TSubclassOf<AActor> ActorClass);

	UFUNCTION(BlueprintCallable)
	void DestroyActorOnTile(int32 X, int32 Y);

	UFUNCTION(BlueprintCallable)
	AActor* GetActorOnTile(int32 X, int32 Y) const;

	// --- misc ---

	float GetTileSize() const { return TileSize; }

private:
	void InitGrid();
	void PlaceHardWalls();

	TArray<TArray<ETileContent>> Data;

	// Parallel array to Data - tracks which actor is on each tile
	TArray<TArray<AActor*>> ActorMap;
};
