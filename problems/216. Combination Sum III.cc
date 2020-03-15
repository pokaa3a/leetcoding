#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int> > combinationSum3(int k, int n) {
		vector<vector<int> > res;
		for (int i = 1; i <= min(n / k, 9); ++i) {
			vector<vector<int> > sub_res = helper(i + 1, k - 1, n - i);
			for (int j = 0; j < sub_res.size(); ++j) {
				sub_res[j].push_back(i);
				res.push_back(sub_res[j]);
			}
		}
		return res;
	}

	vector<vector<int> > helper(int start, int k, int n) {
		vector<vector<int> > res;
		if (k == 1) {
			if (n >= start && n <= 9) res.push_back(vector<int>(1,n));
		} else {
			for (int i = start; i <= min(n / k, 9); ++i) {
				vector<vector<int> > sub_res = helper(i + 1, k - 1, n - i);
				for (int j = 0; j < sub_res.size(); ++j) {
					sub_res[j].push_back(i);
					res.push_back(sub_res[j]);
				}
			}
		}
		return res;
	}
};

int main() {
	Solution sol;
	int k = 3, n = 9;
	vector<vector<int> > res = sol.combinationSum3(k, n);

	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
}