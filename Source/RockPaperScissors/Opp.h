// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RPSType.h"
#include "RPSChoice.h"
#include "EngineUtils.h"
#include "GameFramework/Pawn.h"
#include "Components/SkeletalMeshComponent.h"
#include "Opp.generated.h"

UCLASS()
class ROCKPAPERSCISSORS_API AOpp : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AOpp();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USkeletalMeshComponent *OppMesh;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	EType GetChoice() { return ChoiceType; }

	UFUNCTION(BlueprintCallable, BlueprintPure)
	ARPSChoice *GetChoiceObject() { return Choice; }

	UFUNCTION(BlueprintCallable)
	void SetChoice(EType choice);

	UFUNCTION(BlueprintCallable)
	void SetLastChoice(EType choice);

	UFUNCTION(BlueprintCallable)
	void SetChoiceObject(ARPSChoice *choice) { Choice = choice; };

	UFUNCTION(BlueprintCallable)
	void SetChoiceObjectByType(EType choice);

	UFUNCTION(BlueprintImplementableEvent)
	void MakeChoice();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	EType GetLastChoice() { return LastChoice; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


private:
	EType ChoiceType = EType::None;

	ARPSChoice *Choice;

	EType LastChoice = EType::None;
};
