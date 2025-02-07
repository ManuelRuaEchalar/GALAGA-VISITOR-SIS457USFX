// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EnemyShip.h"
#include "Visitor.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UVisitor : public UInterface
{
	GENERATED_BODY()
};

/**
 *
 */
class GALAGA_API IVisitor
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void VisitBasicEnemy(class AEnemyShip* EnemyShip) = 0;
};