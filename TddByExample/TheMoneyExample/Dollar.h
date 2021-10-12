#pragma once
#include "Money.h"

class Dollar :public Money
{
public:
	explicit Dollar(int amount) :Money(amount)
	{
	}

	Money* times(int multiplier) const override
	{
		return new Dollar(amount * multiplier);
	}
};