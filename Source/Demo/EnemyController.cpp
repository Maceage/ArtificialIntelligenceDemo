// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyController.h"
#include "Navigation/PathFollowingComponent.h"
#include "EnemyCharacter.h"

void AEnemyController::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(PatrolTimerHandle, this, &AEnemyController::GoToNextPatrolPoint, 3, false);

}

void AEnemyController::GoToNextPatrolPoint()
{
	AEnemyCharacter* ControllingEnemy = Cast<AEnemyCharacter>(GetPawn());
	if (ControllingEnemy)
	{
		MoveToLocation(ControllingEnemy->GetNextPatrolLocation());
	}
}

void AEnemyController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
	Super::OnMoveCompleted(RequestID, Result);

	GetWorld()->GetTimerManager().SetTimer(PatrolTimerHandle, this, &AEnemyController::GoToNextPatrolPoint, 3, false);
}

