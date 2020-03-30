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
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
    	int n = org.size();
       	unordered_map<int, int> index;
       	for (int i = 0; i < org.size(); i++) {
       		index[org[i]] = i;
       	}

       	vector<bool> connected(n, false), seen(n, false);
       	connected[0] = true;

       	for (auto seq : seqs) {
       		for (int i = 0; i < seq.size(); i++) {
       			if (index.find(seq[i]) == index.end()) return false;
       			seen[index[seq[i]]] = true;
       			if (i == 0) continue;

       			int id1 = index[seq[i - 1]], id2 = index[seq[i]];
       			if (id1 < id2) {
       				if (id1 + 1 == id2) connected[id2] = true;
       			} else {
       				return false;
       			}
       		}
       	}
       	if (n == 1) return seen[0] == true;
       	return *min_element(connected.begin(), connected.end()) == 0 ? false : true;
    }
};



int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	vector<int> org = {5,3,2,4,1};
	vector<vector<int>> seqs{{5,3,2,4}, {4,1}, {1}, {3}, {2,4}, {1000000}};

	cout << sol.sequenceReconstruction(org, seqs) << endl;

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