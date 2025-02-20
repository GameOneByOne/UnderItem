#include "Item/EquipmentItem.h"
#include "Blueprint/WidgetBlueprintLibrary.h"

#include "UI/HeroStatusPanel.h"
#include "Utils/log.h"

void UEquipmentItem::Use(TObjectPtr<ACharacterBase> CharacterObj)
{
	TArray<UUserWidget*> FoundWidgets;
	UWidgetBlueprintLibrary::GetAllWidgetsOfClass(GetWorld(), FoundWidgets, UHeroStatusPanel::StaticClass(), false);
	if (FoundWidgets.IsEmpty()) {
		ERRORLOG("[Hero] No Widgets found.");
		return;
	}

	// 给目标人物上装备
	if (ItemConfig.ItemType == EItemType::Weapon) {
		CharacterObj->EquipWeapon(this);
	} else if (ItemConfig.ItemType == EItemType::Armour) {
		CharacterObj->EquipArmor(this);
	}
	return;
}
