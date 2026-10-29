// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h>
#include "GameFramework/Actor.h>
#include "ProceduralRoom.generated.h"

UENUM(BlueprintType)
enum class ERoomType : uint8
{
	Corridor    UMETA(DisplayName = "Corridor"),
	Hall        UMETA(DisplayName = "Hall"),
	ServerRoom  UMETA(DisplayName = "Server Room"),
	GuardRoom   UMETA(DisplayName = "Guard Room"),
	Lift        UMETA(DisplayName = "Lift"),
	ArmoryRoom  UMETA(DisplayName = "Armory"),
	Anchor      UMETA(DisplayName = "Manual Anchor")
};

UCLASS()
class ECHO_PROTOCOL_API AProceduralRoom : public AActor
{
	GENERATED_BODY()

public:
	AProceduralRoom();

	// Тип комнаты
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Procedural")
	ERoomType RoomType;

	// Якорь (ручная комната) или процедурная?
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Procedural")
	bool bIsManualAnchor = false;

	// Точки соединения (двери/проемы)
	UPROPERTY(EditDefaultsOnly, Category = "Procedural")
	TArray<FVector> ConnectionPoints;

	// Функции
	UFUNCTION(BlueprintCallable, Category = "Procedural")
	void SetRoomType(ERoomType NewType);

protected:
	virtual void BeginPlay() override;
};
