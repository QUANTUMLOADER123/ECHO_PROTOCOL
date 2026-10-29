// Fill out your copyright notice in the Description page of Project Settings.

#include "EchoNetworkComponent.h"

UEchoNetworkComponent::UEchoNetworkComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UEchoNetworkComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UEchoNetworkComponent::HostSession()
{
	bIsHost = true;
	SessionID = FString::Printf(TEXT("ECHO_%d"), FMath::RandRange(100000, 999999));
	// Создание сессии через Steam Networking / Online Subsystem
}

void UEchoNetworkComponent::JoinSession(FString SessionName)
{
	bIsHost = false;
	SessionID = SessionName;
	// Подключение к сессии хоста
}

void UEchoNetworkComponent::LeaveSession()
{
	bIsHost = false;
	SessionID = TEXT("");
	// Отключение от сессии
}
