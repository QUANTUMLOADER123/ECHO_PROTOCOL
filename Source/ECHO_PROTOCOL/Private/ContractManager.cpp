// Fill out your copyright notice in the Description page of Project Settings.

#include "ContractManager.h"

UContractManager::UContractManager()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UContractManager::BeginPlay()
{
	Super::BeginPlay();
}

void UContractManager::SelectContract(TSubclassOf<AContractBase> ContractClass)
{
	if (!ContractClass) return;

	FActorSpawnParameters SpawnParams;
	ActiveContract = GetWorld()->SpawnActor<AContractBase>(ContractClass, SpawnParams);
	if (ActiveContract)
	{
		ActiveContract->StartContract();
	}
}

void UContractManager::CompleteActiveContract()
{
	if (ActiveContract && !ActiveContract->bIsCompleted)
	{
		ActiveContract->CompleteContract();
		CompletedContracts.Add(ActiveContract->ContractName);
		ActiveContract = nullptr;
	}
}
