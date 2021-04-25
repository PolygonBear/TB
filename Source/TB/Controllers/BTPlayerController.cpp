// Fill out your copyright notice in the Description page of Project Settings.


#include "BTPlayerController.h"

#include "Blueprint/UserWidget.h"


void ABTPlayerController::BeginPlay()
{
	Super::BeginPlay();

	HUD = CreateWidget(this, HUDClass);
	if(HUD != nullptr)
	{
		HUD->AddToViewport();	
	}	
}

void ABTPlayerController::GameHasEnded(AActor* EndGameFocus, bool bIsWinner)
{
	Super::GameHasEnded(EndGameFocus, bIsWinner);

	HUD->RemoveFromViewport();
	if(bIsWinner)
	{
		UUserWidget* WinScreen = CreateWidget(this, WinScreeClass);
		if(WinScreen != nullptr)
		{
			WinScreen->AddToViewport();
		}
	}
	else
	{
		UUserWidget* LoseScreen = CreateWidget(this, LoseScreeClass);
		if(LoseScreen != nullptr)
		{
			LoseScreen->AddToViewport();
		}
	}

	//Рестарт уровня
	GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
}
