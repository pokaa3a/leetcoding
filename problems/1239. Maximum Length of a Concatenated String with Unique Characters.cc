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
    int maxLength(vector<string>& arr) {
    	vector<bitset<26> > dp(1, bitset<26>());
    	int ans = 0;
    	for (int i = 0; i < arr.size(); ++i) {
    		string s = arr[i];
    		bitset<26> s_set;
    		for (int k = 0; k < s.size(); ++k) {
    			s_set.set(s[k] - 'a');
    		}
    		if (s_set.count() < s.size()) continue;

    		for (int j = dp.size() - 1; j >= 0; --j) {
    			bitset<26> d = dp[j];
    			if ((s_set & d).any()) continue;
    			dp.push_back(s_set | d);
    			ans = max(ans, (int)d.count() + (int)s_set.count());
    		}
    	}
    	return ans;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	vector<string> arr;
	arr.push_back("cha");
	arr.push_back("r");
	arr.push_back("act");
	arr.push_back("ers");

	cout << sol.maxLength(arr) << endl;

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