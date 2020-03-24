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
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deads(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        visited.insert("0000");
        queue<string> q;
        q.push("0000");
        if (deads.count("0000")) return -1;

        int steps = 0;
        while (!q.empty()) {
        	int q_size = q.size();

        	for (int i = 0; i < q_size; i++) {
        		string cur = q.front();
        		q.pop();

        		if (cur == target) return steps;
        		// 4 digits
        		for (int j = 0; j < 4; j++) {
        			if (cur[j] == '0') {
        				string tmp = cur;
        				tmp[j] = '1';
        				if (deads.count(tmp) == 0 && visited.count(tmp) == 0) {
        					visited.insert(tmp);
        					q.push(tmp);
        				}
        				tmp[j] = '9';
        				if (deads.count(tmp) == 0 && visited.count(tmp) == 0) {
        					visited.insert(tmp);
        					q.push(tmp);
        				}
        			} else if (cur[j] == '9') {
        				string tmp = cur;
        				tmp[j] = '8';
        				if (deads.count(tmp) == 0 && visited.count(tmp) == 0) {
        					visited.insert(tmp);
        					q.push(tmp);
        				}
        				tmp[j] = '0';
        				if (deads.count(tmp) == 0 && visited.count(tmp) == 0) {
        					visited.insert(tmp);
        					q.push(tmp);
        				}
        			} else {
        				string tmp = cur;
        				tmp[j] = cur[j] + 1;
        				if (deads.count(tmp) == 0 && visited.count(tmp) == 0) {
        					visited.insert(tmp);
        					q.push(tmp);
        				}
        				tmp[j] = cur[j] - 1;
        				if (deads.count(tmp) == 0 && visited.count(tmp) == 0) {
        					visited.insert(tmp);
        					q.push(tmp);
        				}
        			}
        		}
        	}
        	steps++;
        }
        return -1;
    }
};



int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	string s[] = {"0000"};
	vector<string> deadends(s, s + 1);

	string target = "8888";
	cout << sol.openLock(deadends, target) << endl;

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