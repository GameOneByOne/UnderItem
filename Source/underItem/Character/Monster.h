// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "Monster.generated.h"


UCLASS()
class UNDERITEM_API AMonster : public ACharacterBase
{
	GENERATED_BODY()
	
public:
	virtual void BeginInteract(TObjectPtr<ACharacterBase> ActorPtr) override;
	virtual void PreDestroy(TObjectPtr<ACharacterBase> ActorObj) override;
};
