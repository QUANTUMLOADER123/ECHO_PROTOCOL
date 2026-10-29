// Fill out your copyright notice in the Description page of Project Settings.

#include "EchoSaveSystem.h"
#include "Kismet/GameplayStatics.h"

UEchoSaveSystem::UEchoSaveSystem()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UEchoSaveSystem::BeginPlay()
{
	Super::BeginPlay();
}

void UEchoSaveSystem::SaveGame(USaveGameEcho* SaveData)
{
	if (SaveData)
	{
		UGameplayStatics::SaveGameToSlot(SaveData, SaveSlotName, UserIndex);
	}
}

USaveGameEcho* UEchoSaveSystem::LoadGame()
{
	if (DoesSaveExist())
	{
		return Cast<USaveGameEcho>(UGameplayStatics::LoadGameFromSlot(SaveSlotName, UserIndex));
	}
	return nullptr;
}

bool UEchoSaveSystem::DoesSaveExist()
{
	return UGameplayStatics::DoesSaveGameExist(SaveSlotName, UserIndex);
}

void UEchoSaveSystem::DeleteSave()
{
	if (DoesSaveExist())
	{
		UGameplayStatics::DeleteGameInSlot(SaveSlotName, UserIndex);
	}
}
