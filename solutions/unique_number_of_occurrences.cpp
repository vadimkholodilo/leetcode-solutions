#include "pch.h"
#include "unique_number_of_occurrences.h"
using namespace std;

bool Solution::uniqueOccurrences(vector<int>& arr) {
	unordered_map<int, int> occurrences;
	for (int i = 0; i < arr.size(); i++) {
		occurrences[arr[i]]++;
	}
	unordered_set<int> uniqueOccurrences;
	for (auto it = occurrences.begin(); it != occurrences.end(); it++) {
		if (uniqueOccurrences.find(it->second) != uniqueOccurrences.end()) {
			return false;
		}
		uniqueOccurrences.insert(it->second);
	}
	return true;
}