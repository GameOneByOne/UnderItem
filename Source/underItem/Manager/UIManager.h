#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "GameFramework/Actor.h"
#include "UI/BattlePanelWidget.h"
#include "UI/HeroBagWidget.h"
#include "UIManager.generated.h"

UCLASS()
class UNDERITEM_API AUIManager : public AActor
{
	GENERATED_BODY()
	
public:	
	AUIManager();
	virtual void Tick(float DeltaTime) override;
	void ShowBattlePanel(TObjectPtr<ACharacterBase> HeroPtr, TObjectPtr<ACharacterBase> MonsterPtr);
	void HideBattlePanel();
	void ShowHeroBag();

public:
	TSubclassOf<UBattlePanelWidget> BattlePanelWidget;
	TSubclassOf<UHeroBagWidget> HeroBagWidget;

protected:
	virtual void BeginPlay() override;

private:
	TObjectPtr<UBattlePanelWidget> BattlePanel;
	TObjectPtr<UHeroBagWidget> HeroBag;
};
