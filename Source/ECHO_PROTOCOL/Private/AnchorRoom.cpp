// Fill out your copyright notice в Description page of Project Settings.

#include "AnchorRoom.h"

AAnchorRoom::AAnchorRoom()
{
}

void AAnchorRoom::BeginPlay()
{
	Super::BeginPlay();
}

void AAnchorRoom::SetAnchorName(FString NewName)
{
	AnchorName = NewName;
}
