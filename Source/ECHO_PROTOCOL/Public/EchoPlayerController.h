// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h>
#include "GameFramework/PlayerController.h>
#include "EchoPlayerController.generated.h"

/**
 * Контроллер игрока: ввод, UI, переключение слоев.
 */
UCLASS()
class ECHO_PROTOCOL_API AEchoPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AEchoPlayerController();

	// Функции
	UFUNCTION(BlueprintCallable, Category = "Player")
	void ToggleEchoLayer();

	UFUNCTION(BlueprintCallable, Category = "Player")
	void OpenBriefingMenu();

	UFUNCTION(BlueprintCallable, Category = "Player")
	void OpenHubMenu();

protected:
	virtual void BeginPlay() override;
};
