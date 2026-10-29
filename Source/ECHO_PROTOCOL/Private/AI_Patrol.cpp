// Fill out your copyright notice в Description page of Project Settings.

#include "AI_Patrol.h"

AAI_Patrol::AAI_Patrol()
{
}

void AAI_Patrol::BeginPlay()
{
	Super::BeginPlay();
}

void AAI_Patrol::FollowRoute()
{
	// Движение по точкам патруля через NavMesh
}

void AAI_Patrol::InvestigateNoise(FVector NoiseLocation)
{
	LastKnownPlayerLocation = NoiseLocation;
	AIState = EAIOption::Investigate;
}

void AAI_Patrol::CallReinforcements()
{
	// Вызов дополнительных патрулей
}
