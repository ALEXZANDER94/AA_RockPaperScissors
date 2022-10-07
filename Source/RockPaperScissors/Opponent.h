// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RPSType.h"
#include "OpponentAI.h"
#include "Opponent.generated.h"

UCLASS()
class ROCKPAPERSCISSORS_API AOpponent : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AOpponent();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USkeletalMeshComponent *OppMesh;

	void MakeChoice();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	EType GetChoice() { return ChoiceType; }

	UFUNCTION(BlueprintCallable, BlueprintPure)
	ARPSChoice *GetChoiceObject() { return Choice; }

	void SetChoice(EType choice) { ChoiceType = choice; };

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void SetChoiceObject(ARPSChoice *choice) { Choice = choice; };

private:
	EType ChoiceType = EType::None;

	UOpponentAI *OpponentAI;

	ARPSChoice *Choice;
};
