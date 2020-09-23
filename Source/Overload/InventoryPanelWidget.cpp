// Fill out your copyright notice in the Description page of Project Settings.

#include "Overload.h"

#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"
#include "Components/Button.h"

#include "InventoryPanelWidget.h"

DEFINE_LOG_CATEGORY(LogInventoryPanelWidget);

void UInventoryPanelWidget::NativeConstruct()
{
	// Call the Blueprint "Event Construct" node
	Super::NativeConstruct();

  UE_LOG(LogInventoryPanelWidget, Log, TEXT("->> UInventoryPanelWidget::NativeConstruct()"));

 	// Listener
  ///StartGamePathButton->OnClicked.AddDynamic(this, &UInventoryPanelWidget::OnStartGamePathButtonPressed);
  StartGamePathButton->OnClicked.AddDynamic(this, &UInventoryPanelWidget::StartDialog);
}


void UInventoryPanelWidget::OnStartGamePathButtonPressed()
{
  //GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("UInventoryPanelWidget::OnStartGamePathButtonPressed."));  
  UE_LOG(LogInventoryPanelWidget, Log, TEXT("->> UInventoryPanelWidget::OnStartGamePathButtonPressed()"));

}

void UInventoryPanelWidget::StartDialog_Implementation()
{
  UE_LOG(LogInventoryPanelWidget, Log, TEXT("->> UInventoryPanelWidget::StartDialog_Implementation()"));
}
void UInventoryPanelWidget::FinishDialog_Implementation()
{
  UE_LOG(LogInventoryPanelWidget, Log, TEXT("->> UInventoryPanelWidget::FinishDialog_Implementation()"));
}