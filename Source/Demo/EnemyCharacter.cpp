// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter.h"
#include "EnemyController.h"

// Sets default values
AEnemyCharacter::AEnemyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AIControllerClass = AEnemyController::StaticClass(); // Set the AI controller class for this character

}

// Called when the game starts or when spawned
void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	// We need to get the actor location and add the patrol point to is
	// since these patrol points move with the actor
	for (auto PatrolPoint : LocalPatrolPoints)
	{
		WorldPatrolPoints.Add(PatrolPoint + GetActorLocation());
	}
}

// Called every frame
void AEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

const FVector& AEnemyCharacter::GetNextPatrolLocation()
{
	if (WorldPatrolPoints.Num() > 0)
	{
		if (CurrentPatrolIndex >= WorldPatrolPoints.Num())
		{
			CurrentPatrolIndex = 0;
		}
		return WorldPatrolPoints[CurrentPatrolIndex++];
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red,
			TEXT("No Patrol Location set for Enemy Actor"));
		return FVector::ZeroVector;
	}
}

