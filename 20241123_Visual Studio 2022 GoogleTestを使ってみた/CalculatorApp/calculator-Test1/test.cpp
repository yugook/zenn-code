#include "pch.h"
#include "../CalculatorApp/calculator.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(addCaseTest1, addTest)
{
	calculator cal;
	EXPECT_EQ(cal.add(1, 2), 3);
}