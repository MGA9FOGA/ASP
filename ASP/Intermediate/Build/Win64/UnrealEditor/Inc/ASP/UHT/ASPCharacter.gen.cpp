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
ASP_API UClass* Z_Construct_UClass_UCustomMoveComponent_NoRegister();
ASP_API UClass* Z_Construct_UClass_UMoveableInterface_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UCapsuleComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USkeletalMeshComponent_NoRegister();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
UPackage* Z_Construct_UPackage__Script_ASP();
// End Cross Module References

// Begin Class AASPCharacter Function GetCapsuleComponent
struct Z_Construct_UFunction_AASPCharacter_GetCapsuleComponent_Statics
{
	struct ASPCharacter_eventGetCapsuleComponent_Parms
	{
		UCapsuleComponent* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ASPCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AASPCharacter_GetCapsuleComponent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASPCharacter_eventGetCapsuleComponent_Parms, ReturnValue), Z_Construct_UClass_UCapsuleComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AASPCharacter_GetCapsuleComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AASPCharacter_GetCapsuleComponent_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AASPCharacter_GetCapsuleComponent_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AASPCharacter_GetCapsuleComponent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AASPCharacter, nullptr, "GetCapsuleComponent", nullptr, nullptr, Z_Construct_UFunction_AASPCharacter_GetCapsuleComponent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AASPCharacter_GetCapsuleComponent_Statics::PropPointers), sizeof(Z_Construct_UFunction_AASPCharacter_GetCapsuleComponent_Statics::ASPCharacter_eventGetCapsuleComponent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AASPCharacter_GetCapsuleComponent_Statics::Function_MetaDataParams), Z_Construct_UFunction_AASPCharacter_GetCapsuleComponent_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AASPCharacter_GetCapsuleComponent_Statics::ASPCharacter_eventGetCapsuleComponent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AASPCharacter_GetCapsuleComponent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AASPCharacter_GetCapsuleComponent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AASPCharacter::execGetCapsuleComponent)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UCapsuleComponent**)Z_Param__Result=P_THIS->GetCapsuleComponent();
	P_NATIVE_END;
}
// End Class AASPCharacter Function GetCapsuleComponent

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

// Begin Class AASPCharacter
void AASPCharacter::StaticRegisterNativesAASPCharacter()
{
	UClass* Class = AASPCharacter::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetCapsuleComponent", &AASPCharacter::execGetCapsuleComponent },
		{ "HandleCustomHit", &AASPCharacter::execHandleCustomHit },
		{ "HandleCustomOverlapBegin", &AASPCharacter::execHandleCustomOverlapBegin },
		{ "HandleCustomOverlapEnd", &AASPCharacter::execHandleCustomOverlapEnd },
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
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ASPCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Capsule_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ASPCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_movement_MetaData[] = {
		{ "Category", "ASPCharacter" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ASPCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_playerController_MetaData[] = {
		{ "Category", "ASPCharacter" },
		{ "ModuleRelativePath", "ASPCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_playerID_MetaData[] = {
		{ "Category", "ASPCharacter" },
		{ "ModuleRelativePath", "ASPCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Mesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Capsule;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_m_movement;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_m_playerController;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_m_playerID;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AASPCharacter_GetCapsuleComponent, "GetCapsuleComponent" }, // 862520768
		{ &Z_Construct_UFunction_AASPCharacter_HandleCustomHit, "HandleCustomHit" }, // 3577566205
		{ &Z_Construct_UFunction_AASPCharacter_HandleCustomOverlapBegin, "HandleCustomOverlapBegin" }, // 2601317895
		{ &Z_Construct_UFunction_AASPCharacter_HandleCustomOverlapEnd, "HandleCustomOverlapEnd" }, // 3224541007
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AASPCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AASPCharacter_Statics::NewProp_Mesh = { "Mesh", nullptr, (EPropertyFlags)0x01440000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AASPCharacter, Mesh), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Mesh_MetaData), NewProp_Mesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AASPCharacter_Statics::NewProp_Capsule = { "Capsule", nullptr, (EPropertyFlags)0x01440000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AASPCharacter, Capsule), Z_Construct_UClass_UCapsuleComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Capsule_MetaData), NewProp_Capsule_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AASPCharacter_Statics::NewProp_m_movement = { "m_movement", nullptr, (EPropertyFlags)0x00200800000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AASPCharacter, m_movement), Z_Construct_UClass_UCustomMoveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_movement_MetaData), NewProp_m_movement_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AASPCharacter_Statics::NewProp_m_playerController = { "m_playerController", nullptr, (EPropertyFlags)0x0020080000020001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AASPCharacter, m_playerController), Z_Construct_UClass_AFightingGame_PlayerController_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_playerController_MetaData), NewProp_m_playerController_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AASPCharacter_Statics::NewProp_m_playerID = { "m_playerID", nullptr, (EPropertyFlags)0x0020080000020001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AASPCharacter, m_playerID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_playerID_MetaData), NewProp_m_playerID_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AASPCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AASPCharacter_Statics::NewProp_Mesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AASPCharacter_Statics::NewProp_Capsule,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AASPCharacter_Statics::NewProp_m_movement,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AASPCharacter_Statics::NewProp_m_playerController,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AASPCharacter_Statics::NewProp_m_playerID,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AASPCharacter_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AASPCharacter_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_ASP,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AASPCharacter_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AASPCharacter_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UMoveableInterface_NoRegister, (int32)VTABLE_OFFSET(AASPCharacter, IMoveableInterface), false },  // 3023271143
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_AASPCharacter_Statics::ClassParams = {
	&AASPCharacter::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AASPCharacter_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AASPCharacter_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
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
		{ Z_Construct_UClass_AASPCharacter, AASPCharacter::StaticClass, TEXT("AASPCharacter"), &Z_Registration_Info_UClass_AASPCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AASPCharacter), 2313589075U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ASP_Source_ASP_ASPCharacter_h_2749995839(TEXT("/Script/ASP"),
	Z_CompiledInDeferFile_FID_ASP_Source_ASP_ASPCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ASP_Source_ASP_ASPCharacter_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
