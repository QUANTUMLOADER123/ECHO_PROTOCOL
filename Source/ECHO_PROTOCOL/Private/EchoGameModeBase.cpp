// Fill out your copyright notice in the Description page of Project Settings.

#include "EchoGameModeBase.h"

AEchoGameModeBase::AEchoGameModeBase()
{
}

void AEchoGameModeBase::BeginPlay()
{
	Super::BeginPlay();
}

void AEchoGameModeBase::RestartMission()
{
	// Перезапуск текущего контракта
}

void AEchoGameModeBase::ExtractPlayer(bool bSuccess)
{
	// Эвакуация игрока, подсчет лута, завершение миссии
}
