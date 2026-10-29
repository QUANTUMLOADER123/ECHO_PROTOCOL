// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EchoLayerComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FEchoStateChanged);

/**
 * Компонент переключения между материальным слоем и слоем ЭХО.
 * Заряд + кулдаун, визуальные эффекты, ослабление оружия в Эхо-слое.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ECHO_PROTOCOL_API UEchoLayerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UEchoLayerComponent();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Текущий слой
	UPROPERTY(BlueprintReadOnly, Category = "Echo")
	bool bIsEchoLayer = false;

	// Заряд Эхо-слоя (0.0 - 1.0)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Echo")
	float EchoCharge = 1.0f;

	// Максимальный заряд
	UPROPERTY(EditDefaultsOnly, Category = "Echo")
	float MaxEchoCharge = 1.0f;

	// Скорость восстановления заряда в секунду
	UPROPERTY(EditDefaultsOnly, Category = "Echo")
	float ChargeRecoveryRate = 0.25f;

	// Скорость разряда заряда в секунду при нахождении в Эхо-слое
	UPROPERTY(EditDefaultsOnly, Category = "Echo")
	float ChargeDrainRate = 0.5f;

	// Кулдаун перед восстановлением после полного разряда
	UPROPERTY(EditDefaultsOnly, Category = "Echo")
	float RechargeCooldown = 2.0f;

	// Коэффициент урона оружия в Эхо-слое (0.0 - 1.0)
	UPROPERTY(EditDefaultsOnly, Category = "Echo")
	float WeaponDamageMultiplier = 0.5f;

	// Событие смены слоя
	UPROPERTY(BlueprintAssignable)
	FEchoStateChanged OnEchoStateChanged;

	// Функции
	UFUNCTION(BlueprintCallable, Category = "Echo")
	void ToggleEchoLayer();

	UFUNCTION(BlueprintCallable, Category = "Echo")
	bool IsInEchoLayer() const { return bIsEchoLayer; }

	UFUNCTION(BlueprintCallable, Category = "Echo")
	float GetEchoChargePercent() const { return FMath::Clamp(EchoCharge / MaxEchoCharge, 0.0f, 1.0f); }

	UFUNCTION(BlueprintCallable, Category = "Echo")
	float GetWeaponDamageMultiplier() const;

protected:
	virtual void BeginPlay() override;

private:
	float CooldownTimer = 0.0f;
	bool bCanRecharge = true;
};
