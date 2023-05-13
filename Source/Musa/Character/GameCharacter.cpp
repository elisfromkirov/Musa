#include "GameCharacter.h"

AGameCharacter::AGameCharacter()
{
	Attributes = CreateDefaultSubobject< UAttributesComponent>(TEXT("Attributes"));

	Effects = CreateDefaultSubobject<UEffectsComponent>(TEXT("Effects"));
}

UAttributesComponent* AGameCharacter::GetAttributes()
{
	return Attributes;
}

UEffectsComponent* AGameCharacter::GetEffects()
{
	return Effects;
}