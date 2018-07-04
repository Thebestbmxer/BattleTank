// Test Tutorial Project Settings

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UAimingComponent;
class UTankMovementComponent;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable)
		void Fire();

protected:
	UPROPERTY(BlueprintReadOnly)
	UAimingComponent* TankAimingComponent = nullptr;

	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* TankTankMovementComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();

	UPROPERTY(EditDefaultsOnly, Category = "SetUp")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	//Value Shoule be in Meters Per Second
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000;	//cm Per Second

	//Time in Seconds to reload
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTime = 3;

	UTankBarrel* Barrel = nullptr; //TODO: Remove value

	float LastFireTime = 0;
};