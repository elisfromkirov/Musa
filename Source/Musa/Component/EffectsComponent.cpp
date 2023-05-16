#include "EffectsComponent.h"

void UEffectsComponent::OnTick(float DeltaTime, AGameCharacter* GameCharacter)
{
	for (SizeType Index = 0; Index < Attributes.Num(); ++Index)
	{
		auto* Attribute = Attributes[Index];
		Attribute->OnTick(DeltaTime, GameCharacter);
	}
}