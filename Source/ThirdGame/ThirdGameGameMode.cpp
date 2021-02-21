// Copyright Epic Games, Inc. All Rights Reserved.

#include "ThirdGameGameMode.h"
#include "ThirdGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

AThirdGameGameMode::AThirdGameGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
