// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "StateMachine.h"
#include "Templates/IsUEnumClass.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ASP_StateMachine_generated_h
#error "StateMachine.generated.h already included, missing '#pragma once' in StateMachine.h"
#endif
#define ASP_StateMachine_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ASP_Source_ASP_StateMachine_h


#define FOREACH_ENUM_ESTATES(op) \
	op(EStates::NONE) \
	op(EStates::IDLE) \
	op(EStates::MOVING) \
	op(EStates::JUMPING) \
	op(EStates::STARTJUMP) \
	op(EStates::FALLING) \
	op(EStates::ATTACKING) \
	op(EStates::CROUCHING) \
	op(EStates::HITTED) 

enum class EStates : uint8;
template<> struct TIsUEnumClass<EStates> { enum { Value = true }; };
template<> ASP_API UEnum* StaticEnum<EStates>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
