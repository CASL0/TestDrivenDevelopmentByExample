#pragma once
#include "Money.h"

class Dollar :public Money
{
public:
	explicit Dollar(int amount) :Money(amount)
	{
	}

	Dollar times(int multiplier) const
	{
		return Dollar(amount * multiplier);
	}
};