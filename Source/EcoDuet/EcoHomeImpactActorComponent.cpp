// Fill out your copyright notice in the Description page of Project Settings.


#include "EcoHomeImpactActorComponent.h"

// Sets default values for this component's properties
UEcoHomeImpactActorComponent::UEcoHomeImpactActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// representation
	//M[row][column] because (0,0,0,1) is on M[0:3][3]
	//M = [
	//	[InX.X, InX.Y, InX.Z, InX.W],
	//	[InY.X, InY.Y, InY.Z, InY.W],
	//	[InZ.X, InZ.Y, InZ.Z, InZ.W],
	//	[InW.X, InW.Y, InW.Z, InW.W],
	//]

	//this->A = FMatrix(FPlane(-0.1, -0.3, 0, 0), FPlane(0.2, -0.1, 0, 0), FPlane(0, 0, -0.2, 0), FPlane(0, 0, -0.04, 0));
	this->A = FMatrix(FPlane(-0.1, 0.2, 0, 0), FPlane(-0.3, -0.1, 0.1, 0), FPlane(0, -0.2, -0.04, 0), FPlane(0, 0, 0, 0));

	//this->A.M[0][0] = -0.1;
	//this->A.M[1][0] = 0.2;
	//this->A.M[2][0] = 0;
	//this->A.M[3][0] = 0;
	//
	//this->A.M[0][1] = -0.3;
	//this->A.M[1][1] = -0.1;
	//this->A.M[2][1] = 0.1;
	//this->A.M[3][1] = 0;

	//this->A.M[0][2] = 0;
	//this->A.M[1][2] = 0;
	//this->A.M[2][2] = -0.2;
	//this->A.M[3][2] = -0.04;

	//this->A.M[0][3] = 0;
	//this->A.M[1][3] = 0;
	//this->A.M[2][3] = 0;
	//this->A.M[3][3] = 0;

	this->r = FVector4(-0.3, 0.08, 0.8, 0.);

	this->x0 = FVector4(0.6, 1.5, 10., 0.);
	this->x = x0;


}

FVector4 UEcoHomeImpactActorComponent::DotProduct(FMatrix Mat, FVector4 v)
{
	FVector4 w;


	w[0] = Mat.M[0][0] * v[0] + Mat.M[0][1] * v[1] + Mat.M[0][2] * v[2] + Mat.M[0][3] * v[3];
	w[1] = Mat.M[1][0] * v[0] + Mat.M[1][1] * v[1] + Mat.M[1][2] * v[2] + Mat.M[1][3] * v[3];
	w[2] = Mat.M[2][0] * v[0] + Mat.M[2][1] * v[1] + Mat.M[2][2] * v[2] + Mat.M[2][3] * v[3];
	w[3] = Mat.M[3][0] * v[0] + Mat.M[3][1] * v[1] + Mat.M[3][2] * v[2] + Mat.M[3][3] * v[3];

	return w;
}

// Called when the game starts
void UEcoHomeImpactActorComponent::BeginPlay()
{
	Super::BeginPlay();
	AActor* Owner = this->GetOwner();
	
	AEcoPlantActor* PlantActor = Cast<AEcoPlantActor>(Owner);

	if (PlantActor)
		this->OwnerActorClass = AEcoPlantActor::StaticClass();
	
	AEcoGameModeHome* GameMode = Cast<AEcoGameModeHome>(UGameplayStatics::GetGameMode(this));

	GameMode->EcologyDensities = this->x0;

	GetWorld()->GetTimerManager().SetTimer(EcoDensitiesTimerHandle, this, &UEcoHomeImpactActorComponent::VoltkaUpdate, EcoDensitiesUpdateTime, true);

}

void UEcoHomeImpactActorComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	GetWorld()->GetTimerManager().ClearTimer(EcoDensitiesTimerHandle);
}



void UEcoHomeImpactActorComponent::VoltkaUpdate()
{

	VoltkaTick(EcoDensitiesUpdateTime);
}

FVector4 UEcoHomeImpactActorComponent::VolterraTick(float DeltaTime)
{
	//GLV
	//x1 = x0 + dt*x0*(r + A.x)

	FVector4 x1 = x + DeltaTime/10.0 * x * (r + DotProduct(A,x));

	return x1;
}

void UEcoHomeImpactActorComponent::VoltkaTick(float DeltaTime)
{

	AEcoGameModeHome* GameMode = Cast<AEcoGameModeHome>(UGameplayStatics::GetGameMode(this));

	this->x = GameMode->EcologyDensities;

	FVector4 new_x = VolterraTick(DeltaTime);

	this->x = new_x;
	GameMode->EcologyDensities = new_x;

	//if (GEngine)
	//{
	//	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, GameMode->EcologyDensities.ToString());
	//	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "r: " + this->r.ToString());
	//}

}


