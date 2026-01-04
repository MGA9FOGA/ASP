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
ASP_API UClass* Z_Construct_UClass_AASPCharacter_NoRegister();
ASP_API UClass* Z_Construct_UClass_AFightingGame_PlayerController();
ASP_API UClass* Z_Construct_UClass_AFightingGame_PlayerController_NoRegister();
ASP_API UClass* Z_Construct_UClass_UGameManager_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APlayerController();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
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
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "FightingGame_PlayerController.h" },
		{ "ModuleRelativePath", "FightingGame_PlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultMappingContext_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "FightingGame_PlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_playerCharacter_MetaData[] = {
		{ "Category", "FightingGame_PlayerController" },
		{ "ModuleRelativePath", "FightingGame_PlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JumpAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// =============================\n// === Jump Input Action ===\n// =============================\n" },
#endif
		{ "ModuleRelativePath", "FightingGame_PlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "=== Jump Input Action ===" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoveAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// =============================\n// === Move Input Action ===\n// =============================\n" },
#endif
		{ "ModuleRelativePath", "FightingGame_PlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "=== Move Input Action ===" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_deadzone_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// =============================\n// === Deadzone ===\n// =============================\n//Controller = 40\n" },
#endif
		{ "ModuleRelativePath", "FightingGame_PlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "=== Deadzone ===\n\nController = 40" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_gameManager_MetaData[] = {
		{ "Category", "FightingGame_PlayerController" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// =============================\n// === GameManager Pointer ===\n// =============================\n" },
#endif
		{ "ModuleRelativePath", "FightingGame_PlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "=== GameManager Pointer ===" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DefaultMappingContext;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_m_playerCharacter;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_JumpAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MoveAction;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_m_deadzone;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_m_gameManager;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFightingGame_PlayerController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFightingGame_PlayerController_Statics::NewProp_DefaultMappingContext = { "DefaultMappingContext", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFightingGame_PlayerController, DefaultMappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultMappingContext_MetaData), NewProp_DefaultMappingContext_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFightingGame_PlayerController_Statics::NewProp_m_playerCharacter = { "m_playerCharacter", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFightingGame_PlayerController, m_playerCharacter), Z_Construct_UClass_AASPCharacter_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_playerCharacter_MetaData), NewProp_m_playerCharacter_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFightingGame_PlayerController_Statics::NewProp_JumpAction = { "JumpAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFightingGame_PlayerController, JumpAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JumpAction_MetaData), NewProp_JumpAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFightingGame_PlayerController_Statics::NewProp_MoveAction = { "MoveAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFightingGame_PlayerController, MoveAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveAction_MetaData), NewProp_MoveAction_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFightingGame_PlayerController_Statics::NewProp_m_deadzone = { "m_deadzone", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFightingGame_PlayerController, m_deadzone), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_deadzone_MetaData), NewProp_m_deadzone_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFightingGame_PlayerController_Statics::NewProp_m_gameManager = { "m_gameManager", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFightingGame_PlayerController, m_gameManager), Z_Construct_UClass_UGameManager_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_gameManager_MetaData), NewProp_m_gameManager_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AFightingGame_PlayerController_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFightingGame_PlayerController_Statics::NewProp_DefaultMappingContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFightingGame_PlayerController_Statics::NewProp_m_playerCharacter,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFightingGame_PlayerController_Statics::NewProp_JumpAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFightingGame_PlayerController_Statics::NewProp_MoveAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFightingGame_PlayerController_Statics::NewProp_m_deadzone,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFightingGame_PlayerController_Statics::NewProp_m_gameManager,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFightingGame_PlayerController_Statics::PropPointers) < 2048);
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
	Z_Construct_UClass_AFightingGame_PlayerController_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AFightingGame_PlayerController_Statics::PropPointers),
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
		{ Z_Construct_UClass_AFightingGame_PlayerController, AFightingGame_PlayerController::StaticClass, TEXT("AFightingGame_PlayerController"), &Z_Registration_Info_UClass_AFightingGame_PlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AFightingGame_PlayerController), 1130847185U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ASP_Source_ASP_FightingGame_PlayerController_h_1006423163(TEXT("/Script/ASP"),
	Z_CompiledInDeferFile_FID_ASP_Source_ASP_FightingGame_PlayerController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ASP_Source_ASP_FightingGame_PlayerController_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
