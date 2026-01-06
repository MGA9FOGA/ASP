// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ASPCharacter.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FHitResult;
#ifdef ASP_ASPCharacter_generated_h
#error "ASPCharacter.generated.h already included, missing '#pragma once' in ASPCharacter.h"
#endif
#define ASP_ASPCharacter_generated_h

#define FID_ASP_Source_ASP_ASPCharacter_h_19_DELEGATE \
ASP_API void FOnCustomHit_DelegateWrapper(const FMulticastScriptDelegate& OnCustomHit, FHitResult const& HitResult);


#define FID_ASP_Source_ASP_ASPCharacter_h_20_DELEGATE \
ASP_API void FOnCustomOverlap_DelegateWrapper(const FMulticastScriptDelegate& OnCustomOverlap, AActor* OtherActor);


#define FID_ASP_Source_ASP_ASPCharacter_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnOverlapEnd); \
	DECLARE_FUNCTION(execOnHit); \
	DECLARE_FUNCTION(execOnOverlapBegin); \
	DECLARE_FUNCTION(execHandleCustomOverlapEnd); \
	DECLARE_FUNCTION(execHandleCustomOverlapBegin); \
	DECLARE_FUNCTION(execHandleCustomHit);


#define FID_ASP_Source_ASP_ASPCharacter_h_25_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAASPCharacter(); \
	friend struct Z_Construct_UClass_AASPCharacter_Statics; \
public: \
	DECLARE_CLASS(AASPCharacter, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ASP"), NO_API) \
	DECLARE_SERIALIZER(AASPCharacter) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define FID_ASP_Source_ASP_ASPCharacter_h_25_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AASPCharacter(AASPCharacter&&); \
	AASPCharacter(const AASPCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AASPCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AASPCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AASPCharacter) \
	NO_API virtual ~AASPCharacter();


#define FID_ASP_Source_ASP_ASPCharacter_h_22_PROLOG
#define FID_ASP_Source_ASP_ASPCharacter_h_25_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ASP_Source_ASP_ASPCharacter_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_ASP_Source_ASP_ASPCharacter_h_25_INCLASS_NO_PURE_DECLS \
	FID_ASP_Source_ASP_ASPCharacter_h_25_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ASP_API UClass* StaticClass<class AASPCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ASP_Source_ASP_ASPCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
