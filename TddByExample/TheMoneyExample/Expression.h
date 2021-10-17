#pragma once
class Money;
class Bank;

class Expression
{
public:
	virtual Money* reduce(const Bank* bank, const char* to) const = 0;
};