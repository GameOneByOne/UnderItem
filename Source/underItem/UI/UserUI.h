#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI/BattlePanelWidget.h"
#include "UI/HeroBagWidget.h"
#include "UI/HeroStatusPanel.h"
#include "UserUI.generated.h"


UCLASS()
class UNDERITEM_API UUserUI : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual bool Initialize() override;
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UHeroStatusPanel> HeroStatusPanel;
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UHeroBagWidget> HeroBagWidget;
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UBattlePanelWidget> BattlePanelWidget;
};
