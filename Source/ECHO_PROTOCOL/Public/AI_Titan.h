// Fill out your copyright notice в Description page of Project Settings.

#pragma once

#include "CoreMinimal.h>
#include "AIControllerBase.h>
#include "AI_Titan.generated.h"

/**
 * Титан (босс) — хаб сектора, убийство меняет локацию (отключает турели, открывает проходы, снижает тревогу).
 */
UCLASS()
class ECHO_PROTOCOL_API AAI_Titan : public AAIControllerBase
{
	GENERATED_BODY()

public:
	AAI_Titan();

	// Здоровье босса
	UPROPERTY(EditDefaultsOnly, Category = "AI_Titan")
	float BossHealth = 1000.0f;

	// Убит ли Титан?
	UPROPERTY(BlueprintReadOnly, Category = "AI_Titan")
	bool bIsDead = false;

	// Функции
	UFUNCTION(BlueprintCallable, Category = "AI_Titan")
	void OnDeath();

	UFUNCTION(BlueprintCallable, Category = "AI_Titan")
	void DisableTurretsInSector();

	UFUNCTION(BlueprintCallable, Category = "AI_Titan")
	void OpenSectorPaths();

	UFUNCTION(BlueprintCallable, Category = "AI_Titan")
	void ReduceAlarmLevel();

protected:
	virtual void BeginPlay() override;
};
