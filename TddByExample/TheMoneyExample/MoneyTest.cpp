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

TEST_F(MoneyTest, Dollar)
{
	auto five = Dollar(5);
	Dollar product = five.times(2);
	ASSERT_EQ(10, product.amount);
	product = five.times(3);
	ASSERT_EQ(15, product.amount);
}