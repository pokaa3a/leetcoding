#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	vector<int> diffWaysToCompute(string input) {
		vector<int> nums;
		vector<int> operators;
		map<pair<int, int>, vector<int> > dp;

		int i = 0;
		while(i < input.length()) {
			if (input[i] == '+') {
				operators.push_back(0);
			} else if (input[i] == '-') {
				operators.push_back(1);
			} else if (input[i] == '*') {
				operators.push_back(2);
			} else {
				int j = i + 1;
				// without adding "j < input.length()", leetcode grader will crash
				for (; j < input.length() && input[j] != '+' && input[j] != '-' && input[j] != '*'; ++j) {}
				int num = stoi(input.substr(i, j - i));
				nums.push_back(num);
				i = j - 1;
			}
			i++;
		}
		return compute(0, nums.size() - 1, nums, operators, dp);
	}
private:
	vector<int> compute(int i, int j, vector<int>& nums, vector<int>& operators,
						map<pair<int, int>, vector<int> >& dp) {
		if (dp.find(make_pair(i, j)) != dp.end()) {
			return dp[make_pair(i, j)];
		}
		if (i == j) return vector<int>(1, nums[i]);

		vector<int> ans;
		for (int r = i; r < j; ++r) {
			vector<int> a = compute(i, r, nums, operators, dp);
			vector<int> b = compute(r + 1, j, nums, operators, dp);
			if (operators[r] == 0) {
				for (int s = 0; s < a.size(); ++s) {
					for (int t = 0; t < b.size(); ++t) {
						ans.push_back(a[s] + b[t]);
					}
				}
			} else if (operators[r] == 1) {
				for (int s = 0; s < a.size(); ++s) {
					for (int t = 0; t < b.size(); ++t) {
						ans.push_back(a[s] - b[t]);
					}
				}
			} else {
				for (int s = 0; s < a.size(); ++s) {
					for (int t = 0; t < b.size(); ++t) {
						ans.push_back(a[s] * b[t]);
					}
				}
			}
		}
		dp[make_pair(i, j)] = ans;
		return ans;
	}
};

int main() {
	string S = "2-1-1";
	Solution sol;
	vector<int> ans = sol.diffWaysToCompute(S);
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << endl;
	}
}