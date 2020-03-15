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
// BFS
// class Solution {
// public:
//     bool flipEquiv(TreeNode* root1, TreeNode* root2) {
//     	if (!root1 && !root2) return true;
//     	if (!root1 || !root2) return false;
//         queue<TreeNode*> q1;
//         queue<TreeNode*> q2;

//         q1.push(root1);
//         q2.push(root2);
//         while (!q1.empty()) {
//         	int q_size = q1.size();
//         	for (int i = 0; i < q_size; ++i) {
//         		TreeNode* n1 = q1.front(); q1.pop();
//         		TreeNode* n2 = q2.front(); q2.pop();

//         		TreeNode* n1_left = n1->left;
//         		TreeNode* n1_right = n1->right;
//         		TreeNode* n2_left = n2->left;
//         		TreeNode* n2_right = n2->right;

//         		if (n1_left && n1_right) {
//         			if (n1_left->val > n1_right->val) {
//         				swap(n1_left, n1_right);
//         			}
//         		} else if (n1_right) {
//         			n1_left = n1_right;
//         			n1_right = NULL;
//         		}
//         		if (n2_left && n2_right) {
//         			if (n2_left->val > n2_right->val) {
//         				swap(n2_left, n2_right);
//         			}
//         		} else if (n2_right) {
//         			n2_left = n2_right;
//         			n2_right = NULL;
//         		}

//         		if ((n1_left == NULL) ^ (n2_left == NULL) ||
//         			(n1_right == NULL) ^ (n2_right == NULL)) return false;

//         		if (n1_left && (n1_left->val != n2_left->val)) return false;
//         		if (n1_right && (n1_right->val != n2_right->val)) return false; 

//         		if (n1_left) {
//         			q1.push(n1_left);
//         			q2.push(n2_left);
//         		}
//         		if (n1_right) {
//         			q1.push(n1_right);
//         			q2.push(n2_right);
//         		}
//         	}
//         }
//         return true;
//     }
// };

// Recursive
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return true;
        if (!root1 || !root2) return false;
        if (root1->val != root2->val) return false;

        if ((flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) || 
        	(flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left)) ) return true;
        return false;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	TreeNode* a_n1 = new TreeNode(1);
	TreeNode* a_n2 = new TreeNode(2);
	TreeNode* a_n3 = new TreeNode(3);
	TreeNode* a_n4 = new TreeNode(4);
	TreeNode* a_n5 = new TreeNode(5);
	TreeNode* a_n6 = new TreeNode(6);
	TreeNode* a_n7 = new TreeNode(7);
	TreeNode* a_n8 = new TreeNode(8);
	a_n1->left = a_n2;
	a_n1->right = a_n3;
	a_n2->left = a_n4;
	a_n2->right = a_n5;
	a_n3->left = a_n6;

	TreeNode* b_n1 = new TreeNode(1);
	TreeNode* b_n2 = new TreeNode(2);
	TreeNode* b_n3 = new TreeNode(3);
	TreeNode* b_n4 = new TreeNode(4);
	TreeNode* b_n5 = new TreeNode(5);
	TreeNode* b_n6 = new TreeNode(6);
	TreeNode* b_n7 = new TreeNode(7);
	TreeNode* b_n8 = new TreeNode(8);
	b_n1->left = b_n3;
	b_n1->right = b_n2;
	b_n3->right = b_n6;
	b_n2->left = b_n4;
	b_n2->right = b_n5;

	cout << sol.flipEquiv(a_n1, b_n1) << endl;

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