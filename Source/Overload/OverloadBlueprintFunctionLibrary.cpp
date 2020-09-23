// Fill out your copyright notice in the Description page of Project Settings.

#include "Overload.h"

#include "GameFramework/PlayerController.h"

#include "OverloadBlueprintFunctionLibrary.h"

APlayerController* UOverloadBlueprintFunctionLibrary::GetLocalPlayerController(UObject* WorldContextObject)
{
	if (UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
	{
		for (FConstPlayerControllerIterator Iterator = World->GetPlayerControllerIterator(); Iterator; ++Iterator)
		{
			APlayerController* PlayerController = Iterator->Get();
			if (PlayerController && PlayerController->IsLocalController())
			{
				// For this project, we will only ever have one local player.
				return PlayerController;
			}
		}
	}
	return nullptr;
}

FString UOverloadBlueprintFunctionLibrary::GetOnlineAccountID(APlayerController* PlayerController)
{
	/**if (PlayerController && PlayerController->PlayerState && PlayerController->PlayerState->GetUniqueId().IsValid())
	{
		return PlayerController->PlayerState->GetUniqueId()->GetHexEncodedString();
	}**/
	return FString();
}
