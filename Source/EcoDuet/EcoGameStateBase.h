// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "EcoGameStateBase.generated.h"

/**
 * 
 */
UCLASS()
class ECODUET_API AEcoGameStateBase : public AGameStateBase
{
	GENERATED_BODY()
	
protected:
		// To add mapping context
	virtual void BeginPlay();
};
