// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 In UCLASS it shows how to set up component group and hide categories of the component
 */

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float RelativeSpeed);
	
private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 2;
	
	//Max Pitch of Barrel
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevationDegrees = 40;

	//Min Pitch of Barrel
	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevationDegrees = 0;

};
