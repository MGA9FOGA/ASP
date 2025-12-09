// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MoveableInterface.generated.h"

/**
 * 
 */
UINTERFACE()
class ASP_API UMoveableInterface : public UInterface
{
	GENERATED_BODY()
};

class ASP_API IMoveableInterface
{
	GENERATED_BODY()

public:
	virtual void FixedUpdate(float _deltaTime) = 0;
	virtual class UCustomMoveComponent* GetNoChaosMovementComponent() const = 0;
};
