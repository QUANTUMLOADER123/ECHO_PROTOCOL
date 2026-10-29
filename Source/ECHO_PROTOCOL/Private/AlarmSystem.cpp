// Fill out your copyright notice in the Description page of Project Settings.

#include "AlarmSystem.h"

UAlarmSystem::UAlarmSystem()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UAlarmSystem::BeginPlay()
{
	Super::BeginPlay();
	AlarmLevel = 0.0f;
	bIsLocationLocked = false;
}

void UAlarmSystem::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (AlarmLevel > 0.0f)
	{
		// Естественное затишье
		AlarmLevel = FMath::FInterpTo(AlarmLevel, 0.0f, DeltaTime, DecayRate);
		if (AlarmLevel < 0.1f) AlarmLevel = 0.0f;
	}

	if (AlarmLevel >= LockdownThreshold && !bIsLocationLocked)
	{
		bIsLocationLocked = true;
		OnLocationLocked.Broadcast(AlarmLevel);
	}
	else if (AlarmLevel < LockdownThreshold * 0.5f && bIsLocationLocked)
	{
		bIsLocationLocked = false;
	}
}

void UAlarmSystem::AddAlarm(float Amount)
{
	float OldLevel = AlarmLevel;
	AlarmLevel = FMath::Clamp(AlarmLevel + Amount, 0.0f, LockdownThreshold);
	if (AlarmLevel != OldLevel)
	{
		OnAlarmLevelChanged.Broadcast(AlarmLevel);
	}
}

void UAlarmSystem::ReduceAlarm(float Amount)
{
	float OldLevel = AlarmLevel;
	AlarmLevel = FMath::Clamp(AlarmLevel - Amount, 0.0f, LockdownThreshold);
	if (AlarmLevel != OldLevel)
	{
		OnAlarmLevelChanged.Broadcast(AlarmLevel);
	}
}
