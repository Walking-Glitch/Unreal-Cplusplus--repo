// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"

// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;



	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleC"));
	RootComponent = CapsuleComp;

	BodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	BodyMesh->SetupAttachment(CapsuleComp);

	CannonMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret"));
	CannonMesh->SetupAttachment(BodyMesh);

	ProjectileSpawn = CreateDefaultSubobject<USceneComponent>(TEXT("PSpawn"));
	ProjectileSpawn->SetupAttachment(CannonMesh);
}

void AMyPawn::RotateTurret(FVector TargetLocation)
{
	FVector ToTarget = TargetLocation - CannonMesh->GetComponentLocation();
	FRotator LookAtRotation = FRotator(0.f, ToTarget.Rotation().Yaw, 0.f);
	CannonMesh->SetWorldRotation(LookAtRotation);
}
// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input

 