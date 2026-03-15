// Copyright Discord, Inc. All Rights Reserved.

#pragma once

#include <charconv>
#include <cstdint>

#include "Kismet/BlueprintFunctionLibrary.h"

#include "DiscordUniqueID.generated.h"

USTRUCT(BlueprintType, meta = (DisplayName = "Discord Unique ID"), Category = "Discord Partner SDK")
struct DISCORDPARTNERSDK_API FDiscordUniqueID {
    GENERATED_BODY()

    FDiscordUniqueID();
    FDiscordUniqueID(uint64_t Value);

    FString ToString() const;
    static FDiscordUniqueID FromString(const FString& DiscordUniqueIDString, bool& Success);

    operator uint64_t() const;

    uint64_t Value;
};

FORCEINLINE uint32 GetTypeHash(const FDiscordUniqueID& UniqueId)
{
    return GetTypeHash(UniqueId.Value);
}

UCLASS()
class DISCORDPARTNERSDK_API UDiscordUniqueIDFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()

    UFUNCTION(BlueprintPure,
              meta = (DisplayName = "Equal (Discord Unique ID)",
                      CompactNodeTitle = "==",
                      Keywords = "== equal"),
              Category = "Discord Partner SDK")
    static bool EqualEqual_DiscordUniqueIDDiscordUniqueID(const FDiscordUniqueID& Left,
                                                          const FDiscordUniqueID& Right)
    {
        return Left.Value == Right.Value;
    }

    UFUNCTION(BlueprintPure,
              meta = (DisplayName = "Not Equal (Discord Unique ID)",
                      CompactNodeTitle = "!=",
                      Keywords = "!= not equal"),
              Category = "Discord Partner SDK")
    static bool NotEqual_DiscordUniqueIDDiscordUniqueID(const FDiscordUniqueID& Left,
                                                        const FDiscordUniqueID& Right)
    {
        return Left.Value != Right.Value;
    }

    UFUNCTION(BlueprintPure,
              meta = (DisplayName = "To String (Discord Unique ID)",
                      CompactNodeTitle = "->",
                      ScriptMethod = "ToString",
                      BlueprintThreadSafe),
              Category = "Discord Partner SDK")
    static FString Conv_DiscordUniqueIDToString(const FDiscordUniqueID& InUniqueID)
    {
        return InUniqueID.ToString();
    }

    UFUNCTION(BlueprintPure,
              meta = (DisplayName = "Parse String (Discord Unique ID)", BlueprintThreadSafe),
              Category = "Discord Partner SDK")
    static void Parse_StringToDiscordUniqueID(const FString& DiscordUniqueIDString,
                                              FDiscordUniqueID& OutUniqueID,
                                              bool& Success)
    {
        OutUniqueID = FDiscordUniqueID::FromString(DiscordUniqueIDString, Success);
    }
};

template <>
struct TStructOpsTypeTraits<FDiscordUniqueID> : TStructOpsTypeTraitsBase2<FDiscordUniqueID> {
    enum {
        WithZeroConstructor = true,
        WithCopy = true,
        WithIdenticalViaEquality = true,
    };
};
