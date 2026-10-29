// Fill out your copyright notice in the Description page of Project Settings.

#include "Terminal.h"

ATerminal::ATerminal()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ATerminal::BeginPlay()
{
	Super::BeginPlay();
}

void ATerminal::Hack()
{
	if (bRequiresHack && TerminalState == ETerminalState::Locked)
	{
		TerminalState = ETerminalState::Hacked;
	}
}

void ATerminal::AccessData()
{
	if (TerminalState == ETerminalState::Hacked || TerminalState == ETerminalState::Active)
	{
		// Выдать данные игроку
	}
}
