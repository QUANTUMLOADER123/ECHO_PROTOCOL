// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h>
#include "Components/ActorComponent.h>
#include "SpawnPoint.h>
#include "SpawnManager.generated.h"

/**
 * Менеджер спауна врагов и лута на уровне.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ECHO_PROTOCOL_API USpawnManager : public UActorComponent
{
	GENERATED_BODY()

public:
	USpawnManager();

	// Все точки спавна на уровне
	UPROPERTY(BlueprintReadOnly, Category = "Spawn")
	TArray<ASpawnPoint*> SpawnPoints;

	// Функции
	UFUNCTION(BlueprintCallable, Category = "Spawn")
	void RegisterSpawnPoint(ASpawnPoint* Point);

	UFUNCTION(BlueprintCallable, Category = "Spawn")
	TArray<ASpawnPoint*> GetSpawnPointsByType(FName Type);

protected:
	virtual void BeginPlay() override;
};
