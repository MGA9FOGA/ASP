// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MoveableInterface.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ASP_MoveableInterface_generated_h
#error "MoveableInterface.generated.h already included, missing '#pragma once' in MoveableInterface.h"
#endif
#define ASP_MoveableInterface_generated_h

#define FID_ASP_Source_ASP_MoveableInterface_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMoveableInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UMoveableInterface(UMoveableInterface&&); \
	UMoveableInterface(const UMoveableInterface&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMoveableInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMoveableInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMoveableInterface) \
	NO_API virtual ~UMoveableInterface();


#define FID_ASP_Source_ASP_MoveableInterface_h_15_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUMoveableInterface(); \
	friend struct Z_Construct_UClass_UMoveableInterface_Statics; \
public: \
	DECLARE_CLASS(UMoveableInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/ASP"), NO_API) \
	DECLARE_SERIALIZER(UMoveableInterface)


#define FID_ASP_Source_ASP_MoveableInterface_h_15_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_ASP_Source_ASP_MoveableInterface_h_15_GENERATED_UINTERFACE_BODY() \
	FID_ASP_Source_ASP_MoveableInterface_h_15_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_ASP_Source_ASP_MoveableInterface_h_15_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IMoveableInterface() {} \
public: \
	typedef UMoveableInterface UClassType; \
	typedef IMoveableInterface ThisClass; \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_ASP_Source_ASP_MoveableInterface_h_12_PROLOG
#define FID_ASP_Source_ASP_MoveableInterface_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ASP_Source_ASP_MoveableInterface_h_15_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ASP_API UClass* StaticClass<class UMoveableInterface>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ASP_Source_ASP_MoveableInterface_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
