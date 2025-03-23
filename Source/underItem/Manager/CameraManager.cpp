#include "Manager/CameraManager.h"

ACameraManager::ACameraManager()
{
	PrimaryActorTick.bCanEverTick = false;
	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");

	SpringArmComponent->SetupAttachment(RootComponent);
	CameraComponent->SetupAttachment(SpringArmComponent);

	SpringArmComponent->SetRelativeRotation({270, 0, 270});
	CameraComponent->SetProjectionMode(ECameraProjectionMode::Type::Orthographic);
	CameraComponent->OrthoWidth = 240;
}

// Called when the game starts or when spawned
void ACameraManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACameraManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

