// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BoarCamera.h"
#include "GalagaGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_API AGalagaGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGalagaGameModeBase();

	virtual void BeginPlay() override;

	ABoarCamera* BoardCamera;
	
};
