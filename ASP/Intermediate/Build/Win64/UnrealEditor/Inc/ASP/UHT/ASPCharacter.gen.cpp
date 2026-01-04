// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ASP/ASPCharacter.h"
#include "Runtime/Engine/Classes/Engine/HitResult.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeASPCharacter() {}

// Begin Cross Module References
ASP_API UClass* Z_Construct_UClass_AASPCharacter();
ASP_API UClass* Z_Construct_UClass_AASPCharacter_NoRegister();
ASP_API UClass* Z_Construct_UClass_AFightingGame_PlayerController_NoRegister();
ASP_API UClass* Z_Construct_UClass_UCharacterAnimationSet_NoRegister();
ASP_API UClass* Z_Construct_UClass_UGameManager_NoRegister();
ASP_API UClass* Z_Construct_UClass_UPushBoxComponent_NoRegister();
ASP_API UFunction* Z_Construct_UDelegateFunction_ASP_OnCustomHit__DelegateSignature();
ASP_API UFunction* Z_Construct_UDelegateFunction_ASP_OnCustomOverlap__DelegateSignature();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UCapsuleComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USkeletalMeshComponent_NoRegister();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
UPackage* Z_Construct_UPackage__Script_ASP();
// End Cross Module References

// Begin Delegate FOnCustomHit
struct Z_Construct_UDelegateFunction_ASP_OnCustomHit__DelegateSignature_Statics
{
	struct _Script_ASP_eventOnCustomHit_Parms
	{
		FHitResult HitResult;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ASPCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HitResult_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_HitResult;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_ASP_OnCustomHit__DelegateSignature_Statics::NewProp_HitResult = { "HitResult", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_ASP_eventOnCustomHit_Parms, HitResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HitResult_MetaData), NewProp_HitResult_MetaData) }; // 4100991306
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ASP_OnCustomHit__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ASP_OnCustomHit__DelegateSignature_Statics::NewProp_HitResult,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ASP_OnCustomHit__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_ASP_OnCustomHit__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_ASP, nullptr, "OnCustomHit__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_ASP_OnCustomHit__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ASP_OnCustomHit__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_ASP_OnCustomHit__DelegateSignature_Statics::_Script_ASP_eventOnCustomHit_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ASP_OnCustomHit__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_ASP_OnCustomHit__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_ASP_OnCustomHit__DelegateSignature_Statics::_Script_ASP_eventOnCustomHit_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_ASP_OnCustomHit__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ASP_OnCustomHit__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnCustomHit_DelegateWrapper(const FMulticastScriptDelegate& OnCustomHit, FHitResult const& HitResult)
{
	struct _Script_ASP_eventOnCustomHit_Parms
	{
		FHitResult HitResult;
	};
	_Script_ASP_eventOnCustomHit_Parms Parms;
	Parms.HitResult=HitResult;
	OnCustomHit.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FOnCustomHit

// Begin Delegate FOnCustomOverlap
struct Z_Construct_UDelegateFunction_ASP_OnCustomOverlap__DelegateSignature_Statics
{
	struct _Script_ASP_eventOnCustomOverlap_Parms
	{
		AActor* OtherActor;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ASPCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_ASP_OnCustomOverlap__DelegateSignature_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_ASP_eventOnCustomOverlap_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ASP_OnCustomOverlap__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ASP_OnCustomOverlap__DelegateSignature_Statics::NewProp_OtherActor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ASP_OnCustomOverlap__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_ASP_OnCustomOverlap__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_ASP, nullptr, "OnCustomOverlap__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_ASP_OnCustomOverlap__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ASP_OnCustomOverlap__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_ASP_OnCustomOverlap__DelegateSignature_Statics::_Script_ASP_eventOnCustomOverlap_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ASP_OnCustomOverlap__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_ASP_OnCustomOverlap__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_ASP_OnCustomOverlap__DelegateSignature_Statics::_Script_ASP_eventOnCustomOverlap_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_ASP_OnCustomOverlap__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ASP_OnCustomOverlap__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnCustomOverlap_DelegateWrapper(const FMulticastScriptDelegate& OnCustomOverlap, AActor* OtherActor)
{
	struct _Script_ASP_eventOnCustomOverlap_Parms
	{
		AActor* OtherActor;
	};
	_Script_ASP_eventOnCustomOverlap_Parms Parms;
	Parms.OtherActor=OtherActor;
	OnCustomOverlap.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FOnCustomOverlap

// Begin Class AASPCharacter Function HandleCustomHit
struct Z_Construct_UFunction_AASPCharacter_HandleCustomHit_Statics
{
	struct ASPCharacter_eventHandleCustomHit_Parms
	{
		FHitResult _hit;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ASPCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__hit_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp__hit;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AASPCharacter_HandleCustomHit_Statics::NewProp__hit = { "_hit", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASPCharacter_eventHandleCustomHit_Parms, _hit), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__hit_MetaData), NewProp__hit_MetaData) }; // 4100991306
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AASPCharacter_HandleCustomHit_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AASPCharacter_HandleCustomHit_Statics::NewProp__hit,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AASPCharacter_HandleCustomHit_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AASPCharacter_HandleCustomHit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AASPCharacter, nullptr, "HandleCustomHit", nullptr, nullptr, Z_Construct_UFunction_AASPCharacter_HandleCustomHit_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AASPCharacter_HandleCustomHit_Statics::PropPointers), sizeof(Z_Construct_UFunction_AASPCharacter_HandleCustomHit_Statics::ASPCharacter_eventHandleCustomHit_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00480401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AASPCharacter_HandleCustomHit_Statics::Function_MetaDataParams), Z_Construct_UFunction_AASPCharacter_HandleCustomHit_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AASPCharacter_HandleCustomHit_Statics::ASPCharacter_eventHandleCustomHit_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AASPCharacter_HandleCustomHit()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AASPCharacter_HandleCustomHit_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AASPCharacter::execHandleCustomHit)
{
	P_GET_STRUCT_REF(FHitResult,Z_Param_Out__hit);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleCustomHit(Z_Param_Out__hit);
	P_NATIVE_END;
}
// End Class AASPCharacter Function HandleCustomHit

// Begin Class AASPCharacter Function HandleCustomOverlapBegin
struct Z_Construct_UFunction_AASPCharacter_HandleCustomOverlapBegin_Statics
{
	struct ASPCharacter_eventHandleCustomOverlapBegin_Parms
	{
		AActor* _otherActor;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ASPCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp__otherActor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AASPCharacter_HandleCustomOverlapBegin_Statics::NewProp__otherActor = { "_otherActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASPCharacter_eventHandleCustomOverlapBegin_Parms, _otherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AASPCharacter_HandleCustomOverlapBegin_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AASPCharacter_HandleCustomOverlapBegin_Statics::NewProp__otherActor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AASPCharacter_HandleCustomOverlapBegin_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AASPCharacter_HandleCustomOverlapBegin_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AASPCharacter, nullptr, "HandleCustomOverlapBegin", nullptr, nullptr, Z_Construct_UFunction_AASPCharacter_HandleCustomOverlapBegin_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AASPCharacter_HandleCustomOverlapBegin_Statics::PropPointers), sizeof(Z_Construct_UFunction_AASPCharacter_HandleCustomOverlapBegin_Statics::ASPCharacter_eventHandleCustomOverlapBegin_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AASPCharacter_HandleCustomOverlapBegin_Statics::Function_MetaDataParams), Z_Construct_UFunction_AASPCharacter_HandleCustomOverlapBegin_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AASPCharacter_HandleCustomOverlapBegin_Statics::ASPCharacter_eventHandleCustomOverlapBegin_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AASPCharacter_HandleCustomOverlapBegin()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AASPCharacter_HandleCustomOverlapBegin_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AASPCharacter::execHandleCustomOverlapBegin)
{
	P_GET_OBJECT(AActor,Z_Param__otherActor);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleCustomOverlapBegin(Z_Param__otherActor);
	P_NATIVE_END;
}
// End Class AASPCharacter Function HandleCustomOverlapBegin

// Begin Class AASPCharacter Function HandleCustomOverlapEnd
struct Z_Construct_UFunction_AASPCharacter_HandleCustomOverlapEnd_Statics
{
	struct ASPCharacter_eventHandleCustomOverlapEnd_Parms
	{
		AActor* _otherActor;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ASPCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp__otherActor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AASPCharacter_HandleCustomOverlapEnd_Statics::NewProp__otherActor = { "_otherActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASPCharacter_eventHandleCustomOverlapEnd_Parms, _otherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AASPCharacter_HandleCustomOverlapEnd_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AASPCharacter_HandleCustomOverlapEnd_Statics::NewProp__otherActor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AASPCharacter_HandleCustomOverlapEnd_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AASPCharacter_HandleCustomOverlapEnd_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AASPCharacter, nullptr, "HandleCustomOverlapEnd", nullptr, nullptr, Z_Construct_UFunction_AASPCharacter_HandleCustomOverlapEnd_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AASPCharacter_HandleCustomOverlapEnd_Statics::PropPointers), sizeof(Z_Construct_UFunction_AASPCharacter_HandleCustomOverlapEnd_Statics::ASPCharacter_eventHandleCustomOverlapEnd_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AASPCharacter_HandleCustomOverlapEnd_Statics::Function_MetaDataParams), Z_Construct_UFunction_AASPCharacter_HandleCustomOverlapEnd_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AASPCharacter_HandleCustomOverlapEnd_Statics::ASPCharacter_eventHandleCustomOverlapEnd_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AASPCharacter_HandleCustomOverlapEnd()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AASPCharacter_HandleCustomOverlapEnd_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AASPCharacter::execHandleCustomOverlapEnd)
{
	P_GET_OBJECT(AActor,Z_Param__otherActor);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleCustomOverlapEnd(Z_Param__otherActor);
	P_NATIVE_END;
}
// End Class AASPCharacter Function HandleCustomOverlapEnd

// Begin Class AASPCharacter Function OnHit
struct Z_Construct_UFunction_AASPCharacter_OnHit_Statics
{
	struct ASPCharacter_eventOnHit_Parms
	{
		UPrimitiveComponent* _hitComp;
		AActor* _otherActor;
		UPrimitiveComponent* _otherComp;
		FVector _ormalImpulse;
		FHitResult _hit;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ASPCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__hitComp_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__otherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__hit_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp__hitComp;
	static const UECodeGen_Private::FObjectPropertyParams NewProp__otherActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp__otherComp;
	static const UECodeGen_Private::FStructPropertyParams NewProp__ormalImpulse;
	static const UECodeGen_Private::FStructPropertyParams NewProp__hit;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AASPCharacter_OnHit_Statics::NewProp__hitComp = { "_hitComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASPCharacter_eventOnHit_Parms, _hitComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__hitComp_MetaData), NewProp__hitComp_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AASPCharacter_OnHit_Statics::NewProp__otherActor = { "_otherActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASPCharacter_eventOnHit_Parms, _otherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AASPCharacter_OnHit_Statics::NewProp__otherComp = { "_otherComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASPCharacter_eventOnHit_Parms, _otherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__otherComp_MetaData), NewProp__otherComp_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AASPCharacter_OnHit_Statics::NewProp__ormalImpulse = { "_ormalImpulse", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASPCharacter_eventOnHit_Parms, _ormalImpulse), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AASPCharacter_OnHit_Statics::NewProp__hit = { "_hit", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASPCharacter_eventOnHit_Parms, _hit), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__hit_MetaData), NewProp__hit_MetaData) }; // 4100991306
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AASPCharacter_OnHit_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AASPCharacter_OnHit_Statics::NewProp__hitComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AASPCharacter_OnHit_Statics::NewProp__otherActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AASPCharacter_OnHit_Statics::NewProp__otherComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AASPCharacter_OnHit_Statics::NewProp__ormalImpulse,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AASPCharacter_OnHit_Statics::NewProp__hit,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AASPCharacter_OnHit_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AASPCharacter_OnHit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AASPCharacter, nullptr, "OnHit", nullptr, nullptr, Z_Construct_UFunction_AASPCharacter_OnHit_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AASPCharacter_OnHit_Statics::PropPointers), sizeof(Z_Construct_UFunction_AASPCharacter_OnHit_Statics::ASPCharacter_eventOnHit_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C80401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AASPCharacter_OnHit_Statics::Function_MetaDataParams), Z_Construct_UFunction_AASPCharacter_OnHit_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AASPCharacter_OnHit_Statics::ASPCharacter_eventOnHit_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AASPCharacter_OnHit()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AASPCharacter_OnHit_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AASPCharacter::execOnHit)
{
	P_GET_OBJECT(UPrimitiveComponent,Z_Param__hitComp);
	P_GET_OBJECT(AActor,Z_Param__otherActor);
	P_GET_OBJECT(UPrimitiveComponent,Z_Param__otherComp);
	P_GET_STRUCT(FVector,Z_Param__ormalImpulse);
	P_GET_STRUCT_REF(FHitResult,Z_Param_Out__hit);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnHit(Z_Param__hitComp,Z_Param__otherActor,Z_Param__otherComp,Z_Param__ormalImpulse,Z_Param_Out__hit);
	P_NATIVE_END;
}
// End Class AASPCharacter Function OnHit

// Begin Class AASPCharacter Function OnOverlapBegin
struct Z_Construct_UFunction_AASPCharacter_OnOverlapBegin_Statics
{
	struct ASPCharacter_eventOnOverlapBegin_Parms
	{
		UPrimitiveComponent* _overlappedComp;
		AActor* _otherActor;
		UPrimitiveComponent* _otherComp;
		int32 _otherBodyIndex;
		bool _bFromSweep;
		FHitResult _sweepResult;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// =============================\n// === Collider Events (cosmetic) ===\n// =============================\n" },
#endif
		{ "ModuleRelativePath", "ASPCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "=== Collider Events (cosmetic) ===" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__overlappedComp_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__otherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__sweepResult_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp__overlappedComp;
	static const UECodeGen_Private::FObjectPropertyParams NewProp__otherActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp__otherComp;
	static const UECodeGen_Private::FIntPropertyParams NewProp__otherBodyIndex;
	static void NewProp__bFromSweep_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp__bFromSweep;
	static const UECodeGen_Private::FStructPropertyParams NewProp__sweepResult;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AASPCharacter_OnOverlapBegin_Statics::NewProp__overlappedComp = { "_overlappedComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASPCharacter_eventOnOverlapBegin_Parms, _overlappedComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__overlappedComp_MetaData), NewProp__overlappedComp_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AASPCharacter_OnOverlapBegin_Statics::NewProp__otherActor = { "_otherActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASPCharacter_eventOnOverlapBegin_Parms, _otherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AASPCharacter_OnOverlapBegin_Statics::NewProp__otherComp = { "_otherComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASPCharacter_eventOnOverlapBegin_Parms, _otherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__otherComp_MetaData), NewProp__otherComp_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AASPCharacter_OnOverlapBegin_Statics::NewProp__otherBodyIndex = { "_otherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASPCharacter_eventOnOverlapBegin_Parms, _otherBodyIndex), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_AASPCharacter_OnOverlapBegin_Statics::NewProp__bFromSweep_SetBit(void* Obj)
{
	((ASPCharacter_eventOnOverlapBegin_Parms*)Obj)->_bFromSweep = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AASPCharacter_OnOverlapBegin_Statics::NewProp__bFromSweep = { "_bFromSweep", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ASPCharacter_eventOnOverlapBegin_Parms), &Z_Construct_UFunction_AASPCharacter_OnOverlapBegin_Statics::NewProp__bFromSweep_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AASPCharacter_OnOverlapBegin_Statics::NewProp__sweepResult = { "_sweepResult", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASPCharacter_eventOnOverlapBegin_Parms, _sweepResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__sweepResult_MetaData), NewProp__sweepResult_MetaData) }; // 4100991306
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AASPCharacter_OnOverlapBegin_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AASPCharacter_OnOverlapBegin_Statics::NewProp__overlappedComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AASPCharacter_OnOverlapBegin_Statics::NewProp__otherActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AASPCharacter_OnOverlapBegin_Statics::NewProp__otherComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AASPCharacter_OnOverlapBegin_Statics::NewProp__otherBodyIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AASPCharacter_OnOverlapBegin_Statics::NewProp__bFromSweep,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AASPCharacter_OnOverlapBegin_Statics::NewProp__sweepResult,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AASPCharacter_OnOverlapBegin_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AASPCharacter_OnOverlapBegin_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AASPCharacter, nullptr, "OnOverlapBegin", nullptr, nullptr, Z_Construct_UFunction_AASPCharacter_OnOverlapBegin_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AASPCharacter_OnOverlapBegin_Statics::PropPointers), sizeof(Z_Construct_UFunction_AASPCharacter_OnOverlapBegin_Statics::ASPCharacter_eventOnOverlapBegin_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00480401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AASPCharacter_OnOverlapBegin_Statics::Function_MetaDataParams), Z_Construct_UFunction_AASPCharacter_OnOverlapBegin_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AASPCharacter_OnOverlapBegin_Statics::ASPCharacter_eventOnOverlapBegin_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AASPCharacter_OnOverlapBegin()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AASPCharacter_OnOverlapBegin_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AASPCharacter::execOnOverlapBegin)
{
	P_GET_OBJECT(UPrimitiveComponent,Z_Param__overlappedComp);
	P_GET_OBJECT(AActor,Z_Param__otherActor);
	P_GET_OBJECT(UPrimitiveComponent,Z_Param__otherComp);
	P_GET_PROPERTY(FIntProperty,Z_Param__otherBodyIndex);
	P_GET_UBOOL(Z_Param__bFromSweep);
	P_GET_STRUCT_REF(FHitResult,Z_Param_Out__sweepResult);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnOverlapBegin(Z_Param__overlappedComp,Z_Param__otherActor,Z_Param__otherComp,Z_Param__otherBodyIndex,Z_Param__bFromSweep,Z_Param_Out__sweepResult);
	P_NATIVE_END;
}
// End Class AASPCharacter Function OnOverlapBegin

// Begin Class AASPCharacter Function OnOverlapEnd
struct Z_Construct_UFunction_AASPCharacter_OnOverlapEnd_Statics
{
	struct ASPCharacter_eventOnOverlapEnd_Parms
	{
		UPrimitiveComponent* _overlappedComp;
		AActor* _otherActor;
		UPrimitiveComponent* _otherComp;
		int32 _otherBodyIndex;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ASPCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__overlappedComp_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__otherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp__overlappedComp;
	static const UECodeGen_Private::FObjectPropertyParams NewProp__otherActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp__otherComp;
	static const UECodeGen_Private::FIntPropertyParams NewProp__otherBodyIndex;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AASPCharacter_OnOverlapEnd_Statics::NewProp__overlappedComp = { "_overlappedComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASPCharacter_eventOnOverlapEnd_Parms, _overlappedComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__overlappedComp_MetaData), NewProp__overlappedComp_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AASPCharacter_OnOverlapEnd_Statics::NewProp__otherActor = { "_otherActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASPCharacter_eventOnOverlapEnd_Parms, _otherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AASPCharacter_OnOverlapEnd_Statics::NewProp__otherComp = { "_otherComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASPCharacter_eventOnOverlapEnd_Parms, _otherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__otherComp_MetaData), NewProp__otherComp_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AASPCharacter_OnOverlapEnd_Statics::NewProp__otherBodyIndex = { "_otherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASPCharacter_eventOnOverlapEnd_Parms, _otherBodyIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AASPCharacter_OnOverlapEnd_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AASPCharacter_OnOverlapEnd_Statics::NewProp__overlappedComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AASPCharacter_OnOverlapEnd_Statics::NewProp__otherActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AASPCharacter_OnOverlapEnd_Statics::NewProp__otherComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AASPCharacter_OnOverlapEnd_Statics::NewProp__otherBodyIndex,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AASPCharacter_OnOverlapEnd_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AASPCharacter_OnOverlapEnd_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AASPCharacter, nullptr, "OnOverlapEnd", nullptr, nullptr, Z_Construct_UFunction_AASPCharacter_OnOverlapEnd_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AASPCharacter_OnOverlapEnd_Statics::PropPointers), sizeof(Z_Construct_UFunction_AASPCharacter_OnOverlapEnd_Statics::ASPCharacter_eventOnOverlapEnd_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AASPCharacter_OnOverlapEnd_Statics::Function_MetaDataParams), Z_Construct_UFunction_AASPCharacter_OnOverlapEnd_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AASPCharacter_OnOverlapEnd_Statics::ASPCharacter_eventOnOverlapEnd_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AASPCharacter_OnOverlapEnd()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AASPCharacter_OnOverlapEnd_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AASPCharacter::execOnOverlapEnd)
{
	P_GET_OBJECT(UPrimitiveComponent,Z_Param__overlappedComp);
	P_GET_OBJECT(AActor,Z_Param__otherActor);
	P_GET_OBJECT(UPrimitiveComponent,Z_Param__otherComp);
	P_GET_PROPERTY(FIntProperty,Z_Param__otherBodyIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnOverlapEnd(Z_Param__overlappedComp,Z_Param__otherActor,Z_Param__otherComp,Z_Param__otherBodyIndex);
	P_NATIVE_END;
}
// End Class AASPCharacter Function OnOverlapEnd

// Begin Class AASPCharacter
void AASPCharacter::StaticRegisterNativesAASPCharacter()
{
	UClass* Class = AASPCharacter::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "HandleCustomHit", &AASPCharacter::execHandleCustomHit },
		{ "HandleCustomOverlapBegin", &AASPCharacter::execHandleCustomOverlapBegin },
		{ "HandleCustomOverlapEnd", &AASPCharacter::execHandleCustomOverlapEnd },
		{ "OnHit", &AASPCharacter::execOnHit },
		{ "OnOverlapBegin", &AASPCharacter::execOnOverlapBegin },
		{ "OnOverlapEnd", &AASPCharacter::execOnOverlapEnd },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AASPCharacter);
UClass* Z_Construct_UClass_AASPCharacter_NoRegister()
{
	return AASPCharacter::StaticClass();
}
struct Z_Construct_UClass_AASPCharacter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "ASPCharacter.h" },
		{ "ModuleRelativePath", "ASPCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Mesh_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Character" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// =============================\n// === Components ===\n// =============================\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ASPCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "=== Components ===" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Capsule_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ASPCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PushBox_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ASPCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_animationSet_MetaData[] = {
		{ "Category", "Animation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// =============================\n// === Animation ===\n// =============================\n" },
#endif
		{ "ModuleRelativePath", "ASPCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "=== Animation ===" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_forwardVector_MetaData[] = {
		{ "Category", "Animation" },
		{ "ModuleRelativePath", "ASPCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_playerController_MetaData[] = {
		{ "Category", "ASPCharacter" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ==================================\n// === Playercontroller/GameManager ===\n// ==================================\n" },
#endif
		{ "ModuleRelativePath", "ASPCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "=== Playercontroller/GameManager ===" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_gameManager_MetaData[] = {
		{ "Category", "ASPCharacter" },
		{ "ModuleRelativePath", "ASPCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_targetRotation_MetaData[] = {
		{ "Category", "ASPCharacter" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// =============================\n// === Rotation ===\n// =============================\n" },
#endif
		{ "ModuleRelativePath", "ASPCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "=== Rotation ===" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnCustomHit_MetaData[] = {
		{ "Category", "CustomMove|Events" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// =========================================\n// === Events for cosmetic Overlaps/Hit  ===\n// =========================================\n" },
#endif
		{ "ModuleRelativePath", "ASPCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "=== Events for cosmetic Overlaps/Hit  ===" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnCustomBeginOverlap_MetaData[] = {
		{ "ModuleRelativePath", "ASPCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnCustomEndOverlap_MetaData[] = {
		{ "ModuleRelativePath", "ASPCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Mesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Capsule;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PushBox;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_m_animationSet;
	static const UECodeGen_Private::FStructPropertyParams NewProp_m_forwardVector;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_m_playerController;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_m_gameManager;
	static const UECodeGen_Private::FStructPropertyParams NewProp_m_targetRotation;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnCustomHit;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnCustomBeginOverlap;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnCustomEndOverlap;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AASPCharacter_HandleCustomHit, "HandleCustomHit" }, // 3577566205
		{ &Z_Construct_UFunction_AASPCharacter_HandleCustomOverlapBegin, "HandleCustomOverlapBegin" }, // 2601317895
		{ &Z_Construct_UFunction_AASPCharacter_HandleCustomOverlapEnd, "HandleCustomOverlapEnd" }, // 3224541007
		{ &Z_Construct_UFunction_AASPCharacter_OnHit, "OnHit" }, // 776553848
		{ &Z_Construct_UFunction_AASPCharacter_OnOverlapBegin, "OnOverlapBegin" }, // 1174541321
		{ &Z_Construct_UFunction_AASPCharacter_OnOverlapEnd, "OnOverlapEnd" }, // 2027696274
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AASPCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AASPCharacter_Statics::NewProp_Mesh = { "Mesh", nullptr, (EPropertyFlags)0x01240800000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AASPCharacter, Mesh), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Mesh_MetaData), NewProp_Mesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AASPCharacter_Statics::NewProp_Capsule = { "Capsule", nullptr, (EPropertyFlags)0x01240800000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AASPCharacter, Capsule), Z_Construct_UClass_UCapsuleComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Capsule_MetaData), NewProp_Capsule_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AASPCharacter_Statics::NewProp_PushBox = { "PushBox", nullptr, (EPropertyFlags)0x01240800000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AASPCharacter, PushBox), Z_Construct_UClass_UPushBoxComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PushBox_MetaData), NewProp_PushBox_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AASPCharacter_Statics::NewProp_m_animationSet = { "m_animationSet", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AASPCharacter, m_animationSet), Z_Construct_UClass_UCharacterAnimationSet_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_animationSet_MetaData), NewProp_m_animationSet_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AASPCharacter_Statics::NewProp_m_forwardVector = { "m_forwardVector", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AASPCharacter, m_forwardVector), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_forwardVector_MetaData), NewProp_m_forwardVector_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AASPCharacter_Statics::NewProp_m_playerController = { "m_playerController", nullptr, (EPropertyFlags)0x0020080000020001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AASPCharacter, m_playerController), Z_Construct_UClass_AFightingGame_PlayerController_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_playerController_MetaData), NewProp_m_playerController_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AASPCharacter_Statics::NewProp_m_gameManager = { "m_gameManager", nullptr, (EPropertyFlags)0x0020080000020001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AASPCharacter, m_gameManager), Z_Construct_UClass_UGameManager_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_gameManager_MetaData), NewProp_m_gameManager_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AASPCharacter_Statics::NewProp_m_targetRotation = { "m_targetRotation", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AASPCharacter, m_targetRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_targetRotation_MetaData), NewProp_m_targetRotation_MetaData) };
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_AASPCharacter_Statics::NewProp_OnCustomHit = { "OnCustomHit", nullptr, (EPropertyFlags)0x0020080010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AASPCharacter, OnCustomHit), Z_Construct_UDelegateFunction_ASP_OnCustomHit__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnCustomHit_MetaData), NewProp_OnCustomHit_MetaData) }; // 1052026296
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_AASPCharacter_Statics::NewProp_OnCustomBeginOverlap = { "OnCustomBeginOverlap", nullptr, (EPropertyFlags)0x0020080010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AASPCharacter, OnCustomBeginOverlap), Z_Construct_UDelegateFunction_ASP_OnCustomOverlap__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnCustomBeginOverlap_MetaData), NewProp_OnCustomBeginOverlap_MetaData) }; // 6881770
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_AASPCharacter_Statics::NewProp_OnCustomEndOverlap = { "OnCustomEndOverlap", nullptr, (EPropertyFlags)0x0020080010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AASPCharacter, OnCustomEndOverlap), Z_Construct_UDelegateFunction_ASP_OnCustomOverlap__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnCustomEndOverlap_MetaData), NewProp_OnCustomEndOverlap_MetaData) }; // 6881770
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AASPCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AASPCharacter_Statics::NewProp_Mesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AASPCharacter_Statics::NewProp_Capsule,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AASPCharacter_Statics::NewProp_PushBox,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AASPCharacter_Statics::NewProp_m_animationSet,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AASPCharacter_Statics::NewProp_m_forwardVector,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AASPCharacter_Statics::NewProp_m_playerController,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AASPCharacter_Statics::NewProp_m_gameManager,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AASPCharacter_Statics::NewProp_m_targetRotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AASPCharacter_Statics::NewProp_OnCustomHit,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AASPCharacter_Statics::NewProp_OnCustomBeginOverlap,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AASPCharacter_Statics::NewProp_OnCustomEndOverlap,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AASPCharacter_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AASPCharacter_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_ASP,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AASPCharacter_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AASPCharacter_Statics::ClassParams = {
	&AASPCharacter::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AASPCharacter_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AASPCharacter_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AASPCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_AASPCharacter_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AASPCharacter()
{
	if (!Z_Registration_Info_UClass_AASPCharacter.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AASPCharacter.OuterSingleton, Z_Construct_UClass_AASPCharacter_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AASPCharacter.OuterSingleton;
}
template<> ASP_API UClass* StaticClass<AASPCharacter>()
{
	return AASPCharacter::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AASPCharacter);
AASPCharacter::~AASPCharacter() {}
// End Class AASPCharacter

// Begin Registration
struct Z_CompiledInDeferFile_FID_ASP_Source_ASP_ASPCharacter_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AASPCharacter, AASPCharacter::StaticClass, TEXT("AASPCharacter"), &Z_Registration_Info_UClass_AASPCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AASPCharacter), 4156846159U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ASP_Source_ASP_ASPCharacter_h_2610662512(TEXT("/Script/ASP"),
	Z_CompiledInDeferFile_FID_ASP_Source_ASP_ASPCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ASP_Source_ASP_ASPCharacter_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
