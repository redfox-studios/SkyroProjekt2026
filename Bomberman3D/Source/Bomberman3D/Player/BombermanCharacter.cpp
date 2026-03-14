// Copyright (c) 2026, Michal Flaška & RedFox Studios. All Rights Reserved.

#include "Player/BombermanCharacter.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Kismet/GameplayStatics.h"

#include "Grid/BombermanGrid.h"
#include "Bomb/BombermanBomb.h"
#include "Player/BombermanPlayerState.h"
#include "Core/BombermanGameMode.h"

#include "GameFramework/CharacterMovementComponent.h"

ABombermanCharacter::ABombermanCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->bUsePawnControlRotation = false;
	SpringArm->TargetArmLength = 400.f;
	SpringArm->bInheritYaw = false;
	SpringArm->bDoCollisionTest = false;
	SpringArm->SetRelativeRotation(FRotator(-65.f, 0.f, 0.f));

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	HealthComponent = CreateDefaultSubobject<UBombermanHealthComponent>(TEXT("HealthComponent"));

	GetCharacterMovement()->bOrientRotationToMovement = true;
	bUseControllerRotationYaw = false;
}

void ABombermanCharacter::BeginPlay()
{
	Super::BeginPlay();

	Grid = Cast<ABombermanGrid>(UGameplayStatics::GetActorOfClass(GetWorld(), ABombermanGrid::StaticClass()));
	HealthComponent->OnDeath.AddDynamic(this, &ABombermanCharacter::OnDeath);

	GetCharacterMovement()->MaxWalkSpeed = BaseSpeed;
}

void ABombermanCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ABombermanCharacter::Move);
		EnhancedInput->BindAction(PlaceBombAction, ETriggerEvent::Started, this, &ABombermanCharacter::PlaceBomb);
	}
}

void ABombermanCharacter::Move(const FInputActionValue& Value)
{
	FVector2D Input = Value.Get<FVector2D>();
	AddMovementInput(FVector::ForwardVector, Input.Y);
	AddMovementInput(FVector::RightVector, Input.X);

	if (WalkSound && !GetCharacterMovement()->Velocity.IsZero())
	{
		UGameplayStatics::PlaySoundAtLocation(this, WalkSound, GetActorLocation());
	}
}

void ABombermanCharacter::PlaceBomb(const FInputActionValue& Value)
{
	if (!Grid || !BombClass) return;

	ABombermanPlayerState* PS = GetPlayerState<ABombermanPlayerState>();

	UE_LOG(LogTemp, Warning, TEXT("PlaceBomb called. ActiveBombCount: %d, MaxBombs: %d"),
		ActiveBombCount, PS ? PS->GetBombCount() : -1);

	FVector2D GridPos = GetCurrentGridPosition();
	int32 GX = FMath::RoundToInt(GridPos.X);
	int32 GY = FMath::RoundToInt(GridPos.Y);

	if (Grid->GetTileContent(GX, GY) != ETileContent::Empty) return;
	if (PS && ActiveBombCount >= PS->GetBombCount()) return;

	FVector WorldPos = Grid->GetTileWorldPosition(GX, GY);

	ABombermanBomb* Bomb = GetWorld()->SpawnActor<ABombermanBomb>(BombClass, WorldPos, FRotator::ZeroRotator);
	if (!Bomb) return;

	if (PlaceBombSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, PlaceBombSound, GetActorLocation());
	}

	Bomb->OwnerCharacter = this;

	if (PS)
	{
		Bomb->BlastRadius = PS->GetBlastRadius();
	}

	Grid->SetTileContent(GX, GY, ETileContent::Bomb);
	ActiveBombCount++;

	Bomb->OnDestroyed.AddDynamic(this, &ABombermanCharacter::OnBombDestroyed);

	UE_LOG(LogTemp, Warning, TEXT("Bomb placed at [%d, %d]"), GX, GY);
}

void ABombermanCharacter::OnBombDestroyed(AActor* DestroyedActor)
{
	ActiveBombCount = FMath::Max(0, ActiveBombCount - 1);
}

void ABombermanCharacter::OnDeath()
{
	ABombermanPlayerState* PS = GetPlayerState<ABombermanPlayerState>();
	if (!PS) return;

	PS->Lives--;

	UE_LOG(LogTemp, Warning, TEXT("Player died. Lives remaining: %d"), PS->Lives);

	if (DeathSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, DeathSound, GetActorLocation());
	}

	if (PS->Lives <= 0)
	{
		if (ABombermanGameMode* GM = Cast<ABombermanGameMode>(GetWorld()->GetAuthGameMode()))
		{
			GM->OnGameOver();
		}
		return;
	}

	// Still has lives - reset and respawn
	HealthComponent->ResetHealth();
	SetActorLocation(Grid ? Grid->GetPlayerSpawnPosition() : FVector::ZeroVector);
}

FVector2D ABombermanCharacter::GetCurrentGridPosition() const
{
	if (Grid)
		return Grid->GetGridPositionFromWorld(GetActorLocation());

	return FVector2D::ZeroVector;
}
