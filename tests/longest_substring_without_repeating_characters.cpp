#include "pch.h"
#include "longest_substring_without_repeating_characters.h"

using namespace std;

int Solution::lengthOfLongestSubstring(string s) {
	int maxLength = 0;
	int l = 0;
	set<char> charset = {};
	for (int r = 0; r < s.length(); r++) {
		if (charset.count(s[r]) == 0) {
			charset.insert(s[r]);
			maxLength = max(maxLength, r - l + 1);
		}
		else {
			while (charset.count(s[r]) != 0) {
				charset.erase(s[l]);
				l++;
			}
			charset.insert(s[r]);
		}
	}
	return maxLength;
}