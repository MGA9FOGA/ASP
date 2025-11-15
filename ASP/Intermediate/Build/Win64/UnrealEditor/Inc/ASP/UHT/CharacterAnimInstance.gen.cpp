// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ASP/CharacterAnimInstance.h"
#include "Runtime/Engine/Classes/Components/SkeletalMeshComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCharacterAnimInstance() {}

// Begin Cross Module References
ASP_API UClass* Z_Construct_UClass_UCharacterAnimInstance();
ASP_API UClass* Z_Construct_UClass_UCharacterAnimInstance_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UAnimInstance();
ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
UPackage* Z_Construct_UPackage__Script_ASP();
// End Cross Module References

// Begin Class UCharacterAnimInstance Function HandleMontageEnded
struct Z_Construct_UFunction_UCharacterAnimInstance_HandleMontageEnded_Statics
{
	struct CharacterAnimInstance_eventHandleMontageEnded_Parms
	{
		UAnimMontage* _montage;
		bool _bInterrupted;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "CharacterAnimInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp__montage;
	static void NewProp__bInterrupted_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp__bInterrupted;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCharacterAnimInstance_HandleMontageEnded_Statics::NewProp__montage = { "_montage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CharacterAnimInstance_eventHandleMontageEnded_Parms, _montage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UCharacterAnimInstance_HandleMontageEnded_Statics::NewProp__bInterrupted_SetBit(void* Obj)
{
	((CharacterAnimInstance_eventHandleMontageEnded_Parms*)Obj)->_bInterrupted = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCharacterAnimInstance_HandleMontageEnded_Statics::NewProp__bInterrupted = { "_bInterrupted", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CharacterAnimInstance_eventHandleMontageEnded_Parms), &Z_Construct_UFunction_UCharacterAnimInstance_HandleMontageEnded_Statics::NewProp__bInterrupted_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCharacterAnimInstance_HandleMontageEnded_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCharacterAnimInstance_HandleMontageEnded_Statics::NewProp__montage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCharacterAnimInstance_HandleMontageEnded_Statics::NewProp__bInterrupted,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCharacterAnimInstance_HandleMontageEnded_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCharacterAnimInstance_HandleMontageEnded_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCharacterAnimInstance, nullptr, "HandleMontageEnded", nullptr, nullptr, Z_Construct_UFunction_UCharacterAnimInstance_HandleMontageEnded_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCharacterAnimInstance_HandleMontageEnded_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCharacterAnimInstance_HandleMontageEnded_Statics::CharacterAnimInstance_eventHandleMontageEnded_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCharacterAnimInstance_HandleMontageEnded_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCharacterAnimInstance_HandleMontageEnded_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCharacterAnimInstance_HandleMontageEnded_Statics::CharacterAnimInstance_eventHandleMontageEnded_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCharacterAnimInstance_HandleMontageEnded()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCharacterAnimInstance_HandleMontageEnded_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCharacterAnimInstance::execHandleMontageEnded)
{
	P_GET_OBJECT(UAnimMontage,Z_Param__montage);
	P_GET_UBOOL(Z_Param__bInterrupted);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleMontageEnded(Z_Param__montage,Z_Param__bInterrupted);
	P_NATIVE_END;
}
// End Class UCharacterAnimInstance Function HandleMontageEnded

// Begin Class UCharacterAnimInstance
void UCharacterAnimInstance::StaticRegisterNativesUCharacterAnimInstance()
{
	UClass* Class = UCharacterAnimInstance::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "HandleMontageEnded", &UCharacterAnimInstance::execHandleMontageEnded },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCharacterAnimInstance);
UClass* Z_Construct_UClass_UCharacterAnimInstance_NoRegister()
{
	return UCharacterAnimInstance::StaticClass();
}
struct Z_Construct_UClass_UCharacterAnimInstance_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "AnimInstance" },
		{ "IncludePath", "CharacterAnimInstance.h" },
		{ "ModuleRelativePath", "CharacterAnimInstance.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UCharacterAnimInstance_HandleMontageEnded, "HandleMontageEnded" }, // 3643238693
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCharacterAnimInstance>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UCharacterAnimInstance_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAnimInstance,
	(UObject* (*)())Z_Construct_UPackage__Script_ASP,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCharacterAnimInstance_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCharacterAnimInstance_Statics::ClassParams = {
	&UCharacterAnimInstance::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x009000A8u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCharacterAnimInstance_Statics::Class_MetaDataParams), Z_Construct_UClass_UCharacterAnimInstance_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCharacterAnimInstance()
{
	if (!Z_Registration_Info_UClass_UCharacterAnimInstance.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCharacterAnimInstance.OuterSingleton, Z_Construct_UClass_UCharacterAnimInstance_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCharacterAnimInstance.OuterSingleton;
}
template<> ASP_API UClass* StaticClass<UCharacterAnimInstance>()
{
	return UCharacterAnimInstance::StaticClass();
}
UCharacterAnimInstance::UCharacterAnimInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCharacterAnimInstance);
UCharacterAnimInstance::~UCharacterAnimInstance() {}
// End Class UCharacterAnimInstance

// Begin Registration
struct Z_CompiledInDeferFile_FID_ASP_Source_ASP_CharacterAnimInstance_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCharacterAnimInstance, UCharacterAnimInstance::StaticClass, TEXT("UCharacterAnimInstance"), &Z_Registration_Info_UClass_UCharacterAnimInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCharacterAnimInstance), 1487388740U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ASP_Source_ASP_CharacterAnimInstance_h_752145553(TEXT("/Script/ASP"),
	Z_CompiledInDeferFile_FID_ASP_Source_ASP_CharacterAnimInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ASP_Source_ASP_CharacterAnimInstance_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
