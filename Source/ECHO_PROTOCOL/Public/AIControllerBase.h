// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AIControllerBase.generated.h"

/**
 * Базовый контроллер ИИ для патрулей, дронов, фантомов, турелей, снайперов, стаи, титанов.
 * Поддерживает тревожное состояние и маршруты через NavMesh.
 */
UCLASS()
class ECHO_PROTOCOL_API AAIControllerBase : public AAIController
{
	GENERATED_BODY()

public:
	AAIControllerBase();

	// Текущее состояние ИИ
	UPROPERTY(BlueprintReadOnly, Category = "AI")
	TEnumAsByte<enum EAIOption> AIState = EAIOption::Patrol;

	// Последняя известная позиция игрока
	UPROPERTY(BlueprintReadOnly, Category = "AI")
	FVector LastKnownPlayerLocation;

	// Функции
	UFUNCTION(BlueprintCallable, Category = "AI")
	void SetAlertState(bool bAlerted);

	UFUNCTION(BlueprintCallable, Category = "AI")
	void SetLastKnownPlayerLocation(FVector Location);

	UFUNCTION(BlueprintCallable, Category = "AI")
	FVector GetLastKnownPlayerLocation() const { return LastKnownPlayerLocation; }

protected:
	virtual void BeginPlay() override;
};

UENUM(BlueprintType)
enum class EAIOption : uint8
{
	Patrol      UMETA(DisplayName = "Patrol"),
	Investigate UMETA(DisplayName = "Investigate"),
	Chase       UMETA(DisplayName = "Chase"),
	Search      UMETA(DisplayName = "Search"),
	Combat      UMETA(DisplayName = "Combat"),
	Return      UMETA(DisplayName = "Return")
};
