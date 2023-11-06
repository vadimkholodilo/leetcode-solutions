#include "pch.h"
#include "reverse_vowels_of_a_string.h"
using namespace std;

namespace LeetcodeSolutions {
	TEST(ReverseVowelsInAString, ShouldReturnEmptyStringIfStringInputIsEmpty) {
		string s = "";
		string expected = "";
		string actual = Solution().reverseVowels(s);
		EXPECT_EQ(expected, actual);
	}

	TEST(ReverseVowelsInAString, ShouldReturnSameStringIfStringInputHasNoVowels) {
		string s = "bcdfghjklmnpqrstvwxyz";
		string expected = "bcdfghjklmnpqrstvwxyz";
		string actual = Solution().reverseVowels(s);
		EXPECT_EQ(expected, actual);
	}

	TEST(ReverseVowelsInAString, ShouldReturnSameStringIfStringInputHasOnlyOneVowel) {
		string s = "a";
		string expected = "a";
		string actual = Solution().reverseVowels(s);
		EXPECT_EQ(expected, actual);
	}

	TEST(ReverseVowelsInAString, ShouldReturnReversedString) {
		string s = "hello";
		string expected = "holle";
		string actual = Solution().reverseVowels(s);
		EXPECT_EQ(expected, actual);
	}
}