#include "Health.h"

EAttributeTag FHealth::GetStaticTag()
{
	return EAttributeTag::Health;
}

FHealth::FHealth()
{
}

EAttributeTag FHealth::GetTag() const
{
	return EAttributeTag::Health;
}

int FHealth::GetValue() const
{
	return Value;
}

void FHealth::SetValue(int NewValue)
{
	if (NewValue <= MaxValue)
	{
		Value = NewValue;
	}
	else
	{
		Value = MaxValue;
	}
}

int FHealth::GetMaxValue() const
{
	return MaxValue;
}

void FHealth::SetMaxValue(int NewMaxValue)
{
	if (Value > NewMaxValue)
	{
		Value = NewMaxValue;
	}

	MaxValue = NewMaxValue;
}