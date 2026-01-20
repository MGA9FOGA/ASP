#pragma once

UENUM(BlueprintType)
enum class EStates : uint8
{
	NONE		UMETA(DisplayName="None"),
	IDLE		UMETA(DisplayName="Idle"),
	MOVING		UMETA(DisplayName="Moving"),
	MOVINGFWD	UMETA(DisplayName="MovingForward"),
	MOVINGBWD	UMETA(DisplayName="MovingBackward"),
	JUMPING		UMETA(DisplayName="Jumping"),
	STARTJUMP	UMETA(DisplayName="StartJump"),
	FALLING		UMETA(DisplayName="Falling"),
	LANDING		UMETA(DisplayName="Landing"),
	ATTACKING 	UMETA(DisplayName="Attacking"),
	CROUCHING 	UMETA(DisplayName="Crouching"),
	HITTED		UMETA(DisplayName="Hitted")
};

inline FColor GetColorForState(EStates _state)
{
	switch (_state)
	{
		case EStates::NONE:			return FColor::White;
		case EStates::IDLE:			return FColor::Green;
		case EStates::MOVING:		return FColor::Magenta;
		case EStates::MOVINGFWD:	return FColor::Magenta;
		case EStates::MOVINGBWD:	return FColor::Magenta;
		case EStates::JUMPING:		return FColor::Blue;
		case EStates::STARTJUMP:	return FColor::Blue;
		case EStates::FALLING:		return FColor::Yellow;
		case EStates::LANDING:		return FColor::Yellow;
		case EStates::ATTACKING:	return FColor::Cyan;
		case EStates::CROUCHING:	return FColor::Black;
		case EStates::HITTED:		return FColor::Red;
		default:					return FColor::White;
	}
}
