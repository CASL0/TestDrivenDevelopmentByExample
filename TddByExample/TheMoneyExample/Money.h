#pragma once
#include "Expression.h"
#include <typeinfo>
#include <string>

class Money :public Expression
{
protected:
	std::string currency;
public:
	int amount = 0;
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
	virtual Expression* operator+(const Money* added) const;

	std::string Currency() const
	{
		return currency;
	}

	Money* reduce(const char* to) const override;

	static Money* dollar(int amount);
	static Money* franc(int amount);
};