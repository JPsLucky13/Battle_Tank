// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "AIController.h"
#include "TankAIController.generated.h"
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

private:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	virtual void SetPawn(APawn * InPawn) override;

	UFUNCTION()
	void OnPossessedTankDeath();

protected:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float AcceptanceRadius = 8000.0f;
};
