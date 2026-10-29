// Fill out your copyright notice in the Description page of Project Settings.

#include "RealityAnchor.h"

ARealityAnchor::ARealityAnchor()
{
	GadgetType = EGadgetType::RealityAnchor;
	MaxCharges = 2;
	RechargeTime = 30.0f;
}

void ARealityAnchor::BeginPlay()
{
	Super::BeginPlay();
}

void ARealityAnchor::AnchorReality()
{
	if (!Use()) return;
	// Выход из Эхо-слоя + урон фантомам в радиусе
}
