// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponBase.generated.h"

UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	Pistol    UMETA(DisplayName = "Pistol"),
	SMG       UMETA(DisplayName = "SMG"),
	Assault   UMETA(DisplayName = "Assault Rifle"),
	Shotgun   UMETA(DisplayName = "Shotgun"),
	Sniper    UMETA(DisplayName = "Sniper Rifle"),
	EMIRifle  UMETA(DisplayName = "EM Rifle")
};

UENUM(BlueprintType)
enum class EFireMode : uint8
{
	Semi      UMETA(DisplayName = "Semi-Auto"),
	Auto      UMETA(DisplayName = "Full-Auto"),
	Burst     UMETA(DisplayName = "Burst"),
	Pump      UMETA(DisplayName = "Pump-Action")
};

UCLASS()
class ECHO_PROTOCOL_API AWeaponBase : public AActor
{
	GENERATED_BODY()

public:
	AWeaponBase();

	// Оружие в руке игрока?
	UPROPERTY(BlueprintReadOnly, Category = "Weapon")
	bool bIsEquipped = false;

	// Текущий тип оружия
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
	EWeaponType WeaponType = EWeaponType::Pistol;

	// Режим огня
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
	EFireMode FireMode = EFireMode::Auto;

	// Урон за выстрел
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Combat")
	float BaseDamage = 25.0f;

	// Множитель урона в Эхо-слое (оружие слабее там)
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Combat")
	float EchoLayerDamageMultiplier = 0.5f;

	// Патроны в магазине
	UPROPERTY(BlueprintReadWrite, Category = "Combat")
	int32 CurrentAmmo = 30;

	// Резерв патронов
	UPROPERTY(BlueprintReadWrite, Category = "Combat")
	int32 ReserveAmmo = 90;

	// Максимальный размер магазина
	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	int32 MaxMagazineSize = 30;

	// Размер магазина с учетом мода
	UPROPERTY(BlueprintReadWrite, Category = "Combat")
	int32 CurrentMagazineSize = 30;

	// Перезарядка
	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	float ReloadTime = 2.0f;

	// Каденс выстрела (выстрелы в секунду)
	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	float FireRate = 8.0f;

	// Шум от выстрела (0.0 - 1.0)
	UPROPERTY(EditDefaultsOnly, Category = "Stealth")
	float NoiseLevel = 0.8f;

	// Точность (разброс в градусах)
	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	float SpreadDegrees = 2.0f;

	// Функции
	UFUNCTION(BlueprintCallable, Category = "Combat")
	void Fire();

	UFUNCTION(BlueprintCallable, Category = "Combat")
	void Reload();

	UFUNCTION(BlueprintCallable, Category = "Combat")
	bool HasAmmo() const { return CurrentAmmo > 0 || ReserveAmmo > 0; }

	UFUNCTION(BlueprintCallable, Category = "Combat")
	float GetDamageMultiplierInEchoLayer() const { return EchoLayerDamageMultiplier; }

	UFUNCTION(BlueprintCallable, Category = "Combat")
	float GetNoiseLevel() const { return NoiseLevel; }

protected:
	virtual void BeginPlay() override;

private:
	float TimeSinceLastShot = 0.0f;
	bool bIsReloading = false;
};
