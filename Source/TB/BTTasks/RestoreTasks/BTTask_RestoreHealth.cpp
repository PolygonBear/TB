// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_RestoreHealth.h"

#include "AIController.h"
#include "TB/Characters/EnemyCharacter.h"


UBTTask_RestoreHealth::UBTTask_RestoreHealth()
{
	NodeName = TEXT("Restore Mood");
}

EBTNodeResult::Type UBTTask_RestoreHealth::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	AEnemyCharacter* Character = Cast<AEnemyCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	Character->CurrentHealth = Character->MaxHealth;

	return EBTNodeResult::Succeeded;
}


