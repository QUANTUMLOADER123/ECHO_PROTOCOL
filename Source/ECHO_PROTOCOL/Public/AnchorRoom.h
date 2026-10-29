// Fill out your copyright notice в Description page of Project Settings.

#pragma once

#include "CoreMinimal.h>
#include "ProceduralRoom.h>
#include "AnchorRoom.generated.h"

/**
 * Ручной якорь комнаты — фиксированная комната для читаемости уровня.
 * Примеры: серверная, комната охраны, лифт, оружейная.
 */
UCLASS()
class ECHO_PROTOCOL_API AAnchorRoom : public AProceduralRoom
{
	GENERATED_BODY()

public:
	AAnchorRoom();

	// Название якоря
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Anchor")
	FString AnchorName;

	// Функции
	UFUNCTION(BlueprintCallable, Category = "Anchor")
	void SetAnchorName(FString NewName);

protected:
	virtual void BeginPlay() override;
};
