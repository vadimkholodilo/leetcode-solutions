#include "pch.h"
#include "unique_number_of_occurrences.h"
using namespace std;

namespace LeetcodeSolutions {
	TEST(UniqueNumberOfOccurrences, ShouldReturnTrueIfNumsArrayContains1Item) {
		vector<int> nums = { 1 };
		bool expected = true;
		bool actual = Solution().uniqueOccurrences(nums);
		EXPECT_EQ(expected, actual);
	}

	TEST(UniqueNumberOfOccurrences, ShouldReturnTrue) {
		vector<int> nums = { 1,2,2,1,1,3 };
		bool expected = true;
		bool actual = Solution().uniqueOccurrences(nums);
		EXPECT_EQ(expected, actual);
	}

	TEST(UniqueNumberOfOccurrences, ShouldReturnFalse) {
		vector<int> nums = { 1,2 };
		bool expected = false;
		bool actual = Solution().uniqueOccurrences(nums);
		EXPECT_EQ(expected, actual);
	}


}