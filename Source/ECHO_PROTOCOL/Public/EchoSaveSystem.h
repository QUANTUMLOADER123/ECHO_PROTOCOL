// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h>
#include "Components/ActorComponent.h>
#include "SaveGameEcho.h>
#include "EchoSaveSystem.generated.h"

/**
 * Система сохранений — автосохранение, слоты, экспорт/импорт JSON.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ECHO_PROTOCOL_API UEchoSaveSystem : public UActorComponent
{
	GENERATED_BODY()

public:
	UEchoSaveSystem();

	// Имя слота сохранения
	UPROPERTY(EditDefaultsOnly, Category = "Save")
	FString SaveSlotName = TEXT("EchoSave");

	// Индекс пользователя
	UPROPERTY(EditDefaultsOnly, Category = "Save")
	int32 UserIndex = 0;

	// Функции
	UFUNCTION(BlueprintCallable, Category = "Save")
	void SaveGame(USaveGameEcho* SaveData);

	UFUNCTION(BlueprintCallable, Category = "Save")
	USaveGameEcho* LoadGame();

	UFUNCTION(BlueprintCallable, Category = "Save")
	bool DoesSaveExist();

	UFUNCTION(BlueprintCallable, Category = "Save")
	void DeleteSave();

protected:
	virtual void BeginPlay() override;
};
