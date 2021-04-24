// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TB/TBCharacter.h"

#include "EnemyCharacter.generated.h"

UENUM(BlueprintType)
enum class WorkersState : uint8 {
	Work,
	Idle,
	Hand,
	Inspire
};

UCLASS()
class TB_API AEnemyCharacter : public ATBCharacter
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	WorkersState WorkerState = WorkersState::Work;

	float PlayerWorkPoints;
	
	UPROPERTY(EditAnywhere)
	float PlayerWorkPointsDivision = 2.f;

	virtual void Tick(float DeltaSeconds) override;

protected:
	virtual void BeginPlay() override;	
	
	
};
