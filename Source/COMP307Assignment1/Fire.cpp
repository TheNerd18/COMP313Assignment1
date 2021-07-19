// Fill out your copyright notice in the Description page of Project Settings.


#include "Fire.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
AFire::AFire()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("FireParticle"));
    ParticleSystem->SetRelativeLocation(FVector(-0.0f, 0.0f, 0.0f));
    static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleAsset(TEXT("/Game/StarterContent/Particles/P_Fire.P_Fire"));
    if (ParticleAsset.Succeeded()){
        ParticleSystem->SetTemplate(ParticleAsset.Object);
	}
}

// Called when the game starts or when spawned
void AFire::BeginPlay()
{
	Super::BeginPlay();


	
}

// Called every frame
void AFire::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

