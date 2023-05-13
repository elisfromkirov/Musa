#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "../Attribute/AttributeInterface.h"

#include "AttributesComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MUSA_API UAttributesComponent final : public UActorComponent
{
	GENERATED_BODY()

public:
	UAttributesComponent();

	~UAttributesComponent() override;

	template <typename TAttribute>
	bool Has();

	template <typename TAttribute>
	TAttribute* Get();

	template <typename TAttribute>
	void Add();

	template <typename TAttribute>
	void Remove();

private:
	typedef TArray<FAttributeInterface>::SizeType SizeType;

private:
	template <typename TAttribute>
	SizeType Find();

private:
	TArray<FAttributeInterface*> Attributes;
};

template <typename TAttribute>
bool UAttributesComponent::Has()
{
	auto Index = Find<TAttribute>();
	if (Index != Attributes.Num())
	{
		return true;
	}
	return false;
}

template <typename TAttribute>
TAttribute* UAttributesComponent::Get()
{
	auto Index = Find<TAttribute>();
	if (Index != Attributes.Num())
	{
		return static_cast<TAttribute*>(Attributes[Index]);
	}
	return nullptr;
}

template <typename TAttribute>
void UAttributesComponent::Add()
{
	auto Index = Find<TAttribute>();
	if (Index == Attributes.Num())
	{
		Attributes.Add(new TAttribute());
	}
}

template <typename TAttribute>
void UAttributesComponent::Remove()
{
	auto Index = Find<TAttribute>();
	if (Index != Attributes.Num())
	{
		delete Attribute[Index];
		Attributes.RemoveAt(Index);
	}
}

template <typename TAttribute>
UAttributesComponent::SizeType UAttributesComponent::Find()
{
	for (SizeType Index = 0; Index < Attributes.Num(); ++Index)
	{
		auto* Attribute = Attributes[Index];
		if (Attribute->GetTag() == TAttribute::GetStaticTag())
		{
			return Index;
		}
	}
	return Attributes.Num();
}