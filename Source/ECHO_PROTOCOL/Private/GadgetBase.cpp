// Fill out your copyright notice in the Description page of Project Settings.

#include "GadgetBase.h"

AGadgetBase::AGadgetBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AGadgetBase::BeginPlay()
{
	Super::BeginPlay();
	Charges = MaxCharges;
}

bool AGadgetBase::Use()
{
	if (Charges <= 0) return false;

	Charges--;
	bIsActive = true;
	return true;
}

void AGadgetBase::Recharge()
{
	if (RechargeTimer > 0.0f)
	{
		RechargeTimer -= GetWorld()->GetDeltaSeconds();
		if (RechargeTimer <= 0.0f && Charges < MaxCharges)
		{
			Charges++;
			RechargeTimer = RechargeTime;
		}
	}
}
