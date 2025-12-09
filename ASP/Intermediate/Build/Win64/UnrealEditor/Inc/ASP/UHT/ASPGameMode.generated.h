// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ASPGameMode.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ASP_ASPGameMode_generated_h
#error "ASPGameMode.generated.h already included, missing '#pragma once' in ASPGameMode.h"
#endif
#define ASP_ASPGameMode_generated_h

#define FID_ASP_Source_ASP_ASPGameMode_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAASPGameMode(); \
	friend struct Z_Construct_UClass_AASPGameMode_Statics; \
public: \
	DECLARE_CLASS(AASPGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/ASP"), ASP_API) \
	DECLARE_SERIALIZER(AASPGameMode)


#define FID_ASP_Source_ASP_ASPGameMode_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AASPGameMode(AASPGameMode&&); \
	AASPGameMode(const AASPGameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(ASP_API, AASPGameMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AASPGameMode); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AASPGameMode) \
	ASP_API virtual ~AASPGameMode();


#define FID_ASP_Source_ASP_ASPGameMode_h_13_PROLOG
#define FID_ASP_Source_ASP_ASPGameMode_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ASP_Source_ASP_ASPGameMode_h_16_INCLASS_NO_PURE_DECLS \
	FID_ASP_Source_ASP_ASPGameMode_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ASP_API UClass* StaticClass<class AASPGameMode>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ASP_Source_ASP_ASPGameMode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
