#include "FRollbackManager.h"


void FRollbackManager::SaveFrame(int32 _frame, const FGameState& _gameState)
{
	FFrameSnapshot snapshot;
	snapshot.FrameNumber = _frame;
	snapshot.GameState = _gameState;

	snapshot.RNGSeed = FMath::Rand();

	m_history.Add(_frame, snapshot);

	const int32 minFrame = _frame - MaxStoredFrames;
	//CreateIterator = create the Iterator of the map
	//It; = It == true; do the loop
	// It == false; stop the loop
	for (auto It = m_history.CreateIterator(); It; ++It)
	{
		if (It.Key() < minFrame)
			It.RemoveCurrent();
	}
}

bool FRollbackManager::LoadFrame(int32 _frame, FGameState& _outGameState)
{
	const FFrameSnapshot* snapshot = m_history.Find(_frame);
	if (!snapshot)
		return false;

	_outGameState = snapshot->GameState;
	FMath::RandInit(snapshot->RNGSeed);
	return true;
}

void FRollbackManager::RollbackToFrame(int32 _targetFrame, int32 _currentFrame, FGameState& _inOutGameState,
                                       TFunctionRef<void(int32, FGameState&)> _simulateFrame)
{
	if (!LoadFrame(_targetFrame + 1, _inOutGameState))
	{
		UE_LOG(LogTemp, Error, TEXT("Rollback failed: frame %d not found"), _targetFrame);
		return;
	}

	for (int32 Frame = _targetFrame; Frame < _currentFrame; ++Frame)
	{
		_simulateFrame(Frame, _inOutGameState);
	}
}

