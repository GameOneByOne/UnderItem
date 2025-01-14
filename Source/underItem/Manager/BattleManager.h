#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Character/CharacterBase.h"
#include "BattleManager.generated.h"

UCLASS()
class UNDERITEM_API ABattleManager : public AActor
{
	GENERATED_BODY()

private:
	bool BattleStarted = false;
	bool ShouldHeroBattle = false;
	TObjectPtr<ACharacterBase> Hero = nullptr;
	TObjectPtr<ACharacterBase> Monster = nullptr;
	
public:	
	ABattleManager();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

public:
	void StartBattle(TObjectPtr<ACharacterBase> HeroPtr, TObjectPtr<ACharacterBase> MonsterPtr);

};
