#pragma once

class Dollar
{
private:
	int amount = 0;
public:
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