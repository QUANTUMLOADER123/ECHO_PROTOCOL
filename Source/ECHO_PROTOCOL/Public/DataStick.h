// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LootItemBase.h"
#include "DataStick.generated.h"

/**
 * Флешка с данными — цель контракта разведки.
 */
UCLASS()
class ECHO_PROTOCOL_API ADataStick : public ALootItemBase
{
	GENERATED_BODY()

public:
	ADataStick();

	// Какие данные на флешке
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "DataStick")
	FString DataContent;

	// Требуется ли взлом для чтения?
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "DataStick")
	bool bRequiresHack = false;

	// Функции
	UFUNCTION(BlueprintCallable, Category = "DataStick")
	void ReadData();

protected:
	virtual void BeginPlay() override;
};
