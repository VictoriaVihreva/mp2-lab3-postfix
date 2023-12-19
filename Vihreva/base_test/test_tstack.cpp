#include "stack.h"
#include <gtest.h>

TEST(TStack, can_create_stack_with_positive_length)
{
  ASSERT_NO_THROW(TStack<int> st(5));
}
TEST(TStack, cant_create_too_large_stack)
{
	ASSERT_ANY_THROW(TStack<int> m(MaxStackSize + 1));
}
TEST(TStack, throws_when_create_stack_with_zero_lenth)
{
	ASSERT_ANY_THROW(TStack<int> m(0));
}
TEST(TStack, throws_when_create_stack_with_negative_lenth)
{
	ASSERT_ANY_THROW(TStack<int> m(-1));
}
TEST(TStack, can_create_copyed_stack)
{
	TStack<int> s(10);
	ASSERT_NO_THROW(TStack<int> s1(s));
}
TEST(TStack, copied_stack_is_equal_to_source_one)
{
	TStack<int> s(3);
	for (int i = 0; i < s.size(); i++)
		s.Push(i);
	TStack<int> s1(s);
	EXPECT_EQ(s, s1);
}
TEST(TStack, copied_stack_has_its_own_memory)
{
	TStack<int> s(3);
	for (int i = 0; i < s.size(); i++)
		s.Push(i);
	TStack<int> s1(s);
	EXPECT_NE(&s, &s1);
}
TEST(TStack, can_get_size)
{
	TStack<int> s(5);
	EXPECT_EQ(5, s.size());
}
TEST(TStack, can_put_and_get_element)
{
	TStack<int> s(3);
	s.Push(2);
	EXPECT_EQ(2, s.Pop());
}
TEST(TStack, can_assign_stack_to_itself)
{
	TStack<int> s(4);
	ASSERT_NO_THROW(s = s);
}

TEST(TStack, can_assign_stacks_of_equal_size)
{
	TStack<int> s(3);
	for (int i = 0; i < s.size(); i++)
		s.Push(i);
	TStack<int> s1(3);
	s1 = s;
	EXPECT_EQ(s, s1);
}

TEST(TStack, assign_operator_change_stack_size)
{
	TStack<int> s(5);
	for (int i = 0; i < s.size(); i++)
		s.Push(i);
	TStack<int> s1(3);
	s1 = s;
	EXPECT_EQ(s.size(), s1.size());
}

TEST(TStack, can_assign_stacks_of_different_size)
{
	TStack<int> s(5);
	for (int i = 0; i < s.size(); i++)
		s.Push(i);
	TStack<int> s1(3);
	s1 = s;
	EXPECT_EQ(s, s1);
}

TEST(TStack, compare_equal_stacks_return_true)
{
	TStack<int> s(2);
	for (int i = 0; i < s.size(); i++)
		s.Push(i);
	TStack<int> s1(2);
	s1 = s;
	EXPECT_TRUE(s == s1);
}

TEST(TStack, compare_stack_with_itself_return_true)
{
	TStack<int> s(3);
	for (int i = 0; i < s.size(); i++)
		s.Push(i);
	EXPECT_TRUE(s == s);
}

TEST(TStack, stacks_with_different_size_are_not_equal)
{
	TStack<int> s1(5);
	TStack<int> s2(3);
	EXPECT_NE(s1, s2);
}

TEST(TStack, can_check_for_emptiness)
{
	TStack<int> s(3);
	EXPECT_TRUE(s.IsEmpty());
}
TEST(TStack, can_check_for_fullness)
{
	TStack<int> s(3);
	for (int i = 0; i < s.size(); i++)
		s.Push(i);
	EXPECT_TRUE(s.IsFull());
}
TEST(TStack, can_view_top_element)
{
	TStack<int> s(7);
	for (int i = 0; i < 3; i++)
		s.Push(i);
	EXPECT_EQ(2, s.ViewTop());
}