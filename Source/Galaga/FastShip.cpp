// Fill out your copyright notice in the Description page of Project Settings.


#include "FastShip.h"

// Sets default values
AFastShip::AFastShip()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    ShipMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
    RootComponent = ShipMesh;

    // Carga el mesh del Fighter
    static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/uploads_files_4254779_SpaceShip.uploads_files_4254779_SpaceShip'"));
    if (ShipMeshAsset.Succeeded())
    {
        ShipMesh->SetStaticMesh(ShipMeshAsset.Object);
        ShipMesh->SetWorldScale3D(FVector(0.05f, 0.05f, 0.05f));  // Cambia el valor para ajustar la escala
    }

    // Carga el material del agua
    static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("Material'/Game/StarterContent/Materials/M_Rock_Marble_Polished.M_Rock_Marble_Polished'"));
    if (MaterialAsset.Succeeded())
    {
        ShipMesh->SetMaterial(0, MaterialAsset.Object);
    }

}

// Called when the game starts or when spawned
void AFastShip::BeginPlay()
{
    Super::BeginPlay();

}

// Called every frame
void AFastShip::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

void AFastShip::Accept(AShipVisitor* Visitor)
{
    Visitor->VisitFastEnemy(this);
}