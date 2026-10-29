// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h>
#include "GameFramework/HUD.h>
#include "EchoHUD.generated.h"

/**
 * HUD ECHO PROTOCOL — чистый милитари-техно стиль.
 */
UCLASS()
class ECHO_PROTOCOL_API AEchoHUD : public AHUD
{
	GENERATED_BODY()

public:
	AEchoHUD();

	// Ссылки на виджеты (УМГ)
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<class UUserWidget> HUDWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<class UUserWidget> EchoLayerHUDClass;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<class UUserWidget> BriefingWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<class UUserWidget> HubMenuWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<class UUserWidget> PerkTreeWidgetClass;

protected:
	virtual void BeginPlay() override;

private:
	class UUserWidget* CurrentHUD = nullptr;
	class UUserWidget* CurrentEchoHUD = nullptr;
};
