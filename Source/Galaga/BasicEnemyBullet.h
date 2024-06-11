// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BulletInterface.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/Material.h" 
#include "BasicEnemyBullet.generated.h"

UCLASS()
class GALAGA_API ABasicEnemyBullet : public AActor, public IBulletInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABasicEnemyBullet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ShipMesh;

	// Speed of the bullet
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float Speed;
	bool bIsShooting;

	// Target location
	float TargetZ;

	virtual void Shoot() override;

};
