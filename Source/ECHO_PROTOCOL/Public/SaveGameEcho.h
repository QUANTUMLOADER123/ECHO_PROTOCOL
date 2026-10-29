// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h>
#include "Kismet/SaveGame.h>
#include "SaveGameEcho.generated.h"

USTRUCT(BlueprintType)
struct FPlayerSaveData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PlayerName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Credits = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Reputation = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> CompletedContracts;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> UnlockedPerks;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PinnedWeapon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> ContainerLoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 WorkbenchLevel = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MedBayLevel = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ArchiveLevel = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ArmoryLevel = 1;
};

/**
 * Сохранения игры: JSON-профиль, база, перки, закреплённый лут.
 */
UCLASS()
class ECHO_PROTOCOL_API USaveGameEcho : public USaveGame
{
	GENERATED_BODY()

public:
	USaveGameEcho();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FPlayerSaveData SaveData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString SaveSlotName = TEXT("EchoSave");

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 UserIndex = 0;
};
