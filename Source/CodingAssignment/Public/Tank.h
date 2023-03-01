// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyPawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class CODINGASSIGNMENT_API ATank : public AMyPawn
{
	GENERATED_BODY()

		ATank();
 

	UPROPERTY(EditDefaultsOnly)
		class USpringArmComponent* SpringArm;
	
	UPROPERTY(EditDefaultsOnly)
		class UCameraComponent* FollowCamera;

	class APlayerController* PlayerControllerRef;

	UPROPERTY(EditAnywhere)
	float Speed = 100.0f;

	UPROPERTY(EditAnywhere)
	float TurnSpeed = 100.0f;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Move(float Value);

	void Turn(float turnAmount);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input



};
