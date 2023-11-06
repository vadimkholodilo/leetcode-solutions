#include "pch.h"
#include "move_zeros.h"
using namespace std;
void Solution::moveZeros(vector<int>& nums) {
	int l = 0;
	int r = 0;
	while (r < nums.size()) {
		if (nums[r] != 0) {
			nums[l] = nums[r];
			l++;
		}
		r++;
	}
	while (l < nums.size()) {
		nums[l] = 0;
		l++;
	}
}