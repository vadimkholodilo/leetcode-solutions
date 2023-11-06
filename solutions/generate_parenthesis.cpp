#include "pch.h"
#include "generate_parenthesis.h"

using namespace std;

vector<string> Solution::generateParenthesis(int n) {
	vector<string> result = {};
	if (n == 0) {
		return result;
	}
	string curr = "";
	backtrack(result, curr, 0, 0, n);
	return result;
}

void Solution::backtrack(vector<string>& result, string& curr, int open, int close, int n) {
	if (curr.size() == 2 * n) {
		result.push_back(curr);
		return;
	}
	if (open < n) {
		curr.push_back('(');
		backtrack(result, curr, open + 1, close, n);
		curr.pop_back();
	}
	if (close < open) {
		curr.push_back(')');
		backtrack(result, curr, open, close + 1, n);
		curr.pop_back();
	}
}