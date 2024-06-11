// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyShip.h"

// Sets default values
AEnemyShip::AEnemyShip()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    ShipMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
    RootComponent = ShipMesh;

    // Carga el mesh del Fighter
    static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/SC_Fighter_VX4_.SC_Fighter_VX4_'"));
    if (ShipMeshAsset.Succeeded())
    {
        ShipMesh->SetStaticMesh(ShipMeshAsset.Object);
        ShipMesh->SetWorldScale3D(FVector(6.0f, 6.0f, 6.0f));  // Cambia el valor para ajustar la escala
    }

    // Carga el material del agua
    static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("Material'/Game/StarterContent/Materials/M_Water_Lake.M_Water_Lake'"));
    if (MaterialAsset.Succeeded())
    {
        ShipMesh->SetMaterial(0, MaterialAsset.Object);
    }

}

// Called when the game starts or when spawned
void AEnemyShip::BeginPlay()
{
    Super::BeginPlay();

}

// Called every frame
void AEnemyShip::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

void AEnemyShip::Accept(AShipVisitor* Visitor)
{
    Visitor->VisitBasicEnemy(this);
}
