// Fill out your copyright notice in the Description page of Project Settings.


#include "FPCharacter.h"

// Sets default values
AFPCharacter::AFPCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFPCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFPCharacter::MoveForward(float value)
{
	AddMovementInput(GetActorForwardVector(), value);
}


void AFPCharacter::MoveRight(float value)
{
	AddMovementInput(GetActorRightVector(), value);
}


void AFPCharacter::LookRight(float value)
{
	AddControllerYawInput(value);
}

void AFPCharacter::LookUp(float value)
{
	AddControllerPitchInput(value);
}

void AFPCharacter::Jump()
{
	bPressedJump = true;
	JumpKeyHoldTime = 0.0f;
}

// Called every frame
void AFPCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFPCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &AFPCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFPCharacter::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this, &AFPCharacter::LookUp);
	PlayerInputComponent->BindAxis("LookRight", this, &AFPCharacter::LookRight);
	PlayerInputComponent->BindAction("Jump", IE_Pressed,this, &AFPCharacter::Jump);
	
}

