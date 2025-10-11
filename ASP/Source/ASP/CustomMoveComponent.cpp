// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomMoveComponent.h"

void UCustomMoveComponent::FixedUpdate(float _deltaTime)
{
	//Apply the calculated Velocity
	ApplyGravity(_deltaTime);

	if (AActor* owner = GetOwner())
	{
		FVector newLocation = GetOwner()->GetActorLocation() + Velocity * _deltaTime;
		owner->SetActorLocation(newLocation);
	}
}

void UCustomMoveComponent::ApplyGravity(float _deltaTime)
{
	//Calculate Gravitiy Velocity
	Velocity.Z -= Gravity * _deltaTime;
}

void UCustomMoveComponent::Move(FVector _direction, float _speed)
{
	//Calculate Velocity
	Velocity += _direction * _speed;
}
