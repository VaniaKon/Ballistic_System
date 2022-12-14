// Basic Ballistic System

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BallisticCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UBallisticWeaponComponent;

UCLASS()
class BALLISTIC_SYSTEM_API ABallisticCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    ABallisticCharacter(const FObjectInitializer& ObjInit);

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    USpringArmComponent* SpringArmComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UCameraComponent* CameraComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UBallisticWeaponComponent* WeaponComponent;

    virtual void BeginPlay() override;
    

public:
    virtual void Tick(float DeltaTime) override;

    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    UFUNCTION(BlueprintCallable, Category = "Movement")
    bool IsRunning() const;

    UFUNCTION(BlueprintCallable, Category = "Movement")
    float GetMovementDirection() const;

private:
    bool WantsToRun = false;
    bool IsMovingForward = false;

    void MoveForward(float Amount);
    void MoveRight(float Amount);

    void OnStartRunning();
    void OnStopRunning();       
};
