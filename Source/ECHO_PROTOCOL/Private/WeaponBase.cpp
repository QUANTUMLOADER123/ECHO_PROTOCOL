// Fill out your copyright notice in the Description page of Project Settings.

#include "WeaponBase.h"

AWeaponBase::AWeaponBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AWeaponBase::BeginPlay()
{
	Super::BeginPlay();
	CurrentMagazineSize = MaxMagazineSize;
	CurrentAmmo = MaxMagazineSize;
}

void AWeaponBase::Fire()
{
	if (bIsReloading || CurrentAmmo <= 0) return;

	float TimeBetweenShots = 1.0f / FireRate;
	if (TimeSinceLastShot < TimeBetweenShots) return;

	CurrentAmmo--;
	TimeSinceLastShot = 0.0f;
}

void AWeaponBase::Reload()
{
	if (bIsReloading || CurrentAmmo >= CurrentMagazineSize || ReserveAmmo <= 0) return;

	bIsReloading = true;

	int32 Needed = CurrentMagazineSize - CurrentAmmo;
	int32 ToReload = FMath::Min(Needed, ReserveAmmo);

	CurrentAmmo += ToReload;
	ReserveAmmo -= ToReload;

	bIsReloading = false;
}
