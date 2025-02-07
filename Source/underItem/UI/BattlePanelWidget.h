// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
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
	
public:
	UPROPERTY(meta = (BindWidget))
	UTextBlock* HeroNameText;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* HeroHPText;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* HeroAttackText;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* HeroDefenseText;
};
