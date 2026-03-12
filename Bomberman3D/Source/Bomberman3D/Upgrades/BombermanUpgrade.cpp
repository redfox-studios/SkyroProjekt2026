// Copyright (c) 2026, Michal Flaška & RedFox Studios. All Rights Reserved.

#include "Upgrades/BombermanUpgrade.h"
#include "Components/BoxComponent.h"
#include "Player/BombermanCharacter.h"
#include "Player/BombermanPlayerState.h"

ABombermanUpgrade::ABombermanUpgrade()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	OverlapBox = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapBox"));
	OverlapBox->SetupAttachment(RootComponent);
	OverlapBox->SetBoxExtent(FVector(40.f));
	OverlapBox->SetCollisionProfileName(TEXT("Trigger"));
	OverlapBox->bHiddenInGame = false;
}

void ABombermanUpgrade::BeginPlay()
{
	Super::BeginPlay();
	OverlapBox->OnComponentBeginOverlap.AddDynamic(this, &ABombermanUpgrade::OnOverlapBegin);
}

void ABombermanUpgrade::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	ABombermanCharacter* Player = Cast<ABombermanCharacter>(OtherActor);
	if (!Player) return;

	ABombermanPlayerState* PS = Player->GetPlayerState<ABombermanPlayerState>();
	if (!PS) return;

	switch (UpgradeType)
	{
	case EUpgradeType::BombUp:
		PS->Upgrades.BombUp = FMath::Min(PS->Upgrades.BombUp + 1, 10);
		break;
	case EUpgradeType::FireUp:
		PS->Upgrades.FireUp = FMath::Min(PS->Upgrades.FireUp + 1, 10);
		break;
	}

	Destroy();
}
