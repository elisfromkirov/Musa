#pragma once

#include "CoreMinimal.h"

enum class EAttributeTag
{
	None,
	Health,
	Mana,
	Armor
};

class FAttributeInterface
{
public:
	virtual ~FAttributeInterface();

	virtual EAttributeTag GetTag() const;
};