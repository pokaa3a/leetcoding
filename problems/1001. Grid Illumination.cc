#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <queue>
#include <stack>
#include <sstream>
#include <cmath>
using namespace std;

const int MOD = 1000000007;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* Solution */
class Solution {
public:
    vector<int> gridIllumination(int N, vector<vector<int> >& lamps, vector<vector<int> >& queries) {
    	n = N;

    	for (int i = 0; i < lamps.size(); ++i) {
    		add_a_lamp(lamps[i][0], lamps[i][1]);
    	}

    	vector<int> ans(queries.size(), 0);
    	for (int i = 0; i < queries.size(); ++i) {
    		if (is_on(queries[i][0], queries[i][1])) ans[i] = 1;
    		after_query(queries[i][0], queries[i][1]);
    	}
    	return ans;
    }
private:
	int n;
	unordered_map<int, int> row_on;
	unordered_map<int, int> col_on;
	unordered_map<int, int> diag_lft_on;
	unordered_map<int, int> diag_rht_on;
	set<pair<int, int> > my_lamps;

	void add_a_lamp(int r, int c) {
		my_lamps.insert(make_pair(r, c));

		row_on[r]++;
		
		col_on[c]++;

		if (r <= c) diag_lft_on[c - r]++;
		else diag_lft_on[r - c + n]++;

		if (r <= (n - 1) - c) diag_rht_on[c + r]++;
		else diag_rht_on[r - (n - 1) + c + n]++;
	}

	void remove_a_lamp(int r, int c) {
		my_lamps.erase(make_pair(r, c));

		

		if (--row_on[r] == 0) row_on.erase(r);

		if (--col_on[c] == 0) col_on.erase(c);

		if (r <= c) {
			if (--diag_lft_on[c - r] == 0) diag_lft_on.erase(c - r);
		} else {
			if (--diag_lft_on[r - c + n] == 0) diag_lft_on.erase(r - c + n);
		}

		if (r <= (n - 1) - c) {
			if (--diag_rht_on[c + r] == 0) diag_rht_on.erase(c + r);
		} else {
			if (--diag_rht_on[r - (n - 1) + c + n] == 0) diag_rht_on.erase(r - (n - 1) + c + n);
		}

		
	}

	void after_query(int r, int c) {
		for (int i = -1; i <= 1; ++i) {
			for (int j = -1; j <= 1; ++j) {
				if (r + i < 0 || r + i >= n || c + j < 0 || c + j >= n) continue;
				if (my_lamps.find(make_pair(r + i, c + j)) != my_lamps.end()) {
					remove_a_lamp(r + i, c + j);
				}
			}
		}
	}

	bool is_on(int r, int c) {
		if (row_on.find(r) != row_on.end() && row_on[r] > 0) return true;
		if (col_on.find(c) != col_on.end() && col_on[c] > 0) return true;

		if (r <= c && diag_lft_on.find(c - r) != diag_lft_on.end() && diag_lft_on[c - r] > 0) return true;
		if (r > c && diag_lft_on.find(r - c + n) != diag_lft_on.end() && diag_lft_on[r - c + n] > 0) return true;

		if (r <= (n - 1) - c && diag_rht_on.find(c + r) != diag_rht_on.end() && diag_rht_on[c + r] > 0) return true;
		if (r > (n - 1) - c && diag_rht_on.find(r - (n - 1) + c + n) != diag_rht_on.end() && diag_rht_on[r - (n - 1) + c + n] > 0) return true;

		return false;  
	}
};

int main() {
	// Solution
	Solution sol;

	// Test cases
	int N = 5;
	int l[2][2] = {{4, 4}};
	vector<vector<int> > lamps;
	for (int i = 0; i < 2; ++i) lamps.push_back(vector<int>(l[i], l[i] + 2));
	int q[2][2] = {{1, 1}, {1, 1}};
	vector<vector<int> > queries;
	for (int i = 0; i < 2; ++i) queries.push_back(vector<int>(q[i], q[i] + 2));

	vector<int> ans = sol.gridIllumination(N, lamps, queries);
	for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
	cout << endl;
}
