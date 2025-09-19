// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyCharacter.generated.h"

UCLASS()
class DEMO_API AEnemyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	// MakeEditWidget:
	// Shows a wireframe diamond in-world at an offset relative to the parent actor. 
	// It also shows some debug text.
	// Used for Transform/Rotator properties. Indicates that the property 
	// should be exposed in the viewport as a movable widget.

	UPROPERTY(EditAnywhere, Category = "Patrol", Meta = (MakeEditWidget))
	TArray<FVector> LocalPatrolPoints;

	UFUNCTION(BlueprintCallable)
	const FVector& GetNextPatrolLocation();

private:
	TArray<FVector> WorldPatrolPoints;

	int CurrentPatrolIndex = 0;

};
