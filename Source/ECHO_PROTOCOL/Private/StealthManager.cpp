// Fill out your copyright notice in the Description page of Project Settings.

#include "StealthManager.h"
#include "GameFramework/CharacterMovementComponent.h"

UStealthManager::UStealthManager()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UStealthManager::BeginPlay()
{
	Super::BeginPlay();
}

void UStealthManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Соскладываем шум со временем
	if (CurrentNoiseLevel > 0.0f)
	{
		CurrentNoiseLevel = FMath::FInterpTo(CurrentNoiseLevel, 0.0f, DeltaTime, 5.0f);
	}

	// Таймер маскировки
	if (bIsDisguised && DisguiseTimeRemaining > 0.0f)
	{
		DisguiseTimeRemaining -= DeltaTime;
		if (DisguiseTimeRemaining <= 0.0f)
		{
			bIsDisguised = false;
			DisguiseTimeRemaining = 0.0f;
		}
	}

	// Скольжение
	if (bIsSliding && SlideTimer > 0.0f)
	{
		SlideTimer -= DeltaTime;
		if (SlideTimer <= 0.0f)
		{
			bIsSliding = false;
		}
	}
}

void UStealthManager::SetCrouch(bool Value)
{
	bIsCrouching = Value;
	if (Value) bIsProne = false;
}

void UStealthManager::SetProne(bool Value)
{
	bIsProne = Value;
	if (Value) bIsCrouching = false;
}

void UStealthManager::StartSlide()
{
	bIsSliding = true;
	SlideTimer = SlideDuration;
}

void UStealthManager::SetDisguise(float DurationSeconds)
{
	bIsDisguised = true;
	DisguiseTimeRemaining = DurationSeconds;
}

void UStealthManager::MakeNoise(float Amount)
{
	CurrentNoiseLevel = FMath::Clamp(CurrentNoiseLevel + Amount, 0.0f, 1.0f);
}

float UStealthManager::GetNoiseLevel() const
{
	return CurrentNoiseLevel;
}

bool UStealthManager::IsHiddenFromAI() const
{
	return bIsDisguised || (CurrentNoiseLevel <= 0.0f && (bIsCrouching || bIsProne));
}
