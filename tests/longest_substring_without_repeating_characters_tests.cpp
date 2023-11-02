#include "pch.h"
#include "longest_substring_without_repeating_characters.h"
using namespace std;
namespace LeetcodeSolutions {
	TEST(LongestSubstringWithoutRepeatingCharacters, ShouldReturn0IfInputStringIsEmpty) {
		string s = "";
		int expected = 0;
		int actual = Solution().lengthOfLongestSubstring(s);
		EXPECT_EQ(expected, actual);
	}

	TEST(LongestSubstringWithoutRepeatingCharacters, ShouldReturn1IfInputStringIsSingleCharacter) {
		string s = "a";
		int expected = 1;
		int actual = Solution().lengthOfLongestSubstring(s);
		EXPECT_EQ(expected, actual);
	}

	TEST(LongestSubstringWithoutRepeatingCharacters, ShouldReturn1IfInputStringIsSingleCharacterRepeated) {
		string s = "aaaa";
		int expected = 1;
		int actual = Solution().lengthOfLongestSubstring(s);
		EXPECT_EQ(expected, actual);
	}

	TEST(LongestSubstringWithoutRepeatingCharacters, ShouldReturn3IfInputStringContains3NonRepeatedCharacters) {
		string s = "abcabcbb";
		int expected = 3;
		int actual = Solution().lengthOfLongestSubstring(s);
		EXPECT_EQ(expected, actual);
	}

}