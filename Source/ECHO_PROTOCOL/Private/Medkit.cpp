// Fill out your copyright notice in the Description page of Project Settings.

#include "Medkit.h"

AMedkit::AMedkit()
{
	GadgetType = EGadgetType::Medkit;
	MaxCharges = 4;
	RechargeTime = 0.0f;
}

void AMedkit::BeginPlay()
{
	Super::BeginPlay();
}

void AMedkit::UseMedicine()
{
	if (!Use()) return;
	// Лечение игрока на HealAmount, если bIsStimulant — ускорение на StimDuration
}
