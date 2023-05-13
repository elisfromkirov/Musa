#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "../Component/AttributesComponent.h"
#include "../Component/EffectsComponent.h"

#include "GameCharacter.generated.h"

UCLASS()
class MUSA_API AGameCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AGameCharacter();

	UAttributesComponent* GetAttributes();

	UEffectsComponent* GetEffects();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UAttributesComponent* Attributes;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UEffectsComponent* Effects;
};