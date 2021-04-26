// Copyright Epic Games, Inc. All Rights Reserved.

#include "TBGameMode.h"

#include "EngineUtils.h"
#include "Characters/EnemyCharacter.h"
#include "Controllers/BTPlayerController.h"
#include "Controllers/TBAIController.h"
#include "Kismet/GameplayStatics.h"



ATBGameMode::ATBGameMode()
{
	PrimaryActorTick.bStartWithTickEnabled = true;
	PrimaryActorTick.bCanEverTick = true;
}

void ATBGameMode::BeginPlay()
{
	Super::BeginPlay();

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemyCharacter::StaticClass(), WorkersActors); //Записываем всех ИИ для проверки в массив

	//Проверка общего настроения каждые 5 секунд 
	FTimerHandle TimerHandle;
	FTimerHandle TimerHandle2;
	FTimerHandle TimerHandle3;
	FTimerDelegate TimerDel;
	TimerDel.BindUFunction(this, FName("CheckBrigadeMood"));
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerDel, 5.f, true);
	RemainingTime = MaxTime;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle3, this, &ATBGameMode::TimerDecrease, 1.f, true);
	
}

void ATBGameMode::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
	EndGame();
}

void ATBGameMode::TimerDecrease()
{
	RemainingTime -= 1;
}

void ATBGameMode::SetCurrentProgress()
{
	for(AActor* Actor : WorkersActors)
	{
		AEnemyCharacter* Worker = Cast<AEnemyCharacter>(Actor);
		CurrentProgress += Worker->AIWorkPoints;
	}	
}

WorkersMood ATBGameMode::CheckBrigadeMood() // проверка общего настроения
 {	 	
 	for(AActor* Actor : WorkersActors)
 	{
 		AEnemyCharacter* Worker = Cast<AEnemyCharacter>(Actor);
 		
 		if(Worker == nullptr)
 		{
 			continue;
 		}			
 		if(Worker->WorkerMood == WorkersMood::Good)
 		{
 			GoodCount++;
 		}
 		if(Worker->WorkerMood == WorkersMood::Normal)
 		{
 			NormalCount++;
 		}
 		if(Worker->WorkerMood == WorkersMood::Bad)
 		{
			BadCount++;
 		}
 	}

	int a, b, c;

	a = GoodCount;
	b = NormalCount;
	c = BadCount;

 	if ( a > b && a > c )
 	{
 		UE_LOG(LogTemp, Warning, TEXT("GoodCount = %i"), a);
 		MoodResult = WorkersMood::Good;
 	}			
 	else if ( b > a && b > c )
 	{
 		UE_LOG(LogTemp, Warning, TEXT("NormalCount = %i"), b);
 		MoodResult = WorkersMood::Normal;
 	}		
 	else if ( c > a && c > b )
 	{
 		UE_LOG(LogTemp, Warning, TEXT("BadCount = %i"), c);
		MoodResult = WorkersMood::Bad;
 	}			
 	else
 	{
 		UE_LOG(LogTemp, Warning, TEXT("Values are not unique"));
 	}
	GoodCount = 0;
	NormalCount = 0;
	BadCount = 0;
 	return MoodResult;
 }

void ATBGameMode::EndGame()
{
	APlayerController* Controller = Cast<ABTPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	
	if(RemainingTime == 0)
	{
		bool bIsPlayerWinner = false;
		Controller->GameHasEnded(Controller->GetPawn(), bIsPlayerWinner);
	}
	if (RemainingTime > 0 && CurrentProgress >= 100)
	{
		bool bIsPlayerWinner = true;
		Controller->GameHasEnded(Controller->GetPawn(), !bIsPlayerWinner);
	}
}

