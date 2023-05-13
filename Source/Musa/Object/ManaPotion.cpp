#include "ManaPotion.h"

#include "../Attribute/Mana.h"

#include "../Character/GameCharacter.h"

void AManaPotion::OnHitGameCharacter(AGameCharacter* GameCharacter)
{
	UE_LOG(LogTemp, Display, TEXT("On mana potion quaffing"));

	auto Attributes = GameCharacter->GetAttributes();
	if (Attributes->Has<FMana>())
	{
		auto Mana = Attributes->Get<FMana>();
		Mana->SetValue(Mana->GetValue() + Value);
	}
}