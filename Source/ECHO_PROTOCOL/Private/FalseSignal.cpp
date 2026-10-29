// Fill out your copyright notice in the Description page of Project Settings.

#include "FalseSignal.h"

AFalseSignal::AFalseSignal()
{
	GadgetType = EGadgetType::FalseSignal;
	MaxCharges = 3;
	RechargeTime = 12.0f;
}

void AFalseSignal::BeginPlay()
{
	Super::BeginPlay();
}

void AFalseSignal::DeploySignal()
{
	if (!Use()) return;
	// Спавн шумовогомэкера, патрули идут на звук
}
