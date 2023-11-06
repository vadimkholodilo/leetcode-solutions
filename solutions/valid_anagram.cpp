#include "pch.h"
#include "valid_anagram.h"
#include <map>

using namespace std;
bool Solution::isValidAnagram(string s, string t) {
	if (s.length() == 0 || t.length() == 0) {
		return false;
	}
	if (s.length() != t.length()) {
		return false;
	}
	map<char, int> sCount;
	map<char, int> tCount;
	for (int i = 0; i < s.length(); i++) {
		if (sCount.count(s[i]) == 0) {
			sCount[s[i]] = 1;
		}
		else {
			sCount[s[i]]++;
		}
		if (tCount.count(t[i]) == 0) {
			tCount[t[i]] = 1;
		}
		else {
			tCount[t[i]]++;
		}
	}
	for (auto it = sCount.begin(); it != sCount.end(); it++) {
		char key = it->first;
		int value = it->second;
		if (tCount.count(key) == 0 || tCount[key] != value) {
			return false;
		}
	}
	return true;
}
