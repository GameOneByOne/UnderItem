#pragma once

#include "CoreMinimal.h"
#define INFOLOG(Fmt, ...) GEngine->AddOnScreenDebugMessage(-1, 25.f, FColor::Green, FString::Printf(TEXT(Fmt), ##__VA_ARGS__))
#define ERRORLOG(Fmt, ...) GEngine->AddOnScreenDebugMessage(-1, 25.f, FColor::Red, FString::Printf(TEXT(Fmt), ##__VA_ARGS__))