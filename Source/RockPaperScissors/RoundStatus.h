// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedEnum.h"
#include "RoundStatus.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EStatus : uint8
{
	Pending = 0	UMETA(DisplayName = "Pending"),
	Draw = 1	UMETA(DisplayName = "Draw"),
	Lose = 2	UMETA(DisplayName = "Lose"),
	Win = 3		UMETA(DisplayName = "Win")
};
UCLASS()
class ROCKPAPERSCISSORS_API URoundStatus : public UUserDefinedEnum
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EStatus RPSStatus;
};
