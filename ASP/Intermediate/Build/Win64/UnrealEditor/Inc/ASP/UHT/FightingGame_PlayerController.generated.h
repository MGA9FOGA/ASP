// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "FightingGame_PlayerController.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ASP_FightingGame_PlayerController_generated_h
#error "FightingGame_PlayerController.generated.h already included, missing '#pragma once' in FightingGame_PlayerController.h"
#endif
#define ASP_FightingGame_PlayerController_generated_h

#define FID_ASP_Source_ASP_FightingGame_PlayerController_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFightingGame_PlayerController(); \
	friend struct Z_Construct_UClass_AFightingGame_PlayerController_Statics; \
public: \
	DECLARE_CLASS(AFightingGame_PlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ASP"), NO_API) \
	DECLARE_SERIALIZER(AFightingGame_PlayerController)


#define FID_ASP_Source_ASP_FightingGame_PlayerController_h_21_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AFightingGame_PlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AFightingGame_PlayerController(AFightingGame_PlayerController&&); \
	AFightingGame_PlayerController(const AFightingGame_PlayerController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFightingGame_PlayerController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFightingGame_PlayerController); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AFightingGame_PlayerController) \
	NO_API virtual ~AFightingGame_PlayerController();


#define FID_ASP_Source_ASP_FightingGame_PlayerController_h_18_PROLOG
#define FID_ASP_Source_ASP_FightingGame_PlayerController_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ASP_Source_ASP_FightingGame_PlayerController_h_21_INCLASS_NO_PURE_DECLS \
	FID_ASP_Source_ASP_FightingGame_PlayerController_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ASP_API UClass* StaticClass<class AFightingGame_PlayerController>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ASP_Source_ASP_FightingGame_PlayerController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
