#include "postfix.h"
#include <gtest.h>

TEST(TPostfix, can_create_postfix)
{
  ASSERT_NO_THROW(TPostfix p);
}
TEST(TPostfix, can_create_right_postfix)
{
	TPostfix expr("2+3");
	expr.ToPostfix();
	EXPECT_EQ("23+", expr.GetPostfix());
}

TEST(TPostfix, can_add_nombers)
{
	TPostfix expr("2+3");
	expr.ToPostfix();
	EXPECT_EQ(5, expr.Calculate());
}
TEST(TPostfix, can_substract_nombers)
{
	TPostfix expr("2-3");
	expr.ToPostfix();
	EXPECT_EQ(-1, expr.Calculate());
}
TEST(TPostfix, can_multiply_nombers)
{
	TPostfix expr("2*3");
	expr.ToPostfix();
	EXPECT_EQ(6, expr.Calculate());
}
TEST(TPostfix, can_divide_nombers)
{
	TPostfix expr("6/2");
	expr.ToPostfix();
	EXPECT_EQ(3, expr.Calculate());
}
TEST(TPostfix, can_divide_nombers_on_itselfs)
{
	TPostfix expr("6/6");
	expr.ToPostfix();
	EXPECT_EQ(1, expr.Calculate());
}
TEST(TPostfix, trow_when_divide_on_zero)
{
	ASSERT_ANY_THROW(TPostfix expr("3/0"));
}
TEST(TPostfix, trow_when_see_incorrect_symbol)
{
	TPostfix expr("5:2");
	ASSERT_ANY_THROW(expr.ToPostfix());
}
TEST(TPostfix, get_postfix_with_MUL)
{
	TPostfix x("1*(1+1)");

	x.ToPostfix();
	EXPECT_EQ("111+*", x.GetPostfix());
}

TEST(TPostfix, get_postfix_with_MUL2)
{
	TPostfix x("2+1*1");

	x.ToPostfix();
	EXPECT_EQ("211*+", x.GetPostfix());
}

TEST(TPostfix, get_postfix_with_MUL3)
{
	TPostfix x("2+1*1/2");
	x.ToPostfix();

	EXPECT_EQ("211*2/+", x.GetPostfix());
}

TEST(TPostfix, get_postfix_with_MUL4)
{
	TPostfix x("(2+1)*1/2");
	x.ToPostfix();

	EXPECT_EQ("21+1*2/", x.GetPostfix());
}
TEST(TPostfix, can_calculate)
{
	TPostfix x("1/(7-(1+1))*3-(2+(1+1))*1/(7-(2+1))*3-(2+(1+1))*(1/(7-(1+1))*3-(2+(1+1))+1/(7-(1+1))*3-(2+(1+1)))");
	x.ToPostfix();
	EXPECT_EQ(24.8, x.Calculate());
}
TEST(TPostfix, trow_when_see_incorrect_string)
{
	TPostfix expr("vi ka");
	ASSERT_ANY_THROW(expr.ToPostfix());
}