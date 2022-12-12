#include "Stack.h"

#include <gtest.h>

TEST(TStack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(TStack<int> st(5));
}


TEST(TStack, throws_when_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(TStack<int> st(-5));
}

TEST(TStack, can_set_and_get_last_element)
{
	TStack<int> st(5);
	st.Push(7);
	EXPECT_EQ(7, st.Pop());
}

TEST(TStack, can_set_and_check_last_element)
{
	TStack<int> st(5);
	st.Push(21);
	EXPECT_EQ(21, st.Top());
}

TEST(TStack, can_get_information_that_empty_stack_is_empty)
{
	TStack<int> st(5);
	EXPECT_EQ(true, st.IsEmpty());
}

TEST(TStack, can_get_information_that_full_stack_is_full)
{
	TStack<int> st(1);
	st.Push(21);
	EXPECT_EQ(true, st.IsFull());
}