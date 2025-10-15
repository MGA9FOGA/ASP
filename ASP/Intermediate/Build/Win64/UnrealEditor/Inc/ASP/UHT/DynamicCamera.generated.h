// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DynamicCamera.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ASP_DynamicCamera_generated_h
#error "DynamicCamera.generated.h already included, missing '#pragma once' in DynamicCamera.h"
#endif
#define ASP_DynamicCamera_generated_h

#define FID_ASP_Source_ASP_DynamicCamera_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesADynamicCamera(); \
	friend struct Z_Construct_UClass_ADynamicCamera_Statics; \
public: \
	DECLARE_CLASS(ADynamicCamera, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ASP"), NO_API) \
	DECLARE_SERIALIZER(ADynamicCamera)


#define FID_ASP_Source_ASP_DynamicCamera_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ADynamicCamera(ADynamicCamera&&); \
	ADynamicCamera(const ADynamicCamera&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADynamicCamera); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADynamicCamera); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ADynamicCamera) \
	NO_API virtual ~ADynamicCamera();


#define FID_ASP_Source_ASP_DynamicCamera_h_9_PROLOG
#define FID_ASP_Source_ASP_DynamicCamera_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ASP_Source_ASP_DynamicCamera_h_12_INCLASS_NO_PURE_DECLS \
	FID_ASP_Source_ASP_DynamicCamera_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ASP_API UClass* StaticClass<class ADynamicCamera>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ASP_Source_ASP_DynamicCamera_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
