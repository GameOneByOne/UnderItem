#include "Character/Monster.h"
#include "Kismet/GameplayStatics.h"
#include "Manager/BattleManager.h"
#include "Utils/log.h"

void AMonster::BeginInteract(TObjectPtr<ACharacterBase> ActorPtr)
{
    TObjectPtr<ABattleManager> BattleManager = Cast<ABattleManager>(UGameplayStatics::GetActorOfClass(GetWorld(), ABattleManager::StaticClass()));
    BattleManager->StartBattle(ActorPtr, this);
    return;
}

void AMonster::PreDestroy(TObjectPtr<ACharacterBase> ActorObj)
{
    // TODO: 增加经验
    // TODO: 增加金币
    
    // 掉落物品
    for (const auto &Iter : CharacterConfig.DropItems) {
        TObjectPtr<UItemBase> Item = NewObject<UItemBase>(ActorObj, Iter.ItemClass);
        Item->SetItem(Iter.ItemName);
        Cast<AHero>(ActorObj)->AddItem(Item);
    }
    OnMonsterDead.Broadcast();
    Destroy();
    return;
}