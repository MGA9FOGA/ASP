// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "States.h"
#include "Templates/IsUEnumClass.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ASP_States_generated_h
#error "States.generated.h already included, missing '#pragma once' in States.h"
#endif
#define ASP_States_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ASP_Source_ASP_States_h


#define FOREACH_ENUM_ESTATES(op) \
	op(EStates::NONE) \
	op(EStates::IDLE) \
	op(EStates::MOVING) \
	op(EStates::MOVINGFWD) \
	op(EStates::MOVINGBWD) \
	op(EStates::JUMPING) \
	op(EStates::STARTJUMP) \
	op(EStates::FALLING) \
	op(EStates::LANDING) \
	op(EStates::ATTACKING) \
	op(EStates::CROUCHING) \
	op(EStates::HITTED) 

enum class EStates : uint8;
template<> struct TIsUEnumClass<EStates> { enum { Value = true }; };
template<> ASP_API UEnum* StaticEnum<EStates>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
