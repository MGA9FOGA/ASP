// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "CustomMoveComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ASP_CustomMoveComponent_generated_h
#error "CustomMoveComponent.generated.h already included, missing '#pragma once' in CustomMoveComponent.h"
#endif
#define ASP_CustomMoveComponent_generated_h

#define FID_ASP_Source_ASP_CustomMoveComponent_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCustomMoveComponent(); \
	friend struct Z_Construct_UClass_UCustomMoveComponent_Statics; \
public: \
	DECLARE_CLASS(UCustomMoveComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ASP"), NO_API) \
	DECLARE_SERIALIZER(UCustomMoveComponent)


#define FID_ASP_Source_ASP_CustomMoveComponent_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCustomMoveComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UCustomMoveComponent(UCustomMoveComponent&&); \
	UCustomMoveComponent(const UCustomMoveComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCustomMoveComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCustomMoveComponent); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCustomMoveComponent) \
	NO_API virtual ~UCustomMoveComponent();


#define FID_ASP_Source_ASP_CustomMoveComponent_h_10_PROLOG
#define FID_ASP_Source_ASP_CustomMoveComponent_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ASP_Source_ASP_CustomMoveComponent_h_13_INCLASS_NO_PURE_DECLS \
	FID_ASP_Source_ASP_CustomMoveComponent_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ASP_API UClass* StaticClass<class UCustomMoveComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ASP_Source_ASP_CustomMoveComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
