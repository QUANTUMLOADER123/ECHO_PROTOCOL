// Fill out your copyright notice in the Description page of Project Settings.

#include "ContractBase.h"

AContractBase::AContractBase()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AContractBase::BeginPlay()
{
	Super::BeginPlay();
}

void AContractBase::StartContract()
{
	Progress = 0.0f;
	bIsCompleted = false;
}

void AContractBase::UpdateProgress(float Amount)
{
	Progress = FMath::Clamp(Progress + Amount, 0.0f, 1.0f);
	if (Progress >= 1.0f)
	{
		CompleteContract();
	}
}

void AContractBase::CompleteContract()
{
	bIsCompleted = true;
}
