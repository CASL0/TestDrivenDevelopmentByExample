#pragma once
class Money;

class Expression
{
public:
	virtual Money* reduce(const char* to) const = 0;
};