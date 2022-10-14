// Basic Ballistic System

using UnrealBuildTool;

public class Ballistic_System : ModuleRules
{
	public Ballistic_System(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[]
		{ 
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"Niagara",
			"PhysicsCore",
			"GameplayTasks"
		});

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		PublicIncludePaths.AddRange(new string[]
			{
			"Ballistic_System/Public/Player",
			"Ballistic_System/Public/Components",
			"Ballistic_System/Public/Weapon",
			"Ballistic_System/Public/UI",
			"Ballistic_System/Public/Weapon/Components"
			});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
