#include "AttributeInterface.h"

FAttributeInterface::~FAttributeInterface()
{
}

EAttributeTag FAttributeInterface::GetTag() const
{
	return EAttributeTag::None;
}