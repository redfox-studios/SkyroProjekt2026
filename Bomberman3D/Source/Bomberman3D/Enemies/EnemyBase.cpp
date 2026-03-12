// Copyright (c) 2026, Michal Flaška & RedFox Studios. All Rights Reserved.

#include "Enemies/EnemyBase.h"
#include "Grid/BombermanGrid.h"
#include "Core/BombermanGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"

AEnemyBase::AEnemyBase()
{
	PrimaryActorTick.bCanEverTick = true;

	HealthComponent = CreateDefaultSubobject<UBombermanHealthComponent>(TEXT("HealthComponent"));

	GetCharacterMovement()->bOrientRotationToMovement = true;
	bUseControllerRotationYaw = false;

	GetCapsuleComponent()->SetCapsuleSize(30.f, 60.f);
	GetCapsuleComponent()->bHiddenInGame = false;
}

void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();

	Grid = Cast<ABombermanGrid>(UGameplayStatics::GetActorOfClass(GetWorld(), ABombermanGrid::StaticClass()));

	HealthComponent->OnDeath.AddDynamic(this, &AEnemyBase::OnDeath);

	GetCharacterMovement()->MaxWalkSpeed = MoveSpeed;

	SpawnDefaultController();
}

void AEnemyBase::OnDeath()
{
	// Notify GameMode
	if (ABombermanGameMode* GM = Cast<ABombermanGameMode>(GetWorld()->GetAuthGameMode()))
	{
		GM->OnEnemyDied();
	}

	Destroy();
}