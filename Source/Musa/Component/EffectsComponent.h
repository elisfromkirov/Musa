#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "../Effect/EffectInterface.h"

#include "EffectsComponent.generated.h"

class AGameCharacter;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MUSA_API UEffectsComponent final : public UActorComponent
{
	GENERATED_BODY()

public:
	template <typename TEffect>
	bool Has();

	template <typename TEffect>
	TEffect* Get();

	template <typename TEffect>
	void Add();

	template <typename TEffect>
	void Remove();

	void OnTick(float DeltaTime, AGameCharacter* GameCharacter);

private:
	typedef TArray<FEffectInterface>::SizeType SizeType;

private:
	template <typename TEffect>
	SizeType Find();

private:
	TArray<FEffectInterface*> Attributes;
};

template <typename TEffect>
bool UEffectsComponent::Has()
{
	auto Index = Find<TEffect>();
	if (Index != Attributes.Num())
	{
		return true;
	}
	return false;
}

template <typename TEffect>
TEffect* UEffectsComponent::Get()
{
	auto Index = Find<TEffect>();
	if (Index != Attributes.Num())
	{
		return static_cast<TEffect*>(Attributes[Index]);
	}
	return nullptr;
}

template <typename TEffect>
void UEffectsComponent::Add()
{
	auto Index = Find<TEffect>();
	if (Index == Attributes.Num())
	{
		Attributes.Add(new TEffect());
	}
}

template <typename TEffect>
void UEffectsComponent::Remove()
{
	auto Index = Find<TEffect>();
	if (Index != Attributes.Num())
	{
		delete Attribute[Index];
		Attributes.RemoveAt(Index);
	}
}

template <typename TEffect>
UEffectsComponent::SizeType UEffectsComponent::Find()
{
	for (SizeType Index = 0; Index < Attributes.Num(); ++Index)
	{
		auto* Attribute = Attributes[Index];
		if (Attribute->GetTag() == TEffect::GetStaticTag())
		{
			return Index;
		}
	}
	return Attributes.Num();
}