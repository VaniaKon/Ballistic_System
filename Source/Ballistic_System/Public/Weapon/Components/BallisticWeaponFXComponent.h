// Basic Ballistic System

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BallisticWeaponFXComponent.generated.h"

class UNiagaraSystem;
class UPhysicalMaterial;


// VFX
USTRUCT(BlueprintType)

struct FDecalData
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX")
    UMaterialInterface* Material;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX")
    FVector Size = FVector(10.0f);

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX")
    float LifeTime = 5.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX")
    float FadeOutTime = 0.7f;
};

USTRUCT(BlueprintType)
struct FImpactData
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX")
    UNiagaraSystem* NiagaraEffect;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX")
    FDecalData DecalData;
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BALLISTIC_SYSTEM_API UBallisticWeaponFXComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UBallisticWeaponFXComponent();

    void PlayImpactFX(const FHitResult& Hit);

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX")
    FImpactData DefaultImpactData;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX")
    TMap<UPhysicalMaterial*, FImpactData> ImpactDataMap;
};



