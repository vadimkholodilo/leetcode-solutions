#include "pch.h"
#include "valid_parenthesis.h"
#include <vector>
#include <map>
using namespace std;

bool Solution::isValid(string s) {
	map<char, char> parenthesis = {
		{ ')', '(' },
		{ '}', '{' },
		{ ']', '[' }
	};
	vector<char> stack = {};
	for (char p : s) {
		if (parenthesis.find(p) == parenthesis.end()) { // Open parenthesy
			stack.push_back(p);
		}
		else {
			if (stack.size() == 0) {
				return false;
			}
			char last = stack.back();
			if (parenthesis[p] == last) {
				stack.pop_back();
			}
			else {
				return false;
			}
		}
	}
	if (stack.size() > 0) {
		return false;
	}
	return true;
}