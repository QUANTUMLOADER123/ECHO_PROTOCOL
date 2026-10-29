// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ExtractionPoint.generated.h"

UCLASS()
class ECHO_PROTOCOL_API AExtractionPoint : public AActor
{
	GENERATED_BODY()

public:
	AExtractionPoint();

	// Активна ли точка эвакуации
	UPROPERTY(BlueprintReadOnly, Category = "Extraction")
	bool bIsActive = false;

	// Текущий уровень тревоги, который влияет на_distance_ до точки
	UPROPERTY(BlueprintReadOnly, Category = "Extraction")
	float CurrentAlarmLevel = 0.0f;

	// Минимальная дистанция от игрока до точки при низкой тревоге
	UPROPERTY(EditDefaultsOnly, Category = "Extraction")
	float MinDistanceFromPlayer = 800.0f;

	// Максимальная дистанция при высокой тревоге
	UPROPERTY(EditDefaultsOnly, Category = "Extraction")
	float MaxDistanceFromPlayer = 2500.0f;

	// Функции
	UFUNCTION(BlueprintCallable, Category = "Extraction")
	void Activate(float AlarmLevel);

	UFUNCTION(BlueprintCallable, Category = "Extraction")
	void Deactivate();

	UFUNCTION(BlueprintCallable, Category = "Extraction")
	bool IsActive() const { return bIsActive; }

	UFUNCTION(BlueprintCallable, Category = "Extraction")
	float GetDistanceFromPlayer() const;

protected:
	virtual void BeginPlay() override;

private:
	FVector BaseLocation;
};
