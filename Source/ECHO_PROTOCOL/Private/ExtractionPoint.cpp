// Fill out your copyright notice in the Description page of Project Settings.

#include "ExtractionPoint.h"
#include "Kismet/GameplayStatics.h"

AExtractionPoint::AExtractionPoint()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AExtractionPoint::BeginPlay()
{
	Super::BeginPlay();
	BaseLocation = GetActorLocation();
}

void AExtractionPoint::Activate(float AlarmLevel)
{
	bIsActive = true;
	CurrentAlarmLevel = AlarmLevel;

	// Смещаем точку дальше при высокой тревоге
	float DistanceScale = FMath::GetMappedRangeValueClamped(
		FVector2D(0.0f, 100.0f),
		FVector2D(0.0f, 1.0f),
		AlarmLevel
	);

	FVector NewLocation = BaseLocation + FVector(0.0f, DistanceScale * 1000.0f, 0.0f);
	SetActorLocation(NewLocation);
}

void AExtractionPoint::Deactivate()
{
	bIsActive = false;
	SetActorLocation(BaseLocation);
}

float AExtractionPoint::GetDistanceFromPlayer() const
{
	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	if (PC && PC->GetPawn())
	{
		return FVector::Dist(GetActorLocation(), PC->GetPawn()->GetActorLocation());
	}
	return 0.0f;
}
