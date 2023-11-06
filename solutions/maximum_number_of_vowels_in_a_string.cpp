#include "pch.h"
#include "maximum_number_of_vowels_in_a_string.h"
using namespace std;

int Solution::maxVowels(string s, int k) {
	unordered_set<char> charmap = { 'a', 'e', 'i', 'o', 'u' };
	int maxCount = 0;
	int count = 0;
	int l = 0;
	for (int r = 0; r < s.size(); r++) {
		if (charmap.find(s[r]) != charmap.end()) {
			count++;
		}
		if (r - l + 1 >= k) {
			maxCount = max(maxCount, count);
			if (charmap.find(s[l]) != charmap.end()) {
				count--;
			}
			l++;
		}
	}
	return maxCount;
}