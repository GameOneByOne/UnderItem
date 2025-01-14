// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelManager.h"
#include "Utils/log.h"
#include "Character/CharacterBase.h"
#include "Kismet/GameplayStatics.h"

namespace {
	const FString LEVEL_CONFIG_DATATABLE_REF = TEXT("/Script/Engine.DataTable'/Game/Data/DT_LevelConfig.DT_LevelConfig'");	
	const int32 MIN_PROBABILITY = 1;
	const int32 MAX_PROBABILITY = 100;
}

ALevelManager::ALevelManager()
{
	PrimaryActorTick.bCanEverTick = false;
	// 加载配置数据表格
	static ConstructorHelpers::FObjectFinder<UDataTable> LoadDataTable(*LEVEL_CONFIG_DATATABLE_REF);
	if (LoadDataTable.Succeeded()) {
		LevelConfigDataTable = LoadDataTable.Object;
	}
}

void ALevelManager::BeginPlay()
{
	Super::BeginPlay();
}

void ALevelManager::Generate()
{
	TArray<AActor*> RangeActors;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), "GenerateMonsterRange", RangeActors);
	INFOLOG("[Level Mgr] Find %d Range To Generate Monster.", RangeActors.Num());
	
	FRandomStream RandomStream;
	for (int i = 0; i <LevelConfig.GenerateMonsterNum; ++i) {
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
			INFOLOG("[Level Mgr] Generate Range  (Origin=%s , Extend=%s)", *Origin.ToString(), *Extend.ToString());
			// 开始生成
			FVector Location = {static_cast<double>(RandomX), static_cast<double>(RandomY), 10};
			FRotator Rotation = {0, 0, 0};
			TObjectPtr<ACharacterBase> Character = Cast<ACharacterBase>(GetWorld()->SpawnActor(ACharacterBase::StaticClass(), &Location, &Rotation));
			if (Character->IsValidLowLevel()) {
				Character->SetCharacter("Hero1");
				INFOLOG("[Level Mgr] Generate Monster In (%d,  %d)", RandomX, RandomY);
			} else {
				ERRORLOG("[Level Mgr] Spawn Actor failed.");
			}
			break;
		}
	}
}

void ALevelManager::SetLevel(int32 Level)
{
	if (!LevelConfigDataTable->IsValidLowLevel()) {
		ERRORLOG("[Level Mgr] SetLevel Failed Because Of Data Type Not Loaded.");
		return;
	}

	// 读取对应关卡的配置数据
	const FName LevelRowName = FName(FString::FromInt(Level));
	FLevelConfig *Config = LevelConfigDataTable->FindRow<FLevelConfig>(LevelRowName, LevelRowName.ToString());
	if (!Config) {
		ERRORLOG("[Level Mgr] SetLevel Failed Because Of Row Name Not Found.");
		return;
	}
	INFOLOG("[Level Mgr] Set Level Config to GenNum Is %d", Config->GenerateMonsterNum);
	for (const auto &Iter : Config->MonsterGenerateLevelDistribution)
	{
		INFOLOG("[Level Mgr] Level Config Monster Distribution, Level is %d, Properbility is %d",
			FMath::TruncToInt(Iter.X), FMath::TruncToInt(Iter.Y));
	}
	LevelConfig = *Config;
	return;
}

int ALevelManager::NextLevel()
{
	SetLevel(LevelConfig.CurrentLevel + 1);
	return LevelConfig.CurrentLevel;
}

