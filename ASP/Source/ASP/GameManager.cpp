// Fill out your copyright notice in the Description page of Project Settings.


#include "GameManager.h"
#include "Engine/World.h"
#include "TimerManager.h"

void UGameManager::Initialize(FSubsystemCollectionBase& _collection)
{
	Super::Initialize(_collection);

	FWorldDelegates::OnPostWorldInitialization.AddUObject(
		this,
		&UGameManager::OnWorldInitialization
	);
}

void UGameManager::Deinitialize()
{
	Super::Deinitialize();
	
	FWorldDelegates::OnPostWorldInitialization.RemoveAll(this);

	if (m_cachedWorld.IsValid())
	{
		m_cachedWorld->GetTimerManager().ClearTimer(m_fixedUpdateHandle);
		m_cachedWorld= nullptr;
	}
}

void UGameManager::FixedGameUpdate60Hz()
{
	if (FrameNumber > 60)
	{
		FrameNumber = 0;
		return;
	}
	
	FrameNumber++;
}

void UGameManager::OnWorldInitialization(UWorld* _world, const UWorld::InitializationValues _ivs)
{
	if (!_world || !_world->IsGameWorld()) return;

	m_cachedWorld = _world;
	
	_world->GetTimerManager().SetTimer(
		m_fixedUpdateHandle,
		this,
		&UGameManager::FixedGameUpdate60Hz,
		FIXED_UPDATE_RATE,
		true
	);
}
