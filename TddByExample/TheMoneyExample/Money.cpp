#include "Dollar.h"
#include "Franc.h"

Money* Money::dollar(int amount)
{
	return new Dollar(amount);
}

Money* Money::franc(int amount)
{
	return new Franc(amount);
}