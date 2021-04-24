// Fill out your copyright notice in the Description page of Project Settings.


#include "PointOfInterests.h"

#include "Components/SphereComponent.h"

// Sets default values
APointOfInterests::APointOfInterests()
{
	PrimaryActorTick.bCanEverTick = true;

	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	Collision->SetupAttachment(RootComponent);
}

void APointOfInterests::BeginPlay()
{
	Super::BeginPlay();	
}

void APointOfInterests::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}



