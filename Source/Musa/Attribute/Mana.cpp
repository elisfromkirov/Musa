#include "Mana.h"

EAttributeTag FMana::GetStaticTag()
{
	return EAttributeTag::Mana;
}

FMana::FMana()
{
}

EAttributeTag FMana::GetTag() const
{
	return EAttributeTag::Mana;
}

int FMana::GetValue() const
{
	return Value;
}

void FMana::SetValue(int NewValue)
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

int FMana::GetMaxValue() const
{
	return MaxValue;
}

void FMana::SetMaxValue(int NewMaxValue)
{
	if (Value > NewMaxValue)
	{
		Value = NewMaxValue;
	}

	MaxValue = NewMaxValue;
}