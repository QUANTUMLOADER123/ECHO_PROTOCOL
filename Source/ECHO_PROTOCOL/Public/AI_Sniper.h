// Fill out your copyright notice в Description page of Project Settings.

#pragma once

#include "CoreMinimal.h>
#include "AIControllerBase.h>
#include "AI_Sniper.generated.h"

/**
 * Снайпер — на высотах, лазерный прицел, требует обхода.
 */
UCLASS()
class ECHO_PROTOCOL_API AAI_Sniper : public AAIControllerBase
{
	GENERATED_BODY()

public:
	AAI_Sniper();

	// Дистанция обнаружения
	UPROPERTY(EditDefaultsOnly, Category = "AI_Sniper")
	float DetectionRange = 2000.0f;

	// Функции
	UFUNCTION(BlueprintCallable, Category = "AI_Sniper")
	void AimLaser();

	UFUNCTION(BlueprintCallable, Category = "AI_Sniper")
	void TakeShot();

protected:
	virtual void BeginPlay() override;
};
