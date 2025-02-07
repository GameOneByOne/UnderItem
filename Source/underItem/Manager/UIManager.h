// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "GameFramework/Actor.h"
#include "UI/BattlePanelWidget.h"
#include "UIManager.generated.h"

UCLASS()
class UNDERITEM_API AUIManager : public AActor
{
	GENERATED_BODY()
	
public:	
	AUIManager();
	virtual void Tick(float DeltaTime) override;
	void ShowBattlePanel(TObjectPtr<ACharacterBase> HeroPtr, TObjectPtr<ACharacterBase> MonsterPtr);

protected:
	virtual void BeginPlay() override;

public:
	TSubclassOf<UBattlePanelWidget> BattlePanelWidget;

};
