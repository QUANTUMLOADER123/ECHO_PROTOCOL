// Fill out your copyright notice в Description page of Project Settings.

#pragma once

#include "CoreMinimal.h>
#include "AIControllerBase.h>
#include "AI_Phantom.generated.h"

/**
 * Фантом — только в Эхо-слое. Атакует ментально: искажает HUD, крадет заряды, ложные метки.
 * Убивается Якорем реальности.
 */
UCLASS()
class ECHO_PROTOCOL_API AAI_Phantom : public AAIControllerBase
{
	GENERATED_BODY()

public:
	AAI_Phantom();

	// Урон ментальной атаке
	UPROPERTY(EditDefaultsOnly, Category = "AI_Phantom")
	float MentalDamage = 10.0f;

	// Функции
	UFUNCTION(BlueprintCallable, Category = "AI_Phantom")
	void MentalAttack();

	UFUNCTION(BlueprintCallable, Category = "AI_Phantom")
	void DistortHUD();

	UFUNCTION(BlueprintCallable, Category = "AI_Phantom")
	void StealEchoCharge();

	UFUNCTION(BlueprintCallable, Category = "AI_Phantom")
	void TakeRealityAnchorDamage(float Amount);

protected:
	virtual void BeginPlay() override;
};
