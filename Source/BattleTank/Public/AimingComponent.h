// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AimingComponent.generated.h"

class UTankBarrel;
class UTankTurret;

//Holds Barrel Properties
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAimingComponent();

	void SetBarrelReference(UTankBarrel* BarrelToSet);
	void SetTurretReferance(UTankTurret* TurretToSet);
	void MoveBarrelTowards(FVector AimDirection);

public:	
	void AimAt(FVector HitLocation, float LaunchSpeed);
	
private:
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;
};
