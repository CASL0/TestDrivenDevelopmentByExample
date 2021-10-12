#include "Dollar.h"

Money* Dollar::times(int multiplier) const
{
	return Money::dollar(amount * multiplier);
}
