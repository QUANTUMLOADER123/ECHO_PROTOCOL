// Fill out your copyright notice in the Description page of Project Settings.

#include "EchoHUD.h"
#include "Blueprint/UserWidget.h"

AEchoHUD::AEchoHUD()
{
}

void AEchoHUD::BeginPlay()
{
	Super::BeginPlay();

	if (HUDWidgetClass)
	{
		CurrentHUD = CreateWidget<UUserWidget>(GetOwningPlayerController(), HUDWidgetClass);
		CurrentHUD->AddToViewport();
	}
}
