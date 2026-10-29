// Fill out your copyright notice in the Description page of Project Settings.

#include "ReconDrone.h"

AReconDrone::AReconDrone()
{
	GadgetType = EGadgetType::ReconDrone;
	MaxCharges = 2;
	RechargeTime = 25.0f;
}

void AReconDrone::BeginPlay()
{
	Super::BeginPlay();
}

void AReconDrone::DeployDrone()
{
	if (!Use()) return;
	// Спавн актера дрона, переключение управления на него
}
