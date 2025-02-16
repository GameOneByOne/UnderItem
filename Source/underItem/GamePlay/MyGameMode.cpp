#include "MyGameMode.h"
#include "Character/Hero.h"
#include "HeroPlayerController.h"


AMyGameMode::AMyGameMode()
{
	DefaultPawnClass = AHero::StaticClass();
	PlayerControllerClass = AHeroPlayerController::StaticClass();
}
