#include "Death.h"

#include "../Attribute/Health.h"

#include "../Character/GameCharacter.h"

EEffectTag FDeath::GetStaticTag()
{
	return EEffectTag::Death;
}

EEffectTag FDeath::GetTag() const
{
	return EEffectTag::Death;
}

void FDeath::OnTick(float DeltaTime, AGameCharacter* GameCharacter)
{
	auto Attributes = GameCharacter->GetAttributes();
	if (Attributes->Has<FHealth>())
	{
		auto Health = Attributes->Get<FHealth>();
		if (Health->GetValue() == 0)
		{
			GameCharacter->Destroy();
		}
	}
}