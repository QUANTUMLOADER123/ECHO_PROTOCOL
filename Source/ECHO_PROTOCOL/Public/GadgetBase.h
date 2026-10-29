// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GadgetBase.generated.h"

UENUM(BlueprintType)
enum class EGadgetType : uint8
{
	EchoScanner       UMETA(DisplayName = "Echo Scanner"),
	SensorJammer      UMETA(DisplayName = "Sensor Jammer"),
	ReconDrone        UMETA(DisplayName = "Recon Drone"),
	RealityAnchor     UMETA(DisplayName = "Reality Anchor"),
	FalseSignal       UMETA(DisplayName = "False Signal"),
	HackerTool        UMETA(DisplayName = "Hacker Tool"),
	Medkit            UMETA(DisplayName = "Medkit"),
	Stimulant         UMETA(DisplayName = "Stimulant")
};

UCLASS()
class ECHO_PROTOCOL_API AGadgetBase : public AActor
{
	GENERATED_BODY()

public:
	AGadgetBase();

	// Тип гаджета
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Gadget")
	EGadgetType GadgetType;

	// Количество зарядов
	UPROPERTY(BlueprintReadWrite, Category = "Gadget")
	int32 Charges = 1;

	// Максимальное количество зарядов
	UPROPERTY(EditDefaultsOnly, Category = "Gadget")
	int32 MaxCharges = 1;

	// Время перезарядки одного заряда (секунды)
	UPROPERTY(EditDefaultsOnly, Category = "Gadget")
	float RechargeTime = 10.0f;

	// Активен ли гаджет сейчас
	UPROPERTY(BlueprintReadOnly, Category = "Gadget")
	bool bIsActive = false;

	// Функции
	UFUNCTION(BlueprintCallable, Category = "Gadget")
	bool Use();

	UFUNCTION(BlueprintCallable, Category = "Gadget")
	void Recharge();

	UFUNCTION(BlueprintCallable, Category = "Gadget")
	bool HasCharges() const { return Charges > 0; }

protected:
	virtual void BeginPlay() override;

private:
	float RechargeTimer = 0.0f;
};
