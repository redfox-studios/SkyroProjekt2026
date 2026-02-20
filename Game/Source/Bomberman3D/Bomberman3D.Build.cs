// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Bomberman3D : ModuleRules
{
	public Bomberman3D(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"Bomberman3D",
			"Bomberman3D/Variant_Platforming",
			"Bomberman3D/Variant_Platforming/Animation",
			"Bomberman3D/Variant_Combat",
			"Bomberman3D/Variant_Combat/AI",
			"Bomberman3D/Variant_Combat/Animation",
			"Bomberman3D/Variant_Combat/Gameplay",
			"Bomberman3D/Variant_Combat/Interfaces",
			"Bomberman3D/Variant_Combat/UI",
			"Bomberman3D/Variant_SideScrolling",
			"Bomberman3D/Variant_SideScrolling/AI",
			"Bomberman3D/Variant_SideScrolling/Gameplay",
			"Bomberman3D/Variant_SideScrolling/Interfaces",
			"Bomberman3D/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
