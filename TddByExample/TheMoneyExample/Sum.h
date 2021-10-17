#pragma once
#include <memory>
#include "Money.h"

class Sum :public Expression
{
public:
	std::unique_ptr<Money> augend = nullptr;
	std::unique_ptr<Money> addend = nullptr;
	Sum(const Money* augend, const Money* addend)
	{
		this->augend.reset(new Money(*augend));
		this->addend.reset(new Money(*addend));
	}

	Money* reduce(const Bank* bank, const char* to) const override;
};
