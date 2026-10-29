// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Terminal.generated.h"

UENUM(BlueprintType)
enum class ETerminalState : uint8
{
	Locked    UMETA(DisplayName = "Locked"),
	Hacked    UMETA(DisplayName = "Hacked"),
	Active    UMETA(DisplayName = "Active")
};

UCLASS()
class ECHO_PROTOCOL_API ATerminal : public AActor
{
	GENERATED_BODY()

public:
	ATerminal();

	// Состояние терминала
	UPROPERTY(BlueprintReadOnly, Category = "Terminal")
	ETerminalState TerminalState = ETerminalState::Locked;

	// Требуется ли взлом?
	UPROPERTY(EditDefaultsOnly, Category = "Terminal")
	bool bRequiresHack = true;

	// Время взлома
	UPROPERTY(EditDefaultsOnly, Category = "Terminal")
	float HackTime = 3.0f;

	// Данные на терминале
	UPROPERTY(EditDefaultsOnly, Category = "Terminal")
	FString TerminalData;

	// Функции
	UFUNCTION(BlueprintCallable, Category = "Terminal")
	void Hack();

	UFUNCTION(BlueprintCallable, Category = "Terminal")
	void AccessData();

protected:
	virtual void BeginPlay() override;
};
