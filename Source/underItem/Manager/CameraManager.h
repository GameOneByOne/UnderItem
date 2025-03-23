#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Actor.h"
#include "GameFramework/SpringArmComponent.h"
#include "CameraManager.generated.h"

UCLASS()
class UNDERITEM_API ACameraManager : public AActor
{
	GENERATED_BODY()
	
public:	
	ACameraManager();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:
	TObjectPtr<UCameraComponent> CameraComponent;
	TObjectPtr<USpringArmComponent> SpringArmComponent;	



};
