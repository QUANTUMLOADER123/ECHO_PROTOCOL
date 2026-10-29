// Fill out your copyright notice in the Description page of Project Settings.

#include "WeaponModular.h"

AWeaponModular::AWeaponModular()
{
}

void AWeaponModular::BeginPlay()
{
	Super::BeginPlay();
	ApplyMods();
}

void AWeaponModular::ApplyMods()
{
	// Здесь применяются бонусы от модов кダメджу, точности, шуму, размеру магазина и т.д.
	// Пример: глушитель снижает шум, прицел снижает разброс, удлиненный магазин увеличивает патроны.
}

void AWeaponModular::SetMod(FName SlotName, FName ModName)
{
	if (SlotName == TEXT("Barrel")) BarrelMod = ModName;
	else if (SlotName == TEXT("Scope")) ScopeMod = ModName;
	else if (SlotName == TEXT("Magazine")) MagazineMod = ModName;
	else if (SlotName == TEXT("Muzzle")) MuzzleMod = ModName;

	ApplyMods();
}
