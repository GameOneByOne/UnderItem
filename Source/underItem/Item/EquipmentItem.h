#pragma once

#include "CoreMinimal.h"
#include "Item/ItemBase.h"
#include "EquipmentItem.generated.h"


UCLASS()
class UNDERITEM_API UEquipmentItem : public UItemBase
{
	GENERATED_BODY()

public:
	virtual void Use(TObjectPtr<ACharacterBase> CharacterObj) override;
	
};
