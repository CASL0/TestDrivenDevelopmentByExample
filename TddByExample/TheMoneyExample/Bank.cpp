#include "Bank.h"
#include "Sum.h"

Money* Bank::reduce(const Expression* source, const char* to) const
{
	return source->reduce(this, to);
}

void Bank::addRate(const char* from, const char* to, int rate)
{
	rates[{ from, to }] = rate;
}

int Bank::rate(const char* from, const char* to) const
{
	if (_stricmp(from, to) == 0)
	{
		return 1;
	}
	return rates.at({ from,to });
}