// Fill out your copyright notice in the Description page of Project Settings.

#include "SpawnPoint.h"

ASpawnPoint::ASpawnPoint()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ASpawnPoint::BeginPlay()
{
	Super::BeginPlay();
}

void ASpawnPoint::Activate()
{
	bIsActive = true;
}

void ASpawnPoint::Deactivate()
{
	bIsActive = false;
}
