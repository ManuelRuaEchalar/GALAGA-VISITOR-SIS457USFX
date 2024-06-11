// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/Material.h"
#include "ShipVisitor.h"
#include "EnemyShip.generated.h"

UCLASS()
class GALAGA_API AEnemyShip : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEnemyShip();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void Accept(class AShipVisitor* Visitor);


	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ShipMesh;


};