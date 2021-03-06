// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_ExecuteWork.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TB/TBGameMode.h"
#include "TB/Characters/EnemyCharacter.h"


UBTTask_ExecuteWork::UBTTask_ExecuteWork()
{
	NodeName = TEXT("Execute work");
}

EBTNodeResult::Type UBTTask_ExecuteWork::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	AEnemyCharacter* Character = Cast<AEnemyCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	

	switch (Character->WorkerState)
	{
		case WorkersState::Initial:
			{
				Character->ChangeWorkingState();
				break;
			}
		case WorkersState::Hand:
			{
				Character->WorkerState = WorkersState::Hand;
				break;
			}
		case WorkersState::Idle:
			{
				Character->WorkerState = WorkersState::Idle;
				break;
			}
		case WorkersState::Work:
			{
				Character->ChangeWorkingState();
				break;
			}
		default:
			{
				Character->ChangeWorkingState();
				break;
			}		
	}
	
	if(Character->WorkerState == WorkersState::Work)
	{
		UE_LOG(LogTemp, Warning, TEXT("WORK!"));
	}
	else if(Character->WorkerState == WorkersState::Idle)
	{
		UE_LOG(LogTemp, Warning, TEXT("Idle!"));
	}
	else if(Character->WorkerState == WorkersState::Hand)
	{
		UE_LOG(LogTemp, Warning, TEXT("Hand!"));
	}

	Character->bIsWorking = false;
	OwnerComp.GetBlackboardComponent()->SetValueAsBool("isWorking", Character->bIsWorking);

	Character->DecreaseMaterial(); //уменьшаем количество материала после работы

	ATBGameMode* GameMode = Cast<ATBGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	GameMode->CurrentProgress += Character->CheckWorkerMood();	//проверяем состояние работника и прибавляем в прогресс	

	return EBTNodeResult::Succeeded;
}
