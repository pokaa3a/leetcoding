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
    int maxDiff(int num) {
    	// cout << to_max(num) << endl;
    	// cout << to_min(num) << endl;
        return to_max(num) - to_min(num);
    }
    int to_max(int num) {
    	string s = to_string(num);
    	
    	bool change = false;
    	char x;
    	for (int i = 0; i < s.size(); i++) {
    		if (change) {
    			if (s[i] == x) s[i] = '9';
    		} else if (s[i] - '0' < 9) {
    			change = true;
    			x = s[i];
    			s[i] = '9';
    		}
    	}
    	return stoi(s);
    }
    int to_min(int num) {
    	string s = to_string(num);

    	bool change = false;
    	char x, y;
    	for (int i = 0; i < s.size(); i++) {
    		if (change) {
    			if (s[i] == x) s[i] = y;
    		} else if (s[i] - '0' > 1) {
    			change = true;
    			x = s[i];
    			y = i == 0 ? '1' : '0';
    			s[i] = y;
    		}
    	}
    	return stoi(s);
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int num = 111;
	cout << sol.maxDiff(num) << endl;

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