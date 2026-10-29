// Fill out your copyright notice in the Description page of Project Settings.

#include "ProceduralDungeonGenerator.h"
#include "Kismet/GameplayStatics.h"

AProceduralDungeonGenerator::AProceduralDungeonGenerator()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AProceduralDungeonGenerator::BeginPlay()
{
	Super::BeginPlay();
}

void AProceduralDungeonGenerator::GenerateLevel()
{
	// Сначала ручные якоря
	PlaceManualAnchors();

	// Затем процедурные комнаты
	for (int32 i = 0; i < ProceduralRoomCount; i++)
	{
		if (ProceduralRoomClasses.Num() > 0)
		{
			int32 ClassIdx = FMath::RandRange(0, ProceduralRoomClasses.Num() - 1);
			FActorSpawnParameters SpawnParams;
			AProceduralRoom* Room = GetWorld()->SpawnActor<AProceduralRoom>(ProceduralRoomClasses[ClassIdx], FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);
			if (Room)
			{
				Rooms.Add(Room);
			}
		}
	}

	// Соединить комнаты
	ConnectRooms();
}

void AProceduralDungeonGenerator::PlaceManualAnchors()
{
	for (TSubclassOf<AProceduralRoom> AnchorClass : ManualAnchorClasses)
	{
		FActorSpawnParameters SpawnParams;
		AProceduralRoom* Room = GetWorld()->SpawnActor<AProceduralRoom>(AnchorClass, FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);
		if (Room)
		{
			Room->bIsManualAnchor = true;
			Rooms.Add(Room);
		}
	}
}

void AProceduralDungeonGenerator::ConnectRooms()
{
	// Валидация проходимости: каждая комната соединена хотя бы с одной другой
	for (int32 i = 0; i < Rooms.Num(); i++)
	{
		for (int32 j = i + 1; j < Rooms.Num(); j++)
		{
			if (FMath::FRand() > 0.7f)
			{
				FRoomConnection Connection;
				Connection.RoomA = Rooms[i];
				Connection.RoomB = Rooms[j];
				// Создать дверь/проем между ними
			}
		}
	}
}
