// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EchoCharacter.generated.h"

UCLASS()
class ECHO_PROTOCOL_API AEchoCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AEchoCharacter();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
