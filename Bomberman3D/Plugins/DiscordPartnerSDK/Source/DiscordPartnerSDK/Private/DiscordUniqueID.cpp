// Copyright Discord, Inc. All Rights Reserved.

#include "DiscordUniqueID.h"

#include <string>
#if ENGINE_MAJOR_VERSION >= 5
#include <charconv>
#else
#include <errno.h>
#include <cstdlib>
#endif

FDiscordUniqueID::FDiscordUniqueID()
  : Value(0)
{
}

FDiscordUniqueID::FDiscordUniqueID(uint64_t value)
  : Value(value)
{
}

FDiscordUniqueID::operator uint64_t() const
{
    return Value;
}

FString FDiscordUniqueID::ToString() const
{
    return UTF8_TO_TCHAR(std::to_string(Value).c_str());
}

FDiscordUniqueID FDiscordUniqueID::FromString(const FString& DiscordUniqueIDString, bool& Success)
{
    FDiscordUniqueID OutUniqueID;
    auto converter = FTCHARToUTF8((const TCHAR*)*DiscordUniqueIDString);

#if ENGINE_MAJOR_VERSION >= 5
    Success = (std::from_chars((ANSICHAR*)converter.Get(),
                               (ANSICHAR*)converter.Get() + converter.Length(),
                               OutUniqueID.Value)
                 .ec == std::errc{});
#else
    // UE4.27 compatible version using traditional string parsing
    char* endPtr = nullptr;
    errno = 0;
    OutUniqueID.Value = strtoull((ANSICHAR*)converter.Get(), &endPtr, 10);
    Success = (errno == 0) && (endPtr == (ANSICHAR*)converter.Get() + converter.Length()) &&
      (endPtr != (ANSICHAR*)converter.Get());
#endif

    return OutUniqueID;
}
