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

/* Solution */
const int MOD = 1000000007;
class Solution {
public:
    vector<int> diStringMatch(string S) {
        int I = 0, D = S.size();
        vector<int> ans(S.size() + 1, 0);
        for (int i = 0; i < S.size(); ++i) {
        	if (S[i] == 'I') ans[i] = I++;
        	else ans[i] = D--;
        }
        if (S.back() == 'I') ans.back() = I;
        else ans.back() = D;

        return ans;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	string S = "DDI";
	vector<int> ans = sol.diStringMatch(S);
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