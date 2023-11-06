#include "pch.h"
#include "max_concecutive_ones_iii.h"
using namespace std;

namespace LeetcodeSolutions {
	TEST(MaxConcecutiveOnesIii, ShouldReturn0) {
		vector<int> nums = { 0,0,0,0 };
		int k = 0;
		int expected = 0;
		int actual = Solution().longestOnes(nums, k);
		EXPECT_EQ(expected, actual);
	}

	TEST(MaxConcecutiveOnesIii, ShouldReturn6) {
		vector<int> nums = { 1,1,1,0,0,0,1,1,1,1,0 };
		int k = 2;
		int expected = 6;
		int actual = Solution().longestOnes(nums, k);
		EXPECT_EQ(expected, actual);
	}

	TEST(MaxConcecutiveOnesIii, ShouldReturn10) {
		vector<int> nums = { 1,1,1,0,0,0,1,1,1,1,0 };
		int k = 3;
		int expected = 10;
		int actual = Solution().longestOnes(nums, k);
		EXPECT_EQ(expected, actual);
	}
}