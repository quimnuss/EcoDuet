// Fill out your copyright notice in the Description page of Project Settings.


#include "EcoOscillatingActor.h"

AEcoOscillatingActor::AEcoOscillatingActor()
{

}

void AEcoOscillatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	this->RunningTime += DeltaTime;

	auto CurrentLocation = this->GetActorLocation();

	float Speed = 150.0f;

	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	CurrentLocation.Z += Speed * DeltaHeight;

	this->SetActorLocation(CurrentLocation);
}
