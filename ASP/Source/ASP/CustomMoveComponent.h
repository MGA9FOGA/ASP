// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CustomMoveComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ASP_API UCustomMoveComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	void FixedUpdate(float _deltaTime);
	void ApplyGravity(float _deltaTime);
	void Move(FVector _direction, float _speed);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Gravity = 980.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Velocity = FVector::ZeroVector;
};
