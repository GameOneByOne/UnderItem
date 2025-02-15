#pragma once

#include "CoreMinimal.h"
#include "PaperFlipbook.h"
#include "CharacterConfig.generated.h"

class UItemBase;

USTRUCT(BlueprintType)
struct FDropItemInfo
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UItemBase> ItemClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString ItemName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 Count;
};

USTRUCT(BlueprintType)
struct FCharacterConfig : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText CharacterName;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText CharacterDescription;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TObjectPtr<UPaperFlipbook> IdleFlipbook;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 MaxHP;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 AttackPower;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 DefensePower;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FDropItemInfo> DropItems;
};
