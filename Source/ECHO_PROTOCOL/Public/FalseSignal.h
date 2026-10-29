// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GadgetBase.h"
#include "FalseSignal.generated.h"

/**
 * Ложный сигнал — отвлекает патрули.
 */
UCLASS()
class ECHO_PROTOCOL_API AFalseSignal : public AGadgetBase
{
	GENERATED_BODY()

public:
	AFalseSignal();

	// Радиус отвлечения
	UPROPERTY(EditDefaultsOnly, Category = "FalseSignal")
	float DistractRadius = 700.0f;

	// Длительность интереса врагов (секунды)
	UPROPERTY(EditDefaultsOnly, Category = "FalseSignal")
	float DistractDuration = 8.0f;

	// Функции
	UFUNCTION(BlueprintCallable, Category = "FalseSignal")
	void DeploySignal();

protected:
	virtual void BeginPlay() override;
};
