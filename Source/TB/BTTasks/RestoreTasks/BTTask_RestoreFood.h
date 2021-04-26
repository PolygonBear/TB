// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_RestoreFood.generated.h"

/**
 * 
 */
UCLASS()
class TB_API UBTTask_RestoreFood : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_RestoreFood();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory) override;
	
};
