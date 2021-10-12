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
	Money* times(int multiplier) const
	{
		return new Money(amount * multiplier, currency.c_str());
	}
	virtual bool operator==(const Money* money) const
	{
		return amount == money->amount && Currency() == money->Currency();
	}

	std::string Currency() const
	{
		return currency;
	}

	static Money* dollar(int amount);
	static Money* franc(int amount);
};