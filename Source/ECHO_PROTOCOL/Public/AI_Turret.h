// Fill out your copyright notice в Description page of Project Settings.

#pragma once

#include "CoreMinimal.h>
#include "AIControllerBase.h>
#include "AI_Turret.generated.h"

/**
 * Турель — стационарная, взламывается, может работать на игрока.
 */
UCLASS()
class ECHO_PROTOCOL_API AAI_Turret : public AAIControllerBase
{
	GENERATED_BODY()

public:
	AAI_Turret();

	// Взломана ли турель?
	UPROPERTY(BlueprintReadOnly, Category = "AI_Turret")
	bool bIsHacked = false;

	// Работает на игрока?
	UPROPERTY(BlueprintReadOnly, Category = "AI_Turret")
	bool bWorksForPlayer = false;

	// Функции
	UFUNCTION(BlueprintCallable, Category = "AI_Turret")
	void HackTurret();

	UFUNCTION(BlueprintCallable, Category = "AI_Turret")
	void TurnToPlayer();

protected:
	virtual void BeginPlay() override;
};
