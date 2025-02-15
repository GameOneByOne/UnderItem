// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/RecoverItem.h"


void URecoverItem::Use(TObjectPtr<ACharacterBase> CharacterObj)
{
    CharacterObj->RecoverHP(ItemConfig.RecoverHP);
    Count = FMath::Clamp(Count - 1, 0, Count);
    return;
}
