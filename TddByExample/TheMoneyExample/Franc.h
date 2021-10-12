#pragma once
#include "Money.h"

class Franc :public Money
{
public:
	explicit Franc(int amount) :Money(amount)
	{
	}

	Money* times(int multiplier) const override
	{
		return new Franc(amount * multiplier);
	}
};