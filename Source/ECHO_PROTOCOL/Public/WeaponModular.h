// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WeaponBase.h"
#include "WeaponModular.generated.h"

/**
 * Модульное оружие: 4 слота (ствол, прицел, магазин, насадка).
 * Каждый мод меняет характеристики.
 */
UCLASS()
class ECHO_PROTOCOL_API AWeaponModular : public AWeaponBase
{
	GENERATED_BODY()

public:
	AWeaponModular();

	// Слоты модов
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Modular")
	FName BarrelMod;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Modular")
	FName ScopeMod;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Modular")
	FName MagazineMod;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Modular")
	FName MuzzleMod;

	// Применить бонусы модов к характеристикам
	UFUNCTION(BlueprintCallable, Category = "Modular")
	void ApplyMods();

	// Сменить мод в слоте
	UFUNCTION(BlueprintCallable, Category = "Modular")
	void SetMod(FName SlotName, FName ModName);

protected:
	virtual void BeginPlay() override;
};
