// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BombermanGrid.generated.h"

UCLASS()
class BOMBERMAN3D_API ABombermanGrid : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABombermanGrid();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
