// Fill out your copyright notice in the Description page of Project Settings.

#include "OpponentAI.h"

// Sets default values for this component's properties
UOpponentAI::UOpponentAI()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	Choices.Add(1);
	Choices.Add(2);
	Choices.Add(3);
}

// Called when the game starts
void UOpponentAI::BeginPlay()
{
	Super::BeginPlay();

	// ...
}

// Called every frame
void UOpponentAI::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

EType UOpponentAI::GetRandomChoice()
{
	return static_cast<EType>(FMath::RandRange(1, 3));
}

EType UOpponentAI::GetFuzzyChoice()
{
	/* Implementation of Fuzzy Logic */
	return EType::Rock;
}
EType UOpponentAI::GetChoice(EType WeightedChoice)
{
	/* The Weighted Choice contains what the AI determines the player's choice is */
	switch (WeightedChoice)
	{
	case EType::Rock:
		return EType::Paper;
		break;
	case EType::Paper:
		return EType::Scissors;
		break;
	case EType::Scissors:
		return EType::Rock;
		break;
	default:
		return EType::Rock;
		break;
	}
}