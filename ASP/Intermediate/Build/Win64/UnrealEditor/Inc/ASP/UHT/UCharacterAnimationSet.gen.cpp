// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ASP/UCharacterAnimationSet.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUCharacterAnimationSet() {}

// Begin Cross Module References
ASP_API UClass* Z_Construct_UClass_UCharacterAnimationSet();
ASP_API UClass* Z_Construct_UClass_UCharacterAnimationSet_NoRegister();
ASP_API UEnum* Z_Construct_UEnum_ASP_EStates();
ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UDataAsset();
UPackage* Z_Construct_UPackage__Script_ASP();
// End Cross Module References

// Begin Class UCharacterAnimationSet
void UCharacterAnimationSet::StaticRegisterNativesUCharacterAnimationSet()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCharacterAnimationSet);
UClass* Z_Construct_UClass_UCharacterAnimationSet_NoRegister()
{
	return UCharacterAnimationSet::StaticClass();
}
struct Z_Construct_UClass_UCharacterAnimationSet_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "UCharacterAnimationSet.h" },
		{ "ModuleRelativePath", "UCharacterAnimationSet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MontageMap_MetaData[] = {
		{ "Category", "Animation" },
		{ "ModuleRelativePath", "UCharacterAnimationSet.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MontageMap_ValueProp;
	static const UECodeGen_Private::FBytePropertyParams NewProp_MontageMap_Key_KeyProp_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_MontageMap_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_MontageMap;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCharacterAnimationSet>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCharacterAnimationSet_Statics::NewProp_MontageMap_ValueProp = { "MontageMap", nullptr, (EPropertyFlags)0x0104000000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UCharacterAnimationSet_Statics::NewProp_MontageMap_Key_KeyProp_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UCharacterAnimationSet_Statics::NewProp_MontageMap_Key_KeyProp = { "MontageMap_Key", nullptr, (EPropertyFlags)0x0100000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_ASP_EStates, METADATA_PARAMS(0, nullptr) }; // 4060847622
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UCharacterAnimationSet_Statics::NewProp_MontageMap = { "MontageMap", nullptr, (EPropertyFlags)0x0114000000000015, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCharacterAnimationSet, MontageMap), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MontageMap_MetaData), NewProp_MontageMap_MetaData) }; // 4060847622
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCharacterAnimationSet_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCharacterAnimationSet_Statics::NewProp_MontageMap_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCharacterAnimationSet_Statics::NewProp_MontageMap_Key_KeyProp_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCharacterAnimationSet_Statics::NewProp_MontageMap_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCharacterAnimationSet_Statics::NewProp_MontageMap,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCharacterAnimationSet_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UCharacterAnimationSet_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_ASP,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCharacterAnimationSet_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCharacterAnimationSet_Statics::ClassParams = {
	&UCharacterAnimationSet::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UCharacterAnimationSet_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UCharacterAnimationSet_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCharacterAnimationSet_Statics::Class_MetaDataParams), Z_Construct_UClass_UCharacterAnimationSet_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCharacterAnimationSet()
{
	if (!Z_Registration_Info_UClass_UCharacterAnimationSet.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCharacterAnimationSet.OuterSingleton, Z_Construct_UClass_UCharacterAnimationSet_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCharacterAnimationSet.OuterSingleton;
}
template<> ASP_API UClass* StaticClass<UCharacterAnimationSet>()
{
	return UCharacterAnimationSet::StaticClass();
}
UCharacterAnimationSet::UCharacterAnimationSet(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCharacterAnimationSet);
UCharacterAnimationSet::~UCharacterAnimationSet() {}
// End Class UCharacterAnimationSet

// Begin Registration
struct Z_CompiledInDeferFile_FID_ASP_Source_ASP_UCharacterAnimationSet_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCharacterAnimationSet, UCharacterAnimationSet::StaticClass, TEXT("UCharacterAnimationSet"), &Z_Registration_Info_UClass_UCharacterAnimationSet, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCharacterAnimationSet), 2297109730U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ASP_Source_ASP_UCharacterAnimationSet_h_2905407983(TEXT("/Script/ASP"),
	Z_CompiledInDeferFile_FID_ASP_Source_ASP_UCharacterAnimationSet_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ASP_Source_ASP_UCharacterAnimationSet_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
