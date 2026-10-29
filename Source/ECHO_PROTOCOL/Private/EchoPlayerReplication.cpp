// Fill out your copyright notice in the Description page of Project Settings.

#include "EchoPlayerReplication.h"
#include "Net/UnrealNetwork.h"

AEchoPlayerReplication::AEchoPlayerReplication()
{
}

void AEchoPlayerReplication::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps)
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AEchoPlayerReplication, Health);
	DOREPLIFETIME(AEchoPlayerReplication, Armor);
	DOREPLIFETIME(AEchoPlayerReplication, bInEchoLayer);
	DOREPLIFETIME(AEchoPlayerReplication, EchoCharge);
}

void AEchoPlayerReplication::ServerSetHealth_Implementation(float NewHealth)
{
	Health = FMath::Clamp(NewHealth, 0.0f, 100.0f);
}

bool AEchoPlayerReplication::ServerSetHealth_Validate(float NewHealth)
{
	return true;
}

void AEchoPlayerReplication::ServerSetEchoLayer_Implementation(bool bInEcho)
{
	bInEchoLayer = bInEcho;
}

bool AEchoPlayerReplication::ServerSetEchoLayer_Validate(bool bInEcho)
{
	return true;
}
