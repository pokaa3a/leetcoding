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
    int minimumSwap(string s1, string s2) {
 		int n_xy = 0, n_yx = 0;
 		for (int i = 0; i < s1.size(); ++i) {
 			if (s1[i] == 'x' && s2[i] == 'y') n_xy++;
 			else if (s1[i] == 'y' && s2[i] == 'x') n_yx++;
 		}
 		if ((n_xy + n_yx) % 2 != 0) return -1;

 		return (n_xy) / 2 + (n_xy) % 2 + (n_yx) / 2 + (n_yx) % 2;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	string s1 = "xxyyxyxyxx";
	string s2 = "xyyxyxxxyx";
	cout << sol.minimumSwap(s1, s2) << endl;

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