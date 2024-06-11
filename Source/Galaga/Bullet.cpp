// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"

// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    ShipMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
    RootComponent = ShipMesh;

    // Carga el mesh del Fighter
    static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/rocket2.rocket2'"));
    if (ShipMeshAsset.Succeeded())
    {
        ShipMesh->SetStaticMesh(ShipMeshAsset.Object);
        ShipMesh->SetWorldScale3D(FVector(12.0f, 12.0f, 12.0f));  // Cambia el valor para ajustar la escala
    }
    // Set initial values
    Speed = 200.0f;
    bIsShooting = false;
    TargetZ = 800.0f;

}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Move the bullet if it is shooting
	if (bIsShooting)
	{
		FVector NewLocation = GetActorLocation();
		NewLocation.Z += Speed * DeltaTime;

		// Check if the bullet has reached the target
		if (NewLocation.Z >= TargetZ)
		{
			NewLocation.Z = TargetZ;
			bIsShooting = false;
			this->Destroy();
			// You can add additional logic here, e.g., destroy the bullet
		}

		SetActorLocation(NewLocation);
	}
}

void ABullet::shoot()
{
	bIsShooting = true;
}