// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BaseHubManager.generated.h"

UENUM(BlueprintType)
enum class EBaseFacility : uint8
{
	Workbench   UMETA(DisplayName = "Workbench"),
	MedBay      UMETA(DisplayName = "MedBay"),
	Archive     UMETA(DisplayName = "Archive"),
	Armory      UMETA(DisplayName = "Armory")
};

/**
 * База-хаб: верстак, медотсек, архив данных, оружейная.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ECHO_PROTOCOL_API UBaseHubManager : public UActorComponent
{
	GENERATED_BODY()

public:
	UBaseHubManager();

	// Уровни объектов базы
	UPROPERTY(BlueprintReadWrite, Category = "BaseHub")
	int32 WorkbenchLevel = 1;

	UPROPERTY(BlueprintReadWrite, Category = "BaseHub")
	int32 MedBayLevel = 1;

	UPROPERTY(BlueprintReadWrite, Category = "BaseHub")
	int32 ArchiveLevel = 1;

	UPROPERTY(BlueprintReadWrite, Category = "BaseHub")
	int32 ArmoryLevel = 1;

	// Разблокированные объекты
	UPROPERTY(BlueprintReadWrite, Category = "BaseHub")
	TArray<EBaseFacility> UnlockedFacilities;

	// Функции
	UFUNCTION(BlueprintCallable, Category = "BaseHub")
	void UpgradeFacility(EBaseFacility Facility);

	UFUNCTION(BlueprintCallable, Category = "BaseHub")
	bool IsFacilityUnlocked(EBaseFacility Facility) const;

	UFUNCTION(BlueprintCallable, Category = "BaseHub")
	int32 GetFacilityLevel(EBaseFacility Facility) const;

protected:
	virtual void BeginPlay() override;
};
