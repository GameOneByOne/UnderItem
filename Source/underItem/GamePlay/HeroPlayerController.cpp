#include "HeroPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "manager/CameraManager.h"
#include "Utils/log.h"

void AHeroPlayerController::BeginPlay()
{
	TObjectPtr<AActor> NewCamera = UGameplayStatics::GetActorOfClass(GetWorld(), ACameraManager::StaticClass());
	SetViewTargetWithBlend(NewCamera);
	return;
}