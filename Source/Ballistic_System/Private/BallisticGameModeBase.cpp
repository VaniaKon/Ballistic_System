// Basic Ballistic System

#include "BallisticGameModeBase.h"
#include "Player/BallisticCharacter.h"
#include "Player/BallisticPlayerController.h"
#include "UI/BallisticGameHUD.h"

ABallisticGameModeBase::ABallisticGameModeBase()
{
    DefaultPawnClass = ABallisticCharacter::StaticClass();
    PlayerControllerClass = ABallisticPlayerController::StaticClass();
    HUDClass = ABallisticGameHUD::StaticClass();
}