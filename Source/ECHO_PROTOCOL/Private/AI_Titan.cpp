// Fill out your copyright notice в Description page of Project Settings.

#include "AI_Titan.h"

AAI_Titan::AAI_Titan()
{
}

void AAI_Titan::BeginPlay()
{
	Super::BeginPlay();
}

void AAI_Titan::OnDeath()
{
	bIsDead = true;
	DisableTurretsInSector();
	OpenSectorPaths();
	ReduceAlarmLevel();
}

void AAI_Titan::DisableTurretsInSector()
{
	// Отключить все турели в секторе
}

void AAI_Titan::OpenSectorPaths()
{
	// Открыть новые проходы в локации
}

void AAI_Titan::ReduceAlarmLevel()
{
	// Снизить тревогу на локации
}
