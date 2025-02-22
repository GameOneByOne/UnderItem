#include "UI/SummaryPanel.h"


bool USummaryPanel::Initialize()
{
	if (!Super::Initialize()) {
		return false;
	}
	
	// BeginGameBtn->OnClicked.AddDynamic(this, &USummaryPanel::BeginGame);
	// ExitGameBtn->OnClicked.AddDynamic(this, &USummaryPanel::EndGame);
	return true;
}

void USummaryPanel::BeginGame()
{
	return;
}

void USummaryPanel::EndGame()
{
	return;
}