#include "pch.h"
#include <vector>
#include "max_consecutive_ones.h"

using namespace std;
namespace LeetcodeSolutions {
TEST(MaxConsecutiveOnes, ShouldReturn0IfNumsArrayIsEmpty) {
	vector<int> nums = {};
	Solution solution;
	int result = solution.findMaxConsecutiveOnes(nums);
	EXPECT_EQ(result, 0);
}

TEST(MaxConsecutiveOnes, ShouldReturn1IfNumsArrayHasOnlyOne1) {
	vector<int> nums = { 1 };
	Solution solution;
int result = solution.findMaxConsecutiveOnes(nums);
	EXPECT_EQ(result, 1);
}

TEST(MaxConsecutiveOnes, ShouldReturn0IfNumsArrayContainsAllZeros) {
	vector<int> nums = { 0, 0, 0, 0, 0 };
	Solution solution;
	int result = solution.findMaxConsecutiveOnes(nums);
	EXPECT_EQ(result, 0);
}

TEST(MaxConsecutiveOnes, ShouldReturn5IfNumsArrayContains5Ones) {
	vector<int> nums = { 1, 1, 1, 1, 1 };
	Solution solution;
	int result = solution.findMaxConsecutiveOnes(nums);
	EXPECT_EQ(result, 5);
}

TEST(MaxConsecutiveOnes, ShouldReturn2IfNumsArrayContainsTwoConsecutiveOnes) {
	vector<int> nums = { 1, 1, 0, 1, 1 };
	Solution solution;
	int result = solution.findMaxConsecutiveOnes(nums);
	EXPECT_EQ(result, 2);
}

TEST(MaxConsecutiveOnes, ShouldReturn3IfNumsArrayConstains3Ones) {
	vector<int> nums = { 1,1,0,1,1,1 };
	Solution solution;
	int result = solution.findMaxConsecutiveOnes(nums);
	EXPECT_EQ(result, 3);
}
}