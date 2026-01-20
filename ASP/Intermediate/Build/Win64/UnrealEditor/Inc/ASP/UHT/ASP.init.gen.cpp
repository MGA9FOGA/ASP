// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeASP_init() {}
	ASP_API UFunction* Z_Construct_UDelegateFunction_ASP_OnCustomHit__DelegateSignature();
	ASP_API UFunction* Z_Construct_UDelegateFunction_ASP_OnCustomOverlap__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_ASP;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_ASP()
	{
		if (!Z_Registration_Info_UPackage__Script_ASP.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_ASP_OnCustomHit__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_ASP_OnCustomOverlap__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/ASP",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x79C36639,
				0x6C53AC83,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_ASP.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_ASP.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_ASP(Z_Construct_UPackage__Script_ASP, TEXT("/Script/ASP"), Z_Registration_Info_UPackage__Script_ASP, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x79C36639, 0x6C53AC83));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
