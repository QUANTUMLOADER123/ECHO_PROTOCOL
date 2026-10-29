// Fill out your copyright notice in the Description page of Project Settings.

#include "EchoScanner.h"

AEchoScanner::AEchoScanner()
{
	GadgetType = EGadgetType::EchoScanner;
	MaxCharges = 3;
	RechargeTime = 15.0f;
}

void AEchoScanner::BeginPlay()
{
	Super::BeginPlay();
}

void AEchoScanner::ScanForEnemies()
{
	if (!Use()) return;
	// Логика подсветки врагов через линию зрения / сферу overlaps
	// Реализуется в Blueprint или через GameplayStatics::GetAllActorsWithInterface
}
