#include "pch.h"
#include "max_concecutive_ones_iii.h"
using namespace std;

int Solution::longestOnes(vector<int>& nums, int k) {
	int maxOnes = 0;
	int currentOnes = 0;
	int l = 0;
	for (int r = 0; r < nums.size(); r++) {
		if (nums[r] == 1) {
			currentOnes++;
		}
		else {
			k--;
			currentOnes++;
while(k < 0) {
if (nums[l] == 0) {
k++;
}
l++;
currentOnes--;
}
}
		maxOnes = max(maxOnes, currentOnes);
	}
	return maxOnes;
}