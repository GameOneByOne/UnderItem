// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HeroStatusPanel.h"

bool UHeroStatusPanel::Initialize()
{
    if (!Super::Initialize()) {
        return false;
    }

    //HeroHPText->TextDelegate.BindDynamic(this, &UHeroStatusPanel::GetHeroHP);
    //HeroAttackText->TextDelegate.BindDynamic(this, &UHeroStatusPanel::GetHeroAttack);
    //HeroDefenseText->TextDelegate.BindDynamic(this, &UHeroStatusPanel::GetHeroDefense);
    return true;
}

FText UHeroStatusPanel::GetHeroHP()
{
    if (HeroObj->IsValidLowLevel()) {
        return FText::AsNumber(HeroObj->CurrentHP);
    }
    return FText::FromString("");

}

FText UHeroStatusPanel::GetHeroAttack()
{
    if (HeroObj->IsValidLowLevel()) {
        return FText::AsNumber(HeroObj->CurrentAttackPower);
    }
    return FText::FromString("");
}

FText UHeroStatusPanel::GetHeroDefense()
{
    if (HeroObj->IsValidLowLevel()) {
        return FText::AsNumber(HeroObj->CurrentDefensePower);
    }
    return FText::FromString("");
}

void UHeroStatusPanel::SetHeroPtr(TObjectPtr<AHero> Hero)
{
    HeroObj = Hero;
}