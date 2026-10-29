// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GadgetBase.h"
#include "RealityAnchor.generated.h"

/**
 * Якорь реальности — принудительный выход из Эхо-слоя, урон фантомам.
 */
UCLASS()
class ECHO_PROTOCOL_API ARealityAnchor : public AGadgetBase
{
	GENERATED_BODY()

public:
	ARealityAnchor();

	// Радиус действия
	UPROPERTY(EditDefaultsOnly, Category = "RealityAnchor")
	float EffectRadius = 600.0f;

	// Урон фантомам
	UPROPERTY(EditDefaultsOnly, Category = "RealityAnchor")
	float PhantomDamage = 100.0f;

	// Функции
	UFUNCTION(BlueprintCallable, Category = "RealityAnchor")
	void AnchorReality();

protected:
	virtual void BeginPlay() override;
};
