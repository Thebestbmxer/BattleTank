// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "BattleTank.h"
#include "Tank.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (PlayerTank)
	{
		//Move Towards Player
		MoveToActor(PlayerTank, AcceptanceRadius);

		Cast<ATank>(GetPawn())->AimAt(PlayerTank->GetActorLocation());//Aim at player
		Cast<ATank>(GetPawn())->Fire();
	}
}
