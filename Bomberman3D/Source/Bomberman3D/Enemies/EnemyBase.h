// Copyright (c) 2026, Michal Flaška & RedFox Studios. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/BombermanHealthComponent.h"
#include "Components/ArrowComponent.h"
#include "EnemyBase.generated.h"

class ABombermanGrid;

UCLASS(Abstract)
class BOMBERMAN3D_API AEnemyBase : public ACharacter
{
	GENERATED_BODY()

public:
	AEnemyBase();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	// Override in subclasses for unique behavior (pursuit, etc.)
	// Base implementation: pick random if blocked
	virtual void UpdateMovement();

	// Shared movement state
	FVector2D CurrentDirection = FVector2D::ZeroVector;
	float DirectionChangeTimer = 0.f;

	// Picks a random unblocked direction. Returns ZeroVector if all blocked.
	FVector2D PickRandomUnblockedDirection() const;

	// Default: checks walkable + not occupied by enemy
	// Override in subclasses that have wall-pass or other special rules
	virtual bool IsDirectionBlocked(FVector2D Dir) const;

	bool IsNextTileOccupied(FVector2D Dir) const;

	UFUNCTION()
	void OnCapsuleOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
		bool bFromSweep, const FHitResult& SweepResult);

public:
	UPROPERTY(VisibleAnywhere, Category = "Health")
	UBombermanHealthComponent* HealthComponent;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float MoveSpeed = 150.f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float DirectionChangeInterval = 0.5f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float CornerRoundingStrength = 5.f;

	ABombermanGrid* Grid = nullptr;

	void ApplyCornerRounding(float DeltaTime);

	UPROPERTY(VisibleAnywhere, Category = "Debug")
	UArrowComponent* DirectionArrow;

private:
	UFUNCTION()
	void OnDeath();
};
