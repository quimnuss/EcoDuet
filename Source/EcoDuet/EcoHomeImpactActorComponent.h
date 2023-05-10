// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Kismet/GameplayStatics.h"
#include "EcoBaseActor.h"
#include "EngineUtils.h"
#include "EngineGlobals.h"
#include "EcoPlantActor.h"
#include "EcoGameModeHome.h"
#include "EcoGameStateHome.h"
#include "EcoHomeImpactActorComponent.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ECODUET_API UEcoHomeImpactActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEcoHomeImpactActorComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EcoActor")
	TSubclassOf<AEcoBaseActor> TargetActorClass;

	UClass* OwnerActorClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EcoActor")
	float Fitness;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EcoActor")
	int SelfCarryingCapacity = 20;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	void ControlTargetSpecies();

	void SuicideIfOverCapacity();

	void VoltkaTick();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
