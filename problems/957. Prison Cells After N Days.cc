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

/* Solution */
const int MOD = 1000000007;
class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<vector<int> > cycles;

        for (int i = 0; i < N; ++i) {
        	vector<int> pre = cycles.size() == 0 ? cells : cycles.back();
        	vector<int> next(8, 0);
        	for (int j = 1; j < 7; ++j) {
        		next[j] = pre[j - 1] == pre[j + 1];
        	}
        	if (cycles.size() > 0 && next == cycles[0]) break;
        	cycles.push_back(next);

        	// for (int k = 0; k < 8; ++k) cout << cycles.back()[k] << " ";
        	// cout << endl;
        }
        return cycles[(N - 1) % cycles.size()];
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int c[] = {0,1,0,1,1,0,0,1}, N = 7;
	vector<int> cells(c, c + 8);
	vector<int> ans = sol.prisonAfterNDays(cells, N);
	for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
	cout << endl;


	/* [1-D vector] */
	// const int a = 1;
	// int arr[] = {};
	// vector<int> nums(arr, arr + a);

	/* [2-D vector] */
	// const int rows = 1;
	// const int cols = 1;
	// int arr[rows][cols] = {{1}};
	// vector<vector<int> > grid;
	// for (int r = 0; r < rows; ++r) {
	// 	grid.push_back(vector<int>(arr[r], arr[r] + cols));
	// }

	/* [String] */
	// string str = "";

}