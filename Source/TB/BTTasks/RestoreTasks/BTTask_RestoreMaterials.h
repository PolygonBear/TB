// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_RestoreMaterials.generated.h"

/**
 * 
 */
UCLASS()
class TB_API UBTTask_RestoreMaterials : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_RestoreMaterials();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory) override;
	
};
