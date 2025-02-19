#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "Components/BoxComponent.h"
#include "Config/CharacterConfig.h"
#include "CharacterBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCharacterDead);


UCLASS()
class UNDERITEM_API ACharacterBase : public APaperCharacter
{
	GENERATED_BODY()
	
public:
	ACharacterBase();
	virtual void BeginInteract(TObjectPtr<ACharacterBase> ActorPtr);
	virtual void PreDestroy(TObjectPtr<ACharacterBase> ActorObj);
	bool SetCharacter(const FString& CharacterName);
	void Attack(ACharacterBase* Opponent) const;
	void RecoverHP(int32 HP);
	bool IsDead() const;
	
public:
	FCharacterConfig CharacterConfig;
	int32 CurrentHP;
	int32 CurrentAttackPower;
	int32 CurrentDefensePower;
	FOnCharacterDead OnCharacterDead;

protected:
	virtual void BeginPlay() override;

protected:
	TObjectPtr<UBoxComponent> CollisionAndInteractComponent;

private:
	TObjectPtr<UDataTable> CharacterConfigDataTable = nullptr;

};
