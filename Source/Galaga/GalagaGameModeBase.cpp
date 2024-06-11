// Copyright Epic Games, Inc. All Rights Reserved.
#include "Camera/CameraActor.h"
#include "Kismet/GameplayStatics.h"
#include "EngineUtils.h"

#include "GalagaGameModeBase.h"
#include "Board.h"

AGalagaGameModeBase::AGalagaGameModeBase()
{
	DefaultPawnClass = ABoard::StaticClass();

}

void AGalagaGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	FVector Location = FVector(-2500.0f, 0.0f, 400.0f);
	FRotator Rotation = FRotator(0.0f, 0.0f, 0.0f);
	BoardCamera = GetWorld()->SpawnActor<ABoarCamera>(ABoarCamera::StaticClass(), Location, Rotation);

	for (TActorIterator<ACameraActor> it(GetWorld()); it; ++it)
	{
		if (it->GetFName() == TEXT("BoarCamera_0"))
		{
			APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
			if (PC)
			{
				PC->SetViewTargetWithBlend(*it, 0.5f);
			}
			break;
		}
	}
}
