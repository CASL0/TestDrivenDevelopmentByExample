#pragma once

class Dollar
{
public:
	int amount = 0;

	explicit Dollar(int amount) :amount(amount)
	{
	}

	Dollar times(int multiplier)
	{
		return Dollar(amount * multiplier);;
	}
};