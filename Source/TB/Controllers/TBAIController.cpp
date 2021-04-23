// Fill out your copyright notice in the Description page of Project Settings.


#include "TBAIController.h"


#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TB/PointOfInterests/PointOfInterests.h"


void ATBAIController::BeginPlay()
{
	Super::BeginPlay();

	if(AIBehavior !=nullptr)
	{
		RunBehaviorTree(AIBehavior);
	}
}

void ATBAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);	
}



