#include "Item/RecoverItem.h"


void URecoverItem::Use(TObjectPtr<ACharacterBase> CharacterObj)
{
    if (Count == 0) {
        return;
    }
    CharacterObj->RecoverHP(ItemConfig.RecoverHP);
    Count = FMath::Clamp(Count - 1, 0, Count);
    return;
}
