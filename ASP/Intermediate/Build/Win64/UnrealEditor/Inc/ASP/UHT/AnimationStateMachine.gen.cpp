// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ASP/AnimationStateMachine.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAnimationStateMachine() {}

// Begin Cross Module References
ASP_API UScriptStruct* Z_Construct_UScriptStruct_FAnimationMontageState();
ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
UPackage* Z_Construct_UPackage__Script_ASP();
// End Cross Module References

// Begin ScriptStruct FAnimationMontageState
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_AnimationMontageState;
class UScriptStruct* FAnimationMontageState::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_AnimationMontageState.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_AnimationMontageState.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAnimationMontageState, (UObject*)Z_Construct_UPackage__Script_ASP(), TEXT("AnimationMontageState"));
	}
	return Z_Registration_Info_UScriptStruct_AnimationMontageState.OuterSingleton;
}
template<> ASP_API UScriptStruct* StaticStruct<FAnimationMontageState>()
{
	return FAnimationMontageState::StaticStruct();
}
struct Z_Construct_UScriptStruct_FAnimationMontageState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "AnimationStateMachine.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Montage_MetaData[] = {
		{ "Category", "Animation" },
		{ "ModuleRelativePath", "AnimationStateMachine.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MontageName_MetaData[] = {
		{ "Category", "Animation" },
		{ "ModuleRelativePath", "AnimationStateMachine.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Time_MetaData[] = {
		{ "Category", "Animation" },
		{ "ModuleRelativePath", "AnimationStateMachine.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Duration_MetaData[] = {
		{ "Category", "Animation" },
		{ "ModuleRelativePath", "AnimationStateMachine.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsPlaying_MetaData[] = {
		{ "Category", "Animation" },
		{ "ModuleRelativePath", "AnimationStateMachine.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Montage;
	static const UECodeGen_Private::FNamePropertyParams NewProp_MontageName;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Time;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Duration;
	static void NewProp_bIsPlaying_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsPlaying;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAnimationMontageState>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FAnimationMontageState_Statics::NewProp_Montage = { "Montage", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimationMontageState, Montage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Montage_MetaData), NewProp_Montage_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FAnimationMontageState_Statics::NewProp_MontageName = { "MontageName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimationMontageState, MontageName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MontageName_MetaData), NewProp_MontageName_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimationMontageState_Statics::NewProp_Time = { "Time", nullptr, (EPropertyFlags)0x0010000000020005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimationMontageState, Time), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Time_MetaData), NewProp_Time_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimationMontageState_Statics::NewProp_Duration = { "Duration", nullptr, (EPropertyFlags)0x0010000000020005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimationMontageState, Duration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Duration_MetaData), NewProp_Duration_MetaData) };
void Z_Construct_UScriptStruct_FAnimationMontageState_Statics::NewProp_bIsPlaying_SetBit(void* Obj)
{
	((FAnimationMontageState*)Obj)->bIsPlaying = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimationMontageState_Statics::NewProp_bIsPlaying = { "bIsPlaying", nullptr, (EPropertyFlags)0x0010000000020005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimationMontageState), &Z_Construct_UScriptStruct_FAnimationMontageState_Statics::NewProp_bIsPlaying_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsPlaying_MetaData), NewProp_bIsPlaying_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAnimationMontageState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimationMontageState_Statics::NewProp_Montage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimationMontageState_Statics::NewProp_MontageName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimationMontageState_Statics::NewProp_Time,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimationMontageState_Statics::NewProp_Duration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimationMontageState_Statics::NewProp_bIsPlaying,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimationMontageState_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAnimationMontageState_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ASP,
	nullptr,
	&NewStructOps,
	"AnimationMontageState",
	Z_Construct_UScriptStruct_FAnimationMontageState_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimationMontageState_Statics::PropPointers),
	sizeof(FAnimationMontageState),
	alignof(FAnimationMontageState),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimationMontageState_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FAnimationMontageState_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FAnimationMontageState()
{
	if (!Z_Registration_Info_UScriptStruct_AnimationMontageState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_AnimationMontageState.InnerSingleton, Z_Construct_UScriptStruct_FAnimationMontageState_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_AnimationMontageState.InnerSingleton;
}
// End ScriptStruct FAnimationMontageState

// Begin Registration
struct Z_CompiledInDeferFile_FID_ASP_Source_ASP_AnimationStateMachine_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FAnimationMontageState::StaticStruct, Z_Construct_UScriptStruct_FAnimationMontageState_Statics::NewStructOps, TEXT("AnimationMontageState"), &Z_Registration_Info_UScriptStruct_AnimationMontageState, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAnimationMontageState), 3307000831U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ASP_Source_ASP_AnimationStateMachine_h_593508065(TEXT("/Script/ASP"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_ASP_Source_ASP_AnimationStateMachine_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ASP_Source_ASP_AnimationStateMachine_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
