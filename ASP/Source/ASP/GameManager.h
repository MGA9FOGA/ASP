// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ASPCharacter.h"
#include "InputHandler.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GameManager.generated.h"

class AFightingGame_PlayerController;
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

	//For Player Input Handling
	void AddInputToQueue(AFightingGame_PlayerController* _playerController, const FInputPacket& _packet);
	const TArray<FInputPacket>& GetInputQueue(int _playerIndex) const;
	void ProcessInputs(); 
	EAction CheckForCombo(int _playerIndex);
	
	//Fixed Update
	UFUNCTION()
	void FixedGameUpdate60Hz(float _fixedDeltatime);
	//Register Player
	UFUNCTION()
	void RegisterMovable(TScriptInterface<IMoveableInterface> _movable);
	FORCEINLINE void RegisterPlayer1(class AASPCharacter* _player, float _number){m_player1 = _player; m_player1->SetPlayerID(_number);}
	FORCEINLINE void RegisterPlayer2(class AASPCharacter* _player, float _number){m_player2 = _player; m_player1->SetPlayerID(_number);}
	//Getter & Setter
	FORCEINLINE class AASPCharacter* GetPlayer1() const { return m_player1; }
	FORCEINLINE class AASPCharacter* GetPlayer2() const { return m_player2; }
	FORCEINLINE class AActor* GetCamera() const {return m_camera;}
	FORCEINLINE float GetFixedDeltatime() const {return FIXED_UPDATE_RATE;}
	FORCEINLINE FVector GetPlayer1SpawnPos() const {return m_player1Position;}
	FORCEINLINE FVector GetPlayer2SpawnPos() const {return m_player2Position;}
	FORCEINLINE FRotator GetPlayer1SpawnRotation() const {return m_player1Rotation;}
	FORCEINLINE FRotator GetPlayer2SpawnRotation() const {return m_player2Rotation;}
	
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
	
	//Input Queue
	TMap<int32, TArray<FInputPacket>> m_playerInputQueues; // z. B. 0 = P1, 1 = P2
	//Player1
	class AASPCharacter* m_player1 = nullptr;
	//Player2
	class AASPCharacter* m_player2 = nullptr;
	//Spawnpoints
	FVector m_player1Position = FVector(730.0f,1230.0f,1800.0f);
	FRotator m_player1Rotation = FRotator(0.0f,0.0f,0.0f);
	FVector m_player2Position = FVector(730.0f,1430.0f,1800.0f);
	FRotator m_player2Rotation = FRotator(0.0f,180.0f,0.0f);
	
};
