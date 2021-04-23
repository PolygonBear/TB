// Copyright Epic Games, Inc. All Rights Reserved.

#include "TBGameMode.h"
#include "TBCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATBGameMode::ATBGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
