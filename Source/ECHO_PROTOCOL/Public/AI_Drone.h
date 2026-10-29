// Fill out your copyright notice в Description page of Project Settings.

#pragma once

#include "CoreMinimal.h>
#include "AIControllerBase.h>
#include "AI_Drone.generated.h"

/**
 * Дрон-адаптор — летает, сканирует, запоминает позиции, меняет маршруты. Уязвим к ЭМИ.
 */
UCLASS()
class ECHO_PROTOCOL_API AAI_Drone : public AAIControllerBase
{
	GENERATED_BODY()

public:
	AAI_Drone();

	// Радиус сканирования
	UPROPERTY(EditDefaultsOnly, Category = "AI_Drone")
	float ScanRadius = 1000.0f;

	// Уязвимость к ЭМИ
	UPROPERTY(EditDefaultsOnly, Category = "AI_Drone")
	bool bVulnerableToEMI = true;

	// Функции
	UFUNCTION(BlueprintCallable, Category = "AI_Drone")
	void ScanArea();

	UFUNCTION(BlueprintCallable, Category = "AI_Drone")
	void ChangeRoute();

	UFUNCTION(BlueprintCallable, Category = "AI_Drone")
	void TakeEMIDamage(float Amount);

protected:
	virtual void BeginPlay() override;
};
