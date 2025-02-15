// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "Config/ItemConfig.h"
#include "GameFramework/Actor.h"
#include "ItemBase.generated.h"

UCLASS(BlueprintType)
class UNDERITEM_API UItemBase : public UObject
{
	GENERATED_BODY()

private:
	TObjectPtr<UDataTable> ItemConfigDataTable = nullptr;
	
public:	
	UItemBase();
	void SetItem(const FString& ItemName);
	virtual void Use(TObjectPtr<ACharacterBase> CharacterObj);

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FItemConfig ItemConfig;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int Count = 1;
};
