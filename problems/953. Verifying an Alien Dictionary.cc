#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool isAlienSorted(vector<string> &words, string order) {
		if (words.size() <= 1) return true;

		// Build dictionary
		unordered_map<char, int> dict;
		for (int i = 0; i < order.length(); ++i) {
			dict[order[i]] = i;
		}

		for (int i = 0; i < words.size() - 1; ++i) {
			if (!compare(words[i], words[i + 1], dict)) return false;
		}
		return true;
	}
	bool compare(string a, string b, unordered_map<char, int> &dict) {
		int a_len = a.length();
		int b_len = b.length();

		for (int i = 0; i < min(a_len, b_len); ++i) {
			if (dict[a[i]] < dict[b[i]]) return true;
			else if (dict[a[i]] > dict[b[i]]) return false;
		}
		return a_len <= b_len;
	}
};

int main() {
	vector<string> words;
	words.push_back("apple");
	words.push_back("app");
	// words.push_back("row");

	string order = "worldabcefghijkmnpqstuvxyz";

	Solution sol;
	cout << sol.isAlienSorted(words, order) << endl;
}