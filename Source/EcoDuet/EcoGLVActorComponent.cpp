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
	
	SpeciesName = this->ComponentTags.Num() > 0 ? this->ComponentTags[0] : "Unknown";

	//Done at blueprint
	//MySpecies = this->ComponentTags.Num() > 0 ? this->ComponentTags[0] : "Unknown";

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

//float UEcoGLVActorComponent::VoltkaTick(float DeltaTime, TMap<FName, float> Densities)
//{
//
//	//AEcoGameModeHome* GameMode = Cast<AEcoGameModeHome>(UGameplayStatics::GetGameMode(this));
//
//	//TODO maybe this should be encompassed in a c++ class elder
//	// OR passed as an argument and returns newDensity
//	//TMap<FString, float> Densities = GameMode->EcoDensities;
//
//	if (!Densities.Contains(SpeciesName))
//	{
//		if (GEngine)
//		{
//			FString Error = FString::Printf(TEXT("VoltkaTickC++ Unknown species %s"), *SpeciesName.ToString());
//			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, *Error);
//		}
//		return 0;
//	}
//
//
//	float OldDensity = Densities.FindRef(SpeciesName);
//	float NewDensity = rate * OldDensity;
//
//	if (GEngine)
//	{
//		FString Info = FString::Printf(TEXT("Known species %s with density %f"), *SpeciesName.ToString(), OldDensity);
//		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, *Info);
//	}
//
//	for (const TPair<FName, float>& EcoElderRelationPair : EcoElderRelationVector)
//	{
//		FName ElderName = EcoElderRelationPair.Key;
//		float Relation = EcoElderRelationPair.Value;
//		float OtherDensity = Densities.FindRef(ElderName);
//
//		NewDensity += OldDensity * Relation * OtherDensity;
//	}
//
//	NewDensity = OldDensity + 0.1f * NewDensity;
//
//	if (NewDensity < 0.01)
//		NewDensity = 0;
//	else if (NewDensity > 200)
//		NewDensity = 200;
//
//	return NewDensity;
//
//}

float UEcoGLVActorComponent::VoltkaSpeciesTick(float DeltaTime, TMap<EEcoSpeciesType, float> Densities)
{

	//AEcoGameModeHome* GameMode = Cast<AEcoGameModeHome>(UGameplayStatics::GetGameMode(this));

	//TODO maybe this should be encompassed in a c++ class elder
	// OR passed as an argument and returns newDensity
	//TMap<FString, float> Densities = GameMode->EcoDensities;

	if (!Densities.Contains(MySpecies))
	{
		if (GEngine)
		{
			FString SpeciesDisplayName = StaticEnum<EEcoSpeciesType>()->GetValueAsString(MySpecies);
			FString Error = FString::Printf(TEXT("VoltkaTickC++ Unknown species %s"), *SpeciesDisplayName);
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, *Error);
		}
		return 0;
	}


	float OldDensity = Densities.FindRef(MySpecies);
	float NewDensity = rate * OldDensity;

	//if (GEngine)
	//{
	//	FString Info = FString::Printf(TEXT("Known species %s with density %f"), *SpeciesName.ToString(), OldDensity);
	//	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, *Info);
	//}

	for (const TPair<EEcoSpeciesType, float>& EcoElderRelationPair : EcoSpeciesRelationVector)
	{
		EEcoSpeciesType ElderSpecies = EcoElderRelationPair.Key;
		float Relation = EcoElderRelationPair.Value;
		float OtherDensity = Densities.FindRef(ElderSpecies);

		NewDensity += OldDensity * Relation * OtherDensity;
	}

	NewDensity = OldDensity + 0.1f * NewDensity;

	if (NewDensity < 0.01)
		NewDensity = 0;
	else if (NewDensity > 200)
		NewDensity = 200;

	return NewDensity;

}

