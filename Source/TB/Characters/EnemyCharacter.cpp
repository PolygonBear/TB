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


WorkersState AEnemyCharacter::ChangeWorkingState()
{
	int Value =	FMath::RandRange(1, 100);
	
	if(Value<=10)
	{
		return WorkerState = WorkersState::Hand;
	}
	if (Value>10 && Value<=40)
	{
		return WorkerState = WorkersState::Idle;
	}
	if (Value>40 && Value<=100)
	{
		return WorkerState = WorkersState::Work;
	}
	
	return WorkerState;
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
			PlayerWorkPoints = PlayerWorkPoints / PlayerWorkPointsDivision;
			break;
		}
	case WorkersState::Work:
		{
			AIWorkPoints = 0.01;	
			break;
		}
	default:
		break;
	}
}


