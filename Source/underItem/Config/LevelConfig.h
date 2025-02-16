#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LevelConfig.generated.h"

USTRUCT(BlueprintType)
struct FLevelConfig : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 CurrentLevel;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 GenerateMonsterNum;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FVector2f> MonsterGenerateLevelDistribution;
};