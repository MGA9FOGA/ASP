// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ASP/FightingGame_PlayerController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFightingGame_PlayerController() {}

// Begin Cross Module References
ASP_API UClass* Z_Construct_UClass_AFightingGame_PlayerController();
ASP_API UClass* Z_Construct_UClass_AFightingGame_PlayerController_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APlayerController();
UPackage* Z_Construct_UPackage__Script_ASP();
// End Cross Module References

// Begin Class AFightingGame_PlayerController
void AFightingGame_PlayerController::StaticRegisterNativesAFightingGame_PlayerController()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AFightingGame_PlayerController);
UClass* Z_Construct_UClass_AFightingGame_PlayerController_NoRegister()
{
	return AFightingGame_PlayerController::StaticClass();
}
struct Z_Construct_UClass_AFightingGame_PlayerController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "FightingGame_PlayerController.h" },
		{ "ModuleRelativePath", "FightingGame_PlayerController.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFightingGame_PlayerController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AFightingGame_PlayerController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerController,
	(UObject* (*)())Z_Construct_UPackage__Script_ASP,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFightingGame_PlayerController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AFightingGame_PlayerController_Statics::ClassParams = {
	&AFightingGame_PlayerController::StaticClass,
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
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFightingGame_PlayerController_Statics::Class_MetaDataParams), Z_Construct_UClass_AFightingGame_PlayerController_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AFightingGame_PlayerController()
{
	if (!Z_Registration_Info_UClass_AFightingGame_PlayerController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AFightingGame_PlayerController.OuterSingleton, Z_Construct_UClass_AFightingGame_PlayerController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AFightingGame_PlayerController.OuterSingleton;
}
template<> ASP_API UClass* StaticClass<AFightingGame_PlayerController>()
{
	return AFightingGame_PlayerController::StaticClass();
}
AFightingGame_PlayerController::AFightingGame_PlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(AFightingGame_PlayerController);
AFightingGame_PlayerController::~AFightingGame_PlayerController() {}
// End Class AFightingGame_PlayerController

// Begin Registration
struct Z_CompiledInDeferFile_FID_ASP_Source_ASP_FightingGame_PlayerController_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AFightingGame_PlayerController, AFightingGame_PlayerController::StaticClass, TEXT("AFightingGame_PlayerController"), &Z_Registration_Info_UClass_AFightingGame_PlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AFightingGame_PlayerController), 3522971104U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ASP_Source_ASP_FightingGame_PlayerController_h_1445390638(TEXT("/Script/ASP"),
	Z_CompiledInDeferFile_FID_ASP_Source_ASP_FightingGame_PlayerController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ASP_Source_ASP_FightingGame_PlayerController_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
