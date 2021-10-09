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
	five.times(2);
	ASSERT_EQ(10, five.amount);
}