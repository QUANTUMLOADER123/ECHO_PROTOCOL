// Fill out your copyright notice в Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WeaponBase.h"
#include "GadgetBase.h"
#include "InventoryComponent.generated.h"

USTRUCT(BlueprintType)
struct FEquippedWeapon
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AWeaponBase> WeaponClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 AmmoInMagazine = 30;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ReserveAmmo = 90;
};

USTRUCT(BlueprintType)
struct FLootItem
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Quantity = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsPocketLoot = true; // теряется при смерти

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsContainerLoot = false; // закреплено, теряется частично
};

/**
 * Инвентарь игрока: оружие, гаджеты, лут, карман vs контейнер.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ECHO_PROTOCOL_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UInventoryComponent();

	// Оружие в руках
	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	TSubclassOf<AWeaponBase> EquippedWeapon;

	// Патроны текущего оружия
	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	int32 CurrentAmmo = 30;

	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	int32 ReserveAmmo = 90;

	// Слот закрепленного оружия (сохраняется после смерти)
	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	TSubclassOf<AWeaponBase> PinnedWeapon;

	// Гаджеты
	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	TArray<TSubclassOf<AGadgetBase>> Gadgets;

	// Лут в кармане (теряется при смерти)
	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	TArray<FLootItem> PocketLoot;

	// Лут в контейнере (закреплен, теряется частично)
	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	TArray<FLootItem> ContainerLoot;

	// Функции
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void AddToPocket(FString ItemName, int32 Quantity);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void AddToContainer(FString ItemName, int32 Quantity);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void DropPocketLoot();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void DropContainerLootPartial(float PercentToKeep);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void EquipWeapon(TSubclassOf<AWeaponBase> WeaponClass);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void PinWeapon(TSubclassOf<AWeaponBase> WeaponClass);

protected:
	virtual void BeginPlay() override;
};
