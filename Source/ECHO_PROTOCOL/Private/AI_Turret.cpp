// Fill out your copyright notice в Description page of Project Settings.

#include "AI_Turret.h"

AAI_Turret::AAI_Turret()
{
}

void AAI_Turret::BeginPlay()
{
	Super::BeginPlay();
}

void AAI_Turret::HackTurret()
{
	bIsHacked = true;
	bWorksForPlayer = true;
}

void AAI_Turret::TurnToPlayer()
{
	// Турель начинает стрелять в врагов
}
