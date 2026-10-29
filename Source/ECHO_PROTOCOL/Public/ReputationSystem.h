// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h>
#include "Components/ActorComponent.h>
#include "ReputationSystem.generated.h"

/**
 * Система репутации — открывает новые контракты, скидки у торговцев.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ECHO_PROTOCOL_API UReputationSystem : public UActorComponent
{
	GENERATED_BODY()

public:
	UReputationSystem();

	// Текущая репутация
	UPROPERTY(BlueprintReadOnly, Category = "Reputation")
	int32 Reputation = 0;

	// Уровень репутации (1-10)
	UPROPERTY(BlueprintReadOnly, Category = "Reputation")
	int32 ReputationLevel = 1;

	// Пороги уровней
	UPROPERTY(EditDefaultsOnly, Category = "Reputation")
	TArray<int32> ReputationThresholds; // [100, 500, 1000, 2500, 5000, 10000, 20000, 40000, 80000]

	// Функции
	UFUNCTION(BlueprintCallable, Category = "Reputation")
	void AddReputation(int32 Amount);

	UFUNCTION(BlueprintCallable, Category = "Reputation")
	int32 GetReputationLevel() const { return ReputationLevel; }

	UFUNCTION(BlueprintCallable, Category = "Reputation")
	float GetReputationPercent() const;

protected:
	virtual void BeginPlay() override;

private:
	void UpdateReputationLevel();
};
