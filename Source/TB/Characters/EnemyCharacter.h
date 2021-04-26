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
	UPROPERTY(BlueprintReadWrite, meta = (ClampMin = 0.0f, UIMin = 0.0f))
	float CurrentMood;
	UPROPERTY(EditAnywhere)
	float MoodDecraseRate = 1.f;
	void DecreaseMood(float DeltaSeconds);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxHealth = 100.f;
	UPROPERTY(BlueprintReadWrite, meta = (ClampMin = 0.0f, UIMin = 0.0f))
	float CurrentHealth;
	UPROPERTY(EditAnywhere)
	float HealthDecraseRate = 1.f;
	void DecreaseHealth(float DeltaSeconds);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxMaterial = 100.f;
	UPROPERTY(BlueprintReadWrite, meta = (ClampMin = 0.0f, UIMin = 0.0f))
	float CurrentMaterial;
	UPROPERTY(EditAnywhere)
	float MaterialDecraseRate = 1.f;
	void DecreaseMaterial();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxFood = 100.f;
	UPROPERTY(BlueprintReadWrite, meta = (ClampMin = 0.0f, UIMin = 0.0f))
	float CurrentFood;
	UPROPERTY(EditAnywhere)
	float FoodDecraseRate = 1.f;
	void DecreaseFood(float DeltaSeconds);	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = 0.0f, UIMin = 0.0f))
	float AIWorkPoints = 1;
		
	WorkersState ChangeWorkingState();
	WorkersMood ChangeWorkingMood();

	bool bIsWorking = false;

	float CheckWorkerMood();

	void PositiveWork();
	void NegativeWork();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = 0, ClampMax = 100, UIMin = 0, UIMax = 100), Category = "Chance on add points")
	int ChanceDecreaseWorkPointOnGoodMood = 20;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = 0, ClampMax = 100, UIMin = 0, UIMax = 100), Category = "Chance on add points")
	int ChanceDecreaseWorkPointOnNormalMood = 50;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = 0, ClampMax = 100, UIMin = 0, UIMax = 100), Category = "Chance on add points")
	int ChanceDecreaseWorkPointOnBadMood = 80;

	UPROPERTY(EditAnywhere, Category = "Particles")
	UParticleSystem* GoodParticle;

	UPROPERTY(EditAnywhere, Category = "Particles")
	UParticleSystem* BadParticle;

	UPROPERTY(EditAnywhere, Category = "Sound")
	USoundBase* GoodSound;

	UPROPERTY(EditAnywhere, Category = "Sound")
	USoundBase* BadSound;

};
