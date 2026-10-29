// Fill out your copyright notice in the Description page of Project Settings.

#include "EchoLayerComponent.h"

UEchoLayerComponent::UEchoLayerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UEchoLayerComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UEchoLayerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (bIsEchoLayer)
	{
		// Разряд заряда в Эхо-слое
		EchoCharge = FMath::FInterpTo(EchoCharge, 0.0f, DeltaTime, ChargeDrainRate);

		if (EchoCharge <= 0.0f)
		{
			// Принудительный выход из Эхо-слоя при разряде
			bIsEchoLayer = false;
			EchoCharge = 0.0f;
			bCanRecharge = false;
			CooldownTimer = RechargeCooldown;
			OnEchoStateChanged.Broadcast();
		}
	}
	else
	{
		// Кулдаун перед восстановлением
		if (!bCanRecharge)
		{
			CooldownTimer -= DeltaTime;
			if (CooldownTimer <= 0.0f)
			{
				bCanRecharge = true;
			}
		}
		else
		{
			// Восстановление заряда
			EchoCharge = FMath::FInterpTo(EchoCharge, MaxEchoCharge, DeltaTime, ChargeRecoveryRate);
		}
	}
}

void UEchoLayerComponent::ToggleEchoLayer()
{
	if (bIsEchoLayer)
	{
		// Выход из Эхо-слоя
		bIsEchoLayer = false;
		bCanRecharge = true;
		CooldownTimer = 0.0f;
		OnEchoStateChanged.Broadcast();
	}
	else
	{
		// Вход в Эхо-слое, если есть заряд
		if (EchoCharge > 0.05f && bCanRecharge)
		{
			bIsEchoLayer = true;
			OnEchoStateChanged.Broadcast();
		}
	}
}

float UEchoLayerComponent::GetWeaponDamageMultiplier() const
{
	return bIsEchoLayer ? WeaponDamageMultiplier : 1.0f;
}
