// Basic Ballistic System

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "BallisticGameHUD.generated.h"

UCLASS()
class BALLISTIC_SYSTEM_API ABallisticGameHUD : public AHUD
{
    GENERATED_BODY()

public:
    virtual void DrawHUD() override;

private:
    void DrawCrossHair();
};
