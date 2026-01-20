// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Tickable.h"

#include "FMovementSimulator.h"
#include "FRollbackManager.h"
#include "GameStateTypes.h"
#include "InputHandler.h"

#include "GameManager.generated.h"

class ADebugStateActor;
class AASPCharacter;
class AFightingGame_PlayerController;
class ADynamicCamera;

/* =============================
 * === GAME MANAGER ===
 * ============================= */
UCLASS(Blueprintable)
class ASP_API UGameManager : public UGameInstanceSubsystem, public FTickableGameObject
{
	GENERATED_BODY()

	UGameManager();

public:
	/* =============================
	 * === SUBSYSTEM ===
	 * ============================= */
	virtual void Initialize(FSubsystemCollectionBase& _collection) override;
	virtual void Deinitialize() override;

	/* =============================
	 * === TICK ===
	 * ============================= */
	virtual void Tick(float _deltaTime) override;
	virtual TStatId GetStatId() const override { RETURN_QUICK_DECLARE_CYCLE_STAT(UGameManager, STATGROUP_Tickables); }

	virtual bool IsTickable() const override { return true; }
	virtual bool IsTickableWhenPaused() const override { return false; }
	virtual bool IsTickableInEditor() const override { return false; }

	// =============================
	// Registration
	// =============================
	void RegisterPlayer(
		int32 _playerIndex,
		AASPCharacter* _character,
		AFightingGame_PlayerController* _controller, FVector _location, float _yaw
	);

	/* =============================
	 * === Add To Queue ===
	 * ============================= */
	void AddInputToQueue(AFightingGame_PlayerController* _pc, const FInputPacket& _packet);
	void FixedGameUpdateForRollback(int32 _frame, FGameState& _state);

	/* =============================
	 * === GETTER ===
	 * ============================= */
	FORCEINLINE class AASPCharacter* GetPlayer1() const { return m_player1; }
	FORCEINLINE class AASPCharacter* GetPlayer2() const { return m_player2; }
	FORCEINLINE class ADynamicCamera* GetCamera() const { return m_camera; }
	FORCEINLINE double static GetFixedDeltatime() { return FIXED_UPDATE_RATE; }
	FORCEINLINE int32 GetFrameNumber() const { return FrameNumber; }

private:
	/* =============================
	 * === FIXED UPDATE ===
	 * ============================= */
	void FixedGameUpdate60Hz(double _fixedDeltatime);
	void RenderUpdate(double _alpha);

	/* =============================
	 * === SETUP ===
	 * ============================= */
	void OnWorldInitialization(UWorld* _world, const UWorld::InitializationValues _ivs);
	void BeginPlaySetup();

	/* =============================
	 * === INPUT BUILDING ===
	 * ============================= */
	void BuildFrameInput(int32 _frame, FGameState& _outState);
	FFrameInput BuildPlayerInput(AFightingGame_PlayerController* _pc, int32 _frame);
public:

	/* =============================
	* === STATE APPLY ===
	* ============================= */
	void ApplyGameStateToActors(const FGameState& _state);

	/* =============================
	 * === Camera ===
	 * ============================= */
	void CheckBackMovement(FCharacterState& _state) const;
	
	/* =============================
	 * === LEGACY INPUT SUPPORT ===
	 * ============================= */
	const FInputPacket* GetInputQueueAtFrame(AFightingGame_PlayerController* _pc, int32 _frameNumber) const;
	EInputAction CheckForCombo(AFightingGame_PlayerController* _pc, int32 _currentFrame);

private:

	UPROPERTY(EditAnywhere,meta = (AllowPrivateAccess=true))
	bool m_bDebugRollbackOnDesync = false;
	void SpawnSnapshotDebug(int32 _frame, const FGameState& _state, bool _bool, bool _bIsLogicstate);
	TMap<int32, FGameState> BeforeRollbackStates;
	/* =============================
	 * Core State
	 * ============================= */
	FGameState m_currentGameState;

	/* =============================
	 * Simulation
	 * ============================= */
	FMovementSimulator m_movementSimP1;
	FMovementSimulator m_movementSimP2;

	/* =============================
	 * Visuals
	 * ============================= */
	TUniquePtr<FCharacterVisual> m_visualP1;
	TUniquePtr<FCharacterVisual> m_visualP2;

	/* =============================
	 * Rollback
	 * ============================= */
	FRollbackManager m_rollbackManager;

	/* =============================
	 * === WORLD ===
	 * ============================= */
	TWeakObjectPtr<UWorld> m_cachedWorld;
	
	// =============================
	// Players
	// =============================
	UPROPERTY(EditAnywhere)
	AFightingGame_PlayerController* m_playerController1 = nullptr;
	UPROPERTY(EditAnywhere)
	AFightingGame_PlayerController* m_playerController2 = nullptr;

	UPROPERTY(EditAnywhere)
	class AASPCharacter* m_player1 = nullptr;
	UPROPERTY(EditAnywhere)
	class AASPCharacter* m_player2 = nullptr;

	/* =============================
	 * === Camera ===
	 * ============================= */
	UPROPERTY(EditAnywhere)
	ADynamicCamera* m_camera;

	/* =============================
	 * === INPUT STORAGE ===
	 * ============================= */
	TMap<AFightingGame_PlayerController*, TMap<int32, FInputPacket>> m_playerInputQueues;
	TMap<AFightingGame_PlayerController*, TMap<int32, FStoredFrameInput>> m_inputHistory;
	
	/* =============================
	 * === TIMING ===
	 * ============================= */
	double m_accumulatedTime = 0.0f;
	static constexpr double FIXED_UPDATE_RATE = 1.0f / 60.0f;
	int32 FrameNumber = 0;
	int LastSimulatedFrame = -1;
};


