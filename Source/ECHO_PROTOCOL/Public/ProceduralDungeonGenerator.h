// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h>
#include "GameFramework/Actor.h>
#include "ProceduralRoom.h>
#include "ProceduralDungeonGenerator.generated.h"

USTRUCT(BlueprintType)
struct FRoomConnection
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AProceduralRoom* RoomA = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AProceduralRoom* RoomB = nullptr;
};

/**
 * Процедурная генерация локаций: граф комнат + ручные якоря.
 */
UCLASS()
class ECHO_PROTOCOL_API AProceduralDungeonGenerator : public AActor
{
	GENERATED_BODY()

public:
	AProceduralDungeonGenerator();

	// Все комнаты уровня
	UPROPERTY(BlueprintReadOnly, Category = "Procedural")
	TArray<AProceduralRoom*> Rooms;

	// Ручные якоря (серверная, комната охраны, лифт, оружейная)
	UPROPERTY(EditDefaultsOnly, Category = "Procedural")
	TArray<TSubclassOf<AProceduralRoom>> ManualAnchorClasses;

	// Процедурные комнаты
	UPROPERTY(EditDefaultsOnly, Category = "Procedural")
	TArray<TSubclassOf<AProceduralRoom>> ProceduralRoomClasses;

	// Количество процедурных комнат
	UPROPERTY(EditDefaultsOnly, Category = "Procedural")
	int32 ProceduralRoomCount = 10;

	// Функции
	UFUNCTION(BlueprintCallable, Category = "Procedural")
	void GenerateLevel();

	UFUNCTION(BlueprintCallable, Category = "Procedural")
	void PlaceManualAnchors();

	UFUNCTION(BlueprintCallable, Category = "Procedural")
	void ConnectRooms();

protected:
	virtual void BeginPlay() override;
};
