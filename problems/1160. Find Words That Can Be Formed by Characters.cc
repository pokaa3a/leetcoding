#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int countCharacters(vector<string>& words, string chars) {
		vector<int> dict(26, 0);
		for (int i = 0; i < chars.length(); ++i) {
			dict[chars[i] - 'a']++;
		}
		int ans = 0;
		for (int i = 0; i < words.size(); ++i) {
			string w = words[i];
			if (check(w, dict)) ans += w.length();
		}
		return ans;
	}
private:
	bool check(string w, vector<int> dict) {
		vector<int> dict_copy = dict;
		for (int i = 0; i < w.length(); ++i) {
			if (--dict_copy[w[i] - 'a'] < 0) return false;
		}
		return true;
	}
};

int main() {
	vector<string> words;
	words.push_back("hello");
	words.push_back("world");
	words.push_back("leetcode");

	string chars = "welldonehoneyr";

	Solution sol;
	cout << sol.countCharacters(words, chars) << endl;
}