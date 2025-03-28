#include "Manager/BattleManager.h"
#include "Kismet/GameplayStatics.h"
#include "Utils/log.h"

namespace {
	const float BATTLE_INTERVAL = 0.1f;
}


ABattleManager::ABattleManager()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ABattleManager::BeginPlay()
{
	Super::BeginPlay();
	UIManager = Cast<AUIManager>(UGameplayStatics::GetActorOfClass(GetWorld(), AUIManager::StaticClass()));
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
		BattleStarted = false;
		UIManager->HideBattlePanel();
		if (Monster->IsDead()) {
			Monster->PreDestroy(Hero);
		}
	}
	return;
}

void ABattleManager::StartBattle(TObjectPtr<ACharacterBase> HeroPtr, TObjectPtr<ACharacterBase> MonsterPtr)
{
	this->Hero = HeroPtr;
	this->Monster = MonsterPtr;
	FRandomStream RandomStream;
	RandomStream.GenerateNewSeed();
	if (RandomStream.RandRange(1, 100) <= 50) {
		ShouldHeroBattle = true;
	}

	UIManager->ShowBattlePanel(HeroPtr, MonsterPtr);
	BattleStarted = true;
	return;
}

