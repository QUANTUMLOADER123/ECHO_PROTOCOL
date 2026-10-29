// Fill out your copyright notice in the Description page of Project Settings.

#include "SensorJammer.h"

ASensorJammer::ASensorJammer()
{
	GadgetType = EGadgetType::SensorJammer;
	MaxCharges = 2;
	RechargeTime = 20.0f;
}

void ASensorJammer::BeginPlay()
{
	Super::BeginPlay();
}

void ASensorJammer::JamSensors()
{
	if (!Use()) return;
	// Отключает камеры и турели в радиусе на JamDuration секунд
}
