// Copyright Epic Games, Inc. All Rights Reserved.

#include "TBGameMode.h"
#include "TBCharacter.h"
#include "Characters/EnemyCharacter.h"
#include "Controllers/TBAIController.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"



ATBGameMode::ATBGameMode()
{

}

void ATBGameMode::BeginPlay()
{
	Super::BeginPlay();	
}

void ATBGameMode::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
    
	CheckBrigadeMood();
}
    
 WorkersMood ATBGameMode::CheckBrigadeMood()
 {	
 	TArray<AActor*> WorkersActors;
 	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemyCharacter::StaticClass(), WorkersActors);
 	
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


