// Fill out your copyright notice in the Description page of Project Settings.

#include "ReputationSystem.h"

UReputationSystem::UReputationSystem()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UReputationSystem::BeginPlay()
{
	Super::BeginPlay();

	// Заполнение порогов по умолчанию, если не заданы
	if (ReputationThresholds.Num() == 0)
	{
		ReputationThresholds.Add(100);
		ReputationThresholds.Add(500);
		ReputationThresholds.Add(1000);
		ReputationThresholds.Add(2500);
		ReputationThresholds.Add(5000);
		ReputationThresholds.Add(10000);
		ReputationThresholds.Add(20000);
		ReputationThresholds.Add(40000);
		ReputationThresholds.Add(80000);
	}

	UpdateReputationLevel();
}

void UReputationSystem::AddReputation(int32 Amount)
{
	Reputation += Amount;
	UpdateReputationLevel();
}

float UReputationSystem::GetReputationPercent() const
{
	if (ReputationLevel >= ReputationThresholds.Num() + 1)
	{
		return 1.0f;
	}

	int32 CurrentThreshold = (ReputationLevel > 0) ? ReputationThresholds[ReputationLevel - 1] : 0;
	int32 NextThreshold = (ReputationLevel <= ReputationThresholds.Num()) ? ReputationThresholds[ReputationLevel] : ReputationThresholds.Last();

	if (NextThreshold == CurrentThreshold) return 1.0f;

	return FMath::GetMappedRangeValueClamped(
		FVector2D(CurrentThreshold, NextThreshold),
		FVector2D(0.0f, 1.0f),
		Reputation
	);
}

void UReputationSystem::UpdateReputationLevel()
{
	int32 NewLevel = 1;
	for (int32 Threshold : ReputationThresholds)
	{
		if (Reputation >= Threshold)
		{
			NewLevel++;
		}
		else
		{
			break;
		}
	}
	ReputationLevel = FMath::Clamp(NewLevel, 1, 10);
}
