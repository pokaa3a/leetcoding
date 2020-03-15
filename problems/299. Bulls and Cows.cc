#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Solution {
public:
	string getHint(string secret, string guess) {
		int bulls = 0;
		int cows = 0;
		unordered_map<char, int> nums;
		queue<char> rest_nums;
		for (int i = 0; i < secret.length(); ++i) {
			char c = secret[i];
			if (!nums.count(c)) nums[c] = 1;
			else nums[c]++;
		}
		for (int i = 0; i < guess.length(); ++i) {
			int d = guess.length() - i - 1;
			int idx_secret = secret.length() - d - 1;
			if (idx_secret < secret.length() &&
				secret[idx_secret] == guess[i]) {
				bulls++;
				nums[guess[i]]--;
			} else {
				rest_nums.push(guess[i]);
			}
		}
		while (!rest_nums.empty()) {
			char c = rest_nums.front();
			rest_nums.pop();
			if (nums.count(c) && nums[c]) {
				cows++;
				nums[c]--;
			}
		}
		return to_string(bulls) + "A" + to_string(cows) + "B";
	}
};

int main() {
	string secret = "1807";
	string guess = "781";
	Solution sol;
	cout << sol.getHint(secret, guess);
}