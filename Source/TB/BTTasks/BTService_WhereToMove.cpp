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

	
	if(Player->MoveToMoodPoint == true)
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsBool("MoveToMood", Player->MoveToMoodPoint);
	}
	else
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsBool("MoveToMood", Player->MoveToMoodPoint);
	}
	
	if(Player->MoveToHealPoint == true)
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsBool("MoveToHeal", Player->MoveToHealPoint);
	}
	else
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsBool("MoveToHeal", Player->MoveToHealPoint);
	}
	
	if(Player->MoveToMaterialPoint == true)
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsBool("MoveToMaterial", Player->MoveToMaterialPoint);
	}
	else
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsBool("MoveToMaterial", Player->MoveToMaterialPoint);
	}

	if(Player->MoveToFoodPoint == true)
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsBool("MoveToFood", Player->MoveToFoodPoint);
	}
	else
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsBool("MoveToFood", Player->MoveToFoodPoint);
	}
}


//TArray<AActor*> InteractiveTables;
//UGameplayStatics::GetAllActorsOfClass(GetWorld(), AInteractiveTables::StaticClass(), InteractiveTables);

// for (AActor* Actor : InteractiveTables)
// {
// 	AInteractiveTables* Table = Cast<AInteractiveTables>(Actor);
// 	if(Table->bMoodTable == true)
// 	{
// 		OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), Table->GetActorLocation());
// 	}
// }
