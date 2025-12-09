// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ASP/UFighting_GameGameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUFighting_GameGameInstance() {}

// Begin Cross Module References
ASP_API UClass* Z_Construct_UClass_AASPCharacter_NoRegister();
ASP_API UClass* Z_Construct_UClass_UFighting_GameGameInstance();
ASP_API UClass* Z_Construct_UClass_UFighting_GameGameInstance_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
ENGINE_API UClass* Z_Construct_UClass_UGameInstance();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
UPackage* Z_Construct_UPackage__Script_ASP();
// End Cross Module References

// Begin Class UFighting_GameGameInstance
void UFighting_GameGameInstance::StaticRegisterNativesUFighting_GameGameInstance()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UFighting_GameGameInstance);
UClass* Z_Construct_UClass_UFighting_GameGameInstance_NoRegister()
{
	return UFighting_GameGameInstance::StaticClass();
}
struct Z_Construct_UClass_UFighting_GameGameInstance_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "UFighting_GameGameInstance.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "UFighting_GameGameInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SelectedPlayer1Class_MetaData[] = {
		{ "Category", "Fighting_GameGameInstance" },
		{ "ModuleRelativePath", "UFighting_GameGameInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SelectedPlayer2Class_MetaData[] = {
		{ "Category", "Fighting_GameGameInstance" },
		{ "ModuleRelativePath", "UFighting_GameGameInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SelectablePlayers_MetaData[] = {
		{ "Category", "Fighting_GameGameInstance" },
		{ "ModuleRelativePath", "UFighting_GameGameInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultMappingContext_Player1_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "UFighting_GameGameInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultMappingContext_Player2_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "UFighting_GameGameInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FClassPropertyParams NewProp_SelectedPlayer1Class;
	static const UECodeGen_Private::FClassPropertyParams NewProp_SelectedPlayer2Class;
	static const UECodeGen_Private::FClassPropertyParams NewProp_SelectablePlayers_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_SelectablePlayers;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DefaultMappingContext_Player1;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DefaultMappingContext_Player2;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UFighting_GameGameInstance>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UFighting_GameGameInstance_Statics::NewProp_SelectedPlayer1Class = { "SelectedPlayer1Class", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UFighting_GameGameInstance, SelectedPlayer1Class), Z_Construct_UClass_UClass, Z_Construct_UClass_AASPCharacter_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectedPlayer1Class_MetaData), NewProp_SelectedPlayer1Class_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UFighting_GameGameInstance_Statics::NewProp_SelectedPlayer2Class = { "SelectedPlayer2Class", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UFighting_GameGameInstance, SelectedPlayer2Class), Z_Construct_UClass_UClass, Z_Construct_UClass_AASPCharacter_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectedPlayer2Class_MetaData), NewProp_SelectedPlayer2Class_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UFighting_GameGameInstance_Statics::NewProp_SelectablePlayers_Inner = { "SelectablePlayers", nullptr, (EPropertyFlags)0x0004000000000000, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UClass, Z_Construct_UClass_AASPCharacter_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UFighting_GameGameInstance_Statics::NewProp_SelectablePlayers = { "SelectablePlayers", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UFighting_GameGameInstance, SelectablePlayers), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectablePlayers_MetaData), NewProp_SelectablePlayers_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UFighting_GameGameInstance_Statics::NewProp_DefaultMappingContext_Player1 = { "DefaultMappingContext_Player1", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UFighting_GameGameInstance, DefaultMappingContext_Player1), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultMappingContext_Player1_MetaData), NewProp_DefaultMappingContext_Player1_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UFighting_GameGameInstance_Statics::NewProp_DefaultMappingContext_Player2 = { "DefaultMappingContext_Player2", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UFighting_GameGameInstance, DefaultMappingContext_Player2), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultMappingContext_Player2_MetaData), NewProp_DefaultMappingContext_Player2_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UFighting_GameGameInstance_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFighting_GameGameInstance_Statics::NewProp_SelectedPlayer1Class,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFighting_GameGameInstance_Statics::NewProp_SelectedPlayer2Class,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFighting_GameGameInstance_Statics::NewProp_SelectablePlayers_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFighting_GameGameInstance_Statics::NewProp_SelectablePlayers,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFighting_GameGameInstance_Statics::NewProp_DefaultMappingContext_Player1,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFighting_GameGameInstance_Statics::NewProp_DefaultMappingContext_Player2,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UFighting_GameGameInstance_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UFighting_GameGameInstance_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstance,
	(UObject* (*)())Z_Construct_UPackage__Script_ASP,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UFighting_GameGameInstance_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UFighting_GameGameInstance_Statics::ClassParams = {
	&UFighting_GameGameInstance::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UFighting_GameGameInstance_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UFighting_GameGameInstance_Statics::PropPointers),
	0,
	0x009000A8u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UFighting_GameGameInstance_Statics::Class_MetaDataParams), Z_Construct_UClass_UFighting_GameGameInstance_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UFighting_GameGameInstance()
{
	if (!Z_Registration_Info_UClass_UFighting_GameGameInstance.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UFighting_GameGameInstance.OuterSingleton, Z_Construct_UClass_UFighting_GameGameInstance_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UFighting_GameGameInstance.OuterSingleton;
}
template<> ASP_API UClass* StaticClass<UFighting_GameGameInstance>()
{
	return UFighting_GameGameInstance::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UFighting_GameGameInstance);
UFighting_GameGameInstance::~UFighting_GameGameInstance() {}
// End Class UFighting_GameGameInstance

// Begin Registration
struct Z_CompiledInDeferFile_FID_ASP_Source_ASP_UFighting_GameGameInstance_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UFighting_GameGameInstance, UFighting_GameGameInstance::StaticClass, TEXT("UFighting_GameGameInstance"), &Z_Registration_Info_UClass_UFighting_GameGameInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UFighting_GameGameInstance), 1990569669U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ASP_Source_ASP_UFighting_GameGameInstance_h_2524888549(TEXT("/Script/ASP"),
	Z_CompiledInDeferFile_FID_ASP_Source_ASP_UFighting_GameGameInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ASP_Source_ASP_UFighting_GameGameInstance_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
