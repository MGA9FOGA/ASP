#pragma once
#include <filesystem>

#include "StateMachine.h"
#include "AnimationStateMachine.generated.h"
class LogicStateMachine;


USTRUCT(BlueprintType)
struct FAnimationMontageState
{
	GENERATED_BODY()
	
	FAnimationMontageState()
		: Montage(nullptr), MontageName(NAME_None), Time(0.f), Duration(0.f), bIsPlaying(false)
	{}

	FAnimationMontageState(UAnimMontage* InMontage)
		: Montage(InMontage), 
		  MontageName(InMontage ? InMontage->GetFName() : NAME_None),
		  Time(0.f),
		  Duration(InMontage ? InMontage->GetPlayLength() : 0.f),
		  bIsPlaying(false)
	{}
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Animation")
	TObjectPtr<UAnimMontage> Montage;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Animation")
	FName MontageName;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Animation")
	float Time;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Animation")
	float Duration;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Animation")
	bool bIsPlaying;
	
	float GetProgress() const
	{
		return (Duration > 0.f) ? (Time / Duration) : 0.f;
	}

	void Reset()
	{
		Time = 0.f;
		bIsPlaying = false;
	}
};

class ASP_API AnimationStateMachine : public FFightingStateMachine
{
public:
	AnimationStateMachine(LogicStateMachine& _stateMachine, AASPCharacter& _character);
	virtual ~AnimationStateMachine() override;
	virtual void BuildStates() override;
	//Delegate Function
	void OnLandingFinished();
	void OnJStartJumpFinished();

	FORCEINLINE bool GetIsLanded()const {return b_landingFinished;}
	FORCEINLINE void SetBoolIsLanded(bool _b) {b_landingFinished = _b;}
	FORCEINLINE void SetIsStartUpJumpFinished(bool _b) {b_startUpJumpingFinished = _b;}
	FORCEINLINE bool GetStartUpJumpedFinished()const {return b_startUpJumpingFinished;}
private:
	LogicStateMachine& m_logicStateMachine;
	//Landing Trasitions Bool
	bool b_landingFinished = false;
	bool b_startUpJumpingFinished = false;
};
