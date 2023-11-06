#include "pch.h"
#include "minimum_size_subarray_sum.h"
using namespace std;

int Solution::minSubArrayLen(int target, vector<int>& nums) {
	int minLength = INT_MAX;
	int sum = 0;
	int l = 0;
	int r = 0;
	while (r < nums.size()) {
		sum += nums[r];
		while (sum >= target) {
			minLength = min(minLength, r - l + 1);
			sum -= nums[l];
			l++;
		}
		r++;
	}
	if (minLength < INT_MAX) {
		return minLength;
	}
	return 0;
}