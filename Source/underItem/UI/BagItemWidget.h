// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Item/ItemBase.h"
#include "BagItemWidget.generated.h"


UCLASS()
class UNDERITEM_API UBagItemWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual bool Initialize() override;
	UFUNCTION(BlueprintCallable)
	FEventReply MouseDownEventDeal(FGeometry MyGeometry, const FPointerEvent& MouseEvent);

public:
	UPROPERTY(Blueprintable, BlueprintReadWrite, meta = (BindWidget))
	UImage* ItemImage;
	UPROPERTY(Blueprintable, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* ItemCountText;
	UPROPERTY(Blueprintable, BlueprintReadWrite)
	TObjectPtr<UItemBase> ItemInfo;
};
