#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "GameFramework/Actor.h"
#include "UI/UserUI.h"
#include "UIManager.generated.h"

UCLASS()
class UNDERITEM_API AUIManager : public AActor
{
	GENERATED_BODY()
	
public:	
	AUIManager();
	virtual void Tick(float DeltaTime) override;
	void ShowUI();
	void ShowBattlePanel(TObjectPtr<ACharacterBase> HeroPtr, TObjectPtr<ACharacterBase> MonsterPtr);
	void HideBattlePanel();

public:
	TSubclassOf<UUserUI> UserUIWidget;

protected:
	virtual void BeginPlay() override;

private:
	TObjectPtr<UUserUI> UserUI;
};
