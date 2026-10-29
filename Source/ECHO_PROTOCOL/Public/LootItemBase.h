// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LootItemBase.generated.h"

UENUM(BlueprintType)
enum class ELootType : uint8
{
	DataStick   UMETA(DisplayName = "Data Stick"),
	Terminal    UMETA(DisplayName = "Terminal"),
	Corpse      UMETA(DisplayName = "Corpse"),
	Keycard     UMETA(DisplayName = "Keycard"),
	Document    UMETA(DisplayName = "Document"),
	Credits     UMETA(DisplayName = "Credits"),
	Blueprint   UMETA(DisplayName = "Blueprint")
};

UCLASS()
class ECHO_PROTOCOL_API ALootItemBase : public AActor
{
	GENERATED_BODY()

public:
	ALootItemBase();

	// Тип лута
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Loot")
	ELootType LootType;

	// Название предмета
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Loot")
	FString ItemName;

	// Описание
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Loot")
	FString Description;

	// Стоимость в кредитах
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Loot")
	int32 CreditValue = 0;

	// Можно ли подобрать
	UPROPERTY(EditDefaultsOnly, Category = "Loot")
	bool bCanPickup = true;

	// Функции
	UFUNCTION(BlueprintCallable, Category = "Loot")
	void OnPickedUp();

protected:
	virtual void BeginPlay() override;
};
