// Copyright 2023 clicligames All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "../EcoGLVActorComponent.h"
#include "../EcoDuetCharacter.h"
#include "EcoElderDataAsset.generated.h"

//class RelationModifier : public something
//{
//	//Actor that causes the buff/nerf
//	AActor* Instigator;
//
//	//Other species affected, or None if it a Rate mod
//	EEcoSpeciesType other;
//
//	float delta;
//};

/**
 * 
 */
UCLASS(BlueprintType)
class ECODUET_API UEcoElderDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EcoActor")
	FName ElderName = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EcoActor")
	EEcoSpeciesType Species = EEcoSpeciesType::EcoNone;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EcoActor")
	UClass* SpeciesClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EcoActor")
	float rate = 0.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EcoActor")
	TMap<EEcoSpeciesType, float> EcoSpeciesRelationVector;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EcoActor")
	//TArray<RelationModifier> EcoMods;
	
};
