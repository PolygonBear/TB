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
	// Collision->OnComponentBeginOverlap.AddDynamic(this, &APointOfInterests::OnOverlap);
	// Collision->OnComponentEndOverlap.AddDynamic(this, &APointOfInterests::OnEndOverlap);
}

// void APointOfInterests::OnOverlap(UPrimitiveComponent* OverlappedComponent,AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
// {
// 	if(OtherActor)
// 	{
// 		bIsOccupied = true;
// 		UE_LOG(LogTemp, Warning, TEXT("%s"), *GetOwner()->GetName());	
// 	}
// 	else
// 	{
// 		UE_LOG(LogTemp, Warning, TEXT("NO!"));	
// 	}
//
// 	
// 	
// }
//
// void APointOfInterests::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
// {
// 	bIsOccupied = false;
// }




