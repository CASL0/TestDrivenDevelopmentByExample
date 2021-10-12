#include "Dollar.h"
#include "Franc.h"

Money* Money::dollar(int amount)
{
	return new Money(amount, "USD");
}

Money* Money::franc(int amount)
{
	return new Money(amount, "CHF");
}