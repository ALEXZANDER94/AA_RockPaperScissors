// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerPawn.h"
#include "Opp.h"
#include "Engine/GameInstance.h"
#include "RoundStatus.h"
#include "RPSRound.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EMode : uint8
{
	BOf3 = 0	UMETA(DisplayName = "Best of 3"),
	BOf5 = 1	UMETA(DisplayName = "Best of 5"),
	FTo3 = 2	UMETA(DisplayName = "First to 3"),
	FTo5 = 3	UMETA(DisplayName = "First to 5"),
	Endless = 5	UMETA(DisplayName = "Endless")
};
UCLASS()
class ROCKPAPERSCISSORS_API URPSRound : public UGameInstance
{
	GENERATED_BODY()
	
	public:
		APlayerPawn* Player;
		AOpp* Opp;
		
		void OpponentTurn();

		/* Have these function be blueprintcallable to use in UserWidgets */

		/* Getters */
		UFUNCTION(BlueprintCallable, BlueprintPure)
		FString GetStatus() { return RoundStatus; };

		UFUNCTION(BlueprintCallable, BlueprintPure)
		APlayerPawn* GetPlayer() { return Player; }

		UFUNCTION(BlueprintCallable, BlueprintPure)
		AOpp* GetOpponent() { return Opp; }

		UFUNCTION(BlueprintCallable, BlueprintPure)
		EStatus GetPlayerWon() { return PlayerWon; }

		UFUNCTION(BlueprintCallable, BlueprintPure)
		int GetPlayerWins() { return PlayerWins; }

		UFUNCTION(BlueprintCallable, BlueprintPure)
		int GetPlayerLosses() { return PlayerLosses; }
		
		UFUNCTION(BlueprintCallable, BlueprintPure)
		int GetDraws() { return DrawGames; }

		UFUNCTION(BlueprintCallable, BlueprintPure)
		int GetRound() { return Round; }

		UFUNCTION(BlueprintCallable, BlueprintPure)
		EMode GetMode() { return Mode; }
		
		UFUNCTION(BlueprintCallable, BlueprintPure)
		bool GetAdvancedAI() { return bAdvancedAI; }

		UFUNCTION(BlueprintCallable, BlueprintPure)
		bool GetOpponentHasEyes() { return bOppHasEyes; }

		UFUNCTION(BlueprintCallable)
		bool GetGameOver() { return GameOver; }

		/* Setters */
		UFUNCTION(BlueprintCallable)
		void SetAdvancedAI(bool advAI) { bAdvancedAI = advAI; }

		UFUNCTION(BlueprintCallable)
		void SetOpponentHasEyes(bool hasEyes) { bOppHasEyes = hasEyes; }

		UFUNCTION(BlueprintCallable)
		void SetMode(EMode mode) { Mode = mode; }

		UFUNCTION(BlueprintCallable)
		void ResetGame();

		UFUNCTION(BlueprintCallable)
		void PerformRoundAnim();

		UFUNCTION(BlueprintCallable)
		void CleanupRoundAnim();

		UFUNCTION(BlueprintImplementableEvent)
		void AppendRound(EType PlayerChoice, EType OppChoice, EStatus Status);

		UFUNCTION(BlueprintCallable)
		void SetPlayerRef(APlayerPawn* PlayerRef) { Player = PlayerRef; }

	protected:
		void ResolveRound();
		void SetStatus(FString status) { RoundStatus = status; };
		void IncPlayerWins() { PlayerWins++; };
		void IncPlayerLosses() { PlayerLosses++; };
		void IncDrawGames() { DrawGames++; };
		UFUNCTION()
		void SetPlayerWon(EStatus won) { PlayerWon = won; };
		void SetGameOver(bool over) { GameOver = over; };
		void IncRounds() { Round++; };
		UFUNCTION(BlueprintCallable)
		void CheckGame();

	private:
		FString RoundStatus;
		int PlayerWins = 0;
		int PlayerLosses = 0;
		int DrawGames = 0;
		EStatus PlayerWon = EStatus::Pending;
		bool bAdvancedAI = true;
		bool bOppHasEyes = true;
		EMode Mode = EMode::BOf3;
		bool GameOver = false;
		int Round = 1;
};
