// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TB/TBCharacter.h"

#include "EnemyCharacter.generated.h"

UENUM(BlueprintType)
enum class WorkersState : uint8 {
	Initial, Work, Idle, Hand
};

UENUM(BlueprintType)
enum class WorkersMood : uint8 {
	Good ,
	Normal ,
	Bad 
};

UCLASS()
class TB_API AEnemyCharacter : public ATBCharacter
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaSeconds) override;	

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	WorkersState WorkerState = WorkersState::Initial;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	WorkersMood WorkerMood;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxMood = 100.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = 0.0f, UIMin = 0.0f))
	float CurrentMood;
	UPROPERTY(EditAnywhere)
	float MoodDecraseRate = 1.f;

	void DecreaseMood(float DeltaSeconds);
	
	UPROPERTY(EditAnywhere)
	float AIWorkPoints = 0;
	
	float PlayerWorkPoints;
	
	UPROPERTY(EditAnywhere)
	float IdleWorkPointsDivision = 2.f;

	WorkersState ChangeWorkingState();
	WorkersMood ChangeWorkingMood();
	

protected:
	virtual void BeginPlay() override;
	void CheckWorkerState();
};
