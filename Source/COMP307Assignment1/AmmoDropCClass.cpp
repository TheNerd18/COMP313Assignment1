// Fill out your copyright notice in the Description page of Project Settings.


#include "AmmoDropCClass.h"

// Sets default values
AAmmoDropCClass::AAmmoDropCClass()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> AmmoVisualAsset(TEXT("/Game/AssetMeshes/AmmoDropMesh.AmmoDropMesh"));

	if (AmmoVisualAsset.Succeeded())
	{
		VisualMesh->SetStaticMesh(AmmoVisualAsset.Object);
		VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}

}

// Called when the game starts or when spawned
void AAmmoDropCClass::BeginPlay()
{
	Super::BeginPlay();


	
}

// Called every frame
void AAmmoDropCClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();
	FRotator NewRotation = GetActorRotation();
	float RunningTime = GetGameTimeSinceCreation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	NewLocation.Z += DeltaHeight * 20.0f;       //Scale our height by a factor of 20
	float DeltaRotation = DeltaTime * 50.0f;    //Rotate by 20 degrees per second
	NewRotation.Yaw += DeltaRotation;
	SetActorLocationAndRotation(NewLocation, NewRotation);

}



