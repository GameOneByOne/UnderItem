#include "Manager/BattleManager.h"
#include "Utils/log.h"

namespace {
	const float BATTLE_INTERVAL = 0.5f;
}


ABattleManager::ABattleManager()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ABattleManager::BeginPlay()
{
	Super::BeginPlay();
}

void ABattleManager::Tick(float DeltaTime)
{
	static float LastBattleTime = 0.f;
	Super::Tick(DeltaTime);
	if (!BattleStarted) {
		return;
	}

	if (LastBattleTime <= BATTLE_INTERVAL) {
		LastBattleTime += DeltaTime;
		return;
	}

	// 战斗逻辑
	LastBattleTime = 0.f;
	if (ShouldHeroBattle) {
		Hero->Attack(Monster);
	} else {
		Monster->Attack(Hero);
	}
	ShouldHeroBattle = !ShouldHeroBattle;

	// 判断战斗是否结束
	if (Hero->IsDead() || Monster->IsDead()) {
		INFOLOG("[Battle Mgr] Battle Is Ended. Winner Is %s", Hero->IsDead() ? TEXT("Monster") : TEXT("Hero"));
		BattleStarted = false;
	}
	return;
}

void ABattleManager::StartBattle(TObjectPtr<ACharacterBase> HeroPtr, TObjectPtr<ACharacterBase> MonsterPtr)
{
	this->Hero = HeroPtr;
	this->Monster = MonsterPtr;
	BattleStarted = true;
	FRandomStream RandomStream;
	RandomStream.GenerateNewSeed();
	if (RandomStream.RandRange(1, 100) <= 50) {
		ShouldHeroBattle = true;
	}
	return;
}

