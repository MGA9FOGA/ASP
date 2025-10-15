// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GameManager.generated.h"

class IMoveableInterface;
/**
 * 
 */
UCLASS(Blueprintable)
class ASP_API UGameManager : public UGameInstanceSubsystem, public FTickableGameObject
{
	GENERATED_BODY()

	UGameManager();
public:
	virtual void Initialize(FSubsystemCollectionBase& _collection) override;
	virtual void Deinitialize() override;
	
	//*FTickableGameObject Functions*//
	virtual void Tick(float _deltaTime) override;
	virtual TStatId GetStatId() const override
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(UGameManager, STATGROUP_Tickables);
	}
	virtual bool IsTickable() const override { return true; }
	virtual bool IsTickableWhenPaused() const override { return false; }
	virtual bool IsTickableInEditor() const override { return false; }
	
	//Fixed Update
	UFUNCTION()
	void FixedGameUpdate60Hz(float _fixedDeltatime);
	//Register Player
	UFUNCTION()
	void RegisterPlayer1(class AASPCharacter* _player){m_player1 = _player;}
	UFUNCTION()
	void RegisterPlayer2(class AASPCharacter* _player){m_player2 = _player;}
	UFUNCTION()
	void RegisterMovable(TScriptInterface<IMoveableInterface> _movable);

	FORCEINLINE class AASPCharacter* GetPlayer1() const { return m_player1; }
	FORCEINLINE class AASPCharacter* GetPlayer2() const { return m_player2; }
	FORCEINLINE class AActor* GetCamera() const {return m_camera;}
	FORCEINLINE float GetFixedDeltatime() const {return FIXED_UPDATE_RATE;}
private:
	void OnWorldInitialization(UWorld* _world, const UWorld::InitializationValues _ivs);

public:
	const float FIXED_UPDATE_RATE = 1.0f / 60.0f;
	
	int32 FrameNumber = 0;

private:
	TArray<TScriptInterface<IMoveableInterface>> m_movables;
	FTimerHandle m_fixedUpdateHandle;
	TWeakObjectPtr<UWorld> m_cachedWorld;
	float m_accumulatedTime = 0.0f;
	AActor* m_camera;

	//Player1
	class AASPCharacter* m_player1 = nullptr;
	//Player2
	class AASPCharacter* m_player2 = nullptr;
};
