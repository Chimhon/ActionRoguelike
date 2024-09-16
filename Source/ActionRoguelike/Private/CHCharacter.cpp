// Fill out your copyright notice in the Description page of Project Settings.



#include "ActionRoguelike/Public/CHCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ACHCharacter::ACHCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	SpringArmComp -> SetupAttachment(RootComponent);
	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp -> SetupAttachment(SpringArmComp);

	SpringArmComp -> bUsePawnControlRotation = true;
	bUseControllerRotationYaw = false;

}

// Called when the game starts or when spawned
void ACHCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void ACHCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACHCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward",this,&ACHCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight",this,&ACHCharacter::MoveRight);
	
	PlayerInputComponent->BindAxis("Turn",this,&APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp",this,&APawn::AddControllerPitchInput);
	
}

void ACHCharacter::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(),Value);
}

void ACHCharacter::MoveRight(float Value)
{
	AddMovementInput(GetActorRightVector(),Value);
}
