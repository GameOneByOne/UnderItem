// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Config/LevelConfig.h"
#include "GameFramework/Actor.h"
#include "LevelManager.generated.h"

UCLASS()
class UNDERITEM_API ALevelManager : public AActor
{
	GENERATED_BODY()

private:
	TObjectPtr<UDataTable> LevelConfigDataTable = nullptr;
	FLevelConfig LevelConfig;
	
public:
	ALevelManager();

protected:
	virtual void BeginPlay() override;

public:
	void Generate();
	void SetLevel(int32 Level);
	int NextLevel();

};
