// Copyright (c) 2026, Michal Flaška & RedFox Studios. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "InputMappingContext.h"
#include "InputAction.h"
#include "InputActionValue.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

#include "Bomb/BombermanBomb.h"

#include "BombermanCharacter.generated.h"

class ABombermanGrid;

UCLASS()
class BOMBERMAN3D_API ABombermanCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ABombermanCharacter();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// --- input actions ---

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* MoveAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* PlaceBombAction;

	// --- camera ---

	UPROPERTY(VisibleAnywhere, Category = "Camera")
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, Category = "Camera")
	UCameraComponent* Camera;

	// --- bomb ---

	UPROPERTY(EditDefaultsOnly, Category = "Bomb")
	TSubclassOf<ABombermanBomb> BombClass;

	// --- grid ---

	UPROPERTY(EditAnywhere, Category = "Grid")
	ABombermanGrid* Grid;

	UFUNCTION()
	FVector2D GetCurrentGridPosition() const;

private:
	void Move(const FInputActionValue& Value);
	void PlaceBomb(const FInputActionValue& Value);

	// Tracks how many bombs are currently live in the world
	int32 ActiveBombCount = 0;

	UFUNCTION()
	void OnBombDestroyed(AActor* DestroyedActor);
};
