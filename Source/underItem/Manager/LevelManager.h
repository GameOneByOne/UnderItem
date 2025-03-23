#pragma once

#include "CoreMinimal.h"
#include "Config/LevelConfig.h"
#include "GameFramework/Actor.h"
#include "LevelManager.generated.h"

enum class ELevelStatus {
	SUCCEED, DATA_NOT_LOAD, DATA_NOT_FIND, LEVEL_END
};

UCLASS()
class UNDERITEM_API ALevelManager : public AActor
{
	GENERATED_BODY()

public:
	ALevelManager();
	void Generate();
	ELevelStatus SetLevel(int32 Level);
	ELevelStatus NextLevel();

public:
	UFUNCTION(BlueprintCallable)
	void DealMonsterDead();

protected:
	virtual void BeginPlay() override;
	
private:
	FVector GetMonsterGenerateRandomLocation(TArray<AActor*> RangeActors) const;
private:
	TObjectPtr<UDataTable> LevelConfigDataTable = nullptr;
	FLevelConfig LevelConfig;
};
