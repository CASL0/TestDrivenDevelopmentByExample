#include "Franc.h"

Money* Franc::times(int multiplier) const
{
	return Money::franc(amount * multiplier);
}