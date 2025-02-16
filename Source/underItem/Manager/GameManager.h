#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Manager/LevelManager.h"
#include "Manager/BattleManager.h"
#include "GameManager.generated.h"

UCLASS()
class UNDERITEM_API AGameManager : public AActor
{
	GENERATED_BODY()

private:
	TObjectPtr<ALevelManager> LevelManager = nullptr;
	TObjectPtr<ABattleManager> BattleManager = nullptr;
	TObjectPtr<AUIManager> UIManager = nullptr;
	
public:
	AGameManager();

protected:
	virtual void BeginPlay() override;
};
