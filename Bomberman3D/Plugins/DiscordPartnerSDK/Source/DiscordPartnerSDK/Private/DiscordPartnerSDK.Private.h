#pragma once

#include "CoreMinimal.h"

#include <functional>

namespace discord {
class ModuleOnLoadFunction {
public:
    using LoadHandler = std::function<void(FString const& BaseDir, FString& LibraryPath)>;
    using UnloadHandler = std::function<void()>;
    ModuleOnLoadFunction(LoadHandler onLoad, UnloadHandler onUnload);
};
} // namespace discord
