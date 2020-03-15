#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int calculateTime(string keyboard, string word) {
		int res = 0, cur_idx = 0;
		for (int i = 0; i < word.length(); ++i) {
			int next_idx = giveMeIdx(word[i], keyboard);
			res += abs(next_idx - cur_idx);
			cur_idx = next_idx;
		}
		return res;
	}
private:
	int giveMeIdx(char c, string& keyboard) {
		for (int i = 0; i < keyboard.size(); ++i) {
			if (keyboard[i] == c) return i;
		}
		return 25;
	}
};

int main() {
	string keyboard = "pqrstuvwxyzabcdefghijklmno";
	string word = "leetcode";
	Solution sol;
	cout << sol.calculateTime(keyboard, word) << endl;
}