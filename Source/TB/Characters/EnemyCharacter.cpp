// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter.h"
#include "Kismet/GameplayStatics.h"

void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	CurrentMood = MaxMood;
	ATBCharacter* Player = Cast<ATBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	PlayerWorkPoints = Player->WorkPoints;
}

void AEnemyCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	ChangeWorkingMood();
	CheckWorkerState();
	DecreaseMood(DeltaSeconds);
}

void AEnemyCharacter::DecreaseMood(float DeltaSeconds)
{
	CurrentMood = CurrentMood - MoodDecraseRate * DeltaSeconds;
}

WorkersMood AEnemyCharacter::ChangeWorkingMood()
{
	if(CurrentMood>=70)
	{
		return WorkerMood = WorkersMood::Good;
	}
	if (CurrentMood<70 && CurrentMood>=40)
	{
		return WorkerMood = WorkersMood::Normal;
	}
	if (CurrentMood<40)
	{
		return WorkerMood = WorkersMood::Bad;
	}

	return WorkerMood;
}

WorkersState AEnemyCharacter::ChangeWorkingState()
{
	//int Value =	FMath::RandRange(1, 100);
	
	if(WorkerMood == WorkersMood::Bad)
	{
		return WorkerState = WorkersState::Hand;
	}
	if (WorkerMood == WorkersMood::Normal)
	{
		return WorkerState = WorkersState::Idle;
	}
	if (WorkerMood == WorkersMood::Good)
	{
		return WorkerState = WorkersState::Work;
	}
	
	return WorkerState;
}
void AEnemyCharacter::CheckWorkerState()
{
	switch (WorkerState)
	{
	case WorkersState::Hand:
		{
			AIWorkPoints = -1;
			break;
		}
	case WorkersState::Idle:
		{
			AIWorkPoints = 0;
			PlayerWorkPoints = PlayerWorkPoints / IdleWorkPointsDivision;
			break;
		}
	case WorkersState::Work:
		{
			AIWorkPoints = 0.5;	
			break;
		}
	default:
		break;
	}
}