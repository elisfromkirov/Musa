#include "HealPotion.h"

#include "../Attribute/Health.h"

#include "../Character/GameCharacter.h"

void AHealPotion::OnHitGameCharacter(AGameCharacter* GameCharacter)
{
	UE_LOG(LogTemp, Display, TEXT("On heal potion quaffing"));

	auto Attributes = GameCharacter->GetAttributes();
	if (Attributes->Has<FHealth>())
	{
		auto Health = Attributes->Get<FHealth>();
		Health->SetValue(Health->GetValue() + Value);
		Destroy();
	}
}