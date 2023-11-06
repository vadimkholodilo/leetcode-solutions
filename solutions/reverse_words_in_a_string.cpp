#include "pch.h"
#include "reverse_words_in_a_string.h"
using namespace std;

string Solution::reverseWords(string s) {
	string result = "";
	stack<string> words;
	string word;
	for (char c : s) {
		if (!isspace(c)) {
			word += c;
		}
		else {
			if (!word.empty()) {
				words.push(word);
				word = "";
			}
		}
	}
	if (!word.empty()) {
		words.push(word);
	}
	while (!words.empty()) {
		result += words.top();
		words.pop();
		if (!words.empty()) {
			result += " ";
		}
	}
	return result;
}