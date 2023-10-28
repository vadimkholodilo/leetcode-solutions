#include "pch.h"
#include "generate_parenthesis.h"
using namespace std;
namespace LeetcodeSolutions {
	TEST(GenerateParenthesis, ShouldReturnEmptyVectorIfNIs0) {
		int n = 0;
		vector<string> expected = {};
		vector<string> actual = Solution().generateParenthesis(n);
		EXPECT_EQ(expected, actual);
	}
	TEST(GenerateParenthesis, ShouldGenerateOnePareIfNIs1) {
		int n = 1;
		vector<string> expected = { "()" };
		vector<string> actual = Solution().generateParenthesis(n);
		EXPECT_EQ(expected, actual);
	}
	TEST(GenerateParenthesis, ShouldGenerate3ParesIfNIs3) {
		int n = 3;
		vector<string> expected = { "((()))","(()())","(())()","()(())","()()()" };
		vector<string> actual = Solution().generateParenthesis(n);
		EXPECT_EQ(expected, actual);
	}
}

