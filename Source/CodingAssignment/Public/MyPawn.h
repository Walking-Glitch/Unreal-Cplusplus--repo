// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPawn.generated.h"

UCLASS()
class CODINGASSIGNMENT_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float health = 100.0f;

	void RotateTurret(FVector LookAtTarget);

	UFUNCTION(BlueprintImplementableEvent)
	void Fire();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void Death();
 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
 	class UCapsuleComponent* CapsuleComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* BodyMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* CannonMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	class USceneComponent* ProjectileSpawn;

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	

};
