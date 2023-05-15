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
#include "TimerManager.h"
#include "EcoHomeImpactActorComponent.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ECODUET_API UEcoHomeImpactActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEcoHomeImpactActorComponent();

	UClass* OwnerActorClass;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EcoActor")
	FMatrix A;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EcoActor")
	FVector4 r;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EcoActor")
	FVector4 x0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "EcoActor")
	FVector4 x;

	/* Handle to manage the timer */
	FTimerHandle EcoDensitiesTimerHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EcoActor")
	float EcoDensitiesUpdateTime = 1.0f;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	FVector4 DotProduct(FMatrix A, FVector4 v);

	FVector4 VolterraTick(float DeltaTime);

	void VoltkaTick(float DeltaTime);
	void VoltkaUpdate();

		
};
