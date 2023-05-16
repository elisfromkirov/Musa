#include "EffectInterface.h"

#include "../Character/GameCharacter.h"

FEffectInterface::~FEffectInterface()
{
}

EEffectTag FEffectInterface::GetTag() const
{
	return EEffectTag::None;
}

void FEffectInterface::OnTick(float DetlaTime, AGameCharacter* GameCharacter)
{
}