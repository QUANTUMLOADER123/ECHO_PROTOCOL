// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryComponent.h"

UInventoryComponent::UInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UInventoryComponent::AddToPocket(FString ItemName, int32 Quantity)
{
	FLootItem Item;
	Item.ItemName = ItemName;
	Item.Quantity = Quantity;
	Item.bIsPocketLoot = true;
	PocketLoot.Add(Item);
}

void UInventoryComponent::AddToContainer(FString ItemName, int32 Quantity)
{
	FLootItem Item;
	Item.ItemName = ItemName;
	Item.Quantity = Quantity;
	Item.bIsContainerLoot = true;
	ContainerLoot.Add(Item);
}

void UInventoryComponent::DropPocketLoot()
{
	PocketLoot.Empty();
}

void UInventoryComponent::DropContainerLootPartial(float PercentToKeep)
{
	// Сохраняем процент контейнера, остальное теряем
	int32 KeepCount = FMath::CeilToInt(ContainerLoot.Num() * PercentToKeep);
	if (KeepCount < ContainerLoot.Num())
	{
		ContainerLoot.SetNum(KeepCount, false);
	}
}

void UInventoryComponent::EquipWeapon(TSubclassOf<AWeaponBase> WeaponClass)
{
	EquippedWeapon = WeaponClass;
}

void UInventoryComponent::PinWeapon(TSubclassOf<AWeaponBase> WeaponClass)
{
	PinnedWeapon = WeaponClass;
}
