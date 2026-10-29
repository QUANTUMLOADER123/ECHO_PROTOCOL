// Fill out your copyright notice in the Description page of Project Settings.

#include "DataStick.h"

ADataStick::ADataStick()
{
	LootType = ELootType::DataStick;
}

void ADataStick::BeginPlay()
{
	Super::BeginPlay();
}

void ADataStick::ReadData()
{
	if (bRequiresHack)
	{
		// Требует взломщика
	}
	else
	{
		// Данные доступны
	}
}
