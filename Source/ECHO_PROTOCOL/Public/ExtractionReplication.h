// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h>
#include "Components/ActorComponent.h>
#include "ExtractionReplication.generated.h"

/**
 * Репликация точки эвакуации для кооператива.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ECHO_PROTOCOL_API UExtractionReplication : public UActorComponent
{
	GENERATED_BODY()

public:
	UExtractionReplication();

	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Extraction")
	bool bExtractionActive = false;

	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Extraction")
	FVector ExtractionLocation;

	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Extraction")
	int32 PlayersExtracted = 0;

	UPROPERTY(EditDefaultsOnly, Category = "Extraction")
	int32 PlayersRequiredForExtraction = 1;

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "Extraction")
	void ServerActivateExtraction(FVector Location);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "Extraction")
	void ServerPlayerExtracted();

protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) override;
};
