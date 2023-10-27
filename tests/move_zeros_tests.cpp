#include "pch.h"
#include "move_zeros.h"
using namespace std;
namespace LeetcodeSolutions {
	TEST(MoveZeros, ShouldNotFailIfNumsArrayIsEmpty) {
		vector<int> nums = {};
		vector<int> expected = {};
		Solution().moveZeros(nums);
		EXPECT_EQ(nums, expected);
	}

	TEST(MoveZeros, ShouldLeaveNumsArrayUnmodifiedIfItContainsAllZeros) {
		vector<int> nums = { 0, 0, 0, 0, 0 };
		vector<int> expected = { 0, 0, 0, 0, 0 };
		Solution().moveZeros(nums);
		EXPECT_EQ(nums, expected);
	}

	TEST(MoveZeros, ShouldLeaveNumsArrayUnmodifiedIfItContainsNoZeros) {
		vector<int> nums = { 1, 2, 3, 4, 5 };
		vector<int> expected = { 1, 2, 3, 4, 5 };
		Solution().moveZeros(nums);
		EXPECT_EQ(nums, expected);
	}

	TEST(MoveZeros, ShouldMoveAllZerosToTheEndOfTheArray) {
		vector<int> nums = { 0, 1, 0, 3, 12 };
		vector<int> expected = { 1, 3, 12, 0, 0 };
		Solution().moveZeros(nums);
		EXPECT_EQ(nums, expected);
	}
}