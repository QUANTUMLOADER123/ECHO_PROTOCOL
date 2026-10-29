// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseHubManager.h"

UBaseHubManager::UBaseHubManager()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UBaseHubManager::BeginPlay()
{
	Super::BeginPlay();
	UnlockedFacilities.Add(EBaseFacility::Workbench);
	UnlockedFacilities.Add(EBaseFacility::Armory);
}

void UBaseHubManager::UpgradeFacility(EBaseFacility Facility)
{
	switch (Facility)
	{
		case EBaseFacility::Workbench: WorkbenchLevel++; break;
		case EBaseFacility::MedBay: MedBayLevel++; break;
		case EBaseFacility::Archive: ArchiveLevel++; break;
		case EBaseFacility::Armory: ArmoryLevel++; break;
	}
}

bool UBaseHubManager::IsFacilityUnlocked(EBaseFacility Facility) const
{
	return UnlockedFacilities.Contains(Facility);
}

int32 UBaseHubManager::GetFacilityLevel(EBaseFacility Facility) const
{
	switch (Facility)
	{
		case EBaseFacility::Workbench: return WorkbenchLevel;
		case EBaseFacility::MedBay: return MedBayLevel;
		case EBaseFacility::Archive: return ArchiveLevel;
		case EBaseFacility::Armory: return ArmoryLevel;
		default: return 0;
	}
}
