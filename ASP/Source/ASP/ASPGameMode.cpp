// Copyright Epic Games, Inc. All Rights Reserved.

#include "ASPGameMode.h"
#include "ASPCharacter.h"
#include "CustomMoveComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameManager.h"
#include "FightingGame_PlayerController.h"
#include "UFighting_GameGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

AASPGameMode::AASPGameMode()
{
}

void AASPGameMode::BeginPlay()
{
	Super::BeginPlay();

	GI = Cast<UFighting_GameGameInstance>(GetGameInstance());
	m_gameManager = GetGameInstance()->GetSubsystem<UGameManager>();
	StartOrder();
}

void AASPGameMode::StartOrder()
{
	if (!GI)
	{
		UE_LOG(LogTemp, Error, TEXT("SpawnCharacterForController: GameInstance ist NULL!"));
		return;
	}

	if (!m_gameManager)
	{
		UE_LOG(LogTemp, Error, TEXT("GameManager ist NULL!"));
		return;
	}

	m_playerController1 = Cast<AFightingGame_PlayerController>(
		UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (!m_playerController1)
	{
		m_playerController1 = Cast<AFightingGame_PlayerController>(UGameplayStatics::CreatePlayer(GetWorld(), 0, true));
	}

	m_playerController2 = Cast<AFightingGame_PlayerController>(
		UGameplayStatics::GetPlayerController(GetWorld(), 1));
	if (!m_playerController2)
	{
		m_playerController2 = Cast<AFightingGame_PlayerController>(UGameplayStatics::CreatePlayer(GetWorld(), 1, true));
	}

	if (!m_playerController1 || !m_playerController2)
	{
		UE_LOG(LogTemp, Error, TEXT("PlayerController(s) existieren noch nicht."));
		GetWorld()->GetTimerManager().SetTimerForNextTick([this]()
		{
			StartOrder();
		});
		return;
	}
	if (m_playerController2)
	{
		m_playerController2->GetLocalPlayer()->ViewportClient->SetForceDisableSplitscreen(true);
	}

	m_playerController2->UsingGamepad();
	m_playerController1->SetPlayerID(0);
	m_playerController2->SetPlayerID(1);


	m_playerController1->SetupMappingContext();
	m_playerController2->SetupMappingContext();

	SpawnCharacterForController(m_playerController1, m_player1, m_player1Position, m_player1Rotation);
	SpawnCharacterForController(m_playerController2, m_player2, m_player2Position, m_player2Rotation);

	InitializeFighters(m_player1, m_playerController1);
	InitializeFighters(m_player2, m_playerController2);

	m_player1->Start();
	m_player2->Start();

	m_playerController1->DefaultMappingContext = GI->DefaultMappingContext_Player1;
	m_playerController2->DefaultMappingContext = GI->DefaultMappingContext_Player2;

	UE_LOG(LogTemp, Warning, TEXT("PC1 Local: %d"), m_playerController1->IsLocalController());
	UE_LOG(LogTemp, Warning, TEXT("PC2 Local: %d"), m_playerController2->IsLocalController());

	UE_LOG(LogTemp, Warning, TEXT("PC1 LocalPlayer: %p"), m_playerController1->GetLocalPlayer());
	UE_LOG(LogTemp, Warning, TEXT("PC2 LocalPlayer: %p"), m_playerController2->GetLocalPlayer());

	UE_LOG(LogTemp, Warning, TEXT("PC1 ID: %d"), m_playerController1->GetLocalPlayer()->GetControllerId());
	UE_LOG(LogTemp, Warning, TEXT("PC2 ID: %d"), m_playerController2->GetLocalPlayer()->GetControllerId());
}

void AASPGameMode::SpawnCharacterForController(AFightingGame_PlayerController* _pc, AASPCharacter*& _outCharacter,
                                               const FVector& _spawnPos, const FRotator& _spawnRot)
{
	if (!_pc || !GI)
	{
		UE_LOG(LogTemp, Error, TEXT("SpawnCharacterForController: PlayerController oder GameInstance ist NULL!"));
		return;
	}

	if (!GI->SelectedPlayer1Class || !GI->SelectedPlayer2Class)
	{
		UE_LOG(LogTemp, Error, TEXT("SpawnCharacterForController: CharacterClasses sind NULL!"));
		return;
	}

	TSubclassOf<AASPCharacter> classToSpawn = (_pc->GetPlayerID() == 0)
		                                          ? GI->SelectedPlayer1Class
		                                          : GI->SelectedPlayer2Class;

	_outCharacter = GetWorld()->SpawnActor<AASPCharacter>(classToSpawn, _spawnPos, _spawnRot);

	if (!_outCharacter)
	{
		UE_LOG(LogTemp, Error, TEXT("GameManager: Character konnte nicht gespawnt werden!"));
		return;
	}

	_pc->SetCharacterRef(_outCharacter);
	_pc->SetGameManager(m_gameManager);
}

void AASPGameMode::InitializeFighters(AASPCharacter* _character, AFightingGame_PlayerController* _pc)
{
	if (!_character || !_pc) return;

	_character->SetPlayerController(_pc);
	_pc->ResetInputBuffer();
}
