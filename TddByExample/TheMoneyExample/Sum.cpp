#include "Sum.h"

Money* Sum::reduce(const Bank* bank, const char* to) const
{
	auto amount = augend->amount + addend->amount;
	return new Money(amount, to);
}