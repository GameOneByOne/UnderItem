// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Manager/LevelManager.h"
#include "Manager/BattleManager.h"
#include "GameManager.generated.h"

UCLASS()
class UNDERITEM_API AGameManager : public AActor
{
	GENERATED_BODY()

private:
	TObjectPtr<ALevelManager> LevelManager = nullptr;
	TObjectPtr<ABattleManager> BattleManager = nullptr;
	TObjectPtr<AUIManager> UIManager = nullptr;
	
public:	
	// Sets default values for this actor's properties
	AGameManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
