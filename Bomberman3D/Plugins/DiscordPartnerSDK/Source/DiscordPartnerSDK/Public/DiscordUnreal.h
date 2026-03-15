// Generated with <3 by Discord.Sdk.Derive
#pragma once
#ifndef DISCORD_PARTNER_SDK_STUB
#define DISCORD_PARTNER_SDK_STUB 0
#endif

#if !DISCORD_PARTNER_SDK_STUB
#include "cdiscord.h"
#endif

#include "CoreMinimal.h"
#include "DiscordUniqueID.h"
#include "DiscordUnreal.generated.h"

enum class DiscordUObjectState {
    Invalid,
    Owned,
};

/// \brief ActivityActionTypes represents the type of invite being sent to a user.
///
/// There are essentially two types of invites:
/// 1: A user with an existing activity party can invite another user to join that existing party
/// 2: A user can request to join the existing activity party of another user
///
/// See https://discord.com/developers/docs/rich-presence/overview for more information.
UENUM(BlueprintType, Category = "Discord Partner SDK")
enum class EDiscordActivityActionTypes : uint8 {

    /// \brief Invalid
    Invalid = 0 UMETA(DisplayName = "Invalid"),

    /// \brief Join
    Join = 1 UMETA(DisplayName = "Join"),

    /// \brief JoinRequest
    JoinRequest = 5 UMETA(DisplayName = "JoinRequest"),
};

/// \brief Allows your game to control the privacy of the party the user is in.
UENUM(BlueprintType, Category = "Discord Partner SDK")
enum class EDiscordActivityPartyPrivacy : uint8 {

    /// \brief The party is private (or unknown), which means that the user is in a party but it is
    /// not
    /// joinable without sending a request to join the party.
    ///
    /// This is the default value. You will also receive this value when receiving other users'
    /// activities as the party privacy for other users is not exposed.
    Private = 0 UMETA(DisplayName = "Private"),

    /// \brief The party is public, which means that the user is in a party which *could* be
    /// joinable by
    /// either friends or mutual voice participants without sending a request to join the party.
    /// This depends on a user's desired Discord account privacy settings.
    Public = 1 UMETA(DisplayName = "Public"),
};

/// \brief Discord RichPresence supports multiple types of activities that a user can be doing.
///
/// For the SDK, the only activity type that is really relevant is `Playing`.
/// The others are provided for completeness.
///
/// See https://discord.com/developers/docs/rich-presence/overview for more information.
UENUM(BlueprintType, Category = "Discord Partner SDK")
enum class EDiscordActivityTypes : uint8 {

    /// \brief Playing
    Playing = 0 UMETA(DisplayName = "Playing"),

    /// \brief Streaming
    Streaming = 1 UMETA(DisplayName = "Streaming"),

    /// \brief Listening
    Listening = 2 UMETA(DisplayName = "Listening"),

    /// \brief Watching
    Watching = 3 UMETA(DisplayName = "Watching"),

    /// \brief CustomStatus
    CustomStatus = 4 UMETA(DisplayName = "CustomStatus"),

    /// \brief Competing
    Competing = 5 UMETA(DisplayName = "Competing"),

    /// \brief HangStatus
    HangStatus = 6 UMETA(DisplayName = "HangStatus"),
};

/// \brief Controls which Discord RichPresence field is displayed in the user's status.
///
/// See https://discord.com/developers/docs/rich-presence/overview for more information.
UENUM(BlueprintType, Category = "Discord Partner SDK")
enum class EDiscordStatusDisplayTypes : uint8 {

    /// \brief Name
    Name = 0 UMETA(DisplayName = "Name"),

    /// \brief State
    State = 1 UMETA(DisplayName = "State"),

    /// \brief Details
    Details = 2 UMETA(DisplayName = "Details"),
};

/// \brief Represents the type of platforms that an activity invite can be accepted on.
UENUM(BlueprintType, Category = "Discord Partner SDK")
enum class EDiscordActivityGamePlatforms : uint8 {
    GeneratedUnknownValue__ = 0 UMETA(DisplayName = "Unknown"),

    /// \brief Desktop
    Desktop = 1 UMETA(DisplayName = "Desktop"),

    /// \brief Xbox
    Xbox = 2 UMETA(DisplayName = "Xbox"),

    /// \brief Samsung
    Samsung = 4 UMETA(DisplayName = "Samsung"),

    /// \brief IOS
    IOS = 8 UMETA(DisplayName = "IOS"),

    /// \brief Android
    Android = 16 UMETA(DisplayName = "Android"),

    /// \brief Embedded
    Embedded = 32 UMETA(DisplayName = "Embedded"),

    /// \brief PS4
    PS4 = 64 UMETA(DisplayName = "PS4"),

    /// \brief PS5
    PS5 = 128 UMETA(DisplayName = "PS5"),
};

/// \brief Enum representing various types of errors the SDK returns.
UENUM(BlueprintType, Category = "Discord Partner SDK")
enum class EDiscordErrorType : uint8 {

    /// \brief No error, the operation was successful.
    None = 0 UMETA(DisplayName = "None"),

    /// \brief The user is offline or there was some network issue that prevented an underlying
    /// HTTP call from succeeding.
    NetworkError = 1 UMETA(DisplayName = "NetworkError"),

    /// \brief An HTTP call was made to Discord's servers but a non success HTTP status code was
    /// returned.
    /// In some cases this may be retryable, and if so ClientResult::Retryable will be true.
    /// In most cases though the failure is due to a validation or permissions error, and the
    /// request is not retryable. ClientResult::Error and ClientResult::ErrorCode will have more
    /// information.
    HTTPError = 2 UMETA(DisplayName = "HTTPError"),

    /// \brief An operation such as sending a friend request or joining a lobby was attempted but
    /// the
    /// Client is not yet ready. Wait for Client::Status to change to Client::Status::Ready before
    /// trying again.
    ///
    /// Also be sure to call Client::Connect to begin the process of connecting to Discord's
    /// servers, otherwise
    /// the Client will never become ready.
    ClientNotReady = 3 UMETA(DisplayName = "ClientNotReady"),

    /// \brief An operation was temporarily disabled for stability reasons.
    Disabled = 4 UMETA(DisplayName = "Disabled"),

    /// \brief The Client has been destroyed and so this operation cannot complete.
    ClientDestroyed = 5 UMETA(DisplayName = "ClientDestroyed"),

    /// \brief Used when an SDK method is called but the inputs don't pass local validation. For
    /// example
    /// if one attempts to accept a friend request when there is no pending friend request for that
    /// user,
    /// this ErrorType would be used.
    ///
    /// The specific validation error will be included in the `error` field, and no other
    /// ClientResult fields will be set.
    ValidationError = 6 UMETA(DisplayName = "ValidationError"),

    /// \brief The user or developer aborted an operation, such as an authorization flow.
    Aborted = 7 UMETA(DisplayName = "Aborted"),

    /// \brief An authorization function failed, but not necessarily as the result of an HTTP call
    /// that
    /// returned an error.
    AuthorizationFailed = 8 UMETA(DisplayName = "AuthorizationFailed"),

    /// \brief An RPC call was made to Discord's desktop application, but it returned a non-success
    /// result.
    /// The error and errorCode fields should both be set with more information.
    RPCError = 9 UMETA(DisplayName = "RPCError"),
};

/// \brief Represents the crypto method used to generate a code challenge.
///
/// The only method used by the SDK is sha256.
UENUM(BlueprintType, Category = "Discord Partner SDK")
enum class EDiscordAuthenticationCodeChallengeMethod : uint8 {

    /// \brief S256
    S256 = 0 UMETA(DisplayName = "S256"),
};

/// \brief Represents the type of integration the app will be installed as.
UENUM(BlueprintType, Category = "Discord Partner SDK")
enum class EDiscordIntegrationType : uint8 {

    /// \brief GuildInstall
    GuildInstall = 0 UMETA(DisplayName = "GuildInstall"),

    /// \brief UserInstall
    UserInstall = 1 UMETA(DisplayName = "UserInstall"),
};

/// \brief Enum that represents the various channel types on Discord.
///
/// For more information see: https://discord.com/developers/docs/resources/channel
UENUM(BlueprintType, Category = "Discord Partner SDK")
enum class EDiscordChannelType : uint8 {

    /// \brief GuildText
    GuildText = 0 UMETA(DisplayName = "GuildText"),

    /// \brief Dm
    Dm = 1 UMETA(DisplayName = "Dm"),

    /// \brief GuildVoice
    GuildVoice = 2 UMETA(DisplayName = "GuildVoice"),

    /// \brief GroupDm
    GroupDm = 3 UMETA(DisplayName = "GroupDm"),

    /// \brief GuildCategory
    GuildCategory = 4 UMETA(DisplayName = "GuildCategory"),

    /// \brief GuildNews
    GuildNews = 5 UMETA(DisplayName = "GuildNews"),

    /// \brief GuildStore
    GuildStore = 6 UMETA(DisplayName = "GuildStore"),

    /// \brief GuildNewsThread
    GuildNewsThread = 10 UMETA(DisplayName = "GuildNewsThread"),

    /// \brief GuildPublicThread
    GuildPublicThread = 11 UMETA(DisplayName = "GuildPublicThread"),

    /// \brief GuildPrivateThread
    GuildPrivateThread = 12 UMETA(DisplayName = "GuildPrivateThread"),

    /// \brief GuildStageVoice
    GuildStageVoice = 13 UMETA(DisplayName = "GuildStageVoice"),

    /// \brief GuildDirectory
    GuildDirectory = 14 UMETA(DisplayName = "GuildDirectory"),

    /// \brief GuildForum
    GuildForum = 15 UMETA(DisplayName = "GuildForum"),

    /// \brief GuildMedia
    GuildMedia = 16 UMETA(DisplayName = "GuildMedia"),

    /// \brief Lobby
    Lobby = 17 UMETA(DisplayName = "Lobby"),

    /// \brief EphemeralDm
    EphemeralDm = 18 UMETA(DisplayName = "EphemeralDm"),
};

/// \brief Represents the type of additional content contained in a message.
UENUM(BlueprintType, Category = "Discord Partner SDK")
enum class EDiscordAdditionalContentType : uint8 {

    /// \brief Other
    Other = 0 UMETA(DisplayName = "Other"),

    /// \brief Attachment
    Attachment = 1 UMETA(DisplayName = "Attachment"),

    /// \brief Poll
    Poll = 2 UMETA(DisplayName = "Poll"),

    /// \brief VoiceMessage
    VoiceMessage = 3 UMETA(DisplayName = "VoiceMessage"),

    /// \brief Thread
    Thread = 4 UMETA(DisplayName = "Thread"),

    /// \brief Embed
    Embed = 5 UMETA(DisplayName = "Embed"),

    /// \brief Sticker
    Sticker = 6 UMETA(DisplayName = "Sticker"),
};

/// \brief The Discord Voice audio system to use.
UENUM(BlueprintType, Category = "Discord Partner SDK")
enum class EDiscordAudioSystem : uint8 {

    /// \brief Use the standard audio system.
    Standard = 0 UMETA(DisplayName = "Standard"),

    /// \brief Use the game audio system.
    Game = 1 UMETA(DisplayName = "Game"),
};

/// \brief Enum that represents any network errors with the Call.
UENUM(BlueprintType, Category = "Discord Partner SDK")
enum class EDiscordCallError : uint8 {

    /// \brief None
    None = 0 UMETA(DisplayName = "None"),

    /// \brief SignalingConnectionFailed
    SignalingConnectionFailed = 1 UMETA(DisplayName = "SignalingConnectionFailed"),

    /// \brief SignalingUnexpectedClose
    SignalingUnexpectedClose = 2 UMETA(DisplayName = "SignalingUnexpectedClose"),

    /// \brief VoiceConnectionFailed
    VoiceConnectionFailed = 3 UMETA(DisplayName = "VoiceConnectionFailed"),

    /// \brief JoinTimeout
    JoinTimeout = 4 UMETA(DisplayName = "JoinTimeout"),

    /// \brief Forbidden
    Forbidden = 5 UMETA(DisplayName = "Forbidden"),
};

/// \brief Represents whether a voice call is using push to talk or auto voice detection
UENUM(BlueprintType, Category = "Discord Partner SDK")
enum class EDiscordAudioModeType : uint8 {

    /// \brief MODE_UNINIT
    MODE_UNINIT = 0 UMETA(DisplayName = "MODE_UNINIT"),

    /// \brief MODE_VAD
    MODE_VAD = 1 UMETA(DisplayName = "MODE_VAD"),

    /// \brief MODE_PTT
    MODE_PTT = 2 UMETA(DisplayName = "MODE_PTT"),
};

/// \brief Enum that respresents the state of the Call's network connection.
UENUM(BlueprintType, Category = "Discord Partner SDK")
enum class EDiscordCallStatus : uint8 {

    /// \brief Disconnected
    Disconnected = 0 UMETA(DisplayName = "Disconnected"),

    /// \brief Joining
    Joining = 1 UMETA(DisplayName = "Joining"),

    /// \brief Connecting
    Connecting = 2 UMETA(DisplayName = "Connecting"),

    /// \brief SignalingConnected
    SignalingConnected = 3 UMETA(DisplayName = "SignalingConnected"),

    /// \brief Connected
    Connected = 4 UMETA(DisplayName = "Connected"),

    /// \brief Reconnecting
    Reconnecting = 5 UMETA(DisplayName = "Reconnecting"),

    /// \brief Disconnecting
    Disconnecting = 6 UMETA(DisplayName = "Disconnecting"),
};

/// \brief Enum that represents the possible types of relationships that can exist between two users
UENUM(BlueprintType, Category = "Discord Partner SDK")
enum class EDiscordRelationshipType : uint8 {

    /// \brief The user has no relationship with the other user.
    None = 0 UMETA(DisplayName = "None"),

    /// \brief The user is friends with the other user.
    Friend = 1 UMETA(DisplayName = "Friend"),

    /// \brief The current user has blocked the target user, and so certain actions such as sending
    /// messages between these users will not work.
    Blocked = 2 UMETA(DisplayName = "Blocked"),

    /// \brief The current user has received a friend request from the target user, but it is not
    /// yet
    /// accepted.
    PendingIncoming = 3 UMETA(DisplayName = "PendingIncoming"),

    /// \brief The current user has sent a friend request to the target user, but it is not yet
    /// accepted.
    PendingOutgoing = 4 UMETA(DisplayName = "PendingOutgoing"),

    /// \brief The Implicit type is documented for visibility, but should be unused in the SDK.
    Implicit = 5 UMETA(DisplayName = "Implicit"),

    /// \brief The Suggestion type is documented for visibility, but should be unused in the SDK.
    Suggestion = 6 UMETA(DisplayName = "Suggestion"),
};

/// \brief The type of external identity provider.
UENUM(BlueprintType, Category = "Discord Partner SDK")
enum class EDiscordExternalIdentityProviderType : uint8 {

    /// \brief OIDC
    OIDC = 0 UMETA(DisplayName = "OIDC"),

    /// \brief EpicOnlineServices
    EpicOnlineServices = 1 UMETA(DisplayName = "EpicOnlineServices"),

    /// \brief Steam
    Steam = 2 UMETA(DisplayName = "Steam"),

    /// \brief Unity
    Unity = 3 UMETA(DisplayName = "Unity"),

    /// \brief DiscordBot
    DiscordBot = 4 UMETA(DisplayName = "DiscordBot"),

    /// \brief None
    None = 5 UMETA(DisplayName = "None"),

    /// \brief Unknown
    Unknown = 6 UMETA(DisplayName = "Unknown"),
};

/// \brief The desired type of avatar url to generate for a User.
UENUM(BlueprintType, Category = "Discord Partner SDK")
enum class EDiscordUserHandleAvatarType : uint8 {

    /// \brief Gif
    Gif = 0 UMETA(DisplayName = "Gif"),

    /// \brief Webp
    Webp = 1 UMETA(DisplayName = "Webp"),

    /// \brief Png
    Png = 2 UMETA(DisplayName = "Png"),

    /// \brief Jpeg
    Jpeg = 3 UMETA(DisplayName = "Jpeg"),
};

/// \brief Enum that specifies the various online statuses for a user.
///
/// Generally a user is online or offline, but in Discord users are able to further customize their
/// status such as turning on "Do not Disturb" mode or "Dnd" to silence notifications.
UENUM(BlueprintType, Category = "Discord Partner SDK")
enum class EDiscordStatusType : uint8 {

    /// \brief The user is online and recently active.
    Online = 0 UMETA(DisplayName = "Online"),

    /// \brief The user is offline and not connected to Discord.
    Offline = 1 UMETA(DisplayName = "Offline"),

    /// \brief Blocked
    Blocked = 2 UMETA(DisplayName = "Blocked"),

    /// \brief The user is online, but has not been active for a while and may be away from their
    /// computer.
    Idle = 3 UMETA(DisplayName = "Idle"),

    /// \brief The user is online, but wishes to suppress notifications for the time being.
    Dnd = 4 UMETA(DisplayName = "Dnd"),

    /// \brief The user is online, but wishes to appear as if they are offline to other users.
    Invisible = 5 UMETA(DisplayName = "Invisible"),

    /// \brief The user is online and is actively streaming content.
    Streaming = 6 UMETA(DisplayName = "Streaming"),

    /// \brief Unknown
    Unknown = 7 UMETA(DisplayName = "Unknown"),
};

/// \brief Enum that represents various informational disclosures that Discord may make to users, so
/// that the game can identity them and customize their rendering as desired.
///
/// See MessageHandle for more details.
UENUM(BlueprintType, Category = "Discord Partner SDK")
enum class EDiscordDisclosureTypes : uint8 {
    GeneratedUnknownValue__ = 0 UMETA(DisplayName = "Unknown"),

    /// \brief This disclosure type happens the first time a user sends a message in game, and that
    /// message will be able to be viewed on Discord, so the user knows their content is being
    /// copied out of the game.
    MessageDataVisibleOnDiscord = 3 UMETA(DisplayName = "MessageDataVisibleOnDiscord"),
};

/// \brief A bitfield that represents the various flags that can be set on a lobby member.
UENUM(BlueprintType, Category = "Discord Partner SDK")
enum class EDiscordLobbyMemberFlags : uint8 {

    /// \brief None
    None = 0 UMETA(DisplayName = "None"),

    /// \brief Controls if the user is allowed to link a channel to this lobby.
    ///
    /// This flag can only be set via the server API, add_lobby_member
    /// The use case for this is for games that want to restrict a lobby so that only the
    /// clan/guild/group leader
    /// is allowed to manage the linked channel for the lobby.
    CanLinkLobby = 1 UMETA(DisplayName = "CanLinkLobby"),
};

/// \brief Represents an error state for the socket connection that the Discord SDK maintains with
/// the Discord backend.
///
/// Generic network failures will use the ConnectionFailed and ConnectionCanceled
/// enum values. Other errors such as if the user's auth token is invalid or out of
/// date will be UnexpectedClose and you should look at the other Error fields for the specific
/// details.
UENUM(BlueprintType, Category = "Discord Partner SDK")
enum class EDiscordClientError : uint8 {

    /// \brief None
    None = 0 UMETA(DisplayName = "None"),

    /// \brief ConnectionFailed
    ConnectionFailed = 1 UMETA(DisplayName = "ConnectionFailed"),

    /// \brief UnexpectedClose
    UnexpectedClose = 2 UMETA(DisplayName = "UnexpectedClose"),

    /// \brief ConnectionCanceled
    ConnectionCanceled = 3 UMETA(DisplayName = "ConnectionCanceled"),
};

/// \brief This enum refers to the status of the internal websocket the SDK uses to communicate with
/// Discord There are ~2 phases for "launching" the client:
/// 1. The socket has to connect to Discord and exchange an auth token. This is indicated by the
/// `Connecting` and `Connected` values.
/// 2. The socket has to receive an initial payload of data that describes the current user,
/// what lobbies they are in, who their friends are, etc. This is the `Ready` status.
/// Many Client functions will not work until the status changes to `Ready`, such as
/// GetCurrentUser().
///
/// Status::Ready is the one you want to wait for!
///
/// Additionally, sometimes the socket will be disconnected, such as through temporary network
/// blips. But it will try to automatically reconnect, as indicated by the `Reconnecting`
/// status.
UENUM(BlueprintType, Category = "Discord Partner SDK")
enum class EDiscordClientStatus : uint8 {

    /// \brief Disconnected
    Disconnected = 0 UMETA(DisplayName = "Disconnected"),

    /// \brief Connecting
    Connecting = 1 UMETA(DisplayName = "Connecting"),

    /// \brief Connected
    Connected = 2 UMETA(DisplayName = "Connected"),

    /// \brief Ready
    Ready = 3 UMETA(DisplayName = "Ready"),

    /// \brief Reconnecting
    Reconnecting = 4 UMETA(DisplayName = "Reconnecting"),

    /// \brief Disconnecting
    Disconnecting = 5 UMETA(DisplayName = "Disconnecting"),

    /// \brief HttpWait
    HttpWait = 6 UMETA(DisplayName = "HttpWait"),
};

/// \brief Represents the type of thread to control thread priority on.
UENUM(BlueprintType, Category = "Discord Partner SDK")
enum class EDiscordClientThread : uint8 {

    /// \brief Client
    Client = 0 UMETA(DisplayName = "Client"),

    /// \brief Voice
    Voice = 1 UMETA(DisplayName = "Voice"),

    /// \brief Network
    Network = 2 UMETA(DisplayName = "Network"),
};

/// \brief Represents the type of auth token used by the SDK, either the normal tokens produced by
/// the Discord desktop app, or an oauth2 bearer token. Only the latter can be used by the SDK.
UENUM(BlueprintType, Category = "Discord Partner SDK")
enum class EDiscordAuthorizationTokenType : uint8 {

    /// \brief User
    User = 0 UMETA(DisplayName = "User"),

    /// \brief Bearer
    Bearer = 1 UMETA(DisplayName = "Bearer"),
};

/// \brief Represents the various identity providers that can be used to authenticate a provisional
/// account user for public clients.
UENUM(BlueprintType, Category = "Discord Partner SDK")
enum class EDiscordAuthenticationExternalAuthType : uint8 {

    /// \brief OIDC
    OIDC = 0 UMETA(DisplayName = "OIDC"),

    /// \brief EpicOnlineServicesAccessToken
    EpicOnlineServicesAccessToken = 1 UMETA(DisplayName = "EpicOnlineServicesAccessToken"),

    /// \brief EpicOnlineServicesIdToken
    EpicOnlineServicesIdToken = 2 UMETA(DisplayName = "EpicOnlineServicesIdToken"),

    /// \brief SteamSessionTicket
    SteamSessionTicket = 3 UMETA(DisplayName = "SteamSessionTicket"),

    /// \brief UnityServicesIdToken
    UnityServicesIdToken = 4 UMETA(DisplayName = "UnityServicesIdToken"),

    /// \brief DiscordBotIssuedAccessToken
    DiscordBotIssuedAccessToken = 5 UMETA(DisplayName = "DiscordBotIssuedAccessToken"),

    /// \brief AppleIdToken
    AppleIdToken = 6 UMETA(DisplayName = "AppleIdToken"),

    /// \brief PlayStationNetworkIdToken
    PlayStationNetworkIdToken = 7 UMETA(DisplayName = "PlayStationNetworkIdToken"),
};

/// \brief Enum that represents the various log levels supported by the SDK.
UENUM(BlueprintType, Category = "Discord Partner SDK")
enum class EDiscordLoggingSeverity : uint8 {
    GeneratedUnknownValue__ = 0 UMETA(DisplayName = "Unknown"),

    /// \brief Verbose
    Verbose = 1 UMETA(DisplayName = "Verbose"),

    /// \brief Info
    Info = 2 UMETA(DisplayName = "Info"),

    /// \brief Warning
    Warning = 3 UMETA(DisplayName = "Warning"),

    /// \brief Error
    Error = 4 UMETA(DisplayName = "Error"),

    /// \brief None
    None = 5 UMETA(DisplayName = "None"),
};

/// \brief Enum that represents the logical groups of relationships based on online status and game
/// activity
UENUM(BlueprintType, Category = "Discord Partner SDK")
enum class EDiscordRelationshipGroupType : uint8 {

    /// \brief Users who are online and currently playing the game
    OnlinePlayingGame = 0 UMETA(DisplayName = "OnlinePlayingGame"),

    /// \brief Users who are online but not playing the game
    OnlineElsewhere = 1 UMETA(DisplayName = "OnlineElsewhere"),

    /// \brief Users who are offline
    Offline = 2 UMETA(DisplayName = "Offline"),
};
class UDiscordActivityInvite;
class UDiscordActivityAssets;
class UDiscordActivityTimestamps;
class UDiscordActivityParty;
class UDiscordActivitySecrets;
class UDiscordActivityButton;
class UDiscordActivity;
class UDiscordClientResult;
class UDiscordAuthorizationCodeChallenge;
class UDiscordAuthorizationCodeVerifier;
class UDiscordAuthorizationArgs;
class UDiscordDeviceAuthorizationArgs;
class UDiscordVoiceStateHandle;
class UDiscordVADThresholdSettings;
class UDiscordCall;
class UDiscordChannelHandle;
class UDiscordGuildMinimal;
class UDiscordGuildChannel;
class UDiscordLinkedLobby;
class UDiscordLinkedChannel;
class UDiscordRelationshipHandle;
class UDiscordUserApplicationProfileHandle;
class UDiscordUserHandle;
class UDiscordLobbyMemberHandle;
class UDiscordLobbyHandle;
class UDiscordAdditionalContent;
class UDiscordMessageHandle;
class UDiscordAudioDevice;
class UDiscordUserMessageSummary;
class UDiscordClientCreateOptions;
class UDiscordClient;
class UDiscordCallInfoHandle;

/// \brief Callback function for Call::SetOnVoiceStateChangedCallback.
DECLARE_DELEGATE_OneParam(FDiscordCallOnVoiceStateChanged, FDiscordUniqueID);
DECLARE_DYNAMIC_DELEGATE_OneParam(FDiscordCallOnVoiceStateChangedDynamic, FDiscordUniqueID, userId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDiscordCallOnVoiceStateChangedMulticast,
                                            FDiscordUniqueID,
                                            userId);

/// \brief Callback function for Call::SetParticipantChangedCallback.
DECLARE_DELEGATE_TwoParams(FDiscordCallOnParticipantChanged, FDiscordUniqueID, bool);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FDiscordCallOnParticipantChangedDynamic,
                                   FDiscordUniqueID,
                                   userId,
                                   bool,
                                   added);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDiscordCallOnParticipantChangedMulticast,
                                             FDiscordUniqueID,
                                             userId,
                                             bool,
                                             added);

/// \brief Callback function for Call::SetSpeakingStatusChangedCallback.
DECLARE_DELEGATE_TwoParams(FDiscordCallOnSpeakingStatusChanged, FDiscordUniqueID, bool);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FDiscordCallOnSpeakingStatusChangedDynamic,
                                   FDiscordUniqueID,
                                   userId,
                                   bool,
                                   isPlayingSound);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDiscordCallOnSpeakingStatusChangedMulticast,
                                             FDiscordUniqueID,
                                             userId,
                                             bool,
                                             isPlayingSound);

/// \brief Callback function for Call::SetStatusChangedCallback.
DECLARE_DELEGATE_ThreeParams(FDiscordCallOnStatusChanged,
                             EDiscordCallStatus,
                             EDiscordCallError,
                             int32);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FDiscordCallOnStatusChangedDynamic,
                                     EDiscordCallStatus,
                                     status,
                                     EDiscordCallError,
                                     error,
                                     int32,
                                     errorDetail);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FDiscordCallOnStatusChangedMulticast,
                                               EDiscordCallStatus,
                                               status,
                                               EDiscordCallError,
                                               error,
                                               int32,
                                               errorDetail);
DECLARE_DELEGATE_ThreeParams(FDiscordClientUpdateLobbyMemberCallback,
                             UDiscordClientResult*,
                             FDiscordUniqueID,
                             FDiscordUniqueID);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FDiscordClientUpdateLobbyMemberCallbackDynamic,
                                     UDiscordClientResult*,
                                     result,
                                     FDiscordUniqueID,
                                     userId,
                                     FDiscordUniqueID,
                                     lobbyId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FDiscordClientUpdateLobbyMemberCallbackMulticast,
                                               UDiscordClientResult*,
                                               result,
                                               FDiscordUniqueID,
                                               userId,
                                               FDiscordUniqueID,
                                               lobbyId);
DECLARE_DELEGATE_TwoParams(FDiscordClientLobbyActionCallback,
                           UDiscordClientResult*,
                           FDiscordUniqueID);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FDiscordClientLobbyActionCallbackDynamic,
                                   UDiscordClientResult*,
                                   result,
                                   FDiscordUniqueID,
                                   lobbyId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDiscordClientLobbyActionCallbackMulticast,
                                             UDiscordClientResult*,
                                             result,
                                             FDiscordUniqueID,
                                             lobbyId);
DECLARE_DELEGATE_OneParam(FDiscordClientPerformOnThreadWithStringCallback, FString);
DECLARE_DYNAMIC_DELEGATE_OneParam(FDiscordClientPerformOnThreadWithStringCallbackDynamic,
                                  FString,
                                  text);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
  FDiscordClientPerformOnThreadWithStringCallbackMulticast,
  FString,
  text);
DECLARE_DELEGATE_OneParam(FDiscordClientUpdateUserApplicationProfileCallback,
                          UDiscordClientResult*);
DECLARE_DYNAMIC_DELEGATE_OneParam(FDiscordClientUpdateUserApplicationProfileCallbackDynamic,
                                  UDiscordClientResult*,
                                  result);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
  FDiscordClientUpdateUserApplicationProfileCallbackMulticast,
  UDiscordClientResult*,
  result);

/// \brief Callback invoked when Client::EndCall completes.
DECLARE_DELEGATE(FDiscordClientEndCallCallback);
DECLARE_DYNAMIC_DELEGATE(FDiscordClientEndCallCallbackDynamic);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDiscordClientEndCallCallbackMulticast);

/// \brief Callback invoked when Client::EndCalls completes.
DECLARE_DELEGATE(FDiscordClientEndCallsCallback);
DECLARE_DYNAMIC_DELEGATE(FDiscordClientEndCallsCallbackDynamic);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDiscordClientEndCallsCallbackMulticast);

/// \brief Callback function for Client::GetCurrentInputDevice.
DECLARE_DELEGATE_OneParam(FDiscordClientGetCurrentInputDeviceCallback, UDiscordAudioDevice*);
DECLARE_DYNAMIC_DELEGATE_OneParam(FDiscordClientGetCurrentInputDeviceCallbackDynamic,
                                  UDiscordAudioDevice*,
                                  device);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDiscordClientGetCurrentInputDeviceCallbackMulticast,
                                            UDiscordAudioDevice*,
                                            device);

/// \brief Callback function for Client::GetCurrentOutputDevice.
DECLARE_DELEGATE_OneParam(FDiscordClientGetCurrentOutputDeviceCallback, UDiscordAudioDevice*);
DECLARE_DYNAMIC_DELEGATE_OneParam(FDiscordClientGetCurrentOutputDeviceCallbackDynamic,
                                  UDiscordAudioDevice*,
                                  device);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDiscordClientGetCurrentOutputDeviceCallbackMulticast,
                                            UDiscordAudioDevice*,
                                            device);

/// \brief Callback function for Client::GetInputDevices.
DECLARE_DELEGATE_OneParam(FDiscordClientGetInputDevicesCallback,
                          TArray<UDiscordAudioDevice*> const&);
DECLARE_DYNAMIC_DELEGATE_OneParam(FDiscordClientGetInputDevicesCallbackDynamic,
                                  TArray<UDiscordAudioDevice*> const&,
                                  devices);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDiscordClientGetInputDevicesCallbackMulticast,
                                            TArray<UDiscordAudioDevice*> const&,
                                            devices);

/// \brief Callback function for Client::GetOutputDevices.
DECLARE_DELEGATE_OneParam(FDiscordClientGetOutputDevicesCallback,
                          TArray<UDiscordAudioDevice*> const&);
DECLARE_DYNAMIC_DELEGATE_OneParam(FDiscordClientGetOutputDevicesCallbackDynamic,
                                  TArray<UDiscordAudioDevice*> const&,
                                  devices);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDiscordClientGetOutputDevicesCallbackMulticast,
                                            TArray<UDiscordAudioDevice*> const&,
                                            devices);

/// \brief Callback function for Client::SetDeviceChangeCallback.
DECLARE_DELEGATE_TwoParams(FDiscordClientDeviceChangeCallback,
                           TArray<UDiscordAudioDevice*> const&,
                           TArray<UDiscordAudioDevice*> const&);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FDiscordClientDeviceChangeCallbackDynamic,
                                   TArray<UDiscordAudioDevice*> const&,
                                   inputDevices,
                                   TArray<UDiscordAudioDevice*> const&,
                                   outputDevices);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDiscordClientDeviceChangeCallbackMulticast,
                                             TArray<UDiscordAudioDevice*> const&,
                                             inputDevices,
                                             TArray<UDiscordAudioDevice*> const&,
                                             outputDevices);

/// \brief Callback function for Client::SetInputDevice.
DECLARE_DELEGATE_OneParam(FDiscordClientSetInputDeviceCallback, UDiscordClientResult*);
DECLARE_DYNAMIC_DELEGATE_OneParam(FDiscordClientSetInputDeviceCallbackDynamic,
                                  UDiscordClientResult*,
                                  result);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDiscordClientSetInputDeviceCallbackMulticast,
                                            UDiscordClientResult*,
                                            result);

/// \brief Callback function for Client::SetNoAudioInputCallback.
DECLARE_DELEGATE_OneParam(FDiscordClientNoAudioInputCallback, bool);
DECLARE_DYNAMIC_DELEGATE_OneParam(FDiscordClientNoAudioInputCallbackDynamic, bool, inputDetected);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDiscordClientNoAudioInputCallbackMulticast,
                                            bool,
                                            inputDetected);

/// \brief Callback function for Client::SetOutputDevice.
DECLARE_DELEGATE_OneParam(FDiscordClientSetOutputDeviceCallback, UDiscordClientResult*);
DECLARE_DYNAMIC_DELEGATE_OneParam(FDiscordClientSetOutputDeviceCallbackDynamic,
                                  UDiscordClientResult*,
                                  result);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDiscordClientSetOutputDeviceCallbackMulticast,
                                            UDiscordClientResult*,
                                            result);

/// \brief Callback function for Client::SetVoiceParticipantChangedCallback.
DECLARE_DELEGATE_ThreeParams(FDiscordClientVoiceParticipantChangedCallback,
                             FDiscordUniqueID,
                             FDiscordUniqueID,
                             bool);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FDiscordClientVoiceParticipantChangedCallbackDynamic,
                                     FDiscordUniqueID,
                                     lobbyId,
                                     FDiscordUniqueID,
                                     memberId,
                                     bool,
                                     added);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(
  FDiscordClientVoiceParticipantChangedCallbackMulticast,
  FDiscordUniqueID,
  lobbyId,
  FDiscordUniqueID,
  memberId,
  bool,
  added);

/// \brief Callback function for Client::StartCallWithAudioCallbacks.
///
/// The audio samples in `data` can be modified in-place to achieve simple DSP effects.
DECLARE_DELEGATE_SixParams(FDiscordClientUserAudioReceivedCallback,
                           FDiscordUniqueID,
                           int64,
                           FDiscordUniqueID,
                           int32,
                           FDiscordUniqueID,
                           bool&);
DECLARE_DYNAMIC_DELEGATE_SixParams(FDiscordClientUserAudioReceivedCallbackDynamic,
                                   FDiscordUniqueID,
                                   userId,
                                   int64,
                                   data,
                                   FDiscordUniqueID,
                                   samplesPerChannel,
                                   int32,
                                   sampleRate,
                                   FDiscordUniqueID,
                                   channels,
                                   bool&,
                                   outShouldMute);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_SixParams(FDiscordClientUserAudioReceivedCallbackMulticast,
                                             FDiscordUniqueID,
                                             userId,
                                             int64,
                                             data,
                                             FDiscordUniqueID,
                                             samplesPerChannel,
                                             int32,
                                             sampleRate,
                                             FDiscordUniqueID,
                                             channels,
                                             bool&,
                                             outShouldMute);

/// \brief Callback function for Client::StartCallWithAudioCallbacks.
///
/// The audio samples in `data` can be modified in-place to achieve simple DSP effects.
DECLARE_DELEGATE_FourParams(FDiscordClientUserAudioCapturedCallback,
                            int64,
                            FDiscordUniqueID,
                            int32,
                            FDiscordUniqueID);
DECLARE_DYNAMIC_DELEGATE_FourParams(FDiscordClientUserAudioCapturedCallbackDynamic,
                                    int64,
                                    data,
                                    FDiscordUniqueID,
                                    samplesPerChannel,
                                    int32,
                                    sampleRate,
                                    FDiscordUniqueID,
                                    channels);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FDiscordClientUserAudioCapturedCallbackMulticast,
                                              int64,
                                              data,
                                              FDiscordUniqueID,
                                              samplesPerChannel,
                                              int32,
                                              sampleRate,
                                              FDiscordUniqueID,
                                              channels);

/// \brief Callback invoked when the Authorize function completes.
///
/// The first arg contains any error message encountered during the authorization flow, such as
/// if the user cancelled the authorization. The second arg, code, contains an authorization
/// _code_. This alone cannot be used to authorize with Discord, and instead must be exchanged
/// for an access token later.
DECLARE_DELEGATE_ThreeParams(FDiscordClientAuthorizationCallback,
                             UDiscordClientResult*,
                             FString,
                             FString);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FDiscordClientAuthorizationCallbackDynamic,
                                     UDiscordClientResult*,
                                     result,
                                     FString,
                                     code,
                                     FString,
                                     redirectUri);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FDiscordClientAuthorizationCallbackMulticast,
                                               UDiscordClientResult*,
                                               result,
                                               FString,
                                               code,
                                               FString,
                                               redirectUri);

/// \brief Callback function for Client::ExchangeChildToken.
DECLARE_DELEGATE_FiveParams(FDiscordClientExchangeChildTokenCallback,
                            UDiscordClientResult*,
                            FString,
                            EDiscordAuthorizationTokenType,
                            int32,
                            FString);
DECLARE_DYNAMIC_DELEGATE_FiveParams(FDiscordClientExchangeChildTokenCallbackDynamic,
                                    UDiscordClientResult*,
                                    result,
                                    FString,
                                    accessToken,
                                    EDiscordAuthorizationTokenType,
                                    tokenType,
                                    int32,
                                    expiresIn,
                                    FString,
                                    scopes);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(FDiscordClientExchangeChildTokenCallbackMulticast,
                                              UDiscordClientResult*,
                                              result,
                                              FString,
                                              accessToken,
                                              EDiscordAuthorizationTokenType,
                                              tokenType,
                                              int32,
                                              expiresIn,
                                              FString,
                                              scopes);

/// \brief Callback function for Client::FetchCurrentUser.
DECLARE_DELEGATE_ThreeParams(FDiscordClientFetchCurrentUserCallback,
                             UDiscordClientResult*,
                             FDiscordUniqueID,
                             FString);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FDiscordClientFetchCurrentUserCallbackDynamic,
                                     UDiscordClientResult*,
                                     result,
                                     FDiscordUniqueID,
                                     id,
                                     FString,
                                     name);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FDiscordClientFetchCurrentUserCallbackMulticast,
                                               UDiscordClientResult*,
                                               result,
                                               FDiscordUniqueID,
                                               id,
                                               FString,
                                               name);

/// \brief Callback function for the token exchange APIs such as Client::GetToken
DECLARE_DELEGATE_SixParams(FDiscordClientTokenExchangeCallback,
                           UDiscordClientResult*,
                           FString,
                           FString,
                           EDiscordAuthorizationTokenType,
                           int32,
                           FString);
DECLARE_DYNAMIC_DELEGATE_SixParams(FDiscordClientTokenExchangeCallbackDynamic,
                                   UDiscordClientResult*,
                                   result,
                                   FString,
                                   accessToken,
                                   FString,
                                   refreshToken,
                                   EDiscordAuthorizationTokenType,
                                   tokenType,
                                   int32,
                                   expiresIn,
                                   FString,
                                   scopes);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_SixParams(FDiscordClientTokenExchangeCallbackMulticast,
                                             UDiscordClientResult*,
                                             result,
                                             FString,
                                             accessToken,
                                             FString,
                                             refreshToken,
                                             EDiscordAuthorizationTokenType,
                                             tokenType,
                                             int32,
                                             expiresIn,
                                             FString,
                                             scopes);

/// \brief Callback invoked when a user requests to initiate the authorization flow from the discord
/// app
///
/// The callback receives no args and must call the functions needed to initiate the auth flow
/// as if the user had clicked the account link button in the game
DECLARE_DELEGATE(FDiscordClientAuthorizeRequestCallback);
DECLARE_DYNAMIC_DELEGATE(FDiscordClientAuthorizeRequestCallbackDynamic);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDiscordClientAuthorizeRequestCallbackMulticast);

/// \brief Callback function for the Client::RevokeToken method.
DECLARE_DELEGATE_OneParam(FDiscordClientRevokeTokenCallback, UDiscordClientResult*);
DECLARE_DYNAMIC_DELEGATE_OneParam(FDiscordClientRevokeTokenCallbackDynamic,
                                  UDiscordClientResult*,
                                  result);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDiscordClientRevokeTokenCallbackMulticast,
                                            UDiscordClientResult*,
                                            result);

/// \brief Callback function for Client::SetAuthorizeDeviceScreenClosedCallback.
DECLARE_DELEGATE(FDiscordClientAuthorizeDeviceScreenClosedCallback);
DECLARE_DYNAMIC_DELEGATE(FDiscordClientAuthorizeDeviceScreenClosedCallbackDynamic);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDiscordClientAuthorizeDeviceScreenClosedCallbackMulticast);

/// \brief Callback function for Client::SetTokenExpirationCallback
DECLARE_DELEGATE(FDiscordClientTokenExpirationCallback);
DECLARE_DYNAMIC_DELEGATE(FDiscordClientTokenExpirationCallbackDynamic);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDiscordClientTokenExpirationCallbackMulticast);

/// \brief Callback function for the Client::UnmergeIntoProvisionalAccount method.
DECLARE_DELEGATE_OneParam(FDiscordClientUnmergeIntoProvisionalAccountCallback,
                          UDiscordClientResult*);
DECLARE_DYNAMIC_DELEGATE_OneParam(FDiscordClientUnmergeIntoProvisionalAccountCallbackDynamic,
                                  UDiscordClientResult*,
                                  result);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
  FDiscordClientUnmergeIntoProvisionalAccountCallbackMulticast,
  UDiscordClientResult*,
  result);

/// \brief Callback function for Client::UpdateProvisionalAccountDisplayName
DECLARE_DELEGATE_OneParam(FDiscordClientUpdateProvisionalAccountDisplayNameCallback,
                          UDiscordClientResult*);
DECLARE_DYNAMIC_DELEGATE_OneParam(FDiscordClientUpdateProvisionalAccountDisplayNameCallbackDynamic,
                                  UDiscordClientResult*,
                                  result);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
  FDiscordClientUpdateProvisionalAccountDisplayNameCallbackMulticast,
  UDiscordClientResult*,
  result);

/// \brief Callback invoked when Client::UpdateToken completes. Once this is done it is safe to call
/// Client::Connect.
DECLARE_DELEGATE_OneParam(FDiscordClientUpdateTokenCallback, UDiscordClientResult*);
DECLARE_DYNAMIC_DELEGATE_OneParam(FDiscordClientUpdateTokenCallbackDynamic,
                                  UDiscordClientResult*,
                                  result);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDiscordClientUpdateTokenCallbackMulticast,
                                            UDiscordClientResult*,
                                            result);

/// \brief Callback function for Client::DeleteUserMessage.
DECLARE_DELEGATE_OneParam(FDiscordClientDeleteUserMessageCallback, UDiscordClientResult*);
DECLARE_DYNAMIC_DELEGATE_OneParam(FDiscordClientDeleteUserMessageCallbackDynamic,
                                  UDiscordClientResult*,
                                  result);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDiscordClientDeleteUserMessageCallbackMulticast,
                                            UDiscordClientResult*,
                                            result);

/// \brief Callback function for Client::EditUserMessage.
DECLARE_DELEGATE_OneParam(FDiscordClientEditUserMessageCallback, UDiscordClientResult*);
DECLARE_DYNAMIC_DELEGATE_OneParam(FDiscordClientEditUserMessageCallbackDynamic,
                                  UDiscordClientResult*,
                                  result);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDiscordClientEditUserMessageCallbackMulticast,
                                            UDiscordClientResult*,
                                            result);

/// \brief Callback function for Client::GetLobbyMessagesWithLimit.
DECLARE_DELEGATE_TwoParams(FDiscordClientGetLobbyMessagesCallback,
                           UDiscordClientResult*,
                           TArray<UDiscordMessageHandle*> const&);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FDiscordClientGetLobbyMessagesCallbackDynamic,
                                   UDiscordClientResult*,
                                   result,
                                   TArray<UDiscordMessageHandle*> const&,
                                   messages);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDiscordClientGetLobbyMessagesCallbackMulticast,
                                             UDiscordClientResult*,
                                             result,
                                             TArray<UDiscordMessageHandle*> const&,
                                             messages);

/// \brief Callback function for Client::GetUserMessageSummaries.
DECLARE_DELEGATE_TwoParams(FDiscordClientUserMessageSummariesCallback,
                           UDiscordClientResult*,
                           TArray<UDiscordUserMessageSummary*> const&);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FDiscordClientUserMessageSummariesCallbackDynamic,
                                   UDiscordClientResult*,
                                   result,
                                   TArray<UDiscordUserMessageSummary*> const&,
                                   summaries);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDiscordClientUserMessageSummariesCallbackMulticast,
                                             UDiscordClientResult*,
                                             result,
                                             TArray<UDiscordUserMessageSummary*> const&,
                                             summaries);

/// \brief Callback function for Client::GetUserMessagesWithLimit.
DECLARE_DELEGATE_TwoParams(FDiscordClientUserMessagesWithLimitCallback,
                           UDiscordClientResult*,
                           TArray<UDiscordMessageHandle*> const&);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FDiscordClientUserMessagesWithLimitCallbackDynamic,
                                   UDiscordClientResult*,
                                   result,
                                   TArray<UDiscordMessageHandle*> const&,
                                   messages);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDiscordClientUserMessagesWithLimitCallbackMulticast,
                                             UDiscordClientResult*,
                                             result,
                                             TArray<UDiscordMessageHandle*> const&,
                                             messages);

/// \brief Callback function for when Client::ProvisionalUserMergeCompleted completes.
DECLARE_DELEGATE(FDiscordClientProvisionalUserMergeRequiredCallback);
DECLARE_DYNAMIC_DELEGATE(FDiscordClientProvisionalUserMergeRequiredCallbackDynamic);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDiscordClientProvisionalUserMergeRequiredCallbackMulticast);

/// \brief Callback function for when Client::OpenMessageInDiscord completes.
DECLARE_DELEGATE_OneParam(FDiscordClientOpenMessageInDiscordCallback, UDiscordClientResult*);
DECLARE_DYNAMIC_DELEGATE_OneParam(FDiscordClientOpenMessageInDiscordCallbackDynamic,
                                  UDiscordClientResult*,
                                  result);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDiscordClientOpenMessageInDiscordCallbackMulticast,
                                            UDiscordClientResult*,
                                            result);

/// \brief This is used for all kinds of 'send message' calls despite the name, to make sure engine
/// bindings use the same delegate type declaration for all of them, which makes things nicer.
/// `SendMessageCallback` was unavailable because it's a macro on Windows.
DECLARE_DELEGATE_TwoParams(FDiscordClientSendUserMessageCallback,
                           UDiscordClientResult*,
                           FDiscordUniqueID);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FDiscordClientSendUserMessageCallbackDynamic,
                                   UDiscordClientResult*,
                                   result,
                                   FDiscordUniqueID,
                                   messageId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDiscordClientSendUserMessageCallbackMulticast,
                                             UDiscordClientResult*,
                                             result,
                                             FDiscordUniqueID,
                                             messageId);

/// \brief Callback function for Client::SetMessageCreatedCallback.
DECLARE_DELEGATE_OneParam(FDiscordClientMessageCreatedCallback, FDiscordUniqueID);
DECLARE_DYNAMIC_DELEGATE_OneParam(FDiscordClientMessageCreatedCallbackDynamic,
                                  FDiscordUniqueID,
                                  messageId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDiscordClientMessageCreatedCallbackMulticast,
                                            FDiscordUniqueID,
                                            messageId);

/// \brief Callback function for Client::SetMessageDeletedCallback.
DECLARE_DELEGATE_TwoParams(FDiscordClientMessageDeletedCallback,
                           FDiscordUniqueID,
                           FDiscordUniqueID);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FDiscordClientMessageDeletedCallbackDynamic,
                                   FDiscordUniqueID,
                                   messageId,
                                   FDiscordUniqueID,
                                   channelId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDiscordClientMessageDeletedCallbackMulticast,
                                             FDiscordUniqueID,
                                             messageId,
                                             FDiscordUniqueID,
                                             channelId);

/// \brief Callback function for Client::SetMessageUpdatedCallback.
DECLARE_DELEGATE_OneParam(FDiscordClientMessageUpdatedCallback, FDiscordUniqueID);
DECLARE_DYNAMIC_DELEGATE_OneParam(FDiscordClientMessageUpdatedCallbackDynamic,
                                  FDiscordUniqueID,
                                  messageId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDiscordClientMessageUpdatedCallbackMulticast,
                                            FDiscordUniqueID,
                                            messageId);

/// \brief Callback function invoked when a new log message is generated.
DECLARE_DELEGATE_TwoParams(FDiscordClientLogCallback, FString, EDiscordLoggingSeverity);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FDiscordClientLogCallbackDynamic,
                                   FString,
                                   message,
                                   EDiscordLoggingSeverity,
                                   severity);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDiscordClientLogCallbackMulticast,
                                             FString,
                                             message,
                                             EDiscordLoggingSeverity,
                                             severity);

/// \brief Callback function for when Client::OpenConnectedGamesSettingsInDiscord completes.
DECLARE_DELEGATE_OneParam(FDiscordClientOpenConnectedGamesSettingsInDiscordCallback,
                          UDiscordClientResult*);
DECLARE_DYNAMIC_DELEGATE_OneParam(FDiscordClientOpenConnectedGamesSettingsInDiscordCallbackDynamic,
                                  UDiscordClientResult*,
                                  result);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
  FDiscordClientOpenConnectedGamesSettingsInDiscordCallbackMulticast,
  UDiscordClientResult*,
  result);

/// \brief Callback function for Client::SetStatusChangedCallback.
///
/// errorDetail will usually be one of the error code described here:
/// https://discord.com/developers/docs/topics/opcodes-and-status-codes#gateway-gateway-close-event-codes
DECLARE_DELEGATE_ThreeParams(FDiscordClientOnStatusChanged,
                             EDiscordClientStatus,
                             EDiscordClientError,
                             int32);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FDiscordClientOnStatusChangedDynamic,
                                     EDiscordClientStatus,
                                     status,
                                     EDiscordClientError,
                                     error,
                                     int32,
                                     errorDetail);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FDiscordClientOnStatusChangedMulticast,
                                               EDiscordClientStatus,
                                               status,
                                               EDiscordClientError,
                                               error,
                                               int32,
                                               errorDetail);

/// \brief Callback function for Client::CreateOrJoinLobby
DECLARE_DELEGATE_TwoParams(FDiscordClientCreateOrJoinLobbyCallback,
                           UDiscordClientResult*,
                           FDiscordUniqueID);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FDiscordClientCreateOrJoinLobbyCallbackDynamic,
                                   UDiscordClientResult*,
                                   result,
                                   FDiscordUniqueID,
                                   lobbyId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDiscordClientCreateOrJoinLobbyCallbackMulticast,
                                             UDiscordClientResult*,
                                             result,
                                             FDiscordUniqueID,
                                             lobbyId);

/// \brief Callback function for Client::GetGuildChannels.
DECLARE_DELEGATE_TwoParams(FDiscordClientGetGuildChannelsCallback,
                           UDiscordClientResult*,
                           TArray<UDiscordGuildChannel*> const&);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FDiscordClientGetGuildChannelsCallbackDynamic,
                                   UDiscordClientResult*,
                                   result,
                                   TArray<UDiscordGuildChannel*> const&,
                                   guildChannels);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDiscordClientGetGuildChannelsCallbackMulticast,
                                             UDiscordClientResult*,
                                             result,
                                             TArray<UDiscordGuildChannel*> const&,
                                             guildChannels);

/// \brief Callback function for Client::GetUserGuilds.
DECLARE_DELEGATE_TwoParams(FDiscordClientGetUserGuildsCallback,
                           UDiscordClientResult*,
                           TArray<UDiscordGuildMinimal*> const&);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FDiscordClientGetUserGuildsCallbackDynamic,
                                   UDiscordClientResult*,
                                   result,
                                   TArray<UDiscordGuildMinimal*> const&,
                                   guilds);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDiscordClientGetUserGuildsCallbackMulticast,
                                             UDiscordClientResult*,
                                             result,
                                             TArray<UDiscordGuildMinimal*> const&,
                                             guilds);

/// \brief Callback function for Client::JoinLinkedLobbyGuild.
DECLARE_DELEGATE_TwoParams(FDiscordClientJoinLinkedLobbyGuildCallback,
                           UDiscordClientResult*,
                           FString);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FDiscordClientJoinLinkedLobbyGuildCallbackDynamic,
                                   UDiscordClientResult*,
                                   result,
                                   FString,
                                   inviteUrl);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDiscordClientJoinLinkedLobbyGuildCallbackMulticast,
                                             UDiscordClientResult*,
                                             result,
                                             FString,
                                             inviteUrl);

/// \brief Callback function for Client::LeaveLobby.
DECLARE_DELEGATE_OneParam(FDiscordClientLeaveLobbyCallback, UDiscordClientResult*);
DECLARE_DYNAMIC_DELEGATE_OneParam(FDiscordClientLeaveLobbyCallbackDynamic,
                                  UDiscordClientResult*,
                                  result);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDiscordClientLeaveLobbyCallbackMulticast,
                                            UDiscordClientResult*,
                                            result);

/// \brief Callback function for Client::LinkChannelToLobby.
DECLARE_DELEGATE_OneParam(FDiscordClientLinkOrUnlinkChannelCallback, UDiscordClientResult*);
DECLARE_DYNAMIC_DELEGATE_OneParam(FDiscordClientLinkOrUnlinkChannelCallbackDynamic,
                                  UDiscordClientResult*,
                                  result);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDiscordClientLinkOrUnlinkChannelCallbackMulticast,
                                            UDiscordClientResult*,
                                            result);

/// \brief Callback function for Client::SetLobbyCreatedCallback.
DECLARE_DELEGATE_OneParam(FDiscordClientLobbyCreatedCallback, FDiscordUniqueID);
DECLARE_DYNAMIC_DELEGATE_OneParam(FDiscordClientLobbyCreatedCallbackDynamic,
                                  FDiscordUniqueID,
                                  lobbyId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDiscordClientLobbyCreatedCallbackMulticast,
                                            FDiscordUniqueID,
                                            lobbyId);

/// \brief Callback function for Client::SetLobbyDeletedCallback.
DECLARE_DELEGATE_OneParam(FDiscordClientLobbyDeletedCallback, FDiscordUniqueID);
DECLARE_DYNAMIC_DELEGATE_OneParam(FDiscordClientLobbyDeletedCallbackDynamic,
                                  FDiscordUniqueID,
                                  lobbyId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDiscordClientLobbyDeletedCallbackMulticast,
                                            FDiscordUniqueID,
                                            lobbyId);

/// \brief Callback function for Client::SetLobbyMemberAddedCallback.
DECLARE_DELEGATE_TwoParams(FDiscordClientLobbyMemberAddedCallback,
                           FDiscordUniqueID,
                           FDiscordUniqueID);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FDiscordClientLobbyMemberAddedCallbackDynamic,
                                   FDiscordUniqueID,
                                   lobbyId,
                                   FDiscordUniqueID,
                                   memberId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDiscordClientLobbyMemberAddedCallbackMulticast,
                                             FDiscordUniqueID,
                                             lobbyId,
                                             FDiscordUniqueID,
                                             memberId);

/// \brief Callback function for Client::SetLobbyMemberRemovedCallback.
DECLARE_DELEGATE_TwoParams(FDiscordClientLobbyMemberRemovedCallback,
                           FDiscordUniqueID,
                           FDiscordUniqueID);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FDiscordClientLobbyMemberRemovedCallbackDynamic,
                                   FDiscordUniqueID,
                                   lobbyId,
                                   FDiscordUniqueID,
                                   memberId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDiscordClientLobbyMemberRemovedCallbackMulticast,
                                             FDiscordUniqueID,
                                             lobbyId,
                                             FDiscordUniqueID,
                                             memberId);

/// \brief Callback function for Client::SetLobbyMemberUpdatedCallback.
DECLARE_DELEGATE_TwoParams(FDiscordClientLobbyMemberUpdatedCallback,
                           FDiscordUniqueID,
                           FDiscordUniqueID);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FDiscordClientLobbyMemberUpdatedCallbackDynamic,
                                   FDiscordUniqueID,
                                   lobbyId,
                                   FDiscordUniqueID,
                                   memberId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDiscordClientLobbyMemberUpdatedCallbackMulticast,
                                             FDiscordUniqueID,
                                             lobbyId,
                                             FDiscordUniqueID,
                                             memberId);

/// \brief Callback function for Client::SetLobbyUpdatedCallback.
DECLARE_DELEGATE_OneParam(FDiscordClientLobbyUpdatedCallback, FDiscordUniqueID);
DECLARE_DYNAMIC_DELEGATE_OneParam(FDiscordClientLobbyUpdatedCallbackDynamic,
                                  FDiscordUniqueID,
                                  lobbyId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDiscordClientLobbyUpdatedCallbackMulticast,
                                            FDiscordUniqueID,
                                            lobbyId);

/// \brief Callback invoked when the IsDiscordAppInstalled function completes.
DECLARE_DELEGATE_OneParam(FDiscordClientIsDiscordAppInstalledCallback, bool);
DECLARE_DYNAMIC_DELEGATE_OneParam(FDiscordClientIsDiscordAppInstalledCallbackDynamic,
                                  bool,
                                  installed);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDiscordClientIsDiscordAppInstalledCallbackMulticast,
                                            bool,
                                            installed);

/// \brief Callback function for Client::AcceptActivityInvite.
DECLARE_DELEGATE_TwoParams(FDiscordClientAcceptActivityInviteCallback,
                           UDiscordClientResult*,
                           FString);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FDiscordClientAcceptActivityInviteCallbackDynamic,
                                   UDiscordClientResult*,
                                   result,
                                   FString,
                                   joinSecret);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDiscordClientAcceptActivityInviteCallbackMulticast,
                                             UDiscordClientResult*,
                                             result,
                                             FString,
                                             joinSecret);

/// \brief Callback function for Client::SendActivityInvite, Client::SendActivityJoinRequest, and
/// Client::SendActivityJoinRequestReply.
DECLARE_DELEGATE_OneParam(FDiscordClientSendActivityInviteCallback, UDiscordClientResult*);
DECLARE_DYNAMIC_DELEGATE_OneParam(FDiscordClientSendActivityInviteCallbackDynamic,
                                  UDiscordClientResult*,
                                  result);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDiscordClientSendActivityInviteCallbackMulticast,
                                            UDiscordClientResult*,
                                            result);

/// \brief Callback function for Client::SetActivityInviteCreatedCallback and
/// Client::SetActivityInviteUpdatedCallback.
DECLARE_DELEGATE_OneParam(FDiscordClientActivityInviteCallback, UDiscordActivityInvite*);
DECLARE_DYNAMIC_DELEGATE_OneParam(FDiscordClientActivityInviteCallbackDynamic,
                                  UDiscordActivityInvite*,
                                  invite);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDiscordClientActivityInviteCallbackMulticast,
                                            UDiscordActivityInvite*,
                                            invite);

/// \brief Callback function for Client::SetActivityJoinCallback
DECLARE_DELEGATE_OneParam(FDiscordClientActivityJoinCallback, FString);
DECLARE_DYNAMIC_DELEGATE_OneParam(FDiscordClientActivityJoinCallbackDynamic, FString, joinSecret);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDiscordClientActivityJoinCallbackMulticast,
                                            FString,
                                            joinSecret);

/// \brief Callback function for Client::SetActivityJoinWithApplicationCallback
DECLARE_DELEGATE_TwoParams(FDiscordClientActivityJoinWithApplicationCallback,
                           FDiscordUniqueID,
                           FString);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FDiscordClientActivityJoinWithApplicationCallbackDynamic,
                                   FDiscordUniqueID,
                                   applicationId,
                                   FString,
                                   joinSecret);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
  FDiscordClientActivityJoinWithApplicationCallbackMulticast,
  FDiscordUniqueID,
  applicationId,
  FString,
  joinSecret);

/// \brief Callback function for when Client::SetOnlineStatus completes.
DECLARE_DELEGATE_OneParam(FDiscordClientUpdateStatusCallback, UDiscordClientResult*);
DECLARE_DYNAMIC_DELEGATE_OneParam(FDiscordClientUpdateStatusCallbackDynamic,
                                  UDiscordClientResult*,
                                  result);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDiscordClientUpdateStatusCallbackMulticast,
                                            UDiscordClientResult*,
                                            result);

/// \brief Callback function for when Client::UpdateRichPresence completes.
DECLARE_DELEGATE_OneParam(FDiscordClientUpdateRichPresenceCallback, UDiscordClientResult*);
DECLARE_DYNAMIC_DELEGATE_OneParam(FDiscordClientUpdateRichPresenceCallbackDynamic,
                                  UDiscordClientResult*,
                                  result);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDiscordClientUpdateRichPresenceCallbackMulticast,
                                            UDiscordClientResult*,
                                            result);

/// \brief Callback function for most other Relationship functions such as
/// Client::SendDiscordFriendRequestById.
DECLARE_DELEGATE_OneParam(FDiscordClientUpdateRelationshipCallback, UDiscordClientResult*);
DECLARE_DYNAMIC_DELEGATE_OneParam(FDiscordClientUpdateRelationshipCallbackDynamic,
                                  UDiscordClientResult*,
                                  result);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDiscordClientUpdateRelationshipCallbackMulticast,
                                            UDiscordClientResult*,
                                            result);

/// \brief Callback function for Client::SendDiscordFriendRequest and Client::SendGameFriendRequest.
DECLARE_DELEGATE_OneParam(FDiscordClientSendFriendRequestCallback, UDiscordClientResult*);
DECLARE_DYNAMIC_DELEGATE_OneParam(FDiscordClientSendFriendRequestCallbackDynamic,
                                  UDiscordClientResult*,
                                  result);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDiscordClientSendFriendRequestCallbackMulticast,
                                            UDiscordClientResult*,
                                            result);

/// \brief Callback function for Client::SetRelationshipCreatedCallback.
///
/// `isDiscordRelationshipUpdate` will be true if the relationship created with the `userId` is
/// a Discord relationship, and false if it's an in-game relationship.
DECLARE_DELEGATE_TwoParams(FDiscordClientRelationshipCreatedCallback, FDiscordUniqueID, bool);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FDiscordClientRelationshipCreatedCallbackDynamic,
                                   FDiscordUniqueID,
                                   userId,
                                   bool,
                                   isDiscordRelationshipUpdate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDiscordClientRelationshipCreatedCallbackMulticast,
                                             FDiscordUniqueID,
                                             userId,
                                             bool,
                                             isDiscordRelationshipUpdate);

/// \brief Callback function for Client::SetRelationshipDeletedCallback.
///
/// `isDiscordRelationshipUpdate` will be true if the relationship deleted with the `userId` is
/// a Discord relationship, and false if it's an in-game relationship.
DECLARE_DELEGATE_TwoParams(FDiscordClientRelationshipDeletedCallback, FDiscordUniqueID, bool);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FDiscordClientRelationshipDeletedCallbackDynamic,
                                   FDiscordUniqueID,
                                   userId,
                                   bool,
                                   isDiscordRelationshipUpdate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDiscordClientRelationshipDeletedCallbackMulticast,
                                             FDiscordUniqueID,
                                             userId,
                                             bool,
                                             isDiscordRelationshipUpdate);

/// \brief Callback function for when Client::GetDiscordClientConnectedUser completes.
DECLARE_DELEGATE_TwoParams(FDiscordClientGetDiscordClientConnectedUserCallback,
                           UDiscordClientResult*,
                           UDiscordUserHandle*);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FDiscordClientGetDiscordClientConnectedUserCallbackDynamic,
                                   UDiscordClientResult*,
                                   result,
                                   UDiscordUserHandle*,
                                   user);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
  FDiscordClientGetDiscordClientConnectedUserCallbackMulticast,
  UDiscordClientResult*,
  result,
  UDiscordUserHandle*,
  user);

/// \brief Callback function for Client::SetRelationshipGroupsUpdatedCallback.
DECLARE_DELEGATE_OneParam(FDiscordClientRelationshipGroupsUpdatedCallback, FDiscordUniqueID);
DECLARE_DYNAMIC_DELEGATE_OneParam(FDiscordClientRelationshipGroupsUpdatedCallbackDynamic,
                                  FDiscordUniqueID,
                                  userId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
  FDiscordClientRelationshipGroupsUpdatedCallbackMulticast,
  FDiscordUniqueID,
  userId);

/// \brief Callback function for Client::SetUserUpdatedCallback.
DECLARE_DELEGATE_OneParam(FDiscordClientUserUpdatedCallback, FDiscordUniqueID);
DECLARE_DYNAMIC_DELEGATE_OneParam(FDiscordClientUserUpdatedCallbackDynamic,
                                  FDiscordUniqueID,
                                  userId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDiscordClientUserUpdatedCallbackMulticast,
                                            FDiscordUniqueID,
                                            userId);

/// \brief When one user invites another to join their game on Discord, it will send a message to
/// that user. The SDK will parse those messages for you automatically, and this struct contains all
/// of the relevant invite information which is needed to later accept that invite.
UCLASS(BlueprintType, Category = "Discord Partner SDK")
class DISCORDPARTNERSDK_API UDiscordActivityInvite : public UObject {
    GENERATED_BODY()
public:
    ~UDiscordActivityInvite();
#if !DISCORD_PARTNER_SDK_STUB
    Discord_ActivityInvite instance;
    DiscordUObjectState state = DiscordUObjectState::Invalid;
#endif

    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void Init();
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void Drop();

    /// \brief The user id of the user who sent the invite.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get SenderId"))
    FDiscordUniqueID SenderId();

    /// \brief The user id of the user who sent the invite.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetSenderId(FDiscordUniqueID SenderId);

    /// \brief The id of the Discord channel in which the invite was sent.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get ChannelId"))
    FDiscordUniqueID ChannelId();

    /// \brief The id of the Discord channel in which the invite was sent.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetChannelId(FDiscordUniqueID ChannelId);

    /// \brief The id of the Discord message that contains the invite.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get MessageId"))
    FDiscordUniqueID MessageId();

    /// \brief The id of the Discord message that contains the invite.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetMessageId(FDiscordUniqueID MessageId);

    /// \brief The type of invite that was sent.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get Type"))
    EDiscordActivityActionTypes Type();

    /// \brief The type of invite that was sent.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetType(EDiscordActivityActionTypes Type);

    /// \brief The target application of the invite.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get ApplicationId"))
    FDiscordUniqueID ApplicationId();

    /// \brief The target application of the invite.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetApplicationId(FDiscordUniqueID ApplicationId);

    /// \brief The application id of the parent - this is only applicable if there is a parent
    /// for a publisher's suite of applications.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get ParentApplicationId"))
    FDiscordUniqueID ParentApplicationId();

    /// \brief The application id of the parent - this is only applicable if there is a parent
    /// for a publisher's suite of applications.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetParentApplicationId(FDiscordUniqueID ParentApplicationId);

    /// \brief The id of the party the invite was sent for.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get PartyId"))
    FString PartyId();

    /// \brief The id of the party the invite was sent for.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetPartyId(FString PartyId);

    /// \brief The session id of the user who sent the invite.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get SessionId"))
    FString SessionId();

    /// \brief The session id of the user who sent the invite.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetSessionId(FString SessionId);

    /// \brief Whether or not this invite is currently joinable. An invite becomes invalid if it was
    /// sent more than 6 hours ago or if the sender is no longer playing the game the invite is for.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get IsValid"))
    bool IsValid();

    /// \brief Whether or not this invite is currently joinable. An invite becomes invalid if it was
    /// sent more than 6 hours ago or if the sender is no longer playing the game the invite is for.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetIsValid(bool IsValid);
};

/// \brief Struct which controls what your rich presence looks like in
/// the Discord client. If you don't specify any values, the icon
/// and name of your application will be used as defaults.
///
/// Image assets can be either the unique identifier for an image
/// you uploaded to your application via the `Rich Presence` page in
/// the Developer portal, or they can be an external image URL.
///
/// As an example, if I uploaded an asset and name it `goofy-icon`,
/// I could set either image field to the string `goofy-icon`. Alternatively,
/// if my icon was hosted at `http://my-site.com/goofy.jpg`, I could
/// pass that URL into either image field.
///
/// See https://discord.com/developers/docs/rich-presence/overview#adding-custom-art-assets
/// for more information on using custom art assets, as well as for visual
/// examples of what each field does.
UCLASS(BlueprintType, Category = "Discord Partner SDK")
class DISCORDPARTNERSDK_API UDiscordActivityAssets : public UObject {
    GENERATED_BODY()
public:
    ~UDiscordActivityAssets();
#if !DISCORD_PARTNER_SDK_STUB
    Discord_ActivityAssets instance;
    DiscordUObjectState state = DiscordUObjectState::Invalid;
#endif

    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void Init();
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void Drop();

    /// \brief The primary image identifier or URL, rendered as a large square icon on a user's rich
    /// presence.
    ///
    /// If specified, must be a string between 1 and 300 characters.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get LargeImage"))
    FString LargeImage();

    /// \brief The primary image identifier or URL, rendered as a large square icon on a user's rich
    /// presence.
    ///
    /// If specified, must be a string between 1 and 300 characters.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetLargeImage(FString LargeImage);

    /// \brief A tooltip string that is shown when the user hovers over the large image.
    ///
    /// If specified, must be a string between 2 and 128 characters.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get LargeText"))
    FString LargeText();

    /// \brief A tooltip string that is shown when the user hovers over the large image.
    ///
    /// If specified, must be a string between 2 and 128 characters.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetLargeText(FString LargeText);

    /// \brief A URL that opens when the user clicks/taps the large image.
    ///
    /// If specified, must be a string between 1 and 256 characters.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get LargeUrl"))
    FString LargeUrl();

    /// \brief A URL that opens when the user clicks/taps the large image.
    ///
    /// If specified, must be a string between 1 and 256 characters.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetLargeUrl(FString LargeUrl);

    /// \brief The secondary image, rendered as a small circle over the `largeImage`.
    ///
    /// If specified, must be a string between 1 and 300 characters.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get SmallImage"))
    FString SmallImage();

    /// \brief The secondary image, rendered as a small circle over the `largeImage`.
    ///
    /// If specified, must be a string between 1 and 300 characters.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetSmallImage(FString SmallImage);

    /// \brief A tooltip string that is shown when the user hovers over the small image.
    ///
    /// If specified, must be a string between 2 and 128 characters.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get SmallText"))
    FString SmallText();

    /// \brief A tooltip string that is shown when the user hovers over the small image.
    ///
    /// If specified, must be a string between 2 and 128 characters.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetSmallText(FString SmallText);

    /// \brief A URL that opens when the user clicks/taps the small image.
    ///
    /// If specified, must be a string between 1 and 256 characters.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get SmallUrl"))
    FString SmallUrl();

    /// \brief A URL that opens when the user clicks/taps the small image.
    ///
    /// If specified, must be a string between 1 and 256 characters.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetSmallUrl(FString SmallUrl);

    /// \brief The invite cover image identifier or URL, rendered as a banner image on activity
    /// invites.
    ///
    /// If specified, must be a string between 1 and 300 characters.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get InviteCoverImage"))
    FString InviteCoverImage();

    /// \brief The invite cover image identifier or URL, rendered as a banner image on activity
    /// invites.
    ///
    /// If specified, must be a string between 1 and 300 characters.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetInviteCoverImage(FString InviteCoverImage);
};

/// \brief \see Activity
UCLASS(BlueprintType, Category = "Discord Partner SDK")
class DISCORDPARTNERSDK_API UDiscordActivityTimestamps : public UObject {
    GENERATED_BODY()
public:
    ~UDiscordActivityTimestamps();
#if !DISCORD_PARTNER_SDK_STUB
    Discord_ActivityTimestamps instance;
    DiscordUObjectState state = DiscordUObjectState::Invalid;
#endif

    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void Init();
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void Drop();

    /// \brief The time the activity started, in milliseconds since Unix epoch.
    ///
    /// The SDK will try to convert seconds to milliseconds if a small-ish value is passed in.
    /// If specified, the Discord client will render a count up timer showing how long the user has
    /// been playing this activity.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get Start"))
    FDiscordUniqueID Start();

    /// \brief The time the activity started, in milliseconds since Unix epoch.
    ///
    /// The SDK will try to convert seconds to milliseconds if a small-ish value is passed in.
    /// If specified, the Discord client will render a count up timer showing how long the user has
    /// been playing this activity.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetStart(FDiscordUniqueID Start);

    /// \brief The time the activity will end at, in milliseconds since Unix epoch.
    ///
    /// The SDK will try to convert seconds to milliseconds if a small-ish value is passed in.
    /// If specified, the Discord client will render a countdown timer showing how long until the
    /// activity ends.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get End"))
    FDiscordUniqueID End();

    /// \brief The time the activity will end at, in milliseconds since Unix epoch.
    ///
    /// The SDK will try to convert seconds to milliseconds if a small-ish value is passed in.
    /// If specified, the Discord client will render a countdown timer showing how long until the
    /// activity ends.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetEnd(FDiscordUniqueID End);
};

/// \brief \see Activity
UCLASS(BlueprintType, Category = "Discord Partner SDK")
class DISCORDPARTNERSDK_API UDiscordActivityParty : public UObject {
    GENERATED_BODY()
public:
    ~UDiscordActivityParty();
#if !DISCORD_PARTNER_SDK_STUB
    Discord_ActivityParty instance;
    DiscordUObjectState state = DiscordUObjectState::Invalid;
#endif

    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void Init();
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void Drop();

    /// \brief Specifies the id of the party. "Party" is used colloquially to refer to a group of
    /// players in a shared context. This could be a lobby id, server id, team id, etc.
    ///
    /// All party members should specify a RichPresence update using
    /// the same party id so that the Discord client knows how to group them together. If specified,
    /// must be a string between 2 and 128 characters.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get Id"))
    FString Id();

    /// \brief Specifies the id of the party. "Party" is used colloquially to refer to a group of
    /// players in a shared context. This could be a lobby id, server id, team id, etc.
    ///
    /// All party members should specify a RichPresence update using
    /// the same party id so that the Discord client knows how to group them together. If specified,
    /// must be a string between 2 and 128 characters.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetId(FString Id);

    /// \brief The number of people currently in the party, must be at least 1.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get CurrentSize"))
    int32 CurrentSize();

    /// \brief The number of people currently in the party, must be at least 1.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetCurrentSize(int32 CurrentSize);

    /// \brief The maximum number of people that can be in the party, must be at least 0. When 0,
    /// the UI will not display a maximum.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get MaxSize"))
    int32 MaxSize();

    /// \brief The maximum number of people that can be in the party, must be at least 0. When 0,
    /// the UI will not display a maximum.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetMaxSize(int32 MaxSize);

    /// \brief The privacy of the party.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get Privacy"))
    EDiscordActivityPartyPrivacy Privacy();

    /// \brief The privacy of the party.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetPrivacy(EDiscordActivityPartyPrivacy Privacy);
};

/// \brief \see Activity
UCLASS(BlueprintType, Category = "Discord Partner SDK")
class DISCORDPARTNERSDK_API UDiscordActivitySecrets : public UObject {
    GENERATED_BODY()
public:
    ~UDiscordActivitySecrets();
#if !DISCORD_PARTNER_SDK_STUB
    Discord_ActivitySecrets instance;
    DiscordUObjectState state = DiscordUObjectState::Invalid;
#endif

    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void Init();
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void Drop();

    /// \brief A secret string that is shared with users who are accepted into the party so the game
    /// knows how to join the user to the party. For example you might specify an internal game
    /// server ID or a Discord lobby ID or secret. If specified, must be a string between 2 and 128
    /// characters.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get Join"))
    FString Join();

    /// \brief A secret string that is shared with users who are accepted into the party so the game
    /// knows how to join the user to the party. For example you might specify an internal game
    /// server ID or a Discord lobby ID or secret. If specified, must be a string between 2 and 128
    /// characters.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetJoin(FString Join);
};

/// \brief \see Activity
UCLASS(BlueprintType, Category = "Discord Partner SDK")
class DISCORDPARTNERSDK_API UDiscordActivityButton : public UObject {
    GENERATED_BODY()
public:
    ~UDiscordActivityButton();
#if !DISCORD_PARTNER_SDK_STUB
    Discord_ActivityButton instance;
    DiscordUObjectState state = DiscordUObjectState::Invalid;
#endif

    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void Init();
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void Drop();

    /// \brief The label of the button.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get Label"))
    FString Label();

    /// \brief The label of the button.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetLabel(FString Label);

    /// \brief The url of the button.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get Url"))
    FString Url();

    /// \brief The url of the button.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetUrl(FString Url);
};

/// \brief An Activity represents one "thing" a user is doing on Discord and is part of their rich
/// presence.
///
/// Additional information is located on the Discord Developer Portal:
/// - https://discord.com/developers/docs/rich-presence/overview
/// - https://discord.com/developers/docs/developer-tools/game-sdk#activities
/// - https://discord.com/developers/docs/rich-presence/best-practices
///
/// While RichPresence supports multiple types of activities, the only activity type that is really
/// relevant for the SDK is ActivityTypes::Playing. Additionally, the SDK will only expose
/// Activities that are associated with the current game (or application). So for example, a field
/// like `name` below, will always be set to the current game's name from the view of the SDK.
///
/// ## Customization
/// When an activity shows up on Discord, it will look something like this:
/// 1. Playing "game name"
/// 2. Capture the flag | 2 - 1
/// 3. In a group (2 of 3)
///
/// You can control how lines 2 and 3 are rendered in Discord, here's the breakdown:
/// - Line 1, `Playing "game name"` is powered by the name of your game (or application) on Discord.
/// - Line 2, `Capture the flag | 2 - 1` is powered by the `details` field in the activity, and this
/// should generally try to describe what the _player_ is currently doing. You can even include
/// dynamic data such as a match score here.
/// - Line 3, `In a group (2 of 3)` describes the _party_ the player is in. "Party" is used to refer
/// to a group of players in a shared context, such as a lobby, server, team, etc. The first half,
/// `In a group` is powered by the `state` field in the activity, and the second half, `(2 of 3)` is
/// powered by the `party` field in the activity and describes how many people are in the current
/// party and how big the party can get.
///
/// This diagram visually shows the field mapping:
///
///
/// \image html "rich_presence.png" "Rich presence field diagram" width=1070px
///
/// You can also specify up to two custom buttons to display on the rich presence.
/// These buttons will open the URL in the user's default browser.
///
/// \code
///     discordpp::ActivityButton button;
///     button.SetLabel("Button 1");
///     button.SetUrl("https://example.com");
///     activity.AddButton(button);
/// \endcode
///
///
/// ## Invites / Joinable Activities
/// Other users can be invited to join the current player's activity (or request to join it too),
/// but that does require certain fields to be set:
/// 1. ActivityParty must be set and have a non-empty ActivityParty::Id field. All users in the
/// party should set the same id field too!
/// 2. ActivityParty must specify the size of the group, and there must be room in the group for
/// another person to join.
/// 3. ActivitySecrets::Join must be set to a non-empty string. The join secret is only shared with
/// users who are accepted into the party by an existing member, so it is truly a secret. You can
/// use this so that when the user is accepted your game knows how to join them to the party. For
/// example it could be an internal game ID, or a Discord lobby ID/secret that the client could
/// join.
///
/// There is additional information about game invites here:
/// https://support.discord.com/hc/en-us/articles/115001557452-Game-Invites
///
/// ### Mobile Invites
/// Activity invites are handled via a deep link. To enable users to join your game via an invite in
/// the Discord client, you must do two things:
/// 1. Set your deep link URL in the Discord developer portal. This will be available on the General
/// tab of your application once Social Layer integration is enabled for your app.
/// 2. Set the desired supported platforms when reporting the activity info in your rich presence,
/// e.g.:
///
///
/// \code
///     activity.SetSupportedPlatforms(
///         ActivityGamePlatforms.Desktop |
///         ActivityGamePlatforms.IOS |
///         ActivityGamePlatforms.Android);
/// \endcode
///
///
/// When the user accepts the invite, the Discord client will open:
/// `[your url]/_discord/join?secret=[the join secret you set]`
///
/// ### Example Invites Flow
/// If you are using Discord lobbies for your game, a neat flow would look like this:
/// - When a user starts playing the game, they create a lobby with a random secret string, using
/// Client::CreateOrJoinLobby
/// - That user publishes their RichPresence with the join secret set to the lobby secret, along
/// with party size information
/// - Another use can then see that RichPresence on Discord and join off of it
/// - Once accepted the new user receives the join secret and their client can call
/// CreateOrJoinLobby(joinSecret) to join the lobby
/// - Finally the original user can notice that the lobby membership has changed and so they publish
/// a new RichPresence update containing the updating party size information.
///
/// ### Invites Code Example
///
/// \code
/// // User A
/// // 1. Create a lobby with secret
/// std::string lobbySecret = "foo";
/// client->CreateOrJoinLobby(lobbySecret, [=](discordpp::ClientResult result, uint64_t lobbyId) {
///     // 2. Update rich presence with join secret
///     discordpp::Activity activity{};
///     // set name, state, party size ...
///     discordpp::ActivitySecrets secrets{};
///     secrets.SetJoin(lobbySecret);
///     activity.SetSecrets(secrets);
///     client->UpdateRichPresence(std::move(activity), [](discordpp::ClientResult result) {});
/// });
/// // 3. Some time later, send an invite
/// client->SendActivityInvite(USER_B_ID, "come play with me", [](auto result) {});
///
/// // User B
/// // 4. Monitor for new invites. Alternatively, you can use
/// // Client::SetActivityInviteUpdatedCallback to get updates on existing invites.
/// client->SetActivityInviteCreatedCallback([client](auto invite) {
///     // 5. When an invite is received, ask the user if they want to accept it.
///     // If they choose to do so then go ahead and invoke AcceptActivityInvite
///     client->AcceptActivityInvite(invite,
///         [client](discordpp::ClientResult result, std::string secret) {
///         if (result.Successful()) {
///             // 5. Join the lobby using the joinSecret
///             client->CreateOrJoinLobby(secret, [](discordpp::ClientResult result, uint64_t
///             lobbyId) {
///                 // Successfully joined lobby!
///             });
///         }
///     });
/// });
/// \endcode
///
///
/// ### Join Requests Code Example
/// Users can also request to join each others parties. This code snippet shows how that flow might
/// look:
///
/// \code
/// // User A
/// // 1. Create a lobby with secret
/// std::string lobbySecret = "foo";
/// client->CreateOrJoinLobby(lobbySecret, [=](discordpp::ClientResult result, uint64_t lobbyId) {
///     // 2. Update rich presence with join secret
///     discordpp::Activity activity{};
///     // set name, state, party size ...
///     discordpp::ActivitySecrets secrets{};
///     secrets.SetJoin(lobbySecret);
///     activity.SetSecrets(secrets);
///     client->UpdateRichPresence(std::move(activity), [](discordpp::ClientResult result) {});
/// });
///
/// // User B
/// // 3. Request to join User A's party
/// client->SendActivityJoinRequest(USER_A_ID, [](auto result) {});
///
/// // User A
/// // Monitor for new invites:
/// client->SetActivityInviteCreatedCallback([client](auto invite) {
///     // 5. The game can now show that User A has received a request to join their party
///     // If User A is ok with that, they can reply back:
///     // Note: invite.type will be ActivityActionTypes::JoinRequest in this example
///     client->SendActivityJoinRequestReply(invite, [](auto result) {});
/// });
///
/// // User B
/// // 6. Same as before, user B can monitor for invites
/// client->SetActivityInviteCreatedCallback([client](auto invite) {
///     // 7. When an invite is received, ask the user if they want to accept it.
///     // If they choose to do so then go ahead and invoke AcceptActivityInvite
///     client->AcceptActivityInvite(invite,
///         [client](discordpp::ClientResult result, std::string secret) {
///         if (result.Successful()) {
///             // 5. Join the lobby using the joinSecret
///             client->CreateOrJoinLobby(secret, [](auto result, uint64_t lobbyId) {
///                 // Successfully joined lobby!
///             });
///         }
///     });
/// });
/// \endcode
///
UCLASS(BlueprintType, Category = "Discord Partner SDK")
class DISCORDPARTNERSDK_API UDiscordActivity : public UObject {
    GENERATED_BODY()
public:
    ~UDiscordActivity();
#if !DISCORD_PARTNER_SDK_STUB
    Discord_Activity instance;
    DiscordUObjectState state = DiscordUObjectState::Invalid;
#endif

    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void Init();
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void Drop();

    /// \brief Adds a custom button to the rich presence
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void AddButton(UDiscordActivityButton* button);

    /// \brief Compares each field of the Activity struct for equality.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    bool Equals(UDiscordActivity* other);

    /// \brief Returns the custom buttons for the rich presence
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    TArray<UDiscordActivityButton*> GetButtons();

    /// \brief The name of the game or application that the activity is associated with.
    ///
    /// This field defaults to the name of the current game.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get Name"))
    FString Name();

    /// \brief The name of the game or application that the activity is associated with.
    ///
    /// This field defaults to the name of the current game.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetName(FString Name);

    /// \brief The type of activity this is.
    ///
    /// This should almost always be set to `Playing`
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get Type"))
    EDiscordActivityTypes Type();

    /// \brief The type of activity this is.
    ///
    /// This should almost always be set to `Playing`
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetType(EDiscordActivityTypes Type);

    /// \brief Controls which field is used for the user's status message
    ///
    /// See the docs on the Activity struct for more info.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get StatusDisplayType"))
    EDiscordStatusDisplayTypes StatusDisplayType();

    /// \brief Controls which field is used for the user's status message
    ///
    /// See the docs on the Activity struct for more info.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetStatusDisplayType(EDiscordStatusDisplayTypes StatusDisplayType);

    /// \brief The state _of the party_ for this activity.
    ///
    /// See the docs on the Activity struct for more info.
    /// If specified, must be a string between 2 and 128 characters.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get State"))
    FString State();

    /// \brief The state _of the party_ for this activity.
    ///
    /// See the docs on the Activity struct for more info.
    /// If specified, must be a string between 2 and 128 characters.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetState(FString State);

    /// \brief A URL that opens when the user clicks/taps the state text.
    ///
    /// See the docs on the Activity struct for more info.
    /// If specified, must be a string between 2 and 256 characters.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get StateUrl"))
    FString StateUrl();

    /// \brief A URL that opens when the user clicks/taps the state text.
    ///
    /// See the docs on the Activity struct for more info.
    /// If specified, must be a string between 2 and 256 characters.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetStateUrl(FString StateUrl);

    /// \brief The state _of the what the user is doing_ for this activity.
    ///
    /// See the docs on the Activity struct for more info.
    /// If specified, must be a string between 2 and 128 characters.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get Details"))
    FString Details();

    /// \brief The state _of the what the user is doing_ for this activity.
    ///
    /// See the docs on the Activity struct for more info.
    /// If specified, must be a string between 2 and 128 characters.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetDetails(FString Details);

    /// \brief A URL that opens when the user clicks/taps the details text.
    ///
    /// See the docs on the Activity struct for more info.
    /// If specified, must be a string between 2 and 256 characters.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get DetailsUrl"))
    FString DetailsUrl();

    /// \brief A URL that opens when the user clicks/taps the details text.
    ///
    /// See the docs on the Activity struct for more info.
    /// If specified, must be a string between 2 and 256 characters.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetDetailsUrl(FString DetailsUrl);

    /// \brief The application ID of the game that the activity is associated with.
    ///
    /// This field cannot be set by the SDK, and will always be the application ID of the current
    /// game or a game from the same publisher.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get ApplicationId"))
    FDiscordUniqueID ApplicationId();

    /// \brief The application ID of the game that the activity is associated with.
    ///
    /// This field cannot be set by the SDK, and will always be the application ID of the current
    /// game or a game from the same publisher.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetApplicationId(FDiscordUniqueID ApplicationId);

    /// \brief The application ID of the parent application that the activity is associated with if
    /// it exists. This is to help identify a collection of games that are from the same publisher.
    ///
    /// This field cannot be set by the SDK, and will always be the application ID of the game's
    /// parent or unset if the game has no parent.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get ParentApplicationId"))
    FDiscordUniqueID ParentApplicationId();

    /// \brief The application ID of the parent application that the activity is associated with if
    /// it exists. This is to help identify a collection of games that are from the same publisher.
    ///
    /// This field cannot be set by the SDK, and will always be the application ID of the game's
    /// parent or unset if the game has no parent.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetParentApplicationId(FDiscordUniqueID ParentApplicationId);

    /// \brief Images used to customize how the Activity is displayed in the Discord client.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get Assets"))
    UDiscordActivityAssets* Assets();

    /// \brief Images used to customize how the Activity is displayed in the Discord client.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetAssets(UDiscordActivityAssets* Assets);

    /// \brief The timestamps struct can be used to render either:
    /// - a "time remaining" countdown timer (by specifying the `end` value)
    /// - a "time elapsed" countup timer (by specifying the `start` value)
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get Timestamps"))
    UDiscordActivityTimestamps* Timestamps();

    /// \brief The timestamps struct can be used to render either:
    /// - a "time remaining" countdown timer (by specifying the `end` value)
    /// - a "time elapsed" countup timer (by specifying the `start` value)
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetTimestamps(UDiscordActivityTimestamps* Timestamps);

    /// \brief The party struct is used to indicate the size and members of the people the current
    /// user is playing with.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get Party"))
    UDiscordActivityParty* Party();

    /// \brief The party struct is used to indicate the size and members of the people the current
    /// user is playing with.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetParty(UDiscordActivityParty* Party);

    /// \brief The secrets struct is used in combination with the party struct to make an Activity
    /// joinable.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get Secrets"))
    UDiscordActivitySecrets* Secrets();

    /// \brief The secrets struct is used in combination with the party struct to make an Activity
    /// joinable.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetSecrets(UDiscordActivitySecrets* Secrets);

    /// \brief If an activity is joinable, but only on certain platforms, this field can be used to
    /// indicate which platforms the activity is joinable on. For example if a game is available on
    /// both PC and Mobile, but PC users cannot join Mobile users and vice versa, this field can be
    /// used so that an activity only shows as joinable on Discord if the user is on the appropriate
    /// platform.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get SupportedPlatforms"))
    EDiscordActivityGamePlatforms SupportedPlatforms();

    /// \brief If an activity is joinable, but only on certain platforms, this field can be used to
    /// indicate which platforms the activity is joinable on. For example if a game is available on
    /// both PC and Mobile, but PC users cannot join Mobile users and vice versa, this field can be
    /// used so that an activity only shows as joinable on Discord if the user is on the appropriate
    /// platform.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetSupportedPlatforms(EDiscordActivityGamePlatforms SupportedPlatforms);
};

/// \brief Struct that stores information about the result of an SDK function call.
///
/// Functions can fail for a few reasons including:
/// - The Client is not yet ready and able to perform the action.
/// - The inputs passed to the function are invalid.
/// - The function makes an API call to Discord's backend which returns an error.
/// - The user is offline.
///
/// The ClientResult::Type field is used to to distinguish between the above types of failures
UCLASS(BlueprintType, Category = "Discord Partner SDK")
class DISCORDPARTNERSDK_API UDiscordClientResult : public UObject {
    GENERATED_BODY()
public:
    ~UDiscordClientResult();
#if !DISCORD_PARTNER_SDK_STUB
    Discord_ClientResult instance;
    DiscordUObjectState state = DiscordUObjectState::Invalid;
#endif

    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void Drop();

    /// \brief Returns the error message if any of the ClientResult.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    FString ToString();

    /// \brief The type of error that occurred. See ErrorType for more information.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get Type"))
    EDiscordErrorType Type();

    /// \brief The type of error that occurred. See ErrorType for more information.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetType(EDiscordErrorType Type);

    /// \brief A description of the error that occurred.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get Error"))
    FString Error();

    /// \brief A description of the error that occurred.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetError(FString Error);

    /// \brief A more detailed error code for this failure. Currently the only use of this is when
    /// an API request is made to Discord's backend and that fails with a specific error, that error
    /// will be included in this field.
    ///
    /// Many of these error codes are documented at:
    /// https://discord.com/developers/docs/topics/opcodes-and-status-codes#json
    ///
    /// This will only be set if the type of error is ErrorType::HTTPError
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get ErrorCode"))
    int32 ErrorCode();

    /// \brief A more detailed error code for this failure. Currently the only use of this is when
    /// an API request is made to Discord's backend and that fails with a specific error, that error
    /// will be included in this field.
    ///
    /// Many of these error codes are documented at:
    /// https://discord.com/developers/docs/topics/opcodes-and-status-codes#json
    ///
    /// This will only be set if the type of error is ErrorType::HTTPError
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetErrorCode(int32 ErrorCode);

    /// \brief The HTTP status code of the API call.
    ///
    /// This will only be set if the type of error is ErrorType::HTTPError
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get Status"))
    int32 Status();

    /// \brief The HTTP status code of the API call.
    ///
    /// This will only be set if the type of error is ErrorType::HTTPError
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetStatus(int32 Status);

    /// \brief The full HTTP response body, which will usually be a JSON string.
    ///
    /// The error format here is a bit more complicated because Discord's API tries to
    /// make it clear which field from the request is causing the error. Documentation on the format
    /// of these errors is here: https://discord.com/developers/docs/reference#error-messages
    ///
    /// This will only be set if the type of error is ErrorType::HTTPError
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get ResponseBody"))
    FString ResponseBody();

    /// \brief The full HTTP response body, which will usually be a JSON string.
    ///
    /// The error format here is a bit more complicated because Discord's API tries to
    /// make it clear which field from the request is causing the error. Documentation on the format
    /// of these errors is here: https://discord.com/developers/docs/reference#error-messages
    ///
    /// This will only be set if the type of error is ErrorType::HTTPError
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetResponseBody(FString ResponseBody);

    /// \brief Equivalent to type == ErrorType::None
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get Successful"))
    bool Successful();

    /// \brief Equivalent to type == ErrorType::None
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetSuccessful(bool Successful);

    /// \brief Indicates if, although an API request failed, it is safe and recommended to retry it.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get Retryable"))
    bool Retryable();

    /// \brief Indicates if, although an API request failed, it is safe and recommended to retry it.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetRetryable(bool Retryable);

    /// \brief When a user is being rate limited by Discord (and so status == 429), this field
    /// should be set and is the number of seconds to wait before trying again.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get RetryAfter"))
    float RetryAfter();

    /// \brief When a user is being rate limited by Discord (and so status == 429), this field
    /// should be set and is the number of seconds to wait before trying again.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetRetryAfter(float RetryAfter);
};

/// \brief Struct that encapsulates the challenge part of the code verification flow.
UCLASS(BlueprintType, Category = "Discord Partner SDK")
class DISCORDPARTNERSDK_API UDiscordAuthorizationCodeChallenge : public UObject {
    GENERATED_BODY()
public:
    ~UDiscordAuthorizationCodeChallenge();
#if !DISCORD_PARTNER_SDK_STUB
    Discord_AuthorizationCodeChallenge instance;
    DiscordUObjectState state = DiscordUObjectState::Invalid;
#endif

    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void Init();
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void Drop();

    /// \brief The method used to generate the challenge. The only method used by the SDK is sha256.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get Method"))
    EDiscordAuthenticationCodeChallengeMethod Method();

    /// \brief The method used to generate the challenge. The only method used by the SDK is sha256.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetMethod(EDiscordAuthenticationCodeChallengeMethod Method);

    /// \brief The challenge value
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get Challenge"))
    FString Challenge();

    /// \brief The challenge value
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetChallenge(FString Challenge);
};

/// \brief Struct that encapsulates both parts of the code verification flow.
UCLASS(BlueprintType, Category = "Discord Partner SDK")
class DISCORDPARTNERSDK_API UDiscordAuthorizationCodeVerifier : public UObject {
    GENERATED_BODY()
public:
    ~UDiscordAuthorizationCodeVerifier();
#if !DISCORD_PARTNER_SDK_STUB
    Discord_AuthorizationCodeVerifier instance;
    DiscordUObjectState state = DiscordUObjectState::Invalid;
#endif

    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void Drop();

    /// \brief The challenge part of the code verification flow.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get Challenge"))
    UDiscordAuthorizationCodeChallenge* Challenge();

    /// \brief The challenge part of the code verification flow.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetChallenge(UDiscordAuthorizationCodeChallenge* Challenge);

    /// \brief The verifier part of the code verification flow.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get Verifier"))
    FString Verifier();

    /// \brief The verifier part of the code verification flow.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetVerifier(FString Verifier);
};

/// \brief Arguments to the Client::Authorize function.
UCLASS(BlueprintType, Category = "Discord Partner SDK")
class DISCORDPARTNERSDK_API UDiscordAuthorizationArgs : public UObject {
    GENERATED_BODY()
public:
    ~UDiscordAuthorizationArgs();
#if !DISCORD_PARTNER_SDK_STUB
    Discord_AuthorizationArgs instance;
    DiscordUObjectState state = DiscordUObjectState::Invalid;
#endif

    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void Init();
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void Drop();

    /// \brief Optional. The Discord application ID for your game. Defaults to the value set by
    /// Client::SetApplicationId.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get ClientId"))
    FDiscordUniqueID ClientId();

    /// \brief Optional. The Discord application ID for your game. Defaults to the value set by
    /// Client::SetApplicationId.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetClientId(FDiscordUniqueID ClientId);

    /// \brief Scopes is a space separated string of the oauth scopes your game is requesting.
    ///
    /// Most games should just pass in Client::GetDefaultCommunicationScopes or
    /// Client::GetDefaultPresenceScopes which will include these scopes, respectively:
    /// `openid sdk.social_layer` or `openid sdk.social_layer_presence`
    ///
    /// `sdk.social_layer` and `sdk.social_layer_presence` automatically expand to include all the
    /// necessary scopes for the integration.
    ///
    /// You can pass in additional scopes if you need to, but as a general rule you should only
    /// request the scopes you actually need, and the user will need to grant access to those
    /// additional scopes as well.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get Scopes"))
    FString Scopes();

    /// \brief Scopes is a space separated string of the oauth scopes your game is requesting.
    ///
    /// Most games should just pass in Client::GetDefaultCommunicationScopes or
    /// Client::GetDefaultPresenceScopes which will include these scopes, respectively:
    /// `openid sdk.social_layer` or `openid sdk.social_layer_presence`
    ///
    /// `sdk.social_layer` and `sdk.social_layer_presence` automatically expand to include all the
    /// necessary scopes for the integration.
    ///
    /// You can pass in additional scopes if you need to, but as a general rule you should only
    /// request the scopes you actually need, and the user will need to grant access to those
    /// additional scopes as well.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetScopes(FString Scopes);

    /// \brief See https://discord.com/developers/docs/topics/oauth2#state-and-security for details
    /// on this field.
    ///
    /// We recommend leaving this unset, and the SDK will automatically generate a secure
    /// random value for you.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get State"))
    FString State();

    /// \brief See https://discord.com/developers/docs/topics/oauth2#state-and-security for details
    /// on this field.
    ///
    /// We recommend leaving this unset, and the SDK will automatically generate a secure
    /// random value for you.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetState(FString State);

    /// \brief The nonce field is generally only useful for backend integrations using ID tokens.
    ///
    /// For more information, see:
    /// https://openid.net/specs/openid-connect-core-1_0.html#rfc.section.2~nonce:~:text=auth_time%20response%20parameter.)-,nonce,-String%20value%20used
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get Nonce"))
    FString Nonce();

    /// \brief The nonce field is generally only useful for backend integrations using ID tokens.
    ///
    /// For more information, see:
    /// https://openid.net/specs/openid-connect-core-1_0.html#rfc.section.2~nonce:~:text=auth_time%20response%20parameter.)-,nonce,-String%20value%20used
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetNonce(FString Nonce);

    /// \brief If using the Client::GetToken flow, you will need to generate a code challenge and
    /// verifier.
    ///
    /// Use Client::CreateAuthorizationCodeVerifier to generate these values and pass the challenge
    /// property here.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get CodeChallenge"))
    UDiscordAuthorizationCodeChallenge* CodeChallenge();

    /// \brief If using the Client::GetToken flow, you will need to generate a code challenge and
    /// verifier.
    ///
    /// Use Client::CreateAuthorizationCodeVerifier to generate these values and pass the challenge
    /// property here.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetCodeChallenge(UDiscordAuthorizationCodeChallenge* CodeChallenge);

    /// \brief The type of integration the app will be installed as.
    ///
    /// https://discord.com/developers/docs/resources/application#installation-context
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get IntegrationType"))
    EDiscordIntegrationType IntegrationType();

    /// \brief The type of integration the app will be installed as.
    ///
    /// https://discord.com/developers/docs/resources/application#installation-context
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetIntegrationType(EDiscordIntegrationType IntegrationType);

    /// \brief Custom URI scheme for mobile redirects.
    ///
    /// This allows games to specify a completely custom URI scheme for OAuth redirects.
    /// For example, setting this to "mygame" will result in a URI scheme like:
    /// mygame:/authorize/callback
    ///
    /// If not provided, defaults to the standard Discord format:
    /// discord-123456789:/authorize/callback
    ///
    /// This is particularly useful for distinguishing between multiple games from the same
    /// developer or for avoiding conflicts with other apps.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get CustomSchemeParam"))
    FString CustomSchemeParam();

    /// \brief Custom URI scheme for mobile redirects.
    ///
    /// This allows games to specify a completely custom URI scheme for OAuth redirects.
    /// For example, setting this to "mygame" will result in a URI scheme like:
    /// mygame:/authorize/callback
    ///
    /// If not provided, defaults to the standard Discord format:
    /// discord-123456789:/authorize/callback
    ///
    /// This is particularly useful for distinguishing between multiple games from the same
    /// developer or for avoiding conflicts with other apps.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetCustomSchemeParam(FString CustomSchemeParam);
};

/// \brief Arguments to the Client::GetTokenFromDevice function.
UCLASS(BlueprintType, Category = "Discord Partner SDK")
class DISCORDPARTNERSDK_API UDiscordDeviceAuthorizationArgs : public UObject {
    GENERATED_BODY()
public:
    ~UDiscordDeviceAuthorizationArgs();
#if !DISCORD_PARTNER_SDK_STUB
    Discord_DeviceAuthorizationArgs instance;
    DiscordUObjectState state = DiscordUObjectState::Invalid;
#endif

    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void Init();
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void Drop();

    /// \brief Optional. The Discord application ID for your game. Defaults to the value set by
    /// Client::SetApplicationId.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get ClientId"))
    FDiscordUniqueID ClientId();

    /// \brief Optional. The Discord application ID for your game. Defaults to the value set by
    /// Client::SetApplicationId.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetClientId(FDiscordUniqueID ClientId);

    /// \brief Scopes is a space separated string of the oauth scopes your game is requesting.
    ///
    /// Most games should just pass in Client::GetDefaultCommunicationScopes or
    /// Client::GetDefaultPresenceScopes which will include these scopes, respectively:
    /// `openid sdk.social_layer` or `openid sdk.social_layer_presence`
    ///
    /// `sdk.social_layer` and `sdk.social_layer_presence` automatically expand to include all the
    /// necessary scopes for the integration.
    ///
    /// You can pass in additional scopes if you need to, but as a general rule you should only
    /// request the scopes you actually need, and the user will need to grant access to those
    /// additional scopes as well.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get Scopes"))
    FString Scopes();

    /// \brief Scopes is a space separated string of the oauth scopes your game is requesting.
    ///
    /// Most games should just pass in Client::GetDefaultCommunicationScopes or
    /// Client::GetDefaultPresenceScopes which will include these scopes, respectively:
    /// `openid sdk.social_layer` or `openid sdk.social_layer_presence`
    ///
    /// `sdk.social_layer` and `sdk.social_layer_presence` automatically expand to include all the
    /// necessary scopes for the integration.
    ///
    /// You can pass in additional scopes if you need to, but as a general rule you should only
    /// request the scopes you actually need, and the user will need to grant access to those
    /// additional scopes as well.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetScopes(FString Scopes);
};

/// \brief A VoiceStateHandle represents the state of a single participant in a Discord voice call.
///
/// The main use case for VoiceStateHandle in the SDK is communicate whether a user has muted or
/// defeaned themselves.
///
/// Handle objects in the SDK hold a reference both to the underlying data, and to the SDK instance.
/// Changes to the underlying data will generally be available on existing handles objects without
/// having to re-create them. If the SDK instance is destroyed, but you still have a reference to a
/// handle object, note that it will return the default value for all method calls (ie an empty
/// string for methods that return a string).
UCLASS(BlueprintType, Category = "Discord Partner SDK")
class DISCORDPARTNERSDK_API UDiscordVoiceStateHandle : public UObject {
    GENERATED_BODY()
public:
    ~UDiscordVoiceStateHandle();
#if !DISCORD_PARTNER_SDK_STUB
    Discord_VoiceStateHandle instance;
    DiscordUObjectState state = DiscordUObjectState::Invalid;
#endif

    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void Drop();

    /// \brief Returns true if the given user has deafened themselves so that no one else in the
    /// call can hear them and so that they do not hear anyone else in the call either.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    bool SelfDeaf();

    /// \brief Returns true if the given user has muted themselves so that no one else in the call
    /// can hear them.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    bool SelfMute();
};

/// \brief Settings for the void auto detection threshold for picking up activity from a user's mic.
UCLASS(BlueprintType, Category = "Discord Partner SDK")
class DISCORDPARTNERSDK_API UDiscordVADThresholdSettings : public UObject {
    GENERATED_BODY()
public:
    ~UDiscordVADThresholdSettings();
#if !DISCORD_PARTNER_SDK_STUB
    Discord_VADThresholdSettings instance;
    DiscordUObjectState state = DiscordUObjectState::Invalid;
#endif

    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void Drop();

    /// \brief The current void auto detection threshold value, has a range of -100, 0 and defaults
    /// to -60.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get VadThreshold"))
    float VadThreshold();

    /// \brief The current void auto detection threshold value, has a range of -100, 0 and defaults
    /// to -60.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetVadThreshold(float VadThreshold);

    /// \brief Whether or not Discord is currently automatically setting and detecting the
    /// appropriate threshold to use.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get Automatic"))
    bool Automatic();

    /// \brief Whether or not Discord is currently automatically setting and detecting the
    /// appropriate threshold to use.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetAutomatic(bool Automatic);
};

/// \brief Class that manages an active voice session in a Lobby.
UCLASS(BlueprintType, Category = "Discord Partner SDK")
class DISCORDPARTNERSDK_API UDiscordCall : public UObject {
    GENERATED_BODY()
public:
    ~UDiscordCall();
#if !DISCORD_PARTNER_SDK_STUB
    Discord_Call instance;
    DiscordUObjectState state = DiscordUObjectState::Invalid;
#endif

    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void Drop();

    /// \brief Converts the Error enum to a string.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    static FString ErrorToString(EDiscordCallError type);

    /// \brief Returns whether the call is configured to use voice auto detection or push to talk
    /// for the current user.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    EDiscordAudioModeType GetAudioMode();

    /// \brief Returns the ID of the lobby with which this call is associated.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    FDiscordUniqueID GetChannelId();

    /// \brief Returns the ID of the lobby with which this call is associated.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    FDiscordUniqueID GetGuildId();

    /// \brief Returns whether the current user has locally muted the given userId for themselves.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    bool GetLocalMute(FDiscordUniqueID userId);

    /// \brief Returns a list of all of the user IDs of the participants in the call.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    TArray<FDiscordUniqueID> GetParticipants();

    /// \brief Returns the locally set playout volume of the given userId.
    ///
    /// Does not affect the volume of this user for any other connected clients. The range of volume
    /// is [0, 200], where 100 indicate default audio volume of the playback device.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    float GetParticipantVolume(FDiscordUniqueID userId);

    /// \brief Returns whether push to talk is currently active, meaning the user is currently
    /// pressing their configured push to talk key.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    bool GetPTTActive();

    /// \brief Returns the time that PTT is active after the user releases the PTT key and
    /// SetPTTActive(false) is called.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    int32 GetPTTReleaseDelay();

    /// \brief Returns whether the current user is deafened.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    bool GetSelfDeaf();

    /// \brief Returns whether the current user's microphone is muted.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    bool GetSelfMute();

    /// \brief Returns the current call status.
    ///
    /// A call is not ready to be used until the status changes to "Connected".
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    EDiscordCallStatus GetStatus();

    /// \brief Returns the current configuration for void auto detection thresholds. See the
    /// description of the VADThreshold struct for specifics.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    UDiscordVADThresholdSettings* GetVADThreshold();

    /// \brief Returns a reference to the VoiceStateHandle for the user ID of the given call
    /// participant.
    ///
    /// The VoiceStateHandle allows other users to know if the target user has muted or deafened
    /// themselves.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    UDiscordVoiceStateHandle* GetVoiceStateHandle(FDiscordUniqueID userId);

    /// \brief Sets whether to use voice auto detection or push to talk for the current user on this
    /// call.
    ///
    /// If using push to talk you should call SetPTTActive() whenever the user presses their
    /// confused push to talk key.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetAudioMode(EDiscordAudioModeType audioMode);

    /// \brief Locally mutes the given userId, so that the current user cannot hear them anymore.
    ///
    /// Does not affect whether the given user is muted for any other connected clients.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetLocalMute(FDiscordUniqueID userId, bool mute);

    /// \brief Sets a callback function to generally be invoked whenever a field on a
    /// VoiceStateHandle object for a user would have changed.
    ///
    /// For example when a user mutes themselves, all other connected clients will invoke the
    /// VoiceStateChanged callback, because the "self mute" field will be true now. The callback is
    /// generally not invoked when users join or leave channels.
    void SetOnVoiceStateChangedCallback(FDiscordCallOnVoiceStateChanged const& cb);

    /// \brief Sets a callback function to generally be invoked whenever a field on a
    /// VoiceStateHandle object for a user would have changed.
    ///
    /// For example when a user mutes themselves, all other connected clients will invoke the
    /// VoiceStateChanged callback, because the "self mute" field will be true now. The callback is
    /// generally not invoked when users join or leave channels.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void SetOnVoiceStateChangedCallback(FDiscordCallOnVoiceStateChangedDynamic const& cb);

    /// \brief Sets a callback function to be invoked whenever some joins or leaves a voice call.
    void SetParticipantChangedCallback(FDiscordCallOnParticipantChanged const& cb);

    /// \brief Sets a callback function to be invoked whenever some joins or leaves a voice call.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void SetParticipantChangedCallback(FDiscordCallOnParticipantChangedDynamic const& cb);

    /// \brief Locally changes the playout volume of the given userId.
    ///
    /// Does not affect the volume of this user for any other connected clients. The range of volume
    /// is [0, 200], where 100 indicate default audio volume of the playback device.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetParticipantVolume(FDiscordUniqueID userId, float volume);

    /// \brief When push to talk is enabled, this should be called whenever the user pushes or
    /// releases their configured push to talk key. This key must be configured in the game, the SDK
    /// does not handle keybinds itself.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetPTTActive(bool active);

    /// \brief If set, extends the time that PTT is active after the user releases the PTT key and
    /// SetPTTActive(false) is called.
    ///
    /// Defaults to no release delay, but we recommend setting to 20ms, which is what Discord uses.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetPTTReleaseDelay(int32 releaseDelayMs);

    /// \brief Mutes all audio from the currently active call for the current user.
    /// They will not be able to hear any other participants,
    /// and no other participants will be able to hear the current user either.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetSelfDeaf(bool deaf);

    /// \brief Mutes the current user's microphone so that no other participant in their active
    /// calls can hear them.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetSelfMute(bool mute);

    /// \brief Sets a callback function to be invoked whenever a user starts or stops speaking and
    /// is passed in the userId and whether they are currently speaking.
    ///
    /// It can be invoked in other cases as well, such as if the priority speaker changes or if the
    /// user plays a soundboard sound.
    void SetSpeakingStatusChangedCallback(FDiscordCallOnSpeakingStatusChanged const& cb);

    /// \brief Sets a callback function to be invoked whenever a user starts or stops speaking and
    /// is passed in the userId and whether they are currently speaking.
    ///
    /// It can be invoked in other cases as well, such as if the priority speaker changes or if the
    /// user plays a soundboard sound.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void SetSpeakingStatusChangedCallback(FDiscordCallOnSpeakingStatusChangedDynamic const& cb);

    /// \brief Sets a callback function to be invoked when the call status changes, such as when it
    /// fully connects or starts reconnecting.
    void SetStatusChangedCallback(FDiscordCallOnStatusChanged const& cb);

    /// \brief Sets a callback function to be invoked when the call status changes, such as when it
    /// fully connects or starts reconnecting.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void SetStatusChangedCallback(FDiscordCallOnStatusChangedDynamic const& cb);

    /// \brief Customizes the void auto detection thresholds for picking up activity from a user's
    /// mic.
    /// - When automatic is set to True, Discord will automatically detect the appropriate threshold
    /// to use.
    /// - When automatic is set to False, the given threshold value will be used. Threshold has a
    /// range of -100, 0, and defaults to -60.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetVADThreshold(bool automatic, float threshold);

    /// \brief Converts the Status enum to a string.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    static FString StatusToString(EDiscordCallStatus type);
};

/// \brief All messages sent on Discord are done so in a Channel. MessageHandle::ChannelId will
/// contain the ID of the channel a message was sent in, and Client::GetChannelHandle will return an
/// instance of this class.
///
/// Handle objects in the SDK hold a reference both to the underlying data, and to the SDK instance.
/// Changes to the underlying data will generally be available on existing handles objects without
/// having to re-create them. If the SDK instance is destroyed, but you still have a reference to a
/// handle object, note that it will return the default value for all method calls (ie an empty
/// string for methods that return a string).
UCLASS(BlueprintType, Category = "Discord Partner SDK")
class DISCORDPARTNERSDK_API UDiscordChannelHandle : public UObject {
    GENERATED_BODY()
public:
    ~UDiscordChannelHandle();
#if !DISCORD_PARTNER_SDK_STUB
    Discord_ChannelHandle instance;
    DiscordUObjectState state = DiscordUObjectState::Invalid;
#endif

    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void Drop();
#if DISCORD_DEBUG_API_ENABLED
    UDiscordCallInfoHandle* GetCallInfoHandle();
#endif

    /// \brief Returns the ID of the channel.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    FDiscordUniqueID Id();

    /// \brief Returns the name of the channel.
    ///
    /// Generally only channels in servers have names, although Discord may generate a display name
    /// for some channels as well.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    FString Name();

    /// \brief For DMs and GroupDMs, returns the user IDs of the members of the channel.
    /// For all other channels returns an empty list.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    TArray<FDiscordUniqueID> Recipients();

    /// \brief Returns the type of the channel.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    EDiscordChannelType Type();
};

/// \brief Represents a guild (also knowns as a Discord server), that the current user is a member
/// of, that contains channels that can be linked to a lobby.
UCLASS(BlueprintType, Category = "Discord Partner SDK")
class DISCORDPARTNERSDK_API UDiscordGuildMinimal : public UObject {
    GENERATED_BODY()
public:
    ~UDiscordGuildMinimal();
#if !DISCORD_PARTNER_SDK_STUB
    Discord_GuildMinimal instance;
    DiscordUObjectState state = DiscordUObjectState::Invalid;
#endif

    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void Drop();

    /// \brief The id of the guild.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get Id"))
    FDiscordUniqueID Id();

    /// \brief The id of the guild.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetId(FDiscordUniqueID Id);

    /// \brief The name of the guild.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get Name"))
    FString Name();

    /// \brief The name of the guild.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetName(FString Name);
};

/// \brief Represents a channel in a guild that the current user is a member of and may be able to
/// be linked to a lobby.
UCLASS(BlueprintType, Category = "Discord Partner SDK")
class DISCORDPARTNERSDK_API UDiscordGuildChannel : public UObject {
    GENERATED_BODY()
public:
    ~UDiscordGuildChannel();
#if !DISCORD_PARTNER_SDK_STUB
    Discord_GuildChannel instance;
    DiscordUObjectState state = DiscordUObjectState::Invalid;
#endif

    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void Drop();

    /// \brief The id of the channel.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get Id"))
    FDiscordUniqueID Id();

    /// \brief The id of the channel.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetId(FDiscordUniqueID Id);

    /// \brief The name of the channel.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get Name"))
    FString Name();

    /// \brief The name of the channel.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetName(FString Name);

    /// \brief The type of the channel.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get Type"))
    EDiscordChannelType Type();

    /// \brief The type of the channel.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetType(EDiscordChannelType Type);

    /// \brief The position of the channel in the guild's channel list.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get Position"))
    int32 Position();

    /// \brief The position of the channel in the guild's channel list.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetPosition(int32 Position);

    /// \brief The id of the parent category channel, if any.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get ParentId"))
    FDiscordUniqueID ParentId();

    /// \brief The id of the parent category channel, if any.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetParentId(FDiscordUniqueID ParentId);

    /// \brief Whether the current user is able to link this channel to a lobby.
    ///
    /// For this to be true:
    /// - The channel must be a guild text channel
    /// - The channel may not be marked as NSFW
    /// - The channel must not be currently linked to a different lobby
    /// - The user must have the following permissions in the channel in order to link it:
    ///   - Manage Channels
    ///   - View Channel
    ///   - Send Messages
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get IsLinkable"))
    bool IsLinkable();

    /// \brief Whether the current user is able to link this channel to a lobby.
    ///
    /// For this to be true:
    /// - The channel must be a guild text channel
    /// - The channel may not be marked as NSFW
    /// - The channel must not be currently linked to a different lobby
    /// - The user must have the following permissions in the channel in order to link it:
    ///   - Manage Channels
    ///   - View Channel
    ///   - Send Messages
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetIsLinkable(bool IsLinkable);

    /// \brief Whether the channel is "fully public" which means every member of the guild is able
    /// to view and send messages in that channel.
    ///
    /// Discord allows lobbies to be linked to private channels
    /// in a server, which enables things like a private admin chat.
    ///
    /// However there is no permission synchronization between the game and Discord, so it is the
    /// responsibility of the game to restrict access to the lobby. Every member of the lobby will
    /// be able to view and send messages in the lobby/channel, regardless of whether that user
    /// would have permission to do so in Discord.
    ///
    /// This may be more complexity than a game wants to take on, so instead you can only allow
    /// linking of channels that are fully public in the server so there is no confusion.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get IsViewableAndWriteableByAllMembers"))
    bool IsViewableAndWriteableByAllMembers();

    /// \brief Whether the channel is "fully public" which means every member of the guild is able
    /// to view and send messages in that channel.
    ///
    /// Discord allows lobbies to be linked to private channels
    /// in a server, which enables things like a private admin chat.
    ///
    /// However there is no permission synchronization between the game and Discord, so it is the
    /// responsibility of the game to restrict access to the lobby. Every member of the lobby will
    /// be able to view and send messages in the lobby/channel, regardless of whether that user
    /// would have permission to do so in Discord.
    ///
    /// This may be more complexity than a game wants to take on, so instead you can only allow
    /// linking of channels that are fully public in the server so there is no confusion.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetIsViewableAndWriteableByAllMembers(bool IsViewableAndWriteableByAllMembers);

    /// \brief Information about the currently linked lobby, if any.
    /// Currently Discord enforces that a channel can only be linked to a single lobby.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get LinkedLobby"))
    UDiscordLinkedLobby* LinkedLobby();

    /// \brief Information about the currently linked lobby, if any.
    /// Currently Discord enforces that a channel can only be linked to a single lobby.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetLinkedLobby(UDiscordLinkedLobby* LinkedLobby);
};

/// \brief Struct that stores information about the lobby linked to a channel.
UCLASS(BlueprintType, Category = "Discord Partner SDK")
class DISCORDPARTNERSDK_API UDiscordLinkedLobby : public UObject {
    GENERATED_BODY()
public:
    ~UDiscordLinkedLobby();
#if !DISCORD_PARTNER_SDK_STUB
    Discord_LinkedLobby instance;
    DiscordUObjectState state = DiscordUObjectState::Invalid;
#endif

    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void Init();
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void Drop();

    /// \brief The ID of the application that owns the lobby.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get ApplicationId"))
    FDiscordUniqueID ApplicationId();

    /// \brief The ID of the application that owns the lobby.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetApplicationId(FDiscordUniqueID ApplicationId);

    /// \brief The ID of the lobby.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get LobbyId"))
    FDiscordUniqueID LobbyId();

    /// \brief The ID of the lobby.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetLobbyId(FDiscordUniqueID LobbyId);
};

/// \brief Struct that stores information about the channel that a lobby is linked to.
UCLASS(BlueprintType, Category = "Discord Partner SDK")
class DISCORDPARTNERSDK_API UDiscordLinkedChannel : public UObject {
    GENERATED_BODY()
public:
    ~UDiscordLinkedChannel();
#if !DISCORD_PARTNER_SDK_STUB
    Discord_LinkedChannel instance;
    DiscordUObjectState state = DiscordUObjectState::Invalid;
#endif

    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void Drop();

    /// \brief The id of the linked channel.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get Id"))
    FDiscordUniqueID Id();

    /// \brief The id of the linked channel.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetId(FDiscordUniqueID Id);

    /// \brief The name of the linked channel.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get Name"))
    FString Name();

    /// \brief The name of the linked channel.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetName(FString Name);

    /// \brief The id of the guild (aka server) that owns the linked channel.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get GuildId"))
    FDiscordUniqueID GuildId();

    /// \brief The id of the guild (aka server) that owns the linked channel.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetGuildId(FDiscordUniqueID GuildId);
};

/// \brief A RelationshipHandle represents the relationship between the current user and a target
/// user on Discord. Relationships include friends, blocked users, and friend invites.
///
/// The SDK supports two types of relationships:
/// - Discord: These are relationships that persist across games and on the Discord client.
/// Both users will be able to see whether each other is online regardless of whether they are in
/// the same game or not.
/// - Game: These are per-game relationships and do not carry over to other games. The two users
/// will only be able to see if the other is online if they are playing a game in which they are
/// friends.
///
/// If someone is a game friend they can later choose to "upgrade" to a full Discord friend. In this
/// case, the user has two relationships at the same time, which is why there are two different type
/// fields on RelationshipHandle. In this example, their RelationshipHandle::DiscordRelationshipType
/// would be set to RelationshipType::PendingIncoming or RelationshipType::PendingOutgoing (based on
/// whether they are receiving or sending the invite respectively), and their
/// RelationshipHandle::GameRelationshipType would remain as RelationshipType::Friend.
///
/// When a user blocks another user, it is always stored on the
/// RelationshipHandle::DiscordRelationshipType field, and will persist across games. It is not
/// possible to block a user in only one game.
///
/// See the @ref friends documentation for more information.
///
/// Note: While the SDK allows you to manage a user's relationships, you should never take an action
/// without their explicit consent. You should not automatically send or accept friend requests.
/// Only invoke APIs to manage relationships in response to a user action such as clicking a "Send
/// Friend Request" button.
///
/// Handle objects in the SDK hold a reference both to the underlying data, and to the SDK instance.
/// Changes to the underlying data will generally be available on existing handles objects without
/// having to re-create them. If the SDK instance is destroyed, but you still have a reference to a
/// handle object, note that it will return the default value for all method calls (ie an empty
/// string for methods that return a string).
UCLASS(BlueprintType, Category = "Discord Partner SDK")
class DISCORDPARTNERSDK_API UDiscordRelationshipHandle : public UObject {
    GENERATED_BODY()
public:
    ~UDiscordRelationshipHandle();
#if !DISCORD_PARTNER_SDK_STUB
    Discord_RelationshipHandle instance;
    DiscordUObjectState state = DiscordUObjectState::Invalid;
#endif

    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void Drop();

    /// \brief Returns the type of the Discord relationship.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    EDiscordRelationshipType DiscordRelationshipType();

    /// \brief Returns the type of the Game relationship.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    EDiscordRelationshipType GameRelationshipType();

    /// \brief Returns the ID of the target user in this relationship.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    FDiscordUniqueID Id();

    /// \brief Returns whether this relationship is a spam request.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    bool IsSpamRequest();

    /// \brief Returns a handle to the target user in this relationship, if one is available.
    /// This would be the user with the same ID as the one returned by the Id() method.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    UDiscordUserHandle* User();
};

/// \brief A UserApplicationProfileHandle represents a profile from an external identity provider,
/// such as Steam or Epic Online Services.
///
/// Handle objects in the SDK hold a reference both to the underlying data, and to the SDK instance.
/// Changes to the underlying data will generally be available on existing handles objects without
/// having to re-create them. If the SDK instance is destroyed, but you still have a reference to a
/// handle object, note that it will return the default value for all method calls (ie an empty
/// string for methods that return a string).
UCLASS(BlueprintType, Category = "Discord Partner SDK")
class DISCORDPARTNERSDK_API UDiscordUserApplicationProfileHandle : public UObject {
    GENERATED_BODY()
public:
    ~UDiscordUserApplicationProfileHandle();
#if !DISCORD_PARTNER_SDK_STUB
    Discord_UserApplicationProfileHandle instance;
    DiscordUObjectState state = DiscordUObjectState::Invalid;
#endif

    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void Drop();

    /// \brief Returns the user's in-game avatar hash.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    FString AvatarHash();

    /// \brief Returns any metadata set by the developer.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    FString Metadata();

    /// \brief Returns the user's external identity provider ID if it exists.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    FString ProviderId();

    /// \brief Returns the user's external identity provider issued user ID.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    FString ProviderIssuedUserId();

    /// \brief Returns the type of the external identity provider.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    EDiscordExternalIdentityProviderType ProviderType();

    /// \brief Returns the user's in-game username.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    FString Username();
};

/// \brief A UserHandle represents a single user on Discord that the SDK knows about and contains
/// basic account information for them such as id, name, and avatar, as well as their "status"
/// information which includes both whether they are online/offline/etc as well as whether they are
/// playing this game.
///
/// Handle objects in the SDK hold a reference both to the underlying data, and to the SDK instance.
/// Changes to the underlying data will generally be available on existing handles objects without
/// having to re-create them. If the SDK instance is destroyed, but you still have a reference to a
/// handle object, note that it will return the default value for all method calls (ie an empty
/// string for methods that return a string).
UCLASS(BlueprintType, Category = "Discord Partner SDK")
class DISCORDPARTNERSDK_API UDiscordUserHandle : public UObject {
    GENERATED_BODY()
public:
    ~UDiscordUserHandle();
#if !DISCORD_PARTNER_SDK_STUB
    Discord_UserHandle instance;
    DiscordUObjectState state = DiscordUObjectState::Invalid;
#endif

    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void Drop();

    /// \brief Returns the hash of the user's Discord profile avatar, if one is set.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    FString Avatar();

    /// \brief Converts the AvatarType enum to a string.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    static FString AvatarTypeToString(EDiscordUserHandleAvatarType type);

    /// \brief Returns a CDN url to the user's Discord profile avatar.
    ///
    /// If the user does not have an avatar set, a url to one of Discord's default avatars is
    /// returned instead.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    FString AvatarUrl(EDiscordUserHandleAvatarType animatedType,
                      EDiscordUserHandleAvatarType staticType);

    /// \brief Returns the user's preferred name, if one is set, otherwise returns their unique
    /// username.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    FString DisplayName();

    /// \brief Returns the user's rich presence activity that is associated with the current game,
    /// if one is set.
    ///
    /// On Discord, users can have multiple rich presence activities at once, but the SDK will only
    /// expose the activity that is associated with your game. You can use this to know about the
    /// party the user is in, if any, and what the user is doing in the game.
    ///
    /// For more information see the Activity class and check out
    /// https://discord.com/developers/docs/rich-presence/overview
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    UDiscordActivity* GameActivity();

    /// \brief Returns the preferred display name of this user, if one is set.
    ///
    /// Discord's public API refers to this as a "global name" instead of "display name".
    ///
    /// Discord users can set their preferred name to almost any string.
    ///
    /// For more information about usernames on Discord, see:
    /// https://discord.com/developers/docs/resources/user
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    FString GlobalName();

    /// \brief Returns the ID of this user.
    ///
    /// If this returns 0 then the UserHandle is no longer valid.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    FDiscordUniqueID Id();

    /// \brief Returns true if this user is a provisional account.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    bool IsProvisional();

    /// \brief Returns a reference to the RelationshipHandle between the currently authenticated
    /// user and this user, if any.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    UDiscordRelationshipHandle* Relationship();

    /// \brief Returns the user's online/offline/idle status.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    EDiscordStatusType Status();

    /// \brief Returns a list of UserApplicationProfileHandles for this user. Currently, a user can
    /// only have a single profile per application, so this list will always contain at most one
    /// UserApplicationProfileHandle.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    TArray<UDiscordUserApplicationProfileHandle*> UserApplicationProfiles();

    /// \brief Returns the globally unique username of this user.
    ///
    /// For provisional accounts this is an auto-generated string.
    ///
    /// For more information about usernames on Discord, see:
    /// https://discord.com/developers/docs/resources/user
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    FString Username();
};

/// \brief A LobbyMemberHandle represents the state of a single user in a Lobby.
///
/// The SDK separates lobby membership into two concepts:
/// 1. Has the user been added to the lobby by the game developer?
/// If the LobbyMemberHandle exists for a user/lobby pair, then the user has been added to the
/// lobby.
/// 2. Does the user have an active game session that is connected to the lobby and will receive any
/// lobby messages? It is possible for a game developer to add a user to a lobby while they are
/// offline. Also users may temporarily disconnect and rejoin later. So the `Connected` boolean
/// tells you whether the user is actively connected to the lobby.
///
/// Handle objects in the SDK hold a reference both to the underlying data, and to the SDK instance.
/// Changes to the underlying data will generally be available on existing handles objects without
/// having to re-create them. If the SDK instance is destroyed, but you still have a reference to a
/// handle object, note that it will return the default value for all method calls (ie an empty
/// string for methods that return a string).
UCLASS(BlueprintType, Category = "Discord Partner SDK")
class DISCORDPARTNERSDK_API UDiscordLobbyMemberHandle : public UObject {
    GENERATED_BODY()
public:
    ~UDiscordLobbyMemberHandle();
#if !DISCORD_PARTNER_SDK_STUB
    Discord_LobbyMemberHandle instance;
    DiscordUObjectState state = DiscordUObjectState::Invalid;
#endif

    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void Drop();

    /// \brief Returns true if the user is allowed to link a channel to this lobby.
    ///
    /// Under the hood this checks if the LobbyMemberFlags::CanLinkLobby flag is set.
    /// This flag can only be set via the server API, add_lobby_member
    /// The use case for this is for games that want to restrict a lobby so that only the
    /// clan/guild/group leader is allowed to manage the linked channel for the lobby.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    bool CanLinkLobby();

    /// \brief Returns true if the user is currently connected to the lobby.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    bool Connected();

    /// \brief The user id of the lobby member.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    FDiscordUniqueID Id();

    /// \brief Metadata is a set of string key/value pairs that the game developer can use.
    ///
    /// A common use case may be to store the game's internal user ID for this user so that every
    /// member of a lobby knows the discord user ID and the game's internal user ID mapping for each
    /// user.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    TMap<FString, FString> Metadata();

    /// \brief The UserHandle of the lobby member.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    UDiscordUserHandle* User();
};

/// \brief A LobbyHandle represents a single lobby in the SDK. A lobby can be thought of as
/// just an arbitrary, developer-controlled group of users that can communicate with each other.
///
/// ## Managing Lobbies
/// Lobbies can be managed through a set of @ref server_apis that are documented elsewhere, which
/// allow you to create lobbies, add and remove users from lobbies, and delete them.
///
/// There is also an API to create lobbies without any server side component using the
/// Client::CreateOrJoinLobby function, which accepts a game-generated secret and will join the user
/// to the lobby associated with that secret, creating it if necessary.
///
/// NOTE: When using this API the secret will auto-expire in 30 days, at which point the existing
/// lobby can no longer be joined, but will still exist. We recommend using this for short term
/// lobbies and not permanent lobbies. Use the Server API for more permanent lobbies.
///
/// Members of a lobby are not automatically removed when they close the game or temporarily
/// disconnect. When the SDK connects, it will attempt to re-connect to any lobbies it is currently
/// a member of.
///
/// # Lobby Auto-Deletion
/// Lobbies are generally ephemeral and will be auto-deleted if they have been idle (meaning no
/// users are actively connected to them) for some amount of time. The default is to auto delete
/// after 5 minutes, but this can be customized when creating the lobby. As long as one user is
/// connected to the lobby though it will not be auto-deleted (meaning they have the SDK running and
/// status is set to Ready). Additionally, lobbies that are linked to a channel on Discord will not
/// be auto deleted.
///
/// You can also use the @ref server_apis to customize this timeout, it can be raised to as high as
/// 7 days, meaning the lobby only gets deleted if no one connects to it for an entire week. This
/// should give a good amount of permanence to lobbies when needed, but there may be rare cases
/// where a lobby does need to be "rebuilt" if everyone is offline for an extended period.
///
/// # Membership Limits
/// Lobbies may have a maximum of 1,000 members, and each user may be in a maximum of 200 lobbies
/// per game.
///
/// ## Audio
/// Lobbies support voice calls. Although a lobby is allowed to have 1,000 members, you should not
/// try to start voice calls in lobbies that large. We strongly recommend sticking to around 25
/// members or fewer for voice calls.
///
/// See Client::StartCall for more information on how to start a voice call in a lobby.
///
/// ## Channel Linking
/// Lobbies can be linked to a channel on Discord, which allows messages sent in one place to show
/// up in the other. Any lobby can be linked to a channel, but only lobby members with the
/// LobbyMemberFlags::CanLinkLobby flag are allowed to a link a lobby. This flag must be set using
/// the server APIs, which allows you to ensure that only clan/guild/group leaders can link lobbies
/// to Discord channels.
///
/// To setup a link you'll need to use methods in the Client class to fetch the servers (aka guilds)
/// and channels a user is a member of and setup the link. The Client::GetUserGuilds and
/// Client::GetGuildChannels methods are used to fetch the servers and channels respectively. You
/// can use these to show a UI for the user to pick which server and channel they want to link to.
///
/// Not all channels are linkable. To be linked:
/// - The channel must be a guild text channel
/// - The channel may not be marked as NSFW
/// - The channel must not be currently linked to a different lobby
/// - The user must have the following permissions in the channel in order to link it:
///   - Manage Channels
///   - View Channel
///   - Send Messages
///
/// ### Linking Private Channels
/// Discord is allowing all channels the user has access to in a server to be linked in game, even
/// if that channel is private to other members of the server. This means that a user could choose
/// to link a private "admins chat" channel (assuming they are an admin) in game if they wanted.
///
/// It's not really possible for the game to know which users should have access to that channel or
/// not though. So in this implementation, every member of a lobby will be able to view all messages
/// sent in the linked channel and reply to them. If you are going to allow private channels to be
/// linked in game, you must make sure that users are aware that their private channel will be
/// viewable by everyone in the lobby!
///
/// To help you identify which channels are public or private, we have added a
/// isViewableAndWriteableByAllMembers boolean which is described more in GuildChannel. You can use
/// that to just not allow private channels to be linked, or to know when to show a clear warning,
/// it's up to you!
///
/// ## Misc
/// Handle objects in the SDK hold a reference both to the underlying data, and to the SDK instance.
/// Changes to the underlying data will generally be available on existing handles objects without
/// having to re-create them. If the SDK instance is destroyed, but you still have a reference to a
/// handle object, note that it will return the default value for all method calls (ie an empty
/// string for methods that return a string).
UCLASS(BlueprintType, Category = "Discord Partner SDK")
class DISCORDPARTNERSDK_API UDiscordLobbyHandle : public UObject {
    GENERATED_BODY()
public:
    ~UDiscordLobbyHandle();
#if !DISCORD_PARTNER_SDK_STUB
    Discord_LobbyHandle instance;
    DiscordUObjectState state = DiscordUObjectState::Invalid;
#endif

    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void Drop();

    /// \brief Returns a reference to the CallInfoHandle if there is an active voice call in this
    /// lobby.
    ///
    /// This can allow you to display which lobby members are in voice, even if the current user has
    /// not yet joined the voice call.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    UDiscordCallInfoHandle* GetCallInfoHandle();

    /// \brief Returns a reference to the LobbyMemberHandle for the given user ID, if they are a
    /// member of this lobby.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    UDiscordLobbyMemberHandle* GetLobbyMemberHandle(FDiscordUniqueID memberId);

    /// \brief Returns the id of the lobby.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    FDiscordUniqueID Id();

    /// \brief Returns information about the channel linked to this lobby, if any.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    UDiscordLinkedChannel* LinkedChannel();

    /// \brief Returns a list of the user IDs that are members of this lobby.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    TArray<FDiscordUniqueID> LobbyMemberIds();

    /// \brief Returns a list of the LobbyMemberHandle objects for each member of this lobby.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    TArray<UDiscordLobbyMemberHandle*> LobbyMembers();

    /// \brief Returns any developer supplied metadata for this lobby.
    ///
    /// Metadata is simple string key/value pairs and is a way to associate internal game
    /// information with the lobby so each lobby member can have easy access to.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    TMap<FString, FString> Metadata();
};

/// \brief Contains information about non-text content in a message that likely cannot be rendered
/// in game such as images, videos, embeds, polls, and more.
UCLASS(BlueprintType, Category = "Discord Partner SDK")
class DISCORDPARTNERSDK_API UDiscordAdditionalContent : public UObject {
    GENERATED_BODY()
public:
    ~UDiscordAdditionalContent();
#if !DISCORD_PARTNER_SDK_STUB
    Discord_AdditionalContent instance;
    DiscordUObjectState state = DiscordUObjectState::Invalid;
#endif

    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void Init();
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void Drop();

    /// \brief Compares each field of the AdditionalContent struct for equality.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    bool Equals(UDiscordAdditionalContent* rhs);

    /// \brief Converts the AdditionalContentType enum to a string.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    static FString TypeToString(EDiscordAdditionalContentType type);

    /// \brief Represents the type of additional content in the message.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get Type"))
    EDiscordAdditionalContentType Type();

    /// \brief Represents the type of additional content in the message.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetType(EDiscordAdditionalContentType Type);

    /// \brief When the additional content is a poll or thread, this field will contain the name of
    /// the poll or thread.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get Title"))
    FString Title();

    /// \brief When the additional content is a poll or thread, this field will contain the name of
    /// the poll or thread.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetTitle(FString Title);

    /// \brief Represents the number of pieces of additional content so you could for example
    /// renders "2 additional images".
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get Count"))
    uint8 Count();

    /// \brief Represents the number of pieces of additional content so you could for example
    /// renders "2 additional images".
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetCount(uint8 Count);
};

/// \brief A MessageHandle represents a single message received by the SDK.
///
/// # Chat types
/// The SDK supports two types of chat:
/// 1. 1 on 1 chat between two users
/// 2. Chat within a lobby
///
/// You can determine the context a message was sent in with the MessageHandle::Channel and
/// ChannelHandle::Type methods. The SDK should only be receiving messages in the following channel
/// types:
/// - DM
/// - Ephemeral DM
/// - Lobby
///
/// # Syncing with Discord
/// In some situations messages sent from the SDK will also show up in Discord.
/// In general this will happen for:
/// - 1 on 1 chat when at least one of the users is a full Discord user
/// - Lobby chat when the lobby is linked to a Discord channel
///
/// Additionally the message must have been sent by a user who is not banned on the Discord side.
///
/// # Legal disclosures
/// As a convenience for game developers, the first time a user sends a message in game, and that
/// message will show up on the Discord client, the SDK will inject a "fake" message into the chat,
/// that contains a basic English explanation of what is happening to the user. You can identify
/// these messages with the MessageHandle::DisclosureType method. We encourage you to customize the
/// rendering of these messages, possibly changing the wording, translating them, and making them
/// look more "official". You can choose to avoid rendering these as well.
///
/// # History
/// The SDK keeps the 25 most recent messages in each channel in memory, but it does not have access
/// to any historical messages sent before the SDK was connected. A MessageHandle will keep working
/// though even after the SDK has discarded the message for being too old, you just won't be able to
/// create a new MessageHandle objects for that message.
///
/// # Unrenderable Content
/// Messages sent on Discord can contain content that may not be renderable in game, such as images,
/// videos, embeds, polls, and more. The game isn't expected to render these, but instead show a
/// small notice so the user is aware there is more content and a way to view that content on
/// Discord. The MessageHandle::AdditionalContent method will contain data about the non-text
/// content in this message.
///
/// There is also more information about the struct of messages on Discord here:
/// https://discord.com/developers/docs/resources/message
///
/// Note: While the SDK allows you to send messages on behalf of a user, you must only do so in
/// response to a user action. You should never automatically send messages.
///
/// Handle objects in the SDK hold a reference both to the underlying data, and to the SDK instance.
/// Changes to the underlying data will generally be available on existing handles objects without
/// having to re-create them. If the SDK instance is destroyed, but you still have a reference to a
/// handle object, note that it will return the default value for all method calls (ie an empty
/// string for methods that return a string).
UCLASS(BlueprintType, Category = "Discord Partner SDK")
class DISCORDPARTNERSDK_API UDiscordMessageHandle : public UObject {
    GENERATED_BODY()
public:
    ~UDiscordMessageHandle();
#if !DISCORD_PARTNER_SDK_STUB
    Discord_MessageHandle instance;
    DiscordUObjectState state = DiscordUObjectState::Invalid;
#endif

    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void Drop();

    /// \brief If the message contains non-text content, such as images, videos, embeds, polls, etc,
    /// this method will return information about that content.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    UDiscordAdditionalContent* AdditionalContent();

    /// \brief Returns the application ID associated with this message, if any. You can use
    /// this to identify if the mesage was sent from another child application in
    /// your catalog.
    ///
    /// Note: Parent / child applications are in limited access and the SentFromGame
    /// field should be relied on for the common case.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    FDiscordUniqueID ApplicationId();

    /// \brief Returns the UserHandle for the author of this message.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    UDiscordUserHandle* Author();

    /// \brief Returns the user ID of the user who sent this message.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    FDiscordUniqueID AuthorId();

    /// \brief Returns the ChannelHandle for the channel this message was sent in.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    UDiscordChannelHandle* Channel();

    /// \brief Returns the channel ID this message was sent in.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    FDiscordUniqueID ChannelId();

    /// \brief Returns the content of this message, if any.
    ///
    /// A message can be blank if it was sent from Discord but only contains content such as image
    /// attachments. Certain types of markup, such as markup for emojis and mentions, will be auto
    /// replaced with a more human readable form, such as `@username` or `:emoji_name:`.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    FString Content();

    /// \brief If this is an auto-generated message that is explaining some integration behavior to
    /// users, this method will return the type of disclosure so you can customize it.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    EDiscordDisclosureTypes DisclosureType();

    /// \brief The timestamp in millis since the epoch when the message was most recently edited.
    ///
    /// Returns 0 if the message has not been edited yet.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    FDiscordUniqueID EditedTimestamp();

    /// \brief Returns the ID of this message.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    FDiscordUniqueID Id();

    /// \brief Returns the LobbyHandle this message was sent in, if it was sent in a lobby.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    UDiscordLobbyHandle* Lobby();

    /// \brief Returns any metadata the developer included with this message.
    ///
    /// Metadata is just a set of simple string key/value pairs.
    /// An example use case might be to include a character name so you can customize how a message
    /// renders in game.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    TMap<FString, FString> Metadata();

    /// \brief Returns any moderation metadata the developer set on this message.
    ///
    /// Moderation metadata is just a set of simple string key/value pairs.
    /// An example use case might be to include a flag that indicates the moderation status of the
    /// message. Another example would be to include a re-written message that is more appropriate
    /// for the game's audience.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    TMap<FString, FString> ModerationMetadata();

    /// \brief Returns the content of this message, if any, but without replacing any markup from
    /// emojis and mentions.
    ///
    /// A message can be blank if it was sent from Discord but only contains content such as image
    /// attachments.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    FString RawContent();

    /// \brief Returns the UserHandle for the other participant in a DM, if this message was sent in
    /// a DM.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    UDiscordUserHandle* Recipient();

    /// \brief When this message was sent in a DM or Ephemeral DM, this method will return the ID of
    /// the other user in that DM.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    FDiscordUniqueID RecipientId();

    /// \brief Returns true if this message was sent in-game, otherwise false (i.e. from Discord
    /// itself). If you are using parent / child applications, this will be true if the message was
    /// sent from any child application.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    bool SentFromGame();

    /// \brief The timestamp in millis since the epoch when the message was sent.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    FDiscordUniqueID SentTimestamp();
};

/// \brief Represents a single input or output audio device available to the user.
///
/// Discord will initialize the audio engine with the system default input and output devices.
/// You can change the device through the Client by passing the id of the desired audio device.
UCLASS(BlueprintType, Category = "Discord Partner SDK")
class DISCORDPARTNERSDK_API UDiscordAudioDevice : public UObject {
    GENERATED_BODY()
public:
    ~UDiscordAudioDevice();
#if !DISCORD_PARTNER_SDK_STUB
    Discord_AudioDevice instance;
    DiscordUObjectState state = DiscordUObjectState::Invalid;
#endif

    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void Drop();

    /// \brief Compares the ID of two AudioDevice objects for equality.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    bool Equals(UDiscordAudioDevice* rhs);

    /// \brief The ID of the audio device.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get Id"))
    FString Id();

    /// \brief The ID of the audio device.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetId(FString Id);

    /// \brief The display name of the audio device.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get Name"))
    FString Name();

    /// \brief The display name of the audio device.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetName(FString Name);

    /// \brief Whether the audio device is the system default device.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get IsDefault"))
    bool IsDefault();

    /// \brief Whether the audio device is the system default device.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetIsDefault(bool IsDefault);
};

/// \brief Represents a summary of a DM conversation with a user.
UCLASS(BlueprintType, Category = "Discord Partner SDK")
class DISCORDPARTNERSDK_API UDiscordUserMessageSummary : public UObject {
    GENERATED_BODY()
public:
    ~UDiscordUserMessageSummary();
#if !DISCORD_PARTNER_SDK_STUB
    Discord_UserMessageSummary instance;
    DiscordUObjectState state = DiscordUObjectState::Invalid;
#endif

    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void Drop();

    /// \brief Returns the ID of the last message sent in the DM conversation.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    FDiscordUniqueID LastMessageId();

    /// \brief Returns the ID of the other user in the DM conversation.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    FDiscordUniqueID UserId();
};

/// \brief Options for creating a new Client instance.
///
/// This class may be used to set advanced initialization-time options on Client.
UCLASS(BlueprintType, Category = "Discord Partner SDK")
class DISCORDPARTNERSDK_API UDiscordClientCreateOptions : public UObject {
    GENERATED_BODY()
public:
    ~UDiscordClientCreateOptions();
#if !DISCORD_PARTNER_SDK_STUB
    Discord_ClientCreateOptions instance;
    DiscordUObjectState state = DiscordUObjectState::Invalid;
#endif

    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void Init();
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void Drop();

    /// \brief The base URL for the Discord web application.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get WebBase"))
    FString WebBase();

    /// \brief The base URL for the Discord web application.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetWebBase(FString WebBase);

    /// \brief The base URL for the Discord API.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get ApiBase"))
    FString ApiBase();

    /// \brief The base URL for the Discord API.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetApiBase(FString ApiBase);

    /// \brief The audio system to use. Defaults to AudioSystem::Standard.
    ///
    /// This is an experimental API which may be removed or changed in a future release.
    ///
    /// The game audio system alters the behavior of Discord Voice on mobile platforms
    /// to use standard media-type streams instead of voice-specific audio APIs when
    /// possible. Currently this will be used on iOS 18.2+ on devices which return true
    /// from `-[AVAudioSession isEchoCancelledInputAvailable]` and on Android devices.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get ExperimentalAudioSystem"))
    EDiscordAudioSystem ExperimentalAudioSystem();

    /// \brief The audio system to use. Defaults to AudioSystem::Standard.
    ///
    /// This is an experimental API which may be removed or changed in a future release.
    ///
    /// The game audio system alters the behavior of Discord Voice on mobile platforms
    /// to use standard media-type streams instead of voice-specific audio APIs when
    /// possible. Currently this will be used on iOS 18.2+ on devices which return true
    /// from `-[AVAudioSession isEchoCancelledInputAvailable]` and on Android devices.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetExperimentalAudioSystem(EDiscordAudioSystem ExperimentalAudioSystem);

    /// \brief Whether to prevent communications mode on Android when Bluetooth is connected.
    ///
    /// This is an experimental API which may be removed or changed in a future release.
    ///
    /// When set to true, the SDK will not enter communications mode when Bluetooth is connected.
    /// This setting is only meaningful on Android. It allows you to retain full quality stereo
    /// audio playback when in-call and avoids mixing issues caused by Bluetooth Absolute Volume,
    /// but will use the device microphone instead of the headset one.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get ExperimentalAndroidPreventCommsForBluetooth"))
    bool ExperimentalAndroidPreventCommsForBluetooth();

    /// \brief Whether to prevent communications mode on Android when Bluetooth is connected.
    ///
    /// This is an experimental API which may be removed or changed in a future release.
    ///
    /// When set to true, the SDK will not enter communications mode when Bluetooth is connected.
    /// This setting is only meaningful on Android. It allows you to retain full quality stereo
    /// audio playback when in-call and avoids mixing issues caused by Bluetooth Absolute Volume,
    /// but will use the device microphone instead of the headset one.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetExperimentalAndroidPreventCommsForBluetooth(
      bool ExperimentalAndroidPreventCommsForBluetooth);

    /// \brief CPU affinity mask hint for certain platforms. Depending on platform support, may or
    /// may not be ignored.
    UFUNCTION(BlueprintCallable,
              BlueprintPure,
              Category = "Discord Partner SDK",
              meta = (DisplayName = "Get CpuAffinityMask"))
    FDiscordUniqueID CpuAffinityMask();

    /// \brief CPU affinity mask hint for certain platforms. Depending on platform support, may or
    /// may not be ignored.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetCpuAffinityMask(FDiscordUniqueID CpuAffinityMask);
};

/// \brief The Client class is the main entry point for the Discord SDK. All functionality is
/// exposed through this class.
///
/// See @ref getting_started "Getting Started" for more information on how to use the Client class.
UCLASS(BlueprintType, Category = "Discord Partner SDK")
class DISCORDPARTNERSDK_API UDiscordClient : public UObject {
    GENERATED_BODY()
public:
    ~UDiscordClient();
#if !DISCORD_PARTNER_SDK_STUB
    Discord_Client instance;
    DiscordUObjectState state = DiscordUObjectState::Invalid;
#endif

    /// \brief Creates a new instance of the Client.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void Init();

    /// \brief Creates a new instance of the Client but allows customizing the Discord URL to use.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void InitWithBases(FString const& apiBase, FString const& webBase);

    /// \brief Creates a new instance of the Client with custom options.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void InitWithOptions(UDiscordClientCreateOptions* options);
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void Drop();
#if DISCORD_DEBUG_API_ENABLED
    void AddOrUpdateLobbyMember(FString const& token,
                                FDiscordUniqueID userId,
                                FDiscordUniqueID lobbyId,
                                TMap<FString, FString> const& metadata,
                                EDiscordLobbyMemberFlags flags,
                                FDiscordClientUpdateLobbyMemberCallback const& callback);
    void AddOrUpdateLobbyMember(FString const& token,
                                FDiscordUniqueID userId,
                                FDiscordUniqueID lobbyId,
                                TMap<FString, FString> const& metadata,
                                EDiscordLobbyMemberFlags flags,
                                FDiscordClientUpdateLobbyMemberCallbackDynamic const& callback);
#endif
#if DISCORD_DEBUG_API_ENABLED
    void CreateNewLobby(FString const& token, FDiscordClientLobbyActionCallback const& callback);
    void CreateNewLobby(FString const& token,
                        FDiscordClientLobbyActionCallbackDynamic const& callback);
#endif
#if DISCORD_DEBUG_API_ENABLED
    void DeleteLobby(FString const& token,
                     FDiscordUniqueID lobbyId,
                     FDiscordClientLobbyActionCallback const& callback);
    void DeleteLobby(FString const& token,
                     FDiscordUniqueID lobbyId,
                     FDiscordClientLobbyActionCallbackDynamic const& callback);
#endif
#if DISCORD_DEBUG_API_ENABLED
    void EditLobby(FString const& token,
                   FDiscordUniqueID lobbyId,
                   TMap<FString, FString> const& lobbyMetadata,
                   FDiscordClientLobbyActionCallback const& callback);
    void EditLobby(FString const& token,
                   FDiscordUniqueID lobbyId,
                   TMap<FString, FString> const& lobbyMetadata,
                   FDiscordClientLobbyActionCallbackDynamic const& callback);
#endif

    /// \brief Converts the Error enum to a string.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    static FString ErrorToString(EDiscordClientError type);
#if DISCORD_DEBUG_API_ENABLED
    void ForceCrash_ForTest();
#endif

    /// \brief This function is used to get the application ID for the client. This is used to
    /// identify the application to the Discord client. This is used for things like
    /// authentication, rich presence, and activity invites when *not* connected with
    /// Client::Connect. When calling Client::Connect, the application ID is set automatically
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    FDiscordUniqueID GetApplicationId();

    /// \brief (deprecated)
    ///
    /// \deprecated Please use GetCurrentUserV2 instead. This will be removed in a future version.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    UDiscordUserHandle* GetCurrentUser();

    /// \brief Returns the ID of the system default audio device if the user has not explicitly
    /// chosen one.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    static FString GetDefaultAudioDeviceId();

    /// \brief Returns the default set of OAuth2 scopes that should be used with the Discord SDK
    /// when making use of the full SDK capabilities, including communications-related features
    /// (e.g. user DMs, lobbies, voice chat). If your application does not make use of these
    /// features, you should use Client::GetDefaultPresenceScopes instead.
    ///
    /// Communications-related features are currently in limited access and are not available to
    /// all applications, however, they can be demoed in limited capacity by all applications. If
    /// you are interested in using these features in your game, please reach out to the Discord
    /// team.
    ///
    /// It's ok to further customize your requested oauth2 scopes to add additional scopes if you
    /// have legitimate usages for them. However, we strongly recommend always using
    /// Client::GetDefaultCommunicationScopes or Client::GetDefaultPresenceScopes as a baseline to
    /// enable a better authorization experience for users!
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    static FString GetDefaultCommunicationScopes();

    /// \brief Returns the default set of OAuth2 scopes that should be used with the Discord SDK
    /// when leveraging baseline presence-related features (e.g. friends list, rich presence,
    /// provisional accounts, activity invites). If your application is using
    /// communications-related features, which are currently available in limited access, you should
    /// use Client::GetDefaultCommunicationScopes instead.
    ///
    /// It's ok to further customize your requested oauth2 scopes to add additional scopes if you
    /// have legitimate usages for them. However, we strongly recommend always using
    /// Client::GetDefaultCommunicationScopes or Client::GetDefaultPresenceScopes as a baseline to
    /// enable a better authorization experience for users!
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    static FString GetDefaultPresenceScopes();

    /// \brief Returns the git commit hash this version was built from.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    static FString GetVersionHash();

    /// \brief Returns the major version of the Discord Social SDK.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    static int32 GetVersionMajor();

    /// \brief Returns the minor version of the Discord Social SDK.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    static int32 GetVersionMinor();

    /// \brief Returns the patch version of the Discord Social SDK.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    static int32 GetVersionPatch();
#if DISCORD_DEBUG_API_ENABLED
    void PerformOnThreadWithString_ForTest(
      FString const& text,
      FDiscordClientPerformOnThreadWithStringCallback const& callback);
    void PerformOnThreadWithString_ForTest(
      FString const& text,
      FDiscordClientPerformOnThreadWithStringCallbackDynamic const& callback);
#endif
#if DISCORD_DEBUG_API_ENABLED
    void RemoveLobbyMember(FString const& token,
                           FDiscordUniqueID userId,
                           FDiscordUniqueID lobbyId,
                           FDiscordClientUpdateLobbyMemberCallback const& callback);
    void RemoveLobbyMember(FString const& token,
                           FDiscordUniqueID userId,
                           FDiscordUniqueID lobbyId,
                           FDiscordClientUpdateLobbyMemberCallbackDynamic const& callback);
#endif

    /// \brief This function is used to override the default HTTP timeout for the websocket client.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetHttpRequestTimeout(int32 httpTimeoutInMilliseconds);

    /// \brief Converts the Status enum to a string.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    static FString StatusToString(EDiscordClientStatus type);

    /// \brief Converts the Thread enum to a string.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    static FString ThreadToString(EDiscordClientThread type);
#if DISCORD_DEBUG_API_ENABLED
    void UpdateUserApplicationProfile(FString const& token,
                                      FDiscordUniqueID applicationId,
                                      FDiscordUniqueID userId,
                                      FString const& providerIssuedUserId,
                                      FString const& username,
                                      TMap<FString, FString> const& metadata,
                                      FDiscordClientUpdateUserApplicationProfileCallback const& cb);
    void UpdateUserApplicationProfile(
      FString const& token,
      FDiscordUniqueID applicationId,
      FDiscordUniqueID userId,
      FString const& providerIssuedUserId,
      FString const& username,
      TMap<FString, FString> const& metadata,
      FDiscordClientUpdateUserApplicationProfileCallbackDynamic const& cb);
#endif

    /// \brief Ends any active call, if any. Any references you have to Call objects are invalid
    /// after they are ended, and can be immediately freed.
    void EndCall(FDiscordUniqueID channelId, FDiscordClientEndCallCallback const& callback);

    /// \brief Ends any active call, if any. Any references you have to Call objects are invalid
    /// after they are ended, and can be immediately freed.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "callback"))
    void EndCall(FDiscordUniqueID channelId, FDiscordClientEndCallCallbackDynamic const& callback);

    /// \brief Ends any active call, if any. Any references you have to Call objects are invalid
    /// after they are ended, and can be immediately freed.
    void EndCalls(FDiscordClientEndCallsCallback const& callback);

    /// \brief Ends any active call, if any. Any references you have to Call objects are invalid
    /// after they are ended, and can be immediately freed.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "callback"))
    void EndCalls(FDiscordClientEndCallsCallbackDynamic const& callback);

    /// \brief Returns a reference to the currently active call, if any.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    UDiscordCall* GetCall(FDiscordUniqueID channelId);

    /// \brief Returns a reference to all currently active calls, if any.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    TArray<UDiscordCall*> GetCalls();

    /// \brief Asynchronously fetches the current audio input device in use by the client.
    void GetCurrentInputDevice(FDiscordClientGetCurrentInputDeviceCallback const& cb);

    /// \brief Asynchronously fetches the current audio input device in use by the client.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void GetCurrentInputDevice(FDiscordClientGetCurrentInputDeviceCallbackDynamic const& cb);

    /// \brief Asynchronously fetches the current audio output device in use by the client.
    void GetCurrentOutputDevice(FDiscordClientGetCurrentOutputDeviceCallback const& cb);

    /// \brief Asynchronously fetches the current audio output device in use by the client.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void GetCurrentOutputDevice(FDiscordClientGetCurrentOutputDeviceCallbackDynamic const& cb);

    /// \brief Asynchronously fetches the list of audio input devices available to the user.
    void GetInputDevices(FDiscordClientGetInputDevicesCallback const& cb);

    /// \brief Asynchronously fetches the list of audio input devices available to the user.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void GetInputDevices(FDiscordClientGetInputDevicesCallbackDynamic const& cb);

    /// \brief Returns the input volume for the current user's microphone.
    ///
    /// Input volume is specified as a percentage in the range [0, 100] which represents the
    /// perceptual loudness.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    float GetInputVolume();

    /// \brief Asynchronously fetches the list of audio output devices available to the user.
    void GetOutputDevices(FDiscordClientGetOutputDevicesCallback const& cb);

    /// \brief Asynchronously fetches the list of audio output devices available to the user.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void GetOutputDevices(FDiscordClientGetOutputDevicesCallbackDynamic const& cb);

    /// \brief Returns the output volume for the current user.
    ///
    /// Output volume specified as a percentage in the range [0, 200] which represents the
    /// perceptual loudness.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    float GetOutputVolume();

    /// \brief Returns whether the current user is deafened in all calls.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    bool GetSelfDeafAll();

    /// \brief Returns whether the current user's microphone is muted in all calls.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    bool GetSelfMuteAll();

    /// \brief Enables or disables AEC diagnostic recording.
    ///
    /// Used to diagnose issues with acoustic echo cancellation. The input and output waveform data
    /// will be written to the log directory.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetAecDump(bool on);

    /// \brief When enabled, automatically adjusts the microphone volume to keep it clear and
    /// consistent.
    ///
    /// Defaults to on.
    ///
    /// Generally this shouldn't need to be used unless you are building a voice settings UI for the
    /// user to control, similar to Discord's voice settings.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetAutomaticGainControl(bool on);

    /// \brief Sets a callback function to be invoked when Discord detects a change in the available
    /// audio devices.
    void SetDeviceChangeCallback(FDiscordClientDeviceChangeCallback const& callback);

    /// \brief Sets a callback function to be invoked when Discord detects a change in the available
    /// audio devices.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "callback"))
    void SetDeviceChangeCallback(FDiscordClientDeviceChangeCallbackDynamic const& callback);

    /// \brief Enables or disables the basic echo cancellation provided by the WebRTC library.
    ///
    /// Defaults to on.
    ///
    /// Generally this shouldn't need to be used unless you are building a voice settings UI for the
    /// user to control, similar to Discord's voice settings.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetEchoCancellation(bool on);

    /// \brief On mobile devices, set whether the audio environment is managed by the engine or the
    /// SDK. On Android, this entails AudioManager state and on iOS, this entails AVAudioSession
    /// activation.
    ///
    /// This method must be called before connecting to any Calls if the
    /// application manages audio on its own, otherwise audio management
    /// will be ended by the voice engine when the last Call is ended.
    ///
    /// The Unity plugin automatically calls this method if the native Unity
    /// audio engine is enabled in the project settings.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetEngineManagedAudioSession(bool isEngineManaged);

    /// \brief Asynchronously changes the audio input device in use by the client to the specified
    /// device. You can find the list of device IDs that can be passed in with the
    /// Client::GetInputDevices function.
    void SetInputDevice(FString const& deviceId, FDiscordClientSetInputDeviceCallback const& cb);

    /// \brief Asynchronously changes the audio input device in use by the client to the specified
    /// device. You can find the list of device IDs that can be passed in with the
    /// Client::GetInputDevices function.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void SetInputDevice(FString const& deviceId,
                        FDiscordClientSetInputDeviceCallbackDynamic const& cb);

    /// \brief Sets the microphone volume for the current user.
    ///
    /// Input volume is specified as a percentage in the range [0, 100] which represents the
    /// perceptual loudness.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetInputVolume(float inputVolume);

    /// \brief Callback function invoked when the above threshold is set and there is a change in
    /// whether audio is being detected.
    void SetNoAudioInputCallback(FDiscordClientNoAudioInputCallback const& callback);

    /// \brief Callback function invoked when the above threshold is set and there is a change in
    /// whether audio is being detected.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "callback"))
    void SetNoAudioInputCallback(FDiscordClientNoAudioInputCallbackDynamic const& callback);

    /// \brief Threshold that can be set to indicate when no audio is being received by the user's
    /// mic.
    ///
    /// An example of when this may be useful: When push to talk is being used and the user pushes
    /// their talk key, but something is configured wrong and no audio is being received, this
    /// threshold and callback can be used to detect that situation and notify the user. The
    /// threshold is specified in DBFS, or decibels relative to full scale, and the range is
    /// [-100.0, 100.0] It defaults to -100.0, so is disabled.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetNoAudioInputThreshold(float dBFSThreshold);

    /// \brief Enables basic background noise suppression.
    ///
    /// Defaults to on.
    ///
    /// Generally this shouldn't need to be used unless you are building a voice settings UI for the
    /// user to control, similar to Discord's voice settings.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetNoiseSuppression(bool on);

    /// \brief Enables or disables hardware encoding and decoding for audio, if it is available.
    ///
    /// Defaults to on.
    ///
    /// This must be called immediately after constructing the Client. If called too late an error
    /// will be logged and the setting will not take effect.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetOpusHardwareCoding(bool encode, bool decode);

    /// \brief Asynchronously changes the audio output device in use by the client to the specified
    /// device. You can find the list of device IDs that can be passed in with the
    /// Client::GetOutputDevices function.
    void SetOutputDevice(FString const& deviceId, FDiscordClientSetOutputDeviceCallback const& cb);

    /// \brief Asynchronously changes the audio output device in use by the client to the specified
    /// device. You can find the list of device IDs that can be passed in with the
    /// Client::GetOutputDevices function.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void SetOutputDevice(FString const& deviceId,
                         FDiscordClientSetOutputDeviceCallbackDynamic const& cb);

    /// \brief Sets the speaker volume for the current user.
    ///
    /// Output volume specified as a percentage in the range [0, 200] which represents the
    /// perceptual loudness.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetOutputVolume(float outputVolume);

    /// \brief Mutes all audio from the currently active call for the current user in all calls.
    /// They will not be able to hear any other participants,
    /// and no other participants will be able to hear the current user either.
    /// Note: This overrides the per-call setting.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetSelfDeafAll(bool deaf);

    /// \brief Mutes the current user's microphone so that no other participant in their active
    /// calls can hear them in all calls. Note: This overrides the per-call setting.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetSelfMuteAll(bool mute);

    /// \brief (deprecated)  On mobile devices, enable speakerphone mode.
    ///
    /// \deprecated Calling Client::SetSpeakerMode is DEPRECATED.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    bool SetSpeakerMode(bool speakerMode);

    /// \brief Allows setting the priority of various SDK threads.
    ///
    /// The threads that can be controlled are:
    /// - Client: This is the main thread for the SDK where most of the data processing happens
    /// - Network: This is the thread that receives voice data from lobby calls
    /// - Voice: This is the thread that the voice engine runs on and processes all audio data
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetThreadPriority(EDiscordClientThread thread, int32 priority);

    /// \brief Callback invoked whenever a user in a lobby joins or leaves a voice call.
    ///
    /// The main use case for this is to enable displaying which users are in voice in a lobby
    /// even if the current user is not in voice yet, and thus does not have a Call object to bind
    /// to.
    void SetVoiceParticipantChangedCallback(
      FDiscordClientVoiceParticipantChangedCallback const& cb);

    /// \brief Callback invoked whenever a user in a lobby joins or leaves a voice call.
    ///
    /// The main use case for this is to enable displaying which users are in voice in a lobby
    /// even if the current user is not in voice yet, and thus does not have a Call object to bind
    /// to.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void SetVoiceParticipantChangedCallback(
      FDiscordClientVoiceParticipantChangedCallbackDynamic const& cb);

    /// \brief On iOS devices, show the system audio route picker.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    bool ShowAudioRoutePicker();

    /// \brief Starts or joins a call in the lobby specified by channelId (For a lobby, simply
    /// pass in the lobbyId).
    ///
    /// On iOS, your application is responsible for enabling the appropriate background audio mode
    /// in your Info.plist. VoiceBuildPostProcessor in the sample demonstrates how to do this
    /// automatically in your Unity build process.
    ///
    /// On macOS, you should set the NSMicrophoneUsageDescription key in your Info.plist.
    ///
    /// Returns null if the user is already in the given voice channel.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    UDiscordCall* StartCall(FDiscordUniqueID channelId);

    /// \brief Starts or joins a call in the specified lobby.
    ///
    /// The audio received callback is invoked whenever incoming audio is received in a call. If
    /// the developer sets outShouldMute to true during the callback, the audio data will be muted
    /// after the callback is invoked, which is useful if the developer is utilizing the incoming
    /// audio and playing it through their own audio engine or playback. The audio samples
    /// in `data` can be modified in-place for simple DSP effects.
    ///
    /// The audio captured callback is invoked whenever local audio is captured before it is
    /// processed and transmitted which may be useful for voice moderation, etc.
    ///
    /// On iOS, your application is responsible for enabling the appropriate background audio mode
    /// in your Info.plist. VoiceBuildPostProcessor in the sample demonstrates how to do this
    /// automatically in your Unity build process.
    ///
    /// On macOS, you should set the NSMicrophoneUsageDescription key in your Info.plist.
    ///
    /// Returns null if the user is already in the given voice channel.
    // This callback may be executed on a background thread. You are responsible for ensuring that
    // your UObject's lifetime is long enough and for not accessing game thread data from a
    // background thread.
    UDiscordCall* StartCallWithAudioCallbacks(
      FDiscordUniqueID lobbyId,
      FDiscordClientUserAudioReceivedCallback const& receivedCb,
      FDiscordClientUserAudioCapturedCallback const& capturedCb);

    /// \brief Starts or joins a call in the specified lobby.
    ///
    /// The audio received callback is invoked whenever incoming audio is received in a call. If
    /// the developer sets outShouldMute to true during the callback, the audio data will be muted
    /// after the callback is invoked, which is useful if the developer is utilizing the incoming
    /// audio and playing it through their own audio engine or playback. The audio samples
    /// in `data` can be modified in-place for simple DSP effects.
    ///
    /// The audio captured callback is invoked whenever local audio is captured before it is
    /// processed and transmitted which may be useful for voice moderation, etc.
    ///
    /// On iOS, your application is responsible for enabling the appropriate background audio mode
    /// in your Info.plist. VoiceBuildPostProcessor in the sample demonstrates how to do this
    /// automatically in your Unity build process.
    ///
    /// On macOS, you should set the NSMicrophoneUsageDescription key in your Info.plist.
    ///
    /// Returns null if the user is already in the given voice channel.
    // This callback may be executed on a background thread. You are responsible for ensuring that
    // your UObject's lifetime is long enough and for not accessing game thread data from a
    // background thread.
    UFUNCTION(Category = "Discord Partner SDK", meta = (AutoCreateRefTerm = "receivedCb"))
    UDiscordCall* StartCallWithAudioCallbacks(
      FDiscordUniqueID lobbyId,
      FDiscordClientUserAudioReceivedCallbackDynamic const& receivedCb,
      FDiscordClientUserAudioCapturedCallbackDynamic const& capturedCb);

    /// \brief This will abort the authorize flow if it is in progress and tear down any associated
    /// state.
    ///
    /// NOTE: this *will not* close authorization windows presented to the user.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void AbortAuthorize();

    /// \brief This function is used to abort/cleanup the device authorization flow.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void AbortGetTokenFromDevice();

    /// \brief Initiates an OAuth2 flow for a user to "sign in with Discord". This flow is intended
    /// for desktop and mobile devices. If you are implementing for the console, leverage the device
    /// auth flow instead (Client::GetTokenFromDevice or Client::OpenAuthorizeDeviceScreen).
    ///
    /// ## Overview
    /// If you're not familiar with OAuth2, some basic background: At a high level the goal of
    /// OAuth2 is to allow a user to connect two applications together and share data between them.
    /// In this case, allowing a game to access some of their Discord data. The high level flow is:
    /// - This function, Authorize, is invoked to start the OAuth2 process, and the user is sent to
    /// Discord
    /// - On Discord, the user sees a prompt to authorize the connection, and that prompt explains
    /// what data and functionality the game is requesting.
    /// - Once the user approves the connection, they are redirected back to your application with a
    /// secret code.
    /// - You can then exchange that secret code to get back an access token which can be used to
    /// authenticate with the SDK.
    ///
    /// ## Public vs Confidential Clients
    /// Normal OAuth2 requires a backend server to handle exchanging the "code" for a "token" (the
    /// last step mentioned above). Not all games have backend servers or their own identity system
    /// though, and for early testing of the SDK that can take some time to setup.
    ///
    /// If desired, you can instead change your Discord application in the developer portal (on the
    /// OAuth2 tab), to be a "public" client. This will allow you to exchange the code for a token
    /// without a backend server, by using the GetToken function below. You can also change this
    /// setting back once you have a backend in place later too.
    ///
    /// ## Overlay
    /// To streamline the authentication process, the SDK will attempt to use the Discord overlay if
    /// it is enabled. This will allow the user to authenticate without leaving the game, enabling a
    /// more seamless experience.
    ///
    /// You should check to see if the Discord overlay works with your game before shipping. It's
    /// ok if it doesn't though, the SDK will fall back to using a browser window. Once you're ready
    /// to ship, you can work with us to have the overlay enabled by default for your game too.
    ///
    /// If your game's main window is not the same process that the SDK is running in, then you need
    /// to tell the SDK the PID of the window that the overlay should attach to. You can do this by
    /// calling Client::SetGameWindowPid.
    ///
    /// ## Redirects
    /// For the Authorize function to work, you must configure a redirect url in your Discord
    /// application in the developer portal, (it is located on the OAuth2 tab).
    /// - For desktop applications, add `http://127.0.0.1/callback`
    /// - For mobile applications, add `discord-APP_ID:/authorize/callback`
    ///
    /// The SDK will then spin up a local webserver to handle the OAuth2 redirects for you as
    /// well to streamline your integration.
    ///
    /// ## Security
    /// This function accepts an args object, and two of those values are important for security:
    /// - To prevent CSRF attacks during auth, the SDK automatically attaches a state and checks it
    /// for you when performing the authorization. You can override state if you want for your own
    /// flow, but please be mindful to keep it a secure, random value.
    /// - If you are using the Client::GetToken function you will need to provide a "code challenge"
    /// or "code verifier". We'll spare you the boring details of how that works (woo… crypto), as
    /// we've made a simple function to create these for you,
    /// Client::CreateAuthorizationCodeVerifier. That returns a struct with two items, a `challenge`
    /// value to pass into this function and a `verifier` value to pass into Client::GetToken.
    ///
    /// ## Callbacks & Code Exchange
    /// When this flow completes, the given callback function will be invoked with a "code". That
    /// code must be exchanged for an actual authorization token before it can be used. To start,
    /// you can use the Client::GetToken function to perform this exchange. Longer term private apps
    /// will want to move to the server side API for this, since that enables provisional accounts
    /// to "upgrade" to full Discord accounts.
    ///
    /// ## Android
    /// You must add the appropriate intent filter to your `AndroidManifest.xml`.
    /// `AndroidBuildPostProcessor` in the sample demonstrates how to do this automatically.
    ///
    /// If you'd like to manage it yourself, the required entry in your `<application>` looks like
    /// this:
    /// ```xml
    /// <activity android:name="com.discord.socialsdk.AuthenticationActivity"
    /// android:exported="true">
    ///   <intent-filter>
    ///     <action android:name="android.intent.action.VIEW" />
    ///     <category android:name="android.intent.category.DEFAULT" />
    ///     <category android:name="android.intent.category.BROWSABLE" />
    ///     <data android:scheme="discord-1234567890123456789" />
    ///   </intent-filter>
    /// </activity>
    /// ```
    /// Replace the numbers after `discord-` with your Application ID from the Discord developer
    /// portal.
    ///
    /// Android support (specifically the builtin auth flow) requires the androidx.browser library
    /// as a dependency of your app. The sample uses Google External Dependency Manager to add this
    /// to the Gradle build for the project, but you may use any means of your choosing to add this
    /// dependency. We currently depend on version 1.8.0 of this library.
    ///
    /// For more information see: https://discord.com/developers/docs/topics/oauth2
    void Authorize(UDiscordAuthorizationArgs* args,
                   FDiscordClientAuthorizationCallback const& callback);

    /// \brief Initiates an OAuth2 flow for a user to "sign in with Discord". This flow is intended
    /// for desktop and mobile devices. If you are implementing for the console, leverage the device
    /// auth flow instead (Client::GetTokenFromDevice or Client::OpenAuthorizeDeviceScreen).
    ///
    /// ## Overview
    /// If you're not familiar with OAuth2, some basic background: At a high level the goal of
    /// OAuth2 is to allow a user to connect two applications together and share data between them.
    /// In this case, allowing a game to access some of their Discord data. The high level flow is:
    /// - This function, Authorize, is invoked to start the OAuth2 process, and the user is sent to
    /// Discord
    /// - On Discord, the user sees a prompt to authorize the connection, and that prompt explains
    /// what data and functionality the game is requesting.
    /// - Once the user approves the connection, they are redirected back to your application with a
    /// secret code.
    /// - You can then exchange that secret code to get back an access token which can be used to
    /// authenticate with the SDK.
    ///
    /// ## Public vs Confidential Clients
    /// Normal OAuth2 requires a backend server to handle exchanging the "code" for a "token" (the
    /// last step mentioned above). Not all games have backend servers or their own identity system
    /// though, and for early testing of the SDK that can take some time to setup.
    ///
    /// If desired, you can instead change your Discord application in the developer portal (on the
    /// OAuth2 tab), to be a "public" client. This will allow you to exchange the code for a token
    /// without a backend server, by using the GetToken function below. You can also change this
    /// setting back once you have a backend in place later too.
    ///
    /// ## Overlay
    /// To streamline the authentication process, the SDK will attempt to use the Discord overlay if
    /// it is enabled. This will allow the user to authenticate without leaving the game, enabling a
    /// more seamless experience.
    ///
    /// You should check to see if the Discord overlay works with your game before shipping. It's
    /// ok if it doesn't though, the SDK will fall back to using a browser window. Once you're ready
    /// to ship, you can work with us to have the overlay enabled by default for your game too.
    ///
    /// If your game's main window is not the same process that the SDK is running in, then you need
    /// to tell the SDK the PID of the window that the overlay should attach to. You can do this by
    /// calling Client::SetGameWindowPid.
    ///
    /// ## Redirects
    /// For the Authorize function to work, you must configure a redirect url in your Discord
    /// application in the developer portal, (it is located on the OAuth2 tab).
    /// - For desktop applications, add `http://127.0.0.1/callback`
    /// - For mobile applications, add `discord-APP_ID:/authorize/callback`
    ///
    /// The SDK will then spin up a local webserver to handle the OAuth2 redirects for you as
    /// well to streamline your integration.
    ///
    /// ## Security
    /// This function accepts an args object, and two of those values are important for security:
    /// - To prevent CSRF attacks during auth, the SDK automatically attaches a state and checks it
    /// for you when performing the authorization. You can override state if you want for your own
    /// flow, but please be mindful to keep it a secure, random value.
    /// - If you are using the Client::GetToken function you will need to provide a "code challenge"
    /// or "code verifier". We'll spare you the boring details of how that works (woo… crypto), as
    /// we've made a simple function to create these for you,
    /// Client::CreateAuthorizationCodeVerifier. That returns a struct with two items, a `challenge`
    /// value to pass into this function and a `verifier` value to pass into Client::GetToken.
    ///
    /// ## Callbacks & Code Exchange
    /// When this flow completes, the given callback function will be invoked with a "code". That
    /// code must be exchanged for an actual authorization token before it can be used. To start,
    /// you can use the Client::GetToken function to perform this exchange. Longer term private apps
    /// will want to move to the server side API for this, since that enables provisional accounts
    /// to "upgrade" to full Discord accounts.
    ///
    /// ## Android
    /// You must add the appropriate intent filter to your `AndroidManifest.xml`.
    /// `AndroidBuildPostProcessor` in the sample demonstrates how to do this automatically.
    ///
    /// If you'd like to manage it yourself, the required entry in your `<application>` looks like
    /// this:
    /// ```xml
    /// <activity android:name="com.discord.socialsdk.AuthenticationActivity"
    /// android:exported="true">
    ///   <intent-filter>
    ///     <action android:name="android.intent.action.VIEW" />
    ///     <category android:name="android.intent.category.DEFAULT" />
    ///     <category android:name="android.intent.category.BROWSABLE" />
    ///     <data android:scheme="discord-1234567890123456789" />
    ///   </intent-filter>
    /// </activity>
    /// ```
    /// Replace the numbers after `discord-` with your Application ID from the Discord developer
    /// portal.
    ///
    /// Android support (specifically the builtin auth flow) requires the androidx.browser library
    /// as a dependency of your app. The sample uses Google External Dependency Manager to add this
    /// to the Gradle build for the project, but you may use any means of your choosing to add this
    /// dependency. We currently depend on version 1.8.0 of this library.
    ///
    /// For more information see: https://discord.com/developers/docs/topics/oauth2
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "callback"))
    void Authorize(UDiscordAuthorizationArgs* args,
                   FDiscordClientAuthorizationCallbackDynamic const& callback);

    /// \brief This function is used to hide the device authorization screen and is used for the
    /// case where the user is on a limited input device, such as a console or smart TV. This
    /// function should be used in conjunction with a backend server to handle the device
    /// authorization flow. For a public client, you can use Client::AbortGetTokenFromDevice
    /// instead.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void CloseAuthorizeDeviceScreen();

    /// \brief Helper function that can create a code challenge and verifier for use in the
    /// Client::Authorize + Client::GetToken flow. This returns a struct with two items, a
    /// `challenge` value to pass into Client::Authorize and a `verifier` value to pass into
    /// GetToken.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    UDiscordAuthorizationCodeVerifier* CreateAuthorizationCodeVerifier();

    /// \brief Exchanges a parent application token for a child application token.
    ///
    /// This is used to get a token for a child application that is linked to the parent
    /// application. This is only relevant if you have an applications set up in a parent/child
    /// relationship, which is applicable if you are a publisher with multiple games under the
    /// same account system. Access to this feature is currently limited.
    ///
    /// NOTE: This function only works for public clients. Public clients are ones that do not have
    /// a backend server or their own concept of user accounts and simply rely on a separate system
    /// for authentication like Steam/Epic.
    ///
    /// When first testing the SDK, it can be a lot easier to use a public client to get a proof of
    /// concept going, and change it to a confidential client later. You can toggle that setting on
    /// the OAuth2 page for your application in the Discord developer portal,
    /// https://discord.com/developers/applications
    void ExchangeChildToken(FString const& parentApplicationToken,
                            FDiscordUniqueID childApplicationId,
                            FDiscordClientExchangeChildTokenCallback const& callback);

    /// \brief Exchanges a parent application token for a child application token.
    ///
    /// This is used to get a token for a child application that is linked to the parent
    /// application. This is only relevant if you have an applications set up in a parent/child
    /// relationship, which is applicable if you are a publisher with multiple games under the
    /// same account system. Access to this feature is currently limited.
    ///
    /// NOTE: This function only works for public clients. Public clients are ones that do not have
    /// a backend server or their own concept of user accounts and simply rely on a separate system
    /// for authentication like Steam/Epic.
    ///
    /// When first testing the SDK, it can be a lot easier to use a public client to get a proof of
    /// concept going, and change it to a confidential client later. You can toggle that setting on
    /// the OAuth2 page for your application in the Discord developer portal,
    /// https://discord.com/developers/applications
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "callback"))
    void ExchangeChildToken(FString const& parentApplicationToken,
                            FDiscordUniqueID childApplicationId,
                            FDiscordClientExchangeChildTokenCallbackDynamic const& callback);

    /// \brief Fetches basic information about the user associated with the given auth token.
    ///
    /// This can allow you to check if an auth token is valid or not.
    /// This does not require the client to be connected or to have it's own authentication token,
    /// so it can be called immediately after the client connects.
    void FetchCurrentUser(EDiscordAuthorizationTokenType tokenType,
                          FString const& token,
                          FDiscordClientFetchCurrentUserCallback const& callback);

    /// \brief Fetches basic information about the user associated with the given auth token.
    ///
    /// This can allow you to check if an auth token is valid or not.
    /// This does not require the client to be connected or to have it's own authentication token,
    /// so it can be called immediately after the client connects.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "callback"))
    void FetchCurrentUser(EDiscordAuthorizationTokenType tokenType,
                          FString const& token,
                          FDiscordClientFetchCurrentUserCallbackDynamic const& callback);

    /// \brief Provisional accounts are a way for users that have not signed up for Discord to still
    /// access SDK functionality. They are "placeholder" Discord accounts for the user that are
    /// owned and managed by your game. Provisional accounts exist so that your users can engage
    /// with Discord APIs and systems without the friction of creating their own Discord account.
    /// Provisional accounts and their data are unique per Discord application.
    ///
    /// This function generates a Discord access token. You pass in the "identity" of the user, and
    /// it generates a new Discord account that is tied to that identity. There are multiple ways of
    /// specifying that identity, including using Steam/Epic services, or using your own identity
    /// system.
    ///
    /// The callback function will be invoked with an access token that expires in 1 hour. Refresh
    /// tokens are not supported for provisional accounts, so that will be an empty string. You
    /// will need to call this function again to get a new access token when the old one expires.
    ///
    /// NOTE: When the token expires the SDK will still continue to receive updates such as new
    /// messages sent in a lobby, and any voice calls will continue to be active. But any new
    /// actions taken will fail such as sending a messaging or adding a friend. You can get a new
    /// token and pass it to UpdateToken without interrupting the user's experience.
    ///
    /// It is suggested that these provisional tokens are not stored, and instead to just invoke
    /// this function each time the game is launched and when these tokens are about to expire.
    /// However, should you choose to store it, it is recommended to differentiate these provisional
    /// account tokens from "full" Discord account tokens.
    ///
    /// NOTE: This function only works for public clients. Public clients are ones that do not have
    /// a backend server or their own concept of user accounts and simply rely on a separate system
    /// for authentication like Steam/Epic.
    ///
    /// When first testing the SDK, it can be a lot easier to use a public client to get a proof of
    /// concept going, and change it to a confidential client later. You can toggle that setting on
    /// the OAuth2 page for your application in the Discord developer portal,
    /// https://discord.com/developers/applications
    void GetProvisionalToken(FDiscordUniqueID applicationId,
                             EDiscordAuthenticationExternalAuthType externalAuthType,
                             FString const& externalAuthToken,
                             FDiscordClientTokenExchangeCallback const& callback);

    /// \brief Provisional accounts are a way for users that have not signed up for Discord to still
    /// access SDK functionality. They are "placeholder" Discord accounts for the user that are
    /// owned and managed by your game. Provisional accounts exist so that your users can engage
    /// with Discord APIs and systems without the friction of creating their own Discord account.
    /// Provisional accounts and their data are unique per Discord application.
    ///
    /// This function generates a Discord access token. You pass in the "identity" of the user, and
    /// it generates a new Discord account that is tied to that identity. There are multiple ways of
    /// specifying that identity, including using Steam/Epic services, or using your own identity
    /// system.
    ///
    /// The callback function will be invoked with an access token that expires in 1 hour. Refresh
    /// tokens are not supported for provisional accounts, so that will be an empty string. You
    /// will need to call this function again to get a new access token when the old one expires.
    ///
    /// NOTE: When the token expires the SDK will still continue to receive updates such as new
    /// messages sent in a lobby, and any voice calls will continue to be active. But any new
    /// actions taken will fail such as sending a messaging or adding a friend. You can get a new
    /// token and pass it to UpdateToken without interrupting the user's experience.
    ///
    /// It is suggested that these provisional tokens are not stored, and instead to just invoke
    /// this function each time the game is launched and when these tokens are about to expire.
    /// However, should you choose to store it, it is recommended to differentiate these provisional
    /// account tokens from "full" Discord account tokens.
    ///
    /// NOTE: This function only works for public clients. Public clients are ones that do not have
    /// a backend server or their own concept of user accounts and simply rely on a separate system
    /// for authentication like Steam/Epic.
    ///
    /// When first testing the SDK, it can be a lot easier to use a public client to get a proof of
    /// concept going, and change it to a confidential client later. You can toggle that setting on
    /// the OAuth2 page for your application in the Discord developer portal,
    /// https://discord.com/developers/applications
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "callback"))
    void GetProvisionalToken(FDiscordUniqueID applicationId,
                             EDiscordAuthenticationExternalAuthType externalAuthType,
                             FString const& externalAuthToken,
                             FDiscordClientTokenExchangeCallbackDynamic const& callback);
#if DISCORD_DEBUG_API_ENABLED

    /// \brief DEBUG ONLY: Creates a provisional token using Discord Bot API.
    /// This method is only available in debug builds and should not be used in production.
    void GetProvisionalTokenBotAPI(FDiscordUniqueID applicationId,
                                   FString const& botToken,
                                   FString const& externalUserId,
                                   FString const& preferredGlobalName,
                                   FDiscordClientTokenExchangeCallback const& callback);

    /// \brief DEBUG ONLY: Creates a provisional token using Discord Bot API.
    /// This method is only available in debug builds and should not be used in production.
    void GetProvisionalTokenBotAPI(FDiscordUniqueID applicationId,
                                   FString const& botToken,
                                   FString const& externalUserId,
                                   FString const& preferredGlobalName,
                                   FDiscordClientTokenExchangeCallbackDynamic const& callback);
#endif

    /// \brief Exchanges an authorization code that was returned from the Client::Authorize function
    /// for an access token which can be used to authenticate with the SDK.
    ///
    /// The callback function will be invoked with two tokens:
    /// - An access token which can be used to authenticate with the SDK, but expires after 7 days.
    /// - A refresh token, which cannot be used to authenticate, but can be used to get a new access
    /// token later. Refresh tokens do not currently expire.
    ///
    /// It will also include when the access token expires in seconds.
    /// You will want to store this value as well and refresh the token when it gets close to
    /// expiring (for example if the user launches the game and the token expires within 24 hours,
    /// it would be good to refresh it).
    ///
    /// For more information see https://discord.com/developers/docs/topics/oauth2
    ///
    /// NOTE: This function only works for public clients. Public clients are ones that do not have
    /// a backend server or their own concept of user accounts and simply rely on a separate system
    /// for authentication like Steam/Epic.
    ///
    /// When first testing the SDK, it can be a lot easier to use a public client to get a proof of
    /// concept going, and change it to a confidential client later. You can toggle that setting on
    /// the OAuth2 page for your application in the Discord developer portal,
    /// https://discord.com/developers/applications
    void GetToken(FDiscordUniqueID applicationId,
                  FString const& code,
                  FString const& codeVerifier,
                  FString const& redirectUri,
                  FDiscordClientTokenExchangeCallback const& callback);

    /// \brief Exchanges an authorization code that was returned from the Client::Authorize function
    /// for an access token which can be used to authenticate with the SDK.
    ///
    /// The callback function will be invoked with two tokens:
    /// - An access token which can be used to authenticate with the SDK, but expires after 7 days.
    /// - A refresh token, which cannot be used to authenticate, but can be used to get a new access
    /// token later. Refresh tokens do not currently expire.
    ///
    /// It will also include when the access token expires in seconds.
    /// You will want to store this value as well and refresh the token when it gets close to
    /// expiring (for example if the user launches the game and the token expires within 24 hours,
    /// it would be good to refresh it).
    ///
    /// For more information see https://discord.com/developers/docs/topics/oauth2
    ///
    /// NOTE: This function only works for public clients. Public clients are ones that do not have
    /// a backend server or their own concept of user accounts and simply rely on a separate system
    /// for authentication like Steam/Epic.
    ///
    /// When first testing the SDK, it can be a lot easier to use a public client to get a proof of
    /// concept going, and change it to a confidential client later. You can toggle that setting on
    /// the OAuth2 page for your application in the Discord developer portal,
    /// https://discord.com/developers/applications
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "callback"))
    void GetToken(FDiscordUniqueID applicationId,
                  FString const& code,
                  FString const& codeVerifier,
                  FString const& redirectUri,
                  FDiscordClientTokenExchangeCallbackDynamic const& callback);

    /// \brief This function is a combination of Client::Authorize and Client::GetToken, but is used
    /// for the case where the user is on a limited input device, such as a console or smart TV.
    ///
    /// The callback function will be invoked with two tokens:
    /// - An access token which can be used to authenticate with the SDK, but expires after 7 days.
    /// - A refresh token, which cannot be used to authenticate, but can be used to get a new access
    /// token later. Refresh tokens do not currently expire.
    ///
    /// It will also include when the access token expires in seconds.
    /// You will want to store this value as well and refresh the token when it gets close to
    /// expiring (for example if the user launches the game and the token expires within 24 hours,
    /// it would be good to refresh it).
    ///
    /// For more information see https://discord.com/developers/docs/topics/oauth2
    ///
    /// NOTE: This function only works for public clients. Public clients are ones that do not have
    /// a backend server or their own concept of user accounts and simply rely on a separate system
    /// for authentication like Steam/Epic. If you have a backend server for auth, you can use
    /// Client::OpenAuthorizeDeviceScreen and Client::CloseAuthorizeDeviceScreen to show/hide the UI
    /// for the device auth flow.
    ///
    /// When first testing the SDK, it can be a lot easier to use a public client to get a proof of
    /// concept going, and change it to a confidential client later. You can toggle that setting on
    /// the OAuth2 page for your application in the Discord developer portal,
    /// https://discord.com/developers/applications
    void GetTokenFromDevice(UDiscordDeviceAuthorizationArgs* args,
                            FDiscordClientTokenExchangeCallback const& callback);

    /// \brief This function is a combination of Client::Authorize and Client::GetToken, but is used
    /// for the case where the user is on a limited input device, such as a console or smart TV.
    ///
    /// The callback function will be invoked with two tokens:
    /// - An access token which can be used to authenticate with the SDK, but expires after 7 days.
    /// - A refresh token, which cannot be used to authenticate, but can be used to get a new access
    /// token later. Refresh tokens do not currently expire.
    ///
    /// It will also include when the access token expires in seconds.
    /// You will want to store this value as well and refresh the token when it gets close to
    /// expiring (for example if the user launches the game and the token expires within 24 hours,
    /// it would be good to refresh it).
    ///
    /// For more information see https://discord.com/developers/docs/topics/oauth2
    ///
    /// NOTE: This function only works for public clients. Public clients are ones that do not have
    /// a backend server or their own concept of user accounts and simply rely on a separate system
    /// for authentication like Steam/Epic. If you have a backend server for auth, you can use
    /// Client::OpenAuthorizeDeviceScreen and Client::CloseAuthorizeDeviceScreen to show/hide the UI
    /// for the device auth flow.
    ///
    /// When first testing the SDK, it can be a lot easier to use a public client to get a proof of
    /// concept going, and change it to a confidential client later. You can toggle that setting on
    /// the OAuth2 page for your application in the Discord developer portal,
    /// https://discord.com/developers/applications
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "callback"))
    void GetTokenFromDevice(UDiscordDeviceAuthorizationArgs* args,
                            FDiscordClientTokenExchangeCallbackDynamic const& callback);

    /// \brief This function is a combination of Client::Authorize and
    /// Client::GetTokenFromProvisionalMerge, but is used for the case where the user is on a
    /// limited input device, such as a console or smart TV.
    ///
    /// This function should be used whenever a user with a provisional account wants to link to an
    /// existing Discord account or "upgrade" their provisional account into a "full" Discord
    /// account.
    ///
    /// In this case, data from the provisional account should be "migrated" to the Discord
    /// account, a process we call "account merging". Specifically relationships, DMs, and lobby
    /// memberships are transferred to the Discord account.
    ///
    /// The provisional account will be deleted once this merging process completes. If the user
    /// later unlinks, then a new provisional account with a new unique ID is created.
    ///
    /// The account merging process starts the same as the normal login flow, by invoking the
    /// GetTokenFromDevice. But instead of calling GetTokenFromDevice, call this function and pass
    /// in the provisional user's identity as well.
    ///
    /// The Discord backend can then find both the provisional account with that identity and the
    /// new Discord account and merge any data as necessary.
    ///
    /// See the documentation for GetTokenFromDevice for more details on the callback. Note that the
    /// callback will be invoked when the token exchange completes, but the process of merging
    /// accounts happens asynchronously so will not be complete yet.
    ///
    /// NOTE: This function only works for public clients. Public clients are ones that do not have
    /// a backend server or their own concept of user accounts and simply rely on a separate system
    /// for authentication like Steam/Epic. If you have a backend server for auth, you can use
    /// Client::OpenAuthorizeDeviceScreen and Client::CloseAuthorizeDeviceScreen to show/hide the UI
    /// for the device auth flow.
    ///
    /// When first testing the SDK, it can be a lot easier to use a public client to get a proof of
    /// concept going, and change it to a confidential client later. You can toggle that setting on
    /// the OAuth2 page for your application in the Discord developer portal,
    /// https://discord.com/developers/applications
    void GetTokenFromDeviceProvisionalMerge(UDiscordDeviceAuthorizationArgs* args,
                                            EDiscordAuthenticationExternalAuthType externalAuthType,
                                            FString const& externalAuthToken,
                                            FDiscordClientTokenExchangeCallback const& callback);

    /// \brief This function is a combination of Client::Authorize and
    /// Client::GetTokenFromProvisionalMerge, but is used for the case where the user is on a
    /// limited input device, such as a console or smart TV.
    ///
    /// This function should be used whenever a user with a provisional account wants to link to an
    /// existing Discord account or "upgrade" their provisional account into a "full" Discord
    /// account.
    ///
    /// In this case, data from the provisional account should be "migrated" to the Discord
    /// account, a process we call "account merging". Specifically relationships, DMs, and lobby
    /// memberships are transferred to the Discord account.
    ///
    /// The provisional account will be deleted once this merging process completes. If the user
    /// later unlinks, then a new provisional account with a new unique ID is created.
    ///
    /// The account merging process starts the same as the normal login flow, by invoking the
    /// GetTokenFromDevice. But instead of calling GetTokenFromDevice, call this function and pass
    /// in the provisional user's identity as well.
    ///
    /// The Discord backend can then find both the provisional account with that identity and the
    /// new Discord account and merge any data as necessary.
    ///
    /// See the documentation for GetTokenFromDevice for more details on the callback. Note that the
    /// callback will be invoked when the token exchange completes, but the process of merging
    /// accounts happens asynchronously so will not be complete yet.
    ///
    /// NOTE: This function only works for public clients. Public clients are ones that do not have
    /// a backend server or their own concept of user accounts and simply rely on a separate system
    /// for authentication like Steam/Epic. If you have a backend server for auth, you can use
    /// Client::OpenAuthorizeDeviceScreen and Client::CloseAuthorizeDeviceScreen to show/hide the UI
    /// for the device auth flow.
    ///
    /// When first testing the SDK, it can be a lot easier to use a public client to get a proof of
    /// concept going, and change it to a confidential client later. You can toggle that setting on
    /// the OAuth2 page for your application in the Discord developer portal,
    /// https://discord.com/developers/applications
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "callback"))
    void GetTokenFromDeviceProvisionalMerge(
      UDiscordDeviceAuthorizationArgs* args,
      EDiscordAuthenticationExternalAuthType externalAuthType,
      FString const& externalAuthToken,
      FDiscordClientTokenExchangeCallbackDynamic const& callback);

    /// \brief This function should be used with the Client::Authorize function whenever a user with
    /// a provisional account wants to link to an existing Discord account or "upgrade" their
    /// provisional account into a "full" Discord account.
    ///
    /// In this case, data from the provisional account should be "migrated" to the Discord
    /// account, a process we call "account merging". Specifically relationships, DMs, and lobby
    /// memberships are transferred to the Discord account.
    ///
    /// The provisional account will be deleted once this merging process completes. If the user
    /// later unlinks, then a new provisional account with a new unique ID is created.
    ///
    /// The account merging process starts the same as the normal login flow, by invoking the
    /// Authorize method to get an authorization code back. But instead of calling GetToken, call
    /// this function and pass in the provisional user's identity as well.
    ///
    /// The Discord backend can then find both the provisional account with that identity and the
    /// new Discord account and merge any data as necessary.
    ///
    /// See the documentation for GetToken for more details on the callback. Note that the callback
    /// will be invoked when the token exchange completes, but the process of merging accounts
    /// happens asynchronously so will not be complete yet.
    ///
    /// NOTE: This function only works for public clients. Public clients are ones that do not have
    /// a backend server or their own concept of user accounts and simply rely on a separate system
    /// for authentication like Steam/Epic.
    ///
    /// When first testing the SDK, it can be a lot easier to use a public client to get a proof of
    /// concept going, and change it to a confidential client later. You can toggle that setting on
    /// the OAuth2 page for your application in the Discord developer portal,
    /// https://discord.com/developers/applications
    void GetTokenFromProvisionalMerge(FDiscordUniqueID applicationId,
                                      FString const& code,
                                      FString const& codeVerifier,
                                      FString const& redirectUri,
                                      EDiscordAuthenticationExternalAuthType externalAuthType,
                                      FString const& externalAuthToken,
                                      FDiscordClientTokenExchangeCallback const& callback);

    /// \brief This function should be used with the Client::Authorize function whenever a user with
    /// a provisional account wants to link to an existing Discord account or "upgrade" their
    /// provisional account into a "full" Discord account.
    ///
    /// In this case, data from the provisional account should be "migrated" to the Discord
    /// account, a process we call "account merging". Specifically relationships, DMs, and lobby
    /// memberships are transferred to the Discord account.
    ///
    /// The provisional account will be deleted once this merging process completes. If the user
    /// later unlinks, then a new provisional account with a new unique ID is created.
    ///
    /// The account merging process starts the same as the normal login flow, by invoking the
    /// Authorize method to get an authorization code back. But instead of calling GetToken, call
    /// this function and pass in the provisional user's identity as well.
    ///
    /// The Discord backend can then find both the provisional account with that identity and the
    /// new Discord account and merge any data as necessary.
    ///
    /// See the documentation for GetToken for more details on the callback. Note that the callback
    /// will be invoked when the token exchange completes, but the process of merging accounts
    /// happens asynchronously so will not be complete yet.
    ///
    /// NOTE: This function only works for public clients. Public clients are ones that do not have
    /// a backend server or their own concept of user accounts and simply rely on a separate system
    /// for authentication like Steam/Epic.
    ///
    /// When first testing the SDK, it can be a lot easier to use a public client to get a proof of
    /// concept going, and change it to a confidential client later. You can toggle that setting on
    /// the OAuth2 page for your application in the Discord developer portal,
    /// https://discord.com/developers/applications
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "callback"))
    void GetTokenFromProvisionalMerge(FDiscordUniqueID applicationId,
                                      FString const& code,
                                      FString const& codeVerifier,
                                      FString const& redirectUri,
                                      EDiscordAuthenticationExternalAuthType externalAuthType,
                                      FString const& externalAuthToken,
                                      FDiscordClientTokenExchangeCallbackDynamic const& callback);

    /// \brief Returns true if the SDK has a non-empty OAuth2 token set, regardless of whether that
    /// token is valid or not.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    bool IsAuthenticated();

    /// \brief This function is used to show the device authorization screen and is used for the
    /// case where the user is on a limited input device, such as a console or smart TV. This
    /// function should be used in conjunction with a backend server to handle the device
    /// authorization flow. For a public client, you can use Client::GetTokenFromDevice instead.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void OpenAuthorizeDeviceScreen(FDiscordUniqueID clientId, FString const& userCode);

    /// \brief Some functions don't work for provisional accounts, and require the user
    /// merge their account into a full Discord account before proceeding. This
    /// callback is invoked when an account merge must take place before
    /// proceeding. The developer is responsible for initiating the account merge,
    /// and then calling Client::ProvisionalUserMergeCompleted to signal to the SDK that
    /// the pending operation can continue with the new account.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void ProvisionalUserMergeCompleted(bool success);

    /// \brief Generates a new access token for the current user from a refresh token.
    ///
    /// Once this is called, the old access and refresh tokens are both invalidated and cannot be
    /// used again. The callback function will be invoked with a new access and refresh token. See
    /// GetToken for more details.
    ///
    /// NOTE: This function only works for public clients. Public clients are ones that do not have
    /// a backend server or their own concept of user accounts and simply rely on a separate system
    /// for authentication like Steam/Epic.
    ///
    /// When first testing the SDK, it can be a lot easier to use a public client to get a proof of
    /// concept going, and change it to a confidential client later. You can toggle that setting on
    /// the OAuth2 page for your application in the Discord developer portal,
    /// https://discord.com/developers/applications
    void RefreshToken(FDiscordUniqueID applicationId,
                      FString const& refreshToken,
                      FDiscordClientTokenExchangeCallback const& callback);

    /// \brief Generates a new access token for the current user from a refresh token.
    ///
    /// Once this is called, the old access and refresh tokens are both invalidated and cannot be
    /// used again. The callback function will be invoked with a new access and refresh token. See
    /// GetToken for more details.
    ///
    /// NOTE: This function only works for public clients. Public clients are ones that do not have
    /// a backend server or their own concept of user accounts and simply rely on a separate system
    /// for authentication like Steam/Epic.
    ///
    /// When first testing the SDK, it can be a lot easier to use a public client to get a proof of
    /// concept going, and change it to a confidential client later. You can toggle that setting on
    /// the OAuth2 page for your application in the Discord developer portal,
    /// https://discord.com/developers/applications
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "callback"))
    void RefreshToken(FDiscordUniqueID applicationId,
                      FString const& refreshToken,
                      FDiscordClientTokenExchangeCallbackDynamic const& callback);

    /// \brief Registers a callback to be invoked when a user requests to initiate the authorization
    /// flow.
    ///
    /// When you register this callback, the Discord app will show new entry points to allow users
    /// to initiate the authorization flow.
    ///
    /// This function is tied to upcoming Discord client functionality experiments that will be
    /// rolled out to a percentage of Discord users over time. More documentation and implementation
    /// details to come as the client experiments run.
    void RegisterAuthorizeRequestCallback(FDiscordClientAuthorizeRequestCallback const& callback);

    /// \brief Registers a callback to be invoked when a user requests to initiate the authorization
    /// flow.
    ///
    /// When you register this callback, the Discord app will show new entry points to allow users
    /// to initiate the authorization flow.
    ///
    /// This function is tied to upcoming Discord client functionality experiments that will be
    /// rolled out to a percentage of Discord users over time. More documentation and implementation
    /// details to come as the client experiments run.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "callback"))
    void RegisterAuthorizeRequestCallback(
      FDiscordClientAuthorizeRequestCallbackDynamic const& callback);

    /// \brief Stops listening for the AUTHORIZE_REQUEST event and removes the registered callback
    ///
    /// This function is tied to upcoming Discord client functionality experiments that will be
    /// rolled out to a percentage of Discord users over time. More documentation and implementation
    /// details to come as the client experiments run.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void RemoveAuthorizeRequestCallback();

    /// \brief Revoke all application access/refresh tokens associated with a user with any valid
    /// access/refresh token. This will invalidate all tokens and they cannot be used again. This
    /// is useful if you want to log the user out of the game and invalidate their session.
    ///
    /// NOTE: This function only works for public clients. Public clients are ones that do not have
    /// a backend server or their own concept of user accounts and simply rely on a separate system
    /// for authentication like Steam/Epic.
    ///
    /// When first testing the SDK, it can be a lot easier to use a public client to get a proof of
    /// concept going, and change it to a confidential client later. You can toggle that setting on
    /// the OAuth2 page for your application in the Discord developer portal,
    /// https://discord.com/developers/applications
    void RevokeToken(FDiscordUniqueID applicationId,
                     FString const& token,
                     FDiscordClientRevokeTokenCallback const& callback);

    /// \brief Revoke all application access/refresh tokens associated with a user with any valid
    /// access/refresh token. This will invalidate all tokens and they cannot be used again. This
    /// is useful if you want to log the user out of the game and invalidate their session.
    ///
    /// NOTE: This function only works for public clients. Public clients are ones that do not have
    /// a backend server or their own concept of user accounts and simply rely on a separate system
    /// for authentication like Steam/Epic.
    ///
    /// When first testing the SDK, it can be a lot easier to use a public client to get a proof of
    /// concept going, and change it to a confidential client later. You can toggle that setting on
    /// the OAuth2 page for your application in the Discord developer portal,
    /// https://discord.com/developers/applications
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "callback"))
    void RevokeToken(FDiscordUniqueID applicationId,
                     FString const& token,
                     FDiscordClientRevokeTokenCallbackDynamic const& callback);

    /// \brief Sets a callback function to be invoked when the device authorization screen is
    /// closed.
    void SetAuthorizeDeviceScreenClosedCallback(
      FDiscordClientAuthorizeDeviceScreenClosedCallback const& cb);

    /// \brief Sets a callback function to be invoked when the device authorization screen is
    /// closed.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void SetAuthorizeDeviceScreenClosedCallback(
      FDiscordClientAuthorizeDeviceScreenClosedCallbackDynamic const& cb);

    /// \brief When users are linking their account with Discord, which involves an OAuth2 flow,
    /// the SDK can streamline it by using Discord's overlay so the interaction happens entirely
    /// in-game. If your game's main window is not the same process as the one running the
    /// integration you may need to set the window PID using this method. It defaults to the current
    /// pid.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetGameWindowPid(int32 pid);

    /// \brief Get a notification when the current token is about to expire or expired.
    ///
    /// This callback is invoked when the SDK detects that the last token passed to
    /// Client::UpdateToken is nearing expiration or has expired. This is a signal to the developer
    /// to refresh the token. The callback is invoked once per token, and will not be invoked again
    /// until a new token is passed to Client::UpdateToken.
    ///
    /// If the token is refreshed before the expiration callback is invoked, call
    /// Client::UpdateToken to pass in the new token and reconfigure the token expiration.
    ///
    /// If your client is disconnected (the token was expired when connecting or was revoked while
    /// connected), the expiration callback will not be invoked.
    void SetTokenExpirationCallback(FDiscordClientTokenExpirationCallback const& callback);

    /// \brief Get a notification when the current token is about to expire or expired.
    ///
    /// This callback is invoked when the SDK detects that the last token passed to
    /// Client::UpdateToken is nearing expiration or has expired. This is a signal to the developer
    /// to refresh the token. The callback is invoked once per token, and will not be invoked again
    /// until a new token is passed to Client::UpdateToken.
    ///
    /// If the token is refreshed before the expiration callback is invoked, call
    /// Client::UpdateToken to pass in the new token and reconfigure the token expiration.
    ///
    /// If your client is disconnected (the token was expired when connecting or was revoked while
    /// connected), the expiration callback will not be invoked.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "callback"))
    void SetTokenExpirationCallback(FDiscordClientTokenExpirationCallbackDynamic const& callback);

    /// \brief This function is used to unlink/unmerge a external identity from a Discord account.
    /// This is useful if the user wants to unlink their external identity from their Discord
    /// account and create a new provisional account for that identity. This will invalidate all
    /// access/refresh tokens for the user and they cannot be used again.
    ///
    /// This function should be used with the Client::GetProvisionalToken function to get a
    /// provisional token for the newly created provisional account.
    ///
    /// NOTE: This function only works for public clients. Public clients are ones that do not have
    /// a backend server or their own concept of user accounts and simply rely on a separate system
    /// for authentication like Steam/Epic.
    ///
    /// When first testing the SDK, it can be a lot easier to use a public client to get a proof of
    /// concept going, and change it to a confidential client later. You can toggle that setting on
    /// the OAuth2 page for your application in the Discord developer portal,
    /// https://discord.com/developers/applications
    void UnmergeIntoProvisionalAccount(
      FDiscordUniqueID applicationId,
      EDiscordAuthenticationExternalAuthType externalAuthType,
      FString const& externalAuthToken,
      FDiscordClientUnmergeIntoProvisionalAccountCallback const& callback);

    /// \brief This function is used to unlink/unmerge a external identity from a Discord account.
    /// This is useful if the user wants to unlink their external identity from their Discord
    /// account and create a new provisional account for that identity. This will invalidate all
    /// access/refresh tokens for the user and they cannot be used again.
    ///
    /// This function should be used with the Client::GetProvisionalToken function to get a
    /// provisional token for the newly created provisional account.
    ///
    /// NOTE: This function only works for public clients. Public clients are ones that do not have
    /// a backend server or their own concept of user accounts and simply rely on a separate system
    /// for authentication like Steam/Epic.
    ///
    /// When first testing the SDK, it can be a lot easier to use a public client to get a proof of
    /// concept going, and change it to a confidential client later. You can toggle that setting on
    /// the OAuth2 page for your application in the Discord developer portal,
    /// https://discord.com/developers/applications
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "callback"))
    void UnmergeIntoProvisionalAccount(
      FDiscordUniqueID applicationId,
      EDiscordAuthenticationExternalAuthType externalAuthType,
      FString const& externalAuthToken,
      FDiscordClientUnmergeIntoProvisionalAccountCallbackDynamic const& callback);

    /// \brief Updates the display name of a provisional account to the specified name.
    ///
    /// This should generally be invoked whenever the SDK starts and whenever a provisional account
    /// changes their name, since the auto-generated name for provisional accounts is just a random
    /// string.
    void UpdateProvisionalAccountDisplayName(
      FString const& name,
      FDiscordClientUpdateProvisionalAccountDisplayNameCallback const& callback);

    /// \brief Updates the display name of a provisional account to the specified name.
    ///
    /// This should generally be invoked whenever the SDK starts and whenever a provisional account
    /// changes their name, since the auto-generated name for provisional accounts is just a random
    /// string.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "callback"))
    void UpdateProvisionalAccountDisplayName(
      FString const& name,
      FDiscordClientUpdateProvisionalAccountDisplayNameCallbackDynamic const& callback);

    /// \brief Asynchronously sets a new auth token for this client to use.
    ///
    /// If your client is already connected, this function *may* trigger a reconnect.
    /// If your client is not connected, this function will only update the auth token, and so you
    /// must invoke Client::Connect as well. You should wait for the given callback function to be
    /// invoked though so that the next Client::Connect attempt uses the updated token.
    void UpdateToken(EDiscordAuthorizationTokenType tokenType,
                     FString const& token,
                     FDiscordClientUpdateTokenCallback const& callback);

    /// \brief Asynchronously sets a new auth token for this client to use.
    ///
    /// If your client is already connected, this function *may* trigger a reconnect.
    /// If your client is not connected, this function will only update the auth token, and so you
    /// must invoke Client::Connect as well. You should wait for the given callback function to be
    /// invoked though so that the next Client::Connect attempt uses the updated token.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "callback"))
    void UpdateToken(EDiscordAuthorizationTokenType tokenType,
                     FString const& token,
                     FDiscordClientUpdateTokenCallbackDynamic const& callback);

    /// \brief Returns true if the given message is able to be viewed in a Discord client.
    ///
    /// Not all chat messages are replicated to Discord. For example lobby chat and some DMs
    /// are ephemeral and not persisted on Discord so cannot be opened. This function checks those
    /// conditions and makes sure the message is viewable in Discord.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    bool CanOpenMessageInDiscord(FDiscordUniqueID messageId);

    /// \brief Deletes the specified message sent by the current user to the specified recipient.
    void DeleteUserMessage(FDiscordUniqueID recipientId,
                           FDiscordUniqueID messageId,
                           FDiscordClientDeleteUserMessageCallback const& cb);

    /// \brief Deletes the specified message sent by the current user to the specified recipient.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void DeleteUserMessage(FDiscordUniqueID recipientId,
                           FDiscordUniqueID messageId,
                           FDiscordClientDeleteUserMessageCallbackDynamic const& cb);

    /// \brief Edits the specified message sent by the current user to the specified recipient.
    ///
    /// All of the same restrictions apply as for sending a message, see SendUserMessage for more.
    void EditUserMessage(FDiscordUniqueID recipientId,
                         FDiscordUniqueID messageId,
                         FString const& content,
                         FDiscordClientEditUserMessageCallback const& cb);

    /// \brief Edits the specified message sent by the current user to the specified recipient.
    ///
    /// All of the same restrictions apply as for sending a message, see SendUserMessage for more.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void EditUserMessage(FDiscordUniqueID recipientId,
                         FDiscordUniqueID messageId,
                         FString const& content,
                         FDiscordClientEditUserMessageCallbackDynamic const& cb);

    /// \brief Returns a reference to the Discord channel object for the given ID.
    ///
    /// All messages in Discord are sent in a channel, so the most common use for this will be
    /// to look up the channel a message was sent in.
    /// For convience this API will also work with lobbies, so the three possible return values
    /// for the SDK are a DM, an Ephemeral DM, and a Lobby.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    UDiscordChannelHandle* GetChannelHandle(FDiscordUniqueID channelId);

    /// \brief Retrieves recent messages from the specified lobby.
    ///
    /// Returns a list of MessageHandle representing the recent messages in the lobby,
    /// with a maximum of 200 messages and up to 72 hours.
    /// The messages are returned in reverse chronological order (newest first).
    /// This function requires the current user to be a member of the lobby.
    ///
    /// Note: This function makes an HTTP request to Discord's API to retrieve messages, as opposed
    /// to only returning messages that are cached locally by the SDK.
    ///
    /// Retrieves recent messages from the specified lobby with the specified limit.
    void GetLobbyMessagesWithLimit(FDiscordUniqueID lobbyId,
                                   int32 limit,
                                   FDiscordClientGetLobbyMessagesCallback const& cb);

    /// \brief Retrieves recent messages from the specified lobby.
    ///
    /// Returns a list of MessageHandle representing the recent messages in the lobby,
    /// with a maximum of 200 messages and up to 72 hours.
    /// The messages are returned in reverse chronological order (newest first).
    /// This function requires the current user to be a member of the lobby.
    ///
    /// Note: This function makes an HTTP request to Discord's API to retrieve messages, as opposed
    /// to only returning messages that are cached locally by the SDK.
    ///
    /// Retrieves recent messages from the specified lobby with the specified limit.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void GetLobbyMessagesWithLimit(FDiscordUniqueID lobbyId,
                                   int32 limit,
                                   FDiscordClientGetLobbyMessagesCallbackDynamic const& cb);

    /// \brief Returns a reference to the Discord message object for the given ID.
    ///
    /// The SDK keeps the 25 most recent messages in each channel in memory.
    /// Messages sent before the SDK was started cannot be accessed with this.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    UDiscordMessageHandle* GetMessageHandle(FDiscordUniqueID messageId);

    /// \brief Retrieves message conversation summaries for all users the current user has DM
    /// conversations with.
    ///
    /// The callback will be invoked with a list of UserMessageSummary objects containing:
    /// - userId: The ID of the user this conversation is with
    /// - lastMessageId: The ID of the most recent message in this conversation
    void GetUserMessageSummaries(FDiscordClientUserMessageSummariesCallback const& cb);

    /// \brief Retrieves message conversation summaries for all users the current user has DM
    /// conversations with.
    ///
    /// The callback will be invoked with a list of UserMessageSummary objects containing:
    /// - userId: The ID of the user this conversation is with
    /// - lastMessageId: The ID of the most recent message in this conversation
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void GetUserMessageSummaries(FDiscordClientUserMessageSummariesCallbackDynamic const& cb);

    /// \brief Retrieves messages from the DM conversation with the specified user.
    ///
    /// Returns a list of MessageHandle representing the recent messages in the conversation with
    /// the recipient, with a with a maximum of 200 messages and up to 72 hours. The messages are
    /// returned in reverse chronological order (newest first). This function checks the local cache
    /// first and only makes an HTTP request to Discord's API if there are not enough cached
    /// messages available.
    ///
    /// If limit is greater than 0, restricts the number of messages returned. If limit is 0
    /// or negative, the limit parameter is 200 messages and 72 hours. This is intended for
    /// games to load message history when users open a DM conversation.
    ///
    /// If either user hasn't played the game, there will be no channel between them and
    /// this function will return a 404 `discordpp::ErrorType::HTTPError` error.
    void GetUserMessagesWithLimit(FDiscordUniqueID recipientId,
                                  int32 limit,
                                  FDiscordClientUserMessagesWithLimitCallback const& cb);

    /// \brief Retrieves messages from the DM conversation with the specified user.
    ///
    /// Returns a list of MessageHandle representing the recent messages in the conversation with
    /// the recipient, with a with a maximum of 200 messages and up to 72 hours. The messages are
    /// returned in reverse chronological order (newest first). This function checks the local cache
    /// first and only makes an HTTP request to Discord's API if there are not enough cached
    /// messages available.
    ///
    /// If limit is greater than 0, restricts the number of messages returned. If limit is 0
    /// or negative, the limit parameter is 200 messages and 72 hours. This is intended for
    /// games to load message history when users open a DM conversation.
    ///
    /// If either user hasn't played the game, there will be no channel between them and
    /// this function will return a 404 `discordpp::ErrorType::HTTPError` error.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void GetUserMessagesWithLimit(FDiscordUniqueID recipientId,
                                  int32 limit,
                                  FDiscordClientUserMessagesWithLimitCallbackDynamic const& cb);

    /// \brief Opens the given message in the Discord client.
    ///
    /// This is useful when a message is sent that contains content that cannot be viewed in
    /// Discord. You can call this function in the click handler for any CTA you show to view the
    /// message in Discord.
    void OpenMessageInDiscord(FDiscordUniqueID messageId,
                              FDiscordClientProvisionalUserMergeRequiredCallback const&
                                provisionalUserMergeRequiredCallback,
                              FDiscordClientOpenMessageInDiscordCallback const& callback);

    /// \brief Opens the given message in the Discord client.
    ///
    /// This is useful when a message is sent that contains content that cannot be viewed in
    /// Discord. You can call this function in the click handler for any CTA you show to view the
    /// message in Discord.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "provisionalUserMergeRequiredCallback"))
    void OpenMessageInDiscord(FDiscordUniqueID messageId,
                              FDiscordClientProvisionalUserMergeRequiredCallbackDynamic const&
                                provisionalUserMergeRequiredCallback,
                              FDiscordClientOpenMessageInDiscordCallbackDynamic const& callback);

    /// \brief Sends a message in a lobby chat to all members of the lobby.
    ///
    /// The content of the message is restricted to 2,000 characters maximum.
    /// See https://discord.com/developers/docs/resources/message for more details.
    ///
    /// The content of the message can also contain special markup for formatting if desired, see
    /// https://discord.com/developers/docs/reference#message-formatting for more details.
    ///
    /// If the lobby is linked to a channel, the message will also be sent to that channel on
    /// Discord.
    void SendLobbyMessage(FDiscordUniqueID lobbyId,
                          FString const& content,
                          FDiscordClientSendUserMessageCallback const& cb);

    /// \brief Sends a message in a lobby chat to all members of the lobby.
    ///
    /// The content of the message is restricted to 2,000 characters maximum.
    /// See https://discord.com/developers/docs/resources/message for more details.
    ///
    /// The content of the message can also contain special markup for formatting if desired, see
    /// https://discord.com/developers/docs/reference#message-formatting for more details.
    ///
    /// If the lobby is linked to a channel, the message will also be sent to that channel on
    /// Discord.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void SendLobbyMessage(FDiscordUniqueID lobbyId,
                          FString const& content,
                          FDiscordClientSendUserMessageCallbackDynamic const& cb);

    /// \brief Variant of Client::SendLobbyMessage that also accepts metadata to be sent with the
    /// message.
    ///
    /// Metadata is just simple string key/value pairs.
    /// An example use case for this might be to include the name of the character that sent a
    /// message.
    void SendLobbyMessageWithMetadata(FDiscordUniqueID lobbyId,
                                      FString const& content,
                                      TMap<FString, FString> const& metadata,
                                      FDiscordClientSendUserMessageCallback const& cb);

    /// \brief Variant of Client::SendLobbyMessage that also accepts metadata to be sent with the
    /// message.
    ///
    /// Metadata is just simple string key/value pairs.
    /// An example use case for this might be to include the name of the character that sent a
    /// message.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void SendLobbyMessageWithMetadata(FDiscordUniqueID lobbyId,
                                      FString const& content,
                                      TMap<FString, FString> const& metadata,
                                      FDiscordClientSendUserMessageCallbackDynamic const& cb);

    /// \brief Sends a direct message to the specified user.
    ///
    /// The content of the message is restricted to 2,000 characters maximum.
    /// See https://discord.com/developers/docs/resources/message for more details.
    ///
    /// The content of the message can also contain special markup for formatting if desired, see
    /// https://discord.com/developers/docs/reference#message-formatting for more details.
    ///
    /// A message can be sent between two users in the following situations:
    /// - Both users are online and in the game and have not blocked each other
    /// - Both users are friends with each other
    /// - Both users share a mutual Discord server and have previously DM'd each other on Discord
    void SendUserMessage(FDiscordUniqueID recipientId,
                         FString const& content,
                         FDiscordClientSendUserMessageCallback const& cb);

    /// \brief Sends a direct message to the specified user.
    ///
    /// The content of the message is restricted to 2,000 characters maximum.
    /// See https://discord.com/developers/docs/resources/message for more details.
    ///
    /// The content of the message can also contain special markup for formatting if desired, see
    /// https://discord.com/developers/docs/reference#message-formatting for more details.
    ///
    /// A message can be sent between two users in the following situations:
    /// - Both users are online and in the game and have not blocked each other
    /// - Both users are friends with each other
    /// - Both users share a mutual Discord server and have previously DM'd each other on Discord
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void SendUserMessage(FDiscordUniqueID recipientId,
                         FString const& content,
                         FDiscordClientSendUserMessageCallbackDynamic const& cb);

    /// \brief Variant of Client::SendUserMessage that also accepts metadata to be sent with the
    /// message.
    ///
    /// Metadata is just simple string key/value pairs.
    /// An example use case for this might be to include the name of the character that sent a
    /// message.
    void SendUserMessageWithMetadata(FDiscordUniqueID recipientId,
                                     FString const& content,
                                     TMap<FString, FString> const& metadata,
                                     FDiscordClientSendUserMessageCallback const& cb);

    /// \brief Variant of Client::SendUserMessage that also accepts metadata to be sent with the
    /// message.
    ///
    /// Metadata is just simple string key/value pairs.
    /// An example use case for this might be to include the name of the character that sent a
    /// message.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void SendUserMessageWithMetadata(FDiscordUniqueID recipientId,
                                     FString const& content,
                                     TMap<FString, FString> const& metadata,
                                     FDiscordClientSendUserMessageCallbackDynamic const& cb);

    /// \brief Sets a callback to be invoked whenever a new message is received in either a lobby or
    /// a DM.
    ///
    /// From the messageId you can fetch the MessageHandle and then the ChannelHandle to determine
    /// the location the message was sent as well.
    ///
    /// If the user has the Discord desktop application open on the same machine as the game, then
    /// they will hear notifications from the Discord application, even though they are able to see
    /// those messages in game. So to avoid double-notifying users, you should call
    /// Client::SetShowingChat whenever the chat is shown or hidden to suppress those duplicate
    /// notifications.
    void SetMessageCreatedCallback(FDiscordClientMessageCreatedCallback const& cb);

    /// \brief Sets a callback to be invoked whenever a new message is received in either a lobby or
    /// a DM.
    ///
    /// From the messageId you can fetch the MessageHandle and then the ChannelHandle to determine
    /// the location the message was sent as well.
    ///
    /// If the user has the Discord desktop application open on the same machine as the game, then
    /// they will hear notifications from the Discord application, even though they are able to see
    /// those messages in game. So to avoid double-notifying users, you should call
    /// Client::SetShowingChat whenever the chat is shown or hidden to suppress those duplicate
    /// notifications.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void SetMessageCreatedCallback(FDiscordClientMessageCreatedCallbackDynamic const& cb);

    /// \brief Sets a callback to be invoked whenever a message is deleted.
    ///
    /// Some messages sent from in game, as well as all messages sent from a connected user's
    /// Discord client can be edited and deleted in the Discord client. So it is valuable to
    /// implement support for this callback so that if a user edits or deletes a message in the
    /// Discord client, it is reflected in game as well.
    void SetMessageDeletedCallback(FDiscordClientMessageDeletedCallback const& cb);

    /// \brief Sets a callback to be invoked whenever a message is deleted.
    ///
    /// Some messages sent from in game, as well as all messages sent from a connected user's
    /// Discord client can be edited and deleted in the Discord client. So it is valuable to
    /// implement support for this callback so that if a user edits or deletes a message in the
    /// Discord client, it is reflected in game as well.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void SetMessageDeletedCallback(FDiscordClientMessageDeletedCallbackDynamic const& cb);

    /// \brief Sets a callback to be invoked whenever a message is edited.
    ///
    /// Some messages sent from in game, as well as all messages sent from a connected user's
    /// Discord client can be edited and deleted in the Discord client. So it is valuable to
    /// implement support for this callback so that if a user edits or deletes a message in the
    /// Discord client, it is reflected in game as well.
    void SetMessageUpdatedCallback(FDiscordClientMessageUpdatedCallback const& cb);

    /// \brief Sets a callback to be invoked whenever a message is edited.
    ///
    /// Some messages sent from in game, as well as all messages sent from a connected user's
    /// Discord client can be edited and deleted in the Discord client. So it is valuable to
    /// implement support for this callback so that if a user edits or deletes a message in the
    /// Discord client, it is reflected in game as well.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void SetMessageUpdatedCallback(FDiscordClientMessageUpdatedCallbackDynamic const& cb);

    /// \brief Sets whether chat messages are currently being shown in the game.
    ///
    /// If the user has the Discord desktop application open on the same machine as the game, then
    /// they will hear notifications from the Discord application, even though they are able to see
    /// those messages in game. So to avoid double-notifying users, you can call this function
    /// whenever the chat is shown or hidden to suppress those duplicate notifications.
    ///
    /// Keep in mind, if the game stops showing chat for a period of time, or the game loses focus
    /// because the user switches to a different app, it is important to call this function again so
    /// that the user's notifications get re-enabled in Discord during this time.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetShowingChat(bool showingChat);

    /// \brief Adds a callback function to be invoked for each new log message generated by the SDK.
    ///
    /// This function explicitly excludes most logs for voice and webrtc activity since those are
    /// generally much noisier and you may want to pick a different log level for those. So it will
    /// instead include logs for things such as lobbies, relationships, presence, and
    /// authentication.
    ///
    /// We strongly recommend invoking this function immediately after constructing the Client
    /// object.
    void AddLogCallback(FDiscordClientLogCallback const& callback,
                        EDiscordLoggingSeverity minSeverity);

    /// \brief Adds a callback function to be invoked for each new log message generated by the SDK.
    ///
    /// This function explicitly excludes most logs for voice and webrtc activity since those are
    /// generally much noisier and you may want to pick a different log level for those. So it will
    /// instead include logs for things such as lobbies, relationships, presence, and
    /// authentication.
    ///
    /// We strongly recommend invoking this function immediately after constructing the Client
    /// object.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "callback"))
    void AddLogCallback(FDiscordClientLogCallbackDynamic const& callback,
                        EDiscordLoggingSeverity minSeverity);

    /// \brief Adds a callback function to be invoked for each new log message generated by the
    /// voice subsystem of the SDK, including the underlying webrtc infrastructure.
    ///
    /// We strongly recommend invoking this function immediately after constructing the Client
    /// object.
    void AddVoiceLogCallback(FDiscordClientLogCallback const& callback,
                             EDiscordLoggingSeverity minSeverity);

    /// \brief Adds a callback function to be invoked for each new log message generated by the
    /// voice subsystem of the SDK, including the underlying webrtc infrastructure.
    ///
    /// We strongly recommend invoking this function immediately after constructing the Client
    /// object.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "callback"))
    void AddVoiceLogCallback(FDiscordClientLogCallbackDynamic const& callback,
                             EDiscordLoggingSeverity minSeverity);

    /// \brief Asynchronously connects the client to Discord.
    ///
    /// If a client is disconnecting, this will wait for the disconnect before reconnecting.
    /// You should use the Client::SetStatusChangedCallback and Client::GetStatus functions to
    /// receive updates on the client status. The Client is only safe to use once the status changes
    /// to Status::Ready.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void Connect();

    /// \brief Asynchronously disconnects the client.
    ///
    /// You can leverage Client::SetStatusChangedCallback and Client::GetStatus to receive updates
    /// on the client status. It is fully disconnected when the status changes to
    /// Client::Status::Disconnected.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void Disconnect();

    /// \brief Returns the current status of the client, see the Status enum for an explanation of
    /// the possible values.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    EDiscordClientStatus GetStatus();

    /// \brief Opens the Connected Games settings in the Discord client, which is where
    /// users can manage their settings related to games using the Discord Social SDK.
    ///
    /// If the client isn't connected or the user is a provisional account, this function does
    /// nothing.
    ///
    /// It is always a no-op for console platforms.
    void OpenConnectedGamesSettingsInDiscord(
      FDiscordClientOpenConnectedGamesSettingsInDiscordCallback const& callback);

    /// \brief Opens the Connected Games settings in the Discord client, which is where
    /// users can manage their settings related to games using the Discord Social SDK.
    ///
    /// If the client isn't connected or the user is a provisional account, this function does
    /// nothing.
    ///
    /// It is always a no-op for console platforms.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "callback"))
    void OpenConnectedGamesSettingsInDiscord(
      FDiscordClientOpenConnectedGamesSettingsInDiscordCallbackDynamic const& callback);

    /// \brief This function is used to set the application ID for the client. This is used to
    /// identify the application to the Discord client. This is used for things like
    /// authentication, rich presence, and activity invites when *not* connected with
    /// Client::Connect. When calling Client::Connect, the application ID is set automatically
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetApplicationId(FDiscordUniqueID applicationId);

    /// \brief Causes logs generated by the SDK to be written to disk in the specified directory.
    ///
    /// This function explicitly excludes most logs for voice and webrtc activity since those are
    /// generally much noisier and you may want to pick a different log level for those. So it will
    /// instead include logs for things such as lobbies, relationships, presence, and
    /// authentication. An empty path defaults to logging alongside the client library. A
    /// minSeverity = LoggingSeverity::None disables logging to a file (also the current default).
    /// The logs will be placed into a file called "discord.log" in the specified directory.
    /// Overwrites any existing discord.log file.
    ///
    /// We strongly recommend invoking this function immediately after constructing the Client
    /// object.
    ///
    /// Returns true if the log file was successfully opened, false otherwise.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    bool SetLogDir(FString const& path, EDiscordLoggingSeverity minSeverity);

    /// \brief Sets a callback function to be invoked whenever the SDKs status changes.
    void SetStatusChangedCallback(FDiscordClientOnStatusChanged const& cb);

    /// \brief Sets a callback function to be invoked whenever the SDKs status changes.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void SetStatusChangedCallback(FDiscordClientOnStatusChangedDynamic const& cb);

    /// \brief Causes logs generated by the voice subsystem of the SDK to be written to disk in the
    /// specified directory.
    ///
    /// These logs will be in a file like discord-webrtc_0, and if they grow to big will be rotated
    /// and the number incremented. If the log files already exist the old ones will be renamed to
    /// discord-last-webrtc_0.
    ///
    /// An empty path defaults to logging alongside the client library.
    /// A minSeverity = LoggingSeverity::None disables logging to a file (also the current default).
    ///
    /// WARNING: This function MUST be invoked immediately after constructing the Client object!
    /// It will print out a warning if invoked too late.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void SetVoiceLogDir(FString const& path, EDiscordLoggingSeverity minSeverity);

    /// \brief Joins the user to the specified lobby, creating one if it does not exist.
    ///
    /// The lobby is specified by the supplied string, which should be a hard to guess secret
    /// generated by the game. All users who join the lobby with the same secret will be placed in
    /// the same lobby.
    ///
    /// For exchanging the secret, we strongly encourage looking into the activity invite and rich
    /// presence systems which provide a way to include a secret string that only accepted party
    /// members are able to see.
    ///
    /// As with server created lobbies, client created lobbies auto-delete once they have been idle
    /// for a few minutes (which currently defaults to 5 minutes). A lobby is idle if no users are
    /// connected to it.
    ///
    /// This function shouldn't be used for long lived lobbies. The "secret" value expires after ~30
    /// days, at which point the existing lobby cannot be joined and a new one would be created
    /// instead.
    void CreateOrJoinLobby(FString const& secret,
                           FDiscordClientCreateOrJoinLobbyCallback const& callback);

    /// \brief Joins the user to the specified lobby, creating one if it does not exist.
    ///
    /// The lobby is specified by the supplied string, which should be a hard to guess secret
    /// generated by the game. All users who join the lobby with the same secret will be placed in
    /// the same lobby.
    ///
    /// For exchanging the secret, we strongly encourage looking into the activity invite and rich
    /// presence systems which provide a way to include a secret string that only accepted party
    /// members are able to see.
    ///
    /// As with server created lobbies, client created lobbies auto-delete once they have been idle
    /// for a few minutes (which currently defaults to 5 minutes). A lobby is idle if no users are
    /// connected to it.
    ///
    /// This function shouldn't be used for long lived lobbies. The "secret" value expires after ~30
    /// days, at which point the existing lobby cannot be joined and a new one would be created
    /// instead.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "callback"))
    void CreateOrJoinLobby(FString const& secret,
                           FDiscordClientCreateOrJoinLobbyCallbackDynamic const& callback);

    /// \brief Variant of Client::CreateOrJoinLobby that also accepts developer-supplied metadata.
    ///
    /// Metadata is just simple string key/value pairs.
    /// An example use case for this might be to the internal game ID of the user of each lobby so
    /// all members of the lobby can have a mapping of discord IDs to game IDs. Subsequent calls to
    /// CreateOrJoinLobby will overwrite the metadata for the lobby and member.
    void CreateOrJoinLobbyWithMetadata(FString const& secret,
                                       TMap<FString, FString> const& lobbyMetadata,
                                       TMap<FString, FString> const& memberMetadata,
                                       FDiscordClientCreateOrJoinLobbyCallback const& callback);

    /// \brief Variant of Client::CreateOrJoinLobby that also accepts developer-supplied metadata.
    ///
    /// Metadata is just simple string key/value pairs.
    /// An example use case for this might be to the internal game ID of the user of each lobby so
    /// all members of the lobby can have a mapping of discord IDs to game IDs. Subsequent calls to
    /// CreateOrJoinLobby will overwrite the metadata for the lobby and member.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "callback"))
    void CreateOrJoinLobbyWithMetadata(
      FString const& secret,
      TMap<FString, FString> const& lobbyMetadata,
      TMap<FString, FString> const& memberMetadata,
      FDiscordClientCreateOrJoinLobbyCallbackDynamic const& callback);

    /// \brief Fetches all of the channels that the current user can access in the given guild.
    /// Channels are sorted by their `position` field, which matches what you see in the Discord
    /// client.
    ///
    /// The purpose of this is to power the channel linking flow for linking a Discord channel to an
    /// in-game lobby. So this function can be used to power a UI to let the user pick which channel
    /// to link to once they have picked a guild. See the docs on LobbyHandle for more information.
    void GetGuildChannels(FDiscordUniqueID guildId,
                          FDiscordClientGetGuildChannelsCallback const& cb);

    /// \brief Fetches all of the channels that the current user can access in the given guild.
    /// Channels are sorted by their `position` field, which matches what you see in the Discord
    /// client.
    ///
    /// The purpose of this is to power the channel linking flow for linking a Discord channel to an
    /// in-game lobby. So this function can be used to power a UI to let the user pick which channel
    /// to link to once they have picked a guild. See the docs on LobbyHandle for more information.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void GetGuildChannels(FDiscordUniqueID guildId,
                          FDiscordClientGetGuildChannelsCallbackDynamic const& cb);

    /// \brief Returns a reference to the Discord lobby object for the given ID.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    UDiscordLobbyHandle* GetLobbyHandle(FDiscordUniqueID lobbyId);

    /// \brief Returns a list of all the lobbies that the user is a member of and the SDK has
    /// loaded.
    ///
    /// Lobbies are optimistically loaded when the SDK starts but in some cases may not be available
    /// immediately after the SDK status changes to Status::Ready.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    TArray<FDiscordUniqueID> GetLobbyIds();

    /// \brief Fetches all of the guilds (also known as Discord servers) that the current user is a
    /// member of.
    ///
    /// The purpose of this is to power the channel linking flow for linking a Discord channel
    /// to an in-game lobby. So this function can be used to power a UI to let the user which guild
    /// to link to. See the docs on LobbyHandle for more information.
    void GetUserGuilds(FDiscordClientGetUserGuildsCallback const& cb);

    /// \brief Fetches all of the guilds (also known as Discord servers) that the current user is a
    /// member of.
    ///
    /// The purpose of this is to power the channel linking flow for linking a Discord channel
    /// to an in-game lobby. So this function can be used to power a UI to let the user which guild
    /// to link to. See the docs on LobbyHandle for more information.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void GetUserGuilds(FDiscordClientGetUserGuildsCallbackDynamic const& cb);

    /// \brief Invites the current user to the Discord guild of the channel that is linked to the
    /// specified lobby. The user is forwarded to the Discord client with the resulting invite url,
    /// upon which the user can decide to accept or decline that invite.
    ///
    /// On console platforms, the user is not navigated to any Discord client, so the invite url
    /// should be presented to the user in some way, so they can use it.
    void JoinLinkedLobbyGuild(FDiscordUniqueID lobbyId,
                              FDiscordClientProvisionalUserMergeRequiredCallback const&
                                provisionalUserMergeRequiredCallback,
                              FDiscordClientJoinLinkedLobbyGuildCallback const& callback);

    /// \brief Invites the current user to the Discord guild of the channel that is linked to the
    /// specified lobby. The user is forwarded to the Discord client with the resulting invite url,
    /// upon which the user can decide to accept or decline that invite.
    ///
    /// On console platforms, the user is not navigated to any Discord client, so the invite url
    /// should be presented to the user in some way, so they can use it.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "provisionalUserMergeRequiredCallback"))
    void JoinLinkedLobbyGuild(FDiscordUniqueID lobbyId,
                              FDiscordClientProvisionalUserMergeRequiredCallbackDynamic const&
                                provisionalUserMergeRequiredCallback,
                              FDiscordClientJoinLinkedLobbyGuildCallbackDynamic const& callback);

    /// \brief Removes the current user from the specified lobby.
    ///
    /// Only lobbies that contain a "secret" can be left.
    /// In other words, only lobbies created with Client::CreateOrJoinLobby can be left.
    /// Lobbies created using the server API may not be manipulated by clients, so you must
    /// use the server API to remove them too.
    void LeaveLobby(FDiscordUniqueID lobbyId, FDiscordClientLeaveLobbyCallback const& callback);

    /// \brief Removes the current user from the specified lobby.
    ///
    /// Only lobbies that contain a "secret" can be left.
    /// In other words, only lobbies created with Client::CreateOrJoinLobby can be left.
    /// Lobbies created using the server API may not be manipulated by clients, so you must
    /// use the server API to remove them too.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "callback"))
    void LeaveLobby(FDiscordUniqueID lobbyId,
                    FDiscordClientLeaveLobbyCallbackDynamic const& callback);

    /// \brief Links the specified channel on Discord to the specified in-game lobby.
    ///
    /// Any message sent in one will be copied over to the other!
    /// See the docs on LobbyHandle for more information.
    void LinkChannelToLobby(FDiscordUniqueID lobbyId,
                            FDiscordUniqueID channelId,
                            FDiscordClientLinkOrUnlinkChannelCallback const& callback);

    /// \brief Links the specified channel on Discord to the specified in-game lobby.
    ///
    /// Any message sent in one will be copied over to the other!
    /// See the docs on LobbyHandle for more information.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "callback"))
    void LinkChannelToLobby(FDiscordUniqueID lobbyId,
                            FDiscordUniqueID channelId,
                            FDiscordClientLinkOrUnlinkChannelCallbackDynamic const& callback);

    /// \brief Sets a callback to be invoked when a lobby "becomes available" to the client.
    ///
    /// A lobby can become available in a few situations:
    /// - A new lobby is created and the current user is a member of it
    /// - The current user is added to an existing lobby
    /// - A lobby recovers after a backend crash and is available once again
    ///
    /// This means that the LobbyCreated callback can be invoked more than once in a single session!
    /// Generally though it should never be invoked twice in a row. For example if a lobby crashes
    /// or a user is removed from the lobby, you should expect to have the LobbyDeleted callback
    /// invoked first.
    void SetLobbyCreatedCallback(FDiscordClientLobbyCreatedCallback const& cb);

    /// \brief Sets a callback to be invoked when a lobby "becomes available" to the client.
    ///
    /// A lobby can become available in a few situations:
    /// - A new lobby is created and the current user is a member of it
    /// - The current user is added to an existing lobby
    /// - A lobby recovers after a backend crash and is available once again
    ///
    /// This means that the LobbyCreated callback can be invoked more than once in a single session!
    /// Generally though it should never be invoked twice in a row. For example if a lobby crashes
    /// or a user is removed from the lobby, you should expect to have the LobbyDeleted callback
    /// invoked first.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void SetLobbyCreatedCallback(FDiscordClientLobbyCreatedCallbackDynamic const& cb);

    /// \brief Sets a callback to be invoked when a lobby is no longer available.
    ///
    /// This callback can be invoked in a number of situations:
    /// - A lobby the user is a member of is deleted
    /// - The current user is removed from a lobby
    /// - There is a backend crash that causes the lobby to be unavailable for all users
    ///
    /// This means that this callback might be invoked even though the lobby still exists for other
    /// users!
    void SetLobbyDeletedCallback(FDiscordClientLobbyDeletedCallback const& cb);

    /// \brief Sets a callback to be invoked when a lobby is no longer available.
    ///
    /// This callback can be invoked in a number of situations:
    /// - A lobby the user is a member of is deleted
    /// - The current user is removed from a lobby
    /// - There is a backend crash that causes the lobby to be unavailable for all users
    ///
    /// This means that this callback might be invoked even though the lobby still exists for other
    /// users!
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void SetLobbyDeletedCallback(FDiscordClientLobbyDeletedCallbackDynamic const& cb);

    /// \brief Sets a callback function to be invoked whenever a user is added to a lobby.
    ///
    /// This callback will not be invoked when the current user is added to a lobby, instead the
    /// LobbyCreated callback will be invoked. Additionally, the SDK separates membership in a lobby
    /// from whether a user is connected to a lobby. So a user being added does not necessarily mean
    /// they are online and in the lobby at that moment, just that they have permission to connect
    /// to that lobby.
    void SetLobbyMemberAddedCallback(FDiscordClientLobbyMemberAddedCallback const& cb);

    /// \brief Sets a callback function to be invoked whenever a user is added to a lobby.
    ///
    /// This callback will not be invoked when the current user is added to a lobby, instead the
    /// LobbyCreated callback will be invoked. Additionally, the SDK separates membership in a lobby
    /// from whether a user is connected to a lobby. So a user being added does not necessarily mean
    /// they are online and in the lobby at that moment, just that they have permission to connect
    /// to that lobby.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void SetLobbyMemberAddedCallback(FDiscordClientLobbyMemberAddedCallbackDynamic const& cb);

    /// \brief Sets a callback function to be invoked whenever a member of a lobby is removed and
    /// can no longer connect to it.
    ///
    /// This callback will not be invoked when the current user is removed from a lobby, instead
    /// LobbyDeleted callback will be invoked. Additionally this is not invoked when a user simply
    /// exits the game. That would cause the LobbyMemberUpdatedCallback to be invoked, and the
    /// LobbyMemberHandle object will indicate they are not connected now.
    void SetLobbyMemberRemovedCallback(FDiscordClientLobbyMemberRemovedCallback const& cb);

    /// \brief Sets a callback function to be invoked whenever a member of a lobby is removed and
    /// can no longer connect to it.
    ///
    /// This callback will not be invoked when the current user is removed from a lobby, instead
    /// LobbyDeleted callback will be invoked. Additionally this is not invoked when a user simply
    /// exits the game. That would cause the LobbyMemberUpdatedCallback to be invoked, and the
    /// LobbyMemberHandle object will indicate they are not connected now.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void SetLobbyMemberRemovedCallback(FDiscordClientLobbyMemberRemovedCallbackDynamic const& cb);

    /// \brief Sets a callback function to be invoked whenever a member of a lobby is changed.
    ///
    /// This is invoked when:
    /// - The user connects or disconnects
    /// - The metadata of the member is changed
    void SetLobbyMemberUpdatedCallback(FDiscordClientLobbyMemberUpdatedCallback const& cb);

    /// \brief Sets a callback function to be invoked whenever a member of a lobby is changed.
    ///
    /// This is invoked when:
    /// - The user connects or disconnects
    /// - The metadata of the member is changed
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void SetLobbyMemberUpdatedCallback(FDiscordClientLobbyMemberUpdatedCallbackDynamic const& cb);

    /// \brief Sets a callback to be invoked when a lobby is edited, for example if the lobby's
    /// metadata is changed.
    void SetLobbyUpdatedCallback(FDiscordClientLobbyUpdatedCallback const& cb);

    /// \brief Sets a callback to be invoked when a lobby is edited, for example if the lobby's
    /// metadata is changed.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void SetLobbyUpdatedCallback(FDiscordClientLobbyUpdatedCallbackDynamic const& cb);

    /// \brief Removes any existing channel link from the specified lobby.
    ///
    /// See the docs on LobbyHandle for more information.
    /// A lobby can be unlinked by any user with the LobbyMemberFlags::CanLinkLobby flag, they do
    /// not need to have any permissions on the Discord channel in order to sever the in-game link.
    void UnlinkChannelFromLobby(FDiscordUniqueID lobbyId,
                                FDiscordClientLinkOrUnlinkChannelCallback const& callback);

    /// \brief Removes any existing channel link from the specified lobby.
    ///
    /// See the docs on LobbyHandle for more information.
    /// A lobby can be unlinked by any user with the LobbyMemberFlags::CanLinkLobby flag, they do
    /// not need to have any permissions on the Discord channel in order to sever the in-game link.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "callback"))
    void UnlinkChannelFromLobby(FDiscordUniqueID lobbyId,
                                FDiscordClientLinkOrUnlinkChannelCallbackDynamic const& callback);

    /// \brief Checks whether the Discord mobile app is installed on this device.
    /// On desktop platforms, always returns false.
    ///
    /// This check does not require a client connection and can be called at any time.
    ///
    /// This can be used to provide UI hints to users about whether they can authorize via the
    /// Discord app, or whether they will need to use a web browser flow.
    ///
    /// Platform Requirements:
    /// - iOS: Your app must include "discord" in the LSApplicationQueriesSchemes array
    ///   in your Info.plist for this check to work correctly.
    /// - Android: Your app must include "com.discord" in the `queries` element
    ///   in your AndroidManifest.xml (required for Android 11+).
    void IsDiscordAppInstalled(FDiscordClientIsDiscordAppInstalledCallback const& callback);

    /// \brief Checks whether the Discord mobile app is installed on this device.
    /// On desktop platforms, always returns false.
    ///
    /// This check does not require a client connection and can be called at any time.
    ///
    /// This can be used to provide UI hints to users about whether they can authorize via the
    /// Discord app, or whether they will need to use a web browser flow.
    ///
    /// Platform Requirements:
    /// - iOS: Your app must include "discord" in the LSApplicationQueriesSchemes array
    ///   in your Info.plist for this check to work correctly.
    /// - Android: Your app must include "com.discord" in the `queries` element
    ///   in your AndroidManifest.xml (required for Android 11+).
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "callback"))
    void IsDiscordAppInstalled(FDiscordClientIsDiscordAppInstalledCallbackDynamic const& callback);

    /// \brief Accepts an activity invite that the current user has received.
    ///
    /// The given callback will be invoked with the join secret for the activity, which can be used
    /// to join the user to the game's internal party system for example.
    /// This join secret comes from the other user's rich presence activity.
    void AcceptActivityInvite(UDiscordActivityInvite* invite,
                              FDiscordClientAcceptActivityInviteCallback const& cb);

    /// \brief Accepts an activity invite that the current user has received.
    ///
    /// The given callback will be invoked with the join secret for the activity, which can be used
    /// to join the user to the game's internal party system for example.
    /// This join secret comes from the other user's rich presence activity.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void AcceptActivityInvite(UDiscordActivityInvite* invite,
                              FDiscordClientAcceptActivityInviteCallbackDynamic const& cb);

    /// \brief Clears the right presence for the current user.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void ClearRichPresence();

    /// \brief When a user accepts an activity invite for your game within the Discord client,
    /// Discord needs to know how to launch the game for that user. This function allows you to
    /// register a command that Discord will run to launch your game. You should invoke this when
    /// the SDK starts up so that if the user in the future tries to join from Discord the game will
    /// be able to be launched for them. Returns true if the command was successfully registered,
    /// false otherwise.
    ///
    /// On Windows and Linux, this command should be a path to an executable. It also supports any
    /// launch parameters that may be needed, like
    /// "C:\path\to my\game.exe" --full-screen --no-hax
    /// If you pass an empty string in for the command, the SDK will register the current running
    /// executable. To launch the game from a custom protocol like my-awesome-game://, pass that in
    /// as an argument of the executable that should be launched by that protocol. For example,
    /// "C:\path\to my\game.exe" my-awesome-game://
    ///
    /// On macOS, due to the way Discord registers executables, your game needs to be bundled for
    /// this command to work. That means it should be a .app. You can pass a custom protocol like
    /// my-awesome-game:// as the custom command, but *not* a path to an executable. If you pass an
    /// empty string in for the command, the SDK will register the current running bundle, if any.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    bool RegisterLaunchCommand(FDiscordUniqueID applicationId, FString const& command);

    /// \brief When a user accepts an activity invite for your game within the Discord client,
    /// Discord needs to know how to launch the game for that user. For steam games, this function
    /// allows you to indicate to Discord what the steam game ID is. You should invoke this when the
    /// SDK starts up so that if the user in the future tries to join from Discord the game will be
    /// able to be launched for them. Returns true if the command was successfully registered, false
    /// otherwise.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    bool RegisterLaunchSteamApplication(FDiscordUniqueID applicationId, int32 steamAppId);

    /// \brief Sends a Discord activity invite to the specified user.
    ///
    /// The invite is sent as a message on Discord, which means it can be sent if any
    /// of the following are true:
    /// - Both users are online and in the game and have not blocked each other
    /// - Both users are friends with each other
    /// - Both users share a mutual Discord server and have previously DM'd each other on Discord
    ///
    /// You can optionally include some message content to include in the message containing the
    /// invite, but it's ok to pass an empty string too.
    void SendActivityInvite(FDiscordUniqueID userId,
                            FString const& content,
                            FDiscordClientSendActivityInviteCallback const& cb);

    /// \brief Sends a Discord activity invite to the specified user.
    ///
    /// The invite is sent as a message on Discord, which means it can be sent if any
    /// of the following are true:
    /// - Both users are online and in the game and have not blocked each other
    /// - Both users are friends with each other
    /// - Both users share a mutual Discord server and have previously DM'd each other on Discord
    ///
    /// You can optionally include some message content to include in the message containing the
    /// invite, but it's ok to pass an empty string too.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void SendActivityInvite(FDiscordUniqueID userId,
                            FString const& content,
                            FDiscordClientSendActivityInviteCallbackDynamic const& cb);

    /// \brief Requests to join the activity of the specified user.
    ///
    /// This can be called whenever the target user has a rich presence activity for the current
    /// game and that activity has space for another user to join them.
    ///
    /// That user will basically receive an activity invite which they can accept or reject.
    void SendActivityJoinRequest(FDiscordUniqueID userId,
                                 FDiscordClientSendActivityInviteCallback const& cb);

    /// \brief Requests to join the activity of the specified user.
    ///
    /// This can be called whenever the target user has a rich presence activity for the current
    /// game and that activity has space for another user to join them.
    ///
    /// That user will basically receive an activity invite which they can accept or reject.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void SendActivityJoinRequest(FDiscordUniqueID userId,
                                 FDiscordClientSendActivityInviteCallbackDynamic const& cb);

    /// \brief When another user requests to join the current user's party, this function is called
    /// to to allow that user to join. Specifically this will send the original user an activity
    /// invite which they then need to accept again.
    void SendActivityJoinRequestReply(UDiscordActivityInvite* invite,
                                      FDiscordClientSendActivityInviteCallback const& cb);

    /// \brief When another user requests to join the current user's party, this function is called
    /// to to allow that user to join. Specifically this will send the original user an activity
    /// invite which they then need to accept again.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void SendActivityJoinRequestReply(UDiscordActivityInvite* invite,
                                      FDiscordClientSendActivityInviteCallbackDynamic const& cb);

    /// \brief Sets a callback function that is invoked when the current user receives an activity
    /// invite from another user.
    ///
    /// These invites are always sent as messages, so the SDK is parsing these
    /// messages to look for invites and invokes this callback instead. The message create callback
    /// will not be invoked for these messages. The invite object contains all the necessary
    /// information to identity the invite, which you can later pass to
    /// Client::AcceptActivityInvite.
    void SetActivityInviteCreatedCallback(FDiscordClientActivityInviteCallback const& cb);

    /// \brief Sets a callback function that is invoked when the current user receives an activity
    /// invite from another user.
    ///
    /// These invites are always sent as messages, so the SDK is parsing these
    /// messages to look for invites and invokes this callback instead. The message create callback
    /// will not be invoked for these messages. The invite object contains all the necessary
    /// information to identity the invite, which you can later pass to
    /// Client::AcceptActivityInvite.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void SetActivityInviteCreatedCallback(FDiscordClientActivityInviteCallbackDynamic const& cb);

    /// \brief Sets a callback function that is invoked when an existing activity invite changes.
    /// Currently, the only thing that changes on an activity invite is its validity. If the sender
    /// goes offline or exits the party the receiver was invited to, the invite is no longer
    /// joinable. It is possible for an invalid invite to go from invalid to valid if the sender
    /// rejoins the activity.
    void SetActivityInviteUpdatedCallback(FDiscordClientActivityInviteCallback const& cb);

    /// \brief Sets a callback function that is invoked when an existing activity invite changes.
    /// Currently, the only thing that changes on an activity invite is its validity. If the sender
    /// goes offline or exits the party the receiver was invited to, the invite is no longer
    /// joinable. It is possible for an invalid invite to go from invalid to valid if the sender
    /// rejoins the activity.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void SetActivityInviteUpdatedCallback(FDiscordClientActivityInviteCallbackDynamic const& cb);

    /// \brief Sets a callback function that is invoked when the current user also has Discord
    /// running on their computer and they accept an activity invite in the Discord client.
    ///
    /// This callback is invoked with the join secret from the activity rich presence, which you can
    /// use to join them to the game's internal party system. See Activity for more information on
    /// invites.
    void SetActivityJoinCallback(FDiscordClientActivityJoinCallback const& cb);

    /// \brief Sets a callback function that is invoked when the current user also has Discord
    /// running on their computer and they accept an activity invite in the Discord client.
    ///
    /// This callback is invoked with the join secret from the activity rich presence, which you can
    /// use to join them to the game's internal party system. See Activity for more information on
    /// invites.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void SetActivityJoinCallback(FDiscordClientActivityJoinCallbackDynamic const& cb);

    /// \brief Sets a callback function that is invoked when the current user also has Discord
    /// running on their computer and they accept an activity invite in the Discord client.
    ///
    /// This callback is invoked with the join secret from the activity rich presence, which you can
    /// use to join them to the game's internal party system. See Activity for more information on
    /// invites.
    void SetActivityJoinWithApplicationCallback(
      FDiscordClientActivityJoinWithApplicationCallback const& cb);

    /// \brief Sets a callback function that is invoked when the current user also has Discord
    /// running on their computer and they accept an activity invite in the Discord client.
    ///
    /// This callback is invoked with the join secret from the activity rich presence, which you can
    /// use to join them to the game's internal party system. See Activity for more information on
    /// invites.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void SetActivityJoinWithApplicationCallback(
      FDiscordClientActivityJoinWithApplicationCallbackDynamic const& cb);

    /// \brief Sets whether a user is online/invisible/idle/dnd on Discord.
    void SetOnlineStatus(EDiscordStatusType status,
                         FDiscordClientUpdateStatusCallback const& callback);

    /// \brief Sets whether a user is online/invisible/idle/dnd on Discord.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "callback"))
    void SetOnlineStatus(EDiscordStatusType status,
                         FDiscordClientUpdateStatusCallbackDynamic const& callback);

    /// \brief Updates the rich presence for the current user.
    ///
    /// You should use rich presence so that other users on Discord know this user is playing a game
    /// and you can include some hints of what they are playing such as a character name or map
    /// name. Rich presence also enables Discord game invites to work too!
    ///
    /// Note: On Desktop, rich presence can be set before calling Client::Connect, but it will be
    /// cleared if the Client connects. When Client is not connected, this sets the rich presence in
    /// the current user's Discord client when available.
    ///
    /// See the docs on the Activity struct for more details.
    ///
    /// Note: The Activity object here is a partial object, fields such as name, and applicationId
    /// cannot be set and will be overwritten by the SDK. See
    /// https://discord.com/developers/docs/rich-presence/using-with-the-game-sdk#partial-activity-struct
    /// for more information.
    void UpdateRichPresence(UDiscordActivity* activity,
                            FDiscordClientUpdateRichPresenceCallback const& cb);

    /// \brief Updates the rich presence for the current user.
    ///
    /// You should use rich presence so that other users on Discord know this user is playing a game
    /// and you can include some hints of what they are playing such as a character name or map
    /// name. Rich presence also enables Discord game invites to work too!
    ///
    /// Note: On Desktop, rich presence can be set before calling Client::Connect, but it will be
    /// cleared if the Client connects. When Client is not connected, this sets the rich presence in
    /// the current user's Discord client when available.
    ///
    /// See the docs on the Activity struct for more details.
    ///
    /// Note: The Activity object here is a partial object, fields such as name, and applicationId
    /// cannot be set and will be overwritten by the SDK. See
    /// https://discord.com/developers/docs/rich-presence/using-with-the-game-sdk#partial-activity-struct
    /// for more information.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void UpdateRichPresence(UDiscordActivity* activity,
                            FDiscordClientUpdateRichPresenceCallbackDynamic const& cb);

    /// \brief Accepts an incoming Discord friend request from the target user.
    ///
    /// Fails if the target user has not sent a Discord friend request to the current user, meaning
    /// that the Discord relationship type between the users must be
    /// RelationshipType::PendingIncoming.
    void AcceptDiscordFriendRequest(FDiscordUniqueID userId,
                                    FDiscordClientUpdateRelationshipCallback const& cb);

    /// \brief Accepts an incoming Discord friend request from the target user.
    ///
    /// Fails if the target user has not sent a Discord friend request to the current user, meaning
    /// that the Discord relationship type between the users must be
    /// RelationshipType::PendingIncoming.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void AcceptDiscordFriendRequest(FDiscordUniqueID userId,
                                    FDiscordClientUpdateRelationshipCallbackDynamic const& cb);

    /// \brief Accepts an incoming game friend request from the target user.
    ///
    /// Fails if the target user has not sent a game friend request to the current user, meaning
    /// that the game relationship type between the users must be RelationshipType::PendingIncoming.
    void AcceptGameFriendRequest(FDiscordUniqueID userId,
                                 FDiscordClientUpdateRelationshipCallback const& cb);

    /// \brief Accepts an incoming game friend request from the target user.
    ///
    /// Fails if the target user has not sent a game friend request to the current user, meaning
    /// that the game relationship type between the users must be RelationshipType::PendingIncoming.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void AcceptGameFriendRequest(FDiscordUniqueID userId,
                                 FDiscordClientUpdateRelationshipCallbackDynamic const& cb);

    /// \brief Blocks the target user so that they cannot send the user friend or activity invites
    /// and cannot message them anymore.
    ///
    /// Blocking a user will also remove any existing relationship
    /// between the two users, and persists across games, so blocking a user in one game or on
    /// Discord will block them in all other games and on Discord as well.
    void BlockUser(FDiscordUniqueID userId, FDiscordClientUpdateRelationshipCallback const& cb);

    /// \brief Blocks the target user so that they cannot send the user friend or activity invites
    /// and cannot message them anymore.
    ///
    /// Blocking a user will also remove any existing relationship
    /// between the two users, and persists across games, so blocking a user in one game or on
    /// Discord will block them in all other games and on Discord as well.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void BlockUser(FDiscordUniqueID userId,
                   FDiscordClientUpdateRelationshipCallbackDynamic const& cb);

    /// \brief Cancels an outgoing Discord friend request to the target user.
    ///
    /// Fails if a Discord friend request has not been sent to the target user, meaning
    /// that the Discord relationship type between the users must be
    /// RelationshipType::PendingOutgoing.
    void CancelDiscordFriendRequest(FDiscordUniqueID userId,
                                    FDiscordClientUpdateRelationshipCallback const& cb);

    /// \brief Cancels an outgoing Discord friend request to the target user.
    ///
    /// Fails if a Discord friend request has not been sent to the target user, meaning
    /// that the Discord relationship type between the users must be
    /// RelationshipType::PendingOutgoing.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void CancelDiscordFriendRequest(FDiscordUniqueID userId,
                                    FDiscordClientUpdateRelationshipCallbackDynamic const& cb);

    /// \brief Cancels an outgoing game friend request to the target user.
    ///
    /// Fails if a game friend request has not been sent to the target user, meaning
    /// that the game relationship type between the users must be RelationshipType::PendingOutgoing.
    void CancelGameFriendRequest(FDiscordUniqueID userId,
                                 FDiscordClientUpdateRelationshipCallback const& cb);

    /// \brief Cancels an outgoing game friend request to the target user.
    ///
    /// Fails if a game friend request has not been sent to the target user, meaning
    /// that the game relationship type between the users must be RelationshipType::PendingOutgoing.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void CancelGameFriendRequest(FDiscordUniqueID userId,
                                 FDiscordClientUpdateRelationshipCallbackDynamic const& cb);

    /// \brief Returns the RelationshipHandle that corresponds to the relationship between the
    /// current user and the given user.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    UDiscordRelationshipHandle* GetRelationshipHandle(FDiscordUniqueID userId);

    /// \brief Returns a list of all of the relationships the current user has with others,
    /// including all Discord relationships and all Game relationships for the current game.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    TArray<UDiscordRelationshipHandle*> GetRelationships();

    /// \brief Returns a list of relationships that belong to the specified relationship group type.
    /// Relationships are logically partitioned into groups based on online status and game
    /// activity:
    /// - OnlinePlayingGame: Users who are online and currently playing the game
    /// - OnlineElsewhere: Users who are online but not playing the game (users who have played the
    /// game before are sorted to the top)
    /// - Offline: Users who are offline
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    TArray<UDiscordRelationshipHandle*> GetRelationshipsByGroup(
      EDiscordRelationshipGroupType groupType);

    /// \brief Declines an incoming Discord friend request from the target user.
    ///
    /// Fails if the target user has not sent a Discord friend request to the current user, meaning
    /// that the Discord relationship type between the users must be
    /// RelationshipType::PendingIncoming.
    void RejectDiscordFriendRequest(FDiscordUniqueID userId,
                                    FDiscordClientUpdateRelationshipCallback const& cb);

    /// \brief Declines an incoming Discord friend request from the target user.
    ///
    /// Fails if the target user has not sent a Discord friend request to the current user, meaning
    /// that the Discord relationship type between the users must be
    /// RelationshipType::PendingIncoming.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void RejectDiscordFriendRequest(FDiscordUniqueID userId,
                                    FDiscordClientUpdateRelationshipCallbackDynamic const& cb);

    /// \brief Declines an incoming game friend request from the target user.
    ///
    /// Fails if the target user has not sent a game friend request to the current user, meaning
    /// that the game relationship type between the users must be RelationshipType::PendingIncoming.
    void RejectGameFriendRequest(FDiscordUniqueID userId,
                                 FDiscordClientUpdateRelationshipCallback const& cb);

    /// \brief Declines an incoming game friend request from the target user.
    ///
    /// Fails if the target user has not sent a game friend request to the current user, meaning
    /// that the game relationship type between the users must be RelationshipType::PendingIncoming.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void RejectGameFriendRequest(FDiscordUniqueID userId,
                                 FDiscordClientUpdateRelationshipCallbackDynamic const& cb);

    /// \brief Removes any friendship between the current user and the target user. This function
    /// will remove BOTH any Discord friendship and any game friendship between the users.
    ///
    /// Fails if the target user is not currently a Discord OR game friend with the current user.
    void RemoveDiscordAndGameFriend(FDiscordUniqueID userId,
                                    FDiscordClientUpdateRelationshipCallback const& cb);

    /// \brief Removes any friendship between the current user and the target user. This function
    /// will remove BOTH any Discord friendship and any game friendship between the users.
    ///
    /// Fails if the target user is not currently a Discord OR game friend with the current user.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void RemoveDiscordAndGameFriend(FDiscordUniqueID userId,
                                    FDiscordClientUpdateRelationshipCallbackDynamic const& cb);

    /// \brief Removes any game friendship between the current user and the target user.
    ///
    /// Fails if the target user is not currently a game friend with the current user.
    void RemoveGameFriend(FDiscordUniqueID userId,
                          FDiscordClientUpdateRelationshipCallback const& cb);

    /// \brief Removes any game friendship between the current user and the target user.
    ///
    /// Fails if the target user is not currently a game friend with the current user.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void RemoveGameFriend(FDiscordUniqueID userId,
                          FDiscordClientUpdateRelationshipCallbackDynamic const& cb);

    /// \brief Searches all of your friends by both username and display name, returning
    /// a list of all friends that match the search string.
    ///
    /// Under the hood uses the Levenshtein distance algorithm.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    TArray<UDiscordUserHandle*> SearchFriendsByUsername(FString const& searchStr);

    /// \brief Sends a Discord friend request to the target user.
    ///
    /// The target user is identified by their Discord unique username (not their DisplayName).
    ///
    /// After the friend request is sent, each user will have a new Discord relationship created.
    /// For the current user the RelationshipHandle::DiscordRelationshipType will be
    /// RelationshipType::PendingOutgoing and for the target user it will be
    /// RelationshipType::PendingIncoming.
    ///
    /// If the current user already has received a Discord friend request from the target user
    /// (meaning RelationshipHandle::DiscordRelationshipType is RelationshipType::PendingIncoming),
    /// then the two users will become Discord friends.
    ///
    /// See RelationshipHandle for more information on the difference between Discord and Game
    /// relationships.
    void SendDiscordFriendRequest(FString const& username,
                                  FDiscordClientSendFriendRequestCallback const& cb);

    /// \brief Sends a Discord friend request to the target user.
    ///
    /// The target user is identified by their Discord unique username (not their DisplayName).
    ///
    /// After the friend request is sent, each user will have a new Discord relationship created.
    /// For the current user the RelationshipHandle::DiscordRelationshipType will be
    /// RelationshipType::PendingOutgoing and for the target user it will be
    /// RelationshipType::PendingIncoming.
    ///
    /// If the current user already has received a Discord friend request from the target user
    /// (meaning RelationshipHandle::DiscordRelationshipType is RelationshipType::PendingIncoming),
    /// then the two users will become Discord friends.
    ///
    /// See RelationshipHandle for more information on the difference between Discord and Game
    /// relationships.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void SendDiscordFriendRequest(FString const& username,
                                  FDiscordClientSendFriendRequestCallbackDynamic const& cb);

    /// \brief Sends a Discord friend request to the target user.
    ///
    /// The target user is identified by their Discord ID.
    ///
    /// After the friend request is sent, each user will have a new Discord relationship created.
    /// For the current user the RelationshipHandle::DiscordRelationshipType will be
    /// RelationshipType::PendingOutgoing and for the target user it will be
    /// RelationshipType::PendingIncoming.
    ///
    /// If the current user already has received a Discord friend request from the target user
    /// (meaning RelationshipHandle::DiscordRelationshipType is RelationshipType::PendingIncoming),
    /// then the two users will become Discord friends.
    ///
    /// See RelationshipHandle for more information on the difference between Discord and Game
    /// relationships.
    void SendDiscordFriendRequestById(FDiscordUniqueID userId,
                                      FDiscordClientUpdateRelationshipCallback const& cb);

    /// \brief Sends a Discord friend request to the target user.
    ///
    /// The target user is identified by their Discord ID.
    ///
    /// After the friend request is sent, each user will have a new Discord relationship created.
    /// For the current user the RelationshipHandle::DiscordRelationshipType will be
    /// RelationshipType::PendingOutgoing and for the target user it will be
    /// RelationshipType::PendingIncoming.
    ///
    /// If the current user already has received a Discord friend request from the target user
    /// (meaning RelationshipHandle::DiscordRelationshipType is RelationshipType::PendingIncoming),
    /// then the two users will become Discord friends.
    ///
    /// See RelationshipHandle for more information on the difference between Discord and Game
    /// relationships.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void SendDiscordFriendRequestById(FDiscordUniqueID userId,
                                      FDiscordClientUpdateRelationshipCallbackDynamic const& cb);

    /// \brief Sends (or accepts) a game friend request to the target user.
    ///
    /// The target user is identified by their Discord unique username (not their DisplayName).
    ///
    /// After the friend request is sent, each user will have a new game relationship created. For
    /// the current user the RelationshipHandle::GameRelationshipType will be
    /// RelationshipType::PendingOutgoing and for the target user it will be
    /// RelationshipType::PendingIncoming.
    ///
    /// If the current user already has received a game friend request from the target user
    /// (meaning RelationshipHandle::GameRelationshipType is RelationshipType::PendingIncoming),
    /// then the two users will become game friends.
    ///
    /// See RelationshipHandle for more information on the difference between Discord and Game
    /// relationships.
    void SendGameFriendRequest(FString const& username,
                               FDiscordClientSendFriendRequestCallback const& cb);

    /// \brief Sends (or accepts) a game friend request to the target user.
    ///
    /// The target user is identified by their Discord unique username (not their DisplayName).
    ///
    /// After the friend request is sent, each user will have a new game relationship created. For
    /// the current user the RelationshipHandle::GameRelationshipType will be
    /// RelationshipType::PendingOutgoing and for the target user it will be
    /// RelationshipType::PendingIncoming.
    ///
    /// If the current user already has received a game friend request from the target user
    /// (meaning RelationshipHandle::GameRelationshipType is RelationshipType::PendingIncoming),
    /// then the two users will become game friends.
    ///
    /// See RelationshipHandle for more information on the difference between Discord and Game
    /// relationships.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void SendGameFriendRequest(FString const& username,
                               FDiscordClientSendFriendRequestCallbackDynamic const& cb);

    /// \brief Sends (or accepts) a game friend request to the target user.
    ///
    /// The target user is identified by their Discord ID.
    ///
    /// After the friend request is sent, each user will have a new game relationship created. For
    /// the current user the RelationshipHandle::GameRelationshipType will be
    /// RelationshipType::PendingOutgoing and for the target user it will be
    /// RelationshipType::PendingIncoming.
    ///
    /// If the current user already has received a game friend request from the target user
    /// (meaning RelationshipHandle::GameRelationshipType is RelationshipType::PendingIncoming),
    /// then the two users will become game friends.
    ///
    /// See RelationshipHandle for more information on the difference between Discord and Game
    /// relationships.
    void SendGameFriendRequestById(FDiscordUniqueID userId,
                                   FDiscordClientUpdateRelationshipCallback const& cb);

    /// \brief Sends (or accepts) a game friend request to the target user.
    ///
    /// The target user is identified by their Discord ID.
    ///
    /// After the friend request is sent, each user will have a new game relationship created. For
    /// the current user the RelationshipHandle::GameRelationshipType will be
    /// RelationshipType::PendingOutgoing and for the target user it will be
    /// RelationshipType::PendingIncoming.
    ///
    /// If the current user already has received a game friend request from the target user
    /// (meaning RelationshipHandle::GameRelationshipType is RelationshipType::PendingIncoming),
    /// then the two users will become game friends.
    ///
    /// See RelationshipHandle for more information on the difference between Discord and Game
    /// relationships.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void SendGameFriendRequestById(FDiscordUniqueID userId,
                                   FDiscordClientUpdateRelationshipCallbackDynamic const& cb);

    /// \brief Sets a callback to be invoked whenever a relationship for this user is established or
    /// changes type.
    ///
    /// This can be invoked when a user sends or accepts a friend invite or blocks a user for
    /// example.
    void SetRelationshipCreatedCallback(FDiscordClientRelationshipCreatedCallback const& cb);

    /// \brief Sets a callback to be invoked whenever a relationship for this user is established or
    /// changes type.
    ///
    /// This can be invoked when a user sends or accepts a friend invite or blocks a user for
    /// example.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void SetRelationshipCreatedCallback(FDiscordClientRelationshipCreatedCallbackDynamic const& cb);

    /// \brief Sets a callback to be invoked whenever a relationship for this user is removed,
    /// such as when the user rejects a friend request or removes a friend.
    ///
    /// When a relationship is removed, Client::GetRelationshipHandle will
    /// return a relationship with the type set to RelationshipType::None.
    void SetRelationshipDeletedCallback(FDiscordClientRelationshipDeletedCallback const& cb);

    /// \brief Sets a callback to be invoked whenever a relationship for this user is removed,
    /// such as when the user rejects a friend request or removes a friend.
    ///
    /// When a relationship is removed, Client::GetRelationshipHandle will
    /// return a relationship with the type set to RelationshipType::None.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void SetRelationshipDeletedCallback(FDiscordClientRelationshipDeletedCallbackDynamic const& cb);

    /// \brief Unblocks the target user. Does not restore any old relationship between the users
    /// though.
    ///
    /// Fails if the target user is not currently blocked.
    void UnblockUser(FDiscordUniqueID userId, FDiscordClientUpdateRelationshipCallback const& cb);

    /// \brief Unblocks the target user. Does not restore any old relationship between the users
    /// though.
    ///
    /// Fails if the target user is not currently blocked.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void UnblockUser(FDiscordUniqueID userId,
                     FDiscordClientUpdateRelationshipCallbackDynamic const& cb);

    /// \brief Unlike GetCurrentUser(), this method returns std::nullopt instead of a dummy object
    /// when no user is authenticated or available. This provides clearer intent about when
    /// the user data is actually available.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    UDiscordUserHandle* GetCurrentUserV2();

    /// \brief If the Discord app is running on the user's computer and the SDK establishes a
    /// connection to it, this function will return the user that is currently logged in to the
    /// Discord app.
    void GetDiscordClientConnectedUser(
      FDiscordUniqueID applicationId,
      FDiscordClientGetDiscordClientConnectedUserCallback const& callback);

    /// \brief If the Discord app is running on the user's computer and the SDK establishes a
    /// connection to it, this function will return the user that is currently logged in to the
    /// Discord app.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "callback"))
    void GetDiscordClientConnectedUser(
      FDiscordUniqueID applicationId,
      FDiscordClientGetDiscordClientConnectedUserCallbackDynamic const& callback);

    /// \brief Returns the UserHandle associated with the given user ID.
    ///
    /// It will not fetch a user from Discord's API if it is not available. Generally you can trust
    /// that users will be available for all relationships and for the authors of any messages
    /// received.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    UDiscordUserHandle* GetUser(FDiscordUniqueID userId);

    /// \brief The RelationshipGroupsUpdatedCallback is invoked whenever any user in the friends
    /// list changes. This is intended to be the callback used to ensure the friends list is kept
    /// fresh. This can be used in tandem with Client::GetRelationshipsByGroup to build and update
    /// the friends list.
    void SetRelationshipGroupsUpdatedCallback(
      FDiscordClientRelationshipGroupsUpdatedCallback const& cb);

    /// \brief The RelationshipGroupsUpdatedCallback is invoked whenever any user in the friends
    /// list changes. This is intended to be the callback used to ensure the friends list is kept
    /// fresh. This can be used in tandem with Client::GetRelationshipsByGroup to build and update
    /// the friends list.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void SetRelationshipGroupsUpdatedCallback(
      FDiscordClientRelationshipGroupsUpdatedCallbackDynamic const& cb);

    /// \brief The UserUpdatedCallback is invoked whenever *any* user the current session knows
    /// about changes, not just if the current user changes. For example if one of your Discord
    /// friends changes their name or avatar the UserUpdatedCallback will be invoked. It is also
    /// invoked when users come online, go offline, or start playing your game.
    void SetUserUpdatedCallback(FDiscordClientUserUpdatedCallback const& cb);

    /// \brief The UserUpdatedCallback is invoked whenever *any* user the current session knows
    /// about changes, not just if the current user changes. For example if one of your Discord
    /// friends changes their name or avatar the UserUpdatedCallback will be invoked. It is also
    /// invoked when users come online, go offline, or start playing your game.
    UFUNCTION(BlueprintCallable,
              Category = "Discord Partner SDK",
              meta = (AutoCreateRefTerm = "cb"))
    void SetUserUpdatedCallback(FDiscordClientUserUpdatedCallbackDynamic const& cb);
};

/// \brief Convenience class that represents the state of a single Discord call in a lobby.
UCLASS(BlueprintType, Category = "Discord Partner SDK")
class DISCORDPARTNERSDK_API UDiscordCallInfoHandle : public UObject {
    GENERATED_BODY()
public:
    ~UDiscordCallInfoHandle();
#if !DISCORD_PARTNER_SDK_STUB
    Discord_CallInfoHandle instance;
    DiscordUObjectState state = DiscordUObjectState::Invalid;
#endif

    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    void Drop();

    /// \brief Returns the lobby ID of the call.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    FDiscordUniqueID ChannelId();

    /// \brief Returns a list of the user IDs of the participants in the call.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    TArray<FDiscordUniqueID> GetParticipants();

    /// \brief Accesses the voice state for a single user so you can know if they have muted or
    /// deafened themselves.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    UDiscordVoiceStateHandle* GetVoiceStateHandle(FDiscordUniqueID userId);

    /// \brief Returns the lobby ID of the call.
    UFUNCTION(BlueprintCallable, Category = "Discord Partner SDK")
    FDiscordUniqueID GuildId();
};
