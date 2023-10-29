#include "pch.h"
#include "valid_parenthesis.h"
using namespace std;
namespace LeetcodeSolutions {
	TEST(ValidParenthesis, ShouldReturnTrueIfEmptyString) {
		string s = "";
		bool expected = true;
		bool actual = Solution().isValid(s);
		EXPECT_EQ(expected, actual);
	}
	TEST(ValidParenthesis, ShouldReturnFalseIfOnlyOpenParenthesis) {
		string s = "(";
		bool expected = false;
		bool actual = Solution().isValid(s);
		EXPECT_EQ(expected, actual);
	}
	TEST(ValidParenthesis, ShouldReturnFalseIfOnlyCloseParenthesis) {
		string s = ")";
		bool expected = false;
		bool actual = Solution().isValid(s);
		EXPECT_EQ(expected, actual);
	}
	TEST(ValidParenthesis, ShouldReturnTrueIfOneOpenAndOneCloseParenthesis) {
		string s = "()";
		bool expected = true;
		bool actual = Solution().isValid(s);
		EXPECT_EQ(expected, actual);
	}
	TEST(ValidParenthesis, ShouldReturnTrueIfTwoOpenAndTwoCloseParenthesis) {
		string s = "()()";
		bool expected = true;
		bool actual = Solution().isValid(s);
		EXPECT_EQ(expected, actual);
	}
	TEST(ValidParenthesis, ShouldReturnTrueIfTwoOpenAndTwoCloseParenthesisInDifferentOrder) {
		string s = "(())";
		bool expected = true;
		bool actual = Solution().isValid(s);
		EXPECT_EQ(expected, actual);
	}
	TEST(ValidParenthesis, ShouldReturnTrueIfThreeOpenAndThreeCloseParenthesisInDifferentOrder) {
		string s = "(()())";
		bool expected = true;
		bool actual = Solution().isValid(s);
		EXPECT_EQ(expected, actual);
	}
	TEST(ValidParenthesis, ShouldReturnTrueIfThreeOpenAndThreeCloseParenthesisInDifferentOrder2) {
		string s = "((()))";
		bool expected = true;
		bool actual = Solution().isValid(s);
		EXPECT_EQ(expected, actual);
	}
	TEST(ValidParenthesis, ShouldReturnFalseIfThreeOpenAndThreeCloseParenthesisInDifferentOrder) {
		string s = "(()))";
		bool expected = false;
		bool actual = Solution().isValid(s);
		EXPECT_EQ(expected, actual);
	}
	TEST(ValidParenthesis, ShouldReturnFalseIfThreeOpenAndThreeCloseParenthesisInDifferentOrder2) {
		string s = "((())";
		bool expected = false;
		bool actual = Solution().isValid(s);
		EXPECT_EQ(expected, actual);
	}
}