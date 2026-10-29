// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h>
#include "GameFramework/GameModeBase.h>
#include "EchoGameModeBase.generated.h"

/**
 * Гейммод ECHO PROTOCOL.
 */
UCLASS()
class ECHO_PROTOCOL_API AEchoGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	AEchoGameModeBase();

	// Функции
	UFUNCTION(BlueprintCallable, Category = "Game")
	void RestartMission();

	UFUNCTION(BlueprintCallable, Category = "Game")
	void ExtractPlayer(bool bSuccess);

protected:
	virtual void BeginPlay() override;
};
