// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/BombermanCharacter.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Kismet/GameplayStatics.h"

#include "Grid/BombermanGrid.h"

#include "GameFramework/CharacterMovementComponent.h" // GetCharacterMovement()

// Sets default values
ABombermanCharacter::ABombermanCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false; // dont need ts

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->bUsePawnControlRotation = false; // bomberman has a fixed camera
	SpringArm->TargetArmLength = 400.f;
	SpringArm->bInheritYaw = false; // fixing the rotation bug
	GetCharacterMovement()->bOrientRotationToMovement = true; // fixing the rotation bug
	SpringArm->bDoCollisionTest = false; // TDD says no collision
	SpringArm->SetRelativeRotation(FRotator(-65.f, 0.f, 0.f));

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	GetCharacterMovement()->bOrientRotationToMovement = true;
	bUseControllerRotationYaw = false;
}

// Called when the game starts or when spawned
void ABombermanCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	Grid = Cast<ABombermanGrid>(UGameplayStatics::GetActorOfClass(GetWorld(), ABombermanGrid::StaticClass())); // moved from BP
}

// Called every frame
void ABombermanCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABombermanCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ABombermanCharacter::Move);
		EnhancedInput->BindAction(PlaceBombAction, ETriggerEvent::Started, this, &ABombermanCharacter::PlaceBomb);
	}
}

// --- custom funcs ---

FVector2D ABombermanCharacter::GetCurrentGridPosition() const
{
	if (Grid) // meow meow null check
	{
		return FVector2D(
			FMath::RoundToInt(GetActorLocation().X / Grid->GetTileSize()),
			FMath::RoundToInt(GetActorLocation().Y / Grid->GetTileSize())
		);
	}

	return FVector2D::ZeroVector; // in case the compiler will talk shit
}

void ABombermanCharacter::Move(const FInputActionValue& Value)
{
	FVector2D Input = Value.Get<FVector2D>();
	AddMovementInput(FVector::ForwardVector, Input.Y);
	AddMovementInput(FVector::RightVector, Input.X);
}

void ABombermanCharacter::PlaceBomb(const FInputActionValue& Value)
{
	if (Grid && BombClass) // meow meow null check
	{
		FVector2D GridPosition = GetCurrentGridPosition();
		FVector WorldPosition = Grid->GetTileWorldPosition(GridPosition.X, GridPosition.Y);

		GetWorld()->SpawnActor<ABombermanBomb>(BombClass, WorldPosition, GetActorRotation());

		UE_LOG(LogTemp, Warning, TEXT("Bomb Placed"));
	}
}