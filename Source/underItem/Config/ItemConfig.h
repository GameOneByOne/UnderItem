#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UI/BattlePanelWidget.h"
#include "ItemConfig.generated.h"

class UPaperSprite;

UENUM(BlueprintType)
enum class EItemType : uint8
{
	Potion, Weapon, Armour 
};

USTRUCT(BlueprintType)
struct FItemConfig : public FTableRowBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText ItemName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText ItemDesc;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EItemType ItemType;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TObjectPtr<UPaperSprite> Sprite;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 RecoverHP = 0;
};
