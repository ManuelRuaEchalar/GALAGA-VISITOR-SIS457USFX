// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/Material.h"  // Incluye la cabecera del material
#include "ShipVisitor.h"
#include "FastShip.generated.h"

UCLASS()
class GALAGA_API AFastShip : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFastShip();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ShipMesh;

	void Accept(class AShipVisitor* Visitor);

};