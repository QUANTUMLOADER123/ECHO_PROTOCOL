// Fill out your copyright notice в Description page of Project Settings.

#include "AI_Drone.h"

AAI_Drone::AAI_Drone()
{
}

void AAI_Drone::BeginPlay()
{
	Super::BeginPlay();
}

void AAI_Drone::ScanArea()
{
	// Сканирование области на наличие игрока
}

void AAI_Drone::ChangeRoute()
{
	// Адаптивная смена маршрута
}

void AAI_Drone::TakeEMIDamage(float Amount)
{
	if (bVulnerableToEMI)
	{
		// Дрон выходит из строя
	}
}
