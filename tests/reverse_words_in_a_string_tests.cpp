#include "pch.h"
#include "reverse_words_in_a_string.h"
using namespace std;

namespace LeetcodeSolutions {
	TEST(ReverseWordsInAString, ShouldReturnTheSameStringIftheInputStringContainsOneWord) {
		string s = "test";
		string expected = "test";
		string actual = Solution().reverseWords(s);
		EXPECT_EQ(expected, actual);
	}

	TEST(ReverseWordsInAString, ShouldReturnWordsInReversedOrderSDoesNotHaveExtraSpaces) {
		string s = "the sky is blue";
		string expected = "blue is sky the";
		string actual = Solution().reverseWords(s);
		EXPECT_EQ(expected, actual);
	}

	TEST(ReverseWordsInAString, ShouldReturnWordsInReversedOrderSHasExtraSpacesAtTheBeginningAndTheEndOfTheString) {
		string s = "  hello world  ";
		string expected = "world hello";
		string actual = Solution().reverseWords(s);
		EXPECT_EQ(expected, actual);
	}

	TEST(ReverseWordsInAString, ShouldReturnWordsInReversedOrderSHasExtraSpacesBetweenWords) {
		string s = "a good   example";
		string expected = "example good a";
		string actual = Solution().reverseWords(s);
		EXPECT_EQ(expected, actual);
	}
}