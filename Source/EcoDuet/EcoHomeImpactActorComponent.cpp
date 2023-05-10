// Fill out your copyright notice in the Description page of Project Settings.


#include "EcoHomeImpactActorComponent.h"

// Sets default values for this component's properties
UEcoHomeImpactActorComponent::UEcoHomeImpactActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UEcoHomeImpactActorComponent::BeginPlay()
{
	Super::BeginPlay();
	AActor* Owner = this->GetOwner();
	
	AEcoPlantActor* PlantActor = Cast<AEcoPlantActor>(Owner);

	if (PlantActor)
		this->OwnerActorClass = AEcoPlantActor::StaticClass();
	
}

// TODO it'd be better if each actor killed himself if above the carrying capacity and lowest fitness or oldest/newest
void UEcoHomeImpactActorComponent::ControlTargetSpecies()
{
	TArray<AActor*> FoundTargets;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), TargetActorClass, FoundTargets);

	int NumPlants = FoundTargets.Num();

	if (NumPlants > SelfCarryingCapacity) {
		AEcoPlantActor* plant = Cast<AEcoPlantActor>(FoundTargets[0]);
		plant->Destroy();
	}
}

void UEcoHomeImpactActorComponent::SuicideIfOverCapacity()
{
	AActor* Owner = this->GetOwner();

	AEcoGameStateHome* GameState = Cast<AEcoGameStateHome>(GetWorld()->GetGameState());

	int RemainingCarryingCapacity = GameState->RemainingCarryingCapacity;

	if (RemainingCarryingCapacity == 0)
	{
		TActorIterator<AActor> It(GetWorld(), this->OwnerActorClass);
		It->Destroy();
	}
}


void UEcoHomeImpactActorComponent::VoltkaTick()
{

	AEcoGameModeHome* GameMode = Cast<AEcoGameModeHome>(UGameplayStatics::GetGameMode(this));

	TSubclassOf<AEcoPlantActor> ClassToFind = AEcoPlantActor::StaticClass();
	TArray<AActor*> FoundTargets;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ClassToFind, FoundTargets);

	int NumPlants = FoundTargets.Num();

	if (NumPlants > SelfCarryingCapacity) {
		AEcoPlantActor* plant = Cast<AEcoPlantActor>(FoundTargets[0]);
		plant->Destroy();
	}

	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::FromInt(NumPlants));

	//for (TActorIterator<AEcoPlantActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	//{
	//	if (GEngine)
	//		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, ActorItr->GetName());
	//}
}

// Called every frame
void UEcoHomeImpactActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


}

