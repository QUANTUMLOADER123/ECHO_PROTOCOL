// Fill out your copyright notice in the Description page of Project Settings.

#include "ExtractionReplication.h"
#include "Net/UnrealNetwork.h"

UExtractionReplication::UExtractionReplication()
{
}

void UExtractionReplication::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps)
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UExtractionReplication, bExtractionActive);
	DOREPLIFETIME(UExtractionReplication, ExtractionLocation);
	DOREPLIFETIME(UExtractionReplication, PlayersExtracted);
}

void UExtractionReplication::ServerActivateExtraction_Implementation(FVector Location)
{
	bExtractionActive = true;
	ExtractionLocation = Location;
}

bool UExtractionReplication::ServerActivateExtraction_Validate(FVector Location)
{
	return true;
}

void UExtractionReplication::ServerPlayerExtracted_Implementation()
{
	PlayersExtracted++;
}

bool UExtractionReplication::ServerPlayerExtracted_Validate()
{
	return true;
}
