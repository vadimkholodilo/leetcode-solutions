#include "pch.h"
#include "two_sum_ii_input_array_is_sorted.h"
using namespace std;

namespace LeetcodeSolutions {
	TEST(TwoSumIIInputArrayIsSorted, ShouldReturnAnEmptyVectorIfInputArrayIsEmpty) {
		vector<int> numbers = {};
		int target = 0;
		vector<int> expected = {};
		vector<int> actual = Solution().twoSum(numbers, target);
		EXPECT_EQ(expected, actual);
	}

	TEST(TwoSumIIInputArrayIsSorted, ShouldReturn2Indexes) {
		vector<int> numbers = { 2, 7, 11, 15 };
		int target = 9;
		vector<int> expected = { 1, 2 };
		vector<int> actual = Solution().twoSum(numbers, target);
		EXPECT_EQ(expected, actual);
	}
}