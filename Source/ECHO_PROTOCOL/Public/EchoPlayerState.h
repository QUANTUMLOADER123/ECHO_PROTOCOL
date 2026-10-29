// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h>
#include "GameFramework/PlayerState.h>
#include "EchoPlayerState.generated.h"

/**
 * Состояние игрока: здоровье, бронь, тревога, Э호-заряд.
 */
UCLASS()
class ECHO_PROTOCOL_API AEchoPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	AEchoPlayerState();

	// Здоровье (0-100)
	UPROPERTY(BlueprintReadOnly, Category = "Player")
	float Health = 100.0f;

	// Броня (0-100)
	UPROPERTY(BlueprintReadOnly, Category = "Player")
	float Armor = 0.0f;

	// Текущий уровень тревоги
	UPROPERTY(BlueprintReadOnly, Category = "Player")
	float AlarmLevel = 0.0f;

	// Функции
	UFUNCTION(BlueprintCallable, Category = "Player")
	void TakeDamage(float DamageAmount);

	UFUNCTION(BlueprintCallable, Category = "Player")
	void Heal(float Amount);

protected:
	virtual void BeginPlay() override;
};
