// Fill out your copyright notice in the Description page of Project Settings.

#include "AlarmReplication.h"
#include "Net/UnrealNetwork.h"

UAlarmReplication::UAlarmReplication()
{
}

void UAlarmReplication::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps)
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UAlarmReplication, GlobalAlarmLevel);
}

void UAlarmReplication::ServerAddAlarm_Implementation(float Amount)
{
	GlobalAlarmLevel = FMath::Clamp(GlobalAlarmLevel + Amount, 0.0f, 100.0f);
}

bool UAlarmReplication::ServerAddAlarm_Validate(float Amount)
{
	return true;
}

void UAlarmReplication::ServerSetAlarm_Implementation(float NewLevel)
{
	GlobalAlarmLevel = FMath::Clamp(NewLevel, 0.0f, 100.0f);
}

bool UAlarmReplication::ServerSetAlarm_Validate(float NewLevel)
{
	return true;
}
