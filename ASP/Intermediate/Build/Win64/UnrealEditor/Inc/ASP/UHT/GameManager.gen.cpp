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
ASP_API UClass* Z_Construct_UClass_UGameManager();
ASP_API UClass* Z_Construct_UClass_UGameManager_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
UPackage* Z_Construct_UPackage__Script_ASP();
// End Cross Module References

// Begin Class UGameManager Function FixedGameUpdate60Hz
struct Z_Construct_UFunction_UGameManager_FixedGameUpdate60Hz_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "GameManager.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameManager_FixedGameUpdate60Hz_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameManager, nullptr, "FixedGameUpdate60Hz", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameManager_FixedGameUpdate60Hz_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGameManager_FixedGameUpdate60Hz_Statics::Function_MetaDataParams) };
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
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->FixedGameUpdate60Hz();
	P_NATIVE_END;
}
// End Class UGameManager Function FixedGameUpdate60Hz

// Begin Class UGameManager
void UGameManager::StaticRegisterNativesUGameManager()
{
	UClass* Class = UGameManager::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "FixedGameUpdate60Hz", &UGameManager::execFixedGameUpdate60Hz },
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
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UGameManager_FixedGameUpdate60Hz, "FixedGameUpdate60Hz" }, // 1059671128
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGameManager>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
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
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
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
UGameManager::UGameManager() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UGameManager);
UGameManager::~UGameManager() {}
// End Class UGameManager

// Begin Registration
struct Z_CompiledInDeferFile_FID_ASP_Source_ASP_GameManager_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UGameManager, UGameManager::StaticClass, TEXT("UGameManager"), &Z_Registration_Info_UClass_UGameManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGameManager), 2677201559U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ASP_Source_ASP_GameManager_h_3755438925(TEXT("/Script/ASP"),
	Z_CompiledInDeferFile_FID_ASP_Source_ASP_GameManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ASP_Source_ASP_GameManager_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
