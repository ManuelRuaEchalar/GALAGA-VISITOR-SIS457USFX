// ShipInterface.h

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ShipInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UShipInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 *
 */
class GALAGA_API IShipInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	// Declare the interface methods
	virtual void Shoot() = 0;
	virtual void MoveRight() = 0;
	virtual void MoveLeft() = 0;
};
