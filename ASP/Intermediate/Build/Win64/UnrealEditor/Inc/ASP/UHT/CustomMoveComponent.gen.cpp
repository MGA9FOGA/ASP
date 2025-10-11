// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ASP/CustomMoveComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCustomMoveComponent() {}

// Begin Cross Module References
ASP_API UClass* Z_Construct_UClass_UCustomMoveComponent();
ASP_API UClass* Z_Construct_UClass_UCustomMoveComponent_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
UPackage* Z_Construct_UPackage__Script_ASP();
// End Cross Module References

// Begin Class UCustomMoveComponent
void UCustomMoveComponent::StaticRegisterNativesUCustomMoveComponent()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCustomMoveComponent);
UClass* Z_Construct_UClass_UCustomMoveComponent_NoRegister()
{
	return UCustomMoveComponent::StaticClass();
}
struct Z_Construct_UClass_UCustomMoveComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "CustomMoveComponent.h" },
		{ "ModuleRelativePath", "CustomMoveComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Gravity_MetaData[] = {
		{ "Category", "CustomMoveComponent" },
		{ "ModuleRelativePath", "CustomMoveComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Velocity_MetaData[] = {
		{ "Category", "CustomMoveComponent" },
		{ "ModuleRelativePath", "CustomMoveComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Gravity;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Velocity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCustomMoveComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_Gravity = { "Gravity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCustomMoveComponent, Gravity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Gravity_MetaData), NewProp_Gravity_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_Velocity = { "Velocity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCustomMoveComponent, Velocity), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Velocity_MetaData), NewProp_Velocity_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCustomMoveComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_Gravity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_Velocity,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCustomMoveComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UCustomMoveComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_ASP,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCustomMoveComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCustomMoveComponent_Statics::ClassParams = {
	&UCustomMoveComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UCustomMoveComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UCustomMoveComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCustomMoveComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UCustomMoveComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCustomMoveComponent()
{
	if (!Z_Registration_Info_UClass_UCustomMoveComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCustomMoveComponent.OuterSingleton, Z_Construct_UClass_UCustomMoveComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCustomMoveComponent.OuterSingleton;
}
template<> ASP_API UClass* StaticClass<UCustomMoveComponent>()
{
	return UCustomMoveComponent::StaticClass();
}
UCustomMoveComponent::UCustomMoveComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCustomMoveComponent);
UCustomMoveComponent::~UCustomMoveComponent() {}
// End Class UCustomMoveComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_ASP_Source_ASP_CustomMoveComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCustomMoveComponent, UCustomMoveComponent::StaticClass, TEXT("UCustomMoveComponent"), &Z_Registration_Info_UClass_UCustomMoveComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCustomMoveComponent), 499784538U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ASP_Source_ASP_CustomMoveComponent_h_67947953(TEXT("/Script/ASP"),
	Z_CompiledInDeferFile_FID_ASP_Source_ASP_CustomMoveComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ASP_Source_ASP_CustomMoveComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
