#include <gtest/gtest.h>
#include "Dollar.h"
#include "Franc.h"
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
	auto five = Dollar(5);
	ASSERT_EQ(Dollar(10), std::make_unique<Dollar>(five.times(2)).get());
	ASSERT_EQ(Dollar(15), std::make_unique<Dollar>(five.times(3)).get());
}

TEST_F(MoneyTest, TestEquality)
{
	ASSERT_TRUE(Dollar(5) == std::make_unique<Dollar>(5).get());
	ASSERT_FALSE(Dollar(5) == std::make_unique<Dollar>(6).get());
	ASSERT_TRUE(Franc(5) == std::make_unique<Franc>(5).get());
	ASSERT_FALSE(Franc(5) == std::make_unique<Franc>(6).get());

}

TEST_F(MoneyTest, TestFrancMultiplication)
{
	auto five = Franc(5);
	ASSERT_EQ(Franc(10), std::make_unique<Franc>(five.times(2)).get());
	ASSERT_EQ(Franc(15), std::make_unique<Franc>(five.times(3)).get());

}