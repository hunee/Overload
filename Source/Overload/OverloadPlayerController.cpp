// Fill out your copyright notice in the Description page of Project Settings.

#include "Overload.h"

#include "OverloadPlayerController.h"

AOverloadPlayerController::AOverloadPlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// We want the mouse cursor to show immediately on startup, without having to click in the window.
	bShowMouseCursor = true;

	// We need click/touch events to interact with our tiles.
	bEnableTouchEvents = bEnableClickEvents = true;
	bEnableTouchOverEvents = bEnableMouseOverEvents = true;
}
