#pragma once

class Money
{
protected:
	int amount = 0;
public:
	explicit Money(int amount) : amount(amount) {}
	virtual bool operator==(const Money* money) const
	{
		return amount == money->amount;
	}

};