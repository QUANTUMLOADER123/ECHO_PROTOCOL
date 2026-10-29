// Fill out your copyright notice in the Description page of Project Settings.

#include "PerkTree.h"

UPerkTree::UPerkTree()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UPerkTree::BeginPlay()
{
	Super::BeginPlay();
}

bool UPerkTree::UnlockPerk(EPerkID PerkID)
{
	FPerkEntry* FoundPerk = nullptr;
	for (FPerkEntry& Perk : Perks)
	{
		if (Perk.PerkID == PerkID)
		{
			FoundPerk = &Perk;
			break;
		}
	}

	if (!FoundPerk || FoundPerk->bUnlocked) return false;

	// Проверка предварительных условий
	for (EPerkID PreReq : FoundPerk->Prerequisites)
	{
		if (!IsPerkUnlocked(PreReq)) return false;
	}

	if (Credits < FoundPerk->Cost) return false;

	Credits -= FoundPerk->Cost;
	FoundPerk->bUnlocked = true;
	return true;
}

bool UPerkTree::IsPerkUnlocked(EPerkID PerkID) const
{
	for (const FPerkEntry& Perk : Perks)
	{
		if (Perk.PerkID == PerkID) return Perk.bUnlocked;
	}
	return false;
}

void UPerkTree::AddCredits(int32 Amount)
{
	Credits += Amount;
}
