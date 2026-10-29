// Fill out your copyright notice в Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "EchoGameStateBase.generated.h"

/**
 * Состояние игры: контракты, лут, прогрессия базы, закреплённое снаряжение.
 */
UCLASS()
class ECHO_PROTOCOL_API AEchoGameStateBase : public AGameStateBase
{
	GENERATED_BODY()

public:
	AEchoGameStateBase();

	// Текущий контракт
	UPROPERTY(BlueprintReadOnly, Category = "Game")
	FString ActiveContract;

	// Прогресс контракта (0.0 - 1.0)
	UPROPERTY(BlueprintReadOnly, Category = "Game")
	float ContractProgress = 0.0f;

	// Кредиты игрока
	UPROPERTY(BlueprintReadOnly, Category = "Game")
	int32 Credits = 0;

	// Репутация
	UPROPERTY(BlueprintReadOnly, Category = "Game")
	int32 Reputation = 0;

	// Функции
	UFUNCTION(BlueprintCallable, Category = "Game")
	void SetActiveContract(FString ContractName);

	UFUNCTION(BlueprintCallable, Category = "Game")
	void AddContractProgress(float Amount);

	UFUNCTION(BlueprintCallable, Category = "Game")
	void AddCredits(int32 Amount);

	UFUNCTION(BlueprintCallable, Category = "Game")
	void AddReputation(int32 Amount);
};
