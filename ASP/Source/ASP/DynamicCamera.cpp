// Fill out your copyright notice in the Description page of Project Settings.


#include "DynamicCamera.h"

#include "ASPCharacter.h"
#include "GameManager.h"
#include "Camera/CameraComponent.h"


const FName ADynamicCamera::CameraName(TEXT("CharacterMesh"));
// Sets default values
ADynamicCamera::ADynamicCamera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	USceneComponent* sceneComp = CreateDefaultSubobject<USceneComponent>(FName("Root"));
	RootComponent = sceneComp;
	
	m_camera = CreateDefaultSubobject<UCameraComponent>(CameraName);
	m_camera->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ADynamicCamera::BeginPlay()
{
	Super::BeginPlay();
	m_gameManager = GetGameInstance()->GetSubsystem<UGameManager>();
}

// Called every frame
void ADynamicCamera::Update(float _deltaTime)
{

	if (!m_gameManager->GetPlayer1() || !m_gameManager->GetPlayer2()) return;

	FVector p1Pos = m_gameManager->GetPlayer1()->GetActorLocation();
	FVector p2Pos = m_gameManager->GetPlayer2()->GetActorLocation();

	FVector center = (p1Pos + p2Pos) * 0.5f;

	float distance = FVector::Dist(p1Pos, p2Pos);
	float targetDistance = FMath::Clamp(distance, m_minDistance, m_maxDistance);

	FVector targetLocation;
	targetLocation.X = center.X - targetDistance;
	targetLocation.Y = center.Y;
	targetLocation.Z = m_height;

	FVector newLocation = FMath::VInterpTo(GetActorLocation(), targetLocation, _deltaTime,m_cameraSmooth);

	SetActorLocation(newLocation);
}

bool ADynamicCamera::characterMaxDistanceAlloToMove()
{
	AASPCharacter* P1 = m_gameManager->GetPlayer1();
	AASPCharacter* P2 = m_gameManager->GetPlayer2();

	if (!P1 || !P2) return false;

	float Distance = FMath::Abs(P1->GetActorLocation().Y - P2->GetActorLocation().Y);

	//UE_LOG(LogTemp, Display, TEXT("Distance: %f"), Distance);
	
	return Distance < m_maxPlayerPositionDifference;
}

