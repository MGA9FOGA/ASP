// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ASP/States.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeStates() {}

// Begin Cross Module References
ASP_API UEnum* Z_Construct_UEnum_ASP_EStates();
UPackage* Z_Construct_UPackage__Script_ASP();
// End Cross Module References

// Begin Enum EStates
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EStates;
static UEnum* EStates_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EStates.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EStates.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ASP_EStates, (UObject*)Z_Construct_UPackage__Script_ASP(), TEXT("EStates"));
	}
	return Z_Registration_Info_UEnum_EStates.OuterSingleton;
}
template<> ASP_API UEnum* StaticEnum<EStates>()
{
	return EStates_StaticEnum();
}
struct Z_Construct_UEnum_ASP_EStates_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "ATTACKING.DisplayName", "Attacking" },
		{ "ATTACKING.Name", "EStates::ATTACKING" },
		{ "BlueprintType", "true" },
		{ "CROUCHING.DisplayName", "Crouching" },
		{ "CROUCHING.Name", "EStates::CROUCHING" },
		{ "FALLING.DisplayName", "Falling" },
		{ "FALLING.Name", "EStates::FALLING" },
		{ "HITTED.DisplayName", "Hitted" },
		{ "HITTED.Name", "EStates::HITTED" },
		{ "IDLE.DisplayName", "Idle" },
		{ "IDLE.Name", "EStates::IDLE" },
		{ "JUMPING.DisplayName", "Jumping" },
		{ "JUMPING.Name", "EStates::JUMPING" },
		{ "LANDING.DisplayName", "Landing" },
		{ "LANDING.Name", "EStates::LANDING" },
		{ "ModuleRelativePath", "States.h" },
		{ "MOVING.DisplayName", "Moving" },
		{ "MOVING.Name", "EStates::MOVING" },
		{ "MOVINGBWD.DisplayName", "MovingBackward" },
		{ "MOVINGBWD.Name", "EStates::MOVINGBWD" },
		{ "MOVINGFWD.DisplayName", "MovingForward" },
		{ "MOVINGFWD.Name", "EStates::MOVINGFWD" },
		{ "NONE.DisplayName", "None" },
		{ "NONE.Name", "EStates::NONE" },
		{ "STARTJUMP.DisplayName", "StartJump" },
		{ "STARTJUMP.Name", "EStates::STARTJUMP" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EStates::NONE", (int64)EStates::NONE },
		{ "EStates::IDLE", (int64)EStates::IDLE },
		{ "EStates::MOVING", (int64)EStates::MOVING },
		{ "EStates::MOVINGFWD", (int64)EStates::MOVINGFWD },
		{ "EStates::MOVINGBWD", (int64)EStates::MOVINGBWD },
		{ "EStates::JUMPING", (int64)EStates::JUMPING },
		{ "EStates::STARTJUMP", (int64)EStates::STARTJUMP },
		{ "EStates::FALLING", (int64)EStates::FALLING },
		{ "EStates::LANDING", (int64)EStates::LANDING },
		{ "EStates::ATTACKING", (int64)EStates::ATTACKING },
		{ "EStates::CROUCHING", (int64)EStates::CROUCHING },
		{ "EStates::HITTED", (int64)EStates::HITTED },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ASP_EStates_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_ASP,
	nullptr,
	"EStates",
	"EStates",
	Z_Construct_UEnum_ASP_EStates_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_ASP_EStates_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_ASP_EStates_Statics::Enum_MetaDataParams), Z_Construct_UEnum_ASP_EStates_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_ASP_EStates()
{
	if (!Z_Registration_Info_UEnum_EStates.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EStates.InnerSingleton, Z_Construct_UEnum_ASP_EStates_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EStates.InnerSingleton;
}
// End Enum EStates

// Begin Registration
struct Z_CompiledInDeferFile_FID_ASP_Source_ASP_States_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EStates_StaticEnum, TEXT("EStates"), &Z_Registration_Info_UEnum_EStates, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 4079083287U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ASP_Source_ASP_States_h_3790256865(TEXT("/Script/ASP"),
	nullptr, 0,
	nullptr, 0,
	Z_CompiledInDeferFile_FID_ASP_Source_ASP_States_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ASP_Source_ASP_States_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
