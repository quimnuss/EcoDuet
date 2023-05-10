// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EcoBaseActor.h"
#include "EcoPlantActor.generated.h"

/**
 * 
 */
UCLASS()
class ECODUET_API AEcoPlantActor : public AEcoBaseActor
{
	GENERATED_BODY()
	
public:
	AEcoPlantActor();

	float RunningTime;

public:
	virtual void Tick(float DeltaTime) override;

};
