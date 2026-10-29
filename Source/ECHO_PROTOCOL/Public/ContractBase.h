// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h>
#include "GameFramework/Actor.h"
#include "ContractBase.generated.h"

UENUM(BlueprintType)
enum class EContractType : uint8
{
	Recon     UMETA(DisplayName = "Recon"),
	Sabotage  UMETA(DisplayName = "Sabotage"),
	Rescue    UMETA(DisplayName = "Rescue")
};

UCLASS()
class ECHO_PROTOCOL_API AContractBase : public AActor
{
	GENERATED_BODY()

public:
	AContractBase();

	// Тип контракта
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Contract")
	EContractType ContractType;

	// Название
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Contract")
	FString ContractName;

	// Описание / брифинг
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Contract")
	FString Briefing;

	// Локация контракта
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Contract")
	FString Location;

	// Награда
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Contract")
	int32 CreditReward = 0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Contract")
	int32 ReputationReward = 0;

	// Прогресс (0.0 - 1.0)
	UPROPERTY(BlueprintReadOnly, Category = "Contract")
	float Progress = 0.0f;

	// Завершен?
	UPROPERTY(BlueprintReadOnly, Category = "Contract")
	bool bIsCompleted = false;

	// Функции
	UFUNCTION(BlueprintCallable, Category = "Contract")
	void StartContract();

	UFUNCTION(BlueprintCallable, Category = "Contract")
	void UpdateProgress(float Amount);

	UFUNCTION(BlueprintCallable, Category = "Contract")
	void CompleteContract();

protected:
	virtual void BeginPlay() override;
};
