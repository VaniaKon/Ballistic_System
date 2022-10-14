// Basic Ballistic System

#include "Weapon/Components/BallisticWeaponFXComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "PhysicalMaterials/PhysicalMaterial.h"
#include "Kismet/GameplayStatics.h"
#include "Components/DecalComponent.h"

UBallisticWeaponFXComponent::UBallisticWeaponFXComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UBallisticWeaponFXComponent::PlayImpactFX(const FHitResult& Hit)
{
    auto ImpactData = DefaultImpactData;

	if (Hit.PhysMaterial.IsValid())
	{
		const auto PhysMat = Hit.PhysMaterial.Get();
		if (ImpactDataMap.Contains(PhysMat))
		{
			ImpactData = ImpactDataMap[PhysMat];
		}
	}

	// Niagara
    UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), //
		ImpactData.NiagaraEffect,                              //
	    Hit.ImpactPoint,                                       //
		Hit.ImpactNormal.Rotation());

	// Decal
	auto DecalComponent = UGameplayStatics::SpawnDecalAtLocation(GetWorld(),  //
		ImpactData.DecalData.Material,                                        //
		ImpactData.DecalData.Size,                                            //
		Hit.ImpactPoint,                                                      //
        Hit.ImpactNormal.Rotation());
	if (DecalComponent)
	{
	    DecalComponent->SetFadeOut(ImpactData.DecalData.LifeTime, ImpactData.DecalData.FadeOutTime);
	}
}
