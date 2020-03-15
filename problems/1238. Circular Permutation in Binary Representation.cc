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
    vector<int> circularPermutation(int n, int start) {
        set<int> s;
        vector<int> v;
        s.insert(start);
        v.push_back(start);

        dfs(n, s, v);
        return v;
    }
    bool dfs(int n, set<int>& s, vector<int>& v) {
    	// cout << "this: " << v.back() << endl;
    	for (int i = 0; i < n; ++i) {
    		int next = v.back() ^ (1 << i);
    		// cout << "next: " << next << endl;
    		
    		if (v.size() == (1 << n) && next == v[0]) return true;
    		if (s.count(next) > 0) continue;
    		
    		s.insert(next);
    		v.push_back(next);
    		if (dfs(n, s, v)) {
    			return true;
    		}
    		s.erase(next);
    		v.pop_back();
    	}
    	return false;
    }
};

int main() {
	/* Solution */
	Solution sol;

	int n = 3;
	int start = 2;
	vector<int> ans = sol.circularPermutation(n, start);
	for (int i = 0; i < ans.size(); ++i) cout << ans[i] << endl;

	/* Test cases */

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