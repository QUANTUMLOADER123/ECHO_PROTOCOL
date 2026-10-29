// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GadgetBase.h"
#include "EchoScanner.generated.h"

/**
 * Сканер Эхо — подсветка врагов сквозь стены (заряды).
 */
UCLASS()
class ECHO_PROTOCOL_API AEchoScanner : public AGadgetBase
{
	GENERATED_BODY()

public:
	AEchoScanner();

	// Радиус сканирования
	UPROPERTY(EditDefaultsOnly, Category = "EchoScanner")
	float ScanRadius = 1500.0f;

	// Длительность подсветки врагов (секунды)
	UPROPERTY(EditDefaultsOnly, Category = "EchoScanner")
	float HighlightDuration = 5.0f;

	// Функции
	UFUNCTION(BlueprintCallable, Category = "EchoScanner")
	void ScanForEnemies();

protected:
	virtual void BeginPlay() override;
};
