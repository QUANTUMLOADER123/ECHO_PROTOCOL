// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h>
#include "GameFramework/PlayerState.h>
#include "EchoPlayerReplication.generated.h"

/**
 * Состояние игрока с репликацией для кооператива.
 */
UCLASS()
class ECHO_PROTOCOL_API AEchoPlayerReplication : public APlayerState
{
	GENERATED_BODY()

public:
	AEchoPlayerReplication();

	// Здоровье
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Player")
	float Health = 100.0f;

	// Броня
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Player")
	float Armor = 0.0f;

	// В Эхо-слое?
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Player")
	bool bInEchoLayer = false;

	// Заряд Эхо
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Player")
	float EchoCharge = 1.0f;

	// Функции
	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "Player")
	void ServerSetHealth(float NewHealth);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "Player")
	void ServerSetEchoLayer(bool bInEcho);

protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) override;
};
