// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_ClearLocationKey.h"

#include "BehaviorTree/BlackboardComponent.h"

UBTTask_ClearLocationKey::UBTTask_ClearLocationKey()
{
	NodeName = TEXT("Clear Blackboard Value");
}

EBTNodeResult::Type UBTTask_ClearLocationKey::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());

	return EBTNodeResult::Succeeded;
}
