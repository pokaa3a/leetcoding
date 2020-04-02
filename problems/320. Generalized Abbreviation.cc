#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	vector<string> generateAbbreviations(string word) {
		vector<string> ans;
		dfs("", false, word, ans);
		return ans;
	}
	void dfs(string pre, bool endNum, string word, vector<string>& ans) {
		if (word.size() == 0) {
			ans.push_back(pre);
			return;
		}

		if (!endNum) {
			int n = word.size();
			for (int i = 1; i <= n; i++) {
				dfs(pre + to_string(i), true, word.substr(i), ans);
			}
		} 
		dfs(pre + word[0], false, word.substr(1), ans);
	}
};

int main() {
	string word = "word";
	Solution sol;
	vector<string> ans = sol.generateAbbreviations(word);
	for (string s : ans) cout << s << " ";
	cout << endl;
}