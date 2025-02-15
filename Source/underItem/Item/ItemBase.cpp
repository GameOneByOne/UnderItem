// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/ItemBase.h"
#include "Utils/log.h"

namespace {
	const FString ITEM_CONFIG_DATATABLE_REF = "/Script/Engine.DataTable'/Game/Data/DT_ItemConfig.DT_ItemConfig'";
}

UItemBase::UItemBase()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> LoadDataTable(*ITEM_CONFIG_DATATABLE_REF);
	if (LoadDataTable.Succeeded()) {
		ItemConfigDataTable = LoadDataTable.Object;
	}
}

void UItemBase::SetItem(const FString& ItemName)
{
	if (ItemName.IsEmpty() || !ItemConfigDataTable->IsValidLowLevel()) {
		ERRORLOG("[Character Base] Set Item Failed. Item Name is %s", *ItemName);
		return;
	}
	// 读取对应角色的配置数据
	const FName ItemRowName = FName(ItemName);
	FItemConfig *Config = ItemConfigDataTable->FindRow<FItemConfig>(ItemRowName, ItemRowName.ToString());
	if (!Config) {
		ERRORLOG("[Character Base] SetItem Failed Because Of Row Name Not Found.");
		return;
	}
	INFOLOG("[Character Base] Set Item Config Succeed. Name is %s", *ItemName);
	ItemConfig = *Config;
	return;
}

void UItemBase::Use(TObjectPtr<ACharacterBase> CharacterObj)
{
	Count--;
	return;
}

