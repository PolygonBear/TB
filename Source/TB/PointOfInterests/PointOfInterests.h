// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PointOfInterests.generated.h"

UCLASS()
class TB_API APointOfInterests : public AActor
{
	GENERATED_BODY()
	
public:	
	APointOfInterests();

protected:
	virtual void BeginPlay() override;


public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, meta = (MakeEditWidget))
	FVector FirstLocation;
	UPROPERTY(EditAnywhere, meta = (MakeEditWidget))
	FVector SecondLocation;
	UPROPERTY(EditAnywhere, meta = (MakeEditWidget))
	FVector ThirdLocation;
	UPROPERTY(EditAnywhere, meta = (MakeEditWidget))
	FVector FourthLocation;
	UPROPERTY(EditAnywhere, meta = (MakeEditWidget))
	FVector FifthLocation;

};
