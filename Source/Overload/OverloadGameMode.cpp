// Copyright Epic Games, Inc. All Rights Reserved.

#include "Overload.h"

#include "Kismet/GameplayStatics.h"
#include "GameFramework/Pawn.h"

#include "OverloadGameMode.h"

#include "OverloadBlueprintFunctionLibrary.h"

#include "OverloadPlayerController.h"
#include "OverloadGameInstance.h"
#include "OverloadSaveGame.h"

#include "CustomDataTables.h"
#include "UObject/ConstructorHelpers.h"

#include "Modules/ModuleManager.h"

DEFINE_LOG_CATEGORY(LogOverloadGameMode);

AOverloadGameMode::AOverloadGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	///DefaultPawnClass = APawn::StaticClass();
	///PlayerControllerClass = AOverloadPlayerController::StaticClass();

	UE_LOG(LogOverloadGameMode, Log, TEXT("->> AOverloadGameModeBase()"));

	
	static ConstructorHelpers::FObjectFinder<UDataTable> DataTable(TEXT("/Game/Assets/DataTables/LevelUpTable"));
	if (DataTable.Succeeded())
	{
			LevelUpDataTable = DataTable.Object;
	}

/**
static ConstructorHelpers::FClassFinder<APawn> BPClass(TEXT("/Game/Blueprints/TestBlueprintClass"));
if (BPClass.Succeeded() && BPClass.Class != NULL)
{
    // 가져온 BPClass.Class를 통한 작업
}


DropItemStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DropItemMesh"));
RootComponent = DropItemStaticMeshComponent;

static ConstructorHelpers::FObjectFinder<UStaticMesh> HelmetStaticMesh(TEXT("/Game/Item/StaticMesh/SM_Helmet"));
if (HelmetStaticMesh.Succeeded() && HelmetStaticMesh.Object != nullptr)
{
    DropItemStaticMeshComponent->SetStaticMesh(HelmetStaticMesh.Object);
}
**/



}

void AOverloadGameMode::BeginPlay()
{
	Super::BeginPlay();

	ChangeMenuWidget(StartingWidgetClass);
	//GetWorldTimerManager().SetTimer(GameOverTimer, this, &AMatch3GameMode::GameOver, TimeRemaining, false);

	// Get our current save data from the game instance.
	UOverloadGameInstance* GameInstance = Cast<UOverloadGameInstance>(UGameplayStatics::GetGameInstance(this));
	if (GameInstance)
	{
		// If we didn't already have save data, put our defaults into the main array. We'll save it later, if anything noteworthy happens.
		///if (!GameInstance->FindSaveDataForLevel(this, SaveGameData))
		///{
			GameInstance->UpdateSave(this, SaveGameData);
		///}
	}


	if (LevelUpDataTable != nullptr)
    {
        for (int32 i = 1; i <= 10; i++)
        {
            FLevelUpTableRow* LevelUpTableRow = LevelUpDataTable->FindRow<FLevelUpTableRow>(FName(*(FString::FormatAsNumber(i))), FString(""));
            UE_LOG(LogTemp, Log, TEXT("Lv.%d :: ExpToNextLevel(%d) TotalExp(%d)"), i, (*LevelUpTableRow).ExpToNextLevel, (*LevelUpTableRow).TotalExp);
        }
    }
}

void AOverloadGameMode::UpdateScoresFromLeaderBoard(int32 GoldScore, int32 SilverScore, int32 BronzeScore)
{
	UOverloadGameInstance* GameInstance = Cast<UOverloadGameInstance>(UGameplayStatics::GetGameInstance(this));
	
	SaveGameData.BronzeScore = BronzeScore;
	SaveGameData.SilverScore = SilverScore;
	SaveGameData.GoldScore = GoldScore;

	GameInstance->SaveGame();
}

void AOverloadGameMode::AddScore(int32 Points, bool bForceImmediateUpdate)
{
	Score += Points;
	/**if (bForceImmediateUpdate)
	{
		DisplayedScore = (float)Score;
	}
	else
	{
		GetWorldTimerManager().SetTimer(TickScoreDisplayHandle, this, &AMatch3PlayerController::TickScoreDisplay, 0.001f, true);
	}**/

	AwardBonus();

}

int32 AOverloadGameMode::GetScore()
{

	return Score;
}

void AOverloadGameMode::ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass)
{
	if (CurrentWidget)
	{
		CurrentWidget->RemoveFromViewport();
		CurrentWidget = nullptr;
	}

	if (NewWidgetClass)
	{
		if (AOverloadPlayerController* PC = Cast<AOverloadPlayerController>(UOverloadBlueprintFunctionLibrary::GetLocalPlayerController(this)))
		{
			CurrentWidget = CreateWidget<UUserWidget>(PC, NewWidgetClass);
			if (CurrentWidget)
			{
				CurrentWidget->AddToViewport();
			}
		}
	}
}

int32 AOverloadGameMode::GetComboPower()
{
/**	if (AMatch3PlayerController* PC = Cast<AMatch3PlayerController>(UMatch3BlueprintFunctionLibrary::GetLocalPlayerController(this)))
	{
		return PC->ComboPower;
	}**/
	return 0;
}

int32 AOverloadGameMode::GetMaxComboPower()
{
	/**if (AMatch3PlayerController* PC = Cast<AMatch3PlayerController>(UMatch3BlueprintFunctionLibrary::GetLocalPlayerController(this)))
	{
		return PC->MaxComboPower;
	}**/
	return 0;
}

int32 AOverloadGameMode::CalculateBombPower_Implementation()
{
	/**if (AMatch3PlayerController* PC = Cast<AMatch3PlayerController>(UMatch3BlueprintFunctionLibrary::GetLocalPlayerController(this)))
	{
		return PC->CalculateBombPower();
	}**/
	return 0;
}
