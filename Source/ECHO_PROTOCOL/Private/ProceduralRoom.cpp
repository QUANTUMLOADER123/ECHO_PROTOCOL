// Fill out your copyright notice in the Description page of Project Settings.

#include "ProceduralRoom.h"

AProceduralRoom::AProceduralRoom()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AProceduralRoom::BeginPlay()
{
	Super::BeginPlay();
}

void AProceduralRoom::SetRoomType(ERoomType NewType)
{
	RoomType = NewType;
}
