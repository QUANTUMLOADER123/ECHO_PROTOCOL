// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h>
#include "GameFramework/Actor.h>
#include "SpawnPoint.generated.h"

/**
 * Точка спавна для врагов и лута.
 */
UCLASS()
class ECHO_PROTOCOL_API ASpawnPoint : public AActor
{
	GENERATED_BODY()

public:
	ASpawnPoint();

	// Тип спауна
	UPROPERTY(EditDefaultsOnly, Category = "Spawn")
	FName SpawnType; // "Enemy", "Loot", "Patrol"

	// Активна ли точка
	UPROPERTY(EditDefaultsOnly, Category = "Spawn")
	bool bIsActive = true;

	// Функции
	UFUNCTION(BlueprintCallable, Category = "Spawn")
	void Activate();

	UFUNCTION(BlueprintCallable, Category = "Spawn")
	void Deactivate();

protected:
	virtual void BeginPlay() override;
};
