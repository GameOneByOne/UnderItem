#pragma once

#include "CoreMinimal.h"
#include "PaperFlipbook.h"
#include "CharacterConfig.generated.h"

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
	TArray<FString> DropItems;
};
