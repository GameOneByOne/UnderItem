// Fill out your copyright notice in the Description page of Project Settings.


#include "Manager/UIManager.h"
#include "Utils/log.h"

namespace {
	const FString BATTLE_PANEL_WIDGET_REF = TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/UI/UBP_BattlePanelWidget.UBP_BattlePanelWidget_C'");
}


AUIManager::AUIManager()
{
	PrimaryActorTick.bCanEverTick = false;
	BattlePanelWidget = LoadClass<UBattlePanelWidget>(this, *BATTLE_PANEL_WIDGET_REF);
}

void AUIManager::BeginPlay()
{
	Super::BeginPlay();
	
}

void AUIManager::ShowBattlePanel(TObjectPtr<ACharacterBase> HeroPtr, TObjectPtr<ACharacterBase> MonsterPtr)
{
	if (BattlePanel->IsValidLowLevel()) {
		BattlePanel->SetHeroObj(HeroPtr);
		BattlePanel->SetMonsterObj(MonsterPtr);
		BattlePanel->SetVisibility(ESlateVisibility::Visible);
		return;
	}
	
	BattlePanel = CreateWidget<UBattlePanelWidget>(Cast<APlayerController>(HeroPtr->GetController()), BattlePanelWidget);
	BattlePanel->Initialize();
	BattlePanel->AddToViewport();
	BattlePanel->ForceLayoutPrepass();
	FVector2D WidgetSize = BattlePanel->GetDesiredSize();
	FIntPoint ScreenXY = GEngine->GameViewport->Viewport->GetSizeXY();
	BattlePanel->SetPositionInViewport({(ScreenXY.X - WidgetSize.X) / 2.0, (ScreenXY.Y - WidgetSize.Y) / 2.0}, true);

	BattlePanel->SetHeroObj(HeroPtr);
	BattlePanel->SetMonsterObj(MonsterPtr);
}

void AUIManager::HideBattlePanel()
{
	if (BattlePanel->IsValidLowLevel()) {
		BattlePanel->SetHeroObj(nullptr);
		BattlePanel->SetMonsterObj(nullptr);
		BattlePanel->SetVisibility(ESlateVisibility::Collapsed);
	}
	return;
}

void AUIManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

