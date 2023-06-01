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

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ECODUET_API UEcoGLVActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EcoActor")
	TMap<FString, float> EcoElderRelationVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EcoActor")
	float rate = 0.f;

	UClass* OwnerActorClass;
	AActor* Owner;


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

	void VoltkaTick(float DeltaTime);
		
};
