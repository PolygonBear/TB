// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_RestoreMaterials.h"

#include "AIController.h"
#include "TB/Characters/EnemyCharacter.h"


UBTTask_RestoreMaterials::UBTTask_RestoreMaterials()
{
	NodeName = TEXT("Restore Mood");
}

EBTNodeResult::Type UBTTask_RestoreMaterials::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	AEnemyCharacter* Character = Cast<AEnemyCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	Character->CurrentMaterial = Character->MaxMaterial;

	return EBTNodeResult::Succeeded;
}

