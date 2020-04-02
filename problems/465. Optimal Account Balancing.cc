#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int minTransfers(vector<vector<int>>& transactions) {
		unordered_map<int, int> mp;
		for (auto tran : transactions) {
			mp[tran[0]] -= tran[2];
			mp[tran[1]] += tran[2];
		}
		vector<int> positive, negative;
		for (auto m : mp) {
			if (m.second > 0) positive.push_back(m.second);
			else if (m.second < 0) negative.push_back(m.second);
		}

		int ans = INT_MAX;
		dfs(positive, negative, 0, 0, ans);

		return ans;
	}
	void dfs(vector<int>& positive, vector<int>& negative, int start, int cnt, int& ans) {
		if (start == positive.size()) {
			ans = min(ans, cnt);
			return;
		}

		for (int i = 0; i < negative.size(); i++) {
			if (positive[start] + negative[i] == 0) {	// perfect match!
				// cout << "pos: " << positive[start] << " neg: " << negative[i] << endl;
				int tmp_pos = positive[start], tmp_neg = negative[i];
				positive[start] += tmp_neg;
				negative[i] += tmp_pos;
				dfs(positive, negative, start + 1, cnt + 1, ans);
				positive[start] -= tmp_neg;
				negative[i] -= tmp_pos;
				return;
			} else if (negative[i] != 0) {
				// cout << "pos: " << positive[start] << " neg: " << negative[i] << endl;
				int tmp_pos = min(positive[start], -negative[i]), tmp_neg = max(-positive[start], negative[i]);
				positive[start] += tmp_neg;
				negative[i] += tmp_pos;
				if (positive[start] == 0) dfs(positive, negative, start + 1, cnt + 1, ans);
				else dfs(positive, negative, start, cnt + 1, ans);
				positive[start] -= tmp_neg;
				negative[i] -= tmp_pos;
			}
		}
	}
};

int main() {
	vector<vector<int>> transactions = {{0, 1, 10}, {2, 0, 5}};
	Solution sol;
	cout << sol.minTransfers(transactions) << endl;
}