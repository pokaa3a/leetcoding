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
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k == 0) return 0;
        unordered_map<char, int> count;
        
        int lo = 0, hi = 0;
        count[s[lo]]++;
        int ans = 0;
        while (lo < s.size()) {
        	cout << "lo: " << lo << endl;
            while (hi + 1 < s.size() && (count.size() < k || (count.find(s[hi + 1]) != count.end()))) {
                hi++;
                count[s[hi]]++;
            }
            cout << "hi: " << hi << endl;
            ans = max(ans, hi - lo + 1);
            if (--count[s[lo]] == 0) count.erase(s[lo]);
            lo++;
        }
        return ans;
    }
};



int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	string s = "aac";
	int k = 2;
	cout << sol.lengthOfLongestSubstringKDistinct(s, k) << endl;

	/* [1-D vector] */
	// int arr[] = {};
	// vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));

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