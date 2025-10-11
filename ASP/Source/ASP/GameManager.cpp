// Fill out your copyright notice in the Description page of Project Settings.


#include "GameManager.h"

#include "ASPCharacter.h"
#include "MoveableInterface.h"
#include "Engine/World.h"
#include "TimerManager.h"

UGameManager::UGameManager()
{
}

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

void UGameManager::Tick(float _deltaTime)
{
	m_accumulatedTime += _deltaTime;

	while (m_accumulatedTime >= FIXED_UPDATE_RATE)
	{
		FixedGameUpdate60Hz(FIXED_UPDATE_RATE);
		m_accumulatedTime -= FIXED_UPDATE_RATE;
	}
}

void UGameManager::FixedGameUpdate60Hz(float _fixedDeltatime)
{
	if (FrameNumber > 60)
	{
		FrameNumber = 0;
		return;
	}

	GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Yellow,
	  FString::Printf(TEXT("Frame: %d | Player1: %s | Player2: %s"),
	  FrameNumber,
	  *GetNameSafe(Player1),
	  *GetNameSafe(Player2)));

	for (auto& movable : m_movables)
	{
		if (movable)
		{
			movable->FixedUpdate(_fixedDeltatime);
		}
	}
	
	FrameNumber++;
}

void UGameManager::RegisterMovable(TScriptInterface<IMoveableInterface> _movable)
{
	m_movables.Add(_movable);
}

void UGameManager::OnWorldInitialization(UWorld* _world, const UWorld::InitializationValues _ivs)
{
	if (!_world || !_world->IsGameWorld()) return;

	m_cachedWorld = _world;
	
//	_world->GetTimerManager().SetTimer(
//		m_fixedUpdateHandle,
//		this,
//		&UGameManager::FixedGameUpdate60Hz,
//		FIXED_UPDATE_RATE,
//		true
//	);
}
