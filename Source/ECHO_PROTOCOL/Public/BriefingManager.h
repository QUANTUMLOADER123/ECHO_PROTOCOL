// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h>
#include "Components/ActorComponent.h>
#include "BriefingData.h>
#include "BriefingManager.generated.h"

/**
 * Менеджер брифингов — загрузка данных контракта перед миссией.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ECHO_PROTOCOL_API UBriefingManager : public UActorComponent
{
	GENERATED_BODY()

public:
	UBriefingManager();

	// Данные текущего брифинга
	UPROPERTY(BlueprintReadOnly, Category = "Briefing")
	FBriefingData CurrentBriefing;

	// Все доступные брифинги
	UPROPERTY(EditDefaultsOnly, Category = "Briefing")
	TArray<FBriefingData> AllBriefings;

	// Функции
	UFUNCTION(BlueprintCallable, Category = "Briefing")
	void LoadBriefing(FString ContractName);

	UFUNCTION(BlueprintCallable, Category = "Briefing")
	FBriefingData GetCurrentBriefing() const { return CurrentBriefing; }

protected:
	virtual void BeginPlay() override;
};
