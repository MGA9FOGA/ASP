#pragma once
#include "GameStateTypes.h"
#include "TimerManager.h"
#include "Engine/World.h"


class AASPCharacter;
struct FAnimationMontageState;

struct FFrameSnapshot
{
	int64 FrameNumber;
	uint32 RNGSeed;
	FGameState GameState;
};


class ASP_API FRollbackManager
{
public:

	void SaveFrame(int32 _frame, const FGameState& _gameState);
	bool LoadFrame(int32 _frame, FGameState& _outGameState);

	void RollbackToFrame(
		int32 _targetFrame,
		int32 _currentFrame,
		FGameState& _inOutGameState,
		TFunctionRef<void(int32, FGameState&)> _simulateFrame
	);

private:
	TMap<int32, FFrameSnapshot> m_history;
	static constexpr int32 MaxStoredFrames = 130;//7
	
};
