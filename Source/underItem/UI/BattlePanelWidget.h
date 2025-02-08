// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Character/Hero.h"
#include "Character/Monster.h"
#include "Components/TextBlock.h"
#include "BattlePanelWidget.generated.h"

/**
 * 
 */
UCLASS()
class UNDERITEM_API UBattlePanelWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual bool Initialize() override;
	void SetHeroObj(TObjectPtr<ACharacterBase> Obj);
	UFUNCTION(BlueprintCallable)
	FText GetHeroHP();
	UFUNCTION(BlueprintCallable)
	FText GetHeroAttack();
	UFUNCTION(BlueprintCallable)
	FText GetHeroDefense();
	UFUNCTION(BlueprintCallable)
	FText GetHeroName();
	
	void SetMonsterObj(TObjectPtr<ACharacterBase> Obj);
	UFUNCTION(BlueprintCallable)
	FText GetMonsterHP();
	UFUNCTION(BlueprintCallable)
	FText GetMonsterAttack();
	UFUNCTION(BlueprintCallable)
	FText GetMonsterDefense();
	UFUNCTION(BlueprintCallable)
	FText GetMonsterName();
	
public:
	UPROPERTY(meta = (BindWidget))
	UTextBlock* HeroNameText;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* HeroHPText;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* HeroAttackText;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* HeroDefenseText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* MonsterNameText;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* MonsterHPText;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* MonsterAttackText;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* MonsterDefenseText;
	
private:
	TObjectPtr<ACharacterBase> HeroObj;
	TObjectPtr<ACharacterBase> MonsterObj;
};
