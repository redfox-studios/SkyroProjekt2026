// Copyright Discord, Inc. All Rights Reserved.

#pragma once

#include "DiscordUnreal.h"

#include "CoreMinimal.h"
#include "Containers/BackgroundableTicker.h"
#include "Subsystems/LocalPlayerSubsystem.h"
#include "DiscordLocalPlayerSubsystem.generated.h"

UCLASS(DisplayName = "Discord Player Subsystem")
class DISCORDPARTNERSDK_API UDiscordLocalPlayerSubsystem : public ULocalPlayerSubsystem {
    GENERATED_BODY()

public:
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    virtual void Deinitialize() override;
    virtual bool ShouldCreateSubsystem(UObject* Outer) const override;

    UFUNCTION(BlueprintCallable)
    void Connect(FString const& Token);

    UFUNCTION(BlueprintCallable)
    void Disconnect();

public:
    UPROPERTY(BlueprintReadOnly)
    UDiscordClient* Client;

    UPROPERTY(BlueprintAssignable)
    FDiscordClientOnStatusChangedMulticast OnStatusChanged;

    UPROPERTY(BlueprintAssignable)
    FDiscordClientActivityInviteCallbackMulticast OnActivityInvite;

    UPROPERTY(BlueprintAssignable)
    FDiscordClientActivityJoinCallbackMulticast OnActivityJoin;

    UPROPERTY(BlueprintAssignable)
    FDiscordClientLobbyCreatedCallbackMulticast OnLobbyCreated;

    UPROPERTY(BlueprintAssignable)
    FDiscordClientLobbyUpdatedCallbackMulticast OnLobbyUpdated;

    UPROPERTY(BlueprintAssignable)
    FDiscordClientLobbyDeletedCallbackMulticast OnLobbyDeleted;

    UPROPERTY(BlueprintAssignable)
    FDiscordClientLobbyMemberAddedCallbackMulticast OnLobbyMemberAdded;

    UPROPERTY(BlueprintAssignable)
    FDiscordClientLobbyMemberUpdatedCallbackMulticast OnLobbyMemberUpdated;

    UPROPERTY(BlueprintAssignable)
    FDiscordClientLobbyMemberRemovedCallbackMulticast OnLobbyMemberRemoved;

    UPROPERTY(BlueprintAssignable)
    FDiscordClientMessageCreatedCallbackMulticast OnMessageCreated;

    UPROPERTY(BlueprintAssignable)
    FDiscordClientMessageUpdatedCallbackMulticast OnMessageUpdated;

    UPROPERTY(BlueprintAssignable)
    FDiscordClientMessageDeletedCallbackMulticast OnMessageDeleted;

    UPROPERTY(BlueprintAssignable)
    FDiscordClientNoAudioInputCallbackMulticast OnNoAudioInput;

    UPROPERTY(BlueprintAssignable)
    FDiscordClientRelationshipCreatedCallbackMulticast OnRelationshipCreated;

    UPROPERTY(BlueprintAssignable)
    FDiscordClientRelationshipCreatedCallbackMulticast OnRelationshipDeleted;

    UPROPERTY(BlueprintAssignable)
    FDiscordClientUserUpdatedCallbackMulticast OnUserUpdated;

private:
    // Ticker handle for Discord_RunCallbacks
#if ENGINE_MAJOR_VERSION >= 5
    FTSTicker::FDelegateHandle TickerHandle;
#else
    FDelegateHandle TickerHandle;
#endif

    // Ticker callback function
    bool RunDiscordCallbacks(float DeltaTime);
};
