// Fill out your copyright notice in the Description page of Project Settings.


#include "ShipVisitor.h"

// Sets default values
AShipVisitor::AShipVisitor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AShipVisitor::BeginPlay()
{
    Super::BeginPlay();

}

// Called every frame
void AShipVisitor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

void AShipVisitor::VisitBasicEnemy(AEnemyShip* EnemyShip)
{
    if (!EnemyShip)
    {
        // Manejar el caso de EnemyShip siendo nulo
        return;
    }

    FVector Location = EnemyShip->GetActorLocation();
    Location.Z -= 100;
    FRotator Rotation = FRotator(0.0f, 0.0f, 0.0f);

    ABasicEnemyBullet* Bullet = GetWorld()->SpawnActor<ABasicEnemyBullet>(Location, Rotation);
    Bullet->Shoot();
}

void AShipVisitor::VisitFastEnemy(class AFastShip* FastShip)
{
    if (!FastShip)
    {
        // Manejar el caso de EnemyShip siendo nulo
        return;
    }

    FVector Location = FastShip->GetActorLocation();
    Location.Z -= 100;
    FRotator Rotation = FRotator(0.0f, 0.0f, 0.0f);

    ABasicEnemyBullet* Bullet = GetWorld()->SpawnActor<ABasicEnemyBullet>(Location, Rotation);
    Bullet->Shoot();

    Location.Y -= 30;

    ABasicEnemyBullet* Bullet2 = GetWorld()->SpawnActor<ABasicEnemyBullet>(Location, Rotation);
    Bullet2->Shoot();
}