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
	FText GetHeroHP();
	UFUNCTION(BlueprintCallable)
	FText GetHeroAttack();
	UFUNCTION(BlueprintCallable)
	FText GetHeroDefense();
	void SetWeaponSlot(TObjectPtr<UItemBase> Weapon);
	void SetArmorSlot(TObjectPtr<UItemBase> Armor);
	
public:
	UPROPERTY(Blueprintable, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* HeroHPText;
	UPROPERTY(Blueprintable, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* HeroAttackText;
	UPROPERTY(Blueprintable, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* HeroDefenseText;
	UPROPERTY(Blueprintable, BlueprintReadWrite, meta = (BindWidget))
	UImage* WeaponSlot;
	UPROPERTY(Blueprintable, BlueprintReadWrite, meta = (BindWidget))
	UImage* ArmorSlot;
	UPROPERTY(Blueprintable, BlueprintReadWrite)
	TObjectPtr<AHero> HeroObj;
};
