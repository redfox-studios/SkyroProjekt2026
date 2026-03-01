// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/BombermanGameMode.h"

#include "Player/BombermanPlayerController.h"
#include "Player/BombermanCharacter.h"
#include "Player/BombermanPlayerState.h"

ABombermanGameMode::ABombermanGameMode()
{
    DefaultPawnClass = ABombermanCharacter::StaticClass();
    PlayerControllerClass = ABombermanPlayerController::StaticClass();
    PlayerStateClass = ABombermanPlayerState::StaticClass();
}