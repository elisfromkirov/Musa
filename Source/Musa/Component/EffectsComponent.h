#pragma once

#include "CoreMinimal.h"

#include "Components/ActorComponent.h"

#include "EffectsComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MUSA_API UEffectsComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UEffectsComponent();
};