#include "Dollar.h"
#include "Franc.h"
#include "Sum.h"

Expression* Money::operator+(const Money* added) const
{
	return new Sum(this, added);
}

Money* Money::dollar(int amount)
{
	return new Money(amount, "USD");
}

Money* Money::franc(int amount)
{
	return new Money(amount, "CHF");
}

Money* Money::reduce(const char* to) const
{
	return new Money(amount, currency.c_str());
}