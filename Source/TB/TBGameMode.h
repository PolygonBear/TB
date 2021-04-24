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
		
	int32 GetEnemyCount();
	int32 WorkersCount = 0;

	int GoodCount = 0;
	int NormalCount = 0;
	int BadCount = 0;

	WorkersMood CheckBrigadeMood();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	WorkersMood MoodResult;
	

};



