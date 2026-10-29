// Fill out your copyright notice in the Description page of Project Settings.

#include "BriefingManager.h"

UBriefingManager::UBriefingManager()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UBriefingManager::BeginPlay()
{
	Super::BeginPlay();
}

void UBriefingManager::LoadBriefing(FString ContractName)
{
	for (const FBriefingData& Briefing : AllBriefings)
	{
		if (Briefing.ContractName == ContractName)
		{
			CurrentBriefing = Briefing;
			return;
		}
	}
}
