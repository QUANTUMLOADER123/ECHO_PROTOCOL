// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GadgetBase.h"
#include "Medkit.generated.h"

/**
 * Аптечка / стимулятор — лечение, ускорение.
 */
UCLASS()
class ECHO_PROTOCOL_API AMedkit : public AGadgetBase
{
	GENERATED_BODY()

public:
	AMedkit();

	// Количество лечения
	UPROPERTY(EditDefaultsOnly, Category = "Medkit")
	float HealAmount = 50.0f;

	// Дает ли стимулятор ускорение?
	UPROPERTY(EditDefaultsOnly, Category = "Medkit")
	bool bIsStimulant = false;

	// Множитель скорости при стимуляторе
	UPROPERTY(EditDefaultsOnly, Category = "Medkit")
	float SpeedMultiplier = 1.5f;

	// Длительность стимуляции (секунды)
	UPROPERTY(EditDefaultsOnly, Category = "Medkit")
	float StimDuration = 10.0f;

	// Функции
	UFUNCTION(BlueprintCallable, Category = "Medkit")
	void UseMedicine();

protected:
	virtual void BeginPlay() override;
};
