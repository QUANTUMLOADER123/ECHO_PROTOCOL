// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AlarmSystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAlarmLevelChanged, float, NewAlarmLevel);

/**
 * Шкала тревоги 0-100. Растёт от шума, камер, трупов, взломов.
 * При 100 локация блокируется, спавнятся элитные отряды.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ECHO_PROTOCOL_API UAlarmSystem : public UActorComponent
{
	GENERATED_BODY()

public:
	UAlarmSystem();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Текущий уровень тревоги (0-100)
	UPROPERTY(BlueprintReadOnly, Category = "Alarm")
	float AlarmLevel = 0.0f;

	// Порог блокировки локации
	UPROPERTY(EditDefaultsOnly, Category = "Alarm")
	float LockdownThreshold = 100.0f;

	// Скорость естественного спада тревоги в секунду
	UPROPERTY(EditDefaultsOnly, Category = "Alarm")
	float DecayRate = 5.0f;

	// Флаг блокировки локации
	UPROPERTY(BlueprintReadOnly, Category = "Alarm")
	bool bIsLocationLocked = false;

	// Событие изменения тревоги
	UPROPERTY(BlueprintAssignable)
	FAlarmLevelChanged OnAlarmLevelChanged;

	// Событие блокировки локации
	UPROPERTY(BlueprintAssignable)
	FAlarmLevelChanged OnLocationLocked;

	// Функции
	UFUNCTION(BlueprintCallable, Category = "Alarm")
	void AddAlarm(float Amount);

	UFUNCTION(BlueprintCallable, Category = "Alarm")
	void ReduceAlarm(float Amount);

	UFUNCTION(BlueprintCallable, Category = "Alarm")
	float GetAlarmLevel() const { return AlarmLevel; }

	UFUNCTION(BlueprintCallable, Category = "Alarm")
	bool IsLocationLocked() const { return bIsLocationLocked; }

	UFUNCTION(BlueprintCallable, Category = "Alarm")
	float GetAlarmPercent() const { return FMath::Clamp(AlarmLevel / LockdownThreshold, 0.0f, 1.0f); }

protected:
	virtual void BeginPlay() override;
};
