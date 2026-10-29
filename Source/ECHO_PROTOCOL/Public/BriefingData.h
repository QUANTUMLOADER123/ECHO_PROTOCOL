// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h>
#include "BriefingData.generated.h"

/**
 * Данные брифинга контракта — карта, цели, разведданные.
 */
USTRUCT(BlueprintType)
struct FBriefingData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ContractName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Location;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> Objectives;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> EnemyTypes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> RecommendedGadgets;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 CreditReward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ReputationReward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString MapPath;
};
