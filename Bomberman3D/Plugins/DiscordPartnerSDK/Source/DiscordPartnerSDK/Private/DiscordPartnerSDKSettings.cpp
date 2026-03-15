// Copyright Discord, Inc. All Rights Reserved.

#include "DiscordPartnerSDKSettings.h"

UDiscordPartnerSDKSettings::UDiscordPartnerSDKSettings()
{
    // Initialize with a default application ID (empty string)
    ApplicationIdString = TEXT("");
}

FString UDiscordPartnerSDKSettings::GetApplicationIdString() const
{
    return ApplicationIdString;
}

int64 UDiscordPartnerSDKSettings::GetApplicationIdInt64() const
{
    FDiscordUniqueID appId = GetApplicationId();
    return static_cast<int64>(appId);
}

uint64 UDiscordPartnerSDKSettings::GetApplicationIdUint64() const
{
    FDiscordUniqueID appId = GetApplicationId();
    return static_cast<uint64>(appId);
}

FDiscordUniqueID UDiscordPartnerSDKSettings::GetApplicationId() const
{
    bool success;
    FDiscordUniqueID result = FDiscordUniqueID::FromString(ApplicationIdString, success);
    if (!success) {
        // Return 0 if parsing fails
        return FDiscordUniqueID(0);
    }
    return result;
}

const UDiscordPartnerSDKSettings* UDiscordPartnerSDKSettings::Get()
{
    return GetDefault<UDiscordPartnerSDKSettings>();
}

FName UDiscordPartnerSDKSettings::GetCategoryName() const
{
    return TEXT("Plugins");
}

FName UDiscordPartnerSDKSettings::GetSectionName() const
{
    return TEXT("Discord Social SDK");
}