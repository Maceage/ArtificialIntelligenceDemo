// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyController.generated.h"

/**
 * 
 */
UCLASS()
class DEMO_API AEnemyController : public AAIController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

	UFUNCTION()
	void GoToNextPatrolPoint();

	virtual void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) override;

private:
	FTimerHandle PatrolTimerHandle;

};
