// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_ExecuteWork.h"

#include "AIController.h"
#include "TB/Characters/EnemyCharacter.h"


UBTTask_ExecuteWork::UBTTask_ExecuteWork()
{
	NodeName = TEXT("Execute work");
}

EBTNodeResult::Type UBTTask_ExecuteWork::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	AEnemyCharacter* Character = Cast<AEnemyCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	Character->ChangeWorkingState();
	if(Character->WorkerState == WorkersState::Work)
	{
		UE_LOG(LogTemp, Warning, TEXT("WORK!"));
	}
	else if(Character->WorkerState == WorkersState::Idle)
	{
		UE_LOG(LogTemp, Warning, TEXT("Idle!"));
	}
	else if(Character->WorkerState == WorkersState::Hand)
	{
		UE_LOG(LogTemp, Warning, TEXT("Hand!"));
	}
	

	return EBTNodeResult::Succeeded;
}
