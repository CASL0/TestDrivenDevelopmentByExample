#pragma once
#include "Money.h"

class Bank
{
public:
	Money* reduce(const Expression* source, const char* to) const;
};