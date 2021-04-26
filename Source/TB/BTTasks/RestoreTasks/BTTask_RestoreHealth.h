// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_RestoreHealth.generated.h"

/**
 * 
 */
UCLASS()
class TB_API UBTTask_RestoreHealth : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_RestoreHealth();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory) override;
};
