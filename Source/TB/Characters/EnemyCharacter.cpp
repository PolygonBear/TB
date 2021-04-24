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
				WorkPoints = -1;
				break;
			}
		case WorkersState::Idle:
			{
				WorkPoints = 0;
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

void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	ATBCharacter* Player = Cast<ATBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	PlayerWorkPoints = Player->WorkPoints;
}
