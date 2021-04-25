// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_WhatToDo.generated.h"

/**
 * 
 */
UCLASS()
class TB_API UBTTask_WhatToDo : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_WhatToDo();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory) override;
	
};