#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Character/CharacterBase.h"
#include "Manager/UIManager.h"
#include "BattleManager.generated.h"

UCLASS()
class UNDERITEM_API ABattleManager : public AActor
{
	GENERATED_BODY()
	
public:	
	ABattleManager();
	virtual void Tick(float DeltaTime) override;
	void StartBattle(TObjectPtr<ACharacterBase> HeroPtr, TObjectPtr<ACharacterBase> MonsterPtr);
	
protected:
	virtual void BeginPlay() override;

private:
	bool BattleStarted = false;
	bool ShouldHeroBattle = false;
	TObjectPtr<AUIManager> UIManager;
	TObjectPtr<ACharacterBase> Hero;
	TObjectPtr<ACharacterBase> Monster;

};
