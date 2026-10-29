// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GadgetBase.h"
#include "SensorJammer.generated.h"

/**
 * Глушилка сенсоров — временно отключает камеры и турели.
 */
UCLASS()
class ECHO_PROTOCOL_API ASensorJammer : public AGadgetBase
{
	GENERATED_BODY()

public:
	ASensorJammer();

	// Радиус глушения
	UPROPERTY(EditDefaultsOnly, Category = "SensorJammer")
	float JamRadius = 800.0f;

	// Длительность действия (секунды)
	UPROPERTY(EditDefaultsOnly, Category = "SensorJammer")
	float JamDuration = 10.0f;

	// Функции
	UFUNCTION(BlueprintCallable, Category = "SensorJammer")
	void JamSensors();

protected:
	virtual void BeginPlay() override;
};
