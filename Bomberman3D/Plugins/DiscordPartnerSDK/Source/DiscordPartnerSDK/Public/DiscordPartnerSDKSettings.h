// Copyright Discord, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "DiscordUniqueID.h"
#include "DiscordPartnerSDKSettings.generated.h"

/**
 * Settings for Discord Social SDK
 * This class reads configuration from the INI file
 */
UCLASS(config = Engine, defaultconfig, meta = (DisplayName = "Discord Social SDK"))
class DISCORDPARTNERSDK_API UDiscordPartnerSDKSettings : public UDeveloperSettings {
    GENERATED_BODY()

public:
    UDiscordPartnerSDKSettings();

    /** Discord Application ID - required for OAuth authentication (enter as string, e.g.,
     * "1234567890123456789") */
    UPROPERTY(config,
              EditAnywhere,
              BlueprintReadWrite,
              Category = "Discord",
              meta = (DisplayName = "Application ID"))
    FString ApplicationIdString;

    /** Get the Discord application ID as a string for use in Android manifest */
    UFUNCTION(BlueprintCallable, Category = "Discord")
    FString GetApplicationIdString() const;

    /** Get the Discord application ID as a int64 for use with the SDK (Blueprint compatible) */
    UFUNCTION(BlueprintCallable, Category = "Discord")
    int64 GetApplicationIdInt64() const;

    /** Get the Discord application ID as a uint64 for use with the SDK (C++ only) */
    uint64 GetApplicationIdUint64() const;

    /** Get the Discord application ID as a FDiscordUniqueID */
    UFUNCTION(BlueprintCallable, Category = "Discord")
    FDiscordUniqueID GetApplicationId() const;

    /** Get the singleton instance of the settings */
    static const UDiscordPartnerSDKSettings* Get();

protected:
    virtual FName GetCategoryName() const override;
    virtual FName GetSectionName() const override;
};