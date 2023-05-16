#pragma once

#include "CoreMinimal.h"

class AGameCharacter;

enum class EEffectTag
{
	None,
	Death
};

class FEffectInterface
{
public:
	virtual ~FEffectInterface();

	virtual EEffectTag GetTag() const;

	virtual void OnTick(float DetlaTime, AGameCharacter* GameCharacter);
};