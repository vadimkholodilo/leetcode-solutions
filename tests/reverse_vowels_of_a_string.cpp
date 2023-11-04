#include "pch.h"
#include "reverse_vowels_of_a_string.h"
using namespace std;

string Solution::reverseVowels(string s) {
	unordered_set<char> vowels = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
	int l = 0;
	int r = s.size() - 1;
	while (l < r) {
		if (vowels.find(s[l]) == vowels.end()) {
			l++;
		}
		if (vowels.find(s[r]) == vowels.end()) {
			r--;
		}
		if (vowels.find(s[l]) != vowels.end() && vowels.find(s[r]) != vowels.end()) {
			swap(s[l], s[r]);
			l++;
			r--;
		}
	}
	return s;
}