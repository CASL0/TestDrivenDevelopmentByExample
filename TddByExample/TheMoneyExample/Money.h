#pragma once
#include <typeinfo>
#include <string>

class Money
{
protected:
	int amount = 0;
	std::string currency;
public:
	explicit Money(int amount) : amount(amount) {}
	Money(int amount, const char* currency)
	{
		this->amount = amount;
		this->currency = currency ? currency : "";
	}
	virtual Money* times(int multiplier) const = 0;
	virtual bool operator==(const Money* money) const
	{
		return typeid(*this) == typeid(*money) && amount == money->amount;
	}

	std::string Currency() const
	{
		return currency;
	}

	static Money* dollar(int amount);
	static Money* franc(int amount);
};