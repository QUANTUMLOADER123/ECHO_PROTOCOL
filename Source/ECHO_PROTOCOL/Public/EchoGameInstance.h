// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h>
#include "Engine/GameInstance.h>
#include "EchoGameInstance.generated.h"

/**
 * Игровой экземпляр: сохранения между сессиями, базовые настройки.
 */
UCLASS()
class ECHO_PROTOCOL_API UEchoGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UEchoGameInstance();

	// Функции сохранения/загрузки
	UFUNCTION(BlueprintCallable, Category = "Save")
	void SaveGame();

	UFUNCTION(BlueprintCallable, Category = "Save")
	void LoadGame();

protected:
	virtual void OnStart() override;
};
