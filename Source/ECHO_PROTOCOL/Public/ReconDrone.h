// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GadgetBase.h"
#include "ReconDrone.generated.h"

/**
 * Дрон-разведчик — управляемый, малый радиус.
 */
UCLASS()
class ECHO_PROTOCOL_API AReconDrone : public AGadgetBase
{
	GENERATED_BODY()

public:
	AReconDrone();

	// Радиус управления дроном
	UPROPERTY(EditDefaultsOnly, Category = "ReconDrone")
	float ControlRadius = 1000.0f;

	// Время полета (секунды)
	UPROPERTY(EditDefaultsOnly, Category = "ReconDrone")
	float FlightTime = 30.0f;

	// Функции
	UFUNCTION(BlueprintCallable, Category = "ReconDrone")
	void DeployDrone();

protected:
	virtual void BeginPlay() override;
};
