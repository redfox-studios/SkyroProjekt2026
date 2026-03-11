// Copyright (c) 2026, Michal Flaška & RedFox Studios. All Rights Reserved.


#include "Player/BombermanPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

void ABombermanPlayerController::BeginPlay() {
	Super::BeginPlay();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}
}
