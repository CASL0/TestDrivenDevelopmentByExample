#pragma once
#include <typeinfo>

class Money
{
protected:
	int amount = 0;
public:
	explicit Money(int amount) : amount(amount) {}
	virtual Money* times(int multiplier) const = 0;
	virtual bool operator==(const Money* money) const
	{
		return typeid(*this) == typeid(*money) && amount == money->amount;
	}

	static Money* dollar(int amount);
	static Money* franc(int amount);
};