#include "Dollar.h"
#include "Franc.h"
#include "Sum.h"
#include "Bank.h"

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

Money* Money::reduce(const Bank* bank, const char* to) const
{
	auto rate = bank->rate(currency.c_str(), to);
	return new Money(amount / rate, to);
}