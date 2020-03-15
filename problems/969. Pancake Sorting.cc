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
    vector<int> pancakeSort(vector<int>& A) {
    	vector<int> ans;
        for (vector<int>::iterator it = A.end(); it != A.begin(); it--) {
        	vector<int>::iterator max_it = max_element(A.begin(), it);

        	reverse(A.begin(), max_it + 1);
        	ans.push_back(max_it - A.begin() + 1);

        	reverse(A.begin(), it);
        	ans.push_back(it - A.begin());
        }
    	return ans;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int a[] = {1,2,3};
	vector<int> A(a, a + 3);

	vector<int> ans = sol.pancakeSort(A);
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