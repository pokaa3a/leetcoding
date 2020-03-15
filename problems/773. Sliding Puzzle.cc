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
    int slidingPuzzle(vector<vector<int> >& board) {
        const string final_state = "123450";
        string init_state = "";
        for (int i = 0; i < 2; ++i) {
        	for (int j = 0; j < 3; ++j) {
        		init_state += to_string(board[i][j]);
        	}
        }
        queue<string> q;
        unordered_set<string> seen;
        q.push(init_state);
        seen.insert(init_state);
        int step = 0;
        while (!q.empty()) {
        	int q_size = q.size();
        	for (int i = 0; i < q_size; ++i) {
        		string cur = q.front(); q.pop();
        		if (cur == final_state) return step;
        		next_states(cur, q, seen);
        	}
        	step++;
        }
        return -1;
    }
    void next_states(string cur, queue<string>& q, unordered_set<string>& seen) {
    	int zero = cur.find("0");
    	int r = zero / 3, c = zero % 3;
    	int dirs[] = {0, 1, 0, -1, 0};
    	for (int i = 0; i < 4; ++i) {
    		if (r + dirs[i] >= 0 && r + dirs[i] < 2 &&
    			c + dirs[i + 1] >= 0 && c + dirs[i + 1] < 3) {
    			string next = cur;
    			swap(next[zero], next[3 * (r + dirs[i]) + (c + dirs[i + 1])]);
    			if (seen.count(next) == 0) {
    				q.push(next);
    				seen.insert(next);
    			}
    		}
    	}
    }
};



int main() {
	/* Solution */
	Solution sol;

	/* Test cases */

	/* [1-D vector] */
	// const int a = 1;
	// int arr[] = {};
	// vector<int> nums(arr, arr + a);

	/* [2-D vector] */
	const int rows = 2;
	const int cols = 3;
	int arr[rows][cols] = {{3,2,4}, {1,5,0}};
	vector<vector<int> > grid;
	for (int r = 0; r < rows; ++r) {
		grid.push_back(vector<int>(arr[r], arr[r] + cols));
	}
	cout << sol.slidingPuzzle(grid) << endl;

	/* [String] */
	// string str = "";

}