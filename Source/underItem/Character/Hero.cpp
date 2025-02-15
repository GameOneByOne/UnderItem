// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Hero.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "UI/HeroBagWidget.h"
#include "Item/ItemBase.h"
#include "Utils/log.h"

namespace {
    const FString PLAYER_INPUT_MAPPING_REF = TEXT("/Script/EnhancedInput.InputMappingContext'/Game/Input/IMC_PlayerInputMap.IMC_PlayerInputMap'");
    const FString PLAYER_INPUT_ACTION_MOVE_REF = TEXT("/Script/EnhancedInput.InputAction'/Game/Input/IA_Move.IA_Move'");
    const FString PLAYER_INPUT_ACTION_INTERACT_REF = TEXT("/Script/EnhancedInput.InputAction'/Game/Input/IA_Interact.IA_Interact'");
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
    InputActionInteract = Cast<UInputAction>(LoadObject<UInputAction>(nullptr, *PLAYER_INPUT_ACTION_INTERACT_REF));

    CollisionAndInteractComponent->OnComponentBeginOverlap.AddDynamic(this, &AHero::CollisionWithActor);
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

    // 设置鼠标显示
    Cast<APlayerController>(GetController())->bShowMouseCursor = true;
}

void AHero::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
        // 加载玩家运动输入
        EnhancedInputComponent->BindAction(InputActionMove, ETriggerEvent::Triggered, this, &AHero::Move);
        EnhancedInputComponent->BindAction(InputActionInteract,ETriggerEvent::Started, this, &AHero::Interact);
    }
}

void AHero::Move(const FInputActionValue& Value)
{
    FVector2D MoveVector = Value.Get<FVector2D>();
    AddMovementInput({MoveVector.X, 0, 0}, 1);
    AddMovementInput({0, MoveVector.Y, 0}, 1);
}

void AHero::Interact(const FInputActionValue& Value)
{
    bool IsAttack = Value.Get<bool>();
    if (InteractCharacter.IsValid()) {
        INFOLOG("[Hero] Interact With Actor, %s", *InteractCharacter->GetName());
        InteractCharacter->BeginInteract(this);
    }
}

void AHero::CollisionWithActor(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (OtherComp->GetName() != "CollisionAndInteractComponent") {
        return;
    }

    InteractCharacter = Cast<ACharacterBase>(OtherActor);
    INFOLOG("[Hero] Collision With Actor, %s", *InteractCharacter->GetName());
    return;
}

void AHero::AddItem(TObjectPtr<UItemBase> NewItem)
{
    TArray<UUserWidget*> FoundWidgets;
    UWidgetBlueprintLibrary::GetAllWidgetsOfClass(GetWorld(), FoundWidgets, UHeroBagWidget::StaticClass(), false);
    if (FoundWidgets.IsEmpty()) {
        ERRORLOG("[Hero] AddItem: No Widgets found.");
        return;
    }

    // 找一下当前物品栏里面有没有同样物品的
    for (const auto &Iter : ItemList) {
        if (Iter->ItemConfig.ItemName == NewItem->ItemConfig.ItemName) {
            Iter->Count += NewItem->Count;
            Cast<UHeroBagWidget>(FoundWidgets[0])->Update();
            return;
        }
    }

    // 说明没有重复的则新建物品
    ItemList.Add(NewItem);
    Cast<UHeroBagWidget>(FoundWidgets[0])->Update();
    INFOLOG("[Hero] AddItem: New Item %s", *NewItem->GetName());
    return;
}

void AHero::RemoveItem(const FString &ItemName, int Count)
{
    return;
}



