#include "BattlePanelWidget.h"


bool UBattlePanelWidget::Initialize()
{
    if (!Super::Initialize()) {
        return false;
    }

    HeroHPText->TextDelegate.BindDynamic(this, &UBattlePanelWidget::GetHeroHP);
    HeroAttackText->TextDelegate.BindDynamic(this, &UBattlePanelWidget::GetHeroAttack);
    HeroDefenseText->TextDelegate.BindDynamic(this, &UBattlePanelWidget::GetHeroDefense);
    HeroNameText->TextDelegate.BindDynamic(this, &UBattlePanelWidget::GetHeroName);
    
    MonsterHPText->TextDelegate.BindDynamic(this, &UBattlePanelWidget::GetMonsterHP);
    MonsterAttackText->TextDelegate.BindDynamic(this, &UBattlePanelWidget::GetMonsterAttack);
    MonsterDefenseText->TextDelegate.BindDynamic(this, &UBattlePanelWidget::GetMonsterDefense);
    MonsterNameText->TextDelegate.BindDynamic(this, &UBattlePanelWidget::GetMonsterName);
    return true;
}

void UBattlePanelWidget::SetHeroObj(TObjectPtr<ACharacterBase> Obj)
{
    HeroObj = Obj;
    return;
}

FText UBattlePanelWidget::GetHeroHP()
{
    if (HeroObj->IsValidLowLevel()) {
        return FText::AsNumber(HeroObj->CurrentHP);
    }
    return FText::FromString("");

}

FText UBattlePanelWidget::GetHeroAttack()
{
    if (HeroObj->IsValidLowLevel()) {
        return FText::AsNumber(HeroObj->CurrentAttackPower);
    }
    return FText::FromString("");
}

FText UBattlePanelWidget::GetHeroDefense()
{
    if (HeroObj->IsValidLowLevel()) {
        return FText::AsNumber(HeroObj->CurrentDefensePower);
    }
    return FText::FromString("");
}

FText UBattlePanelWidget::GetHeroName()
{
    if (HeroObj->IsValidLowLevel()) {
        return HeroObj->CharacterConfig.CharacterName;
    }
    return FText::FromString("");
}

void UBattlePanelWidget::SetMonsterObj(TObjectPtr<ACharacterBase> Obj)
{
    MonsterObj = Obj;
    return;
}

FText UBattlePanelWidget::GetMonsterHP()
{
    if (MonsterObj->IsValidLowLevel()) {
        return FText::AsNumber(MonsterObj->CurrentHP);
    }
    return FText::FromString("");
}

FText UBattlePanelWidget::GetMonsterAttack()
{
    if (MonsterObj->IsValidLowLevel()) {
        return FText::AsNumber(MonsterObj->CurrentAttackPower);
    }
    return FText::FromString("");
}

FText UBattlePanelWidget::GetMonsterDefense()
{
    if (MonsterObj->IsValidLowLevel()) {
        return FText::AsNumber(MonsterObj->CurrentDefensePower);
    }
    return FText::FromString("");
}

FText UBattlePanelWidget::GetMonsterName()
{
    if (MonsterObj->IsValidLowLevel()) {
        return MonsterObj->CharacterConfig.CharacterName;
    }
    return FText::FromString("");
}

