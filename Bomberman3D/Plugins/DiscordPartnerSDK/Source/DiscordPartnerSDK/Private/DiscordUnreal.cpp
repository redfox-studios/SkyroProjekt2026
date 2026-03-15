// Generated with <3 by Discord.Sdk.Derive
#include "DiscordUnreal.h"

#include <exception>

#if !DISCORD_PARTNER_SDK_STUB
// Version-conditional character type macro for compact code generation
#if ENGINE_MAJOR_VERSION >= 5
#define DISCORD_CHAR_CAST(ptr) reinterpret_cast<UTF8CHAR*>(ptr)
#else
#define DISCORD_CHAR_CAST(ptr) reinterpret_cast<ANSICHAR*>(ptr)
#endif

namespace {
template <typename T>
struct TDelegateUserData {
    T delegate;
    TDelegateUserData(T delegate)
      : delegate{delegate}
    {
    }

    static void Free(void* ptr) { delete reinterpret_cast<TDelegateUserData*>(ptr); }
};

struct ConvertedProperties {
    ConvertedProperties(TMap<FString, FString> const& PropertyMap)
    {
        Properties.size = PropertyMap.Num();
        Properties.keys = reinterpret_cast<Discord_String*>(
          Discord_Alloc(Properties.size * sizeof(Discord_String)));
        Properties.values = reinterpret_cast<Discord_String*>(
          Discord_Alloc(Properties.size * sizeof(Discord_String)));
        size_t i = 0;
        for (auto& pair : PropertyMap) {
            Properties.keys[i] = AllocateString(pair.Key);
            Properties.values[i] = AllocateString(pair.Value);
            ++i;
        }
    }
    ~ConvertedProperties() { Discord_FreeProperties(Properties); }
    Discord_Properties Properties{};

private:
    Discord_String AllocateString(FString const& str)
    {
        FTCHARToUTF8 convert(*str);
        Discord_String result;
        result.ptr = reinterpret_cast<uint8*>(Discord_Alloc(convert.Length()));
        result.size = convert.Length();
        FMemory::Memcpy(result.ptr, convert.Get(), result.size);
        return result;
    }
};

TMap<FString, FString> ConvertReturnedProperties(Discord_Properties const& Properties)
{
    TMap<FString, FString> result;
    for (size_t i = 0; i < Properties.size; ++i) {
        FString key, value;
        key.AppendChars(DISCORD_CHAR_CAST(Properties.keys[i].ptr), Properties.keys[i].size);
        value.AppendChars(DISCORD_CHAR_CAST(Properties.values[i].ptr), Properties.values[i].size);
        result.Add(MoveTemp(key), MoveTemp(value));
    }
    return result;
}
} // namespace
#endif

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4702)
#elif defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunreachable-code"
#endif
UDiscordActivityInvite::~UDiscordActivityInvite()
{
    Drop();
}
void UDiscordActivityInvite::Init()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - ActivityInvite::Init cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Invalid);
    Discord_ActivityInvite_Init(&instance);
    state = DiscordUObjectState::Owned;
#endif
}
void UDiscordActivityInvite::Drop()
{
#if DISCORD_PARTNER_SDK_STUB
#else
    if (state != DiscordUObjectState::Owned) {
        return;
    }
    Discord_ActivityInvite_Drop(&instance);
    state = DiscordUObjectState::Invalid;
#endif
}
/* TODO: Clone */
FDiscordUniqueID UDiscordActivityInvite::SenderId()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - ActivityInvite::SenderId getter cannot be called"));
    std::terminate();
#else
    uint64_t returnValue__;
    returnValue__ = Discord_ActivityInvite_SenderId(&instance);
    return returnValue__;

#endif
}
void UDiscordActivityInvite::SetSenderId(FDiscordUniqueID SenderId)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - ActivityInvite::SetSenderId cannot be called"));
    std::terminate();
#else
    Discord_ActivityInvite_SetSenderId(&instance, SenderId);

#endif
}
FDiscordUniqueID UDiscordActivityInvite::ChannelId()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - ActivityInvite::ChannelId getter cannot be called"));
    std::terminate();
#else
    uint64_t returnValue__;
    returnValue__ = Discord_ActivityInvite_ChannelId(&instance);
    return returnValue__;

#endif
}
void UDiscordActivityInvite::SetChannelId(FDiscordUniqueID ChannelId)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - ActivityInvite::SetChannelId cannot be called"));
    std::terminate();
#else
    Discord_ActivityInvite_SetChannelId(&instance, ChannelId);

#endif
}
FDiscordUniqueID UDiscordActivityInvite::MessageId()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - ActivityInvite::MessageId getter cannot be called"));
    std::terminate();
#else
    uint64_t returnValue__;
    returnValue__ = Discord_ActivityInvite_MessageId(&instance);
    return returnValue__;

#endif
}
void UDiscordActivityInvite::SetMessageId(FDiscordUniqueID MessageId)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - ActivityInvite::SetMessageId cannot be called"));
    std::terminate();
#else
    Discord_ActivityInvite_SetMessageId(&instance, MessageId);

#endif
}
EDiscordActivityActionTypes UDiscordActivityInvite::Type()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - ActivityInvite::Type getter cannot be called"));
    std::terminate();
#else
    Discord_ActivityActionTypes returnValue__;
    returnValue__ = Discord_ActivityInvite_Type(&instance);
    return static_cast<EDiscordActivityActionTypes>(returnValue__);

#endif
}
void UDiscordActivityInvite::SetType(EDiscordActivityActionTypes Type)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - ActivityInvite::SetType cannot be called"));
    std::terminate();
#else
    Discord_ActivityInvite_SetType(&instance, static_cast<Discord_ActivityActionTypes>(Type));

#endif
}
FDiscordUniqueID UDiscordActivityInvite::ApplicationId()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - ActivityInvite::ApplicationId getter cannot "
                "be called"));
    std::terminate();
#else
    uint64_t returnValue__;
    returnValue__ = Discord_ActivityInvite_ApplicationId(&instance);
    return returnValue__;

#endif
}
void UDiscordActivityInvite::SetApplicationId(FDiscordUniqueID ApplicationId)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - ActivityInvite::SetApplicationId cannot be called"));
    std::terminate();
#else
    Discord_ActivityInvite_SetApplicationId(&instance, ApplicationId);

#endif
}
FDiscordUniqueID UDiscordActivityInvite::ParentApplicationId()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - ActivityInvite::ParentApplicationId getter "
                "cannot be called"));
    std::terminate();
#else
    uint64_t returnValue__;
    returnValue__ = Discord_ActivityInvite_ParentApplicationId(&instance);
    return returnValue__;

#endif
}
void UDiscordActivityInvite::SetParentApplicationId(FDiscordUniqueID ParentApplicationId)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - ActivityInvite::SetParentApplicationId "
                "cannot be called"));
    std::terminate();
#else
    Discord_ActivityInvite_SetParentApplicationId(&instance, ParentApplicationId);

#endif
}
FString UDiscordActivityInvite::PartyId()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - ActivityInvite::PartyId getter cannot be called"));
    std::terminate();
#else
    Discord_String returnValueNative__;
    Discord_ActivityInvite_PartyId(&instance, &returnValueNative__);
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;

#endif
}
void UDiscordActivityInvite::SetPartyId(FString PartyId)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - ActivityInvite::SetPartyId cannot be called"));
    std::terminate();
#else
    Discord_String PartyId__span;
    FTCHARToUTF8 PartyId__convert(*PartyId);
    PartyId__span.ptr = (uint8*)PartyId__convert.Get();
    PartyId__span.size = PartyId__convert.Length();
    Discord_ActivityInvite_SetPartyId(&instance, PartyId__span);

#endif
}
FString UDiscordActivityInvite::SessionId()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - ActivityInvite::SessionId getter cannot be called"));
    std::terminate();
#else
    Discord_String returnValueNative__;
    Discord_ActivityInvite_SessionId(&instance, &returnValueNative__);
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;

#endif
}
void UDiscordActivityInvite::SetSessionId(FString SessionId)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - ActivityInvite::SetSessionId cannot be called"));
    std::terminate();
#else
    Discord_String SessionId__span;
    FTCHARToUTF8 SessionId__convert(*SessionId);
    SessionId__span.ptr = (uint8*)SessionId__convert.Get();
    SessionId__span.size = SessionId__convert.Length();
    Discord_ActivityInvite_SetSessionId(&instance, SessionId__span);

#endif
}
bool UDiscordActivityInvite::IsValid()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - ActivityInvite::IsValid getter cannot be called"));
    std::terminate();
#else
    bool returnValue__;
    returnValue__ = Discord_ActivityInvite_IsValid(&instance);
    return returnValue__;

#endif
}
void UDiscordActivityInvite::SetIsValid(bool IsValid)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - ActivityInvite::SetIsValid cannot be called"));
    std::terminate();
#else
    Discord_ActivityInvite_SetIsValid(&instance, IsValid);

#endif
}
UDiscordActivityAssets::~UDiscordActivityAssets()
{
    Drop();
}
void UDiscordActivityAssets::Init()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - ActivityAssets::Init cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Invalid);
    Discord_ActivityAssets_Init(&instance);
    state = DiscordUObjectState::Owned;
#endif
}
void UDiscordActivityAssets::Drop()
{
#if DISCORD_PARTNER_SDK_STUB
#else
    if (state != DiscordUObjectState::Owned) {
        return;
    }
    Discord_ActivityAssets_Drop(&instance);
    state = DiscordUObjectState::Invalid;
#endif
}
/* TODO: Clone */
FString UDiscordActivityAssets::LargeImage()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - ActivityAssets::LargeImage getter cannot be called"));
    std::terminate();
#else
    bool __returnIsNonNull;
    Discord_String returnValueNative__;
    __returnIsNonNull = Discord_ActivityAssets_LargeImage(&instance, &returnValueNative__);
    if (!__returnIsNonNull) {
        return {};
    }
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;

#endif
}
void UDiscordActivityAssets::SetLargeImage(FString LargeImage)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - ActivityAssets::SetLargeImage cannot be called"));
    std::terminate();
#else
    Discord_String LargeImage__span;
    FTCHARToUTF8 LargeImage__convert(*LargeImage);
    LargeImage__span.ptr = (uint8*)LargeImage__convert.Get();
    LargeImage__span.size = LargeImage__convert.Length();
    Discord_ActivityAssets_SetLargeImage(&instance, &LargeImage__span);

#endif
}
FString UDiscordActivityAssets::LargeText()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - ActivityAssets::LargeText getter cannot be called"));
    std::terminate();
#else
    bool __returnIsNonNull;
    Discord_String returnValueNative__;
    __returnIsNonNull = Discord_ActivityAssets_LargeText(&instance, &returnValueNative__);
    if (!__returnIsNonNull) {
        return {};
    }
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;

#endif
}
void UDiscordActivityAssets::SetLargeText(FString LargeText)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - ActivityAssets::SetLargeText cannot be called"));
    std::terminate();
#else
    Discord_String LargeText__span;
    FTCHARToUTF8 LargeText__convert(*LargeText);
    LargeText__span.ptr = (uint8*)LargeText__convert.Get();
    LargeText__span.size = LargeText__convert.Length();
    Discord_ActivityAssets_SetLargeText(&instance, &LargeText__span);

#endif
}
FString UDiscordActivityAssets::LargeUrl()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - ActivityAssets::LargeUrl getter cannot be called"));
    std::terminate();
#else
    bool __returnIsNonNull;
    Discord_String returnValueNative__;
    __returnIsNonNull = Discord_ActivityAssets_LargeUrl(&instance, &returnValueNative__);
    if (!__returnIsNonNull) {
        return {};
    }
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;

#endif
}
void UDiscordActivityAssets::SetLargeUrl(FString LargeUrl)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - ActivityAssets::SetLargeUrl cannot be called"));
    std::terminate();
#else
    Discord_String LargeUrl__span;
    FTCHARToUTF8 LargeUrl__convert(*LargeUrl);
    LargeUrl__span.ptr = (uint8*)LargeUrl__convert.Get();
    LargeUrl__span.size = LargeUrl__convert.Length();
    Discord_ActivityAssets_SetLargeUrl(&instance, &LargeUrl__span);

#endif
}
FString UDiscordActivityAssets::SmallImage()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - ActivityAssets::SmallImage getter cannot be called"));
    std::terminate();
#else
    bool __returnIsNonNull;
    Discord_String returnValueNative__;
    __returnIsNonNull = Discord_ActivityAssets_SmallImage(&instance, &returnValueNative__);
    if (!__returnIsNonNull) {
        return {};
    }
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;

#endif
}
void UDiscordActivityAssets::SetSmallImage(FString SmallImage)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - ActivityAssets::SetSmallImage cannot be called"));
    std::terminate();
#else
    Discord_String SmallImage__span;
    FTCHARToUTF8 SmallImage__convert(*SmallImage);
    SmallImage__span.ptr = (uint8*)SmallImage__convert.Get();
    SmallImage__span.size = SmallImage__convert.Length();
    Discord_ActivityAssets_SetSmallImage(&instance, &SmallImage__span);

#endif
}
FString UDiscordActivityAssets::SmallText()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - ActivityAssets::SmallText getter cannot be called"));
    std::terminate();
#else
    bool __returnIsNonNull;
    Discord_String returnValueNative__;
    __returnIsNonNull = Discord_ActivityAssets_SmallText(&instance, &returnValueNative__);
    if (!__returnIsNonNull) {
        return {};
    }
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;

#endif
}
void UDiscordActivityAssets::SetSmallText(FString SmallText)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - ActivityAssets::SetSmallText cannot be called"));
    std::terminate();
#else
    Discord_String SmallText__span;
    FTCHARToUTF8 SmallText__convert(*SmallText);
    SmallText__span.ptr = (uint8*)SmallText__convert.Get();
    SmallText__span.size = SmallText__convert.Length();
    Discord_ActivityAssets_SetSmallText(&instance, &SmallText__span);

#endif
}
FString UDiscordActivityAssets::SmallUrl()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - ActivityAssets::SmallUrl getter cannot be called"));
    std::terminate();
#else
    bool __returnIsNonNull;
    Discord_String returnValueNative__;
    __returnIsNonNull = Discord_ActivityAssets_SmallUrl(&instance, &returnValueNative__);
    if (!__returnIsNonNull) {
        return {};
    }
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;

#endif
}
void UDiscordActivityAssets::SetSmallUrl(FString SmallUrl)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - ActivityAssets::SetSmallUrl cannot be called"));
    std::terminate();
#else
    Discord_String SmallUrl__span;
    FTCHARToUTF8 SmallUrl__convert(*SmallUrl);
    SmallUrl__span.ptr = (uint8*)SmallUrl__convert.Get();
    SmallUrl__span.size = SmallUrl__convert.Length();
    Discord_ActivityAssets_SetSmallUrl(&instance, &SmallUrl__span);

#endif
}
FString UDiscordActivityAssets::InviteCoverImage()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - ActivityAssets::InviteCoverImage getter "
                "cannot be called"));
    std::terminate();
#else
    bool __returnIsNonNull;
    Discord_String returnValueNative__;
    __returnIsNonNull = Discord_ActivityAssets_InviteCoverImage(&instance, &returnValueNative__);
    if (!__returnIsNonNull) {
        return {};
    }
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;

#endif
}
void UDiscordActivityAssets::SetInviteCoverImage(FString InviteCoverImage)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - ActivityAssets::SetInviteCoverImage cannot "
                "be called"));
    std::terminate();
#else
    Discord_String InviteCoverImage__span;
    FTCHARToUTF8 InviteCoverImage__convert(*InviteCoverImage);
    InviteCoverImage__span.ptr = (uint8*)InviteCoverImage__convert.Get();
    InviteCoverImage__span.size = InviteCoverImage__convert.Length();
    Discord_ActivityAssets_SetInviteCoverImage(&instance, &InviteCoverImage__span);

#endif
}
UDiscordActivityTimestamps::~UDiscordActivityTimestamps()
{
    Drop();
}
void UDiscordActivityTimestamps::Init()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - ActivityTimestamps::Init cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Invalid);
    Discord_ActivityTimestamps_Init(&instance);
    state = DiscordUObjectState::Owned;
#endif
}
void UDiscordActivityTimestamps::Drop()
{
#if DISCORD_PARTNER_SDK_STUB
#else
    if (state != DiscordUObjectState::Owned) {
        return;
    }
    Discord_ActivityTimestamps_Drop(&instance);
    state = DiscordUObjectState::Invalid;
#endif
}
/* TODO: Clone */
FDiscordUniqueID UDiscordActivityTimestamps::Start()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - ActivityTimestamps::Start getter cannot be called"));
    std::terminate();
#else
    uint64_t returnValue__;
    returnValue__ = Discord_ActivityTimestamps_Start(&instance);
    return returnValue__;

#endif
}
void UDiscordActivityTimestamps::SetStart(FDiscordUniqueID Start)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - ActivityTimestamps::SetStart cannot be called"));
    std::terminate();
#else
    Discord_ActivityTimestamps_SetStart(&instance, Start);

#endif
}
FDiscordUniqueID UDiscordActivityTimestamps::End()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - ActivityTimestamps::End getter cannot be called"));
    std::terminate();
#else
    uint64_t returnValue__;
    returnValue__ = Discord_ActivityTimestamps_End(&instance);
    return returnValue__;

#endif
}
void UDiscordActivityTimestamps::SetEnd(FDiscordUniqueID End)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - ActivityTimestamps::SetEnd cannot be called"));
    std::terminate();
#else
    Discord_ActivityTimestamps_SetEnd(&instance, End);

#endif
}
UDiscordActivityParty::~UDiscordActivityParty()
{
    Drop();
}
void UDiscordActivityParty::Init()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - ActivityParty::Init cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Invalid);
    Discord_ActivityParty_Init(&instance);
    state = DiscordUObjectState::Owned;
#endif
}
void UDiscordActivityParty::Drop()
{
#if DISCORD_PARTNER_SDK_STUB
#else
    if (state != DiscordUObjectState::Owned) {
        return;
    }
    Discord_ActivityParty_Drop(&instance);
    state = DiscordUObjectState::Invalid;
#endif
}
/* TODO: Clone */
FString UDiscordActivityParty::Id()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - ActivityParty::Id getter cannot be called"));
    std::terminate();
#else
    Discord_String returnValueNative__;
    Discord_ActivityParty_Id(&instance, &returnValueNative__);
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;

#endif
}
void UDiscordActivityParty::SetId(FString Id)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - ActivityParty::SetId cannot be called"));
    std::terminate();
#else
    Discord_String Id__span;
    FTCHARToUTF8 Id__convert(*Id);
    Id__span.ptr = (uint8*)Id__convert.Get();
    Id__span.size = Id__convert.Length();
    Discord_ActivityParty_SetId(&instance, Id__span);

#endif
}
int32 UDiscordActivityParty::CurrentSize()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - ActivityParty::CurrentSize getter cannot be called"));
    std::terminate();
#else
    int32_t returnValue__;
    returnValue__ = Discord_ActivityParty_CurrentSize(&instance);
    return returnValue__;

#endif
}
void UDiscordActivityParty::SetCurrentSize(int32 CurrentSize)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - ActivityParty::SetCurrentSize cannot be called"));
    std::terminate();
#else
    Discord_ActivityParty_SetCurrentSize(&instance, CurrentSize);

#endif
}
int32 UDiscordActivityParty::MaxSize()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - ActivityParty::MaxSize getter cannot be called"));
    std::terminate();
#else
    int32_t returnValue__;
    returnValue__ = Discord_ActivityParty_MaxSize(&instance);
    return returnValue__;

#endif
}
void UDiscordActivityParty::SetMaxSize(int32 MaxSize)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - ActivityParty::SetMaxSize cannot be called"));
    std::terminate();
#else
    Discord_ActivityParty_SetMaxSize(&instance, MaxSize);

#endif
}
EDiscordActivityPartyPrivacy UDiscordActivityParty::Privacy()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - ActivityParty::Privacy getter cannot be called"));
    std::terminate();
#else
    Discord_ActivityPartyPrivacy returnValue__;
    returnValue__ = Discord_ActivityParty_Privacy(&instance);
    return static_cast<EDiscordActivityPartyPrivacy>(returnValue__);

#endif
}
void UDiscordActivityParty::SetPrivacy(EDiscordActivityPartyPrivacy Privacy)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - ActivityParty::SetPrivacy cannot be called"));
    std::terminate();
#else
    Discord_ActivityParty_SetPrivacy(&instance, static_cast<Discord_ActivityPartyPrivacy>(Privacy));

#endif
}
UDiscordActivitySecrets::~UDiscordActivitySecrets()
{
    Drop();
}
void UDiscordActivitySecrets::Init()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - ActivitySecrets::Init cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Invalid);
    Discord_ActivitySecrets_Init(&instance);
    state = DiscordUObjectState::Owned;
#endif
}
void UDiscordActivitySecrets::Drop()
{
#if DISCORD_PARTNER_SDK_STUB
#else
    if (state != DiscordUObjectState::Owned) {
        return;
    }
    Discord_ActivitySecrets_Drop(&instance);
    state = DiscordUObjectState::Invalid;
#endif
}
/* TODO: Clone */
FString UDiscordActivitySecrets::Join()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - ActivitySecrets::Join getter cannot be called"));
    std::terminate();
#else
    Discord_String returnValueNative__;
    Discord_ActivitySecrets_Join(&instance, &returnValueNative__);
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;

#endif
}
void UDiscordActivitySecrets::SetJoin(FString Join)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - ActivitySecrets::SetJoin cannot be called"));
    std::terminate();
#else
    Discord_String Join__span;
    FTCHARToUTF8 Join__convert(*Join);
    Join__span.ptr = (uint8*)Join__convert.Get();
    Join__span.size = Join__convert.Length();
    Discord_ActivitySecrets_SetJoin(&instance, Join__span);

#endif
}
UDiscordActivityButton::~UDiscordActivityButton()
{
    Drop();
}
void UDiscordActivityButton::Init()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - ActivityButton::Init cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Invalid);
    Discord_ActivityButton_Init(&instance);
    state = DiscordUObjectState::Owned;
#endif
}
void UDiscordActivityButton::Drop()
{
#if DISCORD_PARTNER_SDK_STUB
#else
    if (state != DiscordUObjectState::Owned) {
        return;
    }
    Discord_ActivityButton_Drop(&instance);
    state = DiscordUObjectState::Invalid;
#endif
}
/* TODO: Clone */
FString UDiscordActivityButton::Label()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - ActivityButton::Label getter cannot be called"));
    std::terminate();
#else
    Discord_String returnValueNative__;
    Discord_ActivityButton_Label(&instance, &returnValueNative__);
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;

#endif
}
void UDiscordActivityButton::SetLabel(FString Label)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - ActivityButton::SetLabel cannot be called"));
    std::terminate();
#else
    Discord_String Label__span;
    FTCHARToUTF8 Label__convert(*Label);
    Label__span.ptr = (uint8*)Label__convert.Get();
    Label__span.size = Label__convert.Length();
    Discord_ActivityButton_SetLabel(&instance, Label__span);

#endif
}
FString UDiscordActivityButton::Url()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - ActivityButton::Url getter cannot be called"));
    std::terminate();
#else
    Discord_String returnValueNative__;
    Discord_ActivityButton_Url(&instance, &returnValueNative__);
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;

#endif
}
void UDiscordActivityButton::SetUrl(FString Url)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - ActivityButton::SetUrl cannot be called"));
    std::terminate();
#else
    Discord_String Url__span;
    FTCHARToUTF8 Url__convert(*Url);
    Url__span.ptr = (uint8*)Url__convert.Get();
    Url__span.size = Url__convert.Length();
    Discord_ActivityButton_SetUrl(&instance, Url__span);

#endif
}
UDiscordActivity::~UDiscordActivity()
{
    Drop();
}
void UDiscordActivity::Init()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - Activity::Init cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Invalid);
    Discord_Activity_Init(&instance);
    state = DiscordUObjectState::Owned;
#endif
}
void UDiscordActivity::Drop()
{
#if DISCORD_PARTNER_SDK_STUB
#else
    if (state != DiscordUObjectState::Owned) {
        return;
    }
    Discord_Activity_Drop(&instance);
    state = DiscordUObjectState::Invalid;
#endif
}
/* TODO: Clone */
void UDiscordActivity::AddButton(UDiscordActivityButton* button)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Activity::AddButton cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_ActivityButton* button__instance = button ? &button->instance : nullptr;
    Discord_Activity_AddButton(&instance, button__instance);
#endif
}
bool UDiscordActivity::Equals(UDiscordActivity* other)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - Activity::Equals cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool returnValue__;
    Discord_Activity* other__instance = other ? &other->instance : nullptr;
    returnValue__ = Discord_Activity_Equals(&instance, other__instance);
    return returnValue__;
#endif
}
TArray<UDiscordActivityButton*> UDiscordActivity::GetButtons()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Activity::GetButtons cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_ActivityButtonSpan returnValueNative__;
    Discord_Activity_GetButtons(&instance, &returnValueNative__);
    TArray<UDiscordActivityButton*> returnValue__;
    returnValue__.Reserve(returnValueNative__.size);
    for (size_t i__ = 0; i__ < returnValueNative__.size; ++i__) {
        auto instance__ = NewObject<UDiscordActivityButton>();
        instance__->instance = returnValueNative__.ptr[i__];
        instance__->state = DiscordUObjectState::Owned;
        returnValue__.Add(instance__);
    }
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;
#endif
}
FString UDiscordActivity::Name()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Activity::Name getter cannot be called"));
    std::terminate();
#else
    Discord_String returnValueNative__;
    Discord_Activity_Name(&instance, &returnValueNative__);
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;

#endif
}
void UDiscordActivity::SetName(FString Name)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - Activity::SetName cannot be called"));
    std::terminate();
#else
    Discord_String Name__span;
    FTCHARToUTF8 Name__convert(*Name);
    Name__span.ptr = (uint8*)Name__convert.Get();
    Name__span.size = Name__convert.Length();
    Discord_Activity_SetName(&instance, Name__span);

#endif
}
EDiscordActivityTypes UDiscordActivity::Type()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Activity::Type getter cannot be called"));
    std::terminate();
#else
    Discord_ActivityTypes returnValue__;
    returnValue__ = Discord_Activity_Type(&instance);
    return static_cast<EDiscordActivityTypes>(returnValue__);

#endif
}
void UDiscordActivity::SetType(EDiscordActivityTypes Type)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - Activity::SetType cannot be called"));
    std::terminate();
#else
    Discord_Activity_SetType(&instance, static_cast<Discord_ActivityTypes>(Type));

#endif
}
EDiscordStatusDisplayTypes UDiscordActivity::StatusDisplayType()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Activity::StatusDisplayType getter cannot be "
                "called"));
    std::terminate();
#else
    bool __returnIsNonNull;
    Discord_StatusDisplayTypes __returnValue{};
    __returnIsNonNull = Discord_Activity_StatusDisplayType(&instance, &__returnValue);
    if (!__returnIsNonNull) {
        return {};
    }
    return static_cast<EDiscordStatusDisplayTypes>(__returnValue);

#endif
}
void UDiscordActivity::SetStatusDisplayType(EDiscordStatusDisplayTypes StatusDisplayType)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Activity::SetStatusDisplayType cannot be called"));
    std::terminate();
#else
    Discord_StatusDisplayTypes discordStatusDisplayType =
      static_cast<Discord_StatusDisplayTypes>(static_cast<int32_t>(StatusDisplayType));
    Discord_Activity_SetStatusDisplayType(&instance, &discordStatusDisplayType);

#endif
}
FString UDiscordActivity::State()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Activity::State getter cannot be called"));
    std::terminate();
#else
    bool __returnIsNonNull;
    Discord_String returnValueNative__;
    __returnIsNonNull = Discord_Activity_State(&instance, &returnValueNative__);
    if (!__returnIsNonNull) {
        return {};
    }
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;

#endif
}
void UDiscordActivity::SetState(FString State)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - Activity::SetState cannot be called"));
    std::terminate();
#else
    Discord_String State__span;
    FTCHARToUTF8 State__convert(*State);
    State__span.ptr = (uint8*)State__convert.Get();
    State__span.size = State__convert.Length();
    Discord_Activity_SetState(&instance, &State__span);

#endif
}
FString UDiscordActivity::StateUrl()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Activity::StateUrl getter cannot be called"));
    std::terminate();
#else
    bool __returnIsNonNull;
    Discord_String returnValueNative__;
    __returnIsNonNull = Discord_Activity_StateUrl(&instance, &returnValueNative__);
    if (!__returnIsNonNull) {
        return {};
    }
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;

#endif
}
void UDiscordActivity::SetStateUrl(FString StateUrl)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Activity::SetStateUrl cannot be called"));
    std::terminate();
#else
    Discord_String StateUrl__span;
    FTCHARToUTF8 StateUrl__convert(*StateUrl);
    StateUrl__span.ptr = (uint8*)StateUrl__convert.Get();
    StateUrl__span.size = StateUrl__convert.Length();
    Discord_Activity_SetStateUrl(&instance, &StateUrl__span);

#endif
}
FString UDiscordActivity::Details()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Activity::Details getter cannot be called"));
    std::terminate();
#else
    bool __returnIsNonNull;
    Discord_String returnValueNative__;
    __returnIsNonNull = Discord_Activity_Details(&instance, &returnValueNative__);
    if (!__returnIsNonNull) {
        return {};
    }
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;

#endif
}
void UDiscordActivity::SetDetails(FString Details)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Activity::SetDetails cannot be called"));
    std::terminate();
#else
    Discord_String Details__span;
    FTCHARToUTF8 Details__convert(*Details);
    Details__span.ptr = (uint8*)Details__convert.Get();
    Details__span.size = Details__convert.Length();
    Discord_Activity_SetDetails(&instance, &Details__span);

#endif
}
FString UDiscordActivity::DetailsUrl()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Activity::DetailsUrl getter cannot be called"));
    std::terminate();
#else
    bool __returnIsNonNull;
    Discord_String returnValueNative__;
    __returnIsNonNull = Discord_Activity_DetailsUrl(&instance, &returnValueNative__);
    if (!__returnIsNonNull) {
        return {};
    }
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;

#endif
}
void UDiscordActivity::SetDetailsUrl(FString DetailsUrl)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Activity::SetDetailsUrl cannot be called"));
    std::terminate();
#else
    Discord_String DetailsUrl__span;
    FTCHARToUTF8 DetailsUrl__convert(*DetailsUrl);
    DetailsUrl__span.ptr = (uint8*)DetailsUrl__convert.Get();
    DetailsUrl__span.size = DetailsUrl__convert.Length();
    Discord_Activity_SetDetailsUrl(&instance, &DetailsUrl__span);

#endif
}
FDiscordUniqueID UDiscordActivity::ApplicationId()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Activity::ApplicationId getter cannot be called"));
    std::terminate();
#else
    bool __returnIsNonNull;
    uint64_t __returnValue{};
    __returnIsNonNull = Discord_Activity_ApplicationId(&instance, &__returnValue);
    if (!__returnIsNonNull) {
        return {};
    }
    return __returnValue;

#endif
}
void UDiscordActivity::SetApplicationId(FDiscordUniqueID ApplicationId)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Activity::SetApplicationId cannot be called"));
    std::terminate();
#else
    uint64_t ApplicationId__optional = ApplicationId;
    Discord_Activity_SetApplicationId(&instance, &ApplicationId__optional);

#endif
}
FDiscordUniqueID UDiscordActivity::ParentApplicationId()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Activity::ParentApplicationId getter cannot "
                "be called"));
    std::terminate();
#else
    bool __returnIsNonNull;
    uint64_t __returnValue{};
    __returnIsNonNull = Discord_Activity_ParentApplicationId(&instance, &__returnValue);
    if (!__returnIsNonNull) {
        return {};
    }
    return __returnValue;

#endif
}
void UDiscordActivity::SetParentApplicationId(FDiscordUniqueID ParentApplicationId)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Activity::SetParentApplicationId cannot be called"));
    std::terminate();
#else
    uint64_t ParentApplicationId__optional = ParentApplicationId;
    Discord_Activity_SetParentApplicationId(&instance, &ParentApplicationId__optional);

#endif
}
UDiscordActivityAssets* UDiscordActivity::Assets()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Activity::Assets getter cannot be called"));
    std::terminate();
#else
    bool __returnIsNonNull;
    Discord_ActivityAssets returnValueNative__;
    UDiscordActivityAssets* returnValue__ = nullptr;
    __returnIsNonNull = Discord_Activity_Assets(&instance, &returnValueNative__);
    if (!__returnIsNonNull) {
        return {};
    }
    returnValue__ = NewObject<UDiscordActivityAssets>();
    returnValue__->instance = returnValueNative__;
    returnValue__->state = DiscordUObjectState::Owned;
    return returnValue__;

#endif
}
void UDiscordActivity::SetAssets(UDiscordActivityAssets* Assets)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Activity::SetAssets cannot be called"));
    std::terminate();
#else
    Discord_ActivityAssets* Assets__instance = Assets ? &Assets->instance : nullptr;
    Discord_Activity_SetAssets(&instance, Assets__instance);

#endif
}
UDiscordActivityTimestamps* UDiscordActivity::Timestamps()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Activity::Timestamps getter cannot be called"));
    std::terminate();
#else
    bool __returnIsNonNull;
    Discord_ActivityTimestamps returnValueNative__;
    UDiscordActivityTimestamps* returnValue__ = nullptr;
    __returnIsNonNull = Discord_Activity_Timestamps(&instance, &returnValueNative__);
    if (!__returnIsNonNull) {
        return {};
    }
    returnValue__ = NewObject<UDiscordActivityTimestamps>();
    returnValue__->instance = returnValueNative__;
    returnValue__->state = DiscordUObjectState::Owned;
    return returnValue__;

#endif
}
void UDiscordActivity::SetTimestamps(UDiscordActivityTimestamps* Timestamps)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Activity::SetTimestamps cannot be called"));
    std::terminate();
#else
    Discord_ActivityTimestamps* Timestamps__instance = Timestamps ? &Timestamps->instance : nullptr;
    Discord_Activity_SetTimestamps(&instance, Timestamps__instance);

#endif
}
UDiscordActivityParty* UDiscordActivity::Party()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Activity::Party getter cannot be called"));
    std::terminate();
#else
    bool __returnIsNonNull;
    Discord_ActivityParty returnValueNative__;
    UDiscordActivityParty* returnValue__ = nullptr;
    __returnIsNonNull = Discord_Activity_Party(&instance, &returnValueNative__);
    if (!__returnIsNonNull) {
        return {};
    }
    returnValue__ = NewObject<UDiscordActivityParty>();
    returnValue__->instance = returnValueNative__;
    returnValue__->state = DiscordUObjectState::Owned;
    return returnValue__;

#endif
}
void UDiscordActivity::SetParty(UDiscordActivityParty* Party)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - Activity::SetParty cannot be called"));
    std::terminate();
#else
    Discord_ActivityParty* Party__instance = Party ? &Party->instance : nullptr;
    Discord_Activity_SetParty(&instance, Party__instance);

#endif
}
UDiscordActivitySecrets* UDiscordActivity::Secrets()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Activity::Secrets getter cannot be called"));
    std::terminate();
#else
    bool __returnIsNonNull;
    Discord_ActivitySecrets returnValueNative__;
    UDiscordActivitySecrets* returnValue__ = nullptr;
    __returnIsNonNull = Discord_Activity_Secrets(&instance, &returnValueNative__);
    if (!__returnIsNonNull) {
        return {};
    }
    returnValue__ = NewObject<UDiscordActivitySecrets>();
    returnValue__->instance = returnValueNative__;
    returnValue__->state = DiscordUObjectState::Owned;
    return returnValue__;

#endif
}
void UDiscordActivity::SetSecrets(UDiscordActivitySecrets* Secrets)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Activity::SetSecrets cannot be called"));
    std::terminate();
#else
    Discord_ActivitySecrets* Secrets__instance = Secrets ? &Secrets->instance : nullptr;
    Discord_Activity_SetSecrets(&instance, Secrets__instance);

#endif
}
EDiscordActivityGamePlatforms UDiscordActivity::SupportedPlatforms()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Activity::SupportedPlatforms getter cannot "
                "be called"));
    std::terminate();
#else
    Discord_ActivityGamePlatforms returnValue__;
    returnValue__ = Discord_Activity_SupportedPlatforms(&instance);
    return static_cast<EDiscordActivityGamePlatforms>(returnValue__);

#endif
}
void UDiscordActivity::SetSupportedPlatforms(EDiscordActivityGamePlatforms SupportedPlatforms)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Activity::SetSupportedPlatforms cannot be called"));
    std::terminate();
#else
    Discord_Activity_SetSupportedPlatforms(
      &instance, static_cast<Discord_ActivityGamePlatforms>(SupportedPlatforms));

#endif
}
UDiscordClientResult::~UDiscordClientResult()
{
    Drop();
}
void UDiscordClientResult::Drop()
{
#if DISCORD_PARTNER_SDK_STUB
#else
    if (state != DiscordUObjectState::Owned) {
        return;
    }
    Discord_ClientResult_Drop(&instance);
    state = DiscordUObjectState::Invalid;
#endif
}
/* TODO: Clone */
FString UDiscordClientResult::ToString()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - ClientResult::ToString cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String returnValueNative__;
    Discord_ClientResult_ToString(&instance, &returnValueNative__);
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;
#endif
}
EDiscordErrorType UDiscordClientResult::Type()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - ClientResult::Type getter cannot be called"));
    std::terminate();
#else
    Discord_ErrorType returnValue__;
    returnValue__ = Discord_ClientResult_Type(&instance);
    return static_cast<EDiscordErrorType>(returnValue__);

#endif
}
void UDiscordClientResult::SetType(EDiscordErrorType Type)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - ClientResult::SetType cannot be called"));
    std::terminate();
#else
    Discord_ClientResult_SetType(&instance, static_cast<Discord_ErrorType>(Type));

#endif
}
FString UDiscordClientResult::Error()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - ClientResult::Error getter cannot be called"));
    std::terminate();
#else
    Discord_String returnValueNative__;
    Discord_ClientResult_Error(&instance, &returnValueNative__);
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;

#endif
}
void UDiscordClientResult::SetError(FString Error)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - ClientResult::SetError cannot be called"));
    std::terminate();
#else
    Discord_String Error__span;
    FTCHARToUTF8 Error__convert(*Error);
    Error__span.ptr = (uint8*)Error__convert.Get();
    Error__span.size = Error__convert.Length();
    Discord_ClientResult_SetError(&instance, Error__span);

#endif
}
int32 UDiscordClientResult::ErrorCode()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - ClientResult::ErrorCode getter cannot be called"));
    std::terminate();
#else
    int32_t returnValue__;
    returnValue__ = Discord_ClientResult_ErrorCode(&instance);
    return returnValue__;

#endif
}
void UDiscordClientResult::SetErrorCode(int32 ErrorCode)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - ClientResult::SetErrorCode cannot be called"));
    std::terminate();
#else
    Discord_ClientResult_SetErrorCode(&instance, ErrorCode);

#endif
}
int32 UDiscordClientResult::Status()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - ClientResult::Status getter cannot be called"));
    std::terminate();
#else
    Discord_HttpStatusCode returnValue__;
    returnValue__ = Discord_ClientResult_Status(&instance);
    return returnValue__;

#endif
}
void UDiscordClientResult::SetStatus(int32 Status)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - ClientResult::SetStatus cannot be called"));
    std::terminate();
#else
    Discord_ClientResult_SetStatus(&instance, static_cast<Discord_HttpStatusCode>(Status));

#endif
}
FString UDiscordClientResult::ResponseBody()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - ClientResult::ResponseBody getter cannot be called"));
    std::terminate();
#else
    Discord_String returnValueNative__;
    Discord_ClientResult_ResponseBody(&instance, &returnValueNative__);
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;

#endif
}
void UDiscordClientResult::SetResponseBody(FString ResponseBody)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - ClientResult::SetResponseBody cannot be called"));
    std::terminate();
#else
    Discord_String ResponseBody__span;
    FTCHARToUTF8 ResponseBody__convert(*ResponseBody);
    ResponseBody__span.ptr = (uint8*)ResponseBody__convert.Get();
    ResponseBody__span.size = ResponseBody__convert.Length();
    Discord_ClientResult_SetResponseBody(&instance, ResponseBody__span);

#endif
}
bool UDiscordClientResult::Successful()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - ClientResult::Successful getter cannot be called"));
    std::terminate();
#else
    bool returnValue__;
    returnValue__ = Discord_ClientResult_Successful(&instance);
    return returnValue__;

#endif
}
void UDiscordClientResult::SetSuccessful(bool Successful)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - ClientResult::SetSuccessful cannot be called"));
    std::terminate();
#else
    Discord_ClientResult_SetSuccessful(&instance, Successful);

#endif
}
bool UDiscordClientResult::Retryable()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - ClientResult::Retryable getter cannot be called"));
    std::terminate();
#else
    bool returnValue__;
    returnValue__ = Discord_ClientResult_Retryable(&instance);
    return returnValue__;

#endif
}
void UDiscordClientResult::SetRetryable(bool Retryable)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - ClientResult::SetRetryable cannot be called"));
    std::terminate();
#else
    Discord_ClientResult_SetRetryable(&instance, Retryable);

#endif
}
float UDiscordClientResult::RetryAfter()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - ClientResult::RetryAfter getter cannot be called"));
    std::terminate();
#else
    float returnValue__;
    returnValue__ = Discord_ClientResult_RetryAfter(&instance);
    return returnValue__;

#endif
}
void UDiscordClientResult::SetRetryAfter(float RetryAfter)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - ClientResult::SetRetryAfter cannot be called"));
    std::terminate();
#else
    Discord_ClientResult_SetRetryAfter(&instance, RetryAfter);

#endif
}
UDiscordAuthorizationCodeChallenge::~UDiscordAuthorizationCodeChallenge()
{
    Drop();
}
void UDiscordAuthorizationCodeChallenge::Init()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - AuthorizationCodeChallenge::Init cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Invalid);
    Discord_AuthorizationCodeChallenge_Init(&instance);
    state = DiscordUObjectState::Owned;
#endif
}
void UDiscordAuthorizationCodeChallenge::Drop()
{
#if DISCORD_PARTNER_SDK_STUB
#else
    if (state != DiscordUObjectState::Owned) {
        return;
    }
    Discord_AuthorizationCodeChallenge_Drop(&instance);
    state = DiscordUObjectState::Invalid;
#endif
}
/* TODO: Clone */
EDiscordAuthenticationCodeChallengeMethod UDiscordAuthorizationCodeChallenge::Method()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - AuthorizationCodeChallenge::Method getter "
                "cannot be called"));
    std::terminate();
#else
    Discord_AuthenticationCodeChallengeMethod returnValue__;
    returnValue__ = Discord_AuthorizationCodeChallenge_Method(&instance);
    return static_cast<EDiscordAuthenticationCodeChallengeMethod>(returnValue__);

#endif
}
void UDiscordAuthorizationCodeChallenge::SetMethod(EDiscordAuthenticationCodeChallengeMethod Method)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - AuthorizationCodeChallenge::SetMethod cannot "
                "be called"));
    std::terminate();
#else
    Discord_AuthorizationCodeChallenge_SetMethod(
      &instance, static_cast<Discord_AuthenticationCodeChallengeMethod>(Method));

#endif
}
FString UDiscordAuthorizationCodeChallenge::Challenge()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - AuthorizationCodeChallenge::Challenge getter "
                "cannot be called"));
    std::terminate();
#else
    Discord_String returnValueNative__;
    Discord_AuthorizationCodeChallenge_Challenge(&instance, &returnValueNative__);
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;

#endif
}
void UDiscordAuthorizationCodeChallenge::SetChallenge(FString Challenge)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - AuthorizationCodeChallenge::SetChallenge "
                "cannot be called"));
    std::terminate();
#else
    Discord_String Challenge__span;
    FTCHARToUTF8 Challenge__convert(*Challenge);
    Challenge__span.ptr = (uint8*)Challenge__convert.Get();
    Challenge__span.size = Challenge__convert.Length();
    Discord_AuthorizationCodeChallenge_SetChallenge(&instance, Challenge__span);

#endif
}
UDiscordAuthorizationCodeVerifier::~UDiscordAuthorizationCodeVerifier()
{
    Drop();
}
void UDiscordAuthorizationCodeVerifier::Drop()
{
#if DISCORD_PARTNER_SDK_STUB
#else
    if (state != DiscordUObjectState::Owned) {
        return;
    }
    Discord_AuthorizationCodeVerifier_Drop(&instance);
    state = DiscordUObjectState::Invalid;
#endif
}
/* TODO: Clone */
UDiscordAuthorizationCodeChallenge* UDiscordAuthorizationCodeVerifier::Challenge()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - AuthorizationCodeVerifier::Challenge getter "
                "cannot be called"));
    std::terminate();
#else
    Discord_AuthorizationCodeChallenge returnValueNative__;
    UDiscordAuthorizationCodeChallenge* returnValue__ = nullptr;
    Discord_AuthorizationCodeVerifier_Challenge(&instance, &returnValueNative__);
    returnValue__ = NewObject<UDiscordAuthorizationCodeChallenge>();
    returnValue__->instance = returnValueNative__;
    returnValue__->state = DiscordUObjectState::Owned;
    return returnValue__;

#endif
}
void UDiscordAuthorizationCodeVerifier::SetChallenge(UDiscordAuthorizationCodeChallenge* Challenge)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - AuthorizationCodeVerifier::SetChallenge "
                "cannot be called"));
    std::terminate();
#else
    Discord_AuthorizationCodeChallenge* Challenge__instance =
      Challenge ? &Challenge->instance : nullptr;
    Discord_AuthorizationCodeVerifier_SetChallenge(&instance, Challenge__instance);

#endif
}
FString UDiscordAuthorizationCodeVerifier::Verifier()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - AuthorizationCodeVerifier::Verifier getter "
                "cannot be called"));
    std::terminate();
#else
    Discord_String returnValueNative__;
    Discord_AuthorizationCodeVerifier_Verifier(&instance, &returnValueNative__);
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;

#endif
}
void UDiscordAuthorizationCodeVerifier::SetVerifier(FString Verifier)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - AuthorizationCodeVerifier::SetVerifier "
                "cannot be called"));
    std::terminate();
#else
    Discord_String Verifier__span;
    FTCHARToUTF8 Verifier__convert(*Verifier);
    Verifier__span.ptr = (uint8*)Verifier__convert.Get();
    Verifier__span.size = Verifier__convert.Length();
    Discord_AuthorizationCodeVerifier_SetVerifier(&instance, Verifier__span);

#endif
}
UDiscordAuthorizationArgs::~UDiscordAuthorizationArgs()
{
    Drop();
}
void UDiscordAuthorizationArgs::Init()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - AuthorizationArgs::Init cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Invalid);
    Discord_AuthorizationArgs_Init(&instance);
    state = DiscordUObjectState::Owned;
#endif
}
void UDiscordAuthorizationArgs::Drop()
{
#if DISCORD_PARTNER_SDK_STUB
#else
    if (state != DiscordUObjectState::Owned) {
        return;
    }
    Discord_AuthorizationArgs_Drop(&instance);
    state = DiscordUObjectState::Invalid;
#endif
}
/* TODO: Clone */
FDiscordUniqueID UDiscordAuthorizationArgs::ClientId()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - AuthorizationArgs::ClientId getter cannot be "
                "called"));
    std::terminate();
#else
    uint64_t returnValue__;
    returnValue__ = Discord_AuthorizationArgs_ClientId(&instance);
    return returnValue__;

#endif
}
void UDiscordAuthorizationArgs::SetClientId(FDiscordUniqueID ClientId)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - AuthorizationArgs::SetClientId cannot be called"));
    std::terminate();
#else
    Discord_AuthorizationArgs_SetClientId(&instance, ClientId);

#endif
}
FString UDiscordAuthorizationArgs::Scopes()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - AuthorizationArgs::Scopes getter cannot be called"));
    std::terminate();
#else
    Discord_String returnValueNative__;
    Discord_AuthorizationArgs_Scopes(&instance, &returnValueNative__);
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;

#endif
}
void UDiscordAuthorizationArgs::SetScopes(FString Scopes)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - AuthorizationArgs::SetScopes cannot be called"));
    std::terminate();
#else
    Discord_String Scopes__span;
    FTCHARToUTF8 Scopes__convert(*Scopes);
    Scopes__span.ptr = (uint8*)Scopes__convert.Get();
    Scopes__span.size = Scopes__convert.Length();
    Discord_AuthorizationArgs_SetScopes(&instance, Scopes__span);

#endif
}
FString UDiscordAuthorizationArgs::State()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - AuthorizationArgs::State getter cannot be called"));
    std::terminate();
#else
    bool __returnIsNonNull;
    Discord_String returnValueNative__;
    __returnIsNonNull = Discord_AuthorizationArgs_State(&instance, &returnValueNative__);
    if (!__returnIsNonNull) {
        return {};
    }
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;

#endif
}
void UDiscordAuthorizationArgs::SetState(FString State)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - AuthorizationArgs::SetState cannot be called"));
    std::terminate();
#else
    Discord_String State__span;
    FTCHARToUTF8 State__convert(*State);
    State__span.ptr = (uint8*)State__convert.Get();
    State__span.size = State__convert.Length();
    Discord_AuthorizationArgs_SetState(&instance, &State__span);

#endif
}
FString UDiscordAuthorizationArgs::Nonce()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - AuthorizationArgs::Nonce getter cannot be called"));
    std::terminate();
#else
    bool __returnIsNonNull;
    Discord_String returnValueNative__;
    __returnIsNonNull = Discord_AuthorizationArgs_Nonce(&instance, &returnValueNative__);
    if (!__returnIsNonNull) {
        return {};
    }
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;

#endif
}
void UDiscordAuthorizationArgs::SetNonce(FString Nonce)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - AuthorizationArgs::SetNonce cannot be called"));
    std::terminate();
#else
    Discord_String Nonce__span;
    FTCHARToUTF8 Nonce__convert(*Nonce);
    Nonce__span.ptr = (uint8*)Nonce__convert.Get();
    Nonce__span.size = Nonce__convert.Length();
    Discord_AuthorizationArgs_SetNonce(&instance, &Nonce__span);

#endif
}
UDiscordAuthorizationCodeChallenge* UDiscordAuthorizationArgs::CodeChallenge()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - AuthorizationArgs::CodeChallenge getter "
                "cannot be called"));
    std::terminate();
#else
    bool __returnIsNonNull;
    Discord_AuthorizationCodeChallenge returnValueNative__;
    UDiscordAuthorizationCodeChallenge* returnValue__ = nullptr;
    __returnIsNonNull = Discord_AuthorizationArgs_CodeChallenge(&instance, &returnValueNative__);
    if (!__returnIsNonNull) {
        return {};
    }
    returnValue__ = NewObject<UDiscordAuthorizationCodeChallenge>();
    returnValue__->instance = returnValueNative__;
    returnValue__->state = DiscordUObjectState::Owned;
    return returnValue__;

#endif
}
void UDiscordAuthorizationArgs::SetCodeChallenge(UDiscordAuthorizationCodeChallenge* CodeChallenge)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - AuthorizationArgs::SetCodeChallenge cannot "
                "be called"));
    std::terminate();
#else
    Discord_AuthorizationCodeChallenge* CodeChallenge__instance =
      CodeChallenge ? &CodeChallenge->instance : nullptr;
    Discord_AuthorizationArgs_SetCodeChallenge(&instance, CodeChallenge__instance);

#endif
}
EDiscordIntegrationType UDiscordAuthorizationArgs::IntegrationType()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - AuthorizationArgs::IntegrationType getter "
                "cannot be called"));
    std::terminate();
#else
    bool __returnIsNonNull;
    Discord_IntegrationType __returnValue{};
    __returnIsNonNull = Discord_AuthorizationArgs_IntegrationType(&instance, &__returnValue);
    if (!__returnIsNonNull) {
        return {};
    }
    return static_cast<EDiscordIntegrationType>(__returnValue);

#endif
}
void UDiscordAuthorizationArgs::SetIntegrationType(EDiscordIntegrationType IntegrationType)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - AuthorizationArgs::SetIntegrationType cannot "
                "be called"));
    std::terminate();
#else
    Discord_IntegrationType discordIntegrationType =
      static_cast<Discord_IntegrationType>(static_cast<uint8_t>(IntegrationType));
    Discord_AuthorizationArgs_SetIntegrationType(&instance, &discordIntegrationType);

#endif
}
FString UDiscordAuthorizationArgs::CustomSchemeParam()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - AuthorizationArgs::CustomSchemeParam getter "
                "cannot be called"));
    std::terminate();
#else
    bool __returnIsNonNull;
    Discord_String returnValueNative__;
    __returnIsNonNull =
      Discord_AuthorizationArgs_CustomSchemeParam(&instance, &returnValueNative__);
    if (!__returnIsNonNull) {
        return {};
    }
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;

#endif
}
void UDiscordAuthorizationArgs::SetCustomSchemeParam(FString CustomSchemeParam)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - AuthorizationArgs::SetCustomSchemeParam "
                "cannot be called"));
    std::terminate();
#else
    Discord_String CustomSchemeParam__span;
    FTCHARToUTF8 CustomSchemeParam__convert(*CustomSchemeParam);
    CustomSchemeParam__span.ptr = (uint8*)CustomSchemeParam__convert.Get();
    CustomSchemeParam__span.size = CustomSchemeParam__convert.Length();
    Discord_AuthorizationArgs_SetCustomSchemeParam(&instance, &CustomSchemeParam__span);

#endif
}
UDiscordDeviceAuthorizationArgs::~UDiscordDeviceAuthorizationArgs()
{
    Drop();
}
void UDiscordDeviceAuthorizationArgs::Init()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - DeviceAuthorizationArgs::Init cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Invalid);
    Discord_DeviceAuthorizationArgs_Init(&instance);
    state = DiscordUObjectState::Owned;
#endif
}
void UDiscordDeviceAuthorizationArgs::Drop()
{
#if DISCORD_PARTNER_SDK_STUB
#else
    if (state != DiscordUObjectState::Owned) {
        return;
    }
    Discord_DeviceAuthorizationArgs_Drop(&instance);
    state = DiscordUObjectState::Invalid;
#endif
}
/* TODO: Clone */
FDiscordUniqueID UDiscordDeviceAuthorizationArgs::ClientId()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - DeviceAuthorizationArgs::ClientId getter "
                "cannot be called"));
    std::terminate();
#else
    uint64_t returnValue__;
    returnValue__ = Discord_DeviceAuthorizationArgs_ClientId(&instance);
    return returnValue__;

#endif
}
void UDiscordDeviceAuthorizationArgs::SetClientId(FDiscordUniqueID ClientId)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - DeviceAuthorizationArgs::SetClientId cannot "
                "be called"));
    std::terminate();
#else
    Discord_DeviceAuthorizationArgs_SetClientId(&instance, ClientId);

#endif
}
FString UDiscordDeviceAuthorizationArgs::Scopes()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - DeviceAuthorizationArgs::Scopes getter "
                "cannot be called"));
    std::terminate();
#else
    Discord_String returnValueNative__;
    Discord_DeviceAuthorizationArgs_Scopes(&instance, &returnValueNative__);
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;

#endif
}
void UDiscordDeviceAuthorizationArgs::SetScopes(FString Scopes)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - DeviceAuthorizationArgs::SetScopes cannot be "
                "called"));
    std::terminate();
#else
    Discord_String Scopes__span;
    FTCHARToUTF8 Scopes__convert(*Scopes);
    Scopes__span.ptr = (uint8*)Scopes__convert.Get();
    Scopes__span.size = Scopes__convert.Length();
    Discord_DeviceAuthorizationArgs_SetScopes(&instance, Scopes__span);

#endif
}
UDiscordVoiceStateHandle::~UDiscordVoiceStateHandle()
{
    Drop();
}
void UDiscordVoiceStateHandle::Drop()
{
#if DISCORD_PARTNER_SDK_STUB
#else
    if (state != DiscordUObjectState::Owned) {
        return;
    }
    Discord_VoiceStateHandle_Drop(&instance);
    state = DiscordUObjectState::Invalid;
#endif
}
/* TODO: Clone */
bool UDiscordVoiceStateHandle::SelfDeaf()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - VoiceStateHandle::SelfDeaf cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool returnValue__;
    returnValue__ = Discord_VoiceStateHandle_SelfDeaf(&instance);
    return returnValue__;
#endif
}
bool UDiscordVoiceStateHandle::SelfMute()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - VoiceStateHandle::SelfMute cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool returnValue__;
    returnValue__ = Discord_VoiceStateHandle_SelfMute(&instance);
    return returnValue__;
#endif
}
UDiscordVADThresholdSettings::~UDiscordVADThresholdSettings()
{
    Drop();
}
void UDiscordVADThresholdSettings::Drop()
{
#if DISCORD_PARTNER_SDK_STUB
#else
    if (state != DiscordUObjectState::Owned) {
        return;
    }
    Discord_VADThresholdSettings_Drop(&instance);
    state = DiscordUObjectState::Invalid;
#endif
}
float UDiscordVADThresholdSettings::VadThreshold()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - VADThresholdSettings::VadThreshold getter "
                "cannot be called"));
    std::terminate();
#else
    float returnValue__;
    returnValue__ = Discord_VADThresholdSettings_VadThreshold(&instance);
    return returnValue__;

#endif
}
void UDiscordVADThresholdSettings::SetVadThreshold(float VadThreshold)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - VADThresholdSettings::SetVadThreshold cannot "
                "be called"));
    std::terminate();
#else
    Discord_VADThresholdSettings_SetVadThreshold(&instance, VadThreshold);

#endif
}
bool UDiscordVADThresholdSettings::Automatic()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - VADThresholdSettings::Automatic getter "
                "cannot be called"));
    std::terminate();
#else
    bool returnValue__;
    returnValue__ = Discord_VADThresholdSettings_Automatic(&instance);
    return returnValue__;

#endif
}
void UDiscordVADThresholdSettings::SetAutomatic(bool Automatic)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - VADThresholdSettings::SetAutomatic cannot be "
                "called"));
    std::terminate();
#else
    Discord_VADThresholdSettings_SetAutomatic(&instance, Automatic);

#endif
}
UDiscordCall::~UDiscordCall()
{
    Drop();
}
void UDiscordCall::Drop()
{
#if DISCORD_PARTNER_SDK_STUB
#else
    if (state != DiscordUObjectState::Owned) {
        return;
    }
    Discord_Call_Drop(&instance);
    state = DiscordUObjectState::Invalid;
#endif
}
/* TODO: Clone */
/* static */ FString UDiscordCall::ErrorToString(EDiscordCallError type)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Call::ErrorToString cannot be called"));
    std::terminate();
#else
    Discord_String returnValueNative__;
    Discord_Call_ErrorToString(static_cast<Discord_Call_Error>(type), &returnValueNative__);
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;
#endif
}
EDiscordAudioModeType UDiscordCall::GetAudioMode()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - Call::GetAudioMode cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_AudioModeType returnValue__;
    returnValue__ = Discord_Call_GetAudioMode(&instance);
    return static_cast<EDiscordAudioModeType>(returnValue__);
#endif
}
FDiscordUniqueID UDiscordCall::GetChannelId()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - Call::GetChannelId cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    uint64_t returnValue__;
    returnValue__ = Discord_Call_GetChannelId(&instance);
    return returnValue__;
#endif
}
FDiscordUniqueID UDiscordCall::GetGuildId()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - Call::GetGuildId cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    uint64_t returnValue__;
    returnValue__ = Discord_Call_GetGuildId(&instance);
    return returnValue__;
#endif
}
bool UDiscordCall::GetLocalMute(FDiscordUniqueID userId)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - Call::GetLocalMute cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool returnValue__;
    returnValue__ = Discord_Call_GetLocalMute(&instance, userId);
    return returnValue__;
#endif
}
TArray<FDiscordUniqueID> UDiscordCall::GetParticipants()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Call::GetParticipants cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_UInt64Span returnValueNative__;
    Discord_Call_GetParticipants(&instance, &returnValueNative__);
    TArray<FDiscordUniqueID> returnValue__;
    returnValue__.Reserve(returnValueNative__.size);
    for (size_t i__ = 0; i__ < returnValueNative__.size; ++i__) {
        returnValue__.Add(FDiscordUniqueID(returnValueNative__.ptr[i__]));
    }
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;
#endif
}
float UDiscordCall::GetParticipantVolume(FDiscordUniqueID userId)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Call::GetParticipantVolume cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    float returnValue__;
    returnValue__ = Discord_Call_GetParticipantVolume(&instance, userId);
    return returnValue__;
#endif
}
bool UDiscordCall::GetPTTActive()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - Call::GetPTTActive cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool returnValue__;
    returnValue__ = Discord_Call_GetPTTActive(&instance);
    return returnValue__;
#endif
}
int32 UDiscordCall::GetPTTReleaseDelay()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Call::GetPTTReleaseDelay cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    uint32_t returnValue__;
    returnValue__ = Discord_Call_GetPTTReleaseDelay(&instance);
    return returnValue__;
#endif
}
bool UDiscordCall::GetSelfDeaf()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - Call::GetSelfDeaf cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool returnValue__;
    returnValue__ = Discord_Call_GetSelfDeaf(&instance);
    return returnValue__;
#endif
}
bool UDiscordCall::GetSelfMute()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - Call::GetSelfMute cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool returnValue__;
    returnValue__ = Discord_Call_GetSelfMute(&instance);
    return returnValue__;
#endif
}
EDiscordCallStatus UDiscordCall::GetStatus()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - Call::GetStatus cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_Call_Status returnValue__;
    returnValue__ = Discord_Call_GetStatus(&instance);
    return static_cast<EDiscordCallStatus>(returnValue__);
#endif
}
UDiscordVADThresholdSettings* UDiscordCall::GetVADThreshold()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Call::GetVADThreshold cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_VADThresholdSettings returnValueNative__;
    UDiscordVADThresholdSettings* returnValue__ = nullptr;
    Discord_Call_GetVADThreshold(&instance, &returnValueNative__);
    returnValue__ = NewObject<UDiscordVADThresholdSettings>();
    returnValue__->instance = returnValueNative__;
    returnValue__->state = DiscordUObjectState::Owned;
    return returnValue__;
#endif
}
UDiscordVoiceStateHandle* UDiscordCall::GetVoiceStateHandle(FDiscordUniqueID userId)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Call::GetVoiceStateHandle cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool __returnIsNonNull;
    Discord_VoiceStateHandle returnValueNative__;
    UDiscordVoiceStateHandle* returnValue__ = nullptr;
    __returnIsNonNull = Discord_Call_GetVoiceStateHandle(&instance, userId, &returnValueNative__);
    if (!__returnIsNonNull) {
        return {};
    }
    returnValue__ = NewObject<UDiscordVoiceStateHandle>();
    returnValue__->instance = returnValueNative__;
    returnValue__->state = DiscordUObjectState::Owned;
    return returnValue__;
#endif
}
void UDiscordCall::SetAudioMode(EDiscordAudioModeType audioMode)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - Call::SetAudioMode cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_Call_SetAudioMode(&instance, static_cast<Discord_AudioModeType>(audioMode));
#endif
}
void UDiscordCall::SetLocalMute(FDiscordUniqueID userId, bool mute)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - Call::SetLocalMute cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_Call_SetLocalMute(&instance, userId, mute);
#endif
}
void UDiscordCall::SetOnVoiceStateChangedCallback(FDiscordCallOnVoiceStateChanged const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Call::SetOnVoiceStateChangedCallback cannot "
                "be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Call_OnVoiceStateChanged cb__native = [](auto userId, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        userData__typed->delegate.ExecuteIfBound(userId);
    };
    Discord_Call_SetOnVoiceStateChangedCallback(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordCall::SetOnVoiceStateChangedCallback(FDiscordCallOnVoiceStateChangedDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Call::SetOnVoiceStateChangedCallback cannot "
                "be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Call_OnVoiceStateChanged cb__native = [](auto userId, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        userData__typed->delegate.ExecuteIfBound(userId);
    };
    Discord_Call_SetOnVoiceStateChangedCallback(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordCall::SetParticipantChangedCallback(FDiscordCallOnParticipantChanged const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Call::SetParticipantChangedCallback cannot "
                "be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Call_OnParticipantChanged cb__native = [](auto userId, auto added, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        userData__typed->delegate.ExecuteIfBound(userId, added);
    };
    Discord_Call_SetParticipantChangedCallback(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordCall::SetParticipantChangedCallback(FDiscordCallOnParticipantChangedDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Call::SetParticipantChangedCallback cannot "
                "be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Call_OnParticipantChanged cb__native = [](auto userId, auto added, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        userData__typed->delegate.ExecuteIfBound(userId, added);
    };
    Discord_Call_SetParticipantChangedCallback(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordCall::SetParticipantVolume(FDiscordUniqueID userId, float volume)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Call::SetParticipantVolume cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_Call_SetParticipantVolume(&instance, userId, volume);
#endif
}
void UDiscordCall::SetPTTActive(bool active)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - Call::SetPTTActive cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_Call_SetPTTActive(&instance, active);
#endif
}
void UDiscordCall::SetPTTReleaseDelay(int32 releaseDelayMs)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Call::SetPTTReleaseDelay cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_Call_SetPTTReleaseDelay(&instance, releaseDelayMs);
#endif
}
void UDiscordCall::SetSelfDeaf(bool deaf)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - Call::SetSelfDeaf cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_Call_SetSelfDeaf(&instance, deaf);
#endif
}
void UDiscordCall::SetSelfMute(bool mute)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - Call::SetSelfMute cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_Call_SetSelfMute(&instance, mute);
#endif
}
void UDiscordCall::SetSpeakingStatusChangedCallback(FDiscordCallOnSpeakingStatusChanged const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Call::SetSpeakingStatusChangedCallback "
                "cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Call_OnSpeakingStatusChanged cb__native =
      [](auto userId, auto isPlayingSound, void* userData__) {
          auto userData__typed = static_cast<Tcb__UserData*>(userData__);
          userData__typed->delegate.ExecuteIfBound(userId, isPlayingSound);
      };
    Discord_Call_SetSpeakingStatusChangedCallback(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordCall::SetSpeakingStatusChangedCallback(
  FDiscordCallOnSpeakingStatusChangedDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Call::SetSpeakingStatusChangedCallback "
                "cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Call_OnSpeakingStatusChanged cb__native =
      [](auto userId, auto isPlayingSound, void* userData__) {
          auto userData__typed = static_cast<Tcb__UserData*>(userData__);
          userData__typed->delegate.ExecuteIfBound(userId, isPlayingSound);
      };
    Discord_Call_SetSpeakingStatusChangedCallback(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordCall::SetStatusChangedCallback(FDiscordCallOnStatusChanged const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Call::SetStatusChangedCallback cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Call_OnStatusChanged cb__native =
      [](auto status, auto error, auto errorDetail, void* userData__) {
          auto userData__typed = static_cast<Tcb__UserData*>(userData__);
          userData__typed->delegate.ExecuteIfBound(static_cast<EDiscordCallStatus>(status),
                                                   static_cast<EDiscordCallError>(error),
                                                   errorDetail);
      };
    Discord_Call_SetStatusChangedCallback(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordCall::SetStatusChangedCallback(FDiscordCallOnStatusChangedDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Call::SetStatusChangedCallback cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Call_OnStatusChanged cb__native =
      [](auto status, auto error, auto errorDetail, void* userData__) {
          auto userData__typed = static_cast<Tcb__UserData*>(userData__);
          userData__typed->delegate.ExecuteIfBound(static_cast<EDiscordCallStatus>(status),
                                                   static_cast<EDiscordCallError>(error),
                                                   errorDetail);
      };
    Discord_Call_SetStatusChangedCallback(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordCall::SetVADThreshold(bool automatic, float threshold)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Call::SetVADThreshold cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_Call_SetVADThreshold(&instance, automatic, threshold);
#endif
}
/* static */ FString UDiscordCall::StatusToString(EDiscordCallStatus type)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Call::StatusToString cannot be called"));
    std::terminate();
#else
    Discord_String returnValueNative__;
    Discord_Call_StatusToString(static_cast<Discord_Call_Status>(type), &returnValueNative__);
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;
#endif
}
UDiscordChannelHandle::~UDiscordChannelHandle()
{
    Drop();
}
void UDiscordChannelHandle::Drop()
{
#if DISCORD_PARTNER_SDK_STUB
#else
    if (state != DiscordUObjectState::Owned) {
        return;
    }
    Discord_ChannelHandle_Drop(&instance);
    state = DiscordUObjectState::Invalid;
#endif
}
/* TODO: Clone */
#if DISCORD_DEBUG_API_ENABLED
UDiscordCallInfoHandle* UDiscordChannelHandle::GetCallInfoHandle()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - ChannelHandle::GetCallInfoHandle cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool __returnIsNonNull;
    Discord_CallInfoHandle returnValueNative__;
    UDiscordCallInfoHandle* returnValue__ = nullptr;
    __returnIsNonNull = Discord_ChannelHandle_GetCallInfoHandle(&instance, &returnValueNative__);
    if (!__returnIsNonNull) {
        return {};
    }
    returnValue__ = NewObject<UDiscordCallInfoHandle>();
    returnValue__->instance = returnValueNative__;
    returnValue__->state = DiscordUObjectState::Owned;
    return returnValue__;
#endif
}
#endif
FDiscordUniqueID UDiscordChannelHandle::Id()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - ChannelHandle::Id cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    uint64_t returnValue__;
    returnValue__ = Discord_ChannelHandle_Id(&instance);
    return returnValue__;
#endif
}
FString UDiscordChannelHandle::Name()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - ChannelHandle::Name cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String returnValueNative__;
    Discord_ChannelHandle_Name(&instance, &returnValueNative__);
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;
#endif
}
TArray<FDiscordUniqueID> UDiscordChannelHandle::Recipients()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - ChannelHandle::Recipients cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_UInt64Span returnValueNative__;
    Discord_ChannelHandle_Recipients(&instance, &returnValueNative__);
    TArray<FDiscordUniqueID> returnValue__;
    returnValue__.Reserve(returnValueNative__.size);
    for (size_t i__ = 0; i__ < returnValueNative__.size; ++i__) {
        returnValue__.Add(FDiscordUniqueID(returnValueNative__.ptr[i__]));
    }
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;
#endif
}
EDiscordChannelType UDiscordChannelHandle::Type()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - ChannelHandle::Type cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_ChannelType returnValue__;
    returnValue__ = Discord_ChannelHandle_Type(&instance);
    return static_cast<EDiscordChannelType>(returnValue__);
#endif
}
UDiscordGuildMinimal::~UDiscordGuildMinimal()
{
    Drop();
}
void UDiscordGuildMinimal::Drop()
{
#if DISCORD_PARTNER_SDK_STUB
#else
    if (state != DiscordUObjectState::Owned) {
        return;
    }
    Discord_GuildMinimal_Drop(&instance);
    state = DiscordUObjectState::Invalid;
#endif
}
/* TODO: Clone */
FDiscordUniqueID UDiscordGuildMinimal::Id()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - GuildMinimal::Id getter cannot be called"));
    std::terminate();
#else
    uint64_t returnValue__;
    returnValue__ = Discord_GuildMinimal_Id(&instance);
    return returnValue__;

#endif
}
void UDiscordGuildMinimal::SetId(FDiscordUniqueID Id)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - GuildMinimal::SetId cannot be called"));
    std::terminate();
#else
    Discord_GuildMinimal_SetId(&instance, Id);

#endif
}
FString UDiscordGuildMinimal::Name()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - GuildMinimal::Name getter cannot be called"));
    std::terminate();
#else
    Discord_String returnValueNative__;
    Discord_GuildMinimal_Name(&instance, &returnValueNative__);
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;

#endif
}
void UDiscordGuildMinimal::SetName(FString Name)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - GuildMinimal::SetName cannot be called"));
    std::terminate();
#else
    Discord_String Name__span;
    FTCHARToUTF8 Name__convert(*Name);
    Name__span.ptr = (uint8*)Name__convert.Get();
    Name__span.size = Name__convert.Length();
    Discord_GuildMinimal_SetName(&instance, Name__span);

#endif
}
UDiscordGuildChannel::~UDiscordGuildChannel()
{
    Drop();
}
void UDiscordGuildChannel::Drop()
{
#if DISCORD_PARTNER_SDK_STUB
#else
    if (state != DiscordUObjectState::Owned) {
        return;
    }
    Discord_GuildChannel_Drop(&instance);
    state = DiscordUObjectState::Invalid;
#endif
}
/* TODO: Clone */
FDiscordUniqueID UDiscordGuildChannel::Id()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - GuildChannel::Id getter cannot be called"));
    std::terminate();
#else
    uint64_t returnValue__;
    returnValue__ = Discord_GuildChannel_Id(&instance);
    return returnValue__;

#endif
}
void UDiscordGuildChannel::SetId(FDiscordUniqueID Id)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - GuildChannel::SetId cannot be called"));
    std::terminate();
#else
    Discord_GuildChannel_SetId(&instance, Id);

#endif
}
FString UDiscordGuildChannel::Name()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - GuildChannel::Name getter cannot be called"));
    std::terminate();
#else
    Discord_String returnValueNative__;
    Discord_GuildChannel_Name(&instance, &returnValueNative__);
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;

#endif
}
void UDiscordGuildChannel::SetName(FString Name)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - GuildChannel::SetName cannot be called"));
    std::terminate();
#else
    Discord_String Name__span;
    FTCHARToUTF8 Name__convert(*Name);
    Name__span.ptr = (uint8*)Name__convert.Get();
    Name__span.size = Name__convert.Length();
    Discord_GuildChannel_SetName(&instance, Name__span);

#endif
}
EDiscordChannelType UDiscordGuildChannel::Type()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - GuildChannel::Type getter cannot be called"));
    std::terminate();
#else
    Discord_ChannelType returnValue__;
    returnValue__ = Discord_GuildChannel_Type(&instance);
    return static_cast<EDiscordChannelType>(returnValue__);

#endif
}
void UDiscordGuildChannel::SetType(EDiscordChannelType Type)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - GuildChannel::SetType cannot be called"));
    std::terminate();
#else
    Discord_GuildChannel_SetType(&instance, static_cast<Discord_ChannelType>(Type));

#endif
}
int32 UDiscordGuildChannel::Position()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - GuildChannel::Position getter cannot be called"));
    std::terminate();
#else
    int32_t returnValue__;
    returnValue__ = Discord_GuildChannel_Position(&instance);
    return returnValue__;

#endif
}
void UDiscordGuildChannel::SetPosition(int32 Position)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - GuildChannel::SetPosition cannot be called"));
    std::terminate();
#else
    Discord_GuildChannel_SetPosition(&instance, Position);

#endif
}
FDiscordUniqueID UDiscordGuildChannel::ParentId()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - GuildChannel::ParentId getter cannot be called"));
    std::terminate();
#else
    bool __returnIsNonNull;
    uint64_t __returnValue{};
    __returnIsNonNull = Discord_GuildChannel_ParentId(&instance, &__returnValue);
    if (!__returnIsNonNull) {
        return {};
    }
    return __returnValue;

#endif
}
void UDiscordGuildChannel::SetParentId(FDiscordUniqueID ParentId)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - GuildChannel::SetParentId cannot be called"));
    std::terminate();
#else
    uint64_t ParentId__optional = ParentId;
    Discord_GuildChannel_SetParentId(&instance, &ParentId__optional);

#endif
}
bool UDiscordGuildChannel::IsLinkable()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - GuildChannel::IsLinkable getter cannot be called"));
    std::terminate();
#else
    bool returnValue__;
    returnValue__ = Discord_GuildChannel_IsLinkable(&instance);
    return returnValue__;

#endif
}
void UDiscordGuildChannel::SetIsLinkable(bool IsLinkable)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - GuildChannel::SetIsLinkable cannot be called"));
    std::terminate();
#else
    Discord_GuildChannel_SetIsLinkable(&instance, IsLinkable);

#endif
}
bool UDiscordGuildChannel::IsViewableAndWriteableByAllMembers()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - "
                "GuildChannel::IsViewableAndWriteableByAllMembers getter cannot be called"));
    std::terminate();
#else
    bool returnValue__;
    returnValue__ = Discord_GuildChannel_IsViewableAndWriteableByAllMembers(&instance);
    return returnValue__;

#endif
}
void UDiscordGuildChannel::SetIsViewableAndWriteableByAllMembers(
  bool IsViewableAndWriteableByAllMembers)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - "
                "GuildChannel::SetIsViewableAndWriteableByAllMembers cannot be called"));
    std::terminate();
#else
    Discord_GuildChannel_SetIsViewableAndWriteableByAllMembers(&instance,
                                                               IsViewableAndWriteableByAllMembers);

#endif
}
UDiscordLinkedLobby* UDiscordGuildChannel::LinkedLobby()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - GuildChannel::LinkedLobby getter cannot be called"));
    std::terminate();
#else
    bool __returnIsNonNull;
    Discord_LinkedLobby returnValueNative__;
    UDiscordLinkedLobby* returnValue__ = nullptr;
    __returnIsNonNull = Discord_GuildChannel_LinkedLobby(&instance, &returnValueNative__);
    if (!__returnIsNonNull) {
        return {};
    }
    returnValue__ = NewObject<UDiscordLinkedLobby>();
    returnValue__->instance = returnValueNative__;
    returnValue__->state = DiscordUObjectState::Owned;
    return returnValue__;

#endif
}
void UDiscordGuildChannel::SetLinkedLobby(UDiscordLinkedLobby* LinkedLobby)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - GuildChannel::SetLinkedLobby cannot be called"));
    std::terminate();
#else
    Discord_LinkedLobby* LinkedLobby__instance = LinkedLobby ? &LinkedLobby->instance : nullptr;
    Discord_GuildChannel_SetLinkedLobby(&instance, LinkedLobby__instance);

#endif
}
UDiscordLinkedLobby::~UDiscordLinkedLobby()
{
    Drop();
}
void UDiscordLinkedLobby::Init()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - LinkedLobby::Init cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Invalid);
    Discord_LinkedLobby_Init(&instance);
    state = DiscordUObjectState::Owned;
#endif
}
void UDiscordLinkedLobby::Drop()
{
#if DISCORD_PARTNER_SDK_STUB
#else
    if (state != DiscordUObjectState::Owned) {
        return;
    }
    Discord_LinkedLobby_Drop(&instance);
    state = DiscordUObjectState::Invalid;
#endif
}
/* TODO: Clone */
FDiscordUniqueID UDiscordLinkedLobby::ApplicationId()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - LinkedLobby::ApplicationId getter cannot be called"));
    std::terminate();
#else
    uint64_t returnValue__;
    returnValue__ = Discord_LinkedLobby_ApplicationId(&instance);
    return returnValue__;

#endif
}
void UDiscordLinkedLobby::SetApplicationId(FDiscordUniqueID ApplicationId)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - LinkedLobby::SetApplicationId cannot be called"));
    std::terminate();
#else
    Discord_LinkedLobby_SetApplicationId(&instance, ApplicationId);

#endif
}
FDiscordUniqueID UDiscordLinkedLobby::LobbyId()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - LinkedLobby::LobbyId getter cannot be called"));
    std::terminate();
#else
    uint64_t returnValue__;
    returnValue__ = Discord_LinkedLobby_LobbyId(&instance);
    return returnValue__;

#endif
}
void UDiscordLinkedLobby::SetLobbyId(FDiscordUniqueID LobbyId)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - LinkedLobby::SetLobbyId cannot be called"));
    std::terminate();
#else
    Discord_LinkedLobby_SetLobbyId(&instance, LobbyId);

#endif
}
UDiscordLinkedChannel::~UDiscordLinkedChannel()
{
    Drop();
}
void UDiscordLinkedChannel::Drop()
{
#if DISCORD_PARTNER_SDK_STUB
#else
    if (state != DiscordUObjectState::Owned) {
        return;
    }
    Discord_LinkedChannel_Drop(&instance);
    state = DiscordUObjectState::Invalid;
#endif
}
/* TODO: Clone */
FDiscordUniqueID UDiscordLinkedChannel::Id()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - LinkedChannel::Id getter cannot be called"));
    std::terminate();
#else
    uint64_t returnValue__;
    returnValue__ = Discord_LinkedChannel_Id(&instance);
    return returnValue__;

#endif
}
void UDiscordLinkedChannel::SetId(FDiscordUniqueID Id)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - LinkedChannel::SetId cannot be called"));
    std::terminate();
#else
    Discord_LinkedChannel_SetId(&instance, Id);

#endif
}
FString UDiscordLinkedChannel::Name()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - LinkedChannel::Name getter cannot be called"));
    std::terminate();
#else
    Discord_String returnValueNative__;
    Discord_LinkedChannel_Name(&instance, &returnValueNative__);
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;

#endif
}
void UDiscordLinkedChannel::SetName(FString Name)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - LinkedChannel::SetName cannot be called"));
    std::terminate();
#else
    Discord_String Name__span;
    FTCHARToUTF8 Name__convert(*Name);
    Name__span.ptr = (uint8*)Name__convert.Get();
    Name__span.size = Name__convert.Length();
    Discord_LinkedChannel_SetName(&instance, Name__span);

#endif
}
FDiscordUniqueID UDiscordLinkedChannel::GuildId()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - LinkedChannel::GuildId getter cannot be called"));
    std::terminate();
#else
    uint64_t returnValue__;
    returnValue__ = Discord_LinkedChannel_GuildId(&instance);
    return returnValue__;

#endif
}
void UDiscordLinkedChannel::SetGuildId(FDiscordUniqueID GuildId)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - LinkedChannel::SetGuildId cannot be called"));
    std::terminate();
#else
    Discord_LinkedChannel_SetGuildId(&instance, GuildId);

#endif
}
UDiscordRelationshipHandle::~UDiscordRelationshipHandle()
{
    Drop();
}
void UDiscordRelationshipHandle::Drop()
{
#if DISCORD_PARTNER_SDK_STUB
#else
    if (state != DiscordUObjectState::Owned) {
        return;
    }
    Discord_RelationshipHandle_Drop(&instance);
    state = DiscordUObjectState::Invalid;
#endif
}
/* TODO: Clone */
EDiscordRelationshipType UDiscordRelationshipHandle::DiscordRelationshipType()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - RelationshipHandle::DiscordRelationshipType "
                "cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_RelationshipType returnValue__;
    returnValue__ = Discord_RelationshipHandle_DiscordRelationshipType(&instance);
    return static_cast<EDiscordRelationshipType>(returnValue__);
#endif
}
EDiscordRelationshipType UDiscordRelationshipHandle::GameRelationshipType()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - RelationshipHandle::GameRelationshipType "
                "cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_RelationshipType returnValue__;
    returnValue__ = Discord_RelationshipHandle_GameRelationshipType(&instance);
    return static_cast<EDiscordRelationshipType>(returnValue__);
#endif
}
FDiscordUniqueID UDiscordRelationshipHandle::Id()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - RelationshipHandle::Id cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    uint64_t returnValue__;
    returnValue__ = Discord_RelationshipHandle_Id(&instance);
    return returnValue__;
#endif
}
bool UDiscordRelationshipHandle::IsSpamRequest()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - RelationshipHandle::IsSpamRequest cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool returnValue__;
    returnValue__ = Discord_RelationshipHandle_IsSpamRequest(&instance);
    return returnValue__;
#endif
}
UDiscordUserHandle* UDiscordRelationshipHandle::User()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - RelationshipHandle::User cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool __returnIsNonNull;
    Discord_UserHandle returnValueNative__;
    UDiscordUserHandle* returnValue__ = nullptr;
    __returnIsNonNull = Discord_RelationshipHandle_User(&instance, &returnValueNative__);
    if (!__returnIsNonNull) {
        return {};
    }
    returnValue__ = NewObject<UDiscordUserHandle>();
    returnValue__->instance = returnValueNative__;
    returnValue__->state = DiscordUObjectState::Owned;
    return returnValue__;
#endif
}
UDiscordUserApplicationProfileHandle::~UDiscordUserApplicationProfileHandle()
{
    Drop();
}
void UDiscordUserApplicationProfileHandle::Drop()
{
#if DISCORD_PARTNER_SDK_STUB
#else
    if (state != DiscordUObjectState::Owned) {
        return;
    }
    Discord_UserApplicationProfileHandle_Drop(&instance);
    state = DiscordUObjectState::Invalid;
#endif
}
/* TODO: Clone */
FString UDiscordUserApplicationProfileHandle::AvatarHash()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - UserApplicationProfileHandle::AvatarHash "
                "cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String returnValueNative__;
    Discord_UserApplicationProfileHandle_AvatarHash(&instance, &returnValueNative__);
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;
#endif
}
FString UDiscordUserApplicationProfileHandle::Metadata()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - UserApplicationProfileHandle::Metadata "
                "cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String returnValueNative__;
    Discord_UserApplicationProfileHandle_Metadata(&instance, &returnValueNative__);
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;
#endif
}
FString UDiscordUserApplicationProfileHandle::ProviderId()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - UserApplicationProfileHandle::ProviderId "
                "cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool __returnIsNonNull;
    Discord_String returnValueNative__;
    __returnIsNonNull =
      Discord_UserApplicationProfileHandle_ProviderId(&instance, &returnValueNative__);
    if (!__returnIsNonNull) {
        return {};
    }
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;
#endif
}
FString UDiscordUserApplicationProfileHandle::ProviderIssuedUserId()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - "
                "UserApplicationProfileHandle::ProviderIssuedUserId cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String returnValueNative__;
    Discord_UserApplicationProfileHandle_ProviderIssuedUserId(&instance, &returnValueNative__);
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;
#endif
}
EDiscordExternalIdentityProviderType UDiscordUserApplicationProfileHandle::ProviderType()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - UserApplicationProfileHandle::ProviderType "
                "cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_ExternalIdentityProviderType returnValue__;
    returnValue__ = Discord_UserApplicationProfileHandle_ProviderType(&instance);
    return static_cast<EDiscordExternalIdentityProviderType>(returnValue__);
#endif
}
FString UDiscordUserApplicationProfileHandle::Username()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - UserApplicationProfileHandle::Username "
                "cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String returnValueNative__;
    Discord_UserApplicationProfileHandle_Username(&instance, &returnValueNative__);
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;
#endif
}
UDiscordUserHandle::~UDiscordUserHandle()
{
    Drop();
}
void UDiscordUserHandle::Drop()
{
#if DISCORD_PARTNER_SDK_STUB
#else
    if (state != DiscordUObjectState::Owned) {
        return;
    }
    Discord_UserHandle_Drop(&instance);
    state = DiscordUObjectState::Invalid;
#endif
}
/* TODO: Clone */
FString UDiscordUserHandle::Avatar()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - UserHandle::Avatar cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool __returnIsNonNull;
    Discord_String returnValueNative__;
    __returnIsNonNull = Discord_UserHandle_Avatar(&instance, &returnValueNative__);
    if (!__returnIsNonNull) {
        return {};
    }
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;
#endif
}
/* static */ FString UDiscordUserHandle::AvatarTypeToString(EDiscordUserHandleAvatarType type)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - UserHandle::AvatarTypeToString cannot be called"));
    std::terminate();
#else
    Discord_String returnValueNative__;
    Discord_UserHandle_AvatarTypeToString(static_cast<Discord_UserHandle_AvatarType>(type),
                                          &returnValueNative__);
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;
#endif
}
FString UDiscordUserHandle::AvatarUrl(EDiscordUserHandleAvatarType animatedType,
                                      EDiscordUserHandleAvatarType staticType)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - UserHandle::AvatarUrl cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String returnValueNative__;
    Discord_UserHandle_AvatarUrl(&instance,
                                 static_cast<Discord_UserHandle_AvatarType>(animatedType),
                                 static_cast<Discord_UserHandle_AvatarType>(staticType),
                                 &returnValueNative__);
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;
#endif
}
FString UDiscordUserHandle::DisplayName()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - UserHandle::DisplayName cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String returnValueNative__;
    Discord_UserHandle_DisplayName(&instance, &returnValueNative__);
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;
#endif
}
UDiscordActivity* UDiscordUserHandle::GameActivity()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - UserHandle::GameActivity cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool __returnIsNonNull;
    Discord_Activity returnValueNative__;
    UDiscordActivity* returnValue__ = nullptr;
    __returnIsNonNull = Discord_UserHandle_GameActivity(&instance, &returnValueNative__);
    if (!__returnIsNonNull) {
        return {};
    }
    returnValue__ = NewObject<UDiscordActivity>();
    returnValue__->instance = returnValueNative__;
    returnValue__->state = DiscordUObjectState::Owned;
    return returnValue__;
#endif
}
FString UDiscordUserHandle::GlobalName()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - UserHandle::GlobalName cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool __returnIsNonNull;
    Discord_String returnValueNative__;
    __returnIsNonNull = Discord_UserHandle_GlobalName(&instance, &returnValueNative__);
    if (!__returnIsNonNull) {
        return {};
    }
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;
#endif
}
FDiscordUniqueID UDiscordUserHandle::Id()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - UserHandle::Id cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    uint64_t returnValue__;
    returnValue__ = Discord_UserHandle_Id(&instance);
    return returnValue__;
#endif
}
bool UDiscordUserHandle::IsProvisional()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - UserHandle::IsProvisional cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool returnValue__;
    returnValue__ = Discord_UserHandle_IsProvisional(&instance);
    return returnValue__;
#endif
}
UDiscordRelationshipHandle* UDiscordUserHandle::Relationship()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - UserHandle::Relationship cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_RelationshipHandle returnValueNative__;
    UDiscordRelationshipHandle* returnValue__ = nullptr;
    Discord_UserHandle_Relationship(&instance, &returnValueNative__);
    returnValue__ = NewObject<UDiscordRelationshipHandle>();
    returnValue__->instance = returnValueNative__;
    returnValue__->state = DiscordUObjectState::Owned;
    return returnValue__;
#endif
}
EDiscordStatusType UDiscordUserHandle::Status()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - UserHandle::Status cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_StatusType returnValue__;
    returnValue__ = Discord_UserHandle_Status(&instance);
    return static_cast<EDiscordStatusType>(returnValue__);
#endif
}
TArray<UDiscordUserApplicationProfileHandle*> UDiscordUserHandle::UserApplicationProfiles()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - UserHandle::UserApplicationProfiles cannot "
                "be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_UserApplicationProfileHandleSpan returnValueNative__;
    Discord_UserHandle_UserApplicationProfiles(&instance, &returnValueNative__);
    TArray<UDiscordUserApplicationProfileHandle*> returnValue__;
    returnValue__.Reserve(returnValueNative__.size);
    for (size_t i__ = 0; i__ < returnValueNative__.size; ++i__) {
        auto instance__ = NewObject<UDiscordUserApplicationProfileHandle>();
        instance__->instance = returnValueNative__.ptr[i__];
        instance__->state = DiscordUObjectState::Owned;
        returnValue__.Add(instance__);
    }
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;
#endif
}
FString UDiscordUserHandle::Username()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - UserHandle::Username cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String returnValueNative__;
    Discord_UserHandle_Username(&instance, &returnValueNative__);
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;
#endif
}
UDiscordLobbyMemberHandle::~UDiscordLobbyMemberHandle()
{
    Drop();
}
void UDiscordLobbyMemberHandle::Drop()
{
#if DISCORD_PARTNER_SDK_STUB
#else
    if (state != DiscordUObjectState::Owned) {
        return;
    }
    Discord_LobbyMemberHandle_Drop(&instance);
    state = DiscordUObjectState::Invalid;
#endif
}
/* TODO: Clone */
bool UDiscordLobbyMemberHandle::CanLinkLobby()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - LobbyMemberHandle::CanLinkLobby cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool returnValue__;
    returnValue__ = Discord_LobbyMemberHandle_CanLinkLobby(&instance);
    return returnValue__;
#endif
}
bool UDiscordLobbyMemberHandle::Connected()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - LobbyMemberHandle::Connected cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool returnValue__;
    returnValue__ = Discord_LobbyMemberHandle_Connected(&instance);
    return returnValue__;
#endif
}
FDiscordUniqueID UDiscordLobbyMemberHandle::Id()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - LobbyMemberHandle::Id cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    uint64_t returnValue__;
    returnValue__ = Discord_LobbyMemberHandle_Id(&instance);
    return returnValue__;
#endif
}
TMap<FString, FString> UDiscordLobbyMemberHandle::Metadata()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - LobbyMemberHandle::Metadata cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_Properties returnValueNative__;
    Discord_LobbyMemberHandle_Metadata(&instance, &returnValueNative__);
    TMap<FString, FString> returnValue__ = ConvertReturnedProperties(returnValueNative__);
    Discord_FreeProperties(returnValueNative__);
    return returnValue__;
#endif
}
UDiscordUserHandle* UDiscordLobbyMemberHandle::User()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - LobbyMemberHandle::User cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool __returnIsNonNull;
    Discord_UserHandle returnValueNative__;
    UDiscordUserHandle* returnValue__ = nullptr;
    __returnIsNonNull = Discord_LobbyMemberHandle_User(&instance, &returnValueNative__);
    if (!__returnIsNonNull) {
        return {};
    }
    returnValue__ = NewObject<UDiscordUserHandle>();
    returnValue__->instance = returnValueNative__;
    returnValue__->state = DiscordUObjectState::Owned;
    return returnValue__;
#endif
}
UDiscordLobbyHandle::~UDiscordLobbyHandle()
{
    Drop();
}
void UDiscordLobbyHandle::Drop()
{
#if DISCORD_PARTNER_SDK_STUB
#else
    if (state != DiscordUObjectState::Owned) {
        return;
    }
    Discord_LobbyHandle_Drop(&instance);
    state = DiscordUObjectState::Invalid;
#endif
}
/* TODO: Clone */
UDiscordCallInfoHandle* UDiscordLobbyHandle::GetCallInfoHandle()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - LobbyHandle::GetCallInfoHandle cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool __returnIsNonNull;
    Discord_CallInfoHandle returnValueNative__;
    UDiscordCallInfoHandle* returnValue__ = nullptr;
    __returnIsNonNull = Discord_LobbyHandle_GetCallInfoHandle(&instance, &returnValueNative__);
    if (!__returnIsNonNull) {
        return {};
    }
    returnValue__ = NewObject<UDiscordCallInfoHandle>();
    returnValue__->instance = returnValueNative__;
    returnValue__->state = DiscordUObjectState::Owned;
    return returnValue__;
#endif
}
UDiscordLobbyMemberHandle* UDiscordLobbyHandle::GetLobbyMemberHandle(FDiscordUniqueID memberId)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - LobbyHandle::GetLobbyMemberHandle cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool __returnIsNonNull;
    Discord_LobbyMemberHandle returnValueNative__;
    UDiscordLobbyMemberHandle* returnValue__ = nullptr;
    __returnIsNonNull =
      Discord_LobbyHandle_GetLobbyMemberHandle(&instance, memberId, &returnValueNative__);
    if (!__returnIsNonNull) {
        return {};
    }
    returnValue__ = NewObject<UDiscordLobbyMemberHandle>();
    returnValue__->instance = returnValueNative__;
    returnValue__->state = DiscordUObjectState::Owned;
    return returnValue__;
#endif
}
FDiscordUniqueID UDiscordLobbyHandle::Id()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - LobbyHandle::Id cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    uint64_t returnValue__;
    returnValue__ = Discord_LobbyHandle_Id(&instance);
    return returnValue__;
#endif
}
UDiscordLinkedChannel* UDiscordLobbyHandle::LinkedChannel()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - LobbyHandle::LinkedChannel cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool __returnIsNonNull;
    Discord_LinkedChannel returnValueNative__;
    UDiscordLinkedChannel* returnValue__ = nullptr;
    __returnIsNonNull = Discord_LobbyHandle_LinkedChannel(&instance, &returnValueNative__);
    if (!__returnIsNonNull) {
        return {};
    }
    returnValue__ = NewObject<UDiscordLinkedChannel>();
    returnValue__->instance = returnValueNative__;
    returnValue__->state = DiscordUObjectState::Owned;
    return returnValue__;
#endif
}
TArray<FDiscordUniqueID> UDiscordLobbyHandle::LobbyMemberIds()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - LobbyHandle::LobbyMemberIds cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_UInt64Span returnValueNative__;
    Discord_LobbyHandle_LobbyMemberIds(&instance, &returnValueNative__);
    TArray<FDiscordUniqueID> returnValue__;
    returnValue__.Reserve(returnValueNative__.size);
    for (size_t i__ = 0; i__ < returnValueNative__.size; ++i__) {
        returnValue__.Add(FDiscordUniqueID(returnValueNative__.ptr[i__]));
    }
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;
#endif
}
TArray<UDiscordLobbyMemberHandle*> UDiscordLobbyHandle::LobbyMembers()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - LobbyHandle::LobbyMembers cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_LobbyMemberHandleSpan returnValueNative__;
    Discord_LobbyHandle_LobbyMembers(&instance, &returnValueNative__);
    TArray<UDiscordLobbyMemberHandle*> returnValue__;
    returnValue__.Reserve(returnValueNative__.size);
    for (size_t i__ = 0; i__ < returnValueNative__.size; ++i__) {
        auto instance__ = NewObject<UDiscordLobbyMemberHandle>();
        instance__->instance = returnValueNative__.ptr[i__];
        instance__->state = DiscordUObjectState::Owned;
        returnValue__.Add(instance__);
    }
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;
#endif
}
TMap<FString, FString> UDiscordLobbyHandle::Metadata()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - LobbyHandle::Metadata cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_Properties returnValueNative__;
    Discord_LobbyHandle_Metadata(&instance, &returnValueNative__);
    TMap<FString, FString> returnValue__ = ConvertReturnedProperties(returnValueNative__);
    Discord_FreeProperties(returnValueNative__);
    return returnValue__;
#endif
}
UDiscordAdditionalContent::~UDiscordAdditionalContent()
{
    Drop();
}
void UDiscordAdditionalContent::Init()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - AdditionalContent::Init cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Invalid);
    Discord_AdditionalContent_Init(&instance);
    state = DiscordUObjectState::Owned;
#endif
}
void UDiscordAdditionalContent::Drop()
{
#if DISCORD_PARTNER_SDK_STUB
#else
    if (state != DiscordUObjectState::Owned) {
        return;
    }
    Discord_AdditionalContent_Drop(&instance);
    state = DiscordUObjectState::Invalid;
#endif
}
/* TODO: Clone */
bool UDiscordAdditionalContent::Equals(UDiscordAdditionalContent* rhs)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - AdditionalContent::Equals cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool returnValue__;
    Discord_AdditionalContent* rhs__instance = rhs ? &rhs->instance : nullptr;
    returnValue__ = Discord_AdditionalContent_Equals(&instance, rhs__instance);
    return returnValue__;
#endif
}
/* static */ FString UDiscordAdditionalContent::TypeToString(EDiscordAdditionalContentType type)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - AdditionalContent::TypeToString cannot be called"));
    std::terminate();
#else
    Discord_String returnValueNative__;
    Discord_AdditionalContent_TypeToString(static_cast<Discord_AdditionalContentType>(type),
                                           &returnValueNative__);
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;
#endif
}
EDiscordAdditionalContentType UDiscordAdditionalContent::Type()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - AdditionalContent::Type getter cannot be called"));
    std::terminate();
#else
    Discord_AdditionalContentType returnValue__;
    returnValue__ = Discord_AdditionalContent_Type(&instance);
    return static_cast<EDiscordAdditionalContentType>(returnValue__);

#endif
}
void UDiscordAdditionalContent::SetType(EDiscordAdditionalContentType Type)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - AdditionalContent::SetType cannot be called"));
    std::terminate();
#else
    Discord_AdditionalContent_SetType(&instance, static_cast<Discord_AdditionalContentType>(Type));

#endif
}
FString UDiscordAdditionalContent::Title()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - AdditionalContent::Title getter cannot be called"));
    std::terminate();
#else
    bool __returnIsNonNull;
    Discord_String returnValueNative__;
    __returnIsNonNull = Discord_AdditionalContent_Title(&instance, &returnValueNative__);
    if (!__returnIsNonNull) {
        return {};
    }
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;

#endif
}
void UDiscordAdditionalContent::SetTitle(FString Title)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - AdditionalContent::SetTitle cannot be called"));
    std::terminate();
#else
    Discord_String Title__span;
    FTCHARToUTF8 Title__convert(*Title);
    Title__span.ptr = (uint8*)Title__convert.Get();
    Title__span.size = Title__convert.Length();
    Discord_AdditionalContent_SetTitle(&instance, &Title__span);

#endif
}
uint8 UDiscordAdditionalContent::Count()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - AdditionalContent::Count getter cannot be called"));
    std::terminate();
#else
    uint8_t returnValue__;
    returnValue__ = Discord_AdditionalContent_Count(&instance);
    return returnValue__;

#endif
}
void UDiscordAdditionalContent::SetCount(uint8 Count)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - AdditionalContent::SetCount cannot be called"));
    std::terminate();
#else
    Discord_AdditionalContent_SetCount(&instance, Count);

#endif
}
UDiscordMessageHandle::~UDiscordMessageHandle()
{
    Drop();
}
void UDiscordMessageHandle::Drop()
{
#if DISCORD_PARTNER_SDK_STUB
#else
    if (state != DiscordUObjectState::Owned) {
        return;
    }
    Discord_MessageHandle_Drop(&instance);
    state = DiscordUObjectState::Invalid;
#endif
}
/* TODO: Clone */
UDiscordAdditionalContent* UDiscordMessageHandle::AdditionalContent()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - MessageHandle::AdditionalContent cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool __returnIsNonNull;
    Discord_AdditionalContent returnValueNative__;
    UDiscordAdditionalContent* returnValue__ = nullptr;
    __returnIsNonNull = Discord_MessageHandle_AdditionalContent(&instance, &returnValueNative__);
    if (!__returnIsNonNull) {
        return {};
    }
    returnValue__ = NewObject<UDiscordAdditionalContent>();
    returnValue__->instance = returnValueNative__;
    returnValue__->state = DiscordUObjectState::Owned;
    return returnValue__;
#endif
}
FDiscordUniqueID UDiscordMessageHandle::ApplicationId()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - MessageHandle::ApplicationId cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool __returnIsNonNull;
    uint64_t __returnValue{};
    __returnIsNonNull = Discord_MessageHandle_ApplicationId(&instance, &__returnValue);
    if (!__returnIsNonNull) {
        return {};
    }
    return __returnValue;
#endif
}
UDiscordUserHandle* UDiscordMessageHandle::Author()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - MessageHandle::Author cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool __returnIsNonNull;
    Discord_UserHandle returnValueNative__;
    UDiscordUserHandle* returnValue__ = nullptr;
    __returnIsNonNull = Discord_MessageHandle_Author(&instance, &returnValueNative__);
    if (!__returnIsNonNull) {
        return {};
    }
    returnValue__ = NewObject<UDiscordUserHandle>();
    returnValue__->instance = returnValueNative__;
    returnValue__->state = DiscordUObjectState::Owned;
    return returnValue__;
#endif
}
FDiscordUniqueID UDiscordMessageHandle::AuthorId()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - MessageHandle::AuthorId cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    uint64_t returnValue__;
    returnValue__ = Discord_MessageHandle_AuthorId(&instance);
    return returnValue__;
#endif
}
UDiscordChannelHandle* UDiscordMessageHandle::Channel()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - MessageHandle::Channel cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool __returnIsNonNull;
    Discord_ChannelHandle returnValueNative__;
    UDiscordChannelHandle* returnValue__ = nullptr;
    __returnIsNonNull = Discord_MessageHandle_Channel(&instance, &returnValueNative__);
    if (!__returnIsNonNull) {
        return {};
    }
    returnValue__ = NewObject<UDiscordChannelHandle>();
    returnValue__->instance = returnValueNative__;
    returnValue__->state = DiscordUObjectState::Owned;
    return returnValue__;
#endif
}
FDiscordUniqueID UDiscordMessageHandle::ChannelId()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - MessageHandle::ChannelId cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    uint64_t returnValue__;
    returnValue__ = Discord_MessageHandle_ChannelId(&instance);
    return returnValue__;
#endif
}
FString UDiscordMessageHandle::Content()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - MessageHandle::Content cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String returnValueNative__;
    Discord_MessageHandle_Content(&instance, &returnValueNative__);
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;
#endif
}
EDiscordDisclosureTypes UDiscordMessageHandle::DisclosureType()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - MessageHandle::DisclosureType cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool __returnIsNonNull;
    Discord_DisclosureTypes __returnValue{};
    __returnIsNonNull = Discord_MessageHandle_DisclosureType(&instance, &__returnValue);
    if (!__returnIsNonNull) {
        return {};
    }
    return static_cast<EDiscordDisclosureTypes>(__returnValue);
#endif
}
FDiscordUniqueID UDiscordMessageHandle::EditedTimestamp()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - MessageHandle::EditedTimestamp cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    uint64_t returnValue__;
    returnValue__ = Discord_MessageHandle_EditedTimestamp(&instance);
    return returnValue__;
#endif
}
FDiscordUniqueID UDiscordMessageHandle::Id()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - MessageHandle::Id cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    uint64_t returnValue__;
    returnValue__ = Discord_MessageHandle_Id(&instance);
    return returnValue__;
#endif
}
UDiscordLobbyHandle* UDiscordMessageHandle::Lobby()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - MessageHandle::Lobby cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool __returnIsNonNull;
    Discord_LobbyHandle returnValueNative__;
    UDiscordLobbyHandle* returnValue__ = nullptr;
    __returnIsNonNull = Discord_MessageHandle_Lobby(&instance, &returnValueNative__);
    if (!__returnIsNonNull) {
        return {};
    }
    returnValue__ = NewObject<UDiscordLobbyHandle>();
    returnValue__->instance = returnValueNative__;
    returnValue__->state = DiscordUObjectState::Owned;
    return returnValue__;
#endif
}
TMap<FString, FString> UDiscordMessageHandle::Metadata()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - MessageHandle::Metadata cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_Properties returnValueNative__;
    Discord_MessageHandle_Metadata(&instance, &returnValueNative__);
    TMap<FString, FString> returnValue__ = ConvertReturnedProperties(returnValueNative__);
    Discord_FreeProperties(returnValueNative__);
    return returnValue__;
#endif
}
TMap<FString, FString> UDiscordMessageHandle::ModerationMetadata()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - MessageHandle::ModerationMetadata cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_Properties returnValueNative__;
    Discord_MessageHandle_ModerationMetadata(&instance, &returnValueNative__);
    TMap<FString, FString> returnValue__ = ConvertReturnedProperties(returnValueNative__);
    Discord_FreeProperties(returnValueNative__);
    return returnValue__;
#endif
}
FString UDiscordMessageHandle::RawContent()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - MessageHandle::RawContent cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String returnValueNative__;
    Discord_MessageHandle_RawContent(&instance, &returnValueNative__);
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;
#endif
}
UDiscordUserHandle* UDiscordMessageHandle::Recipient()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - MessageHandle::Recipient cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool __returnIsNonNull;
    Discord_UserHandle returnValueNative__;
    UDiscordUserHandle* returnValue__ = nullptr;
    __returnIsNonNull = Discord_MessageHandle_Recipient(&instance, &returnValueNative__);
    if (!__returnIsNonNull) {
        return {};
    }
    returnValue__ = NewObject<UDiscordUserHandle>();
    returnValue__->instance = returnValueNative__;
    returnValue__->state = DiscordUObjectState::Owned;
    return returnValue__;
#endif
}
FDiscordUniqueID UDiscordMessageHandle::RecipientId()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - MessageHandle::RecipientId cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    uint64_t returnValue__;
    returnValue__ = Discord_MessageHandle_RecipientId(&instance);
    return returnValue__;
#endif
}
bool UDiscordMessageHandle::SentFromGame()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - MessageHandle::SentFromGame cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool returnValue__;
    returnValue__ = Discord_MessageHandle_SentFromGame(&instance);
    return returnValue__;
#endif
}
FDiscordUniqueID UDiscordMessageHandle::SentTimestamp()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - MessageHandle::SentTimestamp cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    uint64_t returnValue__;
    returnValue__ = Discord_MessageHandle_SentTimestamp(&instance);
    return returnValue__;
#endif
}
UDiscordAudioDevice::~UDiscordAudioDevice()
{
    Drop();
}
void UDiscordAudioDevice::Drop()
{
#if DISCORD_PARTNER_SDK_STUB
#else
    if (state != DiscordUObjectState::Owned) {
        return;
    }
    Discord_AudioDevice_Drop(&instance);
    state = DiscordUObjectState::Invalid;
#endif
}
/* TODO: Clone */
bool UDiscordAudioDevice::Equals(UDiscordAudioDevice* rhs)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - AudioDevice::Equals cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool returnValue__;
    Discord_AudioDevice* rhs__instance = rhs ? &rhs->instance : nullptr;
    returnValue__ = Discord_AudioDevice_Equals(&instance, rhs__instance);
    return returnValue__;
#endif
}
FString UDiscordAudioDevice::Id()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - AudioDevice::Id getter cannot be called"));
    std::terminate();
#else
    Discord_String returnValueNative__;
    Discord_AudioDevice_Id(&instance, &returnValueNative__);
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;

#endif
}
void UDiscordAudioDevice::SetId(FString Id)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - AudioDevice::SetId cannot be called"));
    std::terminate();
#else
    Discord_String Id__span;
    FTCHARToUTF8 Id__convert(*Id);
    Id__span.ptr = (uint8*)Id__convert.Get();
    Id__span.size = Id__convert.Length();
    Discord_AudioDevice_SetId(&instance, Id__span);

#endif
}
FString UDiscordAudioDevice::Name()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - AudioDevice::Name getter cannot be called"));
    std::terminate();
#else
    Discord_String returnValueNative__;
    Discord_AudioDevice_Name(&instance, &returnValueNative__);
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;

#endif
}
void UDiscordAudioDevice::SetName(FString Name)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - AudioDevice::SetName cannot be called"));
    std::terminate();
#else
    Discord_String Name__span;
    FTCHARToUTF8 Name__convert(*Name);
    Name__span.ptr = (uint8*)Name__convert.Get();
    Name__span.size = Name__convert.Length();
    Discord_AudioDevice_SetName(&instance, Name__span);

#endif
}
bool UDiscordAudioDevice::IsDefault()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - AudioDevice::IsDefault getter cannot be called"));
    std::terminate();
#else
    bool returnValue__;
    returnValue__ = Discord_AudioDevice_IsDefault(&instance);
    return returnValue__;

#endif
}
void UDiscordAudioDevice::SetIsDefault(bool IsDefault)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - AudioDevice::SetIsDefault cannot be called"));
    std::terminate();
#else
    Discord_AudioDevice_SetIsDefault(&instance, IsDefault);

#endif
}
UDiscordUserMessageSummary::~UDiscordUserMessageSummary()
{
    Drop();
}
void UDiscordUserMessageSummary::Drop()
{
#if DISCORD_PARTNER_SDK_STUB
#else
    if (state != DiscordUObjectState::Owned) {
        return;
    }
    Discord_UserMessageSummary_Drop(&instance);
    state = DiscordUObjectState::Invalid;
#endif
}
/* TODO: Clone */
FDiscordUniqueID UDiscordUserMessageSummary::LastMessageId()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - UserMessageSummary::LastMessageId cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    uint64_t returnValue__;
    returnValue__ = Discord_UserMessageSummary_LastMessageId(&instance);
    return returnValue__;
#endif
}
FDiscordUniqueID UDiscordUserMessageSummary::UserId()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - UserMessageSummary::UserId cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    uint64_t returnValue__;
    returnValue__ = Discord_UserMessageSummary_UserId(&instance);
    return returnValue__;
#endif
}
UDiscordClientCreateOptions::~UDiscordClientCreateOptions()
{
    Drop();
}
void UDiscordClientCreateOptions::Init()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - ClientCreateOptions::Init cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Invalid);
    Discord_ClientCreateOptions_Init(&instance);
    state = DiscordUObjectState::Owned;
#endif
}
void UDiscordClientCreateOptions::Drop()
{
#if DISCORD_PARTNER_SDK_STUB
#else
    if (state != DiscordUObjectState::Owned) {
        return;
    }
    Discord_ClientCreateOptions_Drop(&instance);
    state = DiscordUObjectState::Invalid;
#endif
}
/* TODO: Clone */
FString UDiscordClientCreateOptions::WebBase()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - ClientCreateOptions::WebBase getter cannot "
                "be called"));
    std::terminate();
#else
    Discord_String returnValueNative__;
    Discord_ClientCreateOptions_WebBase(&instance, &returnValueNative__);
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;

#endif
}
void UDiscordClientCreateOptions::SetWebBase(FString WebBase)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - ClientCreateOptions::SetWebBase cannot be called"));
    std::terminate();
#else
    Discord_String WebBase__span;
    FTCHARToUTF8 WebBase__convert(*WebBase);
    WebBase__span.ptr = (uint8*)WebBase__convert.Get();
    WebBase__span.size = WebBase__convert.Length();
    Discord_ClientCreateOptions_SetWebBase(&instance, WebBase__span);

#endif
}
FString UDiscordClientCreateOptions::ApiBase()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - ClientCreateOptions::ApiBase getter cannot "
                "be called"));
    std::terminate();
#else
    Discord_String returnValueNative__;
    Discord_ClientCreateOptions_ApiBase(&instance, &returnValueNative__);
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;

#endif
}
void UDiscordClientCreateOptions::SetApiBase(FString ApiBase)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - ClientCreateOptions::SetApiBase cannot be called"));
    std::terminate();
#else
    Discord_String ApiBase__span;
    FTCHARToUTF8 ApiBase__convert(*ApiBase);
    ApiBase__span.ptr = (uint8*)ApiBase__convert.Get();
    ApiBase__span.size = ApiBase__convert.Length();
    Discord_ClientCreateOptions_SetApiBase(&instance, ApiBase__span);

#endif
}
EDiscordAudioSystem UDiscordClientCreateOptions::ExperimentalAudioSystem()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - ClientCreateOptions::ExperimentalAudioSystem "
                "getter cannot be called"));
    std::terminate();
#else
    Discord_AudioSystem returnValue__;
    returnValue__ = Discord_ClientCreateOptions_ExperimentalAudioSystem(&instance);
    return static_cast<EDiscordAudioSystem>(returnValue__);

#endif
}
void UDiscordClientCreateOptions::SetExperimentalAudioSystem(
  EDiscordAudioSystem ExperimentalAudioSystem)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - "
                "ClientCreateOptions::SetExperimentalAudioSystem cannot be called"));
    std::terminate();
#else
    Discord_ClientCreateOptions_SetExperimentalAudioSystem(
      &instance, static_cast<Discord_AudioSystem>(ExperimentalAudioSystem));

#endif
}
bool UDiscordClientCreateOptions::ExperimentalAndroidPreventCommsForBluetooth()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - "
                "ClientCreateOptions::ExperimentalAndroidPreventCommsForBluetooth getter cannot be "
                "called"));
    std::terminate();
#else
    bool returnValue__;
    returnValue__ =
      Discord_ClientCreateOptions_ExperimentalAndroidPreventCommsForBluetooth(&instance);
    return returnValue__;

#endif
}
void UDiscordClientCreateOptions::SetExperimentalAndroidPreventCommsForBluetooth(
  bool ExperimentalAndroidPreventCommsForBluetooth)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - "
           "ClientCreateOptions::SetExperimentalAndroidPreventCommsForBluetooth cannot be called"));
    std::terminate();
#else
    Discord_ClientCreateOptions_SetExperimentalAndroidPreventCommsForBluetooth(
      &instance, ExperimentalAndroidPreventCommsForBluetooth);

#endif
}
FDiscordUniqueID UDiscordClientCreateOptions::CpuAffinityMask()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - ClientCreateOptions::CpuAffinityMask getter "
                "cannot be called"));
    std::terminate();
#else
    bool __returnIsNonNull;
    uint64_t __returnValue{};
    __returnIsNonNull = Discord_ClientCreateOptions_CpuAffinityMask(&instance, &__returnValue);
    if (!__returnIsNonNull) {
        return {};
    }
    return __returnValue;

#endif
}
void UDiscordClientCreateOptions::SetCpuAffinityMask(FDiscordUniqueID CpuAffinityMask)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - ClientCreateOptions::SetCpuAffinityMask "
                "cannot be called"));
    std::terminate();
#else
    uint64_t CpuAffinityMask__optional = CpuAffinityMask;
    Discord_ClientCreateOptions_SetCpuAffinityMask(&instance, &CpuAffinityMask__optional);

#endif
}
UDiscordClient::~UDiscordClient()
{
    Drop();
}
void UDiscordClient::Init()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - Client::Init cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Invalid);
    Discord_Client_Init(&instance);
    state = DiscordUObjectState::Owned;
#endif
}
void UDiscordClient::InitWithBases(FString const& apiBase, FString const& webBase)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::InitWithBases cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Invalid);
    Discord_String apiBase__span;
    FTCHARToUTF8 apiBase__convert(*apiBase);
    apiBase__span.ptr = (uint8*)apiBase__convert.Get();
    apiBase__span.size = apiBase__convert.Length();
    Discord_String webBase__span;
    FTCHARToUTF8 webBase__convert(*webBase);
    webBase__span.ptr = (uint8*)webBase__convert.Get();
    webBase__span.size = webBase__convert.Length();
    Discord_Client_InitWithBases(&instance, apiBase__span, webBase__span);
    state = DiscordUObjectState::Owned;
#endif
}
void UDiscordClient::InitWithOptions(UDiscordClientCreateOptions* options)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::InitWithOptions cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Invalid);
    Discord_ClientCreateOptions* options__instance = options ? &options->instance : nullptr;
    Discord_Client_InitWithOptions(&instance, options__instance);
    state = DiscordUObjectState::Owned;
#endif
}
void UDiscordClient::Drop()
{
#if DISCORD_PARTNER_SDK_STUB
#else
    if (state != DiscordUObjectState::Owned) {
        return;
    }
    Discord_Client_Drop(&instance);
    state = DiscordUObjectState::Invalid;
#endif
}
#if DISCORD_DEBUG_API_ENABLED
void UDiscordClient::AddOrUpdateLobbyMember(FString const& token,
                                            FDiscordUniqueID userId,
                                            FDiscordUniqueID lobbyId,
                                            TMap<FString, FString> const& metadata,
                                            EDiscordLobbyMemberFlags flags,
                                            FDiscordClientUpdateLobbyMemberCallback const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Client::AddOrUpdateLobbyMember cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String token__span;
    FTCHARToUTF8 token__convert(*token);
    token__span.ptr = (uint8*)token__convert.Get();
    token__span.size = token__convert.Length();
    ConvertedProperties metadata__convert(metadata);
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_UpdateLobbyMemberCallback callback__native =
      [](auto result, auto userId, auto lobbyId, void* userData__) {
          auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
          UDiscordClientResult* result__instance = nullptr;
          result__instance = NewObject<UDiscordClientResult>();
          result__instance->instance = *result;
          result__instance->state = DiscordUObjectState::Owned;
          userData__typed->delegate.ExecuteIfBound(result__instance, userId, lobbyId);
      };
    Discord_Client_AddOrUpdateLobbyMember(&instance,
                                          token__span,
                                          userId,
                                          lobbyId,
                                          metadata__convert.Properties,
                                          static_cast<Discord_LobbyMemberFlags>(flags),
                                          callback__native,
                                          &Tcallback__UserData::Free,
                                          callback__userData);
#endif
}
void UDiscordClient::AddOrUpdateLobbyMember(
  FString const& token,
  FDiscordUniqueID userId,
  FDiscordUniqueID lobbyId,
  TMap<FString, FString> const& metadata,
  EDiscordLobbyMemberFlags flags,
  FDiscordClientUpdateLobbyMemberCallbackDynamic const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Client::AddOrUpdateLobbyMember cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String token__span;
    FTCHARToUTF8 token__convert(*token);
    token__span.ptr = (uint8*)token__convert.Get();
    token__span.size = token__convert.Length();
    ConvertedProperties metadata__convert(metadata);
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_UpdateLobbyMemberCallback callback__native =
      [](auto result, auto userId, auto lobbyId, void* userData__) {
          auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
          UDiscordClientResult* result__instance = nullptr;
          result__instance = NewObject<UDiscordClientResult>();
          result__instance->instance = *result;
          result__instance->state = DiscordUObjectState::Owned;
          userData__typed->delegate.ExecuteIfBound(result__instance, userId, lobbyId);
      };
    Discord_Client_AddOrUpdateLobbyMember(&instance,
                                          token__span,
                                          userId,
                                          lobbyId,
                                          metadata__convert.Properties,
                                          static_cast<Discord_LobbyMemberFlags>(flags),
                                          callback__native,
                                          &Tcallback__UserData::Free,
                                          callback__userData);
#endif
}
#endif
#if DISCORD_DEBUG_API_ENABLED
void UDiscordClient::CreateNewLobby(FString const& token,
                                    FDiscordClientLobbyActionCallback const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::CreateNewLobby cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String token__span;
    FTCHARToUTF8 token__convert(*token);
    token__span.ptr = (uint8*)token__convert.Get();
    token__span.size = token__convert.Length();
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_LobbyActionCallback callback__native =
      [](auto result, auto lobbyId, void* userData__) {
          auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
          UDiscordClientResult* result__instance = nullptr;
          result__instance = NewObject<UDiscordClientResult>();
          result__instance->instance = *result;
          result__instance->state = DiscordUObjectState::Owned;
          userData__typed->delegate.ExecuteIfBound(result__instance, lobbyId);
      };
    Discord_Client_CreateNewLobby(
      &instance, token__span, callback__native, &Tcallback__UserData::Free, callback__userData);
#endif
}
void UDiscordClient::CreateNewLobby(FString const& token,
                                    FDiscordClientLobbyActionCallbackDynamic const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::CreateNewLobby cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String token__span;
    FTCHARToUTF8 token__convert(*token);
    token__span.ptr = (uint8*)token__convert.Get();
    token__span.size = token__convert.Length();
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_LobbyActionCallback callback__native =
      [](auto result, auto lobbyId, void* userData__) {
          auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
          UDiscordClientResult* result__instance = nullptr;
          result__instance = NewObject<UDiscordClientResult>();
          result__instance->instance = *result;
          result__instance->state = DiscordUObjectState::Owned;
          userData__typed->delegate.ExecuteIfBound(result__instance, lobbyId);
      };
    Discord_Client_CreateNewLobby(
      &instance, token__span, callback__native, &Tcallback__UserData::Free, callback__userData);
#endif
}
#endif
#if DISCORD_DEBUG_API_ENABLED
void UDiscordClient::DeleteLobby(FString const& token,
                                 FDiscordUniqueID lobbyId,
                                 FDiscordClientLobbyActionCallback const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::DeleteLobby cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String token__span;
    FTCHARToUTF8 token__convert(*token);
    token__span.ptr = (uint8*)token__convert.Get();
    token__span.size = token__convert.Length();
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_LobbyActionCallback callback__native =
      [](auto result, auto lobbyId, void* userData__) {
          auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
          UDiscordClientResult* result__instance = nullptr;
          result__instance = NewObject<UDiscordClientResult>();
          result__instance->instance = *result;
          result__instance->state = DiscordUObjectState::Owned;
          userData__typed->delegate.ExecuteIfBound(result__instance, lobbyId);
      };
    Discord_Client_DeleteLobby(&instance,
                               token__span,
                               lobbyId,
                               callback__native,
                               &Tcallback__UserData::Free,
                               callback__userData);
#endif
}
void UDiscordClient::DeleteLobby(FString const& token,
                                 FDiscordUniqueID lobbyId,
                                 FDiscordClientLobbyActionCallbackDynamic const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::DeleteLobby cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String token__span;
    FTCHARToUTF8 token__convert(*token);
    token__span.ptr = (uint8*)token__convert.Get();
    token__span.size = token__convert.Length();
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_LobbyActionCallback callback__native =
      [](auto result, auto lobbyId, void* userData__) {
          auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
          UDiscordClientResult* result__instance = nullptr;
          result__instance = NewObject<UDiscordClientResult>();
          result__instance->instance = *result;
          result__instance->state = DiscordUObjectState::Owned;
          userData__typed->delegate.ExecuteIfBound(result__instance, lobbyId);
      };
    Discord_Client_DeleteLobby(&instance,
                               token__span,
                               lobbyId,
                               callback__native,
                               &Tcallback__UserData::Free,
                               callback__userData);
#endif
}
#endif
#if DISCORD_DEBUG_API_ENABLED
void UDiscordClient::EditLobby(FString const& token,
                               FDiscordUniqueID lobbyId,
                               TMap<FString, FString> const& lobbyMetadata,
                               FDiscordClientLobbyActionCallback const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - Client::EditLobby cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String token__span;
    FTCHARToUTF8 token__convert(*token);
    token__span.ptr = (uint8*)token__convert.Get();
    token__span.size = token__convert.Length();
    ConvertedProperties lobbyMetadata__convert(lobbyMetadata);
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_LobbyActionCallback callback__native =
      [](auto result, auto lobbyId, void* userData__) {
          auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
          UDiscordClientResult* result__instance = nullptr;
          result__instance = NewObject<UDiscordClientResult>();
          result__instance->instance = *result;
          result__instance->state = DiscordUObjectState::Owned;
          userData__typed->delegate.ExecuteIfBound(result__instance, lobbyId);
      };
    Discord_Client_EditLobby(&instance,
                             token__span,
                             lobbyId,
                             lobbyMetadata__convert.Properties,
                             callback__native,
                             &Tcallback__UserData::Free,
                             callback__userData);
#endif
}
void UDiscordClient::EditLobby(FString const& token,
                               FDiscordUniqueID lobbyId,
                               TMap<FString, FString> const& lobbyMetadata,
                               FDiscordClientLobbyActionCallbackDynamic const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - Client::EditLobby cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String token__span;
    FTCHARToUTF8 token__convert(*token);
    token__span.ptr = (uint8*)token__convert.Get();
    token__span.size = token__convert.Length();
    ConvertedProperties lobbyMetadata__convert(lobbyMetadata);
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_LobbyActionCallback callback__native =
      [](auto result, auto lobbyId, void* userData__) {
          auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
          UDiscordClientResult* result__instance = nullptr;
          result__instance = NewObject<UDiscordClientResult>();
          result__instance->instance = *result;
          result__instance->state = DiscordUObjectState::Owned;
          userData__typed->delegate.ExecuteIfBound(result__instance, lobbyId);
      };
    Discord_Client_EditLobby(&instance,
                             token__span,
                             lobbyId,
                             lobbyMetadata__convert.Properties,
                             callback__native,
                             &Tcallback__UserData::Free,
                             callback__userData);
#endif
}
#endif
/* static */ FString UDiscordClient::ErrorToString(EDiscordClientError type)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::ErrorToString cannot be called"));
    std::terminate();
#else
    Discord_String returnValueNative__;
    Discord_Client_ErrorToString(static_cast<Discord_Client_Error>(type), &returnValueNative__);
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;
#endif
}
#if DISCORD_DEBUG_API_ENABLED
void UDiscordClient::ForceCrash_ForTest()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Client::ForceCrash_ForTest cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_Client_ForceCrash_ForTest(&instance);
#endif
}
#endif
FDiscordUniqueID UDiscordClient::GetApplicationId()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::GetApplicationId cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    uint64_t returnValue__;
    returnValue__ = Discord_Client_GetApplicationId(&instance);
    return returnValue__;
#endif
}
UDiscordUserHandle* UDiscordClient::GetCurrentUser()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::GetCurrentUser cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_UserHandle returnValueNative__;
    UDiscordUserHandle* returnValue__ = nullptr;
    Discord_Client_GetCurrentUser(&instance, &returnValueNative__);
    returnValue__ = NewObject<UDiscordUserHandle>();
    returnValue__->instance = returnValueNative__;
    returnValue__->state = DiscordUObjectState::Owned;
    return returnValue__;
#endif
}
/* static */ FString UDiscordClient::GetDefaultAudioDeviceId()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Client::GetDefaultAudioDeviceId cannot be called"));
    std::terminate();
#else
    Discord_String returnValueNative__;
    Discord_Client_GetDefaultAudioDeviceId(&returnValueNative__);
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;
#endif
}
/* static */ FString UDiscordClient::GetDefaultCommunicationScopes()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::GetDefaultCommunicationScopes cannot "
                "be called"));
    std::terminate();
#else
    Discord_String returnValueNative__;
    Discord_Client_GetDefaultCommunicationScopes(&returnValueNative__);
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;
#endif
}
/* static */ FString UDiscordClient::GetDefaultPresenceScopes()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Client::GetDefaultPresenceScopes cannot be called"));
    std::terminate();
#else
    Discord_String returnValueNative__;
    Discord_Client_GetDefaultPresenceScopes(&returnValueNative__);
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;
#endif
}
/* static */ FString UDiscordClient::GetVersionHash()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::GetVersionHash cannot be called"));
    std::terminate();
#else
    Discord_String returnValueNative__;
    Discord_Client_GetVersionHash(&returnValueNative__);
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;
#endif
}
/* static */ int32 UDiscordClient::GetVersionMajor()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::GetVersionMajor cannot be called"));
    std::terminate();
#else
    int32_t returnValue__;
    returnValue__ = Discord_Client_GetVersionMajor();
    return returnValue__;
#endif
}
/* static */ int32 UDiscordClient::GetVersionMinor()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::GetVersionMinor cannot be called"));
    std::terminate();
#else
    int32_t returnValue__;
    returnValue__ = Discord_Client_GetVersionMinor();
    return returnValue__;
#endif
}
/* static */ int32 UDiscordClient::GetVersionPatch()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::GetVersionPatch cannot be called"));
    std::terminate();
#else
    int32_t returnValue__;
    returnValue__ = Discord_Client_GetVersionPatch();
    return returnValue__;
#endif
}
#if DISCORD_DEBUG_API_ENABLED
void UDiscordClient::PerformOnThreadWithString_ForTest(
  FString const& text,
  FDiscordClientPerformOnThreadWithStringCallback const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::PerformOnThreadWithString_ForTest "
                "cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String text__span;
    FTCHARToUTF8 text__convert(*text);
    text__span.ptr = (uint8*)text__convert.Get();
    text__span.size = text__convert.Length();
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_PerformOnThreadWithStringCallback callback__native = [](auto text,
                                                                           void* userData__) {
        auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
        FString text__string;
        text__string.AppendChars(DISCORD_CHAR_CAST(text.ptr), text.size);
        userData__typed->delegate.ExecuteIfBound(std::move(text__string));
        Discord_Free(text.ptr);
    };
    Discord_Client_PerformOnThreadWithString_ForTest(
      &instance, text__span, callback__native, &Tcallback__UserData::Free, callback__userData);
#endif
}
void UDiscordClient::PerformOnThreadWithString_ForTest(
  FString const& text,
  FDiscordClientPerformOnThreadWithStringCallbackDynamic const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::PerformOnThreadWithString_ForTest "
                "cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String text__span;
    FTCHARToUTF8 text__convert(*text);
    text__span.ptr = (uint8*)text__convert.Get();
    text__span.size = text__convert.Length();
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_PerformOnThreadWithStringCallback callback__native = [](auto text,
                                                                           void* userData__) {
        auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
        FString text__string;
        text__string.AppendChars(DISCORD_CHAR_CAST(text.ptr), text.size);
        userData__typed->delegate.ExecuteIfBound(std::move(text__string));
        Discord_Free(text.ptr);
    };
    Discord_Client_PerformOnThreadWithString_ForTest(
      &instance, text__span, callback__native, &Tcallback__UserData::Free, callback__userData);
#endif
}
#endif
#if DISCORD_DEBUG_API_ENABLED
void UDiscordClient::RemoveLobbyMember(FString const& token,
                                       FDiscordUniqueID userId,
                                       FDiscordUniqueID lobbyId,
                                       FDiscordClientUpdateLobbyMemberCallback const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::RemoveLobbyMember cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String token__span;
    FTCHARToUTF8 token__convert(*token);
    token__span.ptr = (uint8*)token__convert.Get();
    token__span.size = token__convert.Length();
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_UpdateLobbyMemberCallback callback__native =
      [](auto result, auto userId, auto lobbyId, void* userData__) {
          auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
          UDiscordClientResult* result__instance = nullptr;
          result__instance = NewObject<UDiscordClientResult>();
          result__instance->instance = *result;
          result__instance->state = DiscordUObjectState::Owned;
          userData__typed->delegate.ExecuteIfBound(result__instance, userId, lobbyId);
      };
    Discord_Client_RemoveLobbyMember(&instance,
                                     token__span,
                                     userId,
                                     lobbyId,
                                     callback__native,
                                     &Tcallback__UserData::Free,
                                     callback__userData);
#endif
}
void UDiscordClient::RemoveLobbyMember(
  FString const& token,
  FDiscordUniqueID userId,
  FDiscordUniqueID lobbyId,
  FDiscordClientUpdateLobbyMemberCallbackDynamic const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::RemoveLobbyMember cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String token__span;
    FTCHARToUTF8 token__convert(*token);
    token__span.ptr = (uint8*)token__convert.Get();
    token__span.size = token__convert.Length();
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_UpdateLobbyMemberCallback callback__native =
      [](auto result, auto userId, auto lobbyId, void* userData__) {
          auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
          UDiscordClientResult* result__instance = nullptr;
          result__instance = NewObject<UDiscordClientResult>();
          result__instance->instance = *result;
          result__instance->state = DiscordUObjectState::Owned;
          userData__typed->delegate.ExecuteIfBound(result__instance, userId, lobbyId);
      };
    Discord_Client_RemoveLobbyMember(&instance,
                                     token__span,
                                     userId,
                                     lobbyId,
                                     callback__native,
                                     &Tcallback__UserData::Free,
                                     callback__userData);
#endif
}
#endif
void UDiscordClient::SetHttpRequestTimeout(int32 httpTimeoutInMilliseconds)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Client::SetHttpRequestTimeout cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_Client_SetHttpRequestTimeout(&instance, httpTimeoutInMilliseconds);
#endif
}
/* static */ FString UDiscordClient::StatusToString(EDiscordClientStatus type)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::StatusToString cannot be called"));
    std::terminate();
#else
    Discord_String returnValueNative__;
    Discord_Client_StatusToString(static_cast<Discord_Client_Status>(type), &returnValueNative__);
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;
#endif
}
/* static */ FString UDiscordClient::ThreadToString(EDiscordClientThread type)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::ThreadToString cannot be called"));
    std::terminate();
#else
    Discord_String returnValueNative__;
    Discord_Client_ThreadToString(static_cast<Discord_Client_Thread>(type), &returnValueNative__);
    FString returnValue__;
    returnValue__.AppendChars(DISCORD_CHAR_CAST(returnValueNative__.ptr), returnValueNative__.size);
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;
#endif
}
#if DISCORD_DEBUG_API_ENABLED
void UDiscordClient::UpdateUserApplicationProfile(
  FString const& token,
  FDiscordUniqueID applicationId,
  FDiscordUniqueID userId,
  FString const& providerIssuedUserId,
  FString const& username,
  TMap<FString, FString> const& metadata,
  FDiscordClientUpdateUserApplicationProfileCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::UpdateUserApplicationProfile cannot "
                "be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String token__span;
    FTCHARToUTF8 token__convert(*token);
    token__span.ptr = (uint8*)token__convert.Get();
    token__span.size = token__convert.Length();
    Discord_String providerIssuedUserId__span;
    FTCHARToUTF8 providerIssuedUserId__convert(*providerIssuedUserId);
    providerIssuedUserId__span.ptr = (uint8*)providerIssuedUserId__convert.Get();
    providerIssuedUserId__span.size = providerIssuedUserId__convert.Length();
    Discord_String username__span;
    FTCHARToUTF8 username__convert(*username);
    username__span.ptr = (uint8*)username__convert.Get();
    username__span.size = username__convert.Length();
    ConvertedProperties metadata__convert(metadata);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_UpdateUserApplicationProfileCallback cb__native = [](auto result,
                                                                        void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_UpdateUserApplicationProfile(&instance,
                                                token__span,
                                                applicationId,
                                                userId,
                                                providerIssuedUserId__span,
                                                username__span,
                                                metadata__convert.Properties,
                                                cb__native,
                                                &Tcb__UserData::Free,
                                                cb__userData);
#endif
}
void UDiscordClient::UpdateUserApplicationProfile(
  FString const& token,
  FDiscordUniqueID applicationId,
  FDiscordUniqueID userId,
  FString const& providerIssuedUserId,
  FString const& username,
  TMap<FString, FString> const& metadata,
  FDiscordClientUpdateUserApplicationProfileCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::UpdateUserApplicationProfile cannot "
                "be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String token__span;
    FTCHARToUTF8 token__convert(*token);
    token__span.ptr = (uint8*)token__convert.Get();
    token__span.size = token__convert.Length();
    Discord_String providerIssuedUserId__span;
    FTCHARToUTF8 providerIssuedUserId__convert(*providerIssuedUserId);
    providerIssuedUserId__span.ptr = (uint8*)providerIssuedUserId__convert.Get();
    providerIssuedUserId__span.size = providerIssuedUserId__convert.Length();
    Discord_String username__span;
    FTCHARToUTF8 username__convert(*username);
    username__span.ptr = (uint8*)username__convert.Get();
    username__span.size = username__convert.Length();
    ConvertedProperties metadata__convert(metadata);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_UpdateUserApplicationProfileCallback cb__native = [](auto result,
                                                                        void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_UpdateUserApplicationProfile(&instance,
                                                token__span,
                                                applicationId,
                                                userId,
                                                providerIssuedUserId__span,
                                                username__span,
                                                metadata__convert.Properties,
                                                cb__native,
                                                &Tcb__UserData::Free,
                                                cb__userData);
#endif
}
#endif
void UDiscordClient::EndCall(FDiscordUniqueID channelId,
                             FDiscordClientEndCallCallback const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - Client::EndCall cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_EndCallCallback callback__native = [](void* userData__) {
        auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
        userData__typed->delegate.ExecuteIfBound();
    };
    Discord_Client_EndCall(
      &instance, channelId, callback__native, &Tcallback__UserData::Free, callback__userData);
#endif
}
void UDiscordClient::EndCall(FDiscordUniqueID channelId,
                             FDiscordClientEndCallCallbackDynamic const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - Client::EndCall cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_EndCallCallback callback__native = [](void* userData__) {
        auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
        userData__typed->delegate.ExecuteIfBound();
    };
    Discord_Client_EndCall(
      &instance, channelId, callback__native, &Tcallback__UserData::Free, callback__userData);
#endif
}
void UDiscordClient::EndCalls(FDiscordClientEndCallsCallback const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - Client::EndCalls cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_EndCallsCallback callback__native = [](void* userData__) {
        auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
        userData__typed->delegate.ExecuteIfBound();
    };
    Discord_Client_EndCalls(
      &instance, callback__native, &Tcallback__UserData::Free, callback__userData);
#endif
}
void UDiscordClient::EndCalls(FDiscordClientEndCallsCallbackDynamic const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - Client::EndCalls cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_EndCallsCallback callback__native = [](void* userData__) {
        auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
        userData__typed->delegate.ExecuteIfBound();
    };
    Discord_Client_EndCalls(
      &instance, callback__native, &Tcallback__UserData::Free, callback__userData);
#endif
}
UDiscordCall* UDiscordClient::GetCall(FDiscordUniqueID channelId)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - Client::GetCall cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool returnIsNonNull__{};
    Discord_Call returnValueNative__;
    UDiscordCall* returnValue__{};
    returnIsNonNull__ = Discord_Client_GetCall(&instance, channelId, &returnValueNative__);
    if (!returnIsNonNull__) {
        return {};
    }
    returnValue__ = NewObject<UDiscordCall>();
    returnValue__->instance = returnValueNative__;
    returnValue__->state = DiscordUObjectState::Owned;
    return returnValue__;
#endif
}
TArray<UDiscordCall*> UDiscordClient::GetCalls()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - Client::GetCalls cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_CallSpan returnValueNative__;
    Discord_Client_GetCalls(&instance, &returnValueNative__);
    TArray<UDiscordCall*> returnValue__;
    returnValue__.Reserve(returnValueNative__.size);
    for (size_t i__ = 0; i__ < returnValueNative__.size; ++i__) {
        auto instance__ = NewObject<UDiscordCall>();
        instance__->instance = returnValueNative__.ptr[i__];
        instance__->state = DiscordUObjectState::Owned;
        returnValue__.Add(instance__);
    }
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;
#endif
}
void UDiscordClient::GetCurrentInputDevice(FDiscordClientGetCurrentInputDeviceCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Client::GetCurrentInputDevice cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_GetCurrentInputDeviceCallback cb__native = [](auto device, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordAudioDevice* device__instance = nullptr;
        device__instance = NewObject<UDiscordAudioDevice>();
        device__instance->instance = *device;
        device__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(device__instance);
    };
    Discord_Client_GetCurrentInputDevice(&instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::GetCurrentInputDevice(
  FDiscordClientGetCurrentInputDeviceCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Client::GetCurrentInputDevice cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_GetCurrentInputDeviceCallback cb__native = [](auto device, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordAudioDevice* device__instance = nullptr;
        device__instance = NewObject<UDiscordAudioDevice>();
        device__instance->instance = *device;
        device__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(device__instance);
    };
    Discord_Client_GetCurrentInputDevice(&instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::GetCurrentOutputDevice(FDiscordClientGetCurrentOutputDeviceCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Client::GetCurrentOutputDevice cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_GetCurrentOutputDeviceCallback cb__native = [](auto device, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordAudioDevice* device__instance = nullptr;
        device__instance = NewObject<UDiscordAudioDevice>();
        device__instance->instance = *device;
        device__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(device__instance);
    };
    Discord_Client_GetCurrentOutputDevice(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::GetCurrentOutputDevice(
  FDiscordClientGetCurrentOutputDeviceCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Client::GetCurrentOutputDevice cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_GetCurrentOutputDeviceCallback cb__native = [](auto device, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordAudioDevice* device__instance = nullptr;
        device__instance = NewObject<UDiscordAudioDevice>();
        device__instance->instance = *device;
        device__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(device__instance);
    };
    Discord_Client_GetCurrentOutputDevice(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::GetInputDevices(FDiscordClientGetInputDevicesCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::GetInputDevices cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_GetInputDevicesCallback cb__native = [](auto devices, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        TArray<UDiscordAudioDevice*> devices__array;
        devices__array.Reserve(devices.size);
        for (size_t i__ = 0; i__ < devices.size; ++i__) {
            auto instance__ = NewObject<UDiscordAudioDevice>();
            instance__->instance = devices.ptr[i__];
            instance__->state = DiscordUObjectState::Owned;
            devices__array.Add(instance__);
        }
        Discord_Free(devices.ptr);
        userData__typed->delegate.ExecuteIfBound(devices__array);
    };
    Discord_Client_GetInputDevices(&instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::GetInputDevices(FDiscordClientGetInputDevicesCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::GetInputDevices cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_GetInputDevicesCallback cb__native = [](auto devices, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        TArray<UDiscordAudioDevice*> devices__array;
        devices__array.Reserve(devices.size);
        for (size_t i__ = 0; i__ < devices.size; ++i__) {
            auto instance__ = NewObject<UDiscordAudioDevice>();
            instance__->instance = devices.ptr[i__];
            instance__->state = DiscordUObjectState::Owned;
            devices__array.Add(instance__);
        }
        Discord_Free(devices.ptr);
        userData__typed->delegate.ExecuteIfBound(devices__array);
    };
    Discord_Client_GetInputDevices(&instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
float UDiscordClient::GetInputVolume()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::GetInputVolume cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    float returnValue__;
    returnValue__ = Discord_Client_GetInputVolume(&instance);
    return returnValue__;
#endif
}
void UDiscordClient::GetOutputDevices(FDiscordClientGetOutputDevicesCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::GetOutputDevices cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_GetOutputDevicesCallback cb__native = [](auto devices, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        TArray<UDiscordAudioDevice*> devices__array;
        devices__array.Reserve(devices.size);
        for (size_t i__ = 0; i__ < devices.size; ++i__) {
            auto instance__ = NewObject<UDiscordAudioDevice>();
            instance__->instance = devices.ptr[i__];
            instance__->state = DiscordUObjectState::Owned;
            devices__array.Add(instance__);
        }
        Discord_Free(devices.ptr);
        userData__typed->delegate.ExecuteIfBound(devices__array);
    };
    Discord_Client_GetOutputDevices(&instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::GetOutputDevices(FDiscordClientGetOutputDevicesCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::GetOutputDevices cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_GetOutputDevicesCallback cb__native = [](auto devices, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        TArray<UDiscordAudioDevice*> devices__array;
        devices__array.Reserve(devices.size);
        for (size_t i__ = 0; i__ < devices.size; ++i__) {
            auto instance__ = NewObject<UDiscordAudioDevice>();
            instance__->instance = devices.ptr[i__];
            instance__->state = DiscordUObjectState::Owned;
            devices__array.Add(instance__);
        }
        Discord_Free(devices.ptr);
        userData__typed->delegate.ExecuteIfBound(devices__array);
    };
    Discord_Client_GetOutputDevices(&instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
float UDiscordClient::GetOutputVolume()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::GetOutputVolume cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    float returnValue__;
    returnValue__ = Discord_Client_GetOutputVolume(&instance);
    return returnValue__;
#endif
}
bool UDiscordClient::GetSelfDeafAll()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::GetSelfDeafAll cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool returnValue__;
    returnValue__ = Discord_Client_GetSelfDeafAll(&instance);
    return returnValue__;
#endif
}
bool UDiscordClient::GetSelfMuteAll()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::GetSelfMuteAll cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool returnValue__;
    returnValue__ = Discord_Client_GetSelfMuteAll(&instance);
    return returnValue__;
#endif
}
void UDiscordClient::SetAecDump(bool on)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - Client::SetAecDump cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_Client_SetAecDump(&instance, on);
#endif
}
void UDiscordClient::SetAutomaticGainControl(bool on)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Client::SetAutomaticGainControl cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_Client_SetAutomaticGainControl(&instance, on);
#endif
}
void UDiscordClient::SetDeviceChangeCallback(FDiscordClientDeviceChangeCallback const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Client::SetDeviceChangeCallback cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_DeviceChangeCallback callback__native =
      [](auto inputDevices, auto outputDevices, void* userData__) {
          auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
          TArray<UDiscordAudioDevice*> inputDevices__array;
          inputDevices__array.Reserve(inputDevices.size);
          for (size_t i__ = 0; i__ < inputDevices.size; ++i__) {
              auto instance__ = NewObject<UDiscordAudioDevice>();
              instance__->instance = inputDevices.ptr[i__];
              instance__->state = DiscordUObjectState::Owned;
              inputDevices__array.Add(instance__);
          }
          Discord_Free(inputDevices.ptr);
          TArray<UDiscordAudioDevice*> outputDevices__array;
          outputDevices__array.Reserve(outputDevices.size);
          for (size_t i__ = 0; i__ < outputDevices.size; ++i__) {
              auto instance__ = NewObject<UDiscordAudioDevice>();
              instance__->instance = outputDevices.ptr[i__];
              instance__->state = DiscordUObjectState::Owned;
              outputDevices__array.Add(instance__);
          }
          Discord_Free(outputDevices.ptr);
          userData__typed->delegate.ExecuteIfBound(inputDevices__array, outputDevices__array);
      };
    Discord_Client_SetDeviceChangeCallback(
      &instance, callback__native, &Tcallback__UserData::Free, callback__userData);
#endif
}
void UDiscordClient::SetDeviceChangeCallback(
  FDiscordClientDeviceChangeCallbackDynamic const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Client::SetDeviceChangeCallback cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_DeviceChangeCallback callback__native =
      [](auto inputDevices, auto outputDevices, void* userData__) {
          auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
          TArray<UDiscordAudioDevice*> inputDevices__array;
          inputDevices__array.Reserve(inputDevices.size);
          for (size_t i__ = 0; i__ < inputDevices.size; ++i__) {
              auto instance__ = NewObject<UDiscordAudioDevice>();
              instance__->instance = inputDevices.ptr[i__];
              instance__->state = DiscordUObjectState::Owned;
              inputDevices__array.Add(instance__);
          }
          Discord_Free(inputDevices.ptr);
          TArray<UDiscordAudioDevice*> outputDevices__array;
          outputDevices__array.Reserve(outputDevices.size);
          for (size_t i__ = 0; i__ < outputDevices.size; ++i__) {
              auto instance__ = NewObject<UDiscordAudioDevice>();
              instance__->instance = outputDevices.ptr[i__];
              instance__->state = DiscordUObjectState::Owned;
              outputDevices__array.Add(instance__);
          }
          Discord_Free(outputDevices.ptr);
          userData__typed->delegate.ExecuteIfBound(inputDevices__array, outputDevices__array);
      };
    Discord_Client_SetDeviceChangeCallback(
      &instance, callback__native, &Tcallback__UserData::Free, callback__userData);
#endif
}
void UDiscordClient::SetEchoCancellation(bool on)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Client::SetEchoCancellation cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_Client_SetEchoCancellation(&instance, on);
#endif
}
void UDiscordClient::SetEngineManagedAudioSession(bool isEngineManaged)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::SetEngineManagedAudioSession cannot "
                "be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_Client_SetEngineManagedAudioSession(&instance, isEngineManaged);
#endif
}
void UDiscordClient::SetInputDevice(FString const& deviceId,
                                    FDiscordClientSetInputDeviceCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::SetInputDevice cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String deviceId__span;
    FTCHARToUTF8 deviceId__convert(*deviceId);
    deviceId__span.ptr = (uint8*)deviceId__convert.Get();
    deviceId__span.size = deviceId__convert.Length();
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_SetInputDeviceCallback cb__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_SetInputDevice(
      &instance, deviceId__span, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SetInputDevice(FString const& deviceId,
                                    FDiscordClientSetInputDeviceCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::SetInputDevice cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String deviceId__span;
    FTCHARToUTF8 deviceId__convert(*deviceId);
    deviceId__span.ptr = (uint8*)deviceId__convert.Get();
    deviceId__span.size = deviceId__convert.Length();
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_SetInputDeviceCallback cb__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_SetInputDevice(
      &instance, deviceId__span, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SetInputVolume(float inputVolume)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::SetInputVolume cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_Client_SetInputVolume(&instance, inputVolume);
#endif
}
void UDiscordClient::SetNoAudioInputCallback(FDiscordClientNoAudioInputCallback const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Client::SetNoAudioInputCallback cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_NoAudioInputCallback callback__native = [](auto inputDetected,
                                                              void* userData__) {
        auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
        userData__typed->delegate.ExecuteIfBound(inputDetected);
    };
    Discord_Client_SetNoAudioInputCallback(
      &instance, callback__native, &Tcallback__UserData::Free, callback__userData);
#endif
}
void UDiscordClient::SetNoAudioInputCallback(
  FDiscordClientNoAudioInputCallbackDynamic const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Client::SetNoAudioInputCallback cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_NoAudioInputCallback callback__native = [](auto inputDetected,
                                                              void* userData__) {
        auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
        userData__typed->delegate.ExecuteIfBound(inputDetected);
    };
    Discord_Client_SetNoAudioInputCallback(
      &instance, callback__native, &Tcallback__UserData::Free, callback__userData);
#endif
}
void UDiscordClient::SetNoAudioInputThreshold(float dBFSThreshold)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Client::SetNoAudioInputThreshold cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_Client_SetNoAudioInputThreshold(&instance, dBFSThreshold);
#endif
}
void UDiscordClient::SetNoiseSuppression(bool on)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Client::SetNoiseSuppression cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_Client_SetNoiseSuppression(&instance, on);
#endif
}
void UDiscordClient::SetOpusHardwareCoding(bool encode, bool decode)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Client::SetOpusHardwareCoding cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_Client_SetOpusHardwareCoding(&instance, encode, decode);
#endif
}
void UDiscordClient::SetOutputDevice(FString const& deviceId,
                                     FDiscordClientSetOutputDeviceCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::SetOutputDevice cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String deviceId__span;
    FTCHARToUTF8 deviceId__convert(*deviceId);
    deviceId__span.ptr = (uint8*)deviceId__convert.Get();
    deviceId__span.size = deviceId__convert.Length();
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_SetOutputDeviceCallback cb__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_SetOutputDevice(
      &instance, deviceId__span, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SetOutputDevice(FString const& deviceId,
                                     FDiscordClientSetOutputDeviceCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::SetOutputDevice cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String deviceId__span;
    FTCHARToUTF8 deviceId__convert(*deviceId);
    deviceId__span.ptr = (uint8*)deviceId__convert.Get();
    deviceId__span.size = deviceId__convert.Length();
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_SetOutputDeviceCallback cb__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_SetOutputDevice(
      &instance, deviceId__span, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SetOutputVolume(float outputVolume)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::SetOutputVolume cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_Client_SetOutputVolume(&instance, outputVolume);
#endif
}
void UDiscordClient::SetSelfDeafAll(bool deaf)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::SetSelfDeafAll cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_Client_SetSelfDeafAll(&instance, deaf);
#endif
}
void UDiscordClient::SetSelfMuteAll(bool mute)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::SetSelfMuteAll cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_Client_SetSelfMuteAll(&instance, mute);
#endif
}
bool UDiscordClient::SetSpeakerMode(bool speakerMode)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::SetSpeakerMode cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool returnValue__;
    returnValue__ = Discord_Client_SetSpeakerMode(&instance, speakerMode);
    return returnValue__;
#endif
}
void UDiscordClient::SetThreadPriority(EDiscordClientThread thread, int32 priority)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::SetThreadPriority cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_Client_SetThreadPriority(
      &instance, static_cast<Discord_Client_Thread>(thread), priority);
#endif
}
void UDiscordClient::SetVoiceParticipantChangedCallback(
  FDiscordClientVoiceParticipantChangedCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::SetVoiceParticipantChangedCallback "
                "cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_VoiceParticipantChangedCallback cb__native =
      [](auto lobbyId, auto memberId, auto added, void* userData__) {
          auto userData__typed = static_cast<Tcb__UserData*>(userData__);
          userData__typed->delegate.ExecuteIfBound(lobbyId, memberId, added);
      };
    Discord_Client_SetVoiceParticipantChangedCallback(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SetVoiceParticipantChangedCallback(
  FDiscordClientVoiceParticipantChangedCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::SetVoiceParticipantChangedCallback "
                "cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_VoiceParticipantChangedCallback cb__native =
      [](auto lobbyId, auto memberId, auto added, void* userData__) {
          auto userData__typed = static_cast<Tcb__UserData*>(userData__);
          userData__typed->delegate.ExecuteIfBound(lobbyId, memberId, added);
      };
    Discord_Client_SetVoiceParticipantChangedCallback(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
bool UDiscordClient::ShowAudioRoutePicker()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Client::ShowAudioRoutePicker cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool returnValue__;
    returnValue__ = Discord_Client_ShowAudioRoutePicker(&instance);
    return returnValue__;
#endif
}
UDiscordCall* UDiscordClient::StartCall(FDiscordUniqueID channelId)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - Client::StartCall cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool returnIsNonNull__{};
    Discord_Call returnValueNative__;
    UDiscordCall* returnValue__{};
    returnIsNonNull__ = Discord_Client_StartCall(&instance, channelId, &returnValueNative__);
    if (!returnIsNonNull__) {
        return {};
    }
    returnValue__ = NewObject<UDiscordCall>();
    returnValue__->instance = returnValueNative__;
    returnValue__->state = DiscordUObjectState::Owned;
    return returnValue__;
#endif
}
UDiscordCall* UDiscordClient::StartCallWithAudioCallbacks(
  FDiscordUniqueID lobbyId,
  FDiscordClientUserAudioReceivedCallback const& receivedCb,
  FDiscordClientUserAudioCapturedCallback const& capturedCb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::StartCallWithAudioCallbacks cannot "
                "be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool returnIsNonNull__{};
    Discord_Call returnValueNative__;
    UDiscordCall* returnValue__{};
    using TreceivedCb__UserData = TDelegateUserData<std::remove_reference_t<decltype(receivedCb)>>;
    auto receivedCb__userData = new TreceivedCb__UserData(receivedCb);
    Discord_Client_UserAudioReceivedCallback receivedCb__native = [](auto userId,
                                                                     auto data,
                                                                     auto samplesPerChannel,
                                                                     auto sampleRate,
                                                                     auto channels,
                                                                     auto outShouldMute,
                                                                     void* userData__) {
        auto userData__typed = static_cast<TreceivedCb__UserData*>(userData__);
        userData__typed->delegate.ExecuteIfBound(userId,
                                                 reinterpret_cast<int64>(data),
                                                 samplesPerChannel,
                                                 sampleRate,
                                                 channels,
                                                 *outShouldMute);
    };
    using TcapturedCb__UserData = TDelegateUserData<std::remove_reference_t<decltype(capturedCb)>>;
    auto capturedCb__userData = new TcapturedCb__UserData(capturedCb);
    Discord_Client_UserAudioCapturedCallback capturedCb__native =
      [](auto data, auto samplesPerChannel, auto sampleRate, auto channels, void* userData__) {
          auto userData__typed = static_cast<TcapturedCb__UserData*>(userData__);
          userData__typed->delegate.ExecuteIfBound(
            reinterpret_cast<int64>(data), samplesPerChannel, sampleRate, channels);
      };
    returnIsNonNull__ = Discord_Client_StartCallWithAudioCallbacks(&instance,
                                                                   lobbyId,
                                                                   receivedCb__native,
                                                                   &TreceivedCb__UserData::Free,
                                                                   receivedCb__userData,
                                                                   capturedCb__native,
                                                                   &TcapturedCb__UserData::Free,
                                                                   capturedCb__userData,
                                                                   &returnValueNative__);
    if (!returnIsNonNull__) {
        return {};
    }
    returnValue__ = NewObject<UDiscordCall>();
    returnValue__->instance = returnValueNative__;
    returnValue__->state = DiscordUObjectState::Owned;
    return returnValue__;
#endif
}
UDiscordCall* UDiscordClient::StartCallWithAudioCallbacks(
  FDiscordUniqueID lobbyId,
  FDiscordClientUserAudioReceivedCallbackDynamic const& receivedCb,
  FDiscordClientUserAudioCapturedCallbackDynamic const& capturedCb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::StartCallWithAudioCallbacks cannot "
                "be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool returnIsNonNull__{};
    Discord_Call returnValueNative__;
    UDiscordCall* returnValue__{};
    using TreceivedCb__UserData = TDelegateUserData<std::remove_reference_t<decltype(receivedCb)>>;
    auto receivedCb__userData = new TreceivedCb__UserData(receivedCb);
    Discord_Client_UserAudioReceivedCallback receivedCb__native = [](auto userId,
                                                                     auto data,
                                                                     auto samplesPerChannel,
                                                                     auto sampleRate,
                                                                     auto channels,
                                                                     auto outShouldMute,
                                                                     void* userData__) {
        auto userData__typed = static_cast<TreceivedCb__UserData*>(userData__);
        userData__typed->delegate.ExecuteIfBound(userId,
                                                 reinterpret_cast<int64>(data),
                                                 samplesPerChannel,
                                                 sampleRate,
                                                 channels,
                                                 *outShouldMute);
    };
    using TcapturedCb__UserData = TDelegateUserData<std::remove_reference_t<decltype(capturedCb)>>;
    auto capturedCb__userData = new TcapturedCb__UserData(capturedCb);
    Discord_Client_UserAudioCapturedCallback capturedCb__native =
      [](auto data, auto samplesPerChannel, auto sampleRate, auto channels, void* userData__) {
          auto userData__typed = static_cast<TcapturedCb__UserData*>(userData__);
          userData__typed->delegate.ExecuteIfBound(
            reinterpret_cast<int64>(data), samplesPerChannel, sampleRate, channels);
      };
    returnIsNonNull__ = Discord_Client_StartCallWithAudioCallbacks(&instance,
                                                                   lobbyId,
                                                                   receivedCb__native,
                                                                   &TreceivedCb__UserData::Free,
                                                                   receivedCb__userData,
                                                                   capturedCb__native,
                                                                   &TcapturedCb__UserData::Free,
                                                                   capturedCb__userData,
                                                                   &returnValueNative__);
    if (!returnIsNonNull__) {
        return {};
    }
    returnValue__ = NewObject<UDiscordCall>();
    returnValue__->instance = returnValueNative__;
    returnValue__->state = DiscordUObjectState::Owned;
    return returnValue__;
#endif
}
void UDiscordClient::AbortAuthorize()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::AbortAuthorize cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_Client_AbortAuthorize(&instance);
#endif
}
void UDiscordClient::AbortGetTokenFromDevice()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Client::AbortGetTokenFromDevice cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_Client_AbortGetTokenFromDevice(&instance);
#endif
}
void UDiscordClient::Authorize(UDiscordAuthorizationArgs* args,
                               FDiscordClientAuthorizationCallback const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - Client::Authorize cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_AuthorizationArgs* args__instance = args ? &args->instance : nullptr;
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_AuthorizationCallback callback__native =
      [](auto result, auto code, auto redirectUri, void* userData__) {
          auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
          UDiscordClientResult* result__instance = nullptr;
          result__instance = NewObject<UDiscordClientResult>();
          result__instance->instance = *result;
          result__instance->state = DiscordUObjectState::Owned;
          FString code__string;
          code__string.AppendChars(DISCORD_CHAR_CAST(code.ptr), code.size);
          FString redirectUri__string;
          redirectUri__string.AppendChars(DISCORD_CHAR_CAST(redirectUri.ptr), redirectUri.size);
          userData__typed->delegate.ExecuteIfBound(
            result__instance, std::move(code__string), std::move(redirectUri__string));
          Discord_Free(redirectUri.ptr);
          Discord_Free(code.ptr);
      };
    Discord_Client_Authorize(
      &instance, args__instance, callback__native, &Tcallback__UserData::Free, callback__userData);
#endif
}
void UDiscordClient::Authorize(UDiscordAuthorizationArgs* args,
                               FDiscordClientAuthorizationCallbackDynamic const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - Client::Authorize cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_AuthorizationArgs* args__instance = args ? &args->instance : nullptr;
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_AuthorizationCallback callback__native =
      [](auto result, auto code, auto redirectUri, void* userData__) {
          auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
          UDiscordClientResult* result__instance = nullptr;
          result__instance = NewObject<UDiscordClientResult>();
          result__instance->instance = *result;
          result__instance->state = DiscordUObjectState::Owned;
          FString code__string;
          code__string.AppendChars(DISCORD_CHAR_CAST(code.ptr), code.size);
          FString redirectUri__string;
          redirectUri__string.AppendChars(DISCORD_CHAR_CAST(redirectUri.ptr), redirectUri.size);
          userData__typed->delegate.ExecuteIfBound(
            result__instance, std::move(code__string), std::move(redirectUri__string));
          Discord_Free(redirectUri.ptr);
          Discord_Free(code.ptr);
      };
    Discord_Client_Authorize(
      &instance, args__instance, callback__native, &Tcallback__UserData::Free, callback__userData);
#endif
}
void UDiscordClient::CloseAuthorizeDeviceScreen()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::CloseAuthorizeDeviceScreen cannot be "
                "called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_Client_CloseAuthorizeDeviceScreen(&instance);
#endif
}
UDiscordAuthorizationCodeVerifier* UDiscordClient::CreateAuthorizationCodeVerifier()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::CreateAuthorizationCodeVerifier "
                "cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_AuthorizationCodeVerifier returnValueNative__;
    UDiscordAuthorizationCodeVerifier* returnValue__ = nullptr;
    Discord_Client_CreateAuthorizationCodeVerifier(&instance, &returnValueNative__);
    returnValue__ = NewObject<UDiscordAuthorizationCodeVerifier>();
    returnValue__->instance = returnValueNative__;
    returnValue__->state = DiscordUObjectState::Owned;
    return returnValue__;
#endif
}
void UDiscordClient::ExchangeChildToken(FString const& parentApplicationToken,
                                        FDiscordUniqueID childApplicationId,
                                        FDiscordClientExchangeChildTokenCallback const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Client::ExchangeChildToken cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String parentApplicationToken__span;
    FTCHARToUTF8 parentApplicationToken__convert(*parentApplicationToken);
    parentApplicationToken__span.ptr = (uint8*)parentApplicationToken__convert.Get();
    parentApplicationToken__span.size = parentApplicationToken__convert.Length();
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_ExchangeChildTokenCallback callback__native = [](auto result,
                                                                    auto accessToken,
                                                                    auto tokenType,
                                                                    auto expiresIn,
                                                                    auto scopes,
                                                                    void* userData__) {
        auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        FString accessToken__string;
        accessToken__string.AppendChars(DISCORD_CHAR_CAST(accessToken.ptr), accessToken.size);
        FString scopes__string;
        scopes__string.AppendChars(DISCORD_CHAR_CAST(scopes.ptr), scopes.size);
        userData__typed->delegate.ExecuteIfBound(
          result__instance,
          std::move(accessToken__string),
          static_cast<EDiscordAuthorizationTokenType>(tokenType),
          expiresIn,
          std::move(scopes__string));
        Discord_Free(scopes.ptr);
        Discord_Free(accessToken.ptr);
    };
    Discord_Client_ExchangeChildToken(&instance,
                                      parentApplicationToken__span,
                                      childApplicationId,
                                      callback__native,
                                      &Tcallback__UserData::Free,
                                      callback__userData);
#endif
}
void UDiscordClient::ExchangeChildToken(
  FString const& parentApplicationToken,
  FDiscordUniqueID childApplicationId,
  FDiscordClientExchangeChildTokenCallbackDynamic const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Client::ExchangeChildToken cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String parentApplicationToken__span;
    FTCHARToUTF8 parentApplicationToken__convert(*parentApplicationToken);
    parentApplicationToken__span.ptr = (uint8*)parentApplicationToken__convert.Get();
    parentApplicationToken__span.size = parentApplicationToken__convert.Length();
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_ExchangeChildTokenCallback callback__native = [](auto result,
                                                                    auto accessToken,
                                                                    auto tokenType,
                                                                    auto expiresIn,
                                                                    auto scopes,
                                                                    void* userData__) {
        auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        FString accessToken__string;
        accessToken__string.AppendChars(DISCORD_CHAR_CAST(accessToken.ptr), accessToken.size);
        FString scopes__string;
        scopes__string.AppendChars(DISCORD_CHAR_CAST(scopes.ptr), scopes.size);
        userData__typed->delegate.ExecuteIfBound(
          result__instance,
          std::move(accessToken__string),
          static_cast<EDiscordAuthorizationTokenType>(tokenType),
          expiresIn,
          std::move(scopes__string));
        Discord_Free(scopes.ptr);
        Discord_Free(accessToken.ptr);
    };
    Discord_Client_ExchangeChildToken(&instance,
                                      parentApplicationToken__span,
                                      childApplicationId,
                                      callback__native,
                                      &Tcallback__UserData::Free,
                                      callback__userData);
#endif
}
void UDiscordClient::FetchCurrentUser(EDiscordAuthorizationTokenType tokenType,
                                      FString const& token,
                                      FDiscordClientFetchCurrentUserCallback const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::FetchCurrentUser cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String token__span;
    FTCHARToUTF8 token__convert(*token);
    token__span.ptr = (uint8*)token__convert.Get();
    token__span.size = token__convert.Length();
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_FetchCurrentUserCallback callback__native =
      [](auto result, auto id, auto name, void* userData__) {
          auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
          UDiscordClientResult* result__instance = nullptr;
          result__instance = NewObject<UDiscordClientResult>();
          result__instance->instance = *result;
          result__instance->state = DiscordUObjectState::Owned;
          FString name__string;
          name__string.AppendChars(DISCORD_CHAR_CAST(name.ptr), name.size);
          userData__typed->delegate.ExecuteIfBound(result__instance, id, std::move(name__string));
          Discord_Free(name.ptr);
      };
    Discord_Client_FetchCurrentUser(&instance,
                                    static_cast<Discord_AuthorizationTokenType>(tokenType),
                                    token__span,
                                    callback__native,
                                    &Tcallback__UserData::Free,
                                    callback__userData);
#endif
}
void UDiscordClient::FetchCurrentUser(EDiscordAuthorizationTokenType tokenType,
                                      FString const& token,
                                      FDiscordClientFetchCurrentUserCallbackDynamic const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::FetchCurrentUser cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String token__span;
    FTCHARToUTF8 token__convert(*token);
    token__span.ptr = (uint8*)token__convert.Get();
    token__span.size = token__convert.Length();
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_FetchCurrentUserCallback callback__native =
      [](auto result, auto id, auto name, void* userData__) {
          auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
          UDiscordClientResult* result__instance = nullptr;
          result__instance = NewObject<UDiscordClientResult>();
          result__instance->instance = *result;
          result__instance->state = DiscordUObjectState::Owned;
          FString name__string;
          name__string.AppendChars(DISCORD_CHAR_CAST(name.ptr), name.size);
          userData__typed->delegate.ExecuteIfBound(result__instance, id, std::move(name__string));
          Discord_Free(name.ptr);
      };
    Discord_Client_FetchCurrentUser(&instance,
                                    static_cast<Discord_AuthorizationTokenType>(tokenType),
                                    token__span,
                                    callback__native,
                                    &Tcallback__UserData::Free,
                                    callback__userData);
#endif
}
void UDiscordClient::GetProvisionalToken(FDiscordUniqueID applicationId,
                                         EDiscordAuthenticationExternalAuthType externalAuthType,
                                         FString const& externalAuthToken,
                                         FDiscordClientTokenExchangeCallback const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Client::GetProvisionalToken cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String externalAuthToken__span;
    FTCHARToUTF8 externalAuthToken__convert(*externalAuthToken);
    externalAuthToken__span.ptr = (uint8*)externalAuthToken__convert.Get();
    externalAuthToken__span.size = externalAuthToken__convert.Length();
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_TokenExchangeCallback callback__native = [](auto result,
                                                               auto accessToken,
                                                               auto refreshToken,
                                                               auto tokenType,
                                                               auto expiresIn,
                                                               auto scopes,
                                                               void* userData__) {
        auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        FString accessToken__string;
        accessToken__string.AppendChars(DISCORD_CHAR_CAST(accessToken.ptr), accessToken.size);
        FString refreshToken__string;
        refreshToken__string.AppendChars(DISCORD_CHAR_CAST(refreshToken.ptr), refreshToken.size);
        FString scopes__string;
        scopes__string.AppendChars(DISCORD_CHAR_CAST(scopes.ptr), scopes.size);
        userData__typed->delegate.ExecuteIfBound(
          result__instance,
          std::move(accessToken__string),
          std::move(refreshToken__string),
          static_cast<EDiscordAuthorizationTokenType>(tokenType),
          expiresIn,
          std::move(scopes__string));
        Discord_Free(scopes.ptr);
        Discord_Free(refreshToken.ptr);
        Discord_Free(accessToken.ptr);
    };
    Discord_Client_GetProvisionalToken(
      &instance,
      applicationId,
      static_cast<Discord_AuthenticationExternalAuthType>(externalAuthType),
      externalAuthToken__span,
      callback__native,
      &Tcallback__UserData::Free,
      callback__userData);
#endif
}
void UDiscordClient::GetProvisionalToken(FDiscordUniqueID applicationId,
                                         EDiscordAuthenticationExternalAuthType externalAuthType,
                                         FString const& externalAuthToken,
                                         FDiscordClientTokenExchangeCallbackDynamic const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Client::GetProvisionalToken cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String externalAuthToken__span;
    FTCHARToUTF8 externalAuthToken__convert(*externalAuthToken);
    externalAuthToken__span.ptr = (uint8*)externalAuthToken__convert.Get();
    externalAuthToken__span.size = externalAuthToken__convert.Length();
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_TokenExchangeCallback callback__native = [](auto result,
                                                               auto accessToken,
                                                               auto refreshToken,
                                                               auto tokenType,
                                                               auto expiresIn,
                                                               auto scopes,
                                                               void* userData__) {
        auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        FString accessToken__string;
        accessToken__string.AppendChars(DISCORD_CHAR_CAST(accessToken.ptr), accessToken.size);
        FString refreshToken__string;
        refreshToken__string.AppendChars(DISCORD_CHAR_CAST(refreshToken.ptr), refreshToken.size);
        FString scopes__string;
        scopes__string.AppendChars(DISCORD_CHAR_CAST(scopes.ptr), scopes.size);
        userData__typed->delegate.ExecuteIfBound(
          result__instance,
          std::move(accessToken__string),
          std::move(refreshToken__string),
          static_cast<EDiscordAuthorizationTokenType>(tokenType),
          expiresIn,
          std::move(scopes__string));
        Discord_Free(scopes.ptr);
        Discord_Free(refreshToken.ptr);
        Discord_Free(accessToken.ptr);
    };
    Discord_Client_GetProvisionalToken(
      &instance,
      applicationId,
      static_cast<Discord_AuthenticationExternalAuthType>(externalAuthType),
      externalAuthToken__span,
      callback__native,
      &Tcallback__UserData::Free,
      callback__userData);
#endif
}
#if DISCORD_DEBUG_API_ENABLED
void UDiscordClient::GetProvisionalTokenBotAPI(FDiscordUniqueID applicationId,
                                               FString const& botToken,
                                               FString const& externalUserId,
                                               FString const& preferredGlobalName,
                                               FDiscordClientTokenExchangeCallback const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Client::GetProvisionalTokenBotAPI cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String botToken__span;
    FTCHARToUTF8 botToken__convert(*botToken);
    botToken__span.ptr = (uint8*)botToken__convert.Get();
    botToken__span.size = botToken__convert.Length();
    Discord_String externalUserId__span;
    FTCHARToUTF8 externalUserId__convert(*externalUserId);
    externalUserId__span.ptr = (uint8*)externalUserId__convert.Get();
    externalUserId__span.size = externalUserId__convert.Length();
    Discord_String preferredGlobalName__span;
    FTCHARToUTF8 preferredGlobalName__convert(*preferredGlobalName);
    preferredGlobalName__span.ptr = (uint8*)preferredGlobalName__convert.Get();
    preferredGlobalName__span.size = preferredGlobalName__convert.Length();
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_TokenExchangeCallback callback__native = [](auto result,
                                                               auto accessToken,
                                                               auto refreshToken,
                                                               auto tokenType,
                                                               auto expiresIn,
                                                               auto scopes,
                                                               void* userData__) {
        auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        FString accessToken__string;
        accessToken__string.AppendChars(DISCORD_CHAR_CAST(accessToken.ptr), accessToken.size);
        FString refreshToken__string;
        refreshToken__string.AppendChars(DISCORD_CHAR_CAST(refreshToken.ptr), refreshToken.size);
        FString scopes__string;
        scopes__string.AppendChars(DISCORD_CHAR_CAST(scopes.ptr), scopes.size);
        userData__typed->delegate.ExecuteIfBound(
          result__instance,
          std::move(accessToken__string),
          std::move(refreshToken__string),
          static_cast<EDiscordAuthorizationTokenType>(tokenType),
          expiresIn,
          std::move(scopes__string));
        Discord_Free(scopes.ptr);
        Discord_Free(refreshToken.ptr);
        Discord_Free(accessToken.ptr);
    };
    Discord_Client_GetProvisionalTokenBotAPI(&instance,
                                             applicationId,
                                             botToken__span,
                                             externalUserId__span,
                                             preferredGlobalName__span,
                                             callback__native,
                                             &Tcallback__UserData::Free,
                                             callback__userData);
#endif
}
void UDiscordClient::GetProvisionalTokenBotAPI(
  FDiscordUniqueID applicationId,
  FString const& botToken,
  FString const& externalUserId,
  FString const& preferredGlobalName,
  FDiscordClientTokenExchangeCallbackDynamic const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Client::GetProvisionalTokenBotAPI cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String botToken__span;
    FTCHARToUTF8 botToken__convert(*botToken);
    botToken__span.ptr = (uint8*)botToken__convert.Get();
    botToken__span.size = botToken__convert.Length();
    Discord_String externalUserId__span;
    FTCHARToUTF8 externalUserId__convert(*externalUserId);
    externalUserId__span.ptr = (uint8*)externalUserId__convert.Get();
    externalUserId__span.size = externalUserId__convert.Length();
    Discord_String preferredGlobalName__span;
    FTCHARToUTF8 preferredGlobalName__convert(*preferredGlobalName);
    preferredGlobalName__span.ptr = (uint8*)preferredGlobalName__convert.Get();
    preferredGlobalName__span.size = preferredGlobalName__convert.Length();
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_TokenExchangeCallback callback__native = [](auto result,
                                                               auto accessToken,
                                                               auto refreshToken,
                                                               auto tokenType,
                                                               auto expiresIn,
                                                               auto scopes,
                                                               void* userData__) {
        auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        FString accessToken__string;
        accessToken__string.AppendChars(DISCORD_CHAR_CAST(accessToken.ptr), accessToken.size);
        FString refreshToken__string;
        refreshToken__string.AppendChars(DISCORD_CHAR_CAST(refreshToken.ptr), refreshToken.size);
        FString scopes__string;
        scopes__string.AppendChars(DISCORD_CHAR_CAST(scopes.ptr), scopes.size);
        userData__typed->delegate.ExecuteIfBound(
          result__instance,
          std::move(accessToken__string),
          std::move(refreshToken__string),
          static_cast<EDiscordAuthorizationTokenType>(tokenType),
          expiresIn,
          std::move(scopes__string));
        Discord_Free(scopes.ptr);
        Discord_Free(refreshToken.ptr);
        Discord_Free(accessToken.ptr);
    };
    Discord_Client_GetProvisionalTokenBotAPI(&instance,
                                             applicationId,
                                             botToken__span,
                                             externalUserId__span,
                                             preferredGlobalName__span,
                                             callback__native,
                                             &Tcallback__UserData::Free,
                                             callback__userData);
#endif
}
#endif
void UDiscordClient::GetToken(FDiscordUniqueID applicationId,
                              FString const& code,
                              FString const& codeVerifier,
                              FString const& redirectUri,
                              FDiscordClientTokenExchangeCallback const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - Client::GetToken cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String code__span;
    FTCHARToUTF8 code__convert(*code);
    code__span.ptr = (uint8*)code__convert.Get();
    code__span.size = code__convert.Length();
    Discord_String codeVerifier__span;
    FTCHARToUTF8 codeVerifier__convert(*codeVerifier);
    codeVerifier__span.ptr = (uint8*)codeVerifier__convert.Get();
    codeVerifier__span.size = codeVerifier__convert.Length();
    Discord_String redirectUri__span;
    FTCHARToUTF8 redirectUri__convert(*redirectUri);
    redirectUri__span.ptr = (uint8*)redirectUri__convert.Get();
    redirectUri__span.size = redirectUri__convert.Length();
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_TokenExchangeCallback callback__native = [](auto result,
                                                               auto accessToken,
                                                               auto refreshToken,
                                                               auto tokenType,
                                                               auto expiresIn,
                                                               auto scopes,
                                                               void* userData__) {
        auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        FString accessToken__string;
        accessToken__string.AppendChars(DISCORD_CHAR_CAST(accessToken.ptr), accessToken.size);
        FString refreshToken__string;
        refreshToken__string.AppendChars(DISCORD_CHAR_CAST(refreshToken.ptr), refreshToken.size);
        FString scopes__string;
        scopes__string.AppendChars(DISCORD_CHAR_CAST(scopes.ptr), scopes.size);
        userData__typed->delegate.ExecuteIfBound(
          result__instance,
          std::move(accessToken__string),
          std::move(refreshToken__string),
          static_cast<EDiscordAuthorizationTokenType>(tokenType),
          expiresIn,
          std::move(scopes__string));
        Discord_Free(scopes.ptr);
        Discord_Free(refreshToken.ptr);
        Discord_Free(accessToken.ptr);
    };
    Discord_Client_GetToken(&instance,
                            applicationId,
                            code__span,
                            codeVerifier__span,
                            redirectUri__span,
                            callback__native,
                            &Tcallback__UserData::Free,
                            callback__userData);
#endif
}
void UDiscordClient::GetToken(FDiscordUniqueID applicationId,
                              FString const& code,
                              FString const& codeVerifier,
                              FString const& redirectUri,
                              FDiscordClientTokenExchangeCallbackDynamic const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - Client::GetToken cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String code__span;
    FTCHARToUTF8 code__convert(*code);
    code__span.ptr = (uint8*)code__convert.Get();
    code__span.size = code__convert.Length();
    Discord_String codeVerifier__span;
    FTCHARToUTF8 codeVerifier__convert(*codeVerifier);
    codeVerifier__span.ptr = (uint8*)codeVerifier__convert.Get();
    codeVerifier__span.size = codeVerifier__convert.Length();
    Discord_String redirectUri__span;
    FTCHARToUTF8 redirectUri__convert(*redirectUri);
    redirectUri__span.ptr = (uint8*)redirectUri__convert.Get();
    redirectUri__span.size = redirectUri__convert.Length();
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_TokenExchangeCallback callback__native = [](auto result,
                                                               auto accessToken,
                                                               auto refreshToken,
                                                               auto tokenType,
                                                               auto expiresIn,
                                                               auto scopes,
                                                               void* userData__) {
        auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        FString accessToken__string;
        accessToken__string.AppendChars(DISCORD_CHAR_CAST(accessToken.ptr), accessToken.size);
        FString refreshToken__string;
        refreshToken__string.AppendChars(DISCORD_CHAR_CAST(refreshToken.ptr), refreshToken.size);
        FString scopes__string;
        scopes__string.AppendChars(DISCORD_CHAR_CAST(scopes.ptr), scopes.size);
        userData__typed->delegate.ExecuteIfBound(
          result__instance,
          std::move(accessToken__string),
          std::move(refreshToken__string),
          static_cast<EDiscordAuthorizationTokenType>(tokenType),
          expiresIn,
          std::move(scopes__string));
        Discord_Free(scopes.ptr);
        Discord_Free(refreshToken.ptr);
        Discord_Free(accessToken.ptr);
    };
    Discord_Client_GetToken(&instance,
                            applicationId,
                            code__span,
                            codeVerifier__span,
                            redirectUri__span,
                            callback__native,
                            &Tcallback__UserData::Free,
                            callback__userData);
#endif
}
void UDiscordClient::GetTokenFromDevice(UDiscordDeviceAuthorizationArgs* args,
                                        FDiscordClientTokenExchangeCallback const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Client::GetTokenFromDevice cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_DeviceAuthorizationArgs* args__instance = args ? &args->instance : nullptr;
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_TokenExchangeCallback callback__native = [](auto result,
                                                               auto accessToken,
                                                               auto refreshToken,
                                                               auto tokenType,
                                                               auto expiresIn,
                                                               auto scopes,
                                                               void* userData__) {
        auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        FString accessToken__string;
        accessToken__string.AppendChars(DISCORD_CHAR_CAST(accessToken.ptr), accessToken.size);
        FString refreshToken__string;
        refreshToken__string.AppendChars(DISCORD_CHAR_CAST(refreshToken.ptr), refreshToken.size);
        FString scopes__string;
        scopes__string.AppendChars(DISCORD_CHAR_CAST(scopes.ptr), scopes.size);
        userData__typed->delegate.ExecuteIfBound(
          result__instance,
          std::move(accessToken__string),
          std::move(refreshToken__string),
          static_cast<EDiscordAuthorizationTokenType>(tokenType),
          expiresIn,
          std::move(scopes__string));
        Discord_Free(scopes.ptr);
        Discord_Free(refreshToken.ptr);
        Discord_Free(accessToken.ptr);
    };
    Discord_Client_GetTokenFromDevice(
      &instance, args__instance, callback__native, &Tcallback__UserData::Free, callback__userData);
#endif
}
void UDiscordClient::GetTokenFromDevice(UDiscordDeviceAuthorizationArgs* args,
                                        FDiscordClientTokenExchangeCallbackDynamic const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Client::GetTokenFromDevice cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_DeviceAuthorizationArgs* args__instance = args ? &args->instance : nullptr;
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_TokenExchangeCallback callback__native = [](auto result,
                                                               auto accessToken,
                                                               auto refreshToken,
                                                               auto tokenType,
                                                               auto expiresIn,
                                                               auto scopes,
                                                               void* userData__) {
        auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        FString accessToken__string;
        accessToken__string.AppendChars(DISCORD_CHAR_CAST(accessToken.ptr), accessToken.size);
        FString refreshToken__string;
        refreshToken__string.AppendChars(DISCORD_CHAR_CAST(refreshToken.ptr), refreshToken.size);
        FString scopes__string;
        scopes__string.AppendChars(DISCORD_CHAR_CAST(scopes.ptr), scopes.size);
        userData__typed->delegate.ExecuteIfBound(
          result__instance,
          std::move(accessToken__string),
          std::move(refreshToken__string),
          static_cast<EDiscordAuthorizationTokenType>(tokenType),
          expiresIn,
          std::move(scopes__string));
        Discord_Free(scopes.ptr);
        Discord_Free(refreshToken.ptr);
        Discord_Free(accessToken.ptr);
    };
    Discord_Client_GetTokenFromDevice(
      &instance, args__instance, callback__native, &Tcallback__UserData::Free, callback__userData);
#endif
}
void UDiscordClient::GetTokenFromDeviceProvisionalMerge(
  UDiscordDeviceAuthorizationArgs* args,
  EDiscordAuthenticationExternalAuthType externalAuthType,
  FString const& externalAuthToken,
  FDiscordClientTokenExchangeCallback const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::GetTokenFromDeviceProvisionalMerge "
                "cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_DeviceAuthorizationArgs* args__instance = args ? &args->instance : nullptr;
    Discord_String externalAuthToken__span;
    FTCHARToUTF8 externalAuthToken__convert(*externalAuthToken);
    externalAuthToken__span.ptr = (uint8*)externalAuthToken__convert.Get();
    externalAuthToken__span.size = externalAuthToken__convert.Length();
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_TokenExchangeCallback callback__native = [](auto result,
                                                               auto accessToken,
                                                               auto refreshToken,
                                                               auto tokenType,
                                                               auto expiresIn,
                                                               auto scopes,
                                                               void* userData__) {
        auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        FString accessToken__string;
        accessToken__string.AppendChars(DISCORD_CHAR_CAST(accessToken.ptr), accessToken.size);
        FString refreshToken__string;
        refreshToken__string.AppendChars(DISCORD_CHAR_CAST(refreshToken.ptr), refreshToken.size);
        FString scopes__string;
        scopes__string.AppendChars(DISCORD_CHAR_CAST(scopes.ptr), scopes.size);
        userData__typed->delegate.ExecuteIfBound(
          result__instance,
          std::move(accessToken__string),
          std::move(refreshToken__string),
          static_cast<EDiscordAuthorizationTokenType>(tokenType),
          expiresIn,
          std::move(scopes__string));
        Discord_Free(scopes.ptr);
        Discord_Free(refreshToken.ptr);
        Discord_Free(accessToken.ptr);
    };
    Discord_Client_GetTokenFromDeviceProvisionalMerge(
      &instance,
      args__instance,
      static_cast<Discord_AuthenticationExternalAuthType>(externalAuthType),
      externalAuthToken__span,
      callback__native,
      &Tcallback__UserData::Free,
      callback__userData);
#endif
}
void UDiscordClient::GetTokenFromDeviceProvisionalMerge(
  UDiscordDeviceAuthorizationArgs* args,
  EDiscordAuthenticationExternalAuthType externalAuthType,
  FString const& externalAuthToken,
  FDiscordClientTokenExchangeCallbackDynamic const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::GetTokenFromDeviceProvisionalMerge "
                "cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_DeviceAuthorizationArgs* args__instance = args ? &args->instance : nullptr;
    Discord_String externalAuthToken__span;
    FTCHARToUTF8 externalAuthToken__convert(*externalAuthToken);
    externalAuthToken__span.ptr = (uint8*)externalAuthToken__convert.Get();
    externalAuthToken__span.size = externalAuthToken__convert.Length();
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_TokenExchangeCallback callback__native = [](auto result,
                                                               auto accessToken,
                                                               auto refreshToken,
                                                               auto tokenType,
                                                               auto expiresIn,
                                                               auto scopes,
                                                               void* userData__) {
        auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        FString accessToken__string;
        accessToken__string.AppendChars(DISCORD_CHAR_CAST(accessToken.ptr), accessToken.size);
        FString refreshToken__string;
        refreshToken__string.AppendChars(DISCORD_CHAR_CAST(refreshToken.ptr), refreshToken.size);
        FString scopes__string;
        scopes__string.AppendChars(DISCORD_CHAR_CAST(scopes.ptr), scopes.size);
        userData__typed->delegate.ExecuteIfBound(
          result__instance,
          std::move(accessToken__string),
          std::move(refreshToken__string),
          static_cast<EDiscordAuthorizationTokenType>(tokenType),
          expiresIn,
          std::move(scopes__string));
        Discord_Free(scopes.ptr);
        Discord_Free(refreshToken.ptr);
        Discord_Free(accessToken.ptr);
    };
    Discord_Client_GetTokenFromDeviceProvisionalMerge(
      &instance,
      args__instance,
      static_cast<Discord_AuthenticationExternalAuthType>(externalAuthType),
      externalAuthToken__span,
      callback__native,
      &Tcallback__UserData::Free,
      callback__userData);
#endif
}
void UDiscordClient::GetTokenFromProvisionalMerge(
  FDiscordUniqueID applicationId,
  FString const& code,
  FString const& codeVerifier,
  FString const& redirectUri,
  EDiscordAuthenticationExternalAuthType externalAuthType,
  FString const& externalAuthToken,
  FDiscordClientTokenExchangeCallback const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::GetTokenFromProvisionalMerge cannot "
                "be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String code__span;
    FTCHARToUTF8 code__convert(*code);
    code__span.ptr = (uint8*)code__convert.Get();
    code__span.size = code__convert.Length();
    Discord_String codeVerifier__span;
    FTCHARToUTF8 codeVerifier__convert(*codeVerifier);
    codeVerifier__span.ptr = (uint8*)codeVerifier__convert.Get();
    codeVerifier__span.size = codeVerifier__convert.Length();
    Discord_String redirectUri__span;
    FTCHARToUTF8 redirectUri__convert(*redirectUri);
    redirectUri__span.ptr = (uint8*)redirectUri__convert.Get();
    redirectUri__span.size = redirectUri__convert.Length();
    Discord_String externalAuthToken__span;
    FTCHARToUTF8 externalAuthToken__convert(*externalAuthToken);
    externalAuthToken__span.ptr = (uint8*)externalAuthToken__convert.Get();
    externalAuthToken__span.size = externalAuthToken__convert.Length();
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_TokenExchangeCallback callback__native = [](auto result,
                                                               auto accessToken,
                                                               auto refreshToken,
                                                               auto tokenType,
                                                               auto expiresIn,
                                                               auto scopes,
                                                               void* userData__) {
        auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        FString accessToken__string;
        accessToken__string.AppendChars(DISCORD_CHAR_CAST(accessToken.ptr), accessToken.size);
        FString refreshToken__string;
        refreshToken__string.AppendChars(DISCORD_CHAR_CAST(refreshToken.ptr), refreshToken.size);
        FString scopes__string;
        scopes__string.AppendChars(DISCORD_CHAR_CAST(scopes.ptr), scopes.size);
        userData__typed->delegate.ExecuteIfBound(
          result__instance,
          std::move(accessToken__string),
          std::move(refreshToken__string),
          static_cast<EDiscordAuthorizationTokenType>(tokenType),
          expiresIn,
          std::move(scopes__string));
        Discord_Free(scopes.ptr);
        Discord_Free(refreshToken.ptr);
        Discord_Free(accessToken.ptr);
    };
    Discord_Client_GetTokenFromProvisionalMerge(
      &instance,
      applicationId,
      code__span,
      codeVerifier__span,
      redirectUri__span,
      static_cast<Discord_AuthenticationExternalAuthType>(externalAuthType),
      externalAuthToken__span,
      callback__native,
      &Tcallback__UserData::Free,
      callback__userData);
#endif
}
void UDiscordClient::GetTokenFromProvisionalMerge(
  FDiscordUniqueID applicationId,
  FString const& code,
  FString const& codeVerifier,
  FString const& redirectUri,
  EDiscordAuthenticationExternalAuthType externalAuthType,
  FString const& externalAuthToken,
  FDiscordClientTokenExchangeCallbackDynamic const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::GetTokenFromProvisionalMerge cannot "
                "be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String code__span;
    FTCHARToUTF8 code__convert(*code);
    code__span.ptr = (uint8*)code__convert.Get();
    code__span.size = code__convert.Length();
    Discord_String codeVerifier__span;
    FTCHARToUTF8 codeVerifier__convert(*codeVerifier);
    codeVerifier__span.ptr = (uint8*)codeVerifier__convert.Get();
    codeVerifier__span.size = codeVerifier__convert.Length();
    Discord_String redirectUri__span;
    FTCHARToUTF8 redirectUri__convert(*redirectUri);
    redirectUri__span.ptr = (uint8*)redirectUri__convert.Get();
    redirectUri__span.size = redirectUri__convert.Length();
    Discord_String externalAuthToken__span;
    FTCHARToUTF8 externalAuthToken__convert(*externalAuthToken);
    externalAuthToken__span.ptr = (uint8*)externalAuthToken__convert.Get();
    externalAuthToken__span.size = externalAuthToken__convert.Length();
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_TokenExchangeCallback callback__native = [](auto result,
                                                               auto accessToken,
                                                               auto refreshToken,
                                                               auto tokenType,
                                                               auto expiresIn,
                                                               auto scopes,
                                                               void* userData__) {
        auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        FString accessToken__string;
        accessToken__string.AppendChars(DISCORD_CHAR_CAST(accessToken.ptr), accessToken.size);
        FString refreshToken__string;
        refreshToken__string.AppendChars(DISCORD_CHAR_CAST(refreshToken.ptr), refreshToken.size);
        FString scopes__string;
        scopes__string.AppendChars(DISCORD_CHAR_CAST(scopes.ptr), scopes.size);
        userData__typed->delegate.ExecuteIfBound(
          result__instance,
          std::move(accessToken__string),
          std::move(refreshToken__string),
          static_cast<EDiscordAuthorizationTokenType>(tokenType),
          expiresIn,
          std::move(scopes__string));
        Discord_Free(scopes.ptr);
        Discord_Free(refreshToken.ptr);
        Discord_Free(accessToken.ptr);
    };
    Discord_Client_GetTokenFromProvisionalMerge(
      &instance,
      applicationId,
      code__span,
      codeVerifier__span,
      redirectUri__span,
      static_cast<Discord_AuthenticationExternalAuthType>(externalAuthType),
      externalAuthToken__span,
      callback__native,
      &Tcallback__UserData::Free,
      callback__userData);
#endif
}
bool UDiscordClient::IsAuthenticated()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::IsAuthenticated cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool returnValue__;
    returnValue__ = Discord_Client_IsAuthenticated(&instance);
    return returnValue__;
#endif
}
void UDiscordClient::OpenAuthorizeDeviceScreen(FDiscordUniqueID clientId, FString const& userCode)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Client::OpenAuthorizeDeviceScreen cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String userCode__span;
    FTCHARToUTF8 userCode__convert(*userCode);
    userCode__span.ptr = (uint8*)userCode__convert.Get();
    userCode__span.size = userCode__convert.Length();
    Discord_Client_OpenAuthorizeDeviceScreen(&instance, clientId, userCode__span);
#endif
}
void UDiscordClient::ProvisionalUserMergeCompleted(bool success)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::ProvisionalUserMergeCompleted cannot "
                "be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_Client_ProvisionalUserMergeCompleted(&instance, success);
#endif
}
void UDiscordClient::RefreshToken(FDiscordUniqueID applicationId,
                                  FString const& refreshToken,
                                  FDiscordClientTokenExchangeCallback const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::RefreshToken cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String refreshToken__span;
    FTCHARToUTF8 refreshToken__convert(*refreshToken);
    refreshToken__span.ptr = (uint8*)refreshToken__convert.Get();
    refreshToken__span.size = refreshToken__convert.Length();
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_TokenExchangeCallback callback__native = [](auto result,
                                                               auto accessToken,
                                                               auto refreshToken,
                                                               auto tokenType,
                                                               auto expiresIn,
                                                               auto scopes,
                                                               void* userData__) {
        auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        FString accessToken__string;
        accessToken__string.AppendChars(DISCORD_CHAR_CAST(accessToken.ptr), accessToken.size);
        FString refreshToken__string;
        refreshToken__string.AppendChars(DISCORD_CHAR_CAST(refreshToken.ptr), refreshToken.size);
        FString scopes__string;
        scopes__string.AppendChars(DISCORD_CHAR_CAST(scopes.ptr), scopes.size);
        userData__typed->delegate.ExecuteIfBound(
          result__instance,
          std::move(accessToken__string),
          std::move(refreshToken__string),
          static_cast<EDiscordAuthorizationTokenType>(tokenType),
          expiresIn,
          std::move(scopes__string));
        Discord_Free(scopes.ptr);
        Discord_Free(refreshToken.ptr);
        Discord_Free(accessToken.ptr);
    };
    Discord_Client_RefreshToken(&instance,
                                applicationId,
                                refreshToken__span,
                                callback__native,
                                &Tcallback__UserData::Free,
                                callback__userData);
#endif
}
void UDiscordClient::RefreshToken(FDiscordUniqueID applicationId,
                                  FString const& refreshToken,
                                  FDiscordClientTokenExchangeCallbackDynamic const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::RefreshToken cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String refreshToken__span;
    FTCHARToUTF8 refreshToken__convert(*refreshToken);
    refreshToken__span.ptr = (uint8*)refreshToken__convert.Get();
    refreshToken__span.size = refreshToken__convert.Length();
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_TokenExchangeCallback callback__native = [](auto result,
                                                               auto accessToken,
                                                               auto refreshToken,
                                                               auto tokenType,
                                                               auto expiresIn,
                                                               auto scopes,
                                                               void* userData__) {
        auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        FString accessToken__string;
        accessToken__string.AppendChars(DISCORD_CHAR_CAST(accessToken.ptr), accessToken.size);
        FString refreshToken__string;
        refreshToken__string.AppendChars(DISCORD_CHAR_CAST(refreshToken.ptr), refreshToken.size);
        FString scopes__string;
        scopes__string.AppendChars(DISCORD_CHAR_CAST(scopes.ptr), scopes.size);
        userData__typed->delegate.ExecuteIfBound(
          result__instance,
          std::move(accessToken__string),
          std::move(refreshToken__string),
          static_cast<EDiscordAuthorizationTokenType>(tokenType),
          expiresIn,
          std::move(scopes__string));
        Discord_Free(scopes.ptr);
        Discord_Free(refreshToken.ptr);
        Discord_Free(accessToken.ptr);
    };
    Discord_Client_RefreshToken(&instance,
                                applicationId,
                                refreshToken__span,
                                callback__native,
                                &Tcallback__UserData::Free,
                                callback__userData);
#endif
}
void UDiscordClient::RegisterAuthorizeRequestCallback(
  FDiscordClientAuthorizeRequestCallback const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::RegisterAuthorizeRequestCallback "
                "cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_AuthorizeRequestCallback callback__native = [](void* userData__) {
        auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
        userData__typed->delegate.ExecuteIfBound();
    };
    Discord_Client_RegisterAuthorizeRequestCallback(
      &instance, callback__native, &Tcallback__UserData::Free, callback__userData);
#endif
}
void UDiscordClient::RegisterAuthorizeRequestCallback(
  FDiscordClientAuthorizeRequestCallbackDynamic const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::RegisterAuthorizeRequestCallback "
                "cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_AuthorizeRequestCallback callback__native = [](void* userData__) {
        auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
        userData__typed->delegate.ExecuteIfBound();
    };
    Discord_Client_RegisterAuthorizeRequestCallback(
      &instance, callback__native, &Tcallback__UserData::Free, callback__userData);
#endif
}
void UDiscordClient::RemoveAuthorizeRequestCallback()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::RemoveAuthorizeRequestCallback "
                "cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_Client_RemoveAuthorizeRequestCallback(&instance);
#endif
}
void UDiscordClient::RevokeToken(FDiscordUniqueID applicationId,
                                 FString const& token,
                                 FDiscordClientRevokeTokenCallback const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::RevokeToken cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String token__span;
    FTCHARToUTF8 token__convert(*token);
    token__span.ptr = (uint8*)token__convert.Get();
    token__span.size = token__convert.Length();
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_RevokeTokenCallback callback__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_RevokeToken(&instance,
                               applicationId,
                               token__span,
                               callback__native,
                               &Tcallback__UserData::Free,
                               callback__userData);
#endif
}
void UDiscordClient::RevokeToken(FDiscordUniqueID applicationId,
                                 FString const& token,
                                 FDiscordClientRevokeTokenCallbackDynamic const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::RevokeToken cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String token__span;
    FTCHARToUTF8 token__convert(*token);
    token__span.ptr = (uint8*)token__convert.Get();
    token__span.size = token__convert.Length();
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_RevokeTokenCallback callback__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_RevokeToken(&instance,
                               applicationId,
                               token__span,
                               callback__native,
                               &Tcallback__UserData::Free,
                               callback__userData);
#endif
}
void UDiscordClient::SetAuthorizeDeviceScreenClosedCallback(
  FDiscordClientAuthorizeDeviceScreenClosedCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - "
                "Client::SetAuthorizeDeviceScreenClosedCallback cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_AuthorizeDeviceScreenClosedCallback cb__native = [](void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        userData__typed->delegate.ExecuteIfBound();
    };
    Discord_Client_SetAuthorizeDeviceScreenClosedCallback(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SetAuthorizeDeviceScreenClosedCallback(
  FDiscordClientAuthorizeDeviceScreenClosedCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - "
                "Client::SetAuthorizeDeviceScreenClosedCallback cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_AuthorizeDeviceScreenClosedCallback cb__native = [](void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        userData__typed->delegate.ExecuteIfBound();
    };
    Discord_Client_SetAuthorizeDeviceScreenClosedCallback(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SetGameWindowPid(int32 pid)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::SetGameWindowPid cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_Client_SetGameWindowPid(&instance, pid);
#endif
}
void UDiscordClient::SetTokenExpirationCallback(
  FDiscordClientTokenExpirationCallback const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::SetTokenExpirationCallback cannot be "
                "called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_TokenExpirationCallback callback__native = [](void* userData__) {
        auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
        userData__typed->delegate.ExecuteIfBound();
    };
    Discord_Client_SetTokenExpirationCallback(
      &instance, callback__native, &Tcallback__UserData::Free, callback__userData);
#endif
}
void UDiscordClient::SetTokenExpirationCallback(
  FDiscordClientTokenExpirationCallbackDynamic const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::SetTokenExpirationCallback cannot be "
                "called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_TokenExpirationCallback callback__native = [](void* userData__) {
        auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
        userData__typed->delegate.ExecuteIfBound();
    };
    Discord_Client_SetTokenExpirationCallback(
      &instance, callback__native, &Tcallback__UserData::Free, callback__userData);
#endif
}
void UDiscordClient::UnmergeIntoProvisionalAccount(
  FDiscordUniqueID applicationId,
  EDiscordAuthenticationExternalAuthType externalAuthType,
  FString const& externalAuthToken,
  FDiscordClientUnmergeIntoProvisionalAccountCallback const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::UnmergeIntoProvisionalAccount cannot "
                "be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String externalAuthToken__span;
    FTCHARToUTF8 externalAuthToken__convert(*externalAuthToken);
    externalAuthToken__span.ptr = (uint8*)externalAuthToken__convert.Get();
    externalAuthToken__span.size = externalAuthToken__convert.Length();
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_UnmergeIntoProvisionalAccountCallback callback__native = [](auto result,
                                                                               void* userData__) {
        auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_UnmergeIntoProvisionalAccount(
      &instance,
      applicationId,
      static_cast<Discord_AuthenticationExternalAuthType>(externalAuthType),
      externalAuthToken__span,
      callback__native,
      &Tcallback__UserData::Free,
      callback__userData);
#endif
}
void UDiscordClient::UnmergeIntoProvisionalAccount(
  FDiscordUniqueID applicationId,
  EDiscordAuthenticationExternalAuthType externalAuthType,
  FString const& externalAuthToken,
  FDiscordClientUnmergeIntoProvisionalAccountCallbackDynamic const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::UnmergeIntoProvisionalAccount cannot "
                "be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String externalAuthToken__span;
    FTCHARToUTF8 externalAuthToken__convert(*externalAuthToken);
    externalAuthToken__span.ptr = (uint8*)externalAuthToken__convert.Get();
    externalAuthToken__span.size = externalAuthToken__convert.Length();
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_UnmergeIntoProvisionalAccountCallback callback__native = [](auto result,
                                                                               void* userData__) {
        auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_UnmergeIntoProvisionalAccount(
      &instance,
      applicationId,
      static_cast<Discord_AuthenticationExternalAuthType>(externalAuthType),
      externalAuthToken__span,
      callback__native,
      &Tcallback__UserData::Free,
      callback__userData);
#endif
}
void UDiscordClient::UpdateProvisionalAccountDisplayName(
  FString const& name,
  FDiscordClientUpdateProvisionalAccountDisplayNameCallback const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::UpdateProvisionalAccountDisplayName "
                "cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String name__span;
    FTCHARToUTF8 name__convert(*name);
    name__span.ptr = (uint8*)name__convert.Get();
    name__span.size = name__convert.Length();
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_UpdateProvisionalAccountDisplayNameCallback callback__native =
      [](auto result, void* userData__) {
          auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
          UDiscordClientResult* result__instance = nullptr;
          result__instance = NewObject<UDiscordClientResult>();
          result__instance->instance = *result;
          result__instance->state = DiscordUObjectState::Owned;
          userData__typed->delegate.ExecuteIfBound(result__instance);
      };
    Discord_Client_UpdateProvisionalAccountDisplayName(
      &instance, name__span, callback__native, &Tcallback__UserData::Free, callback__userData);
#endif
}
void UDiscordClient::UpdateProvisionalAccountDisplayName(
  FString const& name,
  FDiscordClientUpdateProvisionalAccountDisplayNameCallbackDynamic const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::UpdateProvisionalAccountDisplayName "
                "cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String name__span;
    FTCHARToUTF8 name__convert(*name);
    name__span.ptr = (uint8*)name__convert.Get();
    name__span.size = name__convert.Length();
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_UpdateProvisionalAccountDisplayNameCallback callback__native =
      [](auto result, void* userData__) {
          auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
          UDiscordClientResult* result__instance = nullptr;
          result__instance = NewObject<UDiscordClientResult>();
          result__instance->instance = *result;
          result__instance->state = DiscordUObjectState::Owned;
          userData__typed->delegate.ExecuteIfBound(result__instance);
      };
    Discord_Client_UpdateProvisionalAccountDisplayName(
      &instance, name__span, callback__native, &Tcallback__UserData::Free, callback__userData);
#endif
}
void UDiscordClient::UpdateToken(EDiscordAuthorizationTokenType tokenType,
                                 FString const& token,
                                 FDiscordClientUpdateTokenCallback const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::UpdateToken cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String token__span;
    FTCHARToUTF8 token__convert(*token);
    token__span.ptr = (uint8*)token__convert.Get();
    token__span.size = token__convert.Length();
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_UpdateTokenCallback callback__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_UpdateToken(&instance,
                               static_cast<Discord_AuthorizationTokenType>(tokenType),
                               token__span,
                               callback__native,
                               &Tcallback__UserData::Free,
                               callback__userData);
#endif
}
void UDiscordClient::UpdateToken(EDiscordAuthorizationTokenType tokenType,
                                 FString const& token,
                                 FDiscordClientUpdateTokenCallbackDynamic const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::UpdateToken cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String token__span;
    FTCHARToUTF8 token__convert(*token);
    token__span.ptr = (uint8*)token__convert.Get();
    token__span.size = token__convert.Length();
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_UpdateTokenCallback callback__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_UpdateToken(&instance,
                               static_cast<Discord_AuthorizationTokenType>(tokenType),
                               token__span,
                               callback__native,
                               &Tcallback__UserData::Free,
                               callback__userData);
#endif
}
bool UDiscordClient::CanOpenMessageInDiscord(FDiscordUniqueID messageId)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Client::CanOpenMessageInDiscord cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool returnValue__;
    returnValue__ = Discord_Client_CanOpenMessageInDiscord(&instance, messageId);
    return returnValue__;
#endif
}
void UDiscordClient::DeleteUserMessage(FDiscordUniqueID recipientId,
                                       FDiscordUniqueID messageId,
                                       FDiscordClientDeleteUserMessageCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::DeleteUserMessage cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_DeleteUserMessageCallback cb__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_DeleteUserMessage(
      &instance, recipientId, messageId, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::DeleteUserMessage(FDiscordUniqueID recipientId,
                                       FDiscordUniqueID messageId,
                                       FDiscordClientDeleteUserMessageCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::DeleteUserMessage cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_DeleteUserMessageCallback cb__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_DeleteUserMessage(
      &instance, recipientId, messageId, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::EditUserMessage(FDiscordUniqueID recipientId,
                                     FDiscordUniqueID messageId,
                                     FString const& content,
                                     FDiscordClientEditUserMessageCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::EditUserMessage cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String content__span;
    FTCHARToUTF8 content__convert(*content);
    content__span.ptr = (uint8*)content__convert.Get();
    content__span.size = content__convert.Length();
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_EditUserMessageCallback cb__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_EditUserMessage(&instance,
                                   recipientId,
                                   messageId,
                                   content__span,
                                   cb__native,
                                   &Tcb__UserData::Free,
                                   cb__userData);
#endif
}
void UDiscordClient::EditUserMessage(FDiscordUniqueID recipientId,
                                     FDiscordUniqueID messageId,
                                     FString const& content,
                                     FDiscordClientEditUserMessageCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::EditUserMessage cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String content__span;
    FTCHARToUTF8 content__convert(*content);
    content__span.ptr = (uint8*)content__convert.Get();
    content__span.size = content__convert.Length();
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_EditUserMessageCallback cb__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_EditUserMessage(&instance,
                                   recipientId,
                                   messageId,
                                   content__span,
                                   cb__native,
                                   &Tcb__UserData::Free,
                                   cb__userData);
#endif
}
UDiscordChannelHandle* UDiscordClient::GetChannelHandle(FDiscordUniqueID channelId)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::GetChannelHandle cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool __returnIsNonNull;
    Discord_ChannelHandle returnValueNative__;
    UDiscordChannelHandle* returnValue__ = nullptr;
    __returnIsNonNull = Discord_Client_GetChannelHandle(&instance, channelId, &returnValueNative__);
    if (!__returnIsNonNull) {
        return {};
    }
    returnValue__ = NewObject<UDiscordChannelHandle>();
    returnValue__->instance = returnValueNative__;
    returnValue__->state = DiscordUObjectState::Owned;
    return returnValue__;
#endif
}
void UDiscordClient::GetLobbyMessagesWithLimit(FDiscordUniqueID lobbyId,
                                               int32 limit,
                                               FDiscordClientGetLobbyMessagesCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Client::GetLobbyMessagesWithLimit cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_GetLobbyMessagesCallback cb__native =
      [](auto result, auto messages, void* userData__) {
          auto userData__typed = static_cast<Tcb__UserData*>(userData__);
          UDiscordClientResult* result__instance = nullptr;
          result__instance = NewObject<UDiscordClientResult>();
          result__instance->instance = *result;
          result__instance->state = DiscordUObjectState::Owned;
          TArray<UDiscordMessageHandle*> messages__array;
          messages__array.Reserve(messages.size);
          for (size_t i__ = 0; i__ < messages.size; ++i__) {
              auto instance__ = NewObject<UDiscordMessageHandle>();
              instance__->instance = messages.ptr[i__];
              instance__->state = DiscordUObjectState::Owned;
              messages__array.Add(instance__);
          }
          Discord_Free(messages.ptr);
          userData__typed->delegate.ExecuteIfBound(result__instance, messages__array);
      };
    Discord_Client_GetLobbyMessagesWithLimit(
      &instance, lobbyId, limit, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::GetLobbyMessagesWithLimit(
  FDiscordUniqueID lobbyId,
  int32 limit,
  FDiscordClientGetLobbyMessagesCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Client::GetLobbyMessagesWithLimit cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_GetLobbyMessagesCallback cb__native =
      [](auto result, auto messages, void* userData__) {
          auto userData__typed = static_cast<Tcb__UserData*>(userData__);
          UDiscordClientResult* result__instance = nullptr;
          result__instance = NewObject<UDiscordClientResult>();
          result__instance->instance = *result;
          result__instance->state = DiscordUObjectState::Owned;
          TArray<UDiscordMessageHandle*> messages__array;
          messages__array.Reserve(messages.size);
          for (size_t i__ = 0; i__ < messages.size; ++i__) {
              auto instance__ = NewObject<UDiscordMessageHandle>();
              instance__->instance = messages.ptr[i__];
              instance__->state = DiscordUObjectState::Owned;
              messages__array.Add(instance__);
          }
          Discord_Free(messages.ptr);
          userData__typed->delegate.ExecuteIfBound(result__instance, messages__array);
      };
    Discord_Client_GetLobbyMessagesWithLimit(
      &instance, lobbyId, limit, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
UDiscordMessageHandle* UDiscordClient::GetMessageHandle(FDiscordUniqueID messageId)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::GetMessageHandle cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool __returnIsNonNull;
    Discord_MessageHandle returnValueNative__;
    UDiscordMessageHandle* returnValue__ = nullptr;
    __returnIsNonNull = Discord_Client_GetMessageHandle(&instance, messageId, &returnValueNative__);
    if (!__returnIsNonNull) {
        return {};
    }
    returnValue__ = NewObject<UDiscordMessageHandle>();
    returnValue__->instance = returnValueNative__;
    returnValue__->state = DiscordUObjectState::Owned;
    return returnValue__;
#endif
}
void UDiscordClient::GetUserMessageSummaries(FDiscordClientUserMessageSummariesCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Client::GetUserMessageSummaries cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_UserMessageSummariesCallback cb__native =
      [](auto result, auto summaries, void* userData__) {
          auto userData__typed = static_cast<Tcb__UserData*>(userData__);
          UDiscordClientResult* result__instance = nullptr;
          result__instance = NewObject<UDiscordClientResult>();
          result__instance->instance = *result;
          result__instance->state = DiscordUObjectState::Owned;
          TArray<UDiscordUserMessageSummary*> summaries__array;
          summaries__array.Reserve(summaries.size);
          for (size_t i__ = 0; i__ < summaries.size; ++i__) {
              auto instance__ = NewObject<UDiscordUserMessageSummary>();
              instance__->instance = summaries.ptr[i__];
              instance__->state = DiscordUObjectState::Owned;
              summaries__array.Add(instance__);
          }
          Discord_Free(summaries.ptr);
          userData__typed->delegate.ExecuteIfBound(result__instance, summaries__array);
      };
    Discord_Client_GetUserMessageSummaries(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::GetUserMessageSummaries(
  FDiscordClientUserMessageSummariesCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Client::GetUserMessageSummaries cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_UserMessageSummariesCallback cb__native =
      [](auto result, auto summaries, void* userData__) {
          auto userData__typed = static_cast<Tcb__UserData*>(userData__);
          UDiscordClientResult* result__instance = nullptr;
          result__instance = NewObject<UDiscordClientResult>();
          result__instance->instance = *result;
          result__instance->state = DiscordUObjectState::Owned;
          TArray<UDiscordUserMessageSummary*> summaries__array;
          summaries__array.Reserve(summaries.size);
          for (size_t i__ = 0; i__ < summaries.size; ++i__) {
              auto instance__ = NewObject<UDiscordUserMessageSummary>();
              instance__->instance = summaries.ptr[i__];
              instance__->state = DiscordUObjectState::Owned;
              summaries__array.Add(instance__);
          }
          Discord_Free(summaries.ptr);
          userData__typed->delegate.ExecuteIfBound(result__instance, summaries__array);
      };
    Discord_Client_GetUserMessageSummaries(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::GetUserMessagesWithLimit(FDiscordUniqueID recipientId,
                                              int32 limit,
                                              FDiscordClientUserMessagesWithLimitCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Client::GetUserMessagesWithLimit cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_UserMessagesWithLimitCallback cb__native =
      [](auto result, auto messages, void* userData__) {
          auto userData__typed = static_cast<Tcb__UserData*>(userData__);
          UDiscordClientResult* result__instance = nullptr;
          result__instance = NewObject<UDiscordClientResult>();
          result__instance->instance = *result;
          result__instance->state = DiscordUObjectState::Owned;
          TArray<UDiscordMessageHandle*> messages__array;
          messages__array.Reserve(messages.size);
          for (size_t i__ = 0; i__ < messages.size; ++i__) {
              auto instance__ = NewObject<UDiscordMessageHandle>();
              instance__->instance = messages.ptr[i__];
              instance__->state = DiscordUObjectState::Owned;
              messages__array.Add(instance__);
          }
          Discord_Free(messages.ptr);
          userData__typed->delegate.ExecuteIfBound(result__instance, messages__array);
      };
    Discord_Client_GetUserMessagesWithLimit(
      &instance, recipientId, limit, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::GetUserMessagesWithLimit(
  FDiscordUniqueID recipientId,
  int32 limit,
  FDiscordClientUserMessagesWithLimitCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Client::GetUserMessagesWithLimit cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_UserMessagesWithLimitCallback cb__native =
      [](auto result, auto messages, void* userData__) {
          auto userData__typed = static_cast<Tcb__UserData*>(userData__);
          UDiscordClientResult* result__instance = nullptr;
          result__instance = NewObject<UDiscordClientResult>();
          result__instance->instance = *result;
          result__instance->state = DiscordUObjectState::Owned;
          TArray<UDiscordMessageHandle*> messages__array;
          messages__array.Reserve(messages.size);
          for (size_t i__ = 0; i__ < messages.size; ++i__) {
              auto instance__ = NewObject<UDiscordMessageHandle>();
              instance__->instance = messages.ptr[i__];
              instance__->state = DiscordUObjectState::Owned;
              messages__array.Add(instance__);
          }
          Discord_Free(messages.ptr);
          userData__typed->delegate.ExecuteIfBound(result__instance, messages__array);
      };
    Discord_Client_GetUserMessagesWithLimit(
      &instance, recipientId, limit, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::OpenMessageInDiscord(
  FDiscordUniqueID messageId,
  FDiscordClientProvisionalUserMergeRequiredCallback const& provisionalUserMergeRequiredCallback,
  FDiscordClientOpenMessageInDiscordCallback const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Client::OpenMessageInDiscord cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using TprovisionalUserMergeRequiredCallback__UserData =
      TDelegateUserData<std::remove_reference_t<decltype(provisionalUserMergeRequiredCallback)>>;
    auto provisionalUserMergeRequiredCallback__userData =
      new TprovisionalUserMergeRequiredCallback__UserData(provisionalUserMergeRequiredCallback);
    Discord_Client_ProvisionalUserMergeRequiredCallback
      provisionalUserMergeRequiredCallback__native = [](void* userData__) {
          auto userData__typed =
            static_cast<TprovisionalUserMergeRequiredCallback__UserData*>(userData__);
          userData__typed->delegate.ExecuteIfBound();
      };
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_OpenMessageInDiscordCallback callback__native = [](auto result,
                                                                      void* userData__) {
        auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_OpenMessageInDiscord(&instance,
                                        messageId,
                                        provisionalUserMergeRequiredCallback__native,
                                        &TprovisionalUserMergeRequiredCallback__UserData::Free,
                                        provisionalUserMergeRequiredCallback__userData,
                                        callback__native,
                                        &Tcallback__UserData::Free,
                                        callback__userData);
#endif
}
void UDiscordClient::OpenMessageInDiscord(
  FDiscordUniqueID messageId,
  FDiscordClientProvisionalUserMergeRequiredCallbackDynamic const&
    provisionalUserMergeRequiredCallback,
  FDiscordClientOpenMessageInDiscordCallbackDynamic const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Client::OpenMessageInDiscord cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using TprovisionalUserMergeRequiredCallback__UserData =
      TDelegateUserData<std::remove_reference_t<decltype(provisionalUserMergeRequiredCallback)>>;
    auto provisionalUserMergeRequiredCallback__userData =
      new TprovisionalUserMergeRequiredCallback__UserData(provisionalUserMergeRequiredCallback);
    Discord_Client_ProvisionalUserMergeRequiredCallback
      provisionalUserMergeRequiredCallback__native = [](void* userData__) {
          auto userData__typed =
            static_cast<TprovisionalUserMergeRequiredCallback__UserData*>(userData__);
          userData__typed->delegate.ExecuteIfBound();
      };
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_OpenMessageInDiscordCallback callback__native = [](auto result,
                                                                      void* userData__) {
        auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_OpenMessageInDiscord(&instance,
                                        messageId,
                                        provisionalUserMergeRequiredCallback__native,
                                        &TprovisionalUserMergeRequiredCallback__UserData::Free,
                                        provisionalUserMergeRequiredCallback__userData,
                                        callback__native,
                                        &Tcallback__UserData::Free,
                                        callback__userData);
#endif
}
void UDiscordClient::SendLobbyMessage(FDiscordUniqueID lobbyId,
                                      FString const& content,
                                      FDiscordClientSendUserMessageCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::SendLobbyMessage cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String content__span;
    FTCHARToUTF8 content__convert(*content);
    content__span.ptr = (uint8*)content__convert.Get();
    content__span.size = content__convert.Length();
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_SendUserMessageCallback cb__native =
      [](auto result, auto messageId, void* userData__) {
          auto userData__typed = static_cast<Tcb__UserData*>(userData__);
          UDiscordClientResult* result__instance = nullptr;
          result__instance = NewObject<UDiscordClientResult>();
          result__instance->instance = *result;
          result__instance->state = DiscordUObjectState::Owned;
          userData__typed->delegate.ExecuteIfBound(result__instance, messageId);
      };
    Discord_Client_SendLobbyMessage(
      &instance, lobbyId, content__span, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SendLobbyMessage(FDiscordUniqueID lobbyId,
                                      FString const& content,
                                      FDiscordClientSendUserMessageCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::SendLobbyMessage cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String content__span;
    FTCHARToUTF8 content__convert(*content);
    content__span.ptr = (uint8*)content__convert.Get();
    content__span.size = content__convert.Length();
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_SendUserMessageCallback cb__native =
      [](auto result, auto messageId, void* userData__) {
          auto userData__typed = static_cast<Tcb__UserData*>(userData__);
          UDiscordClientResult* result__instance = nullptr;
          result__instance = NewObject<UDiscordClientResult>();
          result__instance->instance = *result;
          result__instance->state = DiscordUObjectState::Owned;
          userData__typed->delegate.ExecuteIfBound(result__instance, messageId);
      };
    Discord_Client_SendLobbyMessage(
      &instance, lobbyId, content__span, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SendLobbyMessageWithMetadata(FDiscordUniqueID lobbyId,
                                                  FString const& content,
                                                  TMap<FString, FString> const& metadata,
                                                  FDiscordClientSendUserMessageCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::SendLobbyMessageWithMetadata cannot "
                "be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String content__span;
    FTCHARToUTF8 content__convert(*content);
    content__span.ptr = (uint8*)content__convert.Get();
    content__span.size = content__convert.Length();
    ConvertedProperties metadata__convert(metadata);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_SendUserMessageCallback cb__native =
      [](auto result, auto messageId, void* userData__) {
          auto userData__typed = static_cast<Tcb__UserData*>(userData__);
          UDiscordClientResult* result__instance = nullptr;
          result__instance = NewObject<UDiscordClientResult>();
          result__instance->instance = *result;
          result__instance->state = DiscordUObjectState::Owned;
          userData__typed->delegate.ExecuteIfBound(result__instance, messageId);
      };
    Discord_Client_SendLobbyMessageWithMetadata(&instance,
                                                lobbyId,
                                                content__span,
                                                metadata__convert.Properties,
                                                cb__native,
                                                &Tcb__UserData::Free,
                                                cb__userData);
#endif
}
void UDiscordClient::SendLobbyMessageWithMetadata(
  FDiscordUniqueID lobbyId,
  FString const& content,
  TMap<FString, FString> const& metadata,
  FDiscordClientSendUserMessageCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::SendLobbyMessageWithMetadata cannot "
                "be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String content__span;
    FTCHARToUTF8 content__convert(*content);
    content__span.ptr = (uint8*)content__convert.Get();
    content__span.size = content__convert.Length();
    ConvertedProperties metadata__convert(metadata);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_SendUserMessageCallback cb__native =
      [](auto result, auto messageId, void* userData__) {
          auto userData__typed = static_cast<Tcb__UserData*>(userData__);
          UDiscordClientResult* result__instance = nullptr;
          result__instance = NewObject<UDiscordClientResult>();
          result__instance->instance = *result;
          result__instance->state = DiscordUObjectState::Owned;
          userData__typed->delegate.ExecuteIfBound(result__instance, messageId);
      };
    Discord_Client_SendLobbyMessageWithMetadata(&instance,
                                                lobbyId,
                                                content__span,
                                                metadata__convert.Properties,
                                                cb__native,
                                                &Tcb__UserData::Free,
                                                cb__userData);
#endif
}
void UDiscordClient::SendUserMessage(FDiscordUniqueID recipientId,
                                     FString const& content,
                                     FDiscordClientSendUserMessageCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::SendUserMessage cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String content__span;
    FTCHARToUTF8 content__convert(*content);
    content__span.ptr = (uint8*)content__convert.Get();
    content__span.size = content__convert.Length();
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_SendUserMessageCallback cb__native =
      [](auto result, auto messageId, void* userData__) {
          auto userData__typed = static_cast<Tcb__UserData*>(userData__);
          UDiscordClientResult* result__instance = nullptr;
          result__instance = NewObject<UDiscordClientResult>();
          result__instance->instance = *result;
          result__instance->state = DiscordUObjectState::Owned;
          userData__typed->delegate.ExecuteIfBound(result__instance, messageId);
      };
    Discord_Client_SendUserMessage(
      &instance, recipientId, content__span, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SendUserMessage(FDiscordUniqueID recipientId,
                                     FString const& content,
                                     FDiscordClientSendUserMessageCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::SendUserMessage cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String content__span;
    FTCHARToUTF8 content__convert(*content);
    content__span.ptr = (uint8*)content__convert.Get();
    content__span.size = content__convert.Length();
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_SendUserMessageCallback cb__native =
      [](auto result, auto messageId, void* userData__) {
          auto userData__typed = static_cast<Tcb__UserData*>(userData__);
          UDiscordClientResult* result__instance = nullptr;
          result__instance = NewObject<UDiscordClientResult>();
          result__instance->instance = *result;
          result__instance->state = DiscordUObjectState::Owned;
          userData__typed->delegate.ExecuteIfBound(result__instance, messageId);
      };
    Discord_Client_SendUserMessage(
      &instance, recipientId, content__span, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SendUserMessageWithMetadata(FDiscordUniqueID recipientId,
                                                 FString const& content,
                                                 TMap<FString, FString> const& metadata,
                                                 FDiscordClientSendUserMessageCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::SendUserMessageWithMetadata cannot "
                "be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String content__span;
    FTCHARToUTF8 content__convert(*content);
    content__span.ptr = (uint8*)content__convert.Get();
    content__span.size = content__convert.Length();
    ConvertedProperties metadata__convert(metadata);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_SendUserMessageCallback cb__native =
      [](auto result, auto messageId, void* userData__) {
          auto userData__typed = static_cast<Tcb__UserData*>(userData__);
          UDiscordClientResult* result__instance = nullptr;
          result__instance = NewObject<UDiscordClientResult>();
          result__instance->instance = *result;
          result__instance->state = DiscordUObjectState::Owned;
          userData__typed->delegate.ExecuteIfBound(result__instance, messageId);
      };
    Discord_Client_SendUserMessageWithMetadata(&instance,
                                               recipientId,
                                               content__span,
                                               metadata__convert.Properties,
                                               cb__native,
                                               &Tcb__UserData::Free,
                                               cb__userData);
#endif
}
void UDiscordClient::SendUserMessageWithMetadata(
  FDiscordUniqueID recipientId,
  FString const& content,
  TMap<FString, FString> const& metadata,
  FDiscordClientSendUserMessageCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::SendUserMessageWithMetadata cannot "
                "be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String content__span;
    FTCHARToUTF8 content__convert(*content);
    content__span.ptr = (uint8*)content__convert.Get();
    content__span.size = content__convert.Length();
    ConvertedProperties metadata__convert(metadata);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_SendUserMessageCallback cb__native =
      [](auto result, auto messageId, void* userData__) {
          auto userData__typed = static_cast<Tcb__UserData*>(userData__);
          UDiscordClientResult* result__instance = nullptr;
          result__instance = NewObject<UDiscordClientResult>();
          result__instance->instance = *result;
          result__instance->state = DiscordUObjectState::Owned;
          userData__typed->delegate.ExecuteIfBound(result__instance, messageId);
      };
    Discord_Client_SendUserMessageWithMetadata(&instance,
                                               recipientId,
                                               content__span,
                                               metadata__convert.Properties,
                                               cb__native,
                                               &Tcb__UserData::Free,
                                               cb__userData);
#endif
}
void UDiscordClient::SetMessageCreatedCallback(FDiscordClientMessageCreatedCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Client::SetMessageCreatedCallback cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_MessageCreatedCallback cb__native = [](auto messageId, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        userData__typed->delegate.ExecuteIfBound(messageId);
    };
    Discord_Client_SetMessageCreatedCallback(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SetMessageCreatedCallback(
  FDiscordClientMessageCreatedCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Client::SetMessageCreatedCallback cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_MessageCreatedCallback cb__native = [](auto messageId, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        userData__typed->delegate.ExecuteIfBound(messageId);
    };
    Discord_Client_SetMessageCreatedCallback(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SetMessageDeletedCallback(FDiscordClientMessageDeletedCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Client::SetMessageDeletedCallback cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_MessageDeletedCallback cb__native =
      [](auto messageId, auto channelId, void* userData__) {
          auto userData__typed = static_cast<Tcb__UserData*>(userData__);
          userData__typed->delegate.ExecuteIfBound(messageId, channelId);
      };
    Discord_Client_SetMessageDeletedCallback(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SetMessageDeletedCallback(
  FDiscordClientMessageDeletedCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Client::SetMessageDeletedCallback cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_MessageDeletedCallback cb__native =
      [](auto messageId, auto channelId, void* userData__) {
          auto userData__typed = static_cast<Tcb__UserData*>(userData__);
          userData__typed->delegate.ExecuteIfBound(messageId, channelId);
      };
    Discord_Client_SetMessageDeletedCallback(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SetMessageUpdatedCallback(FDiscordClientMessageUpdatedCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Client::SetMessageUpdatedCallback cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_MessageUpdatedCallback cb__native = [](auto messageId, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        userData__typed->delegate.ExecuteIfBound(messageId);
    };
    Discord_Client_SetMessageUpdatedCallback(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SetMessageUpdatedCallback(
  FDiscordClientMessageUpdatedCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Client::SetMessageUpdatedCallback cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_MessageUpdatedCallback cb__native = [](auto messageId, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        userData__typed->delegate.ExecuteIfBound(messageId);
    };
    Discord_Client_SetMessageUpdatedCallback(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SetShowingChat(bool showingChat)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::SetShowingChat cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_Client_SetShowingChat(&instance, showingChat);
#endif
}
void UDiscordClient::AddLogCallback(FDiscordClientLogCallback const& callback,
                                    EDiscordLoggingSeverity minSeverity)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::AddLogCallback cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_LogCallback callback__native = [](
                                                    auto message, auto severity, void* userData__) {
        auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
        FString message__string;
        message__string.AppendChars(DISCORD_CHAR_CAST(message.ptr), message.size);
        userData__typed->delegate.ExecuteIfBound(std::move(message__string),
                                                 static_cast<EDiscordLoggingSeverity>(severity));
        Discord_Free(message.ptr);
    };
    Discord_Client_AddLogCallback(&instance,
                                  callback__native,
                                  &Tcallback__UserData::Free,
                                  callback__userData,
                                  static_cast<Discord_LoggingSeverity>(minSeverity));
#endif
}
void UDiscordClient::AddLogCallback(FDiscordClientLogCallbackDynamic const& callback,
                                    EDiscordLoggingSeverity minSeverity)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::AddLogCallback cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_LogCallback callback__native = [](
                                                    auto message, auto severity, void* userData__) {
        auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
        FString message__string;
        message__string.AppendChars(DISCORD_CHAR_CAST(message.ptr), message.size);
        userData__typed->delegate.ExecuteIfBound(std::move(message__string),
                                                 static_cast<EDiscordLoggingSeverity>(severity));
        Discord_Free(message.ptr);
    };
    Discord_Client_AddLogCallback(&instance,
                                  callback__native,
                                  &Tcallback__UserData::Free,
                                  callback__userData,
                                  static_cast<Discord_LoggingSeverity>(minSeverity));
#endif
}
void UDiscordClient::AddVoiceLogCallback(FDiscordClientLogCallback const& callback,
                                         EDiscordLoggingSeverity minSeverity)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Client::AddVoiceLogCallback cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_LogCallback callback__native = [](
                                                    auto message, auto severity, void* userData__) {
        auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
        FString message__string;
        message__string.AppendChars(DISCORD_CHAR_CAST(message.ptr), message.size);
        userData__typed->delegate.ExecuteIfBound(std::move(message__string),
                                                 static_cast<EDiscordLoggingSeverity>(severity));
        Discord_Free(message.ptr);
    };
    Discord_Client_AddVoiceLogCallback(&instance,
                                       callback__native,
                                       &Tcallback__UserData::Free,
                                       callback__userData,
                                       static_cast<Discord_LoggingSeverity>(minSeverity));
#endif
}
void UDiscordClient::AddVoiceLogCallback(FDiscordClientLogCallbackDynamic const& callback,
                                         EDiscordLoggingSeverity minSeverity)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Client::AddVoiceLogCallback cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_LogCallback callback__native = [](
                                                    auto message, auto severity, void* userData__) {
        auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
        FString message__string;
        message__string.AppendChars(DISCORD_CHAR_CAST(message.ptr), message.size);
        userData__typed->delegate.ExecuteIfBound(std::move(message__string),
                                                 static_cast<EDiscordLoggingSeverity>(severity));
        Discord_Free(message.ptr);
    };
    Discord_Client_AddVoiceLogCallback(&instance,
                                       callback__native,
                                       &Tcallback__UserData::Free,
                                       callback__userData,
                                       static_cast<Discord_LoggingSeverity>(minSeverity));
#endif
}
void UDiscordClient::Connect()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - Client::Connect cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_Client_Connect(&instance);
#endif
}
void UDiscordClient::Disconnect()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - Client::Disconnect cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_Client_Disconnect(&instance);
#endif
}
EDiscordClientStatus UDiscordClient::GetStatus()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - Client::GetStatus cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_Client_Status returnValue__;
    returnValue__ = Discord_Client_GetStatus(&instance);
    return static_cast<EDiscordClientStatus>(returnValue__);
#endif
}
void UDiscordClient::OpenConnectedGamesSettingsInDiscord(
  FDiscordClientOpenConnectedGamesSettingsInDiscordCallback const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::OpenConnectedGamesSettingsInDiscord "
                "cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_OpenConnectedGamesSettingsInDiscordCallback callback__native =
      [](auto result, void* userData__) {
          auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
          UDiscordClientResult* result__instance = nullptr;
          result__instance = NewObject<UDiscordClientResult>();
          result__instance->instance = *result;
          result__instance->state = DiscordUObjectState::Owned;
          userData__typed->delegate.ExecuteIfBound(result__instance);
      };
    Discord_Client_OpenConnectedGamesSettingsInDiscord(
      &instance, callback__native, &Tcallback__UserData::Free, callback__userData);
#endif
}
void UDiscordClient::OpenConnectedGamesSettingsInDiscord(
  FDiscordClientOpenConnectedGamesSettingsInDiscordCallbackDynamic const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::OpenConnectedGamesSettingsInDiscord "
                "cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_OpenConnectedGamesSettingsInDiscordCallback callback__native =
      [](auto result, void* userData__) {
          auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
          UDiscordClientResult* result__instance = nullptr;
          result__instance = NewObject<UDiscordClientResult>();
          result__instance->instance = *result;
          result__instance->state = DiscordUObjectState::Owned;
          userData__typed->delegate.ExecuteIfBound(result__instance);
      };
    Discord_Client_OpenConnectedGamesSettingsInDiscord(
      &instance, callback__native, &Tcallback__UserData::Free, callback__userData);
#endif
}
void UDiscordClient::SetApplicationId(FDiscordUniqueID applicationId)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::SetApplicationId cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_Client_SetApplicationId(&instance, applicationId);
#endif
}
bool UDiscordClient::SetLogDir(FString const& path, EDiscordLoggingSeverity minSeverity)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - Client::SetLogDir cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool returnValue__;
    Discord_String path__span;
    FTCHARToUTF8 path__convert(*path);
    path__span.ptr = (uint8*)path__convert.Get();
    path__span.size = path__convert.Length();
    returnValue__ = Discord_Client_SetLogDir(
      &instance, path__span, static_cast<Discord_LoggingSeverity>(minSeverity));
    return returnValue__;
#endif
}
void UDiscordClient::SetStatusChangedCallback(FDiscordClientOnStatusChanged const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Client::SetStatusChangedCallback cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_OnStatusChanged cb__native =
      [](auto status, auto error, auto errorDetail, void* userData__) {
          auto userData__typed = static_cast<Tcb__UserData*>(userData__);
          userData__typed->delegate.ExecuteIfBound(static_cast<EDiscordClientStatus>(status),
                                                   static_cast<EDiscordClientError>(error),
                                                   errorDetail);
      };
    Discord_Client_SetStatusChangedCallback(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SetStatusChangedCallback(FDiscordClientOnStatusChangedDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Client::SetStatusChangedCallback cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_OnStatusChanged cb__native =
      [](auto status, auto error, auto errorDetail, void* userData__) {
          auto userData__typed = static_cast<Tcb__UserData*>(userData__);
          userData__typed->delegate.ExecuteIfBound(static_cast<EDiscordClientStatus>(status),
                                                   static_cast<EDiscordClientError>(error),
                                                   errorDetail);
      };
    Discord_Client_SetStatusChangedCallback(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SetVoiceLogDir(FString const& path, EDiscordLoggingSeverity minSeverity)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::SetVoiceLogDir cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String path__span;
    FTCHARToUTF8 path__convert(*path);
    path__span.ptr = (uint8*)path__convert.Get();
    path__span.size = path__convert.Length();
    Discord_Client_SetVoiceLogDir(
      &instance, path__span, static_cast<Discord_LoggingSeverity>(minSeverity));
#endif
}
void UDiscordClient::CreateOrJoinLobby(FString const& secret,
                                       FDiscordClientCreateOrJoinLobbyCallback const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::CreateOrJoinLobby cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String secret__span;
    FTCHARToUTF8 secret__convert(*secret);
    secret__span.ptr = (uint8*)secret__convert.Get();
    secret__span.size = secret__convert.Length();
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_CreateOrJoinLobbyCallback callback__native =
      [](auto result, auto lobbyId, void* userData__) {
          auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
          UDiscordClientResult* result__instance = nullptr;
          result__instance = NewObject<UDiscordClientResult>();
          result__instance->instance = *result;
          result__instance->state = DiscordUObjectState::Owned;
          userData__typed->delegate.ExecuteIfBound(result__instance, lobbyId);
      };
    Discord_Client_CreateOrJoinLobby(
      &instance, secret__span, callback__native, &Tcallback__UserData::Free, callback__userData);
#endif
}
void UDiscordClient::CreateOrJoinLobby(
  FString const& secret,
  FDiscordClientCreateOrJoinLobbyCallbackDynamic const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::CreateOrJoinLobby cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String secret__span;
    FTCHARToUTF8 secret__convert(*secret);
    secret__span.ptr = (uint8*)secret__convert.Get();
    secret__span.size = secret__convert.Length();
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_CreateOrJoinLobbyCallback callback__native =
      [](auto result, auto lobbyId, void* userData__) {
          auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
          UDiscordClientResult* result__instance = nullptr;
          result__instance = NewObject<UDiscordClientResult>();
          result__instance->instance = *result;
          result__instance->state = DiscordUObjectState::Owned;
          userData__typed->delegate.ExecuteIfBound(result__instance, lobbyId);
      };
    Discord_Client_CreateOrJoinLobby(
      &instance, secret__span, callback__native, &Tcallback__UserData::Free, callback__userData);
#endif
}
void UDiscordClient::CreateOrJoinLobbyWithMetadata(
  FString const& secret,
  TMap<FString, FString> const& lobbyMetadata,
  TMap<FString, FString> const& memberMetadata,
  FDiscordClientCreateOrJoinLobbyCallback const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::CreateOrJoinLobbyWithMetadata cannot "
                "be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String secret__span;
    FTCHARToUTF8 secret__convert(*secret);
    secret__span.ptr = (uint8*)secret__convert.Get();
    secret__span.size = secret__convert.Length();
    ConvertedProperties lobbyMetadata__convert(lobbyMetadata);
    ConvertedProperties memberMetadata__convert(memberMetadata);
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_CreateOrJoinLobbyCallback callback__native =
      [](auto result, auto lobbyId, void* userData__) {
          auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
          UDiscordClientResult* result__instance = nullptr;
          result__instance = NewObject<UDiscordClientResult>();
          result__instance->instance = *result;
          result__instance->state = DiscordUObjectState::Owned;
          userData__typed->delegate.ExecuteIfBound(result__instance, lobbyId);
      };
    Discord_Client_CreateOrJoinLobbyWithMetadata(&instance,
                                                 secret__span,
                                                 lobbyMetadata__convert.Properties,
                                                 memberMetadata__convert.Properties,
                                                 callback__native,
                                                 &Tcallback__UserData::Free,
                                                 callback__userData);
#endif
}
void UDiscordClient::CreateOrJoinLobbyWithMetadata(
  FString const& secret,
  TMap<FString, FString> const& lobbyMetadata,
  TMap<FString, FString> const& memberMetadata,
  FDiscordClientCreateOrJoinLobbyCallbackDynamic const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::CreateOrJoinLobbyWithMetadata cannot "
                "be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String secret__span;
    FTCHARToUTF8 secret__convert(*secret);
    secret__span.ptr = (uint8*)secret__convert.Get();
    secret__span.size = secret__convert.Length();
    ConvertedProperties lobbyMetadata__convert(lobbyMetadata);
    ConvertedProperties memberMetadata__convert(memberMetadata);
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_CreateOrJoinLobbyCallback callback__native =
      [](auto result, auto lobbyId, void* userData__) {
          auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
          UDiscordClientResult* result__instance = nullptr;
          result__instance = NewObject<UDiscordClientResult>();
          result__instance->instance = *result;
          result__instance->state = DiscordUObjectState::Owned;
          userData__typed->delegate.ExecuteIfBound(result__instance, lobbyId);
      };
    Discord_Client_CreateOrJoinLobbyWithMetadata(&instance,
                                                 secret__span,
                                                 lobbyMetadata__convert.Properties,
                                                 memberMetadata__convert.Properties,
                                                 callback__native,
                                                 &Tcallback__UserData::Free,
                                                 callback__userData);
#endif
}
void UDiscordClient::GetGuildChannels(FDiscordUniqueID guildId,
                                      FDiscordClientGetGuildChannelsCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::GetGuildChannels cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_GetGuildChannelsCallback cb__native =
      [](auto result, auto guildChannels, void* userData__) {
          auto userData__typed = static_cast<Tcb__UserData*>(userData__);
          UDiscordClientResult* result__instance = nullptr;
          result__instance = NewObject<UDiscordClientResult>();
          result__instance->instance = *result;
          result__instance->state = DiscordUObjectState::Owned;
          TArray<UDiscordGuildChannel*> guildChannels__array;
          guildChannels__array.Reserve(guildChannels.size);
          for (size_t i__ = 0; i__ < guildChannels.size; ++i__) {
              auto instance__ = NewObject<UDiscordGuildChannel>();
              instance__->instance = guildChannels.ptr[i__];
              instance__->state = DiscordUObjectState::Owned;
              guildChannels__array.Add(instance__);
          }
          Discord_Free(guildChannels.ptr);
          userData__typed->delegate.ExecuteIfBound(result__instance, guildChannels__array);
      };
    Discord_Client_GetGuildChannels(
      &instance, guildId, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::GetGuildChannels(FDiscordUniqueID guildId,
                                      FDiscordClientGetGuildChannelsCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::GetGuildChannels cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_GetGuildChannelsCallback cb__native =
      [](auto result, auto guildChannels, void* userData__) {
          auto userData__typed = static_cast<Tcb__UserData*>(userData__);
          UDiscordClientResult* result__instance = nullptr;
          result__instance = NewObject<UDiscordClientResult>();
          result__instance->instance = *result;
          result__instance->state = DiscordUObjectState::Owned;
          TArray<UDiscordGuildChannel*> guildChannels__array;
          guildChannels__array.Reserve(guildChannels.size);
          for (size_t i__ = 0; i__ < guildChannels.size; ++i__) {
              auto instance__ = NewObject<UDiscordGuildChannel>();
              instance__->instance = guildChannels.ptr[i__];
              instance__->state = DiscordUObjectState::Owned;
              guildChannels__array.Add(instance__);
          }
          Discord_Free(guildChannels.ptr);
          userData__typed->delegate.ExecuteIfBound(result__instance, guildChannels__array);
      };
    Discord_Client_GetGuildChannels(
      &instance, guildId, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
UDiscordLobbyHandle* UDiscordClient::GetLobbyHandle(FDiscordUniqueID lobbyId)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::GetLobbyHandle cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool __returnIsNonNull;
    Discord_LobbyHandle returnValueNative__;
    UDiscordLobbyHandle* returnValue__ = nullptr;
    __returnIsNonNull = Discord_Client_GetLobbyHandle(&instance, lobbyId, &returnValueNative__);
    if (!__returnIsNonNull) {
        return {};
    }
    returnValue__ = NewObject<UDiscordLobbyHandle>();
    returnValue__->instance = returnValueNative__;
    returnValue__->state = DiscordUObjectState::Owned;
    return returnValue__;
#endif
}
TArray<FDiscordUniqueID> UDiscordClient::GetLobbyIds()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::GetLobbyIds cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_UInt64Span returnValueNative__;
    Discord_Client_GetLobbyIds(&instance, &returnValueNative__);
    TArray<FDiscordUniqueID> returnValue__;
    returnValue__.Reserve(returnValueNative__.size);
    for (size_t i__ = 0; i__ < returnValueNative__.size; ++i__) {
        returnValue__.Add(FDiscordUniqueID(returnValueNative__.ptr[i__]));
    }
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;
#endif
}
void UDiscordClient::GetUserGuilds(FDiscordClientGetUserGuildsCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::GetUserGuilds cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_GetUserGuildsCallback cb__native =
      [](auto result, auto guilds, void* userData__) {
          auto userData__typed = static_cast<Tcb__UserData*>(userData__);
          UDiscordClientResult* result__instance = nullptr;
          result__instance = NewObject<UDiscordClientResult>();
          result__instance->instance = *result;
          result__instance->state = DiscordUObjectState::Owned;
          TArray<UDiscordGuildMinimal*> guilds__array;
          guilds__array.Reserve(guilds.size);
          for (size_t i__ = 0; i__ < guilds.size; ++i__) {
              auto instance__ = NewObject<UDiscordGuildMinimal>();
              instance__->instance = guilds.ptr[i__];
              instance__->state = DiscordUObjectState::Owned;
              guilds__array.Add(instance__);
          }
          Discord_Free(guilds.ptr);
          userData__typed->delegate.ExecuteIfBound(result__instance, guilds__array);
      };
    Discord_Client_GetUserGuilds(&instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::GetUserGuilds(FDiscordClientGetUserGuildsCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::GetUserGuilds cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_GetUserGuildsCallback cb__native =
      [](auto result, auto guilds, void* userData__) {
          auto userData__typed = static_cast<Tcb__UserData*>(userData__);
          UDiscordClientResult* result__instance = nullptr;
          result__instance = NewObject<UDiscordClientResult>();
          result__instance->instance = *result;
          result__instance->state = DiscordUObjectState::Owned;
          TArray<UDiscordGuildMinimal*> guilds__array;
          guilds__array.Reserve(guilds.size);
          for (size_t i__ = 0; i__ < guilds.size; ++i__) {
              auto instance__ = NewObject<UDiscordGuildMinimal>();
              instance__->instance = guilds.ptr[i__];
              instance__->state = DiscordUObjectState::Owned;
              guilds__array.Add(instance__);
          }
          Discord_Free(guilds.ptr);
          userData__typed->delegate.ExecuteIfBound(result__instance, guilds__array);
      };
    Discord_Client_GetUserGuilds(&instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::JoinLinkedLobbyGuild(
  FDiscordUniqueID lobbyId,
  FDiscordClientProvisionalUserMergeRequiredCallback const& provisionalUserMergeRequiredCallback,
  FDiscordClientJoinLinkedLobbyGuildCallback const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Client::JoinLinkedLobbyGuild cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using TprovisionalUserMergeRequiredCallback__UserData =
      TDelegateUserData<std::remove_reference_t<decltype(provisionalUserMergeRequiredCallback)>>;
    auto provisionalUserMergeRequiredCallback__userData =
      new TprovisionalUserMergeRequiredCallback__UserData(provisionalUserMergeRequiredCallback);
    Discord_Client_ProvisionalUserMergeRequiredCallback
      provisionalUserMergeRequiredCallback__native = [](void* userData__) {
          auto userData__typed =
            static_cast<TprovisionalUserMergeRequiredCallback__UserData*>(userData__);
          userData__typed->delegate.ExecuteIfBound();
      };
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_JoinLinkedLobbyGuildCallback callback__native =
      [](auto result, auto inviteUrl, void* userData__) {
          auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
          UDiscordClientResult* result__instance = nullptr;
          result__instance = NewObject<UDiscordClientResult>();
          result__instance->instance = *result;
          result__instance->state = DiscordUObjectState::Owned;
          FString inviteUrl__string;
          inviteUrl__string.AppendChars(DISCORD_CHAR_CAST(inviteUrl.ptr), inviteUrl.size);
          userData__typed->delegate.ExecuteIfBound(result__instance, std::move(inviteUrl__string));
          Discord_Free(inviteUrl.ptr);
      };
    Discord_Client_JoinLinkedLobbyGuild(&instance,
                                        lobbyId,
                                        provisionalUserMergeRequiredCallback__native,
                                        &TprovisionalUserMergeRequiredCallback__UserData::Free,
                                        provisionalUserMergeRequiredCallback__userData,
                                        callback__native,
                                        &Tcallback__UserData::Free,
                                        callback__userData);
#endif
}
void UDiscordClient::JoinLinkedLobbyGuild(
  FDiscordUniqueID lobbyId,
  FDiscordClientProvisionalUserMergeRequiredCallbackDynamic const&
    provisionalUserMergeRequiredCallback,
  FDiscordClientJoinLinkedLobbyGuildCallbackDynamic const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Client::JoinLinkedLobbyGuild cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using TprovisionalUserMergeRequiredCallback__UserData =
      TDelegateUserData<std::remove_reference_t<decltype(provisionalUserMergeRequiredCallback)>>;
    auto provisionalUserMergeRequiredCallback__userData =
      new TprovisionalUserMergeRequiredCallback__UserData(provisionalUserMergeRequiredCallback);
    Discord_Client_ProvisionalUserMergeRequiredCallback
      provisionalUserMergeRequiredCallback__native = [](void* userData__) {
          auto userData__typed =
            static_cast<TprovisionalUserMergeRequiredCallback__UserData*>(userData__);
          userData__typed->delegate.ExecuteIfBound();
      };
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_JoinLinkedLobbyGuildCallback callback__native =
      [](auto result, auto inviteUrl, void* userData__) {
          auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
          UDiscordClientResult* result__instance = nullptr;
          result__instance = NewObject<UDiscordClientResult>();
          result__instance->instance = *result;
          result__instance->state = DiscordUObjectState::Owned;
          FString inviteUrl__string;
          inviteUrl__string.AppendChars(DISCORD_CHAR_CAST(inviteUrl.ptr), inviteUrl.size);
          userData__typed->delegate.ExecuteIfBound(result__instance, std::move(inviteUrl__string));
          Discord_Free(inviteUrl.ptr);
      };
    Discord_Client_JoinLinkedLobbyGuild(&instance,
                                        lobbyId,
                                        provisionalUserMergeRequiredCallback__native,
                                        &TprovisionalUserMergeRequiredCallback__UserData::Free,
                                        provisionalUserMergeRequiredCallback__userData,
                                        callback__native,
                                        &Tcallback__UserData::Free,
                                        callback__userData);
#endif
}
void UDiscordClient::LeaveLobby(FDiscordUniqueID lobbyId,
                                FDiscordClientLeaveLobbyCallback const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - Client::LeaveLobby cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_LeaveLobbyCallback callback__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_LeaveLobby(
      &instance, lobbyId, callback__native, &Tcallback__UserData::Free, callback__userData);
#endif
}
void UDiscordClient::LeaveLobby(FDiscordUniqueID lobbyId,
                                FDiscordClientLeaveLobbyCallbackDynamic const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - Client::LeaveLobby cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_LeaveLobbyCallback callback__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_LeaveLobby(
      &instance, lobbyId, callback__native, &Tcallback__UserData::Free, callback__userData);
#endif
}
void UDiscordClient::LinkChannelToLobby(FDiscordUniqueID lobbyId,
                                        FDiscordUniqueID channelId,
                                        FDiscordClientLinkOrUnlinkChannelCallback const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Client::LinkChannelToLobby cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_LinkOrUnlinkChannelCallback callback__native = [](auto result,
                                                                     void* userData__) {
        auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_LinkChannelToLobby(&instance,
                                      lobbyId,
                                      channelId,
                                      callback__native,
                                      &Tcallback__UserData::Free,
                                      callback__userData);
#endif
}
void UDiscordClient::LinkChannelToLobby(
  FDiscordUniqueID lobbyId,
  FDiscordUniqueID channelId,
  FDiscordClientLinkOrUnlinkChannelCallbackDynamic const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Client::LinkChannelToLobby cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_LinkOrUnlinkChannelCallback callback__native = [](auto result,
                                                                     void* userData__) {
        auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_LinkChannelToLobby(&instance,
                                      lobbyId,
                                      channelId,
                                      callback__native,
                                      &Tcallback__UserData::Free,
                                      callback__userData);
#endif
}
void UDiscordClient::SetLobbyCreatedCallback(FDiscordClientLobbyCreatedCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Client::SetLobbyCreatedCallback cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_LobbyCreatedCallback cb__native = [](auto lobbyId, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        userData__typed->delegate.ExecuteIfBound(lobbyId);
    };
    Discord_Client_SetLobbyCreatedCallback(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SetLobbyCreatedCallback(FDiscordClientLobbyCreatedCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Client::SetLobbyCreatedCallback cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_LobbyCreatedCallback cb__native = [](auto lobbyId, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        userData__typed->delegate.ExecuteIfBound(lobbyId);
    };
    Discord_Client_SetLobbyCreatedCallback(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SetLobbyDeletedCallback(FDiscordClientLobbyDeletedCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Client::SetLobbyDeletedCallback cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_LobbyDeletedCallback cb__native = [](auto lobbyId, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        userData__typed->delegate.ExecuteIfBound(lobbyId);
    };
    Discord_Client_SetLobbyDeletedCallback(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SetLobbyDeletedCallback(FDiscordClientLobbyDeletedCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Client::SetLobbyDeletedCallback cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_LobbyDeletedCallback cb__native = [](auto lobbyId, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        userData__typed->delegate.ExecuteIfBound(lobbyId);
    };
    Discord_Client_SetLobbyDeletedCallback(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SetLobbyMemberAddedCallback(FDiscordClientLobbyMemberAddedCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::SetLobbyMemberAddedCallback cannot "
                "be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_LobbyMemberAddedCallback cb__native =
      [](auto lobbyId, auto memberId, void* userData__) {
          auto userData__typed = static_cast<Tcb__UserData*>(userData__);
          userData__typed->delegate.ExecuteIfBound(lobbyId, memberId);
      };
    Discord_Client_SetLobbyMemberAddedCallback(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SetLobbyMemberAddedCallback(
  FDiscordClientLobbyMemberAddedCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::SetLobbyMemberAddedCallback cannot "
                "be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_LobbyMemberAddedCallback cb__native =
      [](auto lobbyId, auto memberId, void* userData__) {
          auto userData__typed = static_cast<Tcb__UserData*>(userData__);
          userData__typed->delegate.ExecuteIfBound(lobbyId, memberId);
      };
    Discord_Client_SetLobbyMemberAddedCallback(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SetLobbyMemberRemovedCallback(
  FDiscordClientLobbyMemberRemovedCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::SetLobbyMemberRemovedCallback cannot "
                "be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_LobbyMemberRemovedCallback cb__native =
      [](auto lobbyId, auto memberId, void* userData__) {
          auto userData__typed = static_cast<Tcb__UserData*>(userData__);
          userData__typed->delegate.ExecuteIfBound(lobbyId, memberId);
      };
    Discord_Client_SetLobbyMemberRemovedCallback(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SetLobbyMemberRemovedCallback(
  FDiscordClientLobbyMemberRemovedCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::SetLobbyMemberRemovedCallback cannot "
                "be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_LobbyMemberRemovedCallback cb__native =
      [](auto lobbyId, auto memberId, void* userData__) {
          auto userData__typed = static_cast<Tcb__UserData*>(userData__);
          userData__typed->delegate.ExecuteIfBound(lobbyId, memberId);
      };
    Discord_Client_SetLobbyMemberRemovedCallback(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SetLobbyMemberUpdatedCallback(
  FDiscordClientLobbyMemberUpdatedCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::SetLobbyMemberUpdatedCallback cannot "
                "be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_LobbyMemberUpdatedCallback cb__native =
      [](auto lobbyId, auto memberId, void* userData__) {
          auto userData__typed = static_cast<Tcb__UserData*>(userData__);
          userData__typed->delegate.ExecuteIfBound(lobbyId, memberId);
      };
    Discord_Client_SetLobbyMemberUpdatedCallback(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SetLobbyMemberUpdatedCallback(
  FDiscordClientLobbyMemberUpdatedCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::SetLobbyMemberUpdatedCallback cannot "
                "be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_LobbyMemberUpdatedCallback cb__native =
      [](auto lobbyId, auto memberId, void* userData__) {
          auto userData__typed = static_cast<Tcb__UserData*>(userData__);
          userData__typed->delegate.ExecuteIfBound(lobbyId, memberId);
      };
    Discord_Client_SetLobbyMemberUpdatedCallback(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SetLobbyUpdatedCallback(FDiscordClientLobbyUpdatedCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Client::SetLobbyUpdatedCallback cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_LobbyUpdatedCallback cb__native = [](auto lobbyId, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        userData__typed->delegate.ExecuteIfBound(lobbyId);
    };
    Discord_Client_SetLobbyUpdatedCallback(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SetLobbyUpdatedCallback(FDiscordClientLobbyUpdatedCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Client::SetLobbyUpdatedCallback cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_LobbyUpdatedCallback cb__native = [](auto lobbyId, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        userData__typed->delegate.ExecuteIfBound(lobbyId);
    };
    Discord_Client_SetLobbyUpdatedCallback(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::UnlinkChannelFromLobby(
  FDiscordUniqueID lobbyId,
  FDiscordClientLinkOrUnlinkChannelCallback const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Client::UnlinkChannelFromLobby cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_LinkOrUnlinkChannelCallback callback__native = [](auto result,
                                                                     void* userData__) {
        auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_UnlinkChannelFromLobby(
      &instance, lobbyId, callback__native, &Tcallback__UserData::Free, callback__userData);
#endif
}
void UDiscordClient::UnlinkChannelFromLobby(
  FDiscordUniqueID lobbyId,
  FDiscordClientLinkOrUnlinkChannelCallbackDynamic const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Client::UnlinkChannelFromLobby cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_LinkOrUnlinkChannelCallback callback__native = [](auto result,
                                                                     void* userData__) {
        auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_UnlinkChannelFromLobby(
      &instance, lobbyId, callback__native, &Tcallback__UserData::Free, callback__userData);
#endif
}
void UDiscordClient::IsDiscordAppInstalled(
  FDiscordClientIsDiscordAppInstalledCallback const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Client::IsDiscordAppInstalled cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_IsDiscordAppInstalledCallback callback__native = [](auto installed,
                                                                       void* userData__) {
        auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
        userData__typed->delegate.ExecuteIfBound(installed);
    };
    Discord_Client_IsDiscordAppInstalled(
      &instance, callback__native, &Tcallback__UserData::Free, callback__userData);
#endif
}
void UDiscordClient::IsDiscordAppInstalled(
  FDiscordClientIsDiscordAppInstalledCallbackDynamic const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Client::IsDiscordAppInstalled cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_IsDiscordAppInstalledCallback callback__native = [](auto installed,
                                                                       void* userData__) {
        auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
        userData__typed->delegate.ExecuteIfBound(installed);
    };
    Discord_Client_IsDiscordAppInstalled(
      &instance, callback__native, &Tcallback__UserData::Free, callback__userData);
#endif
}
void UDiscordClient::AcceptActivityInvite(UDiscordActivityInvite* invite,
                                          FDiscordClientAcceptActivityInviteCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Client::AcceptActivityInvite cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_ActivityInvite* invite__instance = invite ? &invite->instance : nullptr;
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_AcceptActivityInviteCallback cb__native =
      [](auto result, auto joinSecret, void* userData__) {
          auto userData__typed = static_cast<Tcb__UserData*>(userData__);
          UDiscordClientResult* result__instance = nullptr;
          result__instance = NewObject<UDiscordClientResult>();
          result__instance->instance = *result;
          result__instance->state = DiscordUObjectState::Owned;
          FString joinSecret__string;
          joinSecret__string.AppendChars(DISCORD_CHAR_CAST(joinSecret.ptr), joinSecret.size);
          userData__typed->delegate.ExecuteIfBound(result__instance, std::move(joinSecret__string));
          Discord_Free(joinSecret.ptr);
      };
    Discord_Client_AcceptActivityInvite(
      &instance, invite__instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::AcceptActivityInvite(
  UDiscordActivityInvite* invite,
  FDiscordClientAcceptActivityInviteCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Client::AcceptActivityInvite cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_ActivityInvite* invite__instance = invite ? &invite->instance : nullptr;
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_AcceptActivityInviteCallback cb__native =
      [](auto result, auto joinSecret, void* userData__) {
          auto userData__typed = static_cast<Tcb__UserData*>(userData__);
          UDiscordClientResult* result__instance = nullptr;
          result__instance = NewObject<UDiscordClientResult>();
          result__instance->instance = *result;
          result__instance->state = DiscordUObjectState::Owned;
          FString joinSecret__string;
          joinSecret__string.AppendChars(DISCORD_CHAR_CAST(joinSecret.ptr), joinSecret.size);
          userData__typed->delegate.ExecuteIfBound(result__instance, std::move(joinSecret__string));
          Discord_Free(joinSecret.ptr);
      };
    Discord_Client_AcceptActivityInvite(
      &instance, invite__instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::ClearRichPresence()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::ClearRichPresence cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_Client_ClearRichPresence(&instance);
#endif
}
bool UDiscordClient::RegisterLaunchCommand(FDiscordUniqueID applicationId, FString const& command)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Client::RegisterLaunchCommand cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool returnValue__;
    Discord_String command__span;
    FTCHARToUTF8 command__convert(*command);
    command__span.ptr = (uint8*)command__convert.Get();
    command__span.size = command__convert.Length();
    returnValue__ = Discord_Client_RegisterLaunchCommand(&instance, applicationId, command__span);
    return returnValue__;
#endif
}
bool UDiscordClient::RegisterLaunchSteamApplication(FDiscordUniqueID applicationId,
                                                    int32 steamAppId)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::RegisterLaunchSteamApplication "
                "cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool returnValue__;
    returnValue__ =
      Discord_Client_RegisterLaunchSteamApplication(&instance, applicationId, steamAppId);
    return returnValue__;
#endif
}
void UDiscordClient::SendActivityInvite(FDiscordUniqueID userId,
                                        FString const& content,
                                        FDiscordClientSendActivityInviteCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Client::SendActivityInvite cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String content__span;
    FTCHARToUTF8 content__convert(*content);
    content__span.ptr = (uint8*)content__convert.Get();
    content__span.size = content__convert.Length();
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_SendActivityInviteCallback cb__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_SendActivityInvite(
      &instance, userId, content__span, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SendActivityInvite(FDiscordUniqueID userId,
                                        FString const& content,
                                        FDiscordClientSendActivityInviteCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Client::SendActivityInvite cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String content__span;
    FTCHARToUTF8 content__convert(*content);
    content__span.ptr = (uint8*)content__convert.Get();
    content__span.size = content__convert.Length();
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_SendActivityInviteCallback cb__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_SendActivityInvite(
      &instance, userId, content__span, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SendActivityJoinRequest(FDiscordUniqueID userId,
                                             FDiscordClientSendActivityInviteCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Client::SendActivityJoinRequest cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_SendActivityInviteCallback cb__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_SendActivityJoinRequest(
      &instance, userId, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SendActivityJoinRequest(
  FDiscordUniqueID userId,
  FDiscordClientSendActivityInviteCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Client::SendActivityJoinRequest cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_SendActivityInviteCallback cb__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_SendActivityJoinRequest(
      &instance, userId, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SendActivityJoinRequestReply(
  UDiscordActivityInvite* invite,
  FDiscordClientSendActivityInviteCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::SendActivityJoinRequestReply cannot "
                "be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_ActivityInvite* invite__instance = invite ? &invite->instance : nullptr;
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_SendActivityInviteCallback cb__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_SendActivityJoinRequestReply(
      &instance, invite__instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SendActivityJoinRequestReply(
  UDiscordActivityInvite* invite,
  FDiscordClientSendActivityInviteCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::SendActivityJoinRequestReply cannot "
                "be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_ActivityInvite* invite__instance = invite ? &invite->instance : nullptr;
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_SendActivityInviteCallback cb__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_SendActivityJoinRequestReply(
      &instance, invite__instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SetActivityInviteCreatedCallback(
  FDiscordClientActivityInviteCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::SetActivityInviteCreatedCallback "
                "cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_ActivityInviteCallback cb__native = [](auto invite, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordActivityInvite* invite__instance = nullptr;
        invite__instance = NewObject<UDiscordActivityInvite>();
        invite__instance->instance = *invite;
        invite__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(invite__instance);
    };
    Discord_Client_SetActivityInviteCreatedCallback(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SetActivityInviteCreatedCallback(
  FDiscordClientActivityInviteCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::SetActivityInviteCreatedCallback "
                "cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_ActivityInviteCallback cb__native = [](auto invite, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordActivityInvite* invite__instance = nullptr;
        invite__instance = NewObject<UDiscordActivityInvite>();
        invite__instance->instance = *invite;
        invite__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(invite__instance);
    };
    Discord_Client_SetActivityInviteCreatedCallback(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SetActivityInviteUpdatedCallback(
  FDiscordClientActivityInviteCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::SetActivityInviteUpdatedCallback "
                "cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_ActivityInviteCallback cb__native = [](auto invite, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordActivityInvite* invite__instance = nullptr;
        invite__instance = NewObject<UDiscordActivityInvite>();
        invite__instance->instance = *invite;
        invite__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(invite__instance);
    };
    Discord_Client_SetActivityInviteUpdatedCallback(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SetActivityInviteUpdatedCallback(
  FDiscordClientActivityInviteCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::SetActivityInviteUpdatedCallback "
                "cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_ActivityInviteCallback cb__native = [](auto invite, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordActivityInvite* invite__instance = nullptr;
        invite__instance = NewObject<UDiscordActivityInvite>();
        invite__instance->instance = *invite;
        invite__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(invite__instance);
    };
    Discord_Client_SetActivityInviteUpdatedCallback(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SetActivityJoinCallback(FDiscordClientActivityJoinCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Client::SetActivityJoinCallback cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_ActivityJoinCallback cb__native = [](auto joinSecret, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        FString joinSecret__string;
        joinSecret__string.AppendChars(DISCORD_CHAR_CAST(joinSecret.ptr), joinSecret.size);
        userData__typed->delegate.ExecuteIfBound(std::move(joinSecret__string));
        Discord_Free(joinSecret.ptr);
    };
    Discord_Client_SetActivityJoinCallback(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SetActivityJoinCallback(FDiscordClientActivityJoinCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Client::SetActivityJoinCallback cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_ActivityJoinCallback cb__native = [](auto joinSecret, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        FString joinSecret__string;
        joinSecret__string.AppendChars(DISCORD_CHAR_CAST(joinSecret.ptr), joinSecret.size);
        userData__typed->delegate.ExecuteIfBound(std::move(joinSecret__string));
        Discord_Free(joinSecret.ptr);
    };
    Discord_Client_SetActivityJoinCallback(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SetActivityJoinWithApplicationCallback(
  FDiscordClientActivityJoinWithApplicationCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - "
                "Client::SetActivityJoinWithApplicationCallback cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_ActivityJoinWithApplicationCallback cb__native =
      [](auto applicationId, auto joinSecret, void* userData__) {
          auto userData__typed = static_cast<Tcb__UserData*>(userData__);
          FString joinSecret__string;
          joinSecret__string.AppendChars(DISCORD_CHAR_CAST(joinSecret.ptr), joinSecret.size);
          userData__typed->delegate.ExecuteIfBound(applicationId, std::move(joinSecret__string));
          Discord_Free(joinSecret.ptr);
      };
    Discord_Client_SetActivityJoinWithApplicationCallback(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SetActivityJoinWithApplicationCallback(
  FDiscordClientActivityJoinWithApplicationCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - "
                "Client::SetActivityJoinWithApplicationCallback cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_ActivityJoinWithApplicationCallback cb__native =
      [](auto applicationId, auto joinSecret, void* userData__) {
          auto userData__typed = static_cast<Tcb__UserData*>(userData__);
          FString joinSecret__string;
          joinSecret__string.AppendChars(DISCORD_CHAR_CAST(joinSecret.ptr), joinSecret.size);
          userData__typed->delegate.ExecuteIfBound(applicationId, std::move(joinSecret__string));
          Discord_Free(joinSecret.ptr);
      };
    Discord_Client_SetActivityJoinWithApplicationCallback(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SetOnlineStatus(EDiscordStatusType status,
                                     FDiscordClientUpdateStatusCallback const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::SetOnlineStatus cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_UpdateStatusCallback callback__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_SetOnlineStatus(&instance,
                                   static_cast<Discord_StatusType>(status),
                                   callback__native,
                                   &Tcallback__UserData::Free,
                                   callback__userData);
#endif
}
void UDiscordClient::SetOnlineStatus(EDiscordStatusType status,
                                     FDiscordClientUpdateStatusCallbackDynamic const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::SetOnlineStatus cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_UpdateStatusCallback callback__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_SetOnlineStatus(&instance,
                                   static_cast<Discord_StatusType>(status),
                                   callback__native,
                                   &Tcallback__UserData::Free,
                                   callback__userData);
#endif
}
void UDiscordClient::UpdateRichPresence(UDiscordActivity* activity,
                                        FDiscordClientUpdateRichPresenceCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Client::UpdateRichPresence cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_Activity* activity__instance = activity ? &activity->instance : nullptr;
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_UpdateRichPresenceCallback cb__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_UpdateRichPresence(
      &instance, activity__instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::UpdateRichPresence(UDiscordActivity* activity,
                                        FDiscordClientUpdateRichPresenceCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Client::UpdateRichPresence cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_Activity* activity__instance = activity ? &activity->instance : nullptr;
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_UpdateRichPresenceCallback cb__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_UpdateRichPresence(
      &instance, activity__instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::AcceptDiscordFriendRequest(FDiscordUniqueID userId,
                                                FDiscordClientUpdateRelationshipCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::AcceptDiscordFriendRequest cannot be "
                "called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_UpdateRelationshipCallback cb__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_AcceptDiscordFriendRequest(
      &instance, userId, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::AcceptDiscordFriendRequest(
  FDiscordUniqueID userId,
  FDiscordClientUpdateRelationshipCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::AcceptDiscordFriendRequest cannot be "
                "called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_UpdateRelationshipCallback cb__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_AcceptDiscordFriendRequest(
      &instance, userId, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::AcceptGameFriendRequest(FDiscordUniqueID userId,
                                             FDiscordClientUpdateRelationshipCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Client::AcceptGameFriendRequest cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_UpdateRelationshipCallback cb__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_AcceptGameFriendRequest(
      &instance, userId, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::AcceptGameFriendRequest(
  FDiscordUniqueID userId,
  FDiscordClientUpdateRelationshipCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Client::AcceptGameFriendRequest cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_UpdateRelationshipCallback cb__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_AcceptGameFriendRequest(
      &instance, userId, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::BlockUser(FDiscordUniqueID userId,
                               FDiscordClientUpdateRelationshipCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - Client::BlockUser cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_UpdateRelationshipCallback cb__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_BlockUser(&instance, userId, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::BlockUser(FDiscordUniqueID userId,
                               FDiscordClientUpdateRelationshipCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - Client::BlockUser cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_UpdateRelationshipCallback cb__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_BlockUser(&instance, userId, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::CancelDiscordFriendRequest(FDiscordUniqueID userId,
                                                FDiscordClientUpdateRelationshipCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::CancelDiscordFriendRequest cannot be "
                "called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_UpdateRelationshipCallback cb__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_CancelDiscordFriendRequest(
      &instance, userId, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::CancelDiscordFriendRequest(
  FDiscordUniqueID userId,
  FDiscordClientUpdateRelationshipCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::CancelDiscordFriendRequest cannot be "
                "called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_UpdateRelationshipCallback cb__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_CancelDiscordFriendRequest(
      &instance, userId, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::CancelGameFriendRequest(FDiscordUniqueID userId,
                                             FDiscordClientUpdateRelationshipCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Client::CancelGameFriendRequest cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_UpdateRelationshipCallback cb__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_CancelGameFriendRequest(
      &instance, userId, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::CancelGameFriendRequest(
  FDiscordUniqueID userId,
  FDiscordClientUpdateRelationshipCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Client::CancelGameFriendRequest cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_UpdateRelationshipCallback cb__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_CancelGameFriendRequest(
      &instance, userId, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
UDiscordRelationshipHandle* UDiscordClient::GetRelationshipHandle(FDiscordUniqueID userId)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Client::GetRelationshipHandle cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_RelationshipHandle returnValueNative__;
    UDiscordRelationshipHandle* returnValue__ = nullptr;
    Discord_Client_GetRelationshipHandle(&instance, userId, &returnValueNative__);
    returnValue__ = NewObject<UDiscordRelationshipHandle>();
    returnValue__->instance = returnValueNative__;
    returnValue__->state = DiscordUObjectState::Owned;
    return returnValue__;
#endif
}
TArray<UDiscordRelationshipHandle*> UDiscordClient::GetRelationships()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::GetRelationships cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_RelationshipHandleSpan returnValueNative__;
    Discord_Client_GetRelationships(&instance, &returnValueNative__);
    TArray<UDiscordRelationshipHandle*> returnValue__;
    returnValue__.Reserve(returnValueNative__.size);
    for (size_t i__ = 0; i__ < returnValueNative__.size; ++i__) {
        auto instance__ = NewObject<UDiscordRelationshipHandle>();
        instance__->instance = returnValueNative__.ptr[i__];
        instance__->state = DiscordUObjectState::Owned;
        returnValue__.Add(instance__);
    }
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;
#endif
}
TArray<UDiscordRelationshipHandle*> UDiscordClient::GetRelationshipsByGroup(
  EDiscordRelationshipGroupType groupType)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Client::GetRelationshipsByGroup cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_RelationshipHandleSpan returnValueNative__;
    Discord_Client_GetRelationshipsByGroup(
      &instance, static_cast<Discord_RelationshipGroupType>(groupType), &returnValueNative__);
    TArray<UDiscordRelationshipHandle*> returnValue__;
    returnValue__.Reserve(returnValueNative__.size);
    for (size_t i__ = 0; i__ < returnValueNative__.size; ++i__) {
        auto instance__ = NewObject<UDiscordRelationshipHandle>();
        instance__->instance = returnValueNative__.ptr[i__];
        instance__->state = DiscordUObjectState::Owned;
        returnValue__.Add(instance__);
    }
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;
#endif
}
void UDiscordClient::RejectDiscordFriendRequest(FDiscordUniqueID userId,
                                                FDiscordClientUpdateRelationshipCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::RejectDiscordFriendRequest cannot be "
                "called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_UpdateRelationshipCallback cb__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_RejectDiscordFriendRequest(
      &instance, userId, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::RejectDiscordFriendRequest(
  FDiscordUniqueID userId,
  FDiscordClientUpdateRelationshipCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::RejectDiscordFriendRequest cannot be "
                "called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_UpdateRelationshipCallback cb__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_RejectDiscordFriendRequest(
      &instance, userId, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::RejectGameFriendRequest(FDiscordUniqueID userId,
                                             FDiscordClientUpdateRelationshipCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Client::RejectGameFriendRequest cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_UpdateRelationshipCallback cb__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_RejectGameFriendRequest(
      &instance, userId, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::RejectGameFriendRequest(
  FDiscordUniqueID userId,
  FDiscordClientUpdateRelationshipCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Client::RejectGameFriendRequest cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_UpdateRelationshipCallback cb__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_RejectGameFriendRequest(
      &instance, userId, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::RemoveDiscordAndGameFriend(FDiscordUniqueID userId,
                                                FDiscordClientUpdateRelationshipCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::RemoveDiscordAndGameFriend cannot be "
                "called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_UpdateRelationshipCallback cb__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_RemoveDiscordAndGameFriend(
      &instance, userId, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::RemoveDiscordAndGameFriend(
  FDiscordUniqueID userId,
  FDiscordClientUpdateRelationshipCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::RemoveDiscordAndGameFriend cannot be "
                "called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_UpdateRelationshipCallback cb__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_RemoveDiscordAndGameFriend(
      &instance, userId, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::RemoveGameFriend(FDiscordUniqueID userId,
                                      FDiscordClientUpdateRelationshipCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::RemoveGameFriend cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_UpdateRelationshipCallback cb__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_RemoveGameFriend(
      &instance, userId, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::RemoveGameFriend(FDiscordUniqueID userId,
                                      FDiscordClientUpdateRelationshipCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::RemoveGameFriend cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_UpdateRelationshipCallback cb__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_RemoveGameFriend(
      &instance, userId, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
TArray<UDiscordUserHandle*> UDiscordClient::SearchFriendsByUsername(FString const& searchStr)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Client::SearchFriendsByUsername cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_UserHandleSpan returnValueNative__;
    Discord_String searchStr__span;
    FTCHARToUTF8 searchStr__convert(*searchStr);
    searchStr__span.ptr = (uint8*)searchStr__convert.Get();
    searchStr__span.size = searchStr__convert.Length();
    Discord_Client_SearchFriendsByUsername(&instance, searchStr__span, &returnValueNative__);
    TArray<UDiscordUserHandle*> returnValue__;
    returnValue__.Reserve(returnValueNative__.size);
    for (size_t i__ = 0; i__ < returnValueNative__.size; ++i__) {
        auto instance__ = NewObject<UDiscordUserHandle>();
        instance__->instance = returnValueNative__.ptr[i__];
        instance__->state = DiscordUObjectState::Owned;
        returnValue__.Add(instance__);
    }
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;
#endif
}
void UDiscordClient::SendDiscordFriendRequest(FString const& username,
                                              FDiscordClientSendFriendRequestCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Client::SendDiscordFriendRequest cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String username__span;
    FTCHARToUTF8 username__convert(*username);
    username__span.ptr = (uint8*)username__convert.Get();
    username__span.size = username__convert.Length();
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_SendFriendRequestCallback cb__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_SendDiscordFriendRequest(
      &instance, username__span, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SendDiscordFriendRequest(
  FString const& username,
  FDiscordClientSendFriendRequestCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Client::SendDiscordFriendRequest cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String username__span;
    FTCHARToUTF8 username__convert(*username);
    username__span.ptr = (uint8*)username__convert.Get();
    username__span.size = username__convert.Length();
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_SendFriendRequestCallback cb__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_SendDiscordFriendRequest(
      &instance, username__span, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SendDiscordFriendRequestById(
  FDiscordUniqueID userId,
  FDiscordClientUpdateRelationshipCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::SendDiscordFriendRequestById cannot "
                "be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_UpdateRelationshipCallback cb__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_SendDiscordFriendRequestById(
      &instance, userId, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SendDiscordFriendRequestById(
  FDiscordUniqueID userId,
  FDiscordClientUpdateRelationshipCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::SendDiscordFriendRequestById cannot "
                "be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_UpdateRelationshipCallback cb__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_SendDiscordFriendRequestById(
      &instance, userId, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SendGameFriendRequest(FString const& username,
                                           FDiscordClientSendFriendRequestCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Client::SendGameFriendRequest cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String username__span;
    FTCHARToUTF8 username__convert(*username);
    username__span.ptr = (uint8*)username__convert.Get();
    username__span.size = username__convert.Length();
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_SendFriendRequestCallback cb__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_SendGameFriendRequest(
      &instance, username__span, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SendGameFriendRequest(FString const& username,
                                           FDiscordClientSendFriendRequestCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Client::SendGameFriendRequest cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_String username__span;
    FTCHARToUTF8 username__convert(*username);
    username__span.ptr = (uint8*)username__convert.Get();
    username__span.size = username__convert.Length();
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_SendFriendRequestCallback cb__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_SendGameFriendRequest(
      &instance, username__span, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SendGameFriendRequestById(FDiscordUniqueID userId,
                                               FDiscordClientUpdateRelationshipCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Client::SendGameFriendRequestById cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_UpdateRelationshipCallback cb__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_SendGameFriendRequestById(
      &instance, userId, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SendGameFriendRequestById(
  FDiscordUniqueID userId,
  FDiscordClientUpdateRelationshipCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - Client::SendGameFriendRequestById cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_UpdateRelationshipCallback cb__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_SendGameFriendRequestById(
      &instance, userId, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SetRelationshipCreatedCallback(
  FDiscordClientRelationshipCreatedCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::SetRelationshipCreatedCallback "
                "cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_RelationshipCreatedCallback cb__native =
      [](auto userId, auto isDiscordRelationshipUpdate, void* userData__) {
          auto userData__typed = static_cast<Tcb__UserData*>(userData__);
          userData__typed->delegate.ExecuteIfBound(userId, isDiscordRelationshipUpdate);
      };
    Discord_Client_SetRelationshipCreatedCallback(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SetRelationshipCreatedCallback(
  FDiscordClientRelationshipCreatedCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::SetRelationshipCreatedCallback "
                "cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_RelationshipCreatedCallback cb__native =
      [](auto userId, auto isDiscordRelationshipUpdate, void* userData__) {
          auto userData__typed = static_cast<Tcb__UserData*>(userData__);
          userData__typed->delegate.ExecuteIfBound(userId, isDiscordRelationshipUpdate);
      };
    Discord_Client_SetRelationshipCreatedCallback(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SetRelationshipDeletedCallback(
  FDiscordClientRelationshipDeletedCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::SetRelationshipDeletedCallback "
                "cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_RelationshipDeletedCallback cb__native =
      [](auto userId, auto isDiscordRelationshipUpdate, void* userData__) {
          auto userData__typed = static_cast<Tcb__UserData*>(userData__);
          userData__typed->delegate.ExecuteIfBound(userId, isDiscordRelationshipUpdate);
      };
    Discord_Client_SetRelationshipDeletedCallback(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SetRelationshipDeletedCallback(
  FDiscordClientRelationshipDeletedCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::SetRelationshipDeletedCallback "
                "cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_RelationshipDeletedCallback cb__native =
      [](auto userId, auto isDiscordRelationshipUpdate, void* userData__) {
          auto userData__typed = static_cast<Tcb__UserData*>(userData__);
          userData__typed->delegate.ExecuteIfBound(userId, isDiscordRelationshipUpdate);
      };
    Discord_Client_SetRelationshipDeletedCallback(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::UnblockUser(FDiscordUniqueID userId,
                                 FDiscordClientUpdateRelationshipCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::UnblockUser cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_UpdateRelationshipCallback cb__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_UnblockUser(&instance, userId, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::UnblockUser(FDiscordUniqueID userId,
                                 FDiscordClientUpdateRelationshipCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::UnblockUser cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_UpdateRelationshipCallback cb__native = [](auto result, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        UDiscordClientResult* result__instance = nullptr;
        result__instance = NewObject<UDiscordClientResult>();
        result__instance->instance = *result;
        result__instance->state = DiscordUObjectState::Owned;
        userData__typed->delegate.ExecuteIfBound(result__instance);
    };
    Discord_Client_UnblockUser(&instance, userId, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
UDiscordUserHandle* UDiscordClient::GetCurrentUserV2()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::GetCurrentUserV2 cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool __returnIsNonNull;
    Discord_UserHandle returnValueNative__;
    UDiscordUserHandle* returnValue__ = nullptr;
    __returnIsNonNull = Discord_Client_GetCurrentUserV2(&instance, &returnValueNative__);
    if (!__returnIsNonNull) {
        return {};
    }
    returnValue__ = NewObject<UDiscordUserHandle>();
    returnValue__->instance = returnValueNative__;
    returnValue__->state = DiscordUObjectState::Owned;
    return returnValue__;
#endif
}
void UDiscordClient::GetDiscordClientConnectedUser(
  FDiscordUniqueID applicationId,
  FDiscordClientGetDiscordClientConnectedUserCallback const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::GetDiscordClientConnectedUser cannot "
                "be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_GetDiscordClientConnectedUserCallback callback__native =
      [](auto result, auto user, void* userData__) {
          auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
          UDiscordClientResult* result__instance = nullptr;
          result__instance = NewObject<UDiscordClientResult>();
          result__instance->instance = *result;
          result__instance->state = DiscordUObjectState::Owned;
          UDiscordUserHandle* user__instance = nullptr;
          if (user) {
              user__instance = NewObject<UDiscordUserHandle>();
              user__instance->instance = *user;
              user__instance->state = DiscordUObjectState::Owned;
              userData__typed->delegate.ExecuteIfBound(result__instance, user__instance);
          }
      };
    Discord_Client_GetDiscordClientConnectedUser(
      &instance, applicationId, callback__native, &Tcallback__UserData::Free, callback__userData);
#endif
}
void UDiscordClient::GetDiscordClientConnectedUser(
  FDiscordUniqueID applicationId,
  FDiscordClientGetDiscordClientConnectedUserCallbackDynamic const& callback)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::GetDiscordClientConnectedUser cannot "
                "be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcallback__UserData = TDelegateUserData<std::remove_reference_t<decltype(callback)>>;
    auto callback__userData = new Tcallback__UserData(callback);
    Discord_Client_GetDiscordClientConnectedUserCallback callback__native =
      [](auto result, auto user, void* userData__) {
          auto userData__typed = static_cast<Tcallback__UserData*>(userData__);
          UDiscordClientResult* result__instance = nullptr;
          result__instance = NewObject<UDiscordClientResult>();
          result__instance->instance = *result;
          result__instance->state = DiscordUObjectState::Owned;
          UDiscordUserHandle* user__instance = nullptr;
          if (user) {
              user__instance = NewObject<UDiscordUserHandle>();
              user__instance->instance = *user;
              user__instance->state = DiscordUObjectState::Owned;
              userData__typed->delegate.ExecuteIfBound(result__instance, user__instance);
          }
      };
    Discord_Client_GetDiscordClientConnectedUser(
      &instance, applicationId, callback__native, &Tcallback__UserData::Free, callback__userData);
#endif
}
UDiscordUserHandle* UDiscordClient::GetUser(FDiscordUniqueID userId)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false, TEXT("Discord Partner SDK is stubbed out - Client::GetUser cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool __returnIsNonNull;
    Discord_UserHandle returnValueNative__;
    UDiscordUserHandle* returnValue__ = nullptr;
    __returnIsNonNull = Discord_Client_GetUser(&instance, userId, &returnValueNative__);
    if (!__returnIsNonNull) {
        return {};
    }
    returnValue__ = NewObject<UDiscordUserHandle>();
    returnValue__->instance = returnValueNative__;
    returnValue__->state = DiscordUObjectState::Owned;
    return returnValue__;
#endif
}
void UDiscordClient::SetRelationshipGroupsUpdatedCallback(
  FDiscordClientRelationshipGroupsUpdatedCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::SetRelationshipGroupsUpdatedCallback "
                "cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_RelationshipGroupsUpdatedCallback cb__native = [](auto userId,
                                                                     void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        userData__typed->delegate.ExecuteIfBound(userId);
    };
    Discord_Client_SetRelationshipGroupsUpdatedCallback(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SetRelationshipGroupsUpdatedCallback(
  FDiscordClientRelationshipGroupsUpdatedCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - Client::SetRelationshipGroupsUpdatedCallback "
                "cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_RelationshipGroupsUpdatedCallback cb__native = [](auto userId,
                                                                     void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        userData__typed->delegate.ExecuteIfBound(userId);
    };
    Discord_Client_SetRelationshipGroupsUpdatedCallback(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SetUserUpdatedCallback(FDiscordClientUserUpdatedCallback const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Client::SetUserUpdatedCallback cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_UserUpdatedCallback cb__native = [](auto userId, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        userData__typed->delegate.ExecuteIfBound(userId);
    };
    Discord_Client_SetUserUpdatedCallback(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
void UDiscordClient::SetUserUpdatedCallback(FDiscordClientUserUpdatedCallbackDynamic const& cb)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT("Discord Partner SDK is stubbed out - Client::SetUserUpdatedCallback cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    using Tcb__UserData = TDelegateUserData<std::remove_reference_t<decltype(cb)>>;
    auto cb__userData = new Tcb__UserData(cb);
    Discord_Client_UserUpdatedCallback cb__native = [](auto userId, void* userData__) {
        auto userData__typed = static_cast<Tcb__UserData*>(userData__);
        userData__typed->delegate.ExecuteIfBound(userId);
    };
    Discord_Client_SetUserUpdatedCallback(
      &instance, cb__native, &Tcb__UserData::Free, cb__userData);
#endif
}
UDiscordCallInfoHandle::~UDiscordCallInfoHandle()
{
    Drop();
}
void UDiscordCallInfoHandle::Drop()
{
#if DISCORD_PARTNER_SDK_STUB
#else
    if (state != DiscordUObjectState::Owned) {
        return;
    }
    Discord_CallInfoHandle_Drop(&instance);
    state = DiscordUObjectState::Invalid;
#endif
}
/* TODO: Clone */
FDiscordUniqueID UDiscordCallInfoHandle::ChannelId()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - CallInfoHandle::ChannelId cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    uint64_t returnValue__;
    returnValue__ = Discord_CallInfoHandle_ChannelId(&instance);
    return returnValue__;
#endif
}
TArray<FDiscordUniqueID> UDiscordCallInfoHandle::GetParticipants()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(
      false,
      TEXT(
        "Discord Partner SDK is stubbed out - CallInfoHandle::GetParticipants cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    Discord_UInt64Span returnValueNative__;
    Discord_CallInfoHandle_GetParticipants(&instance, &returnValueNative__);
    TArray<FDiscordUniqueID> returnValue__;
    returnValue__.Reserve(returnValueNative__.size);
    for (size_t i__ = 0; i__ < returnValueNative__.size; ++i__) {
        returnValue__.Add(FDiscordUniqueID(returnValueNative__.ptr[i__]));
    }
    Discord_Free(returnValueNative__.ptr);
    return returnValue__;
#endif
}
UDiscordVoiceStateHandle* UDiscordCallInfoHandle::GetVoiceStateHandle(FDiscordUniqueID userId)
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - CallInfoHandle::GetVoiceStateHandle cannot "
                "be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    bool __returnIsNonNull;
    Discord_VoiceStateHandle returnValueNative__;
    UDiscordVoiceStateHandle* returnValue__ = nullptr;
    __returnIsNonNull =
      Discord_CallInfoHandle_GetVoiceStateHandle(&instance, userId, &returnValueNative__);
    if (!__returnIsNonNull) {
        return {};
    }
    returnValue__ = NewObject<UDiscordVoiceStateHandle>();
    returnValue__->instance = returnValueNative__;
    returnValue__->state = DiscordUObjectState::Owned;
    return returnValue__;
#endif
}
FDiscordUniqueID UDiscordCallInfoHandle::GuildId()
{
#if DISCORD_PARTNER_SDK_STUB
    checkf(false,
           TEXT("Discord Partner SDK is stubbed out - CallInfoHandle::GuildId cannot be called"));
    std::terminate();
#else
    check(state == DiscordUObjectState::Owned);
    uint64_t returnValue__;
    returnValue__ = Discord_CallInfoHandle_GuildId(&instance);
    return returnValue__;
#endif
}
#ifdef _MSC_VER
#pragma warning(pop)
#elif defined(__clang__)
#pragma clang diagnostic pop
#endif
