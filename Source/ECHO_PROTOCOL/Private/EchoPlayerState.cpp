// Fill out your copyright notice in the Description page of Project Settings.

#include "EchoPlayerState.h"

AEchoPlayerState::AEchoPlayerState()
{
}

void AEchoPlayerState::BeginPlay()
{
	Super::BeginPlay();
}

void AEchoPlayerState::TakeDamage(float DamageAmount)
{
	float ActualDamage = FMath::Max(0.0f, DamageAmount - Armor * 0.5f);
	Health = FMath::Clamp(Health - ActualDamage, 0.0f, 100.0f);
}

void AEchoPlayerState::Heal(float Amount)
{
	Health = FMath::Clamp(Health + Amount, 0.0f, 100.0f);
}
