// Copyright (c) 2026, Michal Flaška & RedFox Studios. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/BombermanHealthComponent.h"
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

public:
	// Override in subclasses to implement specific movement behavior
	virtual void UpdateMovement() {}

	UPROPERTY(VisibleAnywhere, Category = "Health")
	UBombermanHealthComponent* HealthComponent;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float MoveSpeed = 150.f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float DirectionChangeInterval = 0.5f;

	ABombermanGrid* Grid = nullptr;

	void ApplyCornerRounding(float DeltaTime);

	UPROPERTY(EditAnywhere, Category = "Movement")
	float CornerRoundingStrength = 5.f;

	bool IsNextTileOccupied(FVector2D Dir) const;

private:
	UFUNCTION()
	void OnDeath();
};
