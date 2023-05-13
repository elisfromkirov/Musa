#pragma once

#include "CoreMinimal.h"

#include "AttributeInterface.h"

class FMana final : public FAttributeInterface
{
public:
	static EAttributeTag GetStaticTag();

public:
	FMana();

	EAttributeTag GetTag() const override;

	int GetValue() const;

	void SetValue(int NewValue);

	int GetMaxValue() const;

	void SetMaxValue(int NewMaxValue);

private:
	int Value;
	int MaxValue;
};