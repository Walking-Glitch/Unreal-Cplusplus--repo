// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"

ATank::ATank()
{

 
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(CannonMesh);

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCam"));
	FollowCamera->SetupAttachment(SpringArm);

}

void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("Forward"), this, &ATank::Move);
	PlayerInputComponent->BindAxis(TEXT("Rotation"), this, &ATank::Turn);
	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed ,this, &ATank::Fire);

}

void ATank::Move(float Value) 
{
	FVector DeltaLocation = FVector::ZeroVector;
	DeltaLocation.X = Value * Speed * UGameplayStatics::GetWorldDeltaSeconds(this);
	AddActorLocalOffset(DeltaLocation);
}

void ATank::Turn(float turnAmount) {
	FRotator Rotato = FRotator::ZeroRotator;
	Rotato.Yaw = turnAmount * TurnSpeed * UGameplayStatics::GetWorldDeltaSeconds(this);
	AddActorLocalRotation(Rotato);
}

void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FHitResult HitResult;

	if (PlayerControllerRef)
	{
		PlayerControllerRef->GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, HitResult);

		RotateTurret(HitResult.ImpactPoint);
		DrawDebugSphere
		(
			GetWorld(),
			HitResult.ImpactPoint,
			25.f,
			12,
			FColor::Emerald,
			false,
			-1.f
		);
	}


}

void ATank::BeginPlay()
{
	Super::BeginPlay();

	PlayerControllerRef = Cast<APlayerController>(GetController());
}

