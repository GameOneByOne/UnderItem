// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "Character/CharacterBase.h"
#include "GameFramework/SpringArmComponent.h"
#include "Hero.generated.h"


UCLASS(Blueprintable, BlueprintType)
class UNDERITEM_API AHero : public ACharacterBase
{
	GENERATED_BODY()
	
public:
	AHero();

protected:
	virtual void BeginPlay() override;

private:
	TObjectPtr<USpringArmComponent> SpringArmComponent;
	TObjectPtr<UCameraComponent> CameraComponent;
	class UInputMappingContext* InputMapping;
	class UInputAction* MoveAction;
};
