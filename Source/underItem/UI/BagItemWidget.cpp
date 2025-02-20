#include "UI/BagItemWidget.h"

#include "PaperSprite.h"
#include "Character/Hero.h"
#include "Utils/log.h"
#include "Kismet/GameplayStatics.h"

namespace {
const FString DEFAULT_ITEM_IMAGE = "/Script/Engine.Texture2D'/Game/UI/Texture/ItemBox_24x24.ItemBox_24x24'";
const FVector2f IMAGE_SIZE = {38, 38};
}

bool UBagItemWidget::Initialize()
{
    if (!Super::Initialize()) {
        return false;
    }

    ItemImage->OnMouseButtonDownEvent.BindDynamic(this, &UBagItemWidget::MouseDownEventDeal);
    ItemCountText->TextDelegate.BindDynamic(this, &UBagItemWidget::GetItemCountText);
    ItemImage->BrushDelegate.BindDynamic(this, &UBagItemWidget::GetItemImage);
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

FText UBagItemWidget::GetItemCountText()
{
    if (ItemInfo->Count == 0) {
        return FText::FromString("");
    }

    return FText::AsNumber(ItemInfo->Count);
}

FSlateBrush UBagItemWidget::GetItemImage()
{
    static UTexture2D* LoadedTexture = LoadObject<UTexture2D>(nullptr, *DEFAULT_ITEM_IMAGE);
    if (LoadedTexture->IsValidLowLevel()) {
        DefaultItemImage = LoadedTexture;
    }

    FSlateBrush Brush;
    Brush.SetImageSize(IMAGE_SIZE);
    if (ItemInfo->Count == 0) {
        Brush.SetResourceObject(DefaultItemImage);
    } else {
        TObjectPtr<UTexture2D> Texture = ItemInfo->ItemConfig.Sprite->GetSourceTexture();
        Brush.SetResourceObject(Texture);
        const FVector2d UVSize = ItemInfo->ItemConfig.Sprite->GetSourceSize();
        const FVector2d UV = ItemInfo->ItemConfig.Sprite->GetSourceUV();
        const int32 TextureWidth = Texture->GetSizeX();
        const int32 TextureHeight = Texture->GetSizeY();
        FVector2D UVMin(UV.X / static_cast<float>(TextureWidth), UV.Y / static_cast<float>(TextureHeight));
        FVector2D UVMax((UV.X + UVSize.X) / static_cast<float>(TextureWidth), (UV.Y + UVSize.Y) / static_cast<float>(TextureHeight));
        Brush.SetUVRegion(FBox2D(UVMin, UVMax));
    }
    return Brush;
}