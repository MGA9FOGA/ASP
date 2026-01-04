// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ASP/GameManager.h"
#include "Runtime/Engine/Classes/Engine/GameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameManager() {}

// Begin Cross Module References
ASP_API UClass* Z_Construct_UClass_AASPCharacter_NoRegister();
ASP_API UClass* Z_Construct_UClass_ADynamicCamera_NoRegister();
ASP_API UClass* Z_Construct_UClass_AFightingGame_PlayerController_NoRegister();
ASP_API UClass* Z_Construct_UClass_UGameManager();
ASP_API UClass* Z_Construct_UClass_UGameManager_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
UPackage* Z_Construct_UPackage__Script_ASP();
// End Cross Module References

// Begin Class UGameManager
void UGameManager::StaticRegisterNativesUGameManager()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UGameManager);
UClass* Z_Construct_UClass_UGameManager_NoRegister()
{
	return UGameManager::StaticClass();
}
struct Z_Construct_UClass_UGameManager_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* =============================\n * === GAME MANAGER ===\n * ============================= */" },
#endif
		{ "IncludePath", "GameManager.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "GameManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* === GAME MANAGER ===\n* =============================" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_playerController1_MetaData[] = {
		{ "Category", "GameManager" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// =============================\n// Players\n// =============================\n" },
#endif
		{ "ModuleRelativePath", "GameManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Players" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_playerController2_MetaData[] = {
		{ "Category", "GameManager" },
		{ "ModuleRelativePath", "GameManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_player1_MetaData[] = {
		{ "Category", "GameManager" },
		{ "ModuleRelativePath", "GameManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_player2_MetaData[] = {
		{ "Category", "GameManager" },
		{ "ModuleRelativePath", "GameManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_camera_MetaData[] = {
		{ "Category", "GameManager" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* =============================\n\x09 * === Camera ===\n\x09 * ============================= */" },
#endif
		{ "ModuleRelativePath", "GameManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* === Camera ===\n* =============================" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_m_playerController1;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_m_playerController2;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_m_player1;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_m_player2;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_m_camera;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGameManager>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGameManager_Statics::NewProp_m_playerController1 = { "m_playerController1", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGameManager, m_playerController1), Z_Construct_UClass_AFightingGame_PlayerController_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_playerController1_MetaData), NewProp_m_playerController1_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGameManager_Statics::NewProp_m_playerController2 = { "m_playerController2", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGameManager, m_playerController2), Z_Construct_UClass_AFightingGame_PlayerController_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_playerController2_MetaData), NewProp_m_playerController2_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGameManager_Statics::NewProp_m_player1 = { "m_player1", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGameManager, m_player1), Z_Construct_UClass_AASPCharacter_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_player1_MetaData), NewProp_m_player1_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGameManager_Statics::NewProp_m_player2 = { "m_player2", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGameManager, m_player2), Z_Construct_UClass_AASPCharacter_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_player2_MetaData), NewProp_m_player2_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGameManager_Statics::NewProp_m_camera = { "m_camera", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGameManager, m_camera), Z_Construct_UClass_ADynamicCamera_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_camera_MetaData), NewProp_m_camera_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGameManager_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameManager_Statics::NewProp_m_playerController1,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameManager_Statics::NewProp_m_playerController2,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameManager_Statics::NewProp_m_player1,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameManager_Statics::NewProp_m_player2,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameManager_Statics::NewProp_m_camera,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGameManager_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UGameManager_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_ASP,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGameManager_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UGameManager_Statics::ClassParams = {
	&UGameManager::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UGameManager_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UGameManager_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGameManager_Statics::Class_MetaDataParams), Z_Construct_UClass_UGameManager_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UGameManager()
{
	if (!Z_Registration_Info_UClass_UGameManager.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGameManager.OuterSingleton, Z_Construct_UClass_UGameManager_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UGameManager.OuterSingleton;
}
template<> ASP_API UClass* StaticClass<UGameManager>()
{
	return UGameManager::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UGameManager);
UGameManager::~UGameManager() {}
// End Class UGameManager

// Begin Registration
struct Z_CompiledInDeferFile_FID_ASP_Source_ASP_GameManager_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UGameManager, UGameManager::StaticClass, TEXT("UGameManager"), &Z_Registration_Info_UClass_UGameManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGameManager), 1790776216U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ASP_Source_ASP_GameManager_h_742254564(TEXT("/Script/ASP"),
	Z_CompiledInDeferFile_FID_ASP_Source_ASP_GameManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ASP_Source_ASP_GameManager_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
