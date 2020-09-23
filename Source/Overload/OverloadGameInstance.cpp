// Fill out your copyright notice in the Description page of Project Settings.

#include "Overload.h"

#include "Kismet/GameplayStatics.h"
#include "UnrealClient.h"
#include "Online.h"
#include "OnlineSubsystem.h"

#include "OverloadGameInstance.h"

UOverloadGameInstance::UOverloadGameInstance()
{
	DefaultSaveGameSlot = TEXT("_Overload");
}

void UOverloadGameInstance::Init()
{
	// Point to a default save slot at startup. We will later change our save slot when we log in.
	InitSaveGameSlot();

	
	///LoginChangedHandle = FCoreDelegates::OnUserLoginChangedEvent.AddUObject(this, &UOverloadGameInstance::OnLoginChanged);
	///EnteringForegroundHandle = FCoreDelegates::ApplicationHasEnteredForegroundDelegate.AddUObject(this, &UOverloadGameInstance::OnEnteringForeground);
	///EnteringBackgroundHandle = FCoreDelegates::ApplicationWillEnterBackgroundDelegate.AddUObject(this, &UOverloadGameInstance::OnEnteringBackground);
	ViewportHandle = FViewport::ViewportResizedEvent.AddUObject(this, &UOverloadGameInstance::OnViewportResize_Internal);

	/**IOnlinePurchasePtr PurchaseInterface = Online::GetPurchaseInterface();
	if (PurchaseInterface.IsValid())
	{
		UnexpectedPurchaseHandle = PurchaseInterface->AddOnUnexpectedPurchaseReceiptDelegate_Handle(FOnUnexpectedPurchaseReceiptDelegate::CreateUObject(this, &UOverloadGameInstance::OnUnexpectedPurchase_Internal));
	}**/

	Super::Init();
}



void UOverloadGameInstance::Shutdown()
{
	///FCoreDelegates::OnUserLoginChangedEvent.Remove(LoginChangedHandle);
	///FCoreDelegates::ApplicationHasEnteredForegroundDelegate.Remove(EnteringForegroundHandle);
	///FCoreDelegates::ApplicationWillEnterBackgroundDelegate.Remove(EnteringBackgroundHandle);
	FViewport::ViewportResizedEvent.Remove(ViewportHandle);
	

	Super::Shutdown();
}

void UOverloadGameInstance::InitSaveGameSlot()
{
	const FString SaveSlotName = GetSaveSlotName();
	if (!UGameplayStatics::DoesSaveGameExist(SaveSlotName, 0))
	{
		// Clear default save file, if it exists.
		if (UGameplayStatics::DoesSaveGameExist(DefaultSaveGameSlot, 0))
		{
			UGameplayStatics::DeleteGameInSlot(DefaultSaveGameSlot, 0);
		}
		// If we have no save object, create one.
		if (InstanceGameData == nullptr)
		{
			// We're either not logged in with an Online ID, or we have no save data to transfer over (usually, this indicates program startup).
			InstanceGameData = Cast<UOverloadSaveGame>(UGameplayStatics::CreateSaveGameObject(UOverloadSaveGame::StaticClass()));
		}
		UGameplayStatics::SaveGameToSlot(InstanceGameData, SaveSlotName, 0);
	}
	else
	{
		InstanceGameData = Cast<UOverloadSaveGame>(UGameplayStatics::LoadGameFromSlot(SaveSlotName, 0));
	}
	
  check(InstanceGameData);
}

void UOverloadGameInstance::SaveGame()
{
	UGameplayStatics::SaveGameToSlot(InstanceGameData, GetSaveSlotName(), 0);
}


void UOverloadGameInstance::UpdateSave(UObject* WorldContextObject, FOverloadSaveData& NewData)
{
	const FString LevelName = UGameplayStatics::GetCurrentLevelName(WorldContextObject, true);
///	InstanceGameData->Match3SaveData.FindOrAdd(LevelName) = NewData;
///	UpdateUIAfterSave();
}


FString UOverloadGameInstance::GetSaveSlotName() const
{
	return SaveGamePrefix + DefaultSaveGameSlot;
}

void UOverloadGameInstance::RegisterOnlineID(FString NewOnlineID)
{
	SaveGamePrefix = NewOnlineID;
	InitSaveGameSlot();
}

void UOverloadGameInstance::OnViewportResize_Internal(FViewport* Viewport, uint32 ID)
{
	///OnViewportResize();
}

void UOverloadGameInstance::OnUnexpectedPurchase_Internal(const FUniqueNetId& UserId)
{
	///OnUnexpectedPurchase();
}