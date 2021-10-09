#pragma once
#include <any>

class Dollar
{
public:
	int amount = 0;

	explicit Dollar(int amount) :amount(amount)
	{
	}

	Dollar times(int multiplier) const
	{
		return Dollar(amount * multiplier);;
	}

	bool operator==(const Dollar& dollar) const
	{
		return amount == dollar.amount;
	}
};