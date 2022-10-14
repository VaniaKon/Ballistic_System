// Basic Ballistic System

using UnrealBuildTool;
using System.Collections.Generic;

public class Ballistic_SystemEditorTarget : TargetRules
{
	public Ballistic_SystemEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "Ballistic_System" } );
	}
}
