// Basic Ballistic System

using UnrealBuildTool;
using System.Collections.Generic;

public class Ballistic_SystemTarget : TargetRules
{
	public Ballistic_SystemTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "Ballistic_System" } );
	}
}
