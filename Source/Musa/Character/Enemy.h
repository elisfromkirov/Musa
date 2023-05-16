#pragma once

#include "CoreMinimal.h"

#include "GameCharacter.h"

#include "Enemy.generated.h"

UCLASS()
class MUSA_API AEnemy : public AGameCharacter
{
	GENERATED_BODY()

public:
	AEnemy();

protected:
	UFUNCTION(BlueprintCallable)
	void SetupHealth(int Value, int MaxValue);

protected:
	void Tick(float DeltaTime) override;
};