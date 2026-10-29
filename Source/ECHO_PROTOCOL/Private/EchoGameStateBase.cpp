// Fill out your copyright notice in the Description page of Project Settings.

#include "EchoGameStateBase.h"

AEchoGameStateBase::AEchoGameStateBase()
{
}

void AEchoGameStateBase::SetActiveContract(FString ContractName)
{
	ActiveContract = ContractName;
	ContractProgress = 0.0f;
}

void AEchoGameStateBase::AddContractProgress(float Amount)
{
	ContractProgress = FMath::Clamp(ContractProgress + Amount, 0.0f, 1.0f);
}

void AEchoGameStateBase::AddCredits(int32 Amount)
{
	Credits += Amount;
}

void AEchoGameStateBase::AddReputation(int32 Amount)
{
	Reputation += Amount;
}
