// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedStruct.h"
#include "RPSType.h"
#include "RoundStatus.h"
#include "Round.generated.h"

/**
 * 
 */
UCLASS()
class ROCKPAPERSCISSORS_API URound : public UUserDefinedStruct
{
	GENERATED_BODY()

public:
	URound();
	EType GetPlayerChoice() { return PlayerChoice; }
	EType GetOppChoice() { return OppChoice; }
	EStatus GetRoundStatus() { return RoundStatus; }
	void SetPlayerChoice(EType NewChoice) { PlayerChoice = NewChoice; }
	void SetOppChoice(EType NewChoice) { OppChoice = NewChoice; }
	void SetRoundStatus(EStatus Status) { RoundStatus = Status; }
private:
	EType PlayerChoice;
	EType OppChoice;
	EStatus RoundStatus;
};
