#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/TileView.h"
#include "Character/Hero.h"
#include "HeroBagWidget.generated.h"


UCLASS()
class UNDERITEM_API UHeroBagWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual bool Initialize() override;
	void Update();

public:
	UPROPERTY(meta = (BindWidget))
	UTileView* BagPanel;
	UPROPERTY(meta = (BindWidget))
	UButton* PreBagPageButton;
	UPROPERTY(meta = (BindWidget))
	UButton* NextBagPageButton;

	int CurrentPage = 1;
	TObjectPtr<AHero> HeroPtr;
};
