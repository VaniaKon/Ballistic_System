// Basic Ballistic System

#include "Player/BallisticCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/BallisCharacterMovementComponent.h"
#include "Components/BallisticWeaponComponent.h"

ABallisticCharacter::ABallisticCharacter(const FObjectInitializer& ObjInit)
    : Super(ObjInit.SetDefaultSubobjectClass<UBallisCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
    PrimaryActorTick.bCanEverTick = true;

    SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
    SpringArmComponent->SetupAttachment(GetRootComponent());
    SpringArmComponent->bUsePawnControlRotation = true;
    SpringArmComponent->SocketOffset = FVector(0.0f, 100.0f, 80.0f);

    CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
    CameraComponent->SetupAttachment(SpringArmComponent);

    WeaponComponent = CreateDefaultSubobject<UBallisticWeaponComponent>("WeaponComponent");
}

void ABallisticCharacter::BeginPlay()
{
    Super::BeginPlay();       
}

void ABallisticCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ABallisticCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    check(WeaponComponent);

    PlayerInputComponent->BindAxis("MoveForward", this, &ABallisticCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &ABallisticCharacter::MoveRight);
    PlayerInputComponent->BindAxis("LookUp", this, &ABallisticCharacter::AddControllerPitchInput);
    PlayerInputComponent->BindAxis("TurnAround", this, &ABallisticCharacter::AddControllerYawInput);
    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ABallisticCharacter::Jump);
    PlayerInputComponent->BindAction("Run", IE_Pressed, this, &ABallisticCharacter::OnStartRunning);
    PlayerInputComponent->BindAction("Run", IE_Released, this, &ABallisticCharacter::OnStopRunning);
    PlayerInputComponent->BindAction("Fire", IE_Pressed, WeaponComponent, &UBallisticWeaponComponent::Fire);
    
}

void ABallisticCharacter::MoveForward(float Amount)
{
    IsMovingForward = Amount > 0.0f;
    if(Amount == 0.0f) return;
    AddMovementInput(GetActorForwardVector(), Amount);
}

void ABallisticCharacter::MoveRight(float Amount)
{
    if(Amount == 0.0f) return;
    AddMovementInput(GetActorRightVector(), Amount);
}

void ABallisticCharacter::OnStartRunning()
{
    WantsToRun = true;
}

void ABallisticCharacter::OnStopRunning()
{
    WantsToRun = false;
}

bool ABallisticCharacter::IsRunning() const
{
    return WantsToRun && IsMovingForward && !GetVelocity().IsZero();
}

float ABallisticCharacter::GetMovementDirection() const
{
    if (GetVelocity().IsZero()) return 0.0f;
    const auto VelocityNormal = GetVelocity().GetSafeNormal();
    const auto AngleBetween = FMath::Acos(FVector::DotProduct(GetActorForwardVector(), VelocityNormal));
    const auto CrossProduct = FVector::CrossProduct(GetActorForwardVector(), VelocityNormal);
    const auto Degrees = FMath::RadiansToDegrees(AngleBetween);
    return CrossProduct.IsZero() ? Degrees : Degrees * FMath::Sign(CrossProduct.Z);
}

