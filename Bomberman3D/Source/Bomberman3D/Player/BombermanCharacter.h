// Fill out your copyright notice in the Description page of Project Settings.

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
	// Sets default values for this character's properties
	ABombermanCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// --- input ---

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* MoveAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* PlaceBombAction;

	// --- input refs ---

	void Move(const FInputActionValue& Value);
	void PlaceBomb(const FInputActionValue& Value);

	// --- camera ---

	UPROPERTY(VisibleAnywhere, Category = "Camera")
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, Category = "Camera")
	UCameraComponent* Camera;

	// --- bomb ---
	UPROPERTY(EditDefaultsOnly, Category = "Bomb")
	TSubclassOf<ABombermanBomb> BombClass;

	// --- misc ---

	UPROPERTY(EditAnywhere, Category = "Grid")
	ABombermanGrid* Grid;

	FVector2D GetCurrentGridPosition() const;
};
