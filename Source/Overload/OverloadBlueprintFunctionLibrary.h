// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OverloadBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class OVERLOAD_API UOverloadBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:

	/** Get a list of all player controllers, then pick the first local one we find. */
	UFUNCTION(BlueprintCallable, Category = "Gameplay", Meta = (WorldContext = "WorldContextObject"))
	static APlayerController* GetLocalPlayerController(UObject* WorldContextObject);

	/** Get the online account ID (as an encoded hex string) associated with the provided player controller's player state. Returns a blank string on failure. */
	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	static FString GetOnlineAccountID(APlayerController* PlayerController);
};
