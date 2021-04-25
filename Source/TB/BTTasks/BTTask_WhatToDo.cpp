// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_WhatToDo.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TB/TBCharacter.h"

UBTTask_WhatToDo::UBTTask_WhatToDo()
{
	NodeName = TEXT("AI What to do?");
}

EBTNodeResult::Type UBTTask_WhatToDo::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	OwnerComp.GetBlackboardComponent()->SetValueAsBool("isWorking", true);

	return EBTNodeResult::Succeeded;
}
