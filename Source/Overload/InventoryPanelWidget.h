// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryPanelWidget.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogInventoryPanelWidget, Log, All);

///class UProgressBar;
///class UButton;

/**
 * 
 */
UCLASS()
class OVERLOAD_API UInventoryPanelWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "MainHUD")
	void StartDialog();
	virtual void StartDialog_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "MainHUD")
	void FinishDialog();
	virtual void FinishDialog_Implementation();

protected:
	virtual void NativeConstruct() override;

protected:
	//Button
	UPROPERTY (meta = (BindWidget))
	class UButton* StartGamePathButton;	

	UFUNCTION()
	void OnStartGamePathButtonPressed();

protected:
	UPROPERTY(meta=(BindWidget))
	class UProgressBar* ManaBar;	

};
