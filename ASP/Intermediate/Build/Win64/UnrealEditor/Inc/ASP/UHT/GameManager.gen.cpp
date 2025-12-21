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
ASP_API UClass* Z_Construct_UClass_UMoveableInterface_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
UPackage* Z_Construct_UPackage__Script_ASP();
// End Cross Module References

// Begin Class UGameManager Function FixedGameUpdate60Hz
struct Z_Construct_UFunction_UGameManager_FixedGameUpdate60Hz_Statics
{
	struct GameManager_eventFixedGameUpdate60Hz_Parms
	{
		double _fixedDeltatime;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Fixed Update\n" },
#endif
		{ "ModuleRelativePath", "GameManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fixed Update" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FDoublePropertyParams NewProp__fixedDeltatime;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UFunction_UGameManager_FixedGameUpdate60Hz_Statics::NewProp__fixedDeltatime = { "_fixedDeltatime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameManager_eventFixedGameUpdate60Hz_Parms, _fixedDeltatime), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGameManager_FixedGameUpdate60Hz_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameManager_FixedGameUpdate60Hz_Statics::NewProp__fixedDeltatime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameManager_FixedGameUpdate60Hz_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameManager_FixedGameUpdate60Hz_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameManager, nullptr, "FixedGameUpdate60Hz", nullptr, nullptr, Z_Construct_UFunction_UGameManager_FixedGameUpdate60Hz_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameManager_FixedGameUpdate60Hz_Statics::PropPointers), sizeof(Z_Construct_UFunction_UGameManager_FixedGameUpdate60Hz_Statics::GameManager_eventFixedGameUpdate60Hz_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameManager_FixedGameUpdate60Hz_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGameManager_FixedGameUpdate60Hz_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UGameManager_FixedGameUpdate60Hz_Statics::GameManager_eventFixedGameUpdate60Hz_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGameManager_FixedGameUpdate60Hz()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGameManager_FixedGameUpdate60Hz_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGameManager::execFixedGameUpdate60Hz)
{
	P_GET_PROPERTY(FDoubleProperty,Z_Param__fixedDeltatime);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->FixedGameUpdate60Hz(Z_Param__fixedDeltatime);
	P_NATIVE_END;
}
// End Class UGameManager Function FixedGameUpdate60Hz

// Begin Class UGameManager Function RegisterMovable
struct Z_Construct_UFunction_UGameManager_RegisterMovable_Statics
{
	struct GameManager_eventRegisterMovable_Parms
	{
		TScriptInterface<IMoveableInterface> _movable;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Register Player\n" },
#endif
		{ "ModuleRelativePath", "GameManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Register Player" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FInterfacePropertyParams NewProp__movable;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FInterfacePropertyParams Z_Construct_UFunction_UGameManager_RegisterMovable_Statics::NewProp__movable = { "_movable", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Interface, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameManager_eventRegisterMovable_Parms, _movable), Z_Construct_UClass_UMoveableInterface_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGameManager_RegisterMovable_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameManager_RegisterMovable_Statics::NewProp__movable,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameManager_RegisterMovable_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameManager_RegisterMovable_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameManager, nullptr, "RegisterMovable", nullptr, nullptr, Z_Construct_UFunction_UGameManager_RegisterMovable_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameManager_RegisterMovable_Statics::PropPointers), sizeof(Z_Construct_UFunction_UGameManager_RegisterMovable_Statics::GameManager_eventRegisterMovable_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameManager_RegisterMovable_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGameManager_RegisterMovable_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UGameManager_RegisterMovable_Statics::GameManager_eventRegisterMovable_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGameManager_RegisterMovable()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGameManager_RegisterMovable_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGameManager::execRegisterMovable)
{
	P_GET_TINTERFACE(IMoveableInterface,Z_Param__movable);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RegisterMovable(Z_Param__movable);
	P_NATIVE_END;
}
// End Class UGameManager Function RegisterMovable

// Begin Class UGameManager Function RenderUpdate
struct Z_Construct_UFunction_UGameManager_RenderUpdate_Statics
{
	struct GameManager_eventRenderUpdate_Parms
	{
		double _alpha;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "GameManager.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FDoublePropertyParams NewProp__alpha;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UFunction_UGameManager_RenderUpdate_Statics::NewProp__alpha = { "_alpha", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameManager_eventRenderUpdate_Parms, _alpha), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGameManager_RenderUpdate_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameManager_RenderUpdate_Statics::NewProp__alpha,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameManager_RenderUpdate_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameManager_RenderUpdate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameManager, nullptr, "RenderUpdate", nullptr, nullptr, Z_Construct_UFunction_UGameManager_RenderUpdate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameManager_RenderUpdate_Statics::PropPointers), sizeof(Z_Construct_UFunction_UGameManager_RenderUpdate_Statics::GameManager_eventRenderUpdate_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameManager_RenderUpdate_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGameManager_RenderUpdate_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UGameManager_RenderUpdate_Statics::GameManager_eventRenderUpdate_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGameManager_RenderUpdate()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGameManager_RenderUpdate_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGameManager::execRenderUpdate)
{
	P_GET_PROPERTY(FDoubleProperty,Z_Param__alpha);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RenderUpdate(Z_Param__alpha);
	P_NATIVE_END;
}
// End Class UGameManager Function RenderUpdate

// Begin Class UGameManager
void UGameManager::StaticRegisterNativesUGameManager()
{
	UClass* Class = UGameManager::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "FixedGameUpdate60Hz", &UGameManager::execFixedGameUpdate60Hz },
		{ "RegisterMovable", &UGameManager::execRegisterMovable },
		{ "RenderUpdate", &UGameManager::execRenderUpdate },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
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
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "GameManager.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "GameManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_camera_MetaData[] = {
		{ "Category", "GameManager" },
		{ "ModuleRelativePath", "GameManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_playerControllers_MetaData[] = {
		{ "ModuleRelativePath", "GameManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_player1_MetaData[] = {
		{ "Category", "GameManager" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Player1\n" },
#endif
		{ "ModuleRelativePath", "GameManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Player1" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_playerController1_MetaData[] = {
		{ "Category", "GameManager" },
		{ "ModuleRelativePath", "GameManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_player2_MetaData[] = {
		{ "Category", "GameManager" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//UPROPERTY(EditAnywhere)\n//TSubclassOf<AASPCharacter> m_characterClass1;\n//Player2\n" },
#endif
		{ "ModuleRelativePath", "GameManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UPROPERTY(EditAnywhere)\nTSubclassOf<AASPCharacter> m_characterClass1;\nPlayer2" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_playerController2_MetaData[] = {
		{ "Category", "GameManager" },
		{ "ModuleRelativePath", "GameManager.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_m_camera;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_m_playerControllers_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_m_playerControllers;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_m_player1;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_m_playerController1;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_m_player2;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_m_playerController2;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UGameManager_FixedGameUpdate60Hz, "FixedGameUpdate60Hz" }, // 349409440
		{ &Z_Construct_UFunction_UGameManager_RegisterMovable, "RegisterMovable" }, // 2691433291
		{ &Z_Construct_UFunction_UGameManager_RenderUpdate, "RenderUpdate" }, // 3119112165
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGameManager>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGameManager_Statics::NewProp_m_camera = { "m_camera", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGameManager, m_camera), Z_Construct_UClass_ADynamicCamera_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_camera_MetaData), NewProp_m_camera_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGameManager_Statics::NewProp_m_playerControllers_Inner = { "m_playerControllers", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AFightingGame_PlayerController_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UGameManager_Statics::NewProp_m_playerControllers = { "m_playerControllers", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGameManager, m_playerControllers), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_playerControllers_MetaData), NewProp_m_playerControllers_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGameManager_Statics::NewProp_m_player1 = { "m_player1", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGameManager, m_player1), Z_Construct_UClass_AASPCharacter_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_player1_MetaData), NewProp_m_player1_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGameManager_Statics::NewProp_m_playerController1 = { "m_playerController1", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGameManager, m_playerController1), Z_Construct_UClass_AFightingGame_PlayerController_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_playerController1_MetaData), NewProp_m_playerController1_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGameManager_Statics::NewProp_m_player2 = { "m_player2", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGameManager, m_player2), Z_Construct_UClass_AASPCharacter_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_player2_MetaData), NewProp_m_player2_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGameManager_Statics::NewProp_m_playerController2 = { "m_playerController2", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGameManager, m_playerController2), Z_Construct_UClass_AFightingGame_PlayerController_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_playerController2_MetaData), NewProp_m_playerController2_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGameManager_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameManager_Statics::NewProp_m_camera,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameManager_Statics::NewProp_m_playerControllers_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameManager_Statics::NewProp_m_playerControllers,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameManager_Statics::NewProp_m_player1,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameManager_Statics::NewProp_m_playerController1,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameManager_Statics::NewProp_m_player2,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameManager_Statics::NewProp_m_playerController2,
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
	FuncInfo,
	Z_Construct_UClass_UGameManager_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
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
		{ Z_Construct_UClass_UGameManager, UGameManager::StaticClass, TEXT("UGameManager"), &Z_Registration_Info_UClass_UGameManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGameManager), 4167521986U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ASP_Source_ASP_GameManager_h_1286899028(TEXT("/Script/ASP"),
	Z_CompiledInDeferFile_FID_ASP_Source_ASP_GameManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ASP_Source_ASP_GameManager_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
