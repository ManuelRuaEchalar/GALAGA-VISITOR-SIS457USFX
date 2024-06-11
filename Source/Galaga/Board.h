// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyShip.h"
#include "EnemyShip.h"
#include "FastShip.h"
#include "ShipVisitor.h"
#include "Board.generated.h"

UCLASS()
class GALAGA_API ABoard : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABoard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	AMyShip* miNave;
	bool bIsMovingRight;
	bool bIsMovingLeft;
	int contador = 0;

	AEnemyShip* enemy;
	AFastShip* fastEnemy;

	AShipVisitor* visitor;

	void StartMovingRight();
	void StopMovingRight();

	void StartMovingLeft();
	void StopMovingLeft();

	void MoveRight();

	void MoveLeft();

	void Shoot();

};
