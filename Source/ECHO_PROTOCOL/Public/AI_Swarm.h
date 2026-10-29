// Fill out your copyright notice в Description page of Project Settings.

#pragma once

#include "CoreMinimal.h>
#include "AIControllerBase.h>
#include "AI_Swarm.generated.h"

/**
 * Стая — массовый ИИ, окружают, реагируют на свет и звук.
 */
UCLASS()
class ECHO_PROTOCOL_API AAI_Swarm : public AAIControllerBase
{
	GENERATED_BODY()

public:
	AAI_Swarm();

	// Размер стаи
	UPROPERTY(EditDefaultsOnly, Category = "AI_Swarm")
	int32 SwarmSize = 5;

	// Функции
	UFUNCTION(BlueprintCallable, Category = "AI_Swarm")
	void SurroundPlayer();

	UFUNCTION(BlueprintCallable, Category = "AI_Swarm")
	void ReactToLightAndSound();

protected:
	virtual void BeginPlay() override;
};
