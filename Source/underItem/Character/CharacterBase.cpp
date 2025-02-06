// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterBase.h"
#include "Utils/log.h"
#include "PaperFlipbook.h"
#include "PaperFlipbookComponent.h"
#include "Components/CapsuleComponent.h"

class UPaperFlipbookComponent;

namespace {
	const FString CHARACTER_CONFIG_DATATABLE_REF = TEXT("/Script/Engine.DataTable'/Game/Data/DT_CharacterConfig.DT_CharacterConfig'");
}

ACharacterBase::ACharacterBase()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> LoadDataTable(*CHARACTER_CONFIG_DATATABLE_REF);
	if (LoadDataTable.Succeeded()) {
		CharacterConfigDataTable = LoadDataTable.Object;
	}
	GetCapsuleComponent()->SetCapsuleSize(10, 15);
	GetSprite()->SetRelativeRotation({0, 0, 270});
}

void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	INFOLOG("[Character Base] A New Character Into Battle Field.");
}

bool ACharacterBase::SetCharacter(const FString& CharacterName)
{
	if (CharacterName.IsEmpty() || !CharacterConfigDataTable->IsValidLowLevel()) {
		ERRORLOG("[Character Base] Set Character Failed. Character Name is %s", *CharacterName);
		return false;
	}
	// 读取对应角色的配置数据
	const FName CharacterRowName = FName(CharacterName);
	FCharacterConfig *Config = CharacterConfigDataTable->FindRow<FCharacterConfig>(CharacterRowName, CharacterRowName.ToString());
	if (!Config) {
		ERRORLOG("[Character Base] SetCharacter Failed Because Of Row Name Not Found.");
		return false;
	}
	INFOLOG("[Character Base] Set Character Config Succeed. Name is %s", *CharacterName);
	CharacterConfig = *Config;

	// 赋值属性
	CurrentHP = CharacterConfig.MaxHP;
	CurrentAttackPower = CharacterConfig.AttackPower;
	CurrentDefensePower = CharacterConfig.DefensePower;
	GetSprite()->SetFlipbook(CharacterConfig.IdleFlipbook);
	INFOLOG("[Character Base] Character Attribute HP is %d, Attack is %d, Defense is %d",
		CurrentHP, CurrentAttackPower, CurrentDefensePower);

	return true;
}

void ACharacterBase::Attack(ACharacterBase* Opponent)
{
	int32 OldOpponentHP = Opponent->CurrentHP;
	Opponent->CurrentHP = FMath::Clamp(Opponent->CurrentHP - this->CurrentAttackPower, 0, Opponent->CurrentHP);
	INFOLOG("[Character Base] %s (AttackPower = %d) Attack %s(HPBefore=%d, HPAfter=%d)", *(this->GetName()),
		CurrentAttackPower, *(Opponent->GetName()), OldOpponentHP, Opponent->CurrentHP);
}

void ACharacterBase::RecoverHP(int32 HP)
{
	CurrentHP = FMath::Clamp(CurrentHP + HP, 0, CharacterConfig.MaxHP);
	return;
}

bool ACharacterBase::IsDead() const
{
	return CurrentHP == 0;	
}


