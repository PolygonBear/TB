// Fill out your copyright notice in the Description page of Project Settings.


#include "TBAIController.h"


#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TB/Characters/EnemyCharacter.h"

void ATBAIController::BeginPlay()
{
	Super::BeginPlay();

	PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	AEnemyCharacter* EnemyCharacter = Cast<AEnemyCharacter>(GetPawn());
	if(AIBehavior !=nullptr)
	{
		RunBehaviorTree(AIBehavior);
		GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
		
		if(EnemyCharacter != nullptr)
		{
			GetBlackboardComponent()->SetValueAsVector(TEXT("FirstLocation"), GetPawn()->GetActorLocation() + EnemyCharacter->FirstLocation);
			GetBlackboardComponent()->SetValueAsVector(TEXT("SecondLocation"), GetPawn()->GetActorLocation() + EnemyCharacter->SecondLocation);	
			GetBlackboardComponent()->SetValueAsVector(TEXT("ThirdLocation"), GetPawn()->GetActorLocation() + EnemyCharacter->ThirdLocation);	
		}
		else UE_LOG(LogTemp, Error, TEXT("cast failed"));
	}
}

void ATBAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
}



