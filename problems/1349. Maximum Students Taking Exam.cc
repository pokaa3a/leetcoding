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
#include <numeric>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void traverse(TreeNode* root) {
	if (!root) return;
	cout << root->val << endl;
	traverse(root->left);
	traverse(root->right);
}

/* Solution */
const int MOD = 1000000007;
class Solution {
	int m, n;
public:
    int maxStudents(vector<vector<char> >& seats) {
        // define DP
        // dp[k][seat]: max number of students of first k rows
        // 				and last row is "seat"
        // dp[k][seat] = max(dp[k - 1][all possible seats])
        m = seats.size(), n = seats[0].size();
        vector<int> seat_vec(m, 0);
        for (int i = 0; i < seats.size(); ++i) {
        	for (int j = 0; j < seats[i].size(); ++j) {
        		if (seats[i][j] == '.') seat_vec[i] |= (1 << j);
        	}
        }

        vector<vector<int> > dp(m + 1, vector<int>((1 << n), -1));
        dp[0][0] = 0;
        for (int i = 1; i <= m; ++i) {
        	cout << "row " << i << endl;
        	for (int next = 0; next < (1 << n); ++next) {
        		if ((next | seat_vec[i - 1]) == seat_vec[i - 1]) {
        			dp[i][next] = 0;
        			for (int prev = 0; prev < (1 << n); ++prev) {
        				if (dp[i - 1][prev] < 0) continue;
        				if (no_cheating(next, prev)) {
        					bitset<8> bs(next);
        					cout << bs << endl;
        					dp[i][next] = max(dp[i][next], dp[i - 1][prev] + (int)bs.count());
        				}
        			}
        			bitset<8> tmp(next);
        			cout << "dp[" << i << "][" << tmp << "] = " << dp[i][next] << endl;
        		}
        	}
        }

        return *max_element(dp.back().begin(), dp.back().end());
    }
    bool no_cheating(int next, int prev) {
    	for (int i = 0; i < n; ++i) {
    		if ((1 << i) & next) {
    			if (i > 0) {
    				if ((1 << (i - 1)) & next) return false;
    				if ((1 << (i - 1)) & prev) return false;
    			}
    			if (i < n - 1) {
    				if ((1 << (i + 1)) & next) return false;
    				if ((1 << (i + 1)) & prev) return false;
    			}
    		}
    	}
    	return true;
    }
};



int main() {
	/* Solution */
	Solution sol;

	/* Test cases */

	/* [1-D vector] */
	// const int a = 1;
	// int arr[] = {};
	// vector<int> nums(arr, arr + a);

	/* [2-D vector] */
	const int rows = 3;
	const int cols = 3;
	// char arr[rows][cols] = {{'#','.','#','#','.','#'}, 
	// 						{'.','#','#','#','#','.'},
	// 						{'#','.','#','#','.','#'}};
	char arr[rows][cols] = {{'#','.','#'},
							{'#','#','.'},
							{'.','#','.'}};
	vector<vector<char> > grid;
	for (int r = 0; r < rows; ++r) {
		grid.push_back(vector<char>(arr[r], arr[r] + cols));
	}
	cout << sol.maxStudents(grid) << endl;

	/* [String] */
	// string str = "";

}