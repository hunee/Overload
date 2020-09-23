// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "OverloadSaveGame.generated.h"

USTRUCT(BlueprintType)
struct FOverloadSaveData
{
	GENERATED_USTRUCT_BODY()

	/** Score to beat to get gold. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 GoldScore;

	/** Score to beat to get silver. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 SilverScore;

	/** Score to beat to get bronze. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 BronzeScore;

	/** Player's personal best score. Not necessarily a gold-medal score. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 TopScore;
};


/**
 * 
 */
UCLASS()
class OVERLOAD_API UOverloadSaveGame : public USaveGame
{
	GENERATED_BODY()
	
};
