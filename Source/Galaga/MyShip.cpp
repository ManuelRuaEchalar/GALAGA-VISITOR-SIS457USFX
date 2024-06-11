// Fill out your copyright notice in the Description page of Project Settings.

#include "UObject/ConstructorHelpers.h"
#include "MyShip.h"

// Sets default values
AMyShip::AMyShip()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    ShipMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
    RootComponent = ShipMesh;

    // Carga el mesh del Fighter
    static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Trident-A10.Trident-A10'"));
    if (ShipMeshAsset.Succeeded())
    {
        ShipMesh->SetStaticMesh(ShipMeshAsset.Object);
        ShipMesh->SetWorldScale3D(FVector(0.1f, 0.1f, 0.1f));  // Cambia el valor para ajustar la escala

    }

}

// Called when the game starts or when spawned
void AMyShip::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyShip::MoveRight()
{
    FVector NewLocation = GetActorLocation();
    NewLocation.Y += 10;
    SetActorLocation(NewLocation);
}

void AMyShip::MoveLeft()
{
    FVector NewLocation = GetActorLocation();
    NewLocation.Y -= 10;
    SetActorLocation(NewLocation);
}

void AMyShip::Shoot()
{
    FVector NewLocation = GetActorLocation();
    NewLocation.Z += 170;
    NewLocation.Y += 60;
    FRotator Rotation = FRotator(180.0f, 0.0f, 0.0f);

    myBullet = GetWorld()->SpawnActor<ABullet>(NewLocation, Rotation);

    myBullet->shoot();
}