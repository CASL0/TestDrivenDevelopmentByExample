#include "Dollar.h"
#include "Franc.h"

Money* Money::operator+(const Money* added) const
{
	return new Money(amount + added->amount, currency.c_str());
}

Money* Money::dollar(int amount)
{
	return new Money(amount, "USD");
}

Money* Money::franc(int amount)
{
	return new Money(amount, "CHF");
}