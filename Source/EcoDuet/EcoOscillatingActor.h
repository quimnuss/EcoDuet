// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EcoBaseActor.h"
#include "EcoOscillatingActor.generated.h"

/**
 * 
 */
UCLASS()
class ECODUET_API AEcoOscillatingActor : public AEcoBaseActor
{
	GENERATED_BODY()

public:
	AEcoOscillatingActor();

	float RunningTime;

public:
	virtual void Tick(float DeltaTime) override;

};
