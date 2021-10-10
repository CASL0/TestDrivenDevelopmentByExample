#pragma once
#include "Money.h"

class Franc :public Money
{
public:
	explicit Franc(int amount) :Money(amount)
	{
	}

	Franc times(int multiplier) const
	{
		return Franc(amount * multiplier);
	}
};