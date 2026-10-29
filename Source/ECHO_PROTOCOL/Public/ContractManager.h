// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ContractBase.h"
#include "ContractManager.generated.h"

/**
 * Менеджер контрактов: выбор, отслеживание прогресса, награды.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ECHO_PROTOCOL_API UContractManager : public UActorComponent
{
	GENERATED_BODY()

public:
	UContractManager();

	// Активный контракт
	UPROPERTY(BlueprintReadOnly, Category = "Contracts")
	AContractBase* ActiveContract = nullptr;

	// Доступные контракты (классы)
	UPROPERTY(EditDefaultsOnly, Category = "Contracts")
	TArray<TSubclassOf<AContractBase>> AvailableContracts;

	// История завершенных
	UPROPERTY(BlueprintReadOnly, Category = "Contracts")
	TArray<FString> CompletedContracts;

	// Функции
	UFUNCTION(BlueprintCallable, Category = "Contracts")
	void SelectContract(TSubclassOf<AContractBase> ContractClass);

	UFUNCTION(BlueprintCallable, Category = "Contracts")
	void CompleteActiveContract();

	UFUNCTION(BlueprintCallable, Category = "Contracts")
	AContractBase* GetActiveContract() const { return ActiveContract; }

protected:
	virtual void BeginPlay() override;
};
