#pragma once

#include "CoreMinimal.h"

#include "GameObject.h"

#include "HealPotion.generated.h"

UCLASS()
class MUSA_API AHealPotion : public AGameObject
{
	GENERATED_BODY()

protected:
	void OnHitGameCharacter(AGameCharacter* GameCharacter) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Value;
};
