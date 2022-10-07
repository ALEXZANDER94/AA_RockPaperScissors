// Fill out your copyright notice in the Description page of Project Settings.


#include "Round.h"

URound::URound()
{
	SetPlayerChoice(EType::None);
	SetOppChoice(EType::None);
	SetRoundStatus(EStatus::Pending);
}