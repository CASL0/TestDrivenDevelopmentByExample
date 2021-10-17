#pragma once
#include "Money.h"
#include <map>
#include <string>
#include <utility>

class Bank
{
private:
	std::map<std::pair<std::string, std::string>, int> rates;
public:
	Money* reduce(const Expression* source, const char* to) const;
	void addRate(const char* from, const char* to, int rate);
	int rate(const char* from, const char* to) const;
};