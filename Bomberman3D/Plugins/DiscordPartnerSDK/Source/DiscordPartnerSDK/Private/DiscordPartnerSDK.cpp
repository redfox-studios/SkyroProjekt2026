// Copyright Discord, Inc. All Rights Reserved.

#include "DiscordPartnerSDK.h"
#include "DiscordPartnerSDK.Private.h"
#include "Core.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"
#include "DiscordPartnerSDKSettings.h"

#include "DiscordUnreal.h"
#include "HAL/UnrealMemory.h"

#define LOCTEXT_NAMESPACE "FDiscordPartnerSDKModule"

namespace discord {
static TArray<ModuleOnLoadFunction::LoadHandler>* OnLoadHandlers;
static TArray<ModuleOnLoadFunction::UnloadHandler>* OnUnloadHandlers;

ModuleOnLoadFunction::ModuleOnLoadFunction(ModuleOnLoadFunction::LoadHandler onLoad,
                                           ModuleOnLoadFunction::UnloadHandler onUnload)
{
    if (!OnLoadHandlers) {
        OnLoadHandlers = new TArray<ModuleOnLoadFunction::LoadHandler>();
        OnUnloadHandlers = new TArray<ModuleOnLoadFunction::UnloadHandler>();
    }
    OnLoadHandlers->Add(onLoad);
    OnUnloadHandlers->Add(onUnload);
}

}; // namespace discord

void FDiscordPartnerSDKModule::StartupModule()
{
#if !DISCORD_PARTNER_SDK_STUB
    FString BaseDir = IPluginManager::Get().FindPlugin("DiscordPartnerSDK")->GetBaseDir();
    FString LibraryPath;

    if (discord::OnLoadHandlers) {
        for (auto& Handler : *discord::OnLoadHandlers) {
            Handler(BaseDir, LibraryPath);
        }
        delete discord::OnLoadHandlers;
        discord::OnLoadHandlers = nullptr;
    }
#if PLATFORM_WINDOWS
#if DISCORD_DEBUG_API_ENABLED
    LibraryPath = FPaths::Combine(
      *BaseDir,
      TEXT("Binaries/ThirdParty/DiscordPartnerSDKLibrary/Win64/Debug/discord_partner_sdk.dll"));
#else
    LibraryPath = FPaths::Combine(
      *BaseDir,
      TEXT("Binaries/ThirdParty/DiscordPartnerSDKLibrary/Win64/Release/discord_partner_sdk.dll"));
#endif
// #elif PLATFORM_MAC
#elif PLATFORM_LINUX
#if DISCORD_DEBUG_API_ENABLED
    LibraryPath = FPaths::Combine(
      *BaseDir,
      TEXT("Binaries/ThirdParty/DiscordPartnerSDKLibrary/Linux/Debug/libdiscord_partner_sdk.so"));
#else
    LibraryPath = FPaths::Combine(
      *BaseDir,
      TEXT("Binaries/ThirdParty/DiscordPartnerSDKLibrary/Linux/Release/libdiscord_partner_sdk.so"));
#endif
#endif

    DiscordPartnerSDKLibraryHandle =
      !LibraryPath.IsEmpty() ? FPlatformProcess::GetDllHandle(*LibraryPath) : nullptr;

    if (!LibraryPath.IsEmpty() && !DiscordPartnerSDKLibraryHandle) {
        FMessageDialog::Open(EAppMsgType::Ok,
                             LOCTEXT("ThirdPartyLibraryError",
                                     "Failed to load Discord Partner SDK third party library"));
    }
#endif

    // Log the configured application ID
    const UDiscordPartnerSDKSettings* Settings = UDiscordPartnerSDKSettings::Get();
    if (Settings && Settings->GetApplicationIdUint64() != 0) {
        UE_LOG(LogTemp,
               Log,
               TEXT("Discord Application ID configured: %s"),
               *Settings->GetApplicationIdString());
    }
    else {
        UE_LOG(LogTemp,
               Warning,
               TEXT("Discord Application ID not configured. Please set it in Project Settings > "
                    "Plugins > Discord Partner SDK"));
    }
}

void FDiscordPartnerSDKModule::ShutdownModule()
{
#if !DISCORD_PARTNER_SDK_STUB
    if (discord::OnUnloadHandlers) {
        for (auto& Handler : *discord::OnUnloadHandlers) {
            Handler();
        }
        delete discord::OnUnloadHandlers;
        discord::OnUnloadHandlers = nullptr;
    }
    if (DiscordPartnerSDKLibraryHandle) {
        FPlatformProcess::FreeDllHandle(DiscordPartnerSDKLibraryHandle);
        DiscordPartnerSDKLibraryHandle = nullptr;
    }
#endif
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FDiscordPartnerSDKModule, DiscordPartnerSDK)
