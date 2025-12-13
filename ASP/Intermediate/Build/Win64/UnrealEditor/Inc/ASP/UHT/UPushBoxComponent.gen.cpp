// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ASP/UPushBoxComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUPushBoxComponent() {}

// Begin Cross Module References
ASP_API UClass* Z_Construct_UClass_UPushBoxComponent();
ASP_API UClass* Z_Construct_UClass_UPushBoxComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UBoxComponent();
UPackage* Z_Construct_UPackage__Script_ASP();
// End Cross Module References

// Begin Class UPushBoxComponent
void UPushBoxComponent::StaticRegisterNativesUPushBoxComponent()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPushBoxComponent);
UClass* Z_Construct_UClass_UPushBoxComponent_NoRegister()
{
	return UPushBoxComponent::StaticClass();
}
struct Z_Construct_UClass_UPushBoxComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "HideCategories", "Object LOD Lighting TextureStreaming Object LOD Lighting TextureStreaming Activation Components|Activation Trigger VirtualTexture" },
		{ "IncludePath", "UPushBoxComponent.h" },
		{ "ModuleRelativePath", "UPushBoxComponent.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPushBoxComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UPushBoxComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBoxComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_ASP,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPushBoxComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UPushBoxComponent_Statics::ClassParams = {
	&UPushBoxComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x00B010A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPushBoxComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UPushBoxComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UPushBoxComponent()
{
	if (!Z_Registration_Info_UClass_UPushBoxComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPushBoxComponent.OuterSingleton, Z_Construct_UClass_UPushBoxComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UPushBoxComponent.OuterSingleton;
}
template<> ASP_API UClass* StaticClass<UPushBoxComponent>()
{
	return UPushBoxComponent::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UPushBoxComponent);
UPushBoxComponent::~UPushBoxComponent() {}
// End Class UPushBoxComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_ASP_Source_ASP_UPushBoxComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UPushBoxComponent, UPushBoxComponent::StaticClass, TEXT("UPushBoxComponent"), &Z_Registration_Info_UClass_UPushBoxComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPushBoxComponent), 2219107547U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ASP_Source_ASP_UPushBoxComponent_h_2326218276(TEXT("/Script/ASP"),
	Z_CompiledInDeferFile_FID_ASP_Source_ASP_UPushBoxComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ASP_Source_ASP_UPushBoxComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
