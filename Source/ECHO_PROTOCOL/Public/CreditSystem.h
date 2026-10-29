// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h>
#include "Components/ActorComponent.h>
#include "CreditSystem.generated.h"

/**
 * Система кредитов — валюта игры.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ECHO_PROTOCOL_API UCreditSystem : public UActorComponent
{
	GENERATED_BODY()

public:
	UCreditSystem();

	// Текущее количество кредитов
	UPROPERTY(BlueprintReadOnly, Category = "Credits")
	int32 Credits = 500; // стартовые

	// Функции
	UFUNCTION(BlueprintCallable, Category = "Credits")
	void AddCredits(int32 Amount);

	UFUNCTION(BlueprintCallable, Category = "Credits")
	bool SpendCredits(int32 Amount);

	UFUNCTION(BlueprintCallable, Category = "Credits")
	int32 GetCredits() const { return Credits; }

protected:
	virtual void BeginPlay() override;
};
