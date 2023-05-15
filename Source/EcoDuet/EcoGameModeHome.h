// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EcoBaseActor.h"
#include "GameFramework/GameMode.h"
#include "EcoGameModeHome.generated.h"

/**
 * 
 */
UCLASS()
class ECODUET_API AEcoGameModeHome : public AGameMode
{
	GENERATED_BODY()

public:
	//TMap<TSubclassOf<class AEcoBaseActor>, AEcoBaseActor*> EcologyMap;
	TMap<FString, AEcoBaseActor*> EcologyMap;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EcoEcology")
	FVector4 EcologyDensities;

public:
	void SetEcologyDensities(FVector4 EcologyDensities);

	FVector4 GetEcologyDensities();

};
