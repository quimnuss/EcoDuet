// Copyright 2023 clicligames All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Kismet/GameplayStatics.h"
#include "EcoBaseActor.h"
#include "EngineUtils.h"
#include "EngineGlobals.h"
#include "EcoGameModeHome.h"
#include "EcoGameStateHome.h"
#include "TimerManager.h"
#include "EcoGLVActorComponent.generated.h"

UENUM(BlueprintType)
enum class EEcoSpeciesType : uint8 {
	EcoNone  UMETA(DisplayName = "None"),
	EcoFox   UMETA(DisplayName = "Fox"),
	EcoGrass UMETA(DisplayName = "Grass"),
	EcoPig   UMETA(DisplayName = "Pig"),
	EcoStag  UMETA(DisplayName = "Stag"),
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ECODUET_API UEcoGLVActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EcoActor")
	//TMap<FName, float> EcoElderRelationVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EcoActor")
	TMap<EEcoSpeciesType, float> EcoSpeciesRelationVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EcoActor")
	float rate = 0.f;

	UClass* OwnerActorClass;
	AActor* Owner;
	FName SpeciesName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EcoActor")
	EEcoSpeciesType MySpecies;


public:	
	// Sets default values for this component's properties
	UEcoGLVActorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//UFUNCTION(BlueprintCallable, Category = "EcoActor")
	//float VoltkaTick(float DeltaTime, TMap<FName, float> Densities);

	UFUNCTION(BlueprintCallable, Category = "EcoActor")
	float VoltkaSpeciesTick(float DeltaTime, TMap<EEcoSpeciesType, float> Densities);
		
};
