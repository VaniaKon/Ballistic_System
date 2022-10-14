// Basic Ballistic System

#include "Components/BallisticWeaponComponent.h"
#include "Weapon/BallisticBaseWeapon.h"
#include "GameFramework/Character.h"

UBallisticWeaponComponent::UBallisticWeaponComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UBallisticWeaponComponent::BeginPlay()
{
    Super::BeginPlay();

    SpawnWeapon();
}

void UBallisticWeaponComponent::SpawnWeapon()
{
    if (!GetWorld()) return;
    ACharacter* Character = Cast<ACharacter>(GetOwner());
    if (!Character) return;

    CurrentWeapon = GetWorld()->SpawnActor<ABallisticBaseWeapon>(WeaponClass);
    if(!CurrentWeapon) return;
        
    FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, false);
    CurrentWeapon->AttachToComponent(Character->GetMesh(), AttachmentRules, WeaponAttachPointName);
    CurrentWeapon->SetOwner(Character);
}

void UBallisticWeaponComponent::Fire() 
{
  if(!CurrentWeapon) return;
  CurrentWeapon->Fire();
}