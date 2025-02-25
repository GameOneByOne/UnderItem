#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Character/Hero.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "HeroStatusPanel.generated.h"


UCLASS()
class UNDERITEM_API UHeroStatusPanel : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual bool Initialize() override;
	void SetHeroPtr(TObjectPtr<AHero> Hero);

	UFUNCTION(BlueprintCallable)
	FSlateBrush GetHeroHP();
	UFUNCTION(BlueprintCallable)
	FText GetHeroAttack();
	UFUNCTION(BlueprintCallable)
	FText GetHeroDefense();
	UFUNCTION(BlueprintCallable)
	FSlateBrush GetWeaponImage();
	UFUNCTION(BlueprintCallable)
	FSlateBrush GetArmorImage();
	
public:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* HeroHPBar;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* HeroHpBarBorder;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* HeroAttackText;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* HeroDefenseText;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* WeaponSlot;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* ArmorSlot;
	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<AHero> HeroObj;

private:
	TObjectPtr<UTexture2D> DefaultSlotImage;
};
