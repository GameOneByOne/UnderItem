#include "GamePlay/WelcomeGameMode.h"

#include "HeroPlayerController.h"
#include "Blueprint/UserWidget.h"
#include "UI/SummaryPanel.h"

namespace {
    const FString WELCOME_WIDGET_REF = "/Script/UMGEditor.WidgetBlueprint'/Game/UI/WBP_SummaryPanel.WBP_SummaryPanel_C'";
}

AWelcomeGameMode::AWelcomeGameMode()
{
    DefaultPawnClass = nullptr;
    PlayerControllerClass = AHeroPlayerController::StaticClass();
    TSubclassOf<USummaryPanel> WelcomePanelWidget = LoadClass<USummaryPanel>(this, *WELCOME_WIDGET_REF);
    if (UUserWidget *WelcomPanel = CreateWidget<UUserWidget>(GetWorld(), WelcomePanelWidget)) {
        WelcomPanel->AddToViewport();
    }
}