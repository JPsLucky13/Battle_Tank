// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "TankPlayerController.generated.h"

class UTankAimingComponent;
/**
 * Responsible for helping the player aim
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:

	UFUNCTION(BlueprintImplementableEvent, Category = Setup)
	void FoundAimingComponent(UTankAimingComponent * AimCompRef);

	UFUNCTION()
	void OnPossessedTankDeath();

private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	virtual void SetPawn(APawn * InPawn) override;

	
	
	//Start the tank moving the barrel towards where the barrel intersects the world
	void AimTowardsCrosshair();

	//Return an Out parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection,FVector & HitLocation) const;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation = 0.5f;
	UPROPERTY(EditDefaultsOnly)
	float CrossHairYLocation = 0.33333f;
	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000.0f;
};
