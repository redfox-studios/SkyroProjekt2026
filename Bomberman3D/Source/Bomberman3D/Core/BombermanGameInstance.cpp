// Copyright (c) 2026, Michal Flaška & RedFox Studios. All Rights Reserved.

#include "Core/BombermanGameInstance.h"

void UBombermanGameInstance::ResetToDefaults()
{
	CurrentStage = 1;
	Lives = 3;
	Upgrades = FBombermanPlayerUpgrades();
}
