// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h>
#include "Components/ActorComponent.h>
#include "AlarmReplication.generated.h"

/**
 * Репликация шкалы тревоги между игроками в коопе.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ECHO_PROTOCOL_API UAlarmReplication : public UActorComponent
{
	GENERATED_BODY()

public:
	UAlarmReplication();

	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Alarm")
	float GlobalAlarmLevel = 0.0f;

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "Alarm")
	void ServerAddAlarm(float Amount);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "Alarm")
	void ServerSetAlarm(float NewLevel);

protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) override;
};
