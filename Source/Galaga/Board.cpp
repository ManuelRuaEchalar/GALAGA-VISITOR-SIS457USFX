// Fill out your copyright notice in the Description page of Project Settings.


#include "Board.h"
#include "Engine/World.h"
#include "Engine/GameEngine.h"

// Sets default values
ABoard::ABoard()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABoard::BeginPlay()
{
	Super::BeginPlay();


	FVector Location = FVector(0.0f, 0.0f, 0.0f);
	FRotator Rotation = FRotator(90.0f, 0.0f, 0.0f);

	miNave = GetWorld()->SpawnActor<AMyShip>(Location, Rotation);

	if (miNave)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Hola Mundo desde BeginPlay!"));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Error al generar la nave"));
	}

	FVector LocationEnemy = FVector(0.0f, 0.0f, 600.0f);
	FRotator RotationEnemy = FRotator(0.0f, 90.0f, 90.0f);

	enemy = GetWorld()->SpawnActor<AEnemyShip>(LocationEnemy, RotationEnemy);

	FVector LocationFast = FVector(0.0f, -200.0f, 600.0f);
	FRotator RotationFast = FRotator(0.0f, 90.0f, 90.0f);

	fastEnemy = GetWorld()->SpawnActor<AFastShip>(LocationFast, RotationFast);


	visitor = GetWorld()->SpawnActor<AShipVisitor>(LocationEnemy, RotationEnemy);


	bIsMovingRight = false;
	bIsMovingLeft = false;
}

// Called every frame
void ABoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bIsMovingRight)
	{
		if (miNave)
		{
			miNave->MoveRight();
		}
	}

	if (bIsMovingLeft)
	{
		if (miNave)
		{
			miNave->MoveLeft();
		}
	}

	if (contador == 20)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Disparando"));
		enemy->Accept(visitor);
		fastEnemy->Accept(visitor);
		contador = 0;
	}

}

// Called to bind functionality to input
void ABoard::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("MoveRight", IE_Pressed, this, &ABoard::StartMovingRight);
	PlayerInputComponent->BindAction("MoveRight", IE_Released, this, &ABoard::StopMovingRight);

	PlayerInputComponent->BindAction("MoveLeft", IE_Pressed, this, &ABoard::StartMovingLeft);
	PlayerInputComponent->BindAction("MoveLeft", IE_Released, this, &ABoard::StopMovingLeft);
	PlayerInputComponent->BindAction("Shoot", IE_Pressed, this, &ABoard::Shoot);
}

void ABoard::StartMovingRight()
{
	bIsMovingRight = true;
}

void ABoard::StopMovingRight()
{
	bIsMovingRight = false;
}

void ABoard::StartMovingLeft()
{
	bIsMovingLeft = true;
}

void ABoard::StopMovingLeft()
{
	bIsMovingLeft = false;
}

void ABoard::MoveRight()
{
	if (miNave)
	{
		miNave->MoveRight();
	}
}

void ABoard::MoveLeft()
{
	if (miNave)
	{
		miNave->MoveLeft();
	}
}

void ABoard::Shoot()
{
	if (miNave)
	{
		miNave->Shoot();
		contador += 1;
	}
}