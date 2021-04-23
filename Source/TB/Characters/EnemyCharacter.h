// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TB/TBCharacter.h"

#include "EnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class TB_API AEnemyCharacter : public ATBCharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, meta = (MakeEditWidget))
	FVector FirstLocation;
	UPROPERTY(EditAnywhere, meta = (MakeEditWidget))
	FVector SecondLocation;
	UPROPERTY(EditAnywhere, meta = (MakeEditWidget))
	FVector ThirdLocation;		
	
};
