// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameMode.h"


AMyGameMode::AMyGameMode()
{
	DefaultPawnClass = AHero::StaticClass();
	PlayerControllerClass = AHeroPlayerController::StaticClass();
}
