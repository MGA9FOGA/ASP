// Fill out your copyright notice in the Description page of Project Settings.


#include "DynamicCamera.h"
#include "Camera/CameraComponent.h"


const FName ADynamicCamera::CameraName(TEXT("CharacterMesh"));
// Sets default values
ADynamicCamera::ADynamicCamera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	USceneComponent* sceneComp = CreateDefaultSubobject<USceneComponent>(FName("Root"));
	RootComponent = sceneComp;
	
	Camera = CreateDefaultSubobject<UCameraComponent>(CameraName);
	Camera->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ADynamicCamera::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ADynamicCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

