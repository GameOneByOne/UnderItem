// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HeroBagWidget.h"
#include "Utils/log.h"
#include "BagItemWidget.h"
#include "Character/Hero.h"
#include "Kismet/GameplayStatics.h"

namespace {
    const int BAG_ITEM_TOTAL_NUM = 9;
}


bool UHeroBagWidget::Initialize()
{
    if (!Super::Initialize()) {
        return false;
    }

    for (int i = 0; i < BAG_ITEM_TOTAL_NUM; i++) {
        TObjectPtr<UItemBase> NewItem = NewObject<UItemBase>();
        BagPanel->AddItem(NewItem);
    }

    HeroPtr = Cast<AHero>(UGameplayStatics::GetActorOfClass(GetWorld(), AHero::StaticClass()));

    return true;
}

void UHeroBagWidget::Update()
{
    // TODO: 需要完善
    BagPanel->ClearListItems();
    for (int i = (CurrentPage - 1) * BAG_ITEM_TOTAL_NUM; i < CurrentPage * BAG_ITEM_TOTAL_NUM; i++) {
        if (i >= HeroPtr->ItemList.Num()) {  // 说明没有这么多物品，
            TObjectPtr<UItemBase> NewItem = NewObject<UItemBase>();
            BagPanel->AddItem(NewItem);
        } else { // 显示物品
            TObjectPtr<UItemBase> Item = HeroPtr->ItemList[i];
            BagPanel->AddItem(Item);
            INFOLOG("123123123123123    %s", *Item->GetName());
        }
    }

    return;
}

