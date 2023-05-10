// Fill out your copyright notice in the Description page of Project Settings.


#include "EcoBaseActor.h"

// Sets default values
AEcoBaseActor::AEcoBaseActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEcoBaseActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEcoBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

