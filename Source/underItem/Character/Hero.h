// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "Camera/CameraComponent.h"
#include "Character/CharacterBase.h"
#include "GameFramework/SpringArmComponent.h"
#include "Hero.generated.h"


class UInputMappingContext;

UCLASS(Blueprintable, BlueprintType)
class UNDERITEM_API AHero : public ACharacterBase
{
	GENERATED_BODY()
	
public:
	AHero();
	void Move(const FInputActionValue& Value);

protected:
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	
private:
	TObjectPtr<USpringArmComponent> SpringArmComponent;
	TObjectPtr<UCameraComponent> CameraComponent;
	TObjectPtr<UInputMappingContext> InputMapping;
	TObjectPtr<UInputAction> InputActionMove;
};
