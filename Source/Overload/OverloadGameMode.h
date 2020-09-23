// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "Blueprint/UserWidget.h"
#include "OverloadSaveGame.h"

#include "OverloadGameMode.generated.h"


DECLARE_LOG_CATEGORY_EXTERN(LogOverloadGameMode, Log, All);


/**
 * 
 */
UCLASS()
class OVERLOAD_API AOverloadGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	AOverloadGameMode(const FObjectInitializer& ObjectInitializer);

	/** Called when the game starts. */
	virtual void BeginPlay() override;

	/** Remove the current menu widget and create a new one from the specified class, if provided. */
	UFUNCTION(BlueprintCallable, Category = "UMG")
	void ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass);

	/** Used to force update the scores in the save data, say from the leader boards */
	UFUNCTION(BlueprintCallable, Category = "Save Game")
	void UpdateScoresFromLeaderBoard(int32 GoldScore, int32 SilverScore, int32 BronzeScore);

	/** Notifies when the player has received a bonus/reward, currently a time increase. */
	UFUNCTION(BlueprintImplementableEvent, Category = "Game")
	void AwardBonus();

	/** Add points. If points are negative or we force immediate update, the score will display instantly instead of counting up. */
	UFUNCTION(BlueprintCallable, Category = "Game")
	void AddScore(int32 Points, bool bForceImmediateUpdate = false);

	/** scrore request. */
	UFUNCTION(BlueprintPure, Category = "Game")
	int32 GetComboPower();

	/** Combo power request. */
	UFUNCTION(BlueprintPure, Category = "Game")
	int32 GetMaxComboPower();

	/** Bomb power request (current) - susceptible to BP overriding by the Match3PlayerController. */
	UFUNCTION(BlueprintNativeEvent, Category = "Game")
	int32 CalculateBombPower();
	virtual int32 CalculateBombPower_Implementation();

	/** Get the actual score (not the score that is displayed) */
	UFUNCTION(BlueprintCallable, Category = "Game")
	int32 GetScore();

public:
	/** Current data being saved/loaded. Held as a UPROPERTY for GC reasons. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FOverloadSaveData SaveGameData;

protected:
	/** The widget class we will use as our menu when the game starts. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI Widget")
	TSubclassOf<UUserWidget> StartingWidgetClass;

	/** The widget class we will use as our game over screen when the player loses. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI Widget")
	TSubclassOf<UUserWidget> DefeatWidgetClass;

	/** The widget class we will use as our game over screen when the player wins. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI Widget")
	TSubclassOf<UUserWidget> VictoryWidgetClass;

	/** The widget instance that we are using as our menu. */
	UPROPERTY()
	UUserWidget* CurrentWidget;

	/** Current actual score, though not the display value. */
	UPROPERTY()
	int32 Score;

///
private:
    class UDataTable* LevelUpDataTable;


};
