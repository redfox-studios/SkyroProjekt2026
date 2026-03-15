// (c) 2024 Discord, Inc.

using System;
using System.IO;
using System.Reflection;
using UnrealBuildTool;

public partial class DiscordPartnerSDKLibrary : ModuleRules {
    string RuntimeBinariesPath = "$(PluginDir)/Binaries/ThirdParty/DiscordPartnerSDKLibrary/";

    private string GetSDKBuildConfig(UnrealTargetConfiguration Configuration) {
        switch (Configuration) {
        case UnrealTargetConfiguration.Shipping:
            return "Release";
        default:
            return "Debug";
        }
    }

    public DiscordPartnerSDKLibrary(ReadOnlyTargetRules Target)
      : base(Target) {
        Type = ModuleType.External;

        PublicIncludePaths.AddRange(new string[] { Path.Combine(ModuleDirectory, "include") });

        string SDKBuildConfig = GetSDKBuildConfig(Target.Configuration);

        PublicDefinitions.Add(SDKBuildConfig == "Debug" ? "DISCORD_DEBUG_API_ENABLED=1"
                                                        : "DISCORD_DEBUG_API_ENABLED=0");

        var setupMethodName = "Setup_" + Target.Platform;
        var setupMethod =
          GetType().GetMethod(setupMethodName, BindingFlags.NonPublic | BindingFlags.Instance);
        if (setupMethod != null) {
            setupMethod.Invoke(this, new object[] { Target });
        }

        if (Target.Platform == UnrealTargetPlatform.Win64) {
            // Add the import library
            PublicAdditionalLibraries.Add(
              Path.Combine(ModuleDirectory, "lib", SDKBuildConfig, "discord_partner_sdk.dll.lib"));

            // Delay-load the DLL, so we can load it from the right place first
            PublicDelayLoadDLLs.Add("discord_partner_sdk.dll");

            // Ensure that the DLL is staged along with the executable
            RuntimeDependencies.Add(RuntimeBinariesPath + "Win64/" + SDKBuildConfig +
                                    "/discord_partner_sdk.dll");
        } else if (Target.Platform == UnrealTargetPlatform.Linux) {
            string SharedLibPath = Path.Combine(
              RuntimeBinariesPath, "Linux", SDKBuildConfig, "libdiscord_partner_sdk.so");
            PublicAdditionalLibraries.Add(SharedLibPath);
            RuntimeDependencies.Add(SharedLibPath);
        } else if (Target.Platform == UnrealTargetPlatform.Mac) {
            string SharedLibPath = Path.Combine(
              RuntimeBinariesPath, "Mac", SDKBuildConfig, "libdiscord_partner_sdk.dylib");
            PublicAdditionalLibraries.Add(SharedLibPath);
            RuntimeDependencies.Add(SharedLibPath);
        } else if (Target.Platform == UnrealTargetPlatform.IOS) {
            string FrameworkPath = Path.Combine(PluginDirectory,
                                                "Binaries",
                                                "ThirdParty",
                                                "DiscordPartnerSDKLibrary",
                                                "IOS",
                                                SDKBuildConfig,
                                                "discord_partner_sdk.xcframework");
            PublicAdditionalFrameworks.Add(
              new Framework("discord_partner_sdk", FrameworkPath, bCopyFramework: true));
        } else if (Target.Platform == UnrealTargetPlatform.Android) {
            string AndroidPath = Path.Combine(RuntimeBinariesPath, "Android", SDKBuildConfig);
            PublicAdditionalLibraries.Add(
              Path.Combine(AndroidPath, "jni", "arm64-v8a", "libdiscord_partner_sdk.so"));
            PublicAdditionalLibraries.Add(
              Path.Combine(AndroidPath, "jni", "armeabi-v7a", "libdiscord_partner_sdk.so"));
            PublicAdditionalLibraries.Add(
              Path.Combine(AndroidPath, "jni", "x86", "libdiscord_partner_sdk.so"));
            PublicAdditionalLibraries.Add(
              Path.Combine(AndroidPath, "jni", "x86_64", "libdiscord_partner_sdk.so"));
        }
    }
}
