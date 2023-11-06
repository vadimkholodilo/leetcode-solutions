#include "pch.h"
#include "two_sum_ii_input_array_is_sorted.h"
using namespace std;

vector<int> Solution::twoSum(vector<int>& numbers, int target) {
	vector<int> result = {};
	int l = 0;
	int r = numbers.size() - 1;
	while (l < r) {
		int sum = numbers[l] + numbers[r];
		if (sum == target) {
			result.push_back(l + 1);
			result.push_back(r + 1);
			break;
		}
		if (sum < target) {
			l++;
		}
		else {
			r--;
		}
	}
	return result;
}