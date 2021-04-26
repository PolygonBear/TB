// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_RestoreFood.h"

#include "AIController.h"
#include "TB/Characters/EnemyCharacter.h"


UBTTask_RestoreFood::UBTTask_RestoreFood()
{
	NodeName = TEXT("Restore Mood");
}

EBTNodeResult::Type UBTTask_RestoreFood::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	AEnemyCharacter* Character = Cast<AEnemyCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	Character->CurrentFood = Character->MaxFood;

	return EBTNodeResult::Succeeded;
}


