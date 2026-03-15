// Copyright Discord, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Reflection;

public partial class DiscordPartnerSDK : ModuleRules {
    List<UnrealTargetPlatform> supportedPlatforms = new List<UnrealTargetPlatform> {
        UnrealTargetPlatform.Win64,
        UnrealTargetPlatform.Linux,
        UnrealTargetPlatform.Mac,
        UnrealTargetPlatform.IOS,
        UnrealTargetPlatform.Android,
    };

    public DiscordPartnerSDK(ReadOnlyTargetRules Target)
      : base(Target) {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        var setupMethodName = "Setup_" + Target.Platform;
        var setupMethod =
          GetType().GetMethod(setupMethodName, BindingFlags.NonPublic | BindingFlags.Instance);
        if (setupMethod != null) {
            setupMethod.Invoke(this, new object[] { Target });
        }
        var globalStub = Target.ProjectDefinitions.Contains("DISCORD_PARTNER_SDK_STUB=1");
        bool useStub = !supportedPlatforms.Contains(Target.Platform) || globalStub;
        if (useStub && !globalStub) {
            PublicDefinitions.Add("DISCORD_PARTNER_SDK_STUB=1");
        }
        PublicDependencyModuleNames.AddRange(new string[] { "Core", "Projects" });
        if (!useStub) {
            PublicDependencyModuleNames.Add("DiscordPartnerSDKLibrary");
        }
        PrivateDependencyModuleNames.AddRange(new string[] {
            "CoreUObject",
            "Engine",
            "DeveloperSettings",
        });
        if (Target.Platform == UnrealTargetPlatform.Android) {
            AdditionalPropertiesForReceipt.Add(
              "AndroidPlugin", Path.Combine(ModuleDirectory, "AndroidPluginData.xml"));
        }
    }
}
