#pragma once

class Franc
{
private:
	int amount = 0;
public:
	explicit Franc(int amount) :amount(amount)
	{
	}

	Franc times(int multiplier) const
	{
		return Franc(amount * multiplier);;
	}

	bool operator==(const Franc& dollar) const
	{
		return amount == dollar.amount;
	}
};