// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h>
#include "Components/ActorComponent.h>
#include "EchoNetworkComponent.generated.h"

/**
 * Сетевой компонент для кооператива до 4 игроков (PvE).
 * Host-authoritative, Steam Networking / UE Replication.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ECHO_PROTOCOL_API UEchoNetworkComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UEchoNetworkComponent();

	// Является ли этот игрок хостом
	UPROPERTY(BlueprintReadOnly, Category = "Network")
	bool bIsHost = false;

	// Количество подключённых игроков
	UPROPERTY(BlueprintReadOnly, Category = "Network")
	int32 ConnectedPlayers = 1;

	// Максимум игроков
	UPROPERTY(EditDefaultsOnly, Category = "Network")
	int32 MaxPlayers = 4;

	// ID сессии
	UPROPERTY(BlueprintReadOnly, Category = "Network")
	FString SessionID;

	// Функции
	UFUNCTION(BlueprintCallable, Category = "Network")
	void HostSession();

	UFUNCTION(BlueprintCallable, Category = "Network")
	void JoinSession(FString SessionName);

	UFUNCTION(BlueprintCallable, Category = "Network")
	void LeaveSession();

	UFUNCTION(BlueprintCallable, Category = "Network")
	bool IsHost() const { return bIsHost; }

protected:
	virtual void BeginPlay() override;
};
