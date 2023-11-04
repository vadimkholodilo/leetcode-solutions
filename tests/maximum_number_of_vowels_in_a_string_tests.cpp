#include "pch.h"
#include "maximum_number_of_vowels_in_a_string.h"
using namespace std;
namespace LeetcodeSolutions {
	TEST(MaximumVowelsInAString, ShouldReturn0IfThereAreNoVowels) {
		string s = "bcdfg";
		int k = 1;
		int expected = 0;
		int actual = Solution().maxVowels(s, k);
		EXPECT_EQ(expected, actual);
	}

	TEST(MaximumVowelsInAString, ShouldReturn3IfThereIsThreeVowels) {
		string s = "abciiidef";
		int k = 3;
		int expected = 3;
		int actual = Solution().maxVowels(s, k);
		EXPECT_EQ(expected, actual);
	}

}