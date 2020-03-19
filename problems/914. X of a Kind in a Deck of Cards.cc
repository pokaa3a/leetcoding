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
	int gcd(int a, int b) {
		if (a == 0) return b;
		return gcd(b % a, a);
	}
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> count;
        for (int i = 0; i < deck.size(); i++) {
        	count[deck[i]]++;
        }
        int a = count.begin()->second;
        for (unordered_map<int, int>::iterator it = count.begin(); it != count.end(); it++) {
        	a = gcd(a, it->second);
        	if (a < 2) return false;
        }
        return true;
    }
};



int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int d[] = {1,1,2,2,2,3,3,3,3,3,3};
	vector<int> deck(d, d + sizeof(d) / sizeof(int));
	cout << sol.hasGroupsSizeX(deck) << endl;

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