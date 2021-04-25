// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_WhereToMove.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TB/TBCharacter.h"
#include "TB/PointOfInterests/InteractiveTables.h"

UBTService_WhereToMove::UBTService_WhereToMove()
{
	NodeName = "Where To Move";
}

void UBTService_WhereToMove::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	ATBCharacter* Player = Cast<ATBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (Player == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Cast failed"));
		return;
	}
	
	TArray<AActor*> InteractiveTables;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AInteractiveTables::StaticClass(), InteractiveTables);
	
	if(Player->MoveToMoodPoint == true)
	{
		for (AActor* Actor : InteractiveTables)
		{
			AInteractiveTables* Table = Cast<AInteractiveTables>(Actor);
			if(Table->bMoodTable == true)
			{
				OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), Table->GetActorLocation());
			}
		}
	}
	if(Player->MoveToMoodPoint == true)
	{
		for (AActor* Actor : InteractiveTables)
		{
			AInteractiveTables* Table = Cast<AInteractiveTables>(Actor);
			if(Table->bHealTable == true)
			{
				OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), Table->GetActorLocation());
			}
		}
	}
}
