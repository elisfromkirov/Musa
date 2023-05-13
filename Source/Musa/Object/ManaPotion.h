#pragma once

#include "CoreMinimal.h"

#include "GameObject.h"

#include "ManaPotion.generated.h"

UCLASS()
class MUSA_API AManaPotion : public AGameObject
{
	GENERATED_BODY()

protected:
	void OnHitGameCharacter(AGameCharacter* GameCharacter) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Value;
};
