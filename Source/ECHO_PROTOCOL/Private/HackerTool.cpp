// Fill out your copyright notice in the Description page of Project Settings.

#include "HackerTool.h"

AHackerTool::AHackerTool()
{
	GadgetType = EGadgetType::HackerTool;
	MaxCharges = 5;
	RechargeTime = 5.0f;
}

void AHackerTool::BeginPlay()
{
	Super::BeginPlay();
}

void AHackerTool::HackTarget(AActor* Target)
{
	if (!Use() || !Target) return;
	// Взлом терминала/камеры/турели
}
