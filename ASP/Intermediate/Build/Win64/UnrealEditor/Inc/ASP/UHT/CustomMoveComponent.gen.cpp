// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ASP/CustomMoveComponent.h"
#include "Runtime/Engine/Classes/Engine/HitResult.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCustomMoveComponent() {}

// Begin Cross Module References
ASP_API UClass* Z_Construct_UClass_ADynamicCamera_NoRegister();
ASP_API UClass* Z_Construct_UClass_UCustomMoveComponent();
ASP_API UClass* Z_Construct_UClass_UCustomMoveComponent_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
ENGINE_API UClass* Z_Construct_UClass_UCapsuleComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
UPackage* Z_Construct_UPackage__Script_ASP();
// End Cross Module References

// Begin Class UCustomMoveComponent Function AddLinetraceIgnore
struct Z_Construct_UFunction_UCustomMoveComponent_AddLinetraceIgnore_Statics
{
	struct CustomMoveComponent_eventAddLinetraceIgnore_Parms
	{
		AActor* _actor;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "CustomMoveComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp__actor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCustomMoveComponent_AddLinetraceIgnore_Statics::NewProp__actor = { "_actor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CustomMoveComponent_eventAddLinetraceIgnore_Parms, _actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCustomMoveComponent_AddLinetraceIgnore_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomMoveComponent_AddLinetraceIgnore_Statics::NewProp__actor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMoveComponent_AddLinetraceIgnore_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCustomMoveComponent_AddLinetraceIgnore_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCustomMoveComponent, nullptr, "AddLinetraceIgnore", nullptr, nullptr, Z_Construct_UFunction_UCustomMoveComponent_AddLinetraceIgnore_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMoveComponent_AddLinetraceIgnore_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCustomMoveComponent_AddLinetraceIgnore_Statics::CustomMoveComponent_eventAddLinetraceIgnore_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMoveComponent_AddLinetraceIgnore_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCustomMoveComponent_AddLinetraceIgnore_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCustomMoveComponent_AddLinetraceIgnore_Statics::CustomMoveComponent_eventAddLinetraceIgnore_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCustomMoveComponent_AddLinetraceIgnore()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCustomMoveComponent_AddLinetraceIgnore_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCustomMoveComponent::execAddLinetraceIgnore)
{
	P_GET_OBJECT(AActor,Z_Param__actor);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AddLinetraceIgnore(Z_Param__actor);
	P_NATIVE_END;
}
// End Class UCustomMoveComponent Function AddLinetraceIgnore

// Begin Class UCustomMoveComponent Function GetBoolOnGround
struct Z_Construct_UFunction_UCustomMoveComponent_GetBoolOnGround_Statics
{
	struct CustomMoveComponent_eventGetBoolOnGround_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Getter / Setter\n" },
#endif
		{ "ModuleRelativePath", "CustomMoveComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Getter / Setter" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UCustomMoveComponent_GetBoolOnGround_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((CustomMoveComponent_eventGetBoolOnGround_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCustomMoveComponent_GetBoolOnGround_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CustomMoveComponent_eventGetBoolOnGround_Parms), &Z_Construct_UFunction_UCustomMoveComponent_GetBoolOnGround_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCustomMoveComponent_GetBoolOnGround_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomMoveComponent_GetBoolOnGround_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMoveComponent_GetBoolOnGround_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCustomMoveComponent_GetBoolOnGround_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCustomMoveComponent, nullptr, "GetBoolOnGround", nullptr, nullptr, Z_Construct_UFunction_UCustomMoveComponent_GetBoolOnGround_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMoveComponent_GetBoolOnGround_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCustomMoveComponent_GetBoolOnGround_Statics::CustomMoveComponent_eventGetBoolOnGround_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMoveComponent_GetBoolOnGround_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCustomMoveComponent_GetBoolOnGround_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCustomMoveComponent_GetBoolOnGround_Statics::CustomMoveComponent_eventGetBoolOnGround_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCustomMoveComponent_GetBoolOnGround()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCustomMoveComponent_GetBoolOnGround_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCustomMoveComponent::execGetBoolOnGround)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->GetBoolOnGround();
	P_NATIVE_END;
}
// End Class UCustomMoveComponent Function GetBoolOnGround

// Begin Class UCustomMoveComponent Function GetHitResultOnGround
struct Z_Construct_UFunction_UCustomMoveComponent_GetHitResultOnGround_Statics
{
	struct CustomMoveComponent_eventGetHitResultOnGround_Parms
	{
		FHitResult ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "CustomMoveComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCustomMoveComponent_GetHitResultOnGround_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010008000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CustomMoveComponent_eventGetHitResultOnGround_Parms, ReturnValue), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(0, nullptr) }; // 4100991306
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCustomMoveComponent_GetHitResultOnGround_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomMoveComponent_GetHitResultOnGround_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMoveComponent_GetHitResultOnGround_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCustomMoveComponent_GetHitResultOnGround_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCustomMoveComponent, nullptr, "GetHitResultOnGround", nullptr, nullptr, Z_Construct_UFunction_UCustomMoveComponent_GetHitResultOnGround_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMoveComponent_GetHitResultOnGround_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCustomMoveComponent_GetHitResultOnGround_Statics::CustomMoveComponent_eventGetHitResultOnGround_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMoveComponent_GetHitResultOnGround_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCustomMoveComponent_GetHitResultOnGround_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCustomMoveComponent_GetHitResultOnGround_Statics::CustomMoveComponent_eventGetHitResultOnGround_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCustomMoveComponent_GetHitResultOnGround()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCustomMoveComponent_GetHitResultOnGround_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCustomMoveComponent::execGetHitResultOnGround)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FHitResult*)Z_Param__Result=P_THIS->GetHitResultOnGround();
	P_NATIVE_END;
}
// End Class UCustomMoveComponent Function GetHitResultOnGround

// Begin Class UCustomMoveComponent Function GetLineTraceOnGroundEnd
struct Z_Construct_UFunction_UCustomMoveComponent_GetLineTraceOnGroundEnd_Statics
{
	struct CustomMoveComponent_eventGetLineTraceOnGroundEnd_Parms
	{
		FVector ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "CustomMoveComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCustomMoveComponent_GetLineTraceOnGroundEnd_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CustomMoveComponent_eventGetLineTraceOnGroundEnd_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCustomMoveComponent_GetLineTraceOnGroundEnd_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomMoveComponent_GetLineTraceOnGroundEnd_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMoveComponent_GetLineTraceOnGroundEnd_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCustomMoveComponent_GetLineTraceOnGroundEnd_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCustomMoveComponent, nullptr, "GetLineTraceOnGroundEnd", nullptr, nullptr, Z_Construct_UFunction_UCustomMoveComponent_GetLineTraceOnGroundEnd_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMoveComponent_GetLineTraceOnGroundEnd_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCustomMoveComponent_GetLineTraceOnGroundEnd_Statics::CustomMoveComponent_eventGetLineTraceOnGroundEnd_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMoveComponent_GetLineTraceOnGroundEnd_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCustomMoveComponent_GetLineTraceOnGroundEnd_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCustomMoveComponent_GetLineTraceOnGroundEnd_Statics::CustomMoveComponent_eventGetLineTraceOnGroundEnd_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCustomMoveComponent_GetLineTraceOnGroundEnd()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCustomMoveComponent_GetLineTraceOnGroundEnd_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCustomMoveComponent::execGetLineTraceOnGroundEnd)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FVector*)Z_Param__Result=P_THIS->GetLineTraceOnGroundEnd();
	P_NATIVE_END;
}
// End Class UCustomMoveComponent Function GetLineTraceOnGroundEnd

// Begin Class UCustomMoveComponent Function GetLineTraceOnGroundStart
struct Z_Construct_UFunction_UCustomMoveComponent_GetLineTraceOnGroundStart_Statics
{
	struct CustomMoveComponent_eventGetLineTraceOnGroundStart_Parms
	{
		FVector ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "CustomMoveComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCustomMoveComponent_GetLineTraceOnGroundStart_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CustomMoveComponent_eventGetLineTraceOnGroundStart_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCustomMoveComponent_GetLineTraceOnGroundStart_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomMoveComponent_GetLineTraceOnGroundStart_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMoveComponent_GetLineTraceOnGroundStart_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCustomMoveComponent_GetLineTraceOnGroundStart_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCustomMoveComponent, nullptr, "GetLineTraceOnGroundStart", nullptr, nullptr, Z_Construct_UFunction_UCustomMoveComponent_GetLineTraceOnGroundStart_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMoveComponent_GetLineTraceOnGroundStart_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCustomMoveComponent_GetLineTraceOnGroundStart_Statics::CustomMoveComponent_eventGetLineTraceOnGroundStart_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMoveComponent_GetLineTraceOnGroundStart_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCustomMoveComponent_GetLineTraceOnGroundStart_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCustomMoveComponent_GetLineTraceOnGroundStart_Statics::CustomMoveComponent_eventGetLineTraceOnGroundStart_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCustomMoveComponent_GetLineTraceOnGroundStart()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCustomMoveComponent_GetLineTraceOnGroundStart_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCustomMoveComponent::execGetLineTraceOnGroundStart)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FVector*)Z_Param__Result=P_THIS->GetLineTraceOnGroundStart();
	P_NATIVE_END;
}
// End Class UCustomMoveComponent Function GetLineTraceOnGroundStart

// Begin Class UCustomMoveComponent Function OnOverlapEnd
struct Z_Construct_UFunction_UCustomMoveComponent_OnOverlapEnd_Statics
{
	struct CustomMoveComponent_eventOnOverlapEnd_Parms
	{
		UPrimitiveComponent* _overlappedComp;
		AActor* _otherActor;
		UPrimitiveComponent* _otherComp;
		int32 _otherBodyIndex;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Collider Hit\n//UPROPERTY(BlueprintAssignable, Category=\"CustomMove|Events\")\n//FOnCustomHit OnCustomHit;\n//UFUNCTION()\n//void OnHit(UPrimitiveComponent* _hitComp, AActor* _otherActor,UPrimitiveComponent* _otherComp, FVector _ormalImpulse, const FHitResult& _hit);\n//\n////Overlap Begin\n//UPROPERTY(BlueprintAssignable)\n//FOnCustomOverlap OnCustomBeginOverlap;\n//UFUNCTION()\n//void OnOverlapBegin(UPrimitiveComponent* _overlappedComp, AActor* _otherActor,UPrimitiveComponent* _otherComp, int32 _otherBodyIndex, bool _bFromSweep, const FHitResult& _sweepResult);\n//\n////Overlap End\n//UPROPERTY(BlueprintAssignable)\n//FOnCustomOverlap OnCustomEndOverlap;\n" },
#endif
		{ "ModuleRelativePath", "CustomMoveComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Collider Hit\nUPROPERTY(BlueprintAssignable, Category=\"CustomMove|Events\")\nFOnCustomHit OnCustomHit;\nUFUNCTION()\nvoid OnHit(UPrimitiveComponent* _hitComp, AActor* _otherActor,UPrimitiveComponent* _otherComp, FVector _ormalImpulse, const FHitResult& _hit);\n\n/Overlap Begin\nUPROPERTY(BlueprintAssignable)\nFOnCustomOverlap OnCustomBeginOverlap;\nUFUNCTION()\nvoid OnOverlapBegin(UPrimitiveComponent* _overlappedComp, AActor* _otherActor,UPrimitiveComponent* _otherComp, int32 _otherBodyIndex, bool _bFromSweep, const FHitResult& _sweepResult);\n\n/Overlap End\nUPROPERTY(BlueprintAssignable)\nFOnCustomOverlap OnCustomEndOverlap;" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__overlappedComp_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__otherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp__overlappedComp;
	static const UECodeGen_Private::FObjectPropertyParams NewProp__otherActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp__otherComp;
	static const UECodeGen_Private::FIntPropertyParams NewProp__otherBodyIndex;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCustomMoveComponent_OnOverlapEnd_Statics::NewProp__overlappedComp = { "_overlappedComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CustomMoveComponent_eventOnOverlapEnd_Parms, _overlappedComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__overlappedComp_MetaData), NewProp__overlappedComp_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCustomMoveComponent_OnOverlapEnd_Statics::NewProp__otherActor = { "_otherActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CustomMoveComponent_eventOnOverlapEnd_Parms, _otherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCustomMoveComponent_OnOverlapEnd_Statics::NewProp__otherComp = { "_otherComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CustomMoveComponent_eventOnOverlapEnd_Parms, _otherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__otherComp_MetaData), NewProp__otherComp_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UCustomMoveComponent_OnOverlapEnd_Statics::NewProp__otherBodyIndex = { "_otherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CustomMoveComponent_eventOnOverlapEnd_Parms, _otherBodyIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCustomMoveComponent_OnOverlapEnd_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomMoveComponent_OnOverlapEnd_Statics::NewProp__overlappedComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomMoveComponent_OnOverlapEnd_Statics::NewProp__otherActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomMoveComponent_OnOverlapEnd_Statics::NewProp__otherComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomMoveComponent_OnOverlapEnd_Statics::NewProp__otherBodyIndex,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMoveComponent_OnOverlapEnd_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCustomMoveComponent_OnOverlapEnd_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCustomMoveComponent, nullptr, "OnOverlapEnd", nullptr, nullptr, Z_Construct_UFunction_UCustomMoveComponent_OnOverlapEnd_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMoveComponent_OnOverlapEnd_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCustomMoveComponent_OnOverlapEnd_Statics::CustomMoveComponent_eventOnOverlapEnd_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMoveComponent_OnOverlapEnd_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCustomMoveComponent_OnOverlapEnd_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCustomMoveComponent_OnOverlapEnd_Statics::CustomMoveComponent_eventOnOverlapEnd_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCustomMoveComponent_OnOverlapEnd()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCustomMoveComponent_OnOverlapEnd_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCustomMoveComponent::execOnOverlapEnd)
{
	P_GET_OBJECT(UPrimitiveComponent,Z_Param__overlappedComp);
	P_GET_OBJECT(AActor,Z_Param__otherActor);
	P_GET_OBJECT(UPrimitiveComponent,Z_Param__otherComp);
	P_GET_PROPERTY(FIntProperty,Z_Param__otherBodyIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnOverlapEnd(Z_Param__overlappedComp,Z_Param__otherActor,Z_Param__otherComp,Z_Param__otherBodyIndex);
	P_NATIVE_END;
}
// End Class UCustomMoveComponent Function OnOverlapEnd

// Begin Class UCustomMoveComponent Function SetBoolOnGround
struct Z_Construct_UFunction_UCustomMoveComponent_SetBoolOnGround_Statics
{
	struct CustomMoveComponent_eventSetBoolOnGround_Parms
	{
		bool _bool;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "CustomMoveComponent.h" },
	};
#endif // WITH_METADATA
	static void NewProp__bool_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp__bool;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UCustomMoveComponent_SetBoolOnGround_Statics::NewProp__bool_SetBit(void* Obj)
{
	((CustomMoveComponent_eventSetBoolOnGround_Parms*)Obj)->_bool = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCustomMoveComponent_SetBoolOnGround_Statics::NewProp__bool = { "_bool", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CustomMoveComponent_eventSetBoolOnGround_Parms), &Z_Construct_UFunction_UCustomMoveComponent_SetBoolOnGround_Statics::NewProp__bool_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCustomMoveComponent_SetBoolOnGround_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomMoveComponent_SetBoolOnGround_Statics::NewProp__bool,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMoveComponent_SetBoolOnGround_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCustomMoveComponent_SetBoolOnGround_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCustomMoveComponent, nullptr, "SetBoolOnGround", nullptr, nullptr, Z_Construct_UFunction_UCustomMoveComponent_SetBoolOnGround_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMoveComponent_SetBoolOnGround_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCustomMoveComponent_SetBoolOnGround_Statics::CustomMoveComponent_eventSetBoolOnGround_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMoveComponent_SetBoolOnGround_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCustomMoveComponent_SetBoolOnGround_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCustomMoveComponent_SetBoolOnGround_Statics::CustomMoveComponent_eventSetBoolOnGround_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCustomMoveComponent_SetBoolOnGround()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCustomMoveComponent_SetBoolOnGround_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCustomMoveComponent::execSetBoolOnGround)
{
	P_GET_UBOOL(Z_Param__bool);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetBoolOnGround(Z_Param__bool);
	P_NATIVE_END;
}
// End Class UCustomMoveComponent Function SetBoolOnGround

// Begin Class UCustomMoveComponent Function SetLineTraceOnGroundEnd
struct Z_Construct_UFunction_UCustomMoveComponent_SetLineTraceOnGroundEnd_Statics
{
	struct CustomMoveComponent_eventSetLineTraceOnGroundEnd_Parms
	{
		FVector _end;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "CustomMoveComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp__end;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCustomMoveComponent_SetLineTraceOnGroundEnd_Statics::NewProp__end = { "_end", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CustomMoveComponent_eventSetLineTraceOnGroundEnd_Parms, _end), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCustomMoveComponent_SetLineTraceOnGroundEnd_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomMoveComponent_SetLineTraceOnGroundEnd_Statics::NewProp__end,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMoveComponent_SetLineTraceOnGroundEnd_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCustomMoveComponent_SetLineTraceOnGroundEnd_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCustomMoveComponent, nullptr, "SetLineTraceOnGroundEnd", nullptr, nullptr, Z_Construct_UFunction_UCustomMoveComponent_SetLineTraceOnGroundEnd_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMoveComponent_SetLineTraceOnGroundEnd_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCustomMoveComponent_SetLineTraceOnGroundEnd_Statics::CustomMoveComponent_eventSetLineTraceOnGroundEnd_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMoveComponent_SetLineTraceOnGroundEnd_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCustomMoveComponent_SetLineTraceOnGroundEnd_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCustomMoveComponent_SetLineTraceOnGroundEnd_Statics::CustomMoveComponent_eventSetLineTraceOnGroundEnd_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCustomMoveComponent_SetLineTraceOnGroundEnd()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCustomMoveComponent_SetLineTraceOnGroundEnd_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCustomMoveComponent::execSetLineTraceOnGroundEnd)
{
	P_GET_STRUCT(FVector,Z_Param__end);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetLineTraceOnGroundEnd(Z_Param__end);
	P_NATIVE_END;
}
// End Class UCustomMoveComponent Function SetLineTraceOnGroundEnd

// Begin Class UCustomMoveComponent Function SetLineTraceOnGroundStart
struct Z_Construct_UFunction_UCustomMoveComponent_SetLineTraceOnGroundStart_Statics
{
	struct CustomMoveComponent_eventSetLineTraceOnGroundStart_Parms
	{
		FVector _start;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "CustomMoveComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp__start;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCustomMoveComponent_SetLineTraceOnGroundStart_Statics::NewProp__start = { "_start", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CustomMoveComponent_eventSetLineTraceOnGroundStart_Parms, _start), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCustomMoveComponent_SetLineTraceOnGroundStart_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomMoveComponent_SetLineTraceOnGroundStart_Statics::NewProp__start,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMoveComponent_SetLineTraceOnGroundStart_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCustomMoveComponent_SetLineTraceOnGroundStart_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCustomMoveComponent, nullptr, "SetLineTraceOnGroundStart", nullptr, nullptr, Z_Construct_UFunction_UCustomMoveComponent_SetLineTraceOnGroundStart_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMoveComponent_SetLineTraceOnGroundStart_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCustomMoveComponent_SetLineTraceOnGroundStart_Statics::CustomMoveComponent_eventSetLineTraceOnGroundStart_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMoveComponent_SetLineTraceOnGroundStart_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCustomMoveComponent_SetLineTraceOnGroundStart_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCustomMoveComponent_SetLineTraceOnGroundStart_Statics::CustomMoveComponent_eventSetLineTraceOnGroundStart_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCustomMoveComponent_SetLineTraceOnGroundStart()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCustomMoveComponent_SetLineTraceOnGroundStart_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCustomMoveComponent::execSetLineTraceOnGroundStart)
{
	P_GET_STRUCT(FVector,Z_Param__start);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetLineTraceOnGroundStart(Z_Param__start);
	P_NATIVE_END;
}
// End Class UCustomMoveComponent Function SetLineTraceOnGroundStart

// Begin Class UCustomMoveComponent
void UCustomMoveComponent::StaticRegisterNativesUCustomMoveComponent()
{
	UClass* Class = UCustomMoveComponent::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "AddLinetraceIgnore", &UCustomMoveComponent::execAddLinetraceIgnore },
		{ "GetBoolOnGround", &UCustomMoveComponent::execGetBoolOnGround },
		{ "GetHitResultOnGround", &UCustomMoveComponent::execGetHitResultOnGround },
		{ "GetLineTraceOnGroundEnd", &UCustomMoveComponent::execGetLineTraceOnGroundEnd },
		{ "GetLineTraceOnGroundStart", &UCustomMoveComponent::execGetLineTraceOnGroundStart },
		{ "OnOverlapEnd", &UCustomMoveComponent::execOnOverlapEnd },
		{ "SetBoolOnGround", &UCustomMoveComponent::execSetBoolOnGround },
		{ "SetLineTraceOnGroundEnd", &UCustomMoveComponent::execSetLineTraceOnGroundEnd },
		{ "SetLineTraceOnGroundStart", &UCustomMoveComponent::execSetLineTraceOnGroundStart },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Capsule_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Ref on Character Capsule\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "CustomMoveComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Ref on Character Capsule" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinY_MetaData[] = {
		{ "Category", "Movement|Bounds" },
		{ "ModuleRelativePath", "CustomMoveComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxY_MetaData[] = {
		{ "Category", "Movement|Bounds" },
		{ "ModuleRelativePath", "CustomMoveComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HalfArenaWidth_MetaData[] = {
		{ "Category", "Movement|Bounds" },
		{ "ModuleRelativePath", "CustomMoveComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraCenterY_MetaData[] = {
		{ "Category", "Movement|Bounds" },
		{ "ModuleRelativePath", "CustomMoveComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_camera_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "CustomMoveComponent" },
		{ "ModuleRelativePath", "CustomMoveComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_b_OnGround_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "CustomMoveComponent" },
		{ "ModuleRelativePath", "CustomMoveComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_b_JustJumped_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "CustomMoveComponent" },
		{ "ModuleRelativePath", "CustomMoveComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_b_isColliderOnTheGround_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "CustomMoveComponent" },
		{ "ModuleRelativePath", "CustomMoveComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_start_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "CustomMoveComponent" },
		{ "ModuleRelativePath", "CustomMoveComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_end_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "CustomMoveComponent" },
		{ "ModuleRelativePath", "CustomMoveComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_hitResult_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "CustomMoveComponent" },
		{ "ModuleRelativePath", "CustomMoveComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_newLocation_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "CustomMoveComponent" },
		{ "ModuleRelativePath", "CustomMoveComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_velocity_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "CustomMoveComponent" },
		{ "ModuleRelativePath", "CustomMoveComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Gravity;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Capsule;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MinY;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxY;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_HalfArenaWidth;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CameraCenterY;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_m_camera;
	static void NewProp_b_OnGround_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_b_OnGround;
	static void NewProp_b_JustJumped_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_b_JustJumped;
	static void NewProp_b_isColliderOnTheGround_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_b_isColliderOnTheGround;
	static const UECodeGen_Private::FStructPropertyParams NewProp_m_start;
	static const UECodeGen_Private::FStructPropertyParams NewProp_m_end;
	static const UECodeGen_Private::FStructPropertyParams NewProp_m_hitResult;
	static const UECodeGen_Private::FStructPropertyParams NewProp_m_newLocation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_m_velocity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UCustomMoveComponent_AddLinetraceIgnore, "AddLinetraceIgnore" }, // 362055357
		{ &Z_Construct_UFunction_UCustomMoveComponent_GetBoolOnGround, "GetBoolOnGround" }, // 2888384416
		{ &Z_Construct_UFunction_UCustomMoveComponent_GetHitResultOnGround, "GetHitResultOnGround" }, // 3178150606
		{ &Z_Construct_UFunction_UCustomMoveComponent_GetLineTraceOnGroundEnd, "GetLineTraceOnGroundEnd" }, // 2717208480
		{ &Z_Construct_UFunction_UCustomMoveComponent_GetLineTraceOnGroundStart, "GetLineTraceOnGroundStart" }, // 519892869
		{ &Z_Construct_UFunction_UCustomMoveComponent_OnOverlapEnd, "OnOverlapEnd" }, // 3161140949
		{ &Z_Construct_UFunction_UCustomMoveComponent_SetBoolOnGround, "SetBoolOnGround" }, // 2765703706
		{ &Z_Construct_UFunction_UCustomMoveComponent_SetLineTraceOnGroundEnd, "SetLineTraceOnGroundEnd" }, // 3542780166
		{ &Z_Construct_UFunction_UCustomMoveComponent_SetLineTraceOnGroundStart, "SetLineTraceOnGroundStart" }, // 3601493992
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCustomMoveComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_Gravity = { "Gravity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCustomMoveComponent, Gravity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Gravity_MetaData), NewProp_Gravity_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_Capsule = { "Capsule", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCustomMoveComponent, Capsule), Z_Construct_UClass_UCapsuleComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Capsule_MetaData), NewProp_Capsule_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_MinY = { "MinY", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCustomMoveComponent, MinY), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinY_MetaData), NewProp_MinY_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_MaxY = { "MaxY", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCustomMoveComponent, MaxY), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxY_MetaData), NewProp_MaxY_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_HalfArenaWidth = { "HalfArenaWidth", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCustomMoveComponent, HalfArenaWidth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HalfArenaWidth_MetaData), NewProp_HalfArenaWidth_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_CameraCenterY = { "CameraCenterY", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCustomMoveComponent, CameraCenterY), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraCenterY_MetaData), NewProp_CameraCenterY_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_m_camera = { "m_camera", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCustomMoveComponent, m_camera), Z_Construct_UClass_ADynamicCamera_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_camera_MetaData), NewProp_m_camera_MetaData) };
void Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_b_OnGround_SetBit(void* Obj)
{
	((UCustomMoveComponent*)Obj)->b_OnGround = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_b_OnGround = { "b_OnGround", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UCustomMoveComponent), &Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_b_OnGround_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_b_OnGround_MetaData), NewProp_b_OnGround_MetaData) };
void Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_b_JustJumped_SetBit(void* Obj)
{
	((UCustomMoveComponent*)Obj)->b_JustJumped = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_b_JustJumped = { "b_JustJumped", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UCustomMoveComponent), &Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_b_JustJumped_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_b_JustJumped_MetaData), NewProp_b_JustJumped_MetaData) };
void Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_b_isColliderOnTheGround_SetBit(void* Obj)
{
	((UCustomMoveComponent*)Obj)->b_isColliderOnTheGround = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_b_isColliderOnTheGround = { "b_isColliderOnTheGround", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UCustomMoveComponent), &Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_b_isColliderOnTheGround_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_b_isColliderOnTheGround_MetaData), NewProp_b_isColliderOnTheGround_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_m_start = { "m_start", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCustomMoveComponent, m_start), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_start_MetaData), NewProp_m_start_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_m_end = { "m_end", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCustomMoveComponent, m_end), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_end_MetaData), NewProp_m_end_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_m_hitResult = { "m_hitResult", nullptr, (EPropertyFlags)0x0040008000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCustomMoveComponent, m_hitResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_hitResult_MetaData), NewProp_m_hitResult_MetaData) }; // 4100991306
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_m_newLocation = { "m_newLocation", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCustomMoveComponent, m_newLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_newLocation_MetaData), NewProp_m_newLocation_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_m_velocity = { "m_velocity", nullptr, (EPropertyFlags)0x0040000000020015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCustomMoveComponent, m_velocity), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_velocity_MetaData), NewProp_m_velocity_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCustomMoveComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_Gravity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_Capsule,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_MinY,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_MaxY,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_HalfArenaWidth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_CameraCenterY,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_m_camera,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_b_OnGround,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_b_JustJumped,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_b_isColliderOnTheGround,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_m_start,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_m_end,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_m_hitResult,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_m_newLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_m_velocity,
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
	FuncInfo,
	Z_Construct_UClass_UCustomMoveComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
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
DEFINE_VTABLE_PTR_HELPER_CTOR(UCustomMoveComponent);
UCustomMoveComponent::~UCustomMoveComponent() {}
// End Class UCustomMoveComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_ASP_Source_ASP_CustomMoveComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCustomMoveComponent, UCustomMoveComponent::StaticClass, TEXT("UCustomMoveComponent"), &Z_Registration_Info_UClass_UCustomMoveComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCustomMoveComponent), 753899121U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ASP_Source_ASP_CustomMoveComponent_h_307219344(TEXT("/Script/ASP"),
	Z_CompiledInDeferFile_FID_ASP_Source_ASP_CustomMoveComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ASP_Source_ASP_CustomMoveComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
