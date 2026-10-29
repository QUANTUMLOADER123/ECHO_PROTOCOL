// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Corpse.generated.h"

/**
 * Тело врага или NPC — можно обыскать на лут и ключ-карту.
 */
UCLASS()
class ECHO_PROTOCOL_API ACorpse : public AActor
{
	GENERATED_BODY()

public:
	ACorpse();

	// Уже обыскано?
	UPROPERTY(BlueprintReadOnly, Category = "Corpse")
	bool bIsLooted = false;

	// Лут на теле
	UPROPERTY(EditDefaultsOnly, Category = "Corpse")
	TArray<FString> ItemsOnCorpse;

	// Есть ли ключ-карта
	UPROPERTY(EditDefaultsOnly, Category = "Corpse")
	bool bHasKeycard = false;

	// Функции
	UFUNCTION(BlueprintCallable, Category = "Corpse")
	void LootCorpse();

protected:
	virtual void BeginPlay() override;
};
