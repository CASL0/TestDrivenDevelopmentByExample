#pragma once
#include "Money.h"

class Dollar :public Money
{
public:
	Dollar(int amount, const char* currency) :Money(amount, currency)
	{
	}

	Money* times(int multiplier) const override;
};