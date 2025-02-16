#pragma once

#include "CoreMinimal.h"
#include "Item/ItemBase.h"
#include "RecoverItem.generated.h"


UCLASS()
class UNDERITEM_API URecoverItem : public UItemBase
{
	GENERATED_BODY()

public:
	virtual void Use(TObjectPtr<ACharacterBase> CharacterObj) override;
	
};
