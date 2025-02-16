#pragma once

#include "CoreMinimal.h"
#include "Config/LevelConfig.h"
#include "GameFramework/Actor.h"
#include "LevelManager.generated.h"

UCLASS()
class UNDERITEM_API ALevelManager : public AActor
{
	GENERATED_BODY()

public:
	ALevelManager();
	void Generate();
	void SetLevel(int32 Level);
	int NextLevel();

protected:
	virtual void BeginPlay() override;
	
private:
	TObjectPtr<UDataTable> LevelConfigDataTable = nullptr;
	FLevelConfig LevelConfig;
};
