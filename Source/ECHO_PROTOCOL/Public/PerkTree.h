// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h>
#include "Components/ActorComponent.h"
#include "PerkTree.generated.h"

UENUM(BlueprintType)
enum class EPerkID : uint8
{
	QuietSteps      UMETA(DisplayName = "Quiet Steps"),
	FastHack        UMETA(DisplayName = "Fast Hack"),
	ExtraEchoCharge UMETA(DisplayName = "Extra Echo Charge"),
	ReinforcedContainer UMETA(DisplayName = "Reinforced Container"),
	BetterDisguise  UMETA(DisplayName = "Better Disguise"),
	MoreReserveAmmo UMETA(DisplayName = "More Reserve Ammo")
};

USTRUCT(BlueprintType)
struct FPerkEntry
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPerkID PerkID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PerkName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Cost = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bUnlocked = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<EPerkID> Prerequisites;
};

/**
 * Дерево перков Протокола.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ECHO_PROTOCOL_API UPerkTree : public UActorComponent
{
	GENERATED_BODY()

public:
	UPerkTree();

	// Все перки
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Perks")
	TArray<FPerkEntry> Perks;

	// Кредиты игрока
	UPROPERTY(BlueprintReadOnly, Category = "Perks")
	int32 Credits = 0;

	// Функции
	UFUNCTION(BlueprintCallable, Category = "Perks")
	bool UnlockPerk(EPerkID PerkID);

	UFUNCTION(BlueprintCallable, Category = "Perks")
	bool IsPerkUnlocked(EPerkID PerkID) const;

	UFUNCTION(BlueprintCallable, Category = "Perks")
	int32 GetCredits() const { return Credits; }

	UFUNCTION(BlueprintCallable, Category = "Perks")
	void AddCredits(int32 Amount);

protected:
	virtual void BeginPlay() override;
};
