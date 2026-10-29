// Fill out your copyright notice в Description page of Project Settings.

#pragma once

#include "CoreMinimal.h>
#include "AIControllerBase.h>
#include "AI_Patrol.generated.h"

/**
 * Патруль (человек в экзоскелете) — слышит шум, ищет по следам, вызывает подкрепление.
 */
UCLASS()
class ECHO_PROTOCOL_API AAI_Patrol : public AAIControllerBase
{
	GENERATED_BODY()

public:
	AAI_Patrol();

	// Функции
	UFUNCTION(BlueprintCallable, Category = "AI_Patrol")
	void FollowRoute();

	UFUNCTION(BlueprintCallable, Category = "AI_Patrol")
	void InvestigateNoise(FVector NoiseLocation);

	UFUNCTION(BlueprintCallable, Category = "AI_Patrol")
	void CallReinforcements();

protected:
	virtual void BeginPlay() override;
};
