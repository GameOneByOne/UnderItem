#include "Manager/UIManager.h"
#include "Kismet/GameplayStatics.h"
#include "Utils/log.h"

namespace {
	const FString BATTLE_PANEL_WIDGET_REF = TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/UI/UBP_BattlePanelWidget.UBP_BattlePanelWidget_C'");
	const FString HERO_BAG_WIDGET_REF = TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/UI/UBP_HeroBagWidget.UBP_HeroBagWidget_C'");
	const FString HERO_STATUS_WIDGET_REF = TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/UI/WBP_HeroStatusPanel.WBP_HeroStatusPanel_C'");
}

AUIManager::AUIManager()
{
	PrimaryActorTick.bCanEverTick = false;
	BattlePanelWidget = LoadClass<UBattlePanelWidget>(this, *BATTLE_PANEL_WIDGET_REF);
	HeroBagWidget = LoadClass<UHeroBagWidget>(this, *HERO_BAG_WIDGET_REF);
	HeroStatusPanelWidget = LoadClass<UHeroStatusPanel>(this, *HERO_STATUS_WIDGET_REF);
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
}

void AUIManager::ShowHeroBag()
{
	if (HeroBag->IsValidLowLevel()) {
		return;
	}
	
	HeroBag = CreateWidget<UHeroBagWidget>(Cast<APlayerController>(GWorld->GetFirstPlayerController()), HeroBagWidget);
	HeroBag->Initialize();
	HeroBag->AddToViewport();
}

void AUIManager::ShowHeroStatus()
{
	if (HeroStatusPanel->IsValidLowLevel()) {
		return;
	}
	
	HeroStatusPanel = CreateWidget<UHeroStatusPanel>(Cast<APlayerController>(GWorld->GetFirstPlayerController()), HeroStatusPanelWidget);
	HeroStatusPanel->Initialize();
	HeroStatusPanel->SetHeroPtr(Cast<AHero>(UGameplayStatics::GetActorOfClass(GetWorld(), AHero::StaticClass())));
	HeroStatusPanel->AddToViewport();
}

void AUIManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

