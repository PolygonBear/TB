// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "Characters/EnemyCharacter.h"
#include "GameFramework/GameModeBase.h"
#include "TBGameMode.generated.h"

UCLASS(minimalapi)
class ATBGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATBGameMode();
	
	virtual void BeginPlay() override;

protected:
	virtual void Tick(float DeltaSeconds) override;
	void TimerDecrease();

	void SetCurrentProgress();
	UPROPERTY(EditAnywhere, BlueprintReadWrite) 
	float CurrentProgress = 0.f; // Текущий прогресс работы


	UFUNCTION()
	WorkersMood CheckBrigadeMood(); //проверка общего настроения
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	WorkersMood MoodResult; //возвращаем значение общего настроения
	
	TArray<AActor*> WorkersActors; //массив ии
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RemainingTime = 100;
	
	void EndGame();	

private:
	int GoodCount = 0;
	int NormalCount = 0;
	int BadCount = 0;

	
};



