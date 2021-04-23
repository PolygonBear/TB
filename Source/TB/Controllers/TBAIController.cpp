// Fill out your copyright notice in the Description page of Project Settings.


#include "TBAIController.h"


#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TB/PointOfInterests/PointOfInterests.h"


void ATBAIController::BeginPlay()
{
	Super::BeginPlay();

	PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	APointOfInterests* Points = Cast<APointOfInterests>(GetPawn());
	if(AIBehavior !=nullptr)
	{
		RunBehaviorTree(AIBehavior);
		GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
		
		if(Points != nullptr)
		{
			GetBlackboardComponent()->SetValueAsVector(TEXT("FirstLocation"), GetPawn()->GetActorLocation() + Points->FirstLocation);
			GetBlackboardComponent()->SetValueAsVector(TEXT("SecondLocation"), GetPawn()->GetActorLocation() + Points->SecondLocation);	
			GetBlackboardComponent()->SetValueAsVector(TEXT("ThirdLocation"), GetPawn()->GetActorLocation() + Points->ThirdLocation);
			GetBlackboardComponent()->SetValueAsVector(TEXT("FourthLocation"), GetPawn()->GetActorLocation() + Points->FourthLocation);
			GetBlackboardComponent()->SetValueAsVector(TEXT("ThirdLocation"), GetPawn()->GetActorLocation() + Points->FifthLocation);	
		}
		else UE_LOG(LogTemp, Error, TEXT("cast failed"));
	}
}

void ATBAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);	
}



