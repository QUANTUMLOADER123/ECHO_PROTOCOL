// Fill out your copyright notice in the Description page of Project Settings.

#include "SpawnManager.h"

USpawnManager::USpawnManager()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void USpawnManager::BeginPlay()
{
	Super::BeginPlay();
}

void USpawnManager::RegisterSpawnPoint(ASpawnPoint* Point)
{
	if (Point)
	{
		SpawnPoints.Add(Point);
	}
}

TArray<ASpawnPoint*> USpawnManager::GetSpawnPointsByType(FName Type)
{
	TArray<ASpawnPoint*> Result;
	for (ASpawnPoint* Point : SpawnPoints)
	{
		if (Point && Point->SpawnType == Type)
		{
			Result.Add(Point);
		}
	}
	return Result;
}
