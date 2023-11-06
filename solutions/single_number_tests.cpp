#include "pch.h"
#include "single_number.h"
using namespace std;
namespace LeetcodeSolutions {
TEST(SingleNumber, ShouldReturn0IfNumsArrayIsEmpty) {
vector<int> nums = {};
int expected = 0;
int actual = Solution().singleNumber(nums);
EXPECT_EQ(expected, actual);
}
TEST(SingleNumber, ShouldReturnTheOnlyElementIfNumsArrayHasOnlyOneElement) {
vector<int> nums = { 1 };
int expected = 1;
int actual = Solution().singleNumber(nums);
EXPECT_EQ(expected, actual);
}
TEST(SingleNumber, ShouldReturnOneBecauseItIsPresentOnlyOnce) {
vector<int> nums = { 1, 2, 2 };
int expected = 1;
int actual = Solution().singleNumber(nums);
EXPECT_EQ(expected, actual);
}
}