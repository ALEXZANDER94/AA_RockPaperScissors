// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedEnum.h"
#include "RPSType.generated.h"

/**
 *
 */
UENUM(BlueprintType)
enum class EType : uint8
{
	None = 0 UMETA(DisplayName = "None"),
	Rock = 1 UMETA(DisplayName = "Rock"),
	Paper = 2 UMETA(DisplayName = "Paper"),
	Scissors = 3 UMETA(DisplayName = "Scissors")
};
UCLASS()
class ROCKPAPERSCISSORS_API URPSType : public UUserDefinedEnum
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EType RPSType;
};
