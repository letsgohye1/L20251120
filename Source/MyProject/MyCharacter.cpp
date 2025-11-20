// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"

#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

#include "Kismet/KismetMathLibrary.h"



// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetCapsuleComponent());

	Camera= CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	GetMesh()->SetRelativeLocation(FVector(0, 0, -GetCapsuleComponent()->GetUnscaledCapsuleHalfHeight()));
	GetMesh()->SetRelativeRotation(FRotator(0, -90.0f, 0));
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMyCharacter::Move(float Front, float Right)
{

	AddMovementInput(
		UKismetMathLibrary::GetForwardVector(
			FRotator(0, GetController()->GetControlRotation().Yaw, 0)
		),
		Front
	);

	AddMovementInput(
		UKismetMathLibrary::GetRightVector(
			FRotator(0, GetController()->GetControlRotation().Yaw, GetController()->GetControlRotation().Roll)
		),
		Right
	);
}

void AMyCharacter::Look(float pitch, float Yaw)
{
	AddControllerPitchInput(pitch);
	AddControllerYawInput(Yaw);
}

