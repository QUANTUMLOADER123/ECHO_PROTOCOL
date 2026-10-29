// Fill out your copyright notice in the Description page of Project Settings.

#include "Corpse.h"

ACorpse::ACorpse()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ACorpse::BeginPlay()
{
	Super::BeginPlay();
}

void ACorpse::LootCorpse()
{
	if (bIsLooted) return;
	bIsLooted = true;
	// Передать ItemsOnCorpse в инвентарь игрока
	Destroy();
}
