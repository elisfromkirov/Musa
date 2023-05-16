#pragma once

#include "CoreMinimal.h"

#include "EffectInterface.h"

class FDeath : public FEffectInterface
{
public:
	static EEffectTag GetStaticTag();

public:
	EEffectTag GetTag() const override;

	void OnTick(float DeltaTime, AGameCharacter* GameCharacter) override;
};