// Copyright Discord, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

class FDiscordPartnerSDKModule : public IModuleInterface {
public:
    /** IModuleInterface implementation */
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

private:
    /** Handle to the dll we will load */
    void* DiscordPartnerSDKLibraryHandle;
};
