// Fill out your copyright notice in the Description page of Project Settings.


#include "Opp.h"
#include "RPSChoice.h"
#include "RPSRound.h"
#include "Engine/Engine.h"
// Sets default values
AOpp::AOpp()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	OppMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	RootComponent = OppMesh;
}

// Called when the game starts or when spawned
void AOpp::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOpp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AOpp::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AOpp::SetChoice(EType choice)
{
	ChoiceType = choice;
}
void AOpp::SetLastChoice(EType choice)
{
	LastChoice = choice;
}
void AOpp::SetChoiceObjectByType(EType choice)
{
	FString ChoiceTypeAsString = (choice == EType::Rock) ? TEXT("Rock") : (choice == EType::Paper) ? TEXT("Paper") : TEXT("Scissors");
	for (TActorIterator<ARPSChoice> ChoiceActor(GetWorld()); ChoiceActor; ++ChoiceActor)
	{
		ARPSChoice *ChoiceObj = *ChoiceActor;
		if (ChoiceObj->ActorHasTag("Opponent") && ChoiceObj->ActorHasTag(FName(*ChoiceTypeAsString)))
		{
			SetChoiceObject(ChoiceObj);
		}
	}
}
