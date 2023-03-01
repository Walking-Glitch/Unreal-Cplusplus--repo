// Fill out your copyright notice in the Description page of Project Settings.


#include "Turret.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"


void ATurret::BeginPlay()
{
	Super::BeginPlay();

	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));

	GetWorldTimerManager().SetTimer(FireTimer, this, &ATurret::CheckInRange, FireRate, true);
	
}

void ATurret::Tick(float DeltaTime)
{
	if (Tank)
	{
		float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());

		if (Distance <= FireRange)
		{
			RotateTurret(Tank->GetActorLocation());		
			InRange = true;
		}

		else {
			InRange = false;
		}
	}
}

void ATurret::CheckInRange()
{
	if (InRange)
	{
		Fire();
	}
}

