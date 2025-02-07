// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Monster.h"

#include "Kismet/GameplayStatics.h"
#include "Manager/BattleManager.h"
#include "Utils/log.h"

void AMonster::BeginInteract(TObjectPtr<ACharacterBase> ActorPtr)
{
    TObjectPtr<ABattleManager> BattleManager = Cast<ABattleManager>(UGameplayStatics::GetActorOfClass(GetWorld(), ABattleManager::StaticClass()));
    BattleManager->StartBattle(ActorPtr, this);
    return;
}