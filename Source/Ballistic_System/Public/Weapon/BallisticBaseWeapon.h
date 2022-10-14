// Basic Ballistic System

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BallisticBaseWeapon.generated.h"

class USkeletalMeshComponent;
class UBallisticWeaponFXComponent;
class UNiagaraSystem;
class UNiagaraComponent;
class USoundCue;

UCLASS()
class BALLISTIC_SYSTEM_API ABallisticBaseWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ABallisticBaseWeapon();

	virtual void Fire();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    USkeletalMeshComponent* WeaponMesh;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FName MuzzleSocketName = "Muzzlesocket";

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float TraceMaxDistance = 1500.0f;

	UPROPERTY(VisibleAnywhere, Category = "VFX");
	UBallisticWeaponFXComponent* WeaponFXComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX")
    UNiagaraSystem* MuzzleFX;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX")
	UNiagaraSystem* TraceFX;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX")
	FString TraceTargetName = "TraceTarget";

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sound")
	USoundCue* FireSound;

	virtual void BeginPlay() override;
	
	virtual void MakeShot();
	APlayerController* GetPlayerController() const;
	bool GetPlayerViewPoint(FVector& ViewLocation, FRotator& ViewRatation) const;
	FVector GetMuzzleWorldLocation() const;
	virtual bool GetTraceData(FVector& TraceStart, FVector& TraceEnd) const;
	void MakeHit(FHitResult& HitResult, const FVector& TraceStart, const FVector& TraceEnd);
	void SpawnTraceFX(const FVector& TraceStart, const FVector& TraceEnd);

	UNiagaraComponent* SpawnMuzzleFX();	
};
