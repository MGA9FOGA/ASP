// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ASP/ASPGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeASPGameMode() {}

// Begin Cross Module References
ASP_API UClass* Z_Construct_UClass_AASPGameMode();
ASP_API UClass* Z_Construct_UClass_AASPGameMode_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
UPackage* Z_Construct_UPackage__Script_ASP();
// End Cross Module References

// Begin Class AASPGameMode
void AASPGameMode::StaticRegisterNativesAASPGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AASPGameMode);
UClass* Z_Construct_UClass_AASPGameMode_NoRegister()
{
	return AASPGameMode::StaticClass();
}
struct Z_Construct_UClass_AASPGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "ASPGameMode.h" },
		{ "ModuleRelativePath", "ASPGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AASPGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AASPGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_ASP,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AASPGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AASPGameMode_Statics::ClassParams = {
	&AASPGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008802ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AASPGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AASPGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AASPGameMode()
{
	if (!Z_Registration_Info_UClass_AASPGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AASPGameMode.OuterSingleton, Z_Construct_UClass_AASPGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AASPGameMode.OuterSingleton;
}
template<> ASP_API UClass* StaticClass<AASPGameMode>()
{
	return AASPGameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AASPGameMode);
AASPGameMode::~AASPGameMode() {}
// End Class AASPGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_ASP_Source_ASP_ASPGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AASPGameMode, AASPGameMode::StaticClass, TEXT("AASPGameMode"), &Z_Registration_Info_UClass_AASPGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AASPGameMode), 3591360466U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ASP_Source_ASP_ASPGameMode_h_262096979(TEXT("/Script/ASP"),
	Z_CompiledInDeferFile_FID_ASP_Source_ASP_ASPGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ASP_Source_ASP_ASPGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
