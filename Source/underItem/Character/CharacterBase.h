// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "Config/CharacterConfig.h"
#include "CharacterBase.generated.h"

/**
 * 
 */
UCLASS()
class UNDERITEM_API ACharacterBase : public APaperCharacter
{
	GENERATED_BODY()
	
private:
	TObjectPtr<UDataTable> CharacterConfigDataTable = nullptr;
	FCharacterConfig CharacterConfig;
	
public:
	ACharacterBase();

protected:
	virtual void BeginPlay() override;

public:
	int32 CurrentHP;
	int32 CurrentAttackPower;
	int32 CurrentDefensePower;

public:
	bool SetCharacter(const FString& CharacterName);
	// 战斗相关
	void Attack(ACharacterBase* Opponent);
	void RecoverHP(int32 HP);
	bool IsDead() const;
};
