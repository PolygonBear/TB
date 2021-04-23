// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TBAIController.generated.h"

/**
 * 
 */
UCLASS()
class TB_API ATBAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	virtual void Tick(float DeltaSeconds) override;
	
protected:
	virtual void BeginPlay() override;

private:
	APawn* PlayerPawn;
	
	UPROPERTY(EditDefaultsOnly)
	class UBehaviorTree* AIBehavior; 
	
};
