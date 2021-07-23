// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "AmmoDropCClass.generated.h"

UCLASS()
class COMP307ASSIGNMENT1_API AAmmoDropCClass : public AActor
{
	GENERATED_BODY()
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* VisualMesh;


	//Box Collider
	UPROPERTY(EditAnywhere)
	UBoxComponent* BoxCollider;
	

	
public:	
	// Sets default values for this actor's properties
	AAmmoDropCClass();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
