// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ASP/MoveableInterface.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMoveableInterface() {}

// Begin Cross Module References
ASP_API UClass* Z_Construct_UClass_UMoveableInterface();
ASP_API UClass* Z_Construct_UClass_UMoveableInterface_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
UPackage* Z_Construct_UPackage__Script_ASP();
// End Cross Module References

// Begin Interface UMoveableInterface
void UMoveableInterface::StaticRegisterNativesUMoveableInterface()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMoveableInterface);
UClass* Z_Construct_UClass_UMoveableInterface_NoRegister()
{
	return UMoveableInterface::StaticClass();
}
struct Z_Construct_UClass_UMoveableInterface_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "MoveableInterface.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IMoveableInterface>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UMoveableInterface_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInterface,
	(UObject* (*)())Z_Construct_UPackage__Script_ASP,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMoveableInterface_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UMoveableInterface_Statics::ClassParams = {
	&UMoveableInterface::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x000040A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMoveableInterface_Statics::Class_MetaDataParams), Z_Construct_UClass_UMoveableInterface_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UMoveableInterface()
{
	if (!Z_Registration_Info_UClass_UMoveableInterface.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMoveableInterface.OuterSingleton, Z_Construct_UClass_UMoveableInterface_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UMoveableInterface.OuterSingleton;
}
template<> ASP_API UClass* StaticClass<UMoveableInterface>()
{
	return UMoveableInterface::StaticClass();
}
UMoveableInterface::UMoveableInterface(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UMoveableInterface);
UMoveableInterface::~UMoveableInterface() {}
// End Interface UMoveableInterface

// Begin Registration
struct Z_CompiledInDeferFile_FID_ASP_Source_ASP_MoveableInterface_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMoveableInterface, UMoveableInterface::StaticClass, TEXT("UMoveableInterface"), &Z_Registration_Info_UClass_UMoveableInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMoveableInterface), 3023271143U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ASP_Source_ASP_MoveableInterface_h_4200229628(TEXT("/Script/ASP"),
	Z_CompiledInDeferFile_FID_ASP_Source_ASP_MoveableInterface_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ASP_Source_ASP_MoveableInterface_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
