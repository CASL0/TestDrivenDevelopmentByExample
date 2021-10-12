#pragma once
#include "Money.h"

class Franc :public Money
{
public:
	Franc(int amount, const char* currency) :Money(amount, currency)
	{
	}

	Money* times(int multiplier) const override;
};