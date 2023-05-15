// Fill out your copyright notice in the Description page of Project Settings.


#include "EcoGameModeHome.h"

FVector4 AEcoGameModeHome::GetEcologyDensities()
{
	return this->EcologyDensities;
}

void AEcoGameModeHome::SetEcologyDensities(FVector4 NewEcologyDensities)
{
	//TSubclassOf<AEcoBaseActor> ClassToFind = AEcoBaseActor::StaticClass();
	//TArray<AActor*> FoundTargets;
	//UGameplayStatics::GetAllActorsOfClass(GetWorld(), ClassToFind, FoundTargets);

	//int NumEcoActors = FoundTargets.Num();

	//for (TActorIterator<AEcoPlantActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	//{
	//	if (GEngine)
	//		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, ActorItr->GetName());
	//}
	
	this->EcologyDensities = NewEcologyDensities;

	//call Update population on each AEcoBaseActor
	//for (TActorIterator<AEcoBaseActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		//if (GEngine)
		//	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, ActorItr->GetName());
		
		//auto Comp = ActorItr->GetComponent('PopulationUpdater')
		//Comp->UpdatePopulation()

	}

}
