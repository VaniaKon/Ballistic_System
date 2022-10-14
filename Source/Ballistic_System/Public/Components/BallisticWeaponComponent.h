// Basic Ballistic System

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BallisticWeaponComponent.generated.h"

class ABallisticBaseWeapon;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BALLISTIC_SYSTEM_API UBallisticWeaponComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UBallisticWeaponComponent();

    void Fire();
	

protected:
    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    TSubclassOf<ABallisticBaseWeapon> WeaponClass;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    FName WeaponAttachPointName = "WeaponSocket";

    virtual void BeginPlay() override;

private:
    UPROPERTY()
    ABallisticBaseWeapon* CurrentWeapon = nullptr;

    void SpawnWeapon();
};
