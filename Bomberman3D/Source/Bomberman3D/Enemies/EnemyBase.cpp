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

// debug arrow
	DirectionArrow = CreateDefaultSubobject<UArrowComponent>(TEXT("DirectionArrow"));
	DirectionArrow->SetupAttachment(RootComponent);
#if WITH_EDITOR
	DirectionArrow->SetHiddenInGame(false);
#else
	DirectionArrow->SetHiddenInGame(true);
#endif
}

void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();

	Grid = Cast<ABombermanGrid>(UGameplayStatics::GetActorOfClass(GetWorld(), ABombermanGrid::StaticClass()));
	HealthComponent->OnDeath.AddDynamic(this, &AEnemyBase::OnDeath);
	GetCharacterMovement()->MaxWalkSpeed = MoveSpeed;

	SpawnDefaultController();

	// Pick an initial direction
	CurrentDirection = PickRandomUnblockedDirection();

	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AEnemyBase::OnCapsuleOverlap);
}

void AEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ApplyCornerRounding(DeltaTime);

	DirectionChangeTimer += DeltaTime;
	if (DirectionChangeTimer >= DirectionChangeInterval)
	{
		DirectionChangeTimer = 0.f;
		UpdateMovement();
	}

	if (!CurrentDirection.IsZero())
	{
		AddMovementInput(FVector(CurrentDirection.X, CurrentDirection.Y, 0.f));
	}
}

void AEnemyBase::UpdateMovement()
{
	if (IsDirectionBlocked(CurrentDirection))
	{
		CurrentDirection = PickRandomUnblockedDirection();
	}
}

FVector2D AEnemyBase::PickRandomUnblockedDirection() const
{
	const TArray<FVector2D> Directions = {
		FVector2D(1, 0), FVector2D(-1, 0),
		FVector2D(0, 1), FVector2D(0, -1)
	};

	TArray<FVector2D> Shuffled = Directions;
	for (int32 i = Shuffled.Num() - 1; i > 0; i--)
	{
		int32 j = FMath::RandRange(0, i);
		Shuffled.Swap(i, j);
	}

	for (const FVector2D& Dir : Shuffled)
	{
		if (!IsDirectionBlocked(Dir))
			return Dir;
	}

	return FVector2D::ZeroVector;
}

bool AEnemyBase::IsDirectionBlocked(FVector2D Dir) const
{
	if (!Grid || Dir.IsZero()) return true;

	FVector2D GridPos = Grid->GetGridPositionFromWorld(GetActorLocation());
	int32 NX = FMath::RoundToInt(GridPos.X + Dir.X);
	int32 NY = FMath::RoundToInt(GridPos.Y + Dir.Y);

	return !Grid->IsTileWalkable(NX, NY) || IsNextTileOccupied(Dir);
}

bool AEnemyBase::IsNextTileOccupied(FVector2D Dir) const
{
	if (!Grid) return false;

	FVector2D GridPos = Grid->GetGridPositionFromWorld(GetActorLocation());
	int32 NX = FMath::RoundToInt(GridPos.X + Dir.X);
	int32 NY = FMath::RoundToInt(GridPos.Y + Dir.Y);

	return Grid->IsTileOccupiedByEnemy(NX, NY);
}

void AEnemyBase::OnDeath()
{
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

	FVector Vel = GetCharacterMovement()->Velocity;
	bool bMovingX = FMath::Abs(Vel.X) > FMath::Abs(Vel.Y);

	if (bMovingX)
	{
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
		float DeltaX = TileCenter.X - Pos.X;
		if (FMath::Abs(DeltaX) > 1.f)
		{
			FVector NewPos = Pos;
			NewPos.X += DeltaX * CornerRoundingStrength * DeltaTime;
			SetActorLocation(NewPos);
		}
	}
}

void AEnemyBase::OnCapsuleOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	if (UBombermanHealthComponent* Health = OtherActor->FindComponentByClass<UBombermanHealthComponent>())
	{
		Health->TakeDamage(1.f);
	}
}
