#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "RPSRound.h"
#include "RPS.generated.h"

/**
 *
 */
UCLASS()
class ROCKPAPERSCISSORS_API ARPS : public AGameModeBase
{
	GENERATED_BODY()

	ARPS();

public:
	UFUNCTION(BlueprintImplementableEvent)
	void ToggleRoundResult();

	UFUNCTION(BlueprintImplementableEvent)
	void ShowGameOver(EStatus gameStatus);

	UFUNCTION(BlueprintImplementableEvent)
	void MoveLogUp();

	UFUNCTION(BlueprintImplementableEvent)
	void MoveLogDown();

	UFUNCTION(BlueprintImplementableEvent)
	void RoundSequencer();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void CleanupSequencer();
};
