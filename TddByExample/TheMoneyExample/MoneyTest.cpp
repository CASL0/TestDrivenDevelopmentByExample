#include <gtest/gtest.h>
#include "Money.h"
#include "Bank.h"
#include <memory>

class MoneyTest :public::testing::Test
{
protected:
	void SetUp() override
	{
	}

	void TearDown() override
	{
	}
	
};

TEST_F(MoneyTest, TestMultiplication)
{
	auto five = std::unique_ptr<Money>(Money::dollar(5));
	ASSERT_EQ(*std::unique_ptr<Money>(Money::dollar(10)), std::unique_ptr<Money>(five->times(2)).get());
	ASSERT_EQ(*std::unique_ptr<Money>(Money::dollar(15)), std::unique_ptr<Money>(five->times(3)).get());
}

TEST_F(MoneyTest, TestEquality)
{
	ASSERT_TRUE(*std::unique_ptr<Money>(Money::dollar(5)) == std::unique_ptr<Money>(Money::dollar(5)).get());
	ASSERT_FALSE(*std::unique_ptr<Money>(Money::dollar(5)) == std::unique_ptr<Money>(Money::dollar(6)).get());
	ASSERT_FALSE(*std::unique_ptr<Money>(Money::franc(5)) == std::unique_ptr<Money>(Money::dollar(5)).get());
}

TEST_F(MoneyTest, TestCurrency)
{
	ASSERT_EQ("USD", Money::dollar(1)->Currency());
	ASSERT_EQ("CHF", Money::franc(1)->Currency());
}

TEST_F(MoneyTest, TestSimpleAddition)
{
	std::unique_ptr<Money> five(Money::dollar(5));
	auto sum = std::unique_ptr<Money>(*five + five.get());
	auto bank = std::make_unique<Bank>();
	std::unique_ptr<Money> reduced(bank->reduce(sum.get(), "USD"));
	ASSERT_EQ(*std::unique_ptr<Money>(Money::dollar(10)), reduced.get());
}