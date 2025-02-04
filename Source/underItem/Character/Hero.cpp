// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Hero.h"

#include "Chaos/SoftsSpring.h"

AHero::AHero()
{
    SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
    CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");

    SpringArmComponent->SetupAttachment(RootComponent);
    CameraComponent->SetupAttachment(SpringArmComponent);

    SpringArmComponent->SetRelativeRotation({270, 0, 0});
    CameraComponent->SetProjectionMode(ECameraProjectionMode::Type::Orthographic);
    CameraComponent->OrthoWidth = 240;
}

void AHero::BeginPlay()
{
    // 在你的cpp中...
}

