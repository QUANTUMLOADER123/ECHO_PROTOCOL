// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ECHO_PROTOCOL : ModuleRules
{
	public ECHO_PROTOCOL(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"NavigationSystem",
			"AIModule",
			"GameplayTasks",
			"Slate",
			"SlateCore"
		});

		PrivateDependencyModuleNames.AddRange(new string[]
		{
		});

		PublicIncludePaths.AddRange(new string[] { "ECHO_PROTOCOL/Public" });

		if (Target.bBuildDeveloperTools || Target.Configuration != UnrealTargetConfiguration.Shipping)
		{
			PrivateDependencyModuleNames.Add("LogVisualization");
		}
	}
}
