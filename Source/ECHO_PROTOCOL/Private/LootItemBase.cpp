// Fill out your copyright notice in the Description page of Project Settings.

#include "LootItemBase.h"

ALootItemBase::ALootItemBase()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ALootItemBase::BeginPlay()
{
	Super::BeginPlay();
}

void ALootItemBase::OnPickedUp()
{
	if (bCanPickup)
	{
		// Добавить в инвентарь игрока, удалить актер
		Destroy();
	}
}
