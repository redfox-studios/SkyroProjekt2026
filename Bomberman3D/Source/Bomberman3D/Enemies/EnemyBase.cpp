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

void AEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ApplyCornerRounding(DeltaTime);
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

void AEnemyBase::ApplyCornerRounding(float DeltaTime)
{
    // https://www.construct.net/en/forum/game-development/game-development-design-ideas-25/bomberman-mechanics-ai-128684
    // https://www.gamedev.net/forums/topic/622051-ai-for-simple-bomberman-game/

    if (!Grid) return;

    FVector Pos = GetActorLocation();
    FVector2D GridPos = Grid->GetGridPositionFromWorld(Pos);
    FVector TileCenter = Grid->GetTileWorldPosition(
        FMath::RoundToInt(GridPos.X),
        FMath::RoundToInt(GridPos.Y)
    );

    // figure out movement direction from velocity
    FVector Vel = GetCharacterMovement()->Velocity;
    bool bMovingX = FMath::Abs(Vel.X) > FMath::Abs(Vel.Y);

    if (bMovingX)
    {
        // moving along x - snap y toward tile center
        float DeltaY = TileCenter.Y - Pos.Y;
        if (FMath::Abs(DeltaY) > 1.f)
        {
            FVector NewPos = Pos;
            NewPos.Y += DeltaY * CornerRoundingStrength * DeltaTime;
            SetActorLocation(NewPos);
        }
    }
    else
    {
        // moving along y - snap x toward tile center
        float DeltaX = TileCenter.X - Pos.X;
        if (FMath::Abs(DeltaX) > 1.f)
        {
            FVector NewPos = Pos;
            NewPos.X += DeltaX * CornerRoundingStrength * DeltaTime;
            SetActorLocation(NewPos);
        }
    }
}
