// Basic Ballistic System


#include "UI/BallisticGameHUD.h"
#include "Engine/Canvas.h"

void ABallisticGameHUD::DrawHUD()
{
    Super::DrawHUD();

    DrawCrossHair();
}

void ABallisticGameHUD::DrawCrossHair() 
{
    const TInterval<float> Center(Canvas->SizeX * 0.5f, Canvas->SizeY * 0.5f);

    const float HalfLineSize = 10.0f;
    const float LineThickness = 2.0f;
    const FLinearColor LineColor = FLinearColor::Green;

    DrawLine(Center.Min - HalfLineSize, Center.Max, Center.Min + HalfLineSize, Center.Max, LineColor, LineThickness);
    DrawLine(Center.Min, Center.Max - HalfLineSize, Center.Min, Center.Max + HalfLineSize, LineColor, LineThickness);
}