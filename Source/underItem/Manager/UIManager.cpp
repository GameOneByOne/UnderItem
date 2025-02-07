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
	TObjectPtr<UBattlePanelWidget> BattlePanel = CreateWidget<UBattlePanelWidget>(Cast<APlayerController>(HeroPtr->GetController()), BattlePanelWidget);
	BattlePanel->Initialize();
	FIntPoint ScreenXY = GEngine->GameViewport->Viewport->GetSizeXY();

	BattlePanel->AddToViewport();

	BattlePanel->ForceLayoutPrepass();
	FVector2D tmp = BattlePanel->GetDesiredSize();
	BattlePanel->SetPositionInViewport({ScreenXY.X / 2.0, ScreenXY.Y / 2.0}, true);
}

void AUIManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

