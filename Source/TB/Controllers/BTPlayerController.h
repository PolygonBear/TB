// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BTPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TB_API ABTPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	float RestartDelay = 5.f;
	FTimerHandle RestartTimer;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> LoseScreeClass;
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> WinScreeClass;
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> HUDClass;
	UPROPERTY(EditAnywhere)
	UUserWidget* HUD;
	
protected:
	virtual void BeginPlay() override;
	
	void GameHasEnded(AActor* EndGameFocus, bool bIsWinner);
};
