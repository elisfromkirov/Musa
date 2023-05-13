#pragma once

#include "CoreMinimal.h"

enum class EAttributeTag
{
	None,
	Health,
	Armour,
	Mana
};

class FAttributeInterface
{
public:
	virtual ~FAttributeInterface();

	virtual EAttributeTag GetTag() const;
};