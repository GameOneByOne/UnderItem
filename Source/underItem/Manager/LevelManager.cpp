#include "LevelManager.h"
#include "Utils/log.h"
#include "Character/CharacterBase.h"
#include "Character/Monster.h"
#include "Kismet/GameplayStatics.h"

namespace {
	const FString LEVEL_CONFIG_DATATABLE_REF = TEXT("/Script/Engine.DataTable'/Game/Data/DT_LevelConfig.DT_LevelConfig'");	
	const int32 MIN_PROBABILITY = 1;
	const int32 MAX_PROBABILITY = 100;
}

ALevelManager::ALevelManager()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ALevelManager::BeginPlay()
{
	Super::BeginPlay();

	// 加载配置数据表格
	LevelConfigDataTable = LoadObject<UDataTable>(nullptr, *LEVEL_CONFIG_DATATABLE_REF);
}

void ALevelManager::Generate()
{
	TArray<AActor*> RangeActors;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), "GenerateMonsterRange", RangeActors);
	
	FRandomStream RandomStream;
	for (int i = 0; i < LevelConfig.GenerateMonsterNum; ++i) {
		RandomStream.GenerateNewSeed();
		int32 Result = RandomStream.RandRange(MIN_PROBABILITY, MAX_PROBABILITY);
		int32 TotalProbability = 0;
		for (const auto &Iter : LevelConfig.MonsterGenerateLevelDistribution) {
			TotalProbability += Iter.Y;
			if (Result > TotalProbability) {
				continue;
			}

			// 选定一个生成范围
			RandomStream.GenerateNewSeed();
			int32 RangeIndex = RandomStream.RandRange(0, RangeActors.Num() - 1);
			FVector Origin, Extend;
			RangeActors[RangeIndex]->GetActorBounds(true, Origin, Extend);
			RandomStream.GenerateNewSeed();
			int32 RandomX = RandomStream.RandRange(Origin.X - Extend.X / 2, Origin.X + Extend.X / 2);
			RandomStream.GenerateNewSeed();
			int32 RandomY = RandomStream.RandRange(Origin.Y - Extend.Y / 2, Origin.Y + Extend.Y / 2);
			
			// 开始生成
			FVector Location = {static_cast<double>(RandomX), static_cast<double>(RandomY), 10};
			FRotator Rotation = {0, 0, 0};
			TObjectPtr<AMonster> Monster = Cast<AMonster>(GetWorld()->SpawnActor(AMonster::StaticClass(), &Location, &Rotation));
			if (Monster->IsValidLowLevel()) {
				Monster->SetCharacter("Skeleton");
				Monster->OnMonsterDead.AddDynamic(this, &ALevelManager::DealMonsterDead);
			} else {
				ERRORLOG("[Level Mgr] Spawn Actor failed.");
				LevelConfig.GenerateMonsterNum--;
			}
			break;
		}
	}
}

ELevelStatus ALevelManager::SetLevel(int32 Level)
{
	if (!LevelConfigDataTable->IsValidLowLevel()) {
		ERRORLOG("[Level Mgr] SetLevel Failed Because Of Data Type Not Loaded.");
		return ELevelStatus::DATA_NOT_LOAD;
	}

	// 读取对应关卡的配置数据
	const FName LevelRowName = FName(FString::FromInt(Level));
	FLevelConfig *Config = LevelConfigDataTable->FindRow<FLevelConfig>(LevelRowName, LevelRowName.ToString());
	if (!Config) {
		ERRORLOG("[Level Mgr] SetLevel Failed Because Of Row Name Not Found.");
		return ELevelStatus::LEVEL_END;
	}
	INFOLOG("[Level Mgr] Set Level Config to GenNum Is %d", Config->GenerateMonsterNum);
	for (const auto &Iter : Config->MonsterGenerateLevelDistribution)
	{
		INFOLOG("[Level Mgr] Level Config Monster Distribution, Level is %d, Properbility is %d",
			FMath::TruncToInt(Iter.X), FMath::TruncToInt(Iter.Y));
	}
	LevelConfig = *Config;
	return ELevelStatus::SUCCEED;
}

ELevelStatus ALevelManager::NextLevel()
{
	return SetLevel(LevelConfig.CurrentLevel + 1);
}

void ALevelManager::DealMonsterDead()
{
	LevelConfig.GenerateMonsterNum--;
	if (LevelConfig.GenerateMonsterNum == 0) {
		if (NextLevel() == ELevelStatus::SUCCEED) {
			Generate();
		}
	}
	return;
}

