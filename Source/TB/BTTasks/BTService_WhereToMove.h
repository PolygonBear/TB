// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_WhereToMove.generated.h"

/**
 * 
 */
UCLASS()
class TB_API UBTService_WhereToMove : public UBTService_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTService_WhereToMove();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
