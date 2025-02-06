// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Hero.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "Components/CapsuleComponent.h"
#include "Utils/log.h"

namespace {
    const FString PLAYER_INPUT_MAPPING_REF = TEXT("/Script/EnhancedInput.InputMappingContext'/Game/Input/IMC_PlayerInputMap.IMC_PlayerInputMap'");
    const FString PLAYER_INPUT_ACTION_MOVE_REF = TEXT("/Script/EnhancedInput.InputAction'/Game/Input/IA_Move.IA_Move'");
}

AHero::AHero()
{
    SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
    CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");

    SpringArmComponent->SetupAttachment(RootComponent);
    CameraComponent->SetupAttachment(SpringArmComponent);

    SpringArmComponent->SetRelativeRotation({270, 0, 270});
    CameraComponent->SetProjectionMode(ECameraProjectionMode::Type::Orthographic);
    CameraComponent->OrthoWidth = 240;
    
    InputMapping = Cast<UInputMappingContext>(LoadObject<UInputMappingContext>(nullptr, *PLAYER_INPUT_MAPPING_REF));
    InputActionMove = Cast<UInputAction>(LoadObject<UInputAction>(nullptr, *PLAYER_INPUT_ACTION_MOVE_REF));
}

void AHero::BeginPlay()
{
    Super::BeginPlay();

    // 加载增强输入
    if (APlayerController* PlayerController = Cast<APlayerController>(Controller)) {
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer())) {
            Subsystem->AddMappingContext(InputMapping, 0);
            INFOLOG("[Hero] Load Input Mapping Succeed.");
        }
    }

    // 生成玩家
    SetCharacter("Hero1");
}

void AHero::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
        // 加载玩家运动输入
        EnhancedInputComponent->BindAction(InputActionMove, ETriggerEvent::Triggered, this, &AHero::Move);
    }
}

void AHero::Move(const FInputActionValue& Value)
{
    FVector2D MoveVector = Value.Get<FVector2D>();
    AddMovementInput({MoveVector.X, 0, 0}, 1);
    AddMovementInput({0, MoveVector.Y, 0}, 1);
}

