// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Visitor.h"
#include "BasicEnemyBullet.h"
#include "EnemyShip.h"
#include "FastShip.h"
#include "Engine/World.h"
#include "ShipVisitor.generated.h"

UCLASS()
class GALAGA_API AShipVisitor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AShipVisitor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void VisitBasicEnemy(AEnemyShip* EnemyShip);
	void VisitFastEnemy(class AFastShip* FastShip);

};