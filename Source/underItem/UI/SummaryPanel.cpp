#include "UI/SummaryPanel.h"
#include "Utils/log.h"
#include "GamePlay/MyGameMode.h"
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
	UGameplayStatics::OpenLevel(GetWorld(), "OneLevel", true, FString("GameMode=") + AMyGameMode::StaticClass()->GetName());
	return;
}

void USummaryPanel::EndGame()
{
	return;
}