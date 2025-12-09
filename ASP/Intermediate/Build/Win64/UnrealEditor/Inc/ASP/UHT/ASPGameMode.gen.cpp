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
ASP_API UClass* Z_Construct_UClass_AASPCharacter_NoRegister();
ASP_API UClass* Z_Construct_UClass_AASPGameMode();
ASP_API UClass* Z_Construct_UClass_AASPGameMode_NoRegister();
ASP_API UClass* Z_Construct_UClass_AFightingGame_PlayerController_NoRegister();
ASP_API UClass* Z_Construct_UClass_UGameManager_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_player1_MetaData[] = {
		{ "Category", "ASPGameMode" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Player 1\n" },
#endif
		{ "ModuleRelativePath", "ASPGameMode.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Player 1" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_playerController1_MetaData[] = {
		{ "Category", "ASPGameMode" },
		{ "ModuleRelativePath", "ASPGameMode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_characterClass1_MetaData[] = {
		{ "Category", "ASPGameMode" },
		{ "ModuleRelativePath", "ASPGameMode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ControllerClass_MetaData[] = {
		{ "Category", "ASPGameMode" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Player 2\n" },
#endif
		{ "ModuleRelativePath", "ASPGameMode.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Player 2" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_player2_MetaData[] = {
		{ "Category", "ASPGameMode" },
		{ "ModuleRelativePath", "ASPGameMode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_playerController2_MetaData[] = {
		{ "Category", "ASPGameMode" },
		{ "ModuleRelativePath", "ASPGameMode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_characterClass2_MetaData[] = {
		{ "Category", "ASPGameMode" },
		{ "ModuleRelativePath", "ASPGameMode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_gameManager_MetaData[] = {
		{ "Category", "ASPGameMode" },
		{ "ModuleRelativePath", "ASPGameMode.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_m_player1;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_m_playerController1;
	static const UECodeGen_Private::FClassPropertyParams NewProp_m_characterClass1;
	static const UECodeGen_Private::FClassPropertyParams NewProp_ControllerClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_m_player2;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_m_playerController2;
	static const UECodeGen_Private::FClassPropertyParams NewProp_m_characterClass2;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_m_gameManager;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AASPGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AASPGameMode_Statics::NewProp_m_player1 = { "m_player1", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AASPGameMode, m_player1), Z_Construct_UClass_AASPCharacter_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_player1_MetaData), NewProp_m_player1_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AASPGameMode_Statics::NewProp_m_playerController1 = { "m_playerController1", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AASPGameMode, m_playerController1), Z_Construct_UClass_AFightingGame_PlayerController_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_playerController1_MetaData), NewProp_m_playerController1_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AASPGameMode_Statics::NewProp_m_characterClass1 = { "m_characterClass1", nullptr, (EPropertyFlags)0x0044000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AASPGameMode, m_characterClass1), Z_Construct_UClass_UClass, Z_Construct_UClass_AASPCharacter_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_characterClass1_MetaData), NewProp_m_characterClass1_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AASPGameMode_Statics::NewProp_ControllerClass = { "ControllerClass", nullptr, (EPropertyFlags)0x0044000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AASPGameMode, ControllerClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AFightingGame_PlayerController_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ControllerClass_MetaData), NewProp_ControllerClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AASPGameMode_Statics::NewProp_m_player2 = { "m_player2", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AASPGameMode, m_player2), Z_Construct_UClass_AASPCharacter_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_player2_MetaData), NewProp_m_player2_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AASPGameMode_Statics::NewProp_m_playerController2 = { "m_playerController2", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AASPGameMode, m_playerController2), Z_Construct_UClass_AFightingGame_PlayerController_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_playerController2_MetaData), NewProp_m_playerController2_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AASPGameMode_Statics::NewProp_m_characterClass2 = { "m_characterClass2", nullptr, (EPropertyFlags)0x0044000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AASPGameMode, m_characterClass2), Z_Construct_UClass_UClass, Z_Construct_UClass_AASPCharacter_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_characterClass2_MetaData), NewProp_m_characterClass2_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AASPGameMode_Statics::NewProp_m_gameManager = { "m_gameManager", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AASPGameMode, m_gameManager), Z_Construct_UClass_UGameManager_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_gameManager_MetaData), NewProp_m_gameManager_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AASPGameMode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AASPGameMode_Statics::NewProp_m_player1,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AASPGameMode_Statics::NewProp_m_playerController1,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AASPGameMode_Statics::NewProp_m_characterClass1,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AASPGameMode_Statics::NewProp_ControllerClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AASPGameMode_Statics::NewProp_m_player2,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AASPGameMode_Statics::NewProp_m_playerController2,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AASPGameMode_Statics::NewProp_m_characterClass2,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AASPGameMode_Statics::NewProp_m_gameManager,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AASPGameMode_Statics::PropPointers) < 2048);
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
	Z_Construct_UClass_AASPGameMode_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AASPGameMode_Statics::PropPointers),
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
		{ Z_Construct_UClass_AASPGameMode, AASPGameMode::StaticClass, TEXT("AASPGameMode"), &Z_Registration_Info_UClass_AASPGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AASPGameMode), 2974150368U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ASP_Source_ASP_ASPGameMode_h_3042671409(TEXT("/Script/ASP"),
	Z_CompiledInDeferFile_FID_ASP_Source_ASP_ASPGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ASP_Source_ASP_ASPGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
