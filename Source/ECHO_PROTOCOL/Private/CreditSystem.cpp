// Fill out your copyright notice in the Description page of Project Settings.

#include "CreditSystem.h"

UCreditSystem::UCreditSystem()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UCreditSystem::BeginPlay()
{
	Super::BeginPlay();
}

void UCreditSystem::AddCredits(int32 Amount)
{
	Credits += Amount;
}

bool UCreditSystem::SpendCredits(int32 Amount)
{
	if (Credits >= Amount)
	{
		Credits -= Amount;
		return true;
	}
	return false;
}
