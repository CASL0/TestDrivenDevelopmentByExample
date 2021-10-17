#include <gtest/gtest.h>
#include "Money.h"
#include "Bank.h"
#include "Sum.h"
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
	auto sum = std::unique_ptr<Expression>(*five + five.get());
	auto bank = std::make_unique<Bank>();
	std::unique_ptr<Money> reduced(bank->reduce(sum.get(), "USD"));
	ASSERT_EQ(*std::unique_ptr<Money>(Money::dollar(10)), reduced.get());
}

TEST_F(MoneyTest, TestPlusReturnsSum)
{
	std::unique_ptr<Money> five(Money::dollar(5));
	auto result = std::unique_ptr<Expression>(*five + five.get());
	auto sum = (Sum*)(result.get());
	ASSERT_EQ(*five, sum->augend.get());
	ASSERT_EQ(*five, sum->addend.get());
}

TEST_F(MoneyTest, TestReduceSum)
{
	std::unique_ptr<Expression> sum = std::make_unique<Sum>(std::unique_ptr<Money>(Money::dollar(3)).get(), std::unique_ptr<Money>(Money::dollar(4)).get());
	auto bank = std::make_unique<Bank>();
	std::unique_ptr<Money> result(bank->reduce(sum.get(), "USD"));
	ASSERT_EQ(*std::unique_ptr<Money>(Money::dollar(7)), result.get());
}

TEST_F(MoneyTest, TestReduceMoney)
{
	auto bank = std::make_unique<Bank>();
	std::unique_ptr<Money> result(bank->reduce(std::unique_ptr<Money>(Money::dollar(1)).get(), "USD"));
	ASSERT_EQ(*std::unique_ptr<Money>(Money::dollar(1)), result.get());
}

TEST_F(MoneyTest, TestReduceMoneyDifferentCurrency)
{
	auto bank = std::make_unique<Bank>();
	bank->addRate("CHF", "USD", 2);
	std::unique_ptr<Money> result(bank->reduce(std::unique_ptr<Money>(Money::franc(2)).get(), "USD"));
	ASSERT_EQ(*std::unique_ptr<Money>(Money::dollar(1)), result.get());
}

TEST_F(MoneyTest, TestIdentityRate)
{
	ASSERT_EQ(1, std::unique_ptr<Bank>(new Bank)->rate("USD", "USD"));
}