#pragma once
#include <vector>
#include <string>

class Solution {
public:
std::vector<std::string> generateParenthesis(int n);
private:
void backtrack(std::vector<std::string>&  result, std::string& curr, int open, int close, int n);
};
