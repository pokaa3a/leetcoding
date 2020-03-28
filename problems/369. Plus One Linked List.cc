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
    ListNode* plusOne(ListNode* head) {
    	vector<ListNode*> record;
    	ListNode* cur = head;
    	while (!cur) {
    		record.push_back(cur);
    		cur = cur->next;
    	}
    	int i = record.size() - 1, carry = 1;
    	while (i >= 0 && carry > 0) {
    		record[i]->val += carry;
    		carry = record[i]->val % 10;
    		record[i]->val %= 10;
    		i--;
    	}
    	if (i < 0 && carry > 0) {
    		ListNode* new_head = new ListNode(carry);
    		new_head->next = head;
    		return new_head;
    	}
    	return head;
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