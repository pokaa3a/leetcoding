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
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<vector<int>> stk;	// id, start time, rec time
        vector<int> output(n, 0);

        for (string log : logs) {
        	int id, timestamp;
        	bool isStart = parse(log, id, timestamp);
        	
        	if (isStart) {
        		stk.push({id, timestamp, 0});
        	} else {
        		int start_time = stk.top()[1];
        		int rec_time = stk.top()[2];
        		// cout << id << " ends " << endl;
        		// cout << "started at " << start_time << " rec_time: " << rec_time << endl;

        		stk.pop();
        		int exc_time = timestamp - start_time + 1 - rec_time;
        		output[id] += exc_time;

        		if (!stk.empty()) {
        			stk.top()[2] += timestamp - start_time + 1;
        		}
        	}
        }
        return output;
    }
    bool parse(string log, int& id, int& timestamp) {
        int semi_1 = log.find(':');
        int semi_2 = log.find(':', semi_1 + 1);
        
        id = stoi(log.substr(0, semi_1));
        timestamp = stoi(log.substr(semi_2 + 1));
    	return log.substr(semi_1 + 1, semi_2 - semi_1 - 1) == "start";
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	vector<string> logs = {"0:start:0","0:start:1","0:start:2","0:end:3","0:end:4","0:end:5"};
	int n = 1;
	vector<int> res = sol.exclusiveTime(n, logs);
	for (int x : res) cout << x << " ";
	cout << endl;

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