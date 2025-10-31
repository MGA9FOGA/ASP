// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "GameManager.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class IMoveableInterface;
#ifdef ASP_GameManager_generated_h
#error "GameManager.generated.h already included, missing '#pragma once' in GameManager.h"
#endif
#define ASP_GameManager_generated_h

#define FID_ASP_Source_ASP_GameManager_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execRegisterMovable); \
	DECLARE_FUNCTION(execFixedGameUpdate60Hz);


#define FID_ASP_Source_ASP_GameManager_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGameManager(); \
	friend struct Z_Construct_UClass_UGameManager_Statics; \
public: \
	DECLARE_CLASS(UGameManager, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ASP"), NO_API) \
	DECLARE_SERIALIZER(UGameManager)


#define FID_ASP_Source_ASP_GameManager_h_22_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UGameManager(UGameManager&&); \
	UGameManager(const UGameManager&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGameManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGameManager); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UGameManager) \
	NO_API virtual ~UGameManager();


#define FID_ASP_Source_ASP_GameManager_h_19_PROLOG
#define FID_ASP_Source_ASP_GameManager_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ASP_Source_ASP_GameManager_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_ASP_Source_ASP_GameManager_h_22_INCLASS_NO_PURE_DECLS \
	FID_ASP_Source_ASP_GameManager_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ASP_API UClass* StaticClass<class UGameManager>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ASP_Source_ASP_GameManager_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
