// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter.h"
#include "Kismet/GameplayStatics.h"

void AEnemyCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);


	
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
		case WorkersState::Inspire:
			{
				
				break;
			}
		case WorkersState::Work:
		{
			break;
		}
		default:
			break;
	}
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

void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	ATBCharacter* Player = Cast<ATBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	PlayerWorkPoints = Player->WorkPoints;
}


