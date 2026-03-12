// Copyright (c) 2026, Michal Flaška & RedFox Studios. All Rights Reserved.

#include "Door/BombermanDoor.h"
#include "Components/BoxComponent.h"
#include "Player/BombermanCharacter.h"
#include "Core/BombermanGameMode.h"

ABombermanDoor::ABombermanDoor()
{
	PrimaryActorTick.bCanEverTick = false;

	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	RootComponent = DoorMesh;

	OverlapBox = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapBox"));
	OverlapBox->SetupAttachment(RootComponent);
	OverlapBox->SetBoxExtent(FVector(40.f));
	OverlapBox->SetCollisionProfileName(TEXT("Trigger"));
}

void ABombermanDoor::BeginPlay()
{
	Super::BeginPlay();
	OverlapBox->OnComponentBeginOverlap.AddDynamic(this, &ABombermanDoor::OnOverlapBegin);
}

void ABombermanDoor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	if (!Cast<ABombermanCharacter>(OtherActor)) return;

	if (ABombermanGameMode* GM = Cast<ABombermanGameMode>(GetWorld()->GetAuthGameMode()))
	{
		GM->OnPlayerEnteredDoor();
	}
}
