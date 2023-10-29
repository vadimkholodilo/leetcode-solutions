#include "pch.h"
#include "max_consecutive_ones.h"
using namespace std;

int Solution::findMaxConsecutiveOnes(vector<int>& nums) {
	int max = 0;
	int current = 0;
	for (auto it = nums.begin(); it != nums.end(); it++) {
		if (*it == 1) {
			current++;
		}
		else {
			if (current > max) {
				max = current;
			}
			current = 0;
		}
if (current > max) {
max = current;
}
	}
	return max;
}
