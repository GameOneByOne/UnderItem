#include "UI/SummaryPanel.h"
#include "Utils/log.h"
#include "Kismet/GameplayStatics.h"


bool USummaryPanel::Initialize()
{
	if (!Super::Initialize()) {
		return false;
	}
	
	BeginGameBtn->OnClicked.AddDynamic(this, &USummaryPanel::BeginGame);
	ExitGameBtn->OnClicked.AddDynamic(this, &USummaryPanel::EndGame);
	return true;
}

void USummaryPanel::BeginGame()
{
	INFOLOG("1111111111111111");
	UGameplayStatics::OpenLevel(GetWorld(), "OneLevel", true, FString("GameMode=") + NewGameModeClass->GetName())
	return;
}

void USummaryPanel::EndGame()
{
	INFOLOG("2222222222222222");
	return;
}