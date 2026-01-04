#pragma once

UENUM(BlueprintType)
enum class EStates : uint8
{
	NONE       		UMETA(DisplayName="None"),
	IDLE       		UMETA(DisplayName="Idle"),
	MOVING       	UMETA(DisplayName="Moving"),
	MOVINGFWD   	UMETA(DisplayName="MovingForward"),
	MOVINGBWD      	UMETA(DisplayName="MovingBackward"),
	JUMPING     	UMETA(DisplayName="Jumping"),
	STARTJUMP   	UMETA(DisplayName="StartJump"),
	FALLING     	UMETA(DisplayName="Falling"),
	LANDING     	UMETA(DisplayName="Landing"),
	ATTACKING   	UMETA(DisplayName="Attacking"),
	CROUCHING   	UMETA(DisplayName="Crouching"),
	HITTED      	UMETA(DisplayName="Hitted")
};