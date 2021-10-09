#include <gtest/gtest.h>
#include "Dollar.h"

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
	ASSERT_EQ(Dollar(10), five.times(2));
	ASSERT_EQ(Dollar(15), five.times(3));
}

TEST_F(MoneyTest, TestEquality)
{
	ASSERT_TRUE(Dollar(5) == Dollar(5));
	ASSERT_FALSE(Dollar(5) == Dollar(6));
}