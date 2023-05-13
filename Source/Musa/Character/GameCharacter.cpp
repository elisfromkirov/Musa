#include "GameCharacter.h"

AGameCharacter::AGameCharacter()
{
	Attributes = CreateDefaultSubobject< UAttributesComponent>(TEXT("Attributes"));

	Effects = CreateDefaultSubobject<UEffectsComponent>(TEXT("Effects"));
}