// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"

#include "OverloadSaveGame.h"

#include "OverloadGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class OVERLOAD_API UOverloadGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:

	UOverloadGameInstance();

	// Called by the game at startup.
	void Init() override;

	// Called by the game as it shuts down.
	void Shutdown() override;

	// This function is used to initialize or change our save game slot. Data is transferred when creating a new, non-default slot.
	void InitSaveGameSlot();

	/** Save our game. All save game data is included. */
	UFUNCTION(BlueprintCallable, Category = "Saved Game")
	void SaveGame();

	/** Create or update the saved data for a specific Match3 level. */
	void UpdateSave(UObject* WorldContextObject, FOverloadSaveData& NewData);

	/** Event for refreshing the UI after save games are updated */
	///UFUNCTION(BlueprintImplementableEvent)
	///void UpdateUIAfterSave();

	/** Combined save game data for all levels/modes. */
	UPROPERTY()
	class UOverloadSaveGame* InstanceGameData;

	// Should be called by blueprints when the user's ID changes, such as by logging in or out via the game's blueprint menu system.
	UFUNCTION(BlueprintCallable, Category = "Online")
	void RegisterOnlineID(FString NewOnlineID);

	// Called when the user logs in or out on a mobile device.
	///UFUNCTION(BlueprintImplementableEvent, Category = "Online")
	///void OnLoginChanged(bool bLoggingIn, int32 UserID, int32 UserIndex);

	// Called when the application has just entered the foreground.
	///UFUNCTION(BlueprintImplementableEvent, Category = "Online")
	///void OnEnteringForeground();

	// Called when the application is about to enter the background.
	///UFUNCTION(BlueprintImplementableEvent, Category = "Online")
	///void OnEnteringBackground();

	// Internal function to bind to viewport resizing delegate
	void OnViewportResize_Internal(FViewport* Viewport, uint32 ID);

	// Blueprint event to use to respond to viewport resizing, since FViewport* is not a valid Blueprint pin type
	///UFUNCTION(BlueprintImplementableEvent, Category = "UI")
	///void OnViewportResize();

	// Internal function to bind to unexpected purchase delegate
	void OnUnexpectedPurchase_Internal(const FUniqueNetId& UserId);
	
	// Called when the application has received a purchase event outside of the purchase flow.
	///UFUNCTION(BlueprintImplementableEvent, Category = "Online")
	///void OnUnexpectedPurchase();

protected:
	FString GetSaveSlotName() const;
	FString SaveGamePrefix;
	FString DefaultSaveGameSlot;

private:
	FDelegateHandle LoginChangedHandle;
	FDelegateHandle EnteringForegroundHandle;
	FDelegateHandle EnteringBackgroundHandle;
	FDelegateHandle ViewportHandle;
	FDelegateHandle UnexpectedPurchaseHandle;

};
