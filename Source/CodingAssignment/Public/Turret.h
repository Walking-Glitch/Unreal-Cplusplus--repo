// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyPawn.h"
#include "Turret.generated.h"

/**
 * 
 */
UCLASS()
class CODINGASSIGNMENT_API ATurret : public AMyPawn
{
	GENERATED_BODY()

		class ATank* Tank;
	
	UPROPERTY(EditAnywhere)
	float FireRange = 1000.f;

	UPROPERTY(EditAnywhere)
		float FireRate = 2.f;

	FTimerHandle FireTimer;

	bool InRange;

	void CheckInRange();

public:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	
};
