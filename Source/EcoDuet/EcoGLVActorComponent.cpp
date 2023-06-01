// Copyright 2023 clicligames All rights reserved.


#include "EcoGLVActorComponent.h"

// Sets default values for this component's properties
UEcoGLVActorComponent::UEcoGLVActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UEcoGLVActorComponent::BeginPlay()
{
	Super::BeginPlay();

	Owner = this->GetOwner();
	
	
}

void UEcoGLVActorComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}


// Called every frame
void UEcoGLVActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UEcoGLVActorComponent::VoltkaTick(float DeltaTime)
{

	AEcoGameModeHome* GameMode = Cast<AEcoGameModeHome>(UGameplayStatics::GetGameMode(this));

	//TODO maybe this should be encompassed in a c++ class elder
	// OR passed as an argument and returns newDensity
	TMap<FString, float> Densities = GameMode->EcoDensities;

	
	float OldDensity = Densities.FindRef(Owner->GetName());
	float NewDensity = rate * OldDensity;

	for (const TPair<FString, float>& EcoElderRelationPair : EcoElderRelationVector)
	{
		FString ElderName = EcoElderRelationPair.Key;
		float Relation = EcoElderRelationPair.Value;
		float OtherDensity = Densities.FindRef(ElderName);

		NewDensity += OtherDensity * Relation * OldDensity;
	}

	NewDensity = OldDensity + DeltaTime / 10.0 * NewDensity;

	if (NewDensity < 0.01)
		NewDensity = 0;

	GameMode->NextEcoDensities[Owner->GetName()] = NewDensity;

}

