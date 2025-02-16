#include "UI/BagItemWidget.h"
#include "Character/Hero.h"
#include "Utils/log.h"
#include "Kismet/GameplayStatics.h"

bool UBagItemWidget::Initialize()
{
    if (!Super::Initialize()) {
        return false;
    }

    ItemImage->OnMouseButtonDownEvent.BindDynamic(this, &UBagItemWidget::MouseDownEventDeal);
    return true;
}

FEventReply UBagItemWidget::MouseDownEventDeal(FGeometry MyGeometry, const FPointerEvent& MouseEvent)
{
    FEventReply Reply;
    FKey DownKey = MouseEvent.GetEffectingButton();
    if (DownKey.GetFName() != "RightMouseButton") {
        return Reply;
    }

    TObjectPtr<AHero> HeroPtr = Cast<AHero>(UGameplayStatics::GetActorOfClass(GetWorld(), AHero::StaticClass()));
    ItemInfo->Use(HeroPtr);
    return Reply;
}