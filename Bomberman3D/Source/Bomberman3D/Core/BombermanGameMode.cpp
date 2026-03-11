// Copyright (c) 2026, Michal Flaška & RedFox Studios. All Rights Reserved.


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
