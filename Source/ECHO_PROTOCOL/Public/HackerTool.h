// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GadgetBase.h"
#include "HackerTool.generated.h"

/**
 * Взломщик — терминалы, камеры, турели.
 */
UCLASS()
class ECHO_PROTOCOL_API AHackerTool : public AGadgetBase
{
	GENERATED_BODY()

public:
	AHackerTool();

	// Время взлома (секунды)
	UPROPERTY(EditDefaultsOnly, Category = "HackerTool")
	float HackTime = 3.0f;

	// Функции
	UFUNCTION(BlueprintCallable, Category = "HackerTool")
	void HackTarget(AActor* Target);

protected:
	virtual void BeginPlay() override;
};
