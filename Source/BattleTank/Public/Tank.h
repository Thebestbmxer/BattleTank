// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankTurret;
class UAimingComponent;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	UFUNCTION(BlueprintCallable, Category = SetUp)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = SetUp)
	void SetTurretReference(UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable)
	void Fire();

	void AimAt(FVector HitLocation);
protected:
	UAimingComponent* TankAimingComponent = nullptr;

private:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly, Category = SetUp)
	TSubclassOf<AProjectile> ProjectileBlueprint;

	//Value Shoule be in Meters Per Second
	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float LaunchSpeed = 40;	//cm Per Second

	//Local Barrel referance for spawning projectile
	UTankBarrel* Barrel = nullptr;
	
	//Time in Seconds to reload
	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float ReloadTime;

	float LastFireTime = 3;
};
