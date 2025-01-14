// Fill out your copyright notice in the Description page of Project Settings.


#include "Manager/GameManager.h"
#include "Kismet/GameplayStatics.h"
#include "Utils/log.h"


AGameManager::AGameManager()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AGameManager::BeginPlay()
{
	Super::BeginPlay();
	LevelManager = Cast<ALevelManager>(UGameplayStatics::GetActorOfClass(GetWorld(), ALevelManager::StaticClass()));
	BattleManager = Cast<ABattleManager>(UGameplayStatics::GetActorOfClass(GetWorld(), ABattleManager::StaticClass()));
	if (!LevelManager->IsValidLowLevel() || !BattleManager->IsValidLowLevel()) {
		ERRORLOG("[Game Mgr] World Need Level Manager And Battle Manager Exist.");
		return;
	}

	// 生成关卡
	LevelManager->SetLevel(1);
	LevelManager->Generate();
}

// Called every frame
void AGameManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

