// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "UFighting_GameGameInstance.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ASP_UFighting_GameGameInstance_generated_h
#error "UFighting_GameGameInstance.generated.h already included, missing '#pragma once' in UFighting_GameGameInstance.h"
#endif
#define ASP_UFighting_GameGameInstance_generated_h

#define FID_ASP_Source_ASP_UFighting_GameGameInstance_h_8_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUFighting_GameGameInstance(); \
	friend struct Z_Construct_UClass_UFighting_GameGameInstance_Statics; \
public: \
	DECLARE_CLASS(UFighting_GameGameInstance, UGameInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/ASP"), NO_API) \
	DECLARE_SERIALIZER(UFighting_GameGameInstance)


#define FID_ASP_Source_ASP_UFighting_GameGameInstance_h_8_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UFighting_GameGameInstance(UFighting_GameGameInstance&&); \
	UFighting_GameGameInstance(const UFighting_GameGameInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFighting_GameGameInstance); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFighting_GameGameInstance); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UFighting_GameGameInstance) \
	NO_API virtual ~UFighting_GameGameInstance();


#define FID_ASP_Source_ASP_UFighting_GameGameInstance_h_5_PROLOG
#define FID_ASP_Source_ASP_UFighting_GameGameInstance_h_8_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ASP_Source_ASP_UFighting_GameGameInstance_h_8_INCLASS_NO_PURE_DECLS \
	FID_ASP_Source_ASP_UFighting_GameGameInstance_h_8_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ASP_API UClass* StaticClass<class UFighting_GameGameInstance>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ASP_Source_ASP_UFighting_GameGameInstance_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
