#include "Armor.h"

EAttributeTag FArmor::GetStaticTag()
{
	return EAttributeTag::Armor;
}

FArmor::FArmor()
{
}

EAttributeTag FArmor::GetTag() const
{
	return EAttributeTag::Armor;
}

int FArmor::GetValue() const
{
	return Value;
}

void FArmor::SetValue(int NewValue)
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

int FArmor::GetMaxValue() const
{
	return MaxValue;
}

void FArmor::SetMaxValue(int NewMaxValue)
{
	if (Value > NewMaxValue)
	{
		Value = NewMaxValue;
	}

	MaxValue = NewMaxValue;
}