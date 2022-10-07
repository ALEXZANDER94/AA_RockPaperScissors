#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Components/SpotLightComponent.h"
#include "Components/StaticMeshComponent.h"
#include "RPSType.h"
#include "RPSChoice.generated.h"

UCLASS()
class ROCKPAPERSCISSORS_API ARPSChoice : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ARPSChoice();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBoxComponent* HitBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* RPSMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EType AdvantageOver;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EType Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USpotLightComponent* RPSLight;

	UFUNCTION(BlueprintImplementableEvent)
	void ToggleIntensity(float target);

	void ShowOutline();
	void HideOutline();

	EType GetType() { return Type; };

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
