#pragma once

class Dollar
{
public:
	int amount = 0;

	explicit Dollar(int amount) :amount(amount)
	{
	}

	void times(int multiplier)
	{
		amount *= multiplier;
	}
};