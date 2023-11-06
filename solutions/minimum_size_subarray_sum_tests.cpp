#include "pch.h"
#include "minimum_size_subarray_sum.h"
using namespace std;

namespace LeetcodeSolutions {
TEST(MinimSubarraySum, ShouldReturn0IfNumsArrayIsEmpty) {
	vector<int> nums = {};
	int target = 1;
	int expected = 0;
	int actual = Solution().minSubArrayLen(target, nums);
	EXPECT_EQ(expected, actual);
}

TEST(MinimSubarraySum, ShouldReturn1IfNumsArrayContainsNumbersWhichSumUpToTarget) {
	vector<int> nums = { 1, 2, 3, 4, 5 };
	int target = 5;
	int expected = 1;
	int actual = Solution().minSubArrayLen(target, nums);
	EXPECT_EQ(expected, actual);
}
}