// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TB : ModuleRules
{
	public TB(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "GameplayTasks", "UMG" });
	}
}
