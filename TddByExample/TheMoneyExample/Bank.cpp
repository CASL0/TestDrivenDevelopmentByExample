#include "Bank.h"
#include "Sum.h"

Money* Bank::reduce(const Expression* source, const char* to) const
{
	return source->reduce(to);
}