// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StealthManager.generated.h"

/**
 * Управление стелсом: присед, лежание, скольжение, шум шагов,
 * обнаружение врагами, маскировка под сотрудника.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ECHO_PROTOCOL_API UStealthManager : public UActorComponent
{
	GENERATED_BODY()

public:
	UStealthManager();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Состояние движения
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stealth")
	bool bIsCrouching = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stealth")
	bool bIsProne = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stealth")
	bool bIsSliding = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stealth")
	bool bIsDisguised = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stealth")
	float DisguiseTimeRemaining = 0.0f;

	// Шум, который создаёт игрок (0.0 - тихо, 1.0 - очень громко)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stealth")
	float CurrentNoiseLevel = 0.0f;

	// Расстояние, на которое враги слышат игрока
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stealth")
	float NoiseDetectionRadius = 500.0f;

	// Коэффициенты шума для разных состояний
	UPROPERTY(EditDefaultsOnly, Category = "Stealth")
	float NoiseWalk = 0.2f;

	UPROPERTY(EditDefaultsOnly, Category = "Stealth")
	float NoiseRun = 0.8f;

	UPROPERTY(EditDefaultsOnly, Category = "Stealth")
	float NoiseCrouch = 0.05f;

	UPROPERTY(EditDefaultsOnly, Category = "Stealth")
	float NoiseProne = 0.01f;

	UPROPERTY(EditDefaultsOnly, Category = "Stealth")
	float NoiseSlide = 0.4f;

	UPROPERTY(EditDefaultsOnly, Category = "Stealth")
	float NoiseSprint = 1.0f;

	// Функции
	UFUNCTION(BlueprintCallable, Category = "Stealth")
	void SetCrouch(bool Value);

	UFUNCTION(BlueprintCallable, Category = "Stealth")
	void SetProne(bool Value);

	UFUNCTION(BlueprintCallable, Category = "Stealth")
	void StartSlide();

	UFUNCTION(BlueprintCallable, Category = "Stealth")
	void SetDisguise(float DurationSeconds);

	UFUNCTION(BlueprintCallable, Category = "Stealth")
	void MakeNoise(float Amount);

	UFUNCTION(BlueprintCallable, Category = "Stealth")
	float GetNoiseLevel() const;

	UFUNCTION(BlueprintCallable, Category = "Stealth")
	bool IsHiddenFromAI() const;

protected:
	virtual void BeginPlay() override;

private:
	float SlideTimer = 0.0f;
	float SlideDuration = 0.5f;
};
