// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GameManager.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class ASP_API UGameManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	virtual void Initialize(FSubsystemCollectionBase& _collection) override;
	virtual void Deinitialize() override;
	UFUNCTION()
	void FixedGameUpdate60Hz();

private:
	void OnWorldInitialization(UWorld* _world, const UWorld::InitializationValues _ivs);

public:
	const float FIXED_UPDATE_RATE = 1.0f / 60.0f;
	
	//Player1
	//Player2

	int32 FrameNumber = 0;
private:
	FTimerHandle m_fixedUpdateHandle;
	TWeakObjectPtr<UWorld> m_cachedWorld;
	
};
