// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TB/TBCharacter.h"

#include "EnemyCharacter.generated.h"

UENUM(BlueprintType)
enum class WorkersState : uint8 {
	Work ,
	Idle ,
	Hand ,
	Inspire 
};

UCLASS()
class TB_API AEnemyCharacter : public ATBCharacter
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaSeconds) override;	

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	WorkersState WorkerState;

	UPROPERTY(EditAnywhere)
	float AIWorkPoints;
	
	float PlayerWorkPoints;
	
	UPROPERTY(EditAnywhere)
	float PlayerWorkPointsDivision = 2.f;

	bool bPretendWorking = false;

	WorkersState ChangeWorkingState();

protected:
	virtual void BeginPlay() override;

	
	
	
};
