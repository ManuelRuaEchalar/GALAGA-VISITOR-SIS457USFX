// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ShipInterface.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/Material.h"  // Incluye la cabecera del material
#include "Bullet.h"
#include "MyShip.generated.h"

UCLASS()
class GALAGA_API AMyShip : public AActor, public IShipInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyShip();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ShipMesh;
	ABullet* myBullet;

	// Implement the interface methods
	virtual void Shoot() override;
	virtual void MoveRight() override;
	virtual void MoveLeft() override;

};
