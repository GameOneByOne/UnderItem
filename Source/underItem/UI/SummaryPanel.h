#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "SummaryPanel.generated.h"

UCLASS()
class UNDERITEM_API USummaryPanel : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual bool Initialize() override;
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> BeginGameBtn;
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> ExitGameBtn;

private:
	UFUNCTION(BlueprintCallable)
	void BeginGame();
	UFUNCTION(BlueprintCallable)
	void EndGame();

};
