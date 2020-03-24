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
    int maxNumberOfFamilies(int n, vector<vector<int> >& reservedSeats) {
        unordered_map<int, int> reserved;
        for (int i = 0; i < reservedSeats.size(); i++) {
        	int r = reservedSeats[i][0], c = reservedSeats[i][1];
        	if (reserved.find(r) == reserved.end()) reserved[r] = 0;
        	reserved[r] |= (1 << c);
        }
        const int seat1 = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        const int seat2 = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
        const int seat3 = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);

        int ans = (n - reserved.size()) * 2;

        for (unordered_map<int, int>::iterator it = reserved.begin(); it != reserved.end(); it++) {
        	int reserved_seats = it->second;
        	int add = 0;
        	if ((reserved_seats & seat1) == 0 && (reserved_seats & seat3) == 0) add = 2;
        	else if ((reserved_seats & seat1) == 0 || 
        			 (reserved_seats & seat2) == 0 || 
        			 (reserved_seats & seat3) == 0) add = 1;
        	ans += add;
        }
        return ans;
    }
};



int main() {
	/* Solution */
	Solution sol;

	/* Test cases */

	/* [1-D vector] */
	// int arr[] = {};
	// vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));

	/* [2-D vector] */
	const int rows = 6;
	const int cols = 2;
	int arr[rows][cols] = {{1,2},{1,3},{1,8},{2,6},{3,1},{3,10}};
	vector<vector<int> > grid;
	for (int r = 0; r < rows; ++r) {
		grid.push_back(vector<int>(arr[r], arr[r] + cols));
	}
	int n = 3;
	cout << sol.maxNumberOfFamilies(n, grid) << endl;
	/* [String] */
	// string str = "";

}