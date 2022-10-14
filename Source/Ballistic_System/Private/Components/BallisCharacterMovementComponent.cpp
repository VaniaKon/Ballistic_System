// Basic Ballistic System


#include "Components/BallisCharacterMovementComponent.h"
#include "Player/BallisticCharacter.h"

float UBallisCharacterMovementComponent::GetMaxSpeed() const
{
    const float MaxSpeed = Super::GetMaxSpeed();
    const ABallisticCharacter* Player = Cast<ABallisticCharacter>(GetPawnOwner());
    return Player && Player->IsRunning() ? MaxSpeed * RunModifier : MaxSpeed;
}

