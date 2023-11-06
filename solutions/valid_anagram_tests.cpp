#include "pch.h"
#include "valid_anagram.h"
using namespace std;
namespace LeetcodeSolutions {
	TEST(ValidAnagram, ShouldReturnFalseIfStringsHaveDifferentLength) {
		string s = "abc";
		string t = "abcd";
		Solution solution;
		EXPECT_FALSE(solution.isValidAnagram(s, t));
	}
	TEST(ValidAnagram, ShouldReturnFalseIfBothStringsAreEmpty) {
		string s = "";
		string t = "";
		Solution solution;
		EXPECT_FALSE(solution.isValidAnagram(s, t));
	}

	TEST(ValidAnagram, ShouldReturnFalseIfOneStringIsEmpty) {
		string s = "abc";
		string t = "";
		Solution solution;
		EXPECT_FALSE(solution.isValidAnagram(s, t));
	}

	TEST(ValidAnagram, ShouldReturnFalseIfStringsAreNotValidAnagrams) {
		string s = "rat";
		string t = "car";
		Solution solution;
		EXPECT_FALSE(solution.isValidAnagram(s, t));
	}

	TEST(ValidAnagram, ShouldReturnTrueIfStringsAreValidAnagrams) {
		string s = "anagram";
		string t = "nagaram";
		Solution solution;
		EXPECT_TRUE(solution.isValidAnagram(s, t));
	}
}