// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ASP/DynamicCamera.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDynamicCamera() {}

// Begin Cross Module References
ASP_API UClass* Z_Construct_UClass_ADynamicCamera();
ASP_API UClass* Z_Construct_UClass_ADynamicCamera_NoRegister();
ASP_API UClass* Z_Construct_UClass_UGameManager_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_ASP();
// End Cross Module References

// Begin Class ADynamicCamera
void ADynamicCamera::StaticRegisterNativesADynamicCamera()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ADynamicCamera);
UClass* Z_Construct_UClass_ADynamicCamera_NoRegister()
{
	return ADynamicCamera::StaticClass();
}
struct Z_Construct_UClass_ADynamicCamera_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "DynamicCamera.h" },
		{ "ModuleRelativePath", "DynamicCamera.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_gameManager_MetaData[] = {
		{ "ModuleRelativePath", "DynamicCamera.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_minDistance_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "DynamicCamera" },
		{ "ModuleRelativePath", "DynamicCamera.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_maxDistance_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "DynamicCamera" },
		{ "ModuleRelativePath", "DynamicCamera.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_height_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "DynamicCamera" },
		{ "ModuleRelativePath", "DynamicCamera.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_cameraSmooth_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "DynamicCamera" },
		{ "ModuleRelativePath", "DynamicCamera.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_maxPlayerPositionDifference_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "DynamicCamera" },
		{ "ModuleRelativePath", "DynamicCamera.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_camera_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "DynamicCamera.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_m_gameManager;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_m_minDistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_m_maxDistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_m_height;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_m_cameraSmooth;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_m_maxPlayerPositionDifference;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_m_camera;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADynamicCamera>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADynamicCamera_Statics::NewProp_m_gameManager = { "m_gameManager", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADynamicCamera, m_gameManager), Z_Construct_UClass_UGameManager_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_gameManager_MetaData), NewProp_m_gameManager_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ADynamicCamera_Statics::NewProp_m_minDistance = { "m_minDistance", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADynamicCamera, m_minDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_minDistance_MetaData), NewProp_m_minDistance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ADynamicCamera_Statics::NewProp_m_maxDistance = { "m_maxDistance", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADynamicCamera, m_maxDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_maxDistance_MetaData), NewProp_m_maxDistance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ADynamicCamera_Statics::NewProp_m_height = { "m_height", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADynamicCamera, m_height), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_height_MetaData), NewProp_m_height_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ADynamicCamera_Statics::NewProp_m_cameraSmooth = { "m_cameraSmooth", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADynamicCamera, m_cameraSmooth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_cameraSmooth_MetaData), NewProp_m_cameraSmooth_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ADynamicCamera_Statics::NewProp_m_maxPlayerPositionDifference = { "m_maxPlayerPositionDifference", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADynamicCamera, m_maxPlayerPositionDifference), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_maxPlayerPositionDifference_MetaData), NewProp_m_maxPlayerPositionDifference_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADynamicCamera_Statics::NewProp_m_camera = { "m_camera", nullptr, (EPropertyFlags)0x01440000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADynamicCamera, m_camera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_camera_MetaData), NewProp_m_camera_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ADynamicCamera_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADynamicCamera_Statics::NewProp_m_gameManager,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADynamicCamera_Statics::NewProp_m_minDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADynamicCamera_Statics::NewProp_m_maxDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADynamicCamera_Statics::NewProp_m_height,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADynamicCamera_Statics::NewProp_m_cameraSmooth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADynamicCamera_Statics::NewProp_m_maxPlayerPositionDifference,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADynamicCamera_Statics::NewProp_m_camera,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ADynamicCamera_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ADynamicCamera_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_ASP,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ADynamicCamera_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ADynamicCamera_Statics::ClassParams = {
	&ADynamicCamera::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ADynamicCamera_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ADynamicCamera_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ADynamicCamera_Statics::Class_MetaDataParams), Z_Construct_UClass_ADynamicCamera_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ADynamicCamera()
{
	if (!Z_Registration_Info_UClass_ADynamicCamera.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADynamicCamera.OuterSingleton, Z_Construct_UClass_ADynamicCamera_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ADynamicCamera.OuterSingleton;
}
template<> ASP_API UClass* StaticClass<ADynamicCamera>()
{
	return ADynamicCamera::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ADynamicCamera);
ADynamicCamera::~ADynamicCamera() {}
// End Class ADynamicCamera

// Begin Registration
struct Z_CompiledInDeferFile_FID_ASP_Source_ASP_DynamicCamera_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ADynamicCamera, ADynamicCamera::StaticClass, TEXT("ADynamicCamera"), &Z_Registration_Info_UClass_ADynamicCamera, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADynamicCamera), 2884095504U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ASP_Source_ASP_DynamicCamera_h_2283300476(TEXT("/Script/ASP"),
	Z_CompiledInDeferFile_FID_ASP_Source_ASP_DynamicCamera_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ASP_Source_ASP_DynamicCamera_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
