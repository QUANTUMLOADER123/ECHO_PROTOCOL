// Fill out your copyright notice in the Description page of Project Settings.

#include "AIControllerBase.h"

AAIControllerBase::AAIControllerBase()
{
}

void AAIControllerBase::BeginPlay()
{
	Super::BeginPlay();
	AIState = EAIOption::Patrol;
}

void AAIControllerBase::SetAlertState(bool bAlerted)
{
	AIState = bAlerted ? EAIOption::Combat : EAIOption::Patrol;
}

void AAIControllerBase::SetLastKnownPlayerLocation(FVector Location)
{
	LastKnownPlayerLocation = Location;
}
