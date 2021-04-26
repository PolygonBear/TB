// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_WhatToDo.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "TB/Characters/EnemyCharacter.h"

class AEnemyCharacter;

UBTTask_WhatToDo::UBTTask_WhatToDo()
{
	NodeName = TEXT("AI What to do?");
}

EBTNodeResult::Type UBTTask_WhatToDo::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	AEnemyCharacter* Character = Cast<AEnemyCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	Character->bIsWorking = true;

	OwnerComp.GetBlackboardComponent()->SetValueAsBool("isWorking", Character->bIsWorking);

	return EBTNodeResult::Succeeded;
}
