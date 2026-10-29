// Fill out your copyright notice in the Description page of Project Settings.

#include "EchoGameInstance.h"
#include "Kismet/GameplayStatics.h"

UEchoGameInstance::UEchoGameInstance()
{
}

void UEchoGameInstance::OnStart()
{
	Super::OnStart();
}

void UEchoGameInstance::SaveGame()
{
	USaveGameEcho* SaveGameInstance = Cast<USaveGameEcho>(UGameplayStatics::CreateSaveGameObject(USaveGameEcho::StaticClass()));
	if (SaveGameInstance)
	{
		UGameplayStatics::SaveGameToSlot(SaveGameInstance, SaveGameInstance->SaveSlotName, SaveGameInstance->UserIndex);
	}
}

void UEchoGameInstance::LoadGame()
{
	if (UGameplayStatics::DoesSaveGameExist(TEXT("EchoSave"), 0))
	{
		USaveGameEcho* SaveGameInstance = Cast<USaveGameEcho>(UGameplayStatics::LoadGameFromSlot(TEXT("EchoSave"), 0));
		// Применить сохраненные данные к системам игры
	}
}
