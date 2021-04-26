// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_RestoreMood.h"

#include "AIController.h"
#include "TB/Characters/EnemyCharacter.h"


UBTTask_RestoreMood::UBTTask_RestoreMood()
{
	NodeName = TEXT("Restore Mood");
}

EBTNodeResult::Type UBTTask_RestoreMood::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	AEnemyCharacter* Character = Cast<AEnemyCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	Character->CurrentMood = Character->MaxMood;

	return EBTNodeResult::Succeeded;
}

